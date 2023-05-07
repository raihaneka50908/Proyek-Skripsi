#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"
#include "MWCNNLayerImpl.hpp"
 void MWTargetNetworkImpl::allocate(int numBufsToAlloc, MWCNNLayer* 
layers[],int numLayers) { numBufs = numBufsToAlloc; size_t 
maxCustomLayerBufSize = 0; for (int i = 0; i < numLayers; i++) { if 
(layers[i]->isCustomLayer()) { size_t layerBufSize = 
(size_t)layers[i]->getOutputTensor()->getNumElements(); maxCustomLayerBufSize = 
(maxCustomLayerBufSize < layerBufSize) ? layerBufSize : maxCustomLayerBufSize; 
} } maxBufSize = maxCustomLayerBufSize; for(int i = 0; i < numLayers; i++) { 
auto owningLayerImpl = layers[i]->getImpl(); if (owningLayerImpl != nullptr){ 
auto currLayerOpARMTensor = owningLayerImpl->getCurrentLayerOpArmTensor(); 
if(currLayerOpARMTensor){ size_t layerBufSize = 
(size_t)((layers[i]->getImpl()->getCurrentLayerOpArmTensor()->info()->total_size()) 
/ sizeof(float)); maxBufSize = (maxBufSize < layerBufSize) ? layerBufSize : 
maxBufSize; } else{ size_t layerBufSize = 
(size_t)layers[i]->getOutputTensor()->getNumElements(); maxBufSize = 
(maxBufSize < layerBufSize) ? layerBufSize : maxBufSize; } } } for(int i = 0; i 
< numBufs; i++) { ALLOCATE_MEMORY_BUFFER(); } } void 
MWTargetNetworkImpl::allocatePermuteBuffers(int bufSize, int numBufsToAlloc) { 
for (int i = 0; i < numBufsToAlloc; i++) { float* memPtr = 0; memPtr = 
(float*)calloc(bufSize, sizeof(float)); 
osBZbKVTgXwTSsGSbdth.push_back(memPtr); } } float* 
MWTargetNetworkImpl::getPermuteBuffer(int bufIndex) { return 
osBZbKVTgXwTSsGSbdth[bufIndex]; } float* 
MWTargetNetworkImpl::getLayerOutput(MWCNNLayer* layers[], int layerIndex, int 
portIndex) { MWTensorBase* opTensor = 
layers[layerIndex]->getOutputTensor(portIndex); float* opData = 
getLayerActivation(opTensor); return opData; } float* 
MWTargetNetworkImpl::getLayerActivation(MWTensorBase* opTensorBase){ 
MWTensor<float>* opTensor = static_cast<MWTensor<float>*>(opTensorBase); auto 
owningLayer = opTensor->getOwner(); MWCNNLayerImpl* layerImpl = 
owningLayer->getImpl(); if(layerImpl == NULL){  
if(owningLayer->isCustomLayer()){ return 
static_cast<MWTensor<float>*>(opTensorBase)->getData(); } else{ return 
getLayerActivation(opTensor->getOwner()->getInputTensor()); } } else{ if 
(layerImpl->isHandCodedLayer()) { return 
static_cast<MWTensor<float>*>(opTensorBase)->getData(); } else { 
arm_compute::Tensor* currLayerArmTensor = 
layerImpl->getCurrentLayerOpArmTensor(); int layerOutputSize = 
opTensor->getNumElements(); float* m_data = (float*)malloc(sizeof(float) * 
layerOutputSize); MWACLUtils::fillTensorToBuffer(m_data, *currLayerArmTensor); 
memcpy(opTensor->getData(), m_data, layerOutputSize * sizeof(float)); 
free(m_data); return opTensor->getData(); } } } void 
MWTargetNetworkImpl::createWorkSpace(float** zRhMJbzYfMHEzDwdpDGW) { } void 
MWTargetNetworkImpl::setWorkSpaceSize(size_t wss) { } size_t* 
MWTargetNetworkImpl::getWorkSpaceSize() { return NULL; } float* 
MWTargetNetworkImpl::getWorkSpace() { return NULL; } void 
MWTargetNetworkImpl::deallocate() { for(int i = 0; i < memBuffer.size(); i++) { 
if(memBuffer[i] != nullptr) { FREE_MEMORY_BUFFER(); } } memBuffer.clear(); 
for(int i = 0; i < osBZbKVTgXwTSsGSbdth.size(); i++) { float *memPtr = 
osBZbKVTgXwTSsGSbdth[i]; if(memPtr) { free(memPtr); } } 
osBZbKVTgXwTSsGSbdth.clear(); } void MWTargetNetworkImpl::cleanup() { }