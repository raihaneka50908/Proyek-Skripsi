#include "MWSplittingLayerImpl.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"
#include "MWSplittingLayer.hpp"
#include <math.h>
#include <cassert>
#include <cstring>
 MWSplittingLayerImpl::MWSplittingLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, int numOutputs, int* ) : MWCNNLayerImpl(layer, 
ntwk_impl) , gNROjwaqhxDPvBWUCUcQ(numOutputs) { bERCRkGjpaKXMNComoYl = 
true; } MWSplittingLayerImpl::~MWSplittingLayerImpl() { } void 
MWSplittingLayerImpl::predict() { MWTensorBase* ipTensorBase = 
getLayer()->getInputTensor(0); MWTensor<float>* ipTensor = 
static_cast<MWTensor<float>*>(ipTensorBase); float* memory_ip = 
static_cast<float*>(getUnpaddedIpData(ipTensorBase)); auto prevLayerarmTensor = 
MWACLUtils::getLayerOpArmTensor(ipTensorBase); if(prevLayerarmTensor && 
prevLayerarmTensor->info()->has_padding()){ 
MWACLUtils::fillTensorToBuffer(memory_ip, *prevLayerarmTensor);  } long int 
ipMemOffset = 0; long int npaEYSaGsfCvAUhwdtLe = 
ipTensor->getHeight() * ipTensor->getWidth(); for (int i = 0; i < 
this->gNROjwaqhxDPvBWUCUcQ; i++) { MWTensorBase* opTensorBase = 
getLayer()->getOutputTensor(i); MWTensor<float>* opTensor = 
static_cast<MWTensor<float>*>(opTensorBase); float* memory_op = 
opTensor->getData(); long int mbKaFvmHqfBiTISNPGKJ = 
opTensor->getChannels() * npaEYSaGsfCvAUhwdtLe; 
std::memcpy(memory_op, memory_ip+ ipMemOffset, sizeof(float) * 
mbKaFvmHqfBiTISNPGKJ); ipMemOffset += (mbKaFvmHqfBiTISNPGKJ); }
#if MW_SPLIT_TAP
 for (int i = 0; i < this->gNROjwaqhxDPvBWUCUcQ; i++) { MWTensorBase* 
opTensorBase = getLayer()->getOutputTensor(i); MWTensor<float>* opTensor = 
static_cast<MWTensor<float>*>(opTensorBase); mw_interm_tap(opTensor->getData(), 
opTensorBase->getNumElements(), tap_count++); }
#endif
 return; }