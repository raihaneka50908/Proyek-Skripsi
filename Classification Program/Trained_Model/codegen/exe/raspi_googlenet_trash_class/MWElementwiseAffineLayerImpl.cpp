#include "MWElementwiseAffineLayerImpl.hpp"
#include <cassert>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <arm_neon.h>
#if MW_AFFINE_TAP
 extern int tap_count; extern void mw_interm_tap(arm_compute::Tensor& 
armTensor, int size, int count); extern void mw_interm_tap(float* memBuf, int 
size, int count);
#endif
 MWElementwiseAffineLayerImpl::MWElementwiseAffineLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, int scale_H, int scale_W, int scale_C, int 
offset_H, int offset_W, int offset_C, bool isClipped, int lowerbound, int 
upperbound, const char* scale_file, const char* offset_file) : 
MWCNNLayerImpl(layer, ntwk_impl) , rISNTTiSXOTdHqHTtNiB(NULL) , 
iFWfUCwhmxBsOTMvFHgz(NULL) , rSiiAFiHROnqjxqoWutE(scale_H) , 
rrWNoFNRUEdlTvIOmCla(scale_W) , rMMjgjGRAiLVlTlRSByU(scale_C) , 
jHzoRQWaHafftmrmuvHO(offset_H) , kFQQPKSOkZeHlmrkAXuE(offset_W) , 
jHaoHEqZgMiwRsdCogKz(offset_C) , aFDPITUhkPdupMfPOBnd(isClipped) , 
dAGMlbhOYuZqhuDGCqih(lowerbound) , uznbYLhhKtdvhPWaHJnR(upperbound) { 
setupIpArmTensors(); int inIdx = getLayer()->getInPlaceIndex(0); if (inIdx != 
-1) { assert(inIdx == 0); MWTensorBase* ipTensor = 
getLayer()->getInputTensor(inIdx); 
setCurrentLayerOpArmTensor(getCurrentLayerIpArmTensorSharedPtr()); } else { 
setCurrentLayerOpArmTensor(std::make_shared<arm_compute::Tensor>()); } 
getScaleType(); getOffsetType(); long int rlQsibXJSWJVnUVpdNeL = (long 
int)(rSiiAFiHROnqjxqoWutE * rrWNoFNRUEdlTvIOmCla * rMMjgjGRAiLVlTlRSByU); long int 
jfkhqXBmwICFStMidrQt = (long int)(jHzoRQWaHafftmrmuvHO * kFQQPKSOkZeHlmrkAXuE * 
jHaoHEqZgMiwRsdCogKz); rISNTTiSXOTdHqHTtNiB = CREATE_BUFFER(rlQsibXJSWJVnUVpdNeL); 
iFWfUCwhmxBsOTMvFHgz = CREATE_BUFFER(jfkhqXBmwICFStMidrQt); loadScale(scale_file); 
loadOffset(offset_file); initScaleOffsetTensors();  } 
MWElementwiseAffineLayerImpl::~MWElementwiseAffineLayerImpl() { } void 
MWElementwiseAffineLayerImpl::propagateSize() { MWTensorBase* ipTensor = 
getLayer()->getInputTensor(0); MWTensorBase* opTensor = 
getLayer()->getOutputTensor(0); configureIpArmTensors(); arm_compute::Tensor* 
prevLayerarmTensor = getCurrentLayerIpArmTensor(); bool 
doesPrevLayerHas2DArmTensor = prevLayerarmTensor->info()->num_dimensions() <= 2 
&& ipTensor->getHeight() == 1 && ipTensor->getWidth() == 1; if 
(doesPrevLayerHas2DArmTensor) { 
getCurrentLayerOpArmTensor()->allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape( (long unsigned int)opTensor->getChannels(), (long 
unsigned int)(opTensor->getSequenceLength() * opTensor->getBatchSize())), 1, 
arm_compute::DataType::F32)); } else { 
getCurrentLayerOpArmTensor()->allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape( (long unsigned int)ipTensor->getWidth(), (long 
unsigned int)ipTensor->getHeight(), (long unsigned int)opTensor->getChannels(), 
(long unsigned int)(opTensor->getSequenceLength() * opTensor->getBatchSize())), 
1, arm_compute::DataType::F32)); } initTempAllocators();  if (isScaleScalar && 
isOffsetScalar) { m_actLayer = 
std::unique_ptr<arm_compute::NEActivationLayer>(new 
arm_compute::NEActivationLayer); m_actLayer->configure(prevLayerarmTensor, 
getCurrentLayerOpArmTensor(), 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo( 
arm_compute::ActivationLayerInfo::ActivationFunction::LINEAR, 
*GET_BUFFER(rISNTTiSXOTdHqHTtNiB), *GET_BUFFER(iFWfUCwhmxBsOTMvFHgz)))); } else if 
(isScaleVector && isOffsetVector) { m_depthwiseLayer = 
std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer>( new 
arm_compute::NEDepthwiseConvolutionLayer); m_depthwiseLayer->configure( 
prevLayerarmTensor, &scaleTensor, &offsetTensor, getCurrentLayerOpArmTensor(), 
arm_compute::PadStrideInfo(1, 1, 0, 0, 
arm_compute::DimensionRoundingType::FLOOR)); } else { createScaleAffine(); 
createOffsetAffine(); } } void 
MWElementwiseAffineLayerImpl::initScaleOffsetTensors() { if (!isScaleScalar) { 
scaleTensor.allocator()->init( 
arm_compute::TensorInfo(arm_compute::TensorShape((long unsigned 
int)rrWNoFNRUEdlTvIOmCla, (long unsigned int)rSiiAFiHROnqjxqoWutE, (long unsigned 
int)rMMjgjGRAiLVlTlRSByU), 1, arm_compute::DataType::F32)); } if 
(!isOffsetScalar) { offsetTensor.allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)kFQQPKSOkZeHlmrkAXuE, (long unsigned 
int)jHzoRQWaHafftmrmuvHO, (long unsigned int)jHaoHEqZgMiwRsdCogKz), 1, 
arm_compute::DataType::F32)); } if (isOffsetVector && !isScaleVector) { 
tmpScaleTensor.allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)kFQQPKSOkZeHlmrkAXuE, (long unsigned 
int)jHzoRQWaHafftmrmuvHO, (long unsigned int)jHaoHEqZgMiwRsdCogKz), 1, 
arm_compute::DataType::F32)); } } void 
MWElementwiseAffineLayerImpl::initTempAllocators() { MWTensorBase* ipTensor = 
getLayer()->getInputTensor(0); int eUSuiwvLvXVXrpUkgBVu = ipTensor->getBatchSize(); int 
NmExSIssnXpisMKKatUq = ipTensor->getChannels(); int RgjhbaFFVMpznMgMQMrE = 
ipTensor->getHeight(); int vpXxoeEhdEosLSsYXkNG = ipTensor->getWidth(); int 
qEXwbWWsnOADJeTXfRVa = ipTensor->getSequenceLength(); if (!((isScaleScalar && 
isOffsetScalar) || (isScaleVector && isOffsetVector))) { 
tmparmTensor.allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape( (long unsigned int)vpXxoeEhdEosLSsYXkNG, (long unsigned 
int)RgjhbaFFVMpznMgMQMrE, (long unsigned int)NmExSIssnXpisMKKatUq, (long unsigned 
int)(eUSuiwvLvXVXrpUkgBVu * qEXwbWWsnOADJeTXfRVa)), 1, arm_compute::DataType::F32)); } } void 
MWElementwiseAffineLayerImpl::createScaleAffine() { MWTensorBase* ipTensor = 
getLayer()->getInputTensor(0); arm_compute::Tensor* prevLayerarmTensor = 
getCurrentLayerIpArmTensor(0); if (isScaleScalar) { m_actLayer = 
std::unique_ptr<arm_compute::NEActivationLayer>(new 
arm_compute::NEActivationLayer); m_actLayer->configure(prevLayerarmTensor, 
&tmparmTensor, 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo( 
arm_compute::ActivationLayerInfo::ActivationFunction::LINEAR, 
*GET_BUFFER(rISNTTiSXOTdHqHTtNiB), 0))); } else if (isScaleVector) { 
m_depthwiseLayer = std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer>( 
new arm_compute::NEDepthwiseConvolutionLayer); m_depthwiseLayer->configure( 
prevLayerarmTensor, &scaleTensor, nullptr, &tmparmTensor, 
arm_compute::PadStrideInfo(1, 1, 0, 0, 
arm_compute::DimensionRoundingType::FLOOR)); } else if (isScaleMatrix) { 
m_prodLayer = std::unique_ptr<arm_compute::NEPixelWiseMultiplication>( new 
arm_compute::NEPixelWiseMultiplication); 
m_prodLayer->configure(prevLayerarmTensor, &scaleTensor, &tmparmTensor, 1, 
arm_compute::ConvertPolicy::WRAP, arm_compute::RoundingPolicy::TO_ZERO); } } 
void MWElementwiseAffineLayerImpl::createOffsetAffine() { if (isOffsetScalar) { 
m_actLayer = std::unique_ptr<arm_compute::NEActivationLayer>(new 
arm_compute::NEActivationLayer); m_actLayer->configure(&tmparmTensor, 
getCurrentLayerOpArmTensor(), 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo( 
arm_compute::ActivationLayerInfo::ActivationFunction::LINEAR, 1, 
*GET_BUFFER(iFWfUCwhmxBsOTMvFHgz)))); } else if (isOffsetVector) { 
m_depthwiseLayer = std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer>( 
new arm_compute::NEDepthwiseConvolutionLayer); m_depthwiseLayer->configure( 
&tmparmTensor, &tmpScaleTensor, &offsetTensor, getCurrentLayerOpArmTensor(), 
arm_compute::PadStrideInfo(1, 1, 0, 0, 
arm_compute::DimensionRoundingType::FLOOR)); } else if (isOffsetMatrix) { 
m_addLayer = std::unique_ptr<arm_compute::NEArithmeticAddition>( new 
arm_compute::NEArithmeticAddition); m_addLayer->configure(&tmparmTensor, 
&offsetTensor, getCurrentLayerOpArmTensor(), arm_compute::ConvertPolicy::WRAP); 
} } void MWElementwiseAffineLayerImpl::getScaleType() { if (rSiiAFiHROnqjxqoWutE 
== 1 && rrWNoFNRUEdlTvIOmCla == 1 && rMMjgjGRAiLVlTlRSByU == 1) { isScaleScalar = 
true; } else if (rSiiAFiHROnqjxqoWutE == 1 && rrWNoFNRUEdlTvIOmCla == 1 && 
rMMjgjGRAiLVlTlRSByU != 1) { isScaleVector = true; } else { isScaleMatrix = true; 
} } void MWElementwiseAffineLayerImpl::getOffsetType() { if 
(jHzoRQWaHafftmrmuvHO == 1 && kFQQPKSOkZeHlmrkAXuE == 1 && jHaoHEqZgMiwRsdCogKz == 
1) { isOffsetScalar = true; } else if (jHzoRQWaHafftmrmuvHO == 1 && 
kFQQPKSOkZeHlmrkAXuE == 1 && jHaoHEqZgMiwRsdCogKz != 1) { isOffsetVector = true; 
} else { isOffsetMatrix = true; } } void 
MWElementwiseAffineLayerImpl::allocate() { MWTensorBase* opTensor = 
getLayer()->getOutputTensor(0); if (isOffsetVector && !(isScaleVector)) { 
tmpScaleTensor.allocator()->allocate(); MWACLUtils::fillValueToTensor(1.0f, 
tmpScaleTensor); } if (!(isScaleScalar)) { MWACLUtils::allocateAndFillTensor( 
scaleTensor, rISNTTiSXOTdHqHTtNiB, rSiiAFiHROnqjxqoWutE * rrWNoFNRUEdlTvIOmCla * 
rMMjgjGRAiLVlTlRSByU, isScalePadded); } if (!(isOffsetScalar)) { 
MWACLUtils::allocateAndFillTensor( offsetTensor, iFWfUCwhmxBsOTMvFHgz, 
jHzoRQWaHafftmrmuvHO * kFQQPKSOkZeHlmrkAXuE * jHaoHEqZgMiwRsdCogKz, 
isOffsetPadded); } if (!((isScaleScalar && isOffsetScalar) || (isScaleVector && 
isOffsetVector))) { tmparmTensor.allocator()->allocate(); } return; } void 
MWElementwiseAffineLayerImpl::clipAffineOutput() { arm_compute::Tensor* tensor 
= getCurrentLayerOpArmTensor(); arm_compute::Window input_src_window; 
input_src_window.use_tensor_dimensions(tensor->info()->tensor_shape()); 
arm_compute::Iterator input_src(tensor, input_src_window); execute_window_loop( 
input_src_window, [&](const arm_compute::Coordinates& id) { float* inpPtr = 
reinterpret_cast<float*>(input_src.ptr()); *inpPtr = *inpPtr > 
uznbYLhhKtdvhPWaHJnR ? uznbYLhhKtdvhPWaHJnR : *inpPtr; *inpPtr = *inpPtr < 
dAGMlbhOYuZqhuDGCqih ? dAGMlbhOYuZqhuDGCqih : *inpPtr; }, input_src); } void 
MWElementwiseAffineLayerImpl::predict() { MWElementwiseAffineLayer* 
elAffineLayer = static_cast<MWElementwiseAffineLayer*>(getLayer()); 
MWTensorBase* opTensorBase = elAffineLayer->getOutputTensor(); 
prepareIpArmTensorsForPredict(); if ((isScaleScalar && isOffsetScalar)) { 
m_actLayer->run(); } else if (isScaleVector && isOffsetVector) { 
m_depthwiseLayer->run(); } else { if (isScaleScalar) { m_actLayer->run(); } 
else if (isScaleVector) { m_depthwiseLayer->run(); } else { m_prodLayer->run(); 
} if (isOffsetScalar) { m_actLayer->run(); } else if (isOffsetVector) { 
m_depthwiseLayer->run(); } else { m_addLayer->run(); } } if 
(aFDPITUhkPdupMfPOBnd) { clipAffineOutput(); }
#if MW_AFFINE_TAP
 mw_interm_tap(*getCurrentLayerOpArmTensor(), opTensorBase->getNumElements(), tap_count++);
#endif
 return; } void MWElementwiseAffineLayerImpl::deallocate() { MWTensorBase* 
opTensor = getLayer()->getOutputTensor(0); if (isOffsetVector && 
!(isScaleVector)) { tmpScaleTensor.allocator()->free(); } if (!(isScaleScalar)) 
{ if (isScalePadded) { scaleTensor.allocator()->free(); isScalePadded = false; 
} } if (!(isOffsetScalar)) { if (isOffsetPadded) { 
offsetTensor.allocator()->free(); isOffsetPadded = false; } } if 
(!((isScaleScalar && isOffsetScalar) || (isScaleVector && isOffsetVector))) { 
tmparmTensor.allocator()->free(); } return; } void 
MWElementwiseAffineLayerImpl::cleanup() { FREE_BUFFER_MEMORY(rISNTTiSXOTdHqHTtNiB); 
FREE_BUFFER_MEMORY(iFWfUCwhmxBsOTMvFHgz); return; } void 
MWElementwiseAffineLayerImpl::loadScale(const char* rxMAtVYGgGtZoKBkJcjc) { 
float* rIcMzXptfYweLArNRnBw = GET_BUFFER(rISNTTiSXOTdHqHTtNiB); FILE* RQSttSyDKXCHDWSijmNk = 
MWCNNLayer::openBinaryFile(rxMAtVYGgGtZoKBkJcjc); assert(RQSttSyDKXCHDWSijmNk); long 
int eqUIJyhXTwRqtPfXapcx = (long int)(rSiiAFiHROnqjxqoWutE * rrWNoFNRUEdlTvIOmCla * 
rMMjgjGRAiLVlTlRSByU); call_fread(rIcMzXptfYweLArNRnBw, sizeof(float), 
eqUIJyhXTwRqtPfXapcx, RQSttSyDKXCHDWSijmNk, rxMAtVYGgGtZoKBkJcjc); fclose(RQSttSyDKXCHDWSijmNk); 
return; } void MWElementwiseAffineLayerImpl::loadOffset(const char* 
kMyEnepVyoNObTPqIpWo) { float* iMyHYqdPsEjdhQptHQNt = 
GET_BUFFER(iFWfUCwhmxBsOTMvFHgz); FILE* RQSttSyDKXCHDWSijmNk = 
MWCNNLayer::openBinaryFile(kMyEnepVyoNObTPqIpWo); assert(RQSttSyDKXCHDWSijmNk); long 
int eqUIJyhXTwRqtPfXapcx = (long int)(jHzoRQWaHafftmrmuvHO * kFQQPKSOkZeHlmrkAXuE * 
jHaoHEqZgMiwRsdCogKz); call_fread(iMyHYqdPsEjdhQptHQNt, sizeof(float), 
eqUIJyhXTwRqtPfXapcx, RQSttSyDKXCHDWSijmNk, kMyEnepVyoNObTPqIpWo); fclose(RQSttSyDKXCHDWSijmNk); }