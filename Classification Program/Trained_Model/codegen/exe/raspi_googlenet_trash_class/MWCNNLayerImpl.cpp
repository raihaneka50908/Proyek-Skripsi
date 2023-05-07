#include "MWCNNLayerImpl.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"
#include <cassert>
#include <cstring>
#include <stdio.h>
#if MW_LAYERS_TAP
 extern void mw_interm_tap(arm_compute::Tensor& armTensor, int size, int 
count); extern void mw_interm_tap(float* memBuf, int size, int count); extern 
int tap_count;
#endif
 MWCNNLayerImpl::MWCNNLayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* 
ntwk_impl) : bOrQjJTNlssnrexxbHdi(layer) , edQOkUJIZbwzEeIcCLzG(ntwk_impl) { } 
template <class T> void MWCNNLayerImpl::allocateOutputData(int outIdx) { int 
inIdx = getLayer()->getInPlaceIndex(outIdx); MWTensorBase* opTensorBase = 
getLayer()->getOutputTensor(outIdx); MWTensor<T>* opTensor = 
static_cast<MWTensor<T>*>(opTensorBase); if(m_useIpUnPaddedMemForOp && inIdx != 
-1){ assert(inIdx!=-1); MWTensorBase* ipTensorBase = 
getLayer()->getInputTensor(inIdx); T* ipData = 
(T*)getUnpaddedIpData(ipTensorBase); opTensor->setData(ipData); } else 
if(this->isHandCodedLayer()){ allocateHandCodedLayerOpData<T>(outIdx); } else{ 
allocateACLLayerOpData<T>(outIdx); } } template <class T> void 
MWCNNLayerImpl::allocateACLLayerOpData(int outIdx){ MWTensorBase* opTensorBase 
= getLayer()->getOutputTensor(outIdx); MWTensor<T>* opTensor = 
static_cast<MWTensor<T>*>(opTensorBase); int outBufIndex = 
opTensor->getopBufIndex(); int inIdx = getLayer()->getInPlaceIndex(outIdx); 
auto currLayerOpArmTensor = getCurrentLayerOpArmTensor(outIdx); if(inIdx == 
-1){ if (outBufIndex < 0) {  
getCurrentLayerOpArmTensor(outIdx)->allocator()->allocate(); } else {
#if defined(USE_18_11_LIBRARY) || defined(USE_19_02_LIBRARY)
 getCurrentLayerOpArmTensor(outIdx)->allocator()->import_memory( 
edQOkUJIZbwzEeIcCLzG->memBuffer[outBufIndex],edQOkUJIZbwzEeIcCLzG->maxBufSize *sizeof(T));
#elif defined(USE_19_05_LIBRARY)
 getCurrentLayerOpArmTensor(outIdx)->allocator()->import_memory( edQOkUJIZbwzEeIcCLzG->memBuffer[outBufIndex]);
#else
 getCurrentLayerOpArmTensor(outIdx)->allocator()->import_memory( arm_compute::Memory(edQOkUJIZbwzEeIcCLzG->memBuffer[outBufIndex]));
#endif
 } } else{  MWTensorBase* ipTensorBase = getLayer()->getInputTensor(inIdx); 
auto ipArmTensor = getCurrentLayerIpArmTensor(inIdx); auto opArmTensor = 
getCurrentLayerOpArmTensor(outIdx); if(ipArmTensor != opArmTensor){ T* 
ipArmTensorData = (T*)ipArmTensor->buffer();
#if defined(USE_18_11_LIBRARY) || defined(USE_19_02_LIBRARY)
 getCurrentLayerOpArmTensor(outIdx)->allocator()->import_memory( 
ipArmTensorData, edQOkUJIZbwzEeIcCLzG->maxBufSize *sizeof(T));
#elif defined(USE_19_05_LIBRARY)
 getCurrentLayerOpArmTensor(outIdx)->allocator()->import_memory( ipArmTensorData);
#else
 getCurrentLayerOpArmTensor(outIdx)->allocator()->allocate();
#endif
 } } opTensor->setData((T*)getCurrentLayerOpArmTensor(outIdx)->buffer()); } 
template <class T> void MWCNNLayerImpl::allocateHandCodedLayerOpData(int 
outIdx){ MWTensorBase* opTensorBase = getLayer()->getOutputTensor(outIdx); 
MWTensor<T>* opTensor = static_cast<MWTensor<T>*>(opTensorBase); int 
outBufIndex = opTensor->getopBufIndex(); int inIdx = 
getLayer()->getInPlaceIndex(outIdx); if (outBufIndex < 0) {  if(inIdx != -1){  
MWTensorBase* ipTensorBase = getLayer()->getInputTensor(inIdx); MWTensor<T>* 
ipTensor = static_cast<MWTensor<T>*>(ipTensorBase); T* ipData = 
ipTensor->getData(); opTensor->setData(ipData); } else{  int 
fylVqSnTjNbHDtlPhzaj = opTensorBase->getNumElements(); 
opTensor->setData((T*)calloc(fylVqSnTjNbHDtlPhzaj, sizeof(T))); } } else { 
auto opBuffer = GET_BUFFER(edQOkUJIZbwzEeIcCLzG->memBuffer[outBufIndex]); 
opTensor->setData((T*)opBuffer); } } template void 
MWCNNLayerImpl::allocateOutputData<float>(int); template void 
MWCNNLayerImpl::allocateOutputData<signed char>(int); template <class T> void 
MWCNNLayerImpl::deallocateOutputData(int outIdx) { MWTensorBase* opTensorBase = 
getLayer()->getOutputTensor(outIdx); MWTensor<T>* opTensor = 
static_cast<MWTensor<T>*>(opTensorBase); int inPlaceIdx = 
getLayer()->getInPlaceIndex(outIdx); int opBufIdx = opTensor->getopBufIndex(); 
if(opBufIdx < 0 && inPlaceIdx == -1){ if(this->isHandCodedLayer()){ T* 
opDataBuf = opTensor->getData(); if (opDataBuf) { free(opDataBuf); } } 
opTensor->setData((T*)NULL);  } } template void 
MWCNNLayerImpl::deallocateOutputData<float>(int); template void 
MWCNNLayerImpl::deallocateOutputData<signed char>(int); void 
MWCNNLayerImpl::allocateInputData(int inIdx) { MWTensorBase* ipTensor = 
getLayer()->getInputTensor(inIdx); if (ipTensor->isFloat()) { 
allocateInputDataImpl<float>(inIdx); } else { assert(ipTensor->isInt8()); 
allocateInputDataImpl<signed char>(inIdx); } } template <class T> void 
MWCNNLayerImpl::allocateInputDataImpl(int inIdx) { MWTensorBase* ipTensorBase = 
getLayer()->getInputTensor(inIdx); MWTensor<T>* ipTensor = 
static_cast<MWTensor<T>*>(ipTensorBase); auto prevLayerOpArmTensor = 
MWACLUtils::getLayerOpArmTensor(ipTensorBase); if(this->isHandCodedLayer()){  
if(prevLayerOpArmTensor != nullptr){ 
if(prevLayerOpArmTensor->info()->has_padding()){ 
setUnpaddedIpData<T>(ipTensorBase, (T*)calloc(ipTensor->getNumElements(), 
sizeof(T))); } else{ setUnpaddedIpData<T>(ipTensorBase, 
(T*)prevLayerOpArmTensor->buffer()); } } else{ 
setUnpaddedIpData<T>(ipTensorBase, (T*)ipTensor->getData()); } } else{  
if(prevLayerOpArmTensor == nullptr){ 
if(getCurrentLayerIpArmTensor(inIdx)->info()->has_padding()){ 
getCurrentLayerIpArmTensor(inIdx)->allocator()->allocate(); } else{ T* ipData = (T*)ipTensor->getData();
#if defined(USE_18_05_LIBRARY) || defined(USE_18_08_LIBRARY)
 getCurrentLayerIpArmTensor(inIdx)->allocator()->allocate();
#elif defined(USE_19_05_LIBRARY)
 getCurrentLayerIpArmTensor(inIdx)->allocator()->import_memory(ipData);
#else
 getCurrentLayerIpArmTensor(inIdx)->allocator()->import_memory(ipData, ipTensorBase->getNumElements());
#endif
 } } } } template void MWCNNLayerImpl::allocateInputDataImpl<float>(int); 
template void MWCNNLayerImpl::allocateInputDataImpl<signed char>(int); void 
MWCNNLayerImpl::deallocateInputData(int inIdx) { MWTensorBase* ipTensorBase = 
getLayer()->getInputTensor(inIdx); if (ipTensorBase->isFloat()) { 
deallocateInputDataImpl<float>(inIdx); } else { assert(ipTensorBase->isInt8()); 
deallocateInputDataImpl<signed char>(inIdx); } } template <class T> void 
MWCNNLayerImpl::deallocateInputDataImpl(int inIdx){ MWTensorBase* ipTensorBase 
= getLayer()->getInputTensor(inIdx); MWTensor<T>* ipTensor = 
static_cast<MWTensor<T>*>(ipTensorBase); auto prevLayerOpArmTensor = 
MWACLUtils::getLayerOpArmTensor(ipTensor); if(this->isHandCodedLayer()){  
if(prevLayerOpArmTensor != nullptr && 
prevLayerOpArmTensor->info()->has_padding()){ T* ipDataBuf = 
(T*)getUnpaddedIpData(ipTensorBase); if (ipDataBuf) { free(ipDataBuf); 
setUnpaddedIpData<T>(ipTensorBase, (T*)NULL); } } } } template void 
MWCNNLayerImpl::deallocateInputDataImpl<float>(int); template void 
MWCNNLayerImpl::deallocateInputDataImpl<signed char>(int); template <class T> 
void MWCNNLayerImpl::setUnpaddedIpData(MWTensorBase* aTensor, T* bufPtr){ 
YNDVziqpDddiXQKYZZhX[aTensor] = (T*)bufPtr; } void* 
MWCNNLayerImpl::getUnpaddedIpData(MWTensorBase* aTensor){ 
if(YNDVziqpDddiXQKYZZhX.size() >= 1){ return 
YNDVziqpDddiXQKYZZhX[aTensor]; } else{ return NULL; } } void 
MWCNNLayerImpl::setupIpArmTensors(){ int numInputs = 
static_cast<int>(getLayer()->getNumInputs()); for(int inIdx=0; inIdx<numInputs; 
inIdx++){ MWTensorBase* ipTensor = getLayer()->getInputTensor(inIdx); auto 
prevLayerOpArmTensorSharedPtr = 
MWACLUtils::getLayerOpArmTensorsharedPtr(ipTensor); 
if(prevLayerOpArmTensorSharedPtr){ 
setCurrentLayerIpArmTensor(prevLayerOpArmTensorSharedPtr, inIdx); } else{ 
setCurrentLayerIpArmTensor(std::make_shared<arm_compute::Tensor>(), inIdx); } } 
} void MWCNNLayerImpl::configureIpArmTensors(){ int numInputs = 
getLayer()->getNumInputs(); for(int inIdx=0; inIdx<numInputs ; inIdx++){ 
MWTensorBase* ipTensor = getLayer()->getInputTensor(inIdx); auto 
prevLayerOpArmTensor = MWACLUtils::getLayerOpArmTensor(ipTensor); 
if(prevLayerOpArmTensor == nullptr){ 
getCurrentLayerIpArmTensor(inIdx)->allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)ipTensor->getWidth(), (long 
unsigned int)ipTensor->getHeight(), (long unsigned int)ipTensor->getChannels(), 
(long unsigned int)ipTensor->getBatchSize() * (long unsigned 
int)ipTensor->getSequenceLength()), 1, arm_compute::DataType::F32)); } } } void 
MWCNNLayerImpl::prepareIpArmTensorsForPredict(){ int numInputs = 
getLayer()->getNumInputs(); for(int inIdx=0; inIdx<numInputs; inIdx++){ 
MWTensorBase* ipTensorBase = getLayer()->getInputTensor(inIdx); 
MWTensor<float>* ipTensor = static_cast<MWTensor<float>*>(ipTensorBase); auto 
prevLayerOpArmTensor = MWACLUtils::getLayerOpArmTensor(ipTensor); auto 
currLayerIpArmTensor = getCurrentLayerIpArmTensor(inIdx); float* ipData = 
ipTensor->getData(); if(prevLayerOpArmTensor==nullptr){ 
if(currLayerIpArmTensor->info()->has_padding()){ 
MWACLUtils::fillBufferToTensor(ipData, *currLayerIpArmTensor); } else{
#if defined(USE_18_05_LIBRARY) | defined(USE_18_08_LIBRARY)
 float* ipArmTensorBuffer = (float*)currLayerIpArmTensor->buffer(); 
memcpy(ipArmTensorBuffer, ipData, ipTensorBase->getNumElements()*sizeof(float));
#endif
 } } }  } std::string MWCNNLayerImpl::getLinuxPath(const char* fileName) { 
std::string fileS(fileName); std::string key ("\\"); std::size_t found = 0; 
while(found != std::string::npos){ found = fileS.rfind(key); if 
(found!=std::string::npos) fileS.replace (found,key.length(),"/"); } return 
fileS; } void 
MWCNNLayerImpl::setCurrentLayerOpArmTensor(std::shared_ptr<arm_compute::Tensor> 
tensor, int index) { lHtftnmGBvlSSoGOXVui[index] = tensor; } 
arm_compute::Tensor* MWCNNLayerImpl::getCurrentLayerOpArmTensor(int index) { if 
(lHtftnmGBvlSSoGOXVui.size() >= 1) { return 
lHtftnmGBvlSSoGOXVui[index].get(); } else { return nullptr; } } 
std::shared_ptr<arm_compute::Tensor> 
MWCNNLayerImpl::getCurrentLayerOpArmTensorSharedPtr(int index) { if 
(lHtftnmGBvlSSoGOXVui.size() >= 1) { return 
lHtftnmGBvlSSoGOXVui[index]; } else { return nullptr; } } void 
MWCNNLayerImpl::setCurrentLayerIpArmTensor(std::shared_ptr<arm_compute::Tensor> 
tensor, int index){ VenwEUlYwOBrwLVUhgUH[index] = tensor; } 
arm_compute::Tensor* MWCNNLayerImpl::getCurrentLayerIpArmTensor(int index) { 
if(VenwEUlYwOBrwLVUhgUH.size() >= 1 ){ return 
VenwEUlYwOBrwLVUhgUH[index].get(); } else{ return nullptr; } } 
std::shared_ptr<arm_compute::Tensor> 
MWCNNLayerImpl::getCurrentLayerIpArmTensorSharedPtr(int index) { 
if(VenwEUlYwOBrwLVUhgUH.size() >= 1 ){ return 
VenwEUlYwOBrwLVUhgUH[index]; } else{ return nullptr; } } 
MWInputLayerImpl::MWInputLayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* 
ntwk_impl) : MWCNNLayerImpl(layer, ntwk_impl) { bERCRkGjpaKXMNComoYl = 
true; } void MWInputLayerImpl::predict() {
#if MW_INPUT_TAP
 MWInputLayer* inpLayer = static_cast<MWInputLayer*>(getLayer()); MWTensorBase* 
opTensorBase = inpLayer->getOutputTensor(0); MWTensor<float>* opTensor = 
static_cast<MWTensor<float>*>(opTensorBase); mw_interm_tap(opTensor->getData(), 
opTensor->getNumElements(), tap_count++);
#endif
 return; } MWReLULayerImpl::MWReLULayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl) : MWCNNLayerImpl(layer, ntwk_impl) { 
setupIpArmTensors(); int inIdx = getLayer()->getInPlaceIndex(0); if(inIdx != 
-1){ assert(inIdx == 0); MWTensorBase* ipTensor = 
getLayer()->getInputTensor(inIdx); 
setCurrentLayerOpArmTensor(getCurrentLayerIpArmTensorSharedPtr()); }else{ 
setCurrentLayerOpArmTensor(std::make_shared<arm_compute::Tensor>()); } } 
MWReLULayerImpl::~MWReLULayerImpl() { } void MWReLULayerImpl::propagateSize() { 
MWReLULayer* reluLayer = static_cast<MWReLULayer*>(getLayer()); MWTensorBase* 
ipTensor = reluLayer->getInputTensor(); MWTensorBase* opTensor = 
reluLayer->getOutputTensor(); m_actLayer = 
std::unique_ptr<arm_compute::NEActivationLayer>(new 
arm_compute::NEActivationLayer); configureIpArmTensors(); arm_compute::Tensor* 
prevLayerarmTensor = getCurrentLayerIpArmTensor(); 
if(getLayer()->getInPlaceIndex(0) == -1){ bool doesPrevLayerHas2DArmTensor = 
prevLayerarmTensor->info()->num_dimensions() <= 2 && ipTensor->getHeight() == 1 
&& ipTensor->getWidth()==1; if (doesPrevLayerHas2DArmTensor) { 
getCurrentLayerOpArmTensor()->allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)opTensor->getChannels(), (long 
unsigned int)(opTensor->getSequenceLength()*opTensor->getBatchSize())), 1, 
arm_compute::DataType::F32)); } else { 
getCurrentLayerOpArmTensor()->allocator()->init( 
arm_compute::TensorInfo(arm_compute::TensorShape((long unsigned 
int)ipTensor->getWidth(), (long unsigned int)ipTensor->getHeight(), (long 
unsigned int)opTensor->getChannels(), (long unsigned 
int)(opTensor->getSequenceLength()*opTensor->getBatchSize())), 1, 
arm_compute::DataType::F32)); } } m_actLayer->configure(prevLayerarmTensor, 
getCurrentLayerOpArmTensor(), 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo::ActivationFunction::RELU)); 
return; } void MWReLULayerImpl::predict() { MWReLULayer* reluLayer = 
static_cast<MWReLULayer*>(getLayer()); MWTensorBase* opTensorBase = 
reluLayer->getOutputTensor(); prepareIpArmTensorsForPredict(); m_actLayer->run();
#if MW_RELU_TAP
 mw_interm_tap(*getCurrentLayerOpArmTensor(), opTensorBase->getNumElements(), tap_count++);
#endif
 return; } MWNormLayerImpl::MWNormLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, unsigned GZGFVDrXwFLJleoTDywO,  double 
AVeZfqOFypgpiqfRYlKc,  double AdmgfUbRAfzFeYHxSnQr,  double BlRIQPyqJZORKENzSdYf) : 
MWCNNLayerImpl(layer, ntwk_impl) , AVeZfqOFypgpiqfRYlKc(AVeZfqOFypgpiqfRYlKc) , 
AdmgfUbRAfzFeYHxSnQr(AdmgfUbRAfzFeYHxSnQr) , BlRIQPyqJZORKENzSdYf(BlRIQPyqJZORKENzSdYf) , 
GZGFVDrXwFLJleoTDywO(GZGFVDrXwFLJleoTDywO) { 
setupIpArmTensors(); 
setCurrentLayerOpArmTensor(std::make_shared<arm_compute::Tensor>()); } 
MWNormLayerImpl::~MWNormLayerImpl() { } void MWNormLayerImpl::propagateSize() { 
MWNormLayer* normLayer = static_cast<MWNormLayer*>(getLayer()); MWTensorBase* 
ipTensor = normLayer->getInputTensor(); m_normLayer = 
std::unique_ptr<arm_compute::NENormalizationLayer>(new 
arm_compute::NENormalizationLayer); configureIpArmTensors(); 
arm_compute::Tensor* prevLayerarmTensor = getCurrentLayerIpArmTensor(); 
m_isIpArmTensorReshaped = prevLayerarmTensor->info()->num_dimensions() <= 2 && 
ipTensor->getHeight() == 1 && ipTensor->getWidth()==1; 
if(m_isIpArmTensorReshaped){  m_layerInputArmTensor = 
std::make_shared<arm_compute::Tensor>(); 
m_layerInputArmTensor->allocator()->init( 
arm_compute::TensorInfo(arm_compute::TensorShape((long unsigned 
int)ipTensor->getWidth(), (long unsigned int)ipTensor->getHeight(), (long 
unsigned int)ipTensor->getChannels(), (long unsigned 
int)ipTensor->getBatchSize()), 1, arm_compute::DataType::F32)); m_reshapeKernel 
= std::unique_ptr<arm_compute::NEReshapeLayer>(new 
arm_compute::NEReshapeLayer); m_reshapeKernel->configure(prevLayerarmTensor, 
m_layerInputArmTensor.get()); } else{  m_layerInputArmTensor = 
getCurrentLayerIpArmTensorSharedPtr(); } 
getCurrentLayerOpArmTensor()->allocator()->init( 
arm_compute::TensorInfo(arm_compute::TensorShape((long unsigned 
int)ipTensor->getWidth(), (long unsigned int)ipTensor->getHeight(), (long 
unsigned int)ipTensor->getChannels(), (long unsigned 
int)ipTensor->getBatchSize()), 1, arm_compute::DataType::F32)); 
m_normLayer->configure(m_layerInputArmTensor.get(), 
getCurrentLayerOpArmTensor(), 
arm_compute::NormalizationLayerInfo(arm_compute::NormType::CROSS_MAP, 
GZGFVDrXwFLJleoTDywO, AVeZfqOFypgpiqfRYlKc, AdmgfUbRAfzFeYHxSnQr, 
BlRIQPyqJZORKENzSdYf)); return; } void MWNormLayerImpl::allocate(){ 
if(m_isIpArmTensorReshaped){ m_layerInputArmTensor->allocator()->allocate(); } 
return; } void MWNormLayerImpl::predict() { MWNormLayer* normLayer = 
static_cast<MWNormLayer*>(getLayer()); MWTensorBase* opTensorBase = 
normLayer->getOutputTensor(); prepareIpArmTensorsForPredict(); 
if(m_isIpArmTensorReshaped){ m_reshapeKernel->run(); } m_normLayer->run();
#if MW_NORM_TAP
 mw_interm_tap(*getCurrentLayerOpArmTensor(), opTensorBase->getNumElements(), tap_count++);
#endif
 return; } MWMaxPoolingLayerImpl::MWMaxPoolingLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, int GFggoMvRWucDMqzlWzCl,  int GIbahSoBBDrvvZduPEqU,  
int GLovsOhUpzOJhKgXUAJY,  int GLpnVFeGjOSrhNqnkdCu, int DRzwhbNPpftRRIXXfHzd, int 
DCdZnqpcBnvXVgEsLBnz,  int FshVHIJMRAhtQirYPlZd, int GDRXdUDklKFEYEfifhIH, 
bool GbdgxISzcqHOpzQEBrvP, int gNROjwaqhxDPvBWUCUcQ) : MWCNNLayerImpl(layer, 
ntwk_impl) , GFggoMvRWucDMqzlWzCl(GFggoMvRWucDMqzlWzCl) , 
GIbahSoBBDrvvZduPEqU(GIbahSoBBDrvvZduPEqU) , 
DRzwhbNPpftRRIXXfHzd(DRzwhbNPpftRRIXXfHzd) , 
DCdZnqpcBnvXVgEsLBnz(DCdZnqpcBnvXVgEsLBnz) , 
FshVHIJMRAhtQirYPlZd(FshVHIJMRAhtQirYPlZd) , 
GDRXdUDklKFEYEfifhIH(GDRXdUDklKFEYEfifhIH) , 
GLovsOhUpzOJhKgXUAJY(GLovsOhUpzOJhKgXUAJY) , 
GLpnVFeGjOSrhNqnkdCu(GLpnVFeGjOSrhNqnkdCu){ assert(gNROjwaqhxDPvBWUCUcQ == 1); 
assert(!GbdgxISzcqHOpzQEBrvP); setupIpArmTensors(); 
setCurrentLayerOpArmTensor(std::make_shared<arm_compute::Tensor>()); } 
MWMaxPoolingLayerImpl::~MWMaxPoolingLayerImpl() { } float* 
MWMaxPoolingLayerImpl::getIndexData() { assert(false); } void 
MWMaxPoolingLayerImpl::propagateSize() { MWMaxPoolingLayer* maxPoolLayer = 
static_cast<MWMaxPoolingLayer*>(getLayer()); MWTensorBase* ipTensor = 
maxPoolLayer->getInputTensor(); MWTensorBase* opTensor = 
maxPoolLayer->getOutputTensor(); m_maxPoolLayer = 
std::unique_ptr<arm_compute::NEPoolingLayer>(new arm_compute::NEPoolingLayer); 
configureIpArmTensors(); arm_compute::Tensor* prevLayerarmTensor = 
getCurrentLayerIpArmTensor(); if ((GFggoMvRWucDMqzlWzCl == -1) && (GIbahSoBBDrvvZduPEqU 
== -1)) { GFggoMvRWucDMqzlWzCl = ipTensor->getHeight(); GIbahSoBBDrvvZduPEqU = 
ipTensor->getWidth(); } 
getCurrentLayerOpArmTensor()->allocator()->init(arm_compute::TensorInfo(arm_compute::TensorShape((long 
unsigned int)opTensor->getWidth(), (long unsigned int)opTensor->getHeight(), 
(long unsigned int)opTensor->getChannels(), (long unsigned 
int)opTensor->getBatchSize()), 1, arm_compute::DataType::F32)); 
m_maxPoolLayer->configure( prevLayerarmTensor, getCurrentLayerOpArmTensor(), 
arm_compute::PoolingLayerInfo( arm_compute::PoolingType::MAX, 
arm_compute::Size2D(GIbahSoBBDrvvZduPEqU, GFggoMvRWucDMqzlWzCl), 
arm_compute::PadStrideInfo(GLpnVFeGjOSrhNqnkdCu, GLovsOhUpzOJhKgXUAJY, 
FshVHIJMRAhtQirYPlZd, GDRXdUDklKFEYEfifhIH, DRzwhbNPpftRRIXXfHzd, 
DCdZnqpcBnvXVgEsLBnz, arm_compute::DimensionRoundingType::FLOOR))); return; } 
void MWMaxPoolingLayerImpl::predict() { MWMaxPoolingLayer* maxPoolLayer = 
static_cast<MWMaxPoolingLayer*>(getLayer()); MWTensorBase* opTensorBase = 
maxPoolLayer->getOutputTensor(); prepareIpArmTensorsForPredict(); m_maxPoolLayer->run();
#if MW_POOL_TAP
 mw_interm_tap(*getCurrentLayerOpArmTensor(), opTensorBase->getNumElements(), tap_count++);
#endif
 return; } MWFCLayerImpl::MWFCLayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* 
ntwk_impl, int m_NumInputFeatures, int m_NumOutputFeatures, const char* 
m_weights_file,  const char* m_bias_file) : MWCNNLayerImpl(layer, ntwk_impl) { 
setupIpArmTensors(); 
setCurrentLayerOpArmTensor(std::make_shared<arm_compute::Tensor>()); int 
eqUIJyhXTwRqtPfXapcx = m_NumInputFeatures * m_NumOutputFeatures;  vpXxoeEhdEosLSsYXkNG = 
CREATE_BUFFER(eqUIJyhXTwRqtPfXapcx); KHjdvykTFbUxdfZTFbqy = 
CREATE_BUFFER(m_NumOutputFeatures); m_fcLayerWgtTensor.allocator()->init( 
arm_compute::TensorInfo(arm_compute::TensorShape((long unsigned 
int)(m_NumInputFeatures), (long unsigned int)(m_NumOutputFeatures)), 1, 
arm_compute::DataType::F32)); m_fcLayerBiasTensor.allocator()->init( 
arm_compute::TensorInfo(arm_compute::TensorShape((long unsigned 
int)(m_NumOutputFeatures)), 1, arm_compute::DataType::F32)); 
loadWeights(m_weights_file, eqUIJyhXTwRqtPfXapcx); loadBias(m_bias_file, 
m_NumOutputFeatures); } MWFCLayerImpl::~MWFCLayerImpl() { } void 
MWFCLayerImpl::propagateSize(){ MWFCLayer* fcLayer = 
static_cast<MWFCLayer*>(getLayer()); MWTensorBase* ipTensor = 
fcLayer->getInputTensor(); MWTensorBase* opTensor = fcLayer->getOutputTensor(); 
configureIpArmTensors(); arm_compute::Tensor* prevLayerarmTensor = 
getCurrentLayerIpArmTensor(); 
getCurrentLayerOpArmTensor()->allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)(opTensor->getWidth()* 
opTensor->getHeight()*opTensor->getChannels()), (long unsigned 
int)(opTensor->getBatchSize()* opTensor->getSequenceLength())), 1, 
arm_compute::DataType::F32)); m_fcLayer = 
std::unique_ptr<arm_compute::NEFullyConnectedLayer>(new 
arm_compute::NEFullyConnectedLayer); m_fcLayer->configure(prevLayerarmTensor, 
&m_fcLayerWgtTensor, &m_fcLayerBiasTensor, getCurrentLayerOpArmTensor()); 
prepareWeights(); return; } void MWFCLayerImpl::allocate(){ MWFCLayer* fcLayer 
= static_cast<MWFCLayer*>(getLayer()); MWTensorBase* ipTensor = 
fcLayer->getInputTensor(); MWTensorBase* opTensor = fcLayer->getOutputTensor(); 
int CTCbzQMDaLxINPbODdng = ipTensor->getChannels(); int 
CqtPRJvHlGJFssiPzsOm = opTensor->getChannels(); 
MWACLUtils::allocateAndFillTensor(m_fcLayerWgtTensor, vpXxoeEhdEosLSsYXkNG, 
CTCbzQMDaLxINPbODdng * CqtPRJvHlGJFssiPzsOm, isWgtsPadded); 
MWACLUtils::allocateAndFillTensor(m_fcLayerBiasTensor, KHjdvykTFbUxdfZTFbqy, 
CqtPRJvHlGJFssiPzsOm, isBiasPadded); return; } void 
MWFCLayerImpl::loadWeights(const char* QTXuPiGKeBUnmRzhlIDp, int eqUIJyhXTwRqtPfXapcx) 
{ float* wJyXsrUCMgxdIKVIJSyx = GET_BUFFER(vpXxoeEhdEosLSsYXkNG); std::string fileString = 
getLinuxPath(QTXuPiGKeBUnmRzhlIDp); FILE* RQSttSyDKXCHDWSijmNk = 
MWCNNLayer::openBinaryFile(fileString.c_str()); call_fread(wJyXsrUCMgxdIKVIJSyx, 
sizeof(float), eqUIJyhXTwRqtPfXapcx, RQSttSyDKXCHDWSijmNk, QTXuPiGKeBUnmRzhlIDp); 
fclose(RQSttSyDKXCHDWSijmNk); } void MWFCLayerImpl::prepareWeights(){ float* 
wvufwFZlsnpjbxmTBVYE = GET_BUFFER(vpXxoeEhdEosLSsYXkNG); MWFCLayer* fcLayer = 
static_cast<MWFCLayer*>(getLayer()); MWTensorBase* ipTensor = 
fcLayer->getInputTensor(); MWTensorBase* opTensor = fcLayer->getOutputTensor(); 
int CTCbzQMDaLxINPbODdng = ipTensor->getChannels() * 
ipTensor->getWidth() * ipTensor->getHeight(); int CqtPRJvHlGJFssiPzsOm 
= opTensor->getChannels(); int eqUIJyhXTwRqtPfXapcx = CTCbzQMDaLxINPbODdng * 
CqtPRJvHlGJFssiPzsOm;  if (ipTensor->getHeight() != 1 && 
ipTensor->getWidth() != 1) { float* wJyXsrUCMgxdIKVIJSyx = 
(float*)malloc(sizeof(float) * ipTensor->getHeight() * ipTensor->getWidth()); 
for (int k = 0; k < eqUIJyhXTwRqtPfXapcx / ipTensor->getHeight() / 
ipTensor->getWidth(); k++) { for (int i = 0; i < ipTensor->getHeight() * 
ipTensor->getWidth(); i++) wJyXsrUCMgxdIKVIJSyx[i] = wvufwFZlsnpjbxmTBVYE[k * 
ipTensor->getHeight() * ipTensor->getWidth() + i]; for (int j = 0; j < 
ipTensor->getHeight(); j++) for (int i = 0; i < ipTensor->getWidth(); i++) 
wvufwFZlsnpjbxmTBVYE[k * ipTensor->getHeight() * ipTensor->getWidth() + j * 
ipTensor->getWidth() + i] = wJyXsrUCMgxdIKVIJSyx[j + i * ipTensor->getHeight()]; } 
free(wJyXsrUCMgxdIKVIJSyx); } return; } void MWFCLayerImpl::loadBias(const char* 
QTXuPiGKeBUnmRzhlIDp, int CqtPRJvHlGJFssiPzsOm) { float* KZWeXiYFmdpQdsgidKeG = 
GET_BUFFER(KHjdvykTFbUxdfZTFbqy); std::string fileString = 
getLinuxPath(QTXuPiGKeBUnmRzhlIDp); FILE* RQSttSyDKXCHDWSijmNk = 
MWCNNLayer::openBinaryFile(fileString.c_str()); call_fread(KZWeXiYFmdpQdsgidKeG, 
sizeof(float), CqtPRJvHlGJFssiPzsOm, RQSttSyDKXCHDWSijmNk, 
QTXuPiGKeBUnmRzhlIDp); fclose(RQSttSyDKXCHDWSijmNk); return; } void 
MWFCLayerImpl::predict() { prepareIpArmTensorsForPredict(); m_fcLayer->run();
#if MW_FC_TAP
 MWTensorBase* opTensorBase = getLayer()->getOutputTensor(); 
mw_interm_tap(*getCurrentLayerOpArmTensor(), opTensorBase->getNumElements(), tap_count++);
#endif
 return; } void MWFCLayerImpl::deallocate() { if (isWgtsPadded){ 
m_fcLayerWgtTensor.allocator()->free(); isWgtsPadded = false; } if 
(isBiasPadded){ m_fcLayerBiasTensor.allocator()->free(); isWgtsPadded = false; 
} return; } void MWFCLayerImpl::cleanup() { FREE_BUFFER_MEMORY(vpXxoeEhdEosLSsYXkNG); 
FREE_BUFFER_MEMORY(KHjdvykTFbUxdfZTFbqy); return; } 
MWSoftmaxLayerImpl::MWSoftmaxLayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* 
ntwk_impl) : MWCNNLayerImpl(layer, ntwk_impl) , m_doesChannelwiseSoftmax(false) 
{ setupIpArmTensors(); 
setCurrentLayerOpArmTensor(std::make_shared<arm_compute::Tensor>()); } 
MWSoftmaxLayerImpl::~MWSoftmaxLayerImpl() { } void 
MWSoftmaxLayerImpl::propagateSize() { MWSoftmaxLayer* sfmxLayer = 
static_cast<MWSoftmaxLayer*>(getLayer()); MWTensorBase* ipTensor = 
sfmxLayer->getInputTensor(); MWTensorBase* opTensor = 
sfmxLayer->getOutputTensor(); m_softmaxLayer = 
std::unique_ptr<arm_compute::NESoftmaxLayer>(new arm_compute::NESoftmaxLayer); 
configureIpArmTensors(); arm_compute::Tensor* prevLayerarmTensor = 
getCurrentLayerIpArmTensor(); bool doesPrevLayerHas2DArmTensor = 
prevLayerarmTensor->info()->num_dimensions() <= 2 && ipTensor->getHeight() == 1 
&& ipTensor->getWidth()==1; if (doesPrevLayerHas2DArmTensor) { 
getCurrentLayerOpArmTensor()->allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)opTensor->getChannels(),  (long 
unsigned int)(opTensor->getBatchSize()*opTensor->getSequenceLength())), 1, 
arm_compute::DataType::F32)); } else { m_doesChannelwiseSoftmax = true; 
getCurrentLayerOpArmTensor()->allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)opTensor->getWidth(), (long 
unsigned int)opTensor->getHeight(), (long unsigned int)opTensor->getChannels(), 
(long unsigned int)(opTensor->getBatchSize()*opTensor->getSequenceLength())), 
1, arm_compute::DataType::F32)); } if (!m_doesChannelwiseSoftmax) { 
m_softmaxLayer->configure(prevLayerarmTensor, getCurrentLayerOpArmTensor()); } 
else { permuteToNHWC = std::unique_ptr<arm_compute::NEPermute>(new 
arm_compute::NEPermute); permuteToNCHW = 
std::unique_ptr<arm_compute::NEPermute>(new arm_compute::NEPermute); 
arm_compute::PermutationVector nhwcPermuteDims(2, 0, 1), nchwPermuteDims(1, 2, 
0); inputNHWCArmTensor.allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)ipTensor->getChannels(), (long 
unsigned int)ipTensor->getWidth(), (long unsigned int)ipTensor->getHeight(), 
1), 1, arm_compute::DataType::F32)); 
permuteToNHWC->configure(prevLayerarmTensor, &inputNHWCArmTensor, 
nhwcPermuteDims); 
tmpSfmaxNHWCArmTensor.allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)ipTensor->getChannels(), (long 
unsigned int)ipTensor->getWidth(), (long unsigned int)ipTensor->getHeight(), 
1), 1, arm_compute::DataType::F32)); 
m_softmaxLayer->configure(&inputNHWCArmTensor, &tmpSfmaxNHWCArmTensor); 
permuteToNCHW->configure(&tmpSfmaxNHWCArmTensor, getCurrentLayerOpArmTensor(), 
nchwPermuteDims); } return; } void MWSoftmaxLayerImpl::allocate() { if 
(m_doesChannelwiseSoftmax) { inputNHWCArmTensor.allocator()->allocate(); 
tmpSfmaxNHWCArmTensor.allocator()->allocate(); } return; } void 
MWSoftmaxLayerImpl::predict() { MWSoftmaxLayer* sfmxLayer = 
static_cast<MWSoftmaxLayer*>(getLayer()); MWTensorBase* opTensorBase = 
sfmxLayer->getOutputTensor(); prepareIpArmTensorsForPredict(); if 
(!m_doesChannelwiseSoftmax) { m_softmaxLayer->run(); } else {  
permuteToNHWC->run(); m_softmaxLayer->run(); permuteToNCHW->run(); }
#if MW_SFMX_TAP
 mw_interm_tap(*getCurrentLayerOpArmTensor(), opTensorBase->getNumElements(), tap_count++);
#endif
 return; } void MWSoftmaxLayerImpl::deallocate() { if 
(m_doesChannelwiseSoftmax) { inputNHWCArmTensor.allocator()->free(); 
tmpSfmaxNHWCArmTensor.allocator()->free(); } return; } 
MWAvgPoolingLayerImpl::MWAvgPoolingLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, int GFggoMvRWucDMqzlWzCl,  int GIbahSoBBDrvvZduPEqU,  
int GLovsOhUpzOJhKgXUAJY,  int GLpnVFeGjOSrhNqnkdCu,  int FpguQZSermqZCMRiUfML,  int 
CufLFODQDXTAPyRqYodN, int FLuSVNoPhAFKtLUchSvv, int FOcStuqCptsGIZXskVpC) : 
MWCNNLayerImpl(layer, ntwk_impl) , GFggoMvRWucDMqzlWzCl(GFggoMvRWucDMqzlWzCl) , 
GIbahSoBBDrvvZduPEqU(GIbahSoBBDrvvZduPEqU) , GLovsOhUpzOJhKgXUAJY(GLovsOhUpzOJhKgXUAJY) , 
GLpnVFeGjOSrhNqnkdCu(GLpnVFeGjOSrhNqnkdCu) , 
DRzwhbNPpftRRIXXfHzd(FpguQZSermqZCMRiUfML) , 
DCdZnqpcBnvXVgEsLBnz(CufLFODQDXTAPyRqYodN) , 
FshVHIJMRAhtQirYPlZd(FLuSVNoPhAFKtLUchSvv) , 
GDRXdUDklKFEYEfifhIH(FOcStuqCptsGIZXskVpC) { setupIpArmTensors(); 
setCurrentLayerOpArmTensor(std::make_shared<arm_compute::Tensor>()); } 
MWAvgPoolingLayerImpl::~MWAvgPoolingLayerImpl() { } void 
MWAvgPoolingLayerImpl::propagateSize() { MWAvgPoolingLayer* avgpoolLayer = 
static_cast<MWAvgPoolingLayer*>(getLayer()); MWTensorBase* opTensor = 
avgpoolLayer->getOutputTensor(); MWTensorBase* ipTensor = 
avgpoolLayer->getInputTensor(); m_avgPoolLayer = 
std::unique_ptr<arm_compute::NEPoolingLayer>(new arm_compute::NEPoolingLayer); 
if ((GFggoMvRWucDMqzlWzCl == -1) && (GIbahSoBBDrvvZduPEqU == -1)) { GFggoMvRWucDMqzlWzCl = 
ipTensor->getHeight(); GIbahSoBBDrvvZduPEqU = ipTensor->getWidth(); } 
configureIpArmTensors(); arm_compute::Tensor* prevLayerarmTensor = 
getCurrentLayerIpArmTensor(); 
getCurrentLayerOpArmTensor()->allocator()->init(arm_compute::TensorInfo(arm_compute::TensorShape((long 
unsigned int)opTensor->getWidth(), (long unsigned int)opTensor->getHeight(), 
(long unsigned int)opTensor->getChannels(), (long unsigned 
int)opTensor->getBatchSize()), 1, arm_compute::DataType::F32)); 
m_avgPoolLayer->configure( prevLayerarmTensor, getCurrentLayerOpArmTensor(), 
arm_compute::PoolingLayerInfo( arm_compute::PoolingType::AVG, 
arm_compute::Size2D(GIbahSoBBDrvvZduPEqU, GFggoMvRWucDMqzlWzCl), 
arm_compute::PadStrideInfo(GLpnVFeGjOSrhNqnkdCu, GLovsOhUpzOJhKgXUAJY, 
FshVHIJMRAhtQirYPlZd, GDRXdUDklKFEYEfifhIH, DRzwhbNPpftRRIXXfHzd, 
DCdZnqpcBnvXVgEsLBnz, arm_compute::DimensionRoundingType::FLOOR))); return ; } 
void MWAvgPoolingLayerImpl::predict() { prepareIpArmTensorsForPredict(); m_avgPoolLayer->run();
#if MW_AVG_POOL_TAP
 MWTensorBase* opTensorBase = getLayer()->getOutputTensor(); 
mw_interm_tap(*getCurrentLayerOpArmTensor(), opTensorBase->getNumElements(), tap_count++);
#endif
 return; } MWOutputLayerImpl::MWOutputLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl) : MWCNNLayerImpl(layer, ntwk_impl) { 
bERCRkGjpaKXMNComoYl = true; m_useIpUnPaddedMemForOp = true; } 
MWOutputLayerImpl::~MWOutputLayerImpl() { } void MWOutputLayerImpl::predict() { 
MWOutputLayer* opLayer = static_cast<MWOutputLayer*>(getLayer()); MWTensorBase* 
ipTensorBase = opLayer->getInputTensor(0); MWTensorBase* opTensorBase = 
opLayer->getOutputTensor(0); MWTensor<float>* opTensor = 
static_cast<MWTensor<float>*>(opTensorBase); auto prevLayerarmTensor = 
MWACLUtils::getLayerOpArmTensor(ipTensorBase); if (prevLayerarmTensor && 
prevLayerarmTensor->info()->has_padding()) { 
MWACLUtils::fillTensorToBuffer(opTensor->getData(), *prevLayerarmTensor); } 
return; }