#include "MWConcatenationLayerImpl.hpp"
#include "MWConcatenationLayer.hpp"
#include <stdarg.h>
#include <cassert>
 MWConcatenationLayerImpl::MWConcatenationLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl) : MWCNNLayerImpl(layer, ntwk_impl) { 
setupIpArmTensors(); 
setCurrentLayerOpArmTensor(std::make_shared<arm_compute::Tensor>()); } void 
MWConcatenationLayerImpl::propagateSize() { MWConcatenationLayer* concatLayer = 
static_cast<MWConcatenationLayer*>(getLayer()); int numInputs = 
concatLayer->getNumInputs(); configureIpArmTensors();
#if defined(USE_18_05_LIBRARY)
 m_depthConcatenateLayer = 
std::unique_ptr<arm_compute::NEDepthConcatenateLayer>( new arm_compute::NEDepthConcatenateLayer);
#else
 if (concatLayer->dimension == 3) { m_depthConcatenateLayer = 
std::unique_ptr<arm_compute::NEDepthConcatenateLayer>(new 
arm_compute::NEDepthConcatenateLayer); } else { m_concatenateLayer = 
std::unique_ptr<arm_compute::NEConcatenateLayer>(new 
arm_compute::NEConcatenateLayer); }
#endif
 std::vector<arm_compute::ITensor*> concatInputs; reshapeCount = 0; for (int i 
= 0; i < numInputs; i++) { MWTensorBase* ipTensor = 
concatLayer->getInputTensor(i); arm_compute::Tensor* prevLayerarmTensor = 
getCurrentLayerIpArmTensor(i); 
m_isIpArmTensorReshaped.push_back(prevLayerarmTensor->info()->num_dimensions() 
<= 2 && ipTensor->getHeight() == 1 && ipTensor->getWidth() == 1); if 
(m_isIpArmTensorReshaped[i]) {  
m_layerInputArmTensor.push_back(std::make_shared<arm_compute::Tensor>()); 
m_layerInputArmTensor[i]->allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)ipTensor->getWidth(), (long 
unsigned int)ipTensor->getHeight(), (long unsigned int)ipTensor->getChannels(), 
(long unsigned int)ipTensor->getBatchSize() * ipTensor->getSequenceLength()), 
1, arm_compute::DataType::F32)); 
m_reshapeKernel.push_back(std::unique_ptr<arm_compute::NEReshapeLayer>(new 
arm_compute::NEReshapeLayer)); 
m_reshapeKernel[reshapeCount]->configure(prevLayerarmTensor, 
m_layerInputArmTensor[i].get()); reshapeCount++; } else {  
m_layerInputArmTensor.push_back(getCurrentLayerIpArmTensorSharedPtr(i)); } 
concatInputs.push_back(m_layerInputArmTensor[i].get()); } MWTensorBase* 
opTensor = getLayer()->getOutputTensor(0); 
getCurrentLayerOpArmTensor()->allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)opTensor->getWidth(), (long 
unsigned int)opTensor->getHeight(), (long unsigned int)opTensor->getChannels(), 
(long unsigned int)opTensor->getBatchSize() * opTensor->getSequenceLength()), 
1, arm_compute::DataType::F32)); assert((concatLayer->dimension == 1 || 
concatLayer->dimension == 2) || concatLayer->dimension == 3);
#if defined(USE_18_05_LIBRARY)
 m_depthConcatenateLayer->configure(concatInputs, getCurrentLayerOpArmTensor());
#else
 if (concatLayer->dimension == 3) { 
m_depthConcatenateLayer->configure(concatInputs, getCurrentLayerOpArmTensor()); 
} else { m_concatenateLayer->configure(concatInputs, 
getCurrentLayerOpArmTensor(), concatdimensionmap.at(concatLayer->dimension)); }
#endif
 return; } MWConcatenationLayerImpl::~MWConcatenationLayerImpl() { } void 
MWConcatenationLayerImpl::predict() { MWConcatenationLayer* concatLayer = 
static_cast<MWConcatenationLayer*>(getLayer()); 
prepareIpArmTensorsForPredict(); for(int i = 0; i < reshapeCount; i++){ 
m_reshapeKernel[i]->run(); }
#if defined(USE_18_05_LIBRARY)
 m_depthConcatenateLayer->run();
#else
 if (concatLayer->dimension == 3) { m_depthConcatenateLayer->run(); } else { 
m_concatenateLayer->run(); }
#endif
#if MW_CONCATENATE_TAP
 MWConcatenationLayer* concatLayer = 
static_cast<MWConcatenationLayer*>(getLayer()); MWTensorBase* opTensor = 
concatLayer->getOutputTensor(); mw_interm_tap(*getCurrentLayerOpArmTensor(), 
opTensor->getNumElements(), tap_count++);
#endif
 return; } void MWConcatenationLayerImpl::allocate() { int numInputs = 
getLayer()->getNumInputs(); for(int i = 0; i < numInputs; i++){ 
if(m_isIpArmTensorReshaped[i]){ 
m_layerInputArmTensor[i]->allocator()->allocate(); } } } void 
MWConcatenationLayerImpl::deallocate() { int numInputs = 
getLayer()->getNumInputs(); for(int i = 0; i < numInputs; i++){ 
if(m_isIpArmTensorReshaped[i]){ m_layerInputArmTensor[i]->allocator()->free(); 
} } m_layerInputArmTensor.clear(); m_isIpArmTensorReshaped.clear(); 
m_reshapeKernel.clear(); }