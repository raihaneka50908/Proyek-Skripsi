#include "MWFusedConvReLULayerImpl.hpp"
#include "MWFusedConvReLULayer.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"
#include <cassert>
#include <cstring>
#include <stdio.h>
#if MW_CONV_TAP
 extern void mw_interm_tap(arm_compute::Tensor& armTensor, int size, int 
count); extern void mw_interm_tap(float* memBuf, int size, int count); extern 
int tap_count;
#endif
 MWFusedConvReLULayerImpl::MWFusedConvReLULayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, int filt_H, int filt_W, int numGrps, int 
numChnls, int numFilts, int GLovsOhUpzOJhKgXUAJY, int GLpnVFeGjOSrhNqnkdCu, int 
DRzwhbNPpftRRIXXfHzd, int DCdZnqpcBnvXVgEsLBnz, int FshVHIJMRAhtQirYPlZd, 
int GDRXdUDklKFEYEfifhIH, int AuqaQHxmPQSyYRemQvyX, int 
BHuHNDGoRwGRouCxeMbw, int , const char* zFaEOIBQYqPoaerpaixN, const 
char* MgAiRWiTutoTMxKXjmHQ) : MWCNNLayerImpl(layer, ntwk_impl) , 
BdqURaHPmdnfzvtUvocl(filt_H) , BkwhtPQUCQKchmmimoXs(filt_W) , 
CCKWXUFWgrbBMjwfpOBN(numGrps) , GLovsOhUpzOJhKgXUAJY(GLovsOhUpzOJhKgXUAJY) , 
GLpnVFeGjOSrhNqnkdCu(GLpnVFeGjOSrhNqnkdCu) , 
DRzwhbNPpftRRIXXfHzd(DRzwhbNPpftRRIXXfHzd) , 
DCdZnqpcBnvXVgEsLBnz(DCdZnqpcBnvXVgEsLBnz) , 
FshVHIJMRAhtQirYPlZd(FshVHIJMRAhtQirYPlZd) , 
GDRXdUDklKFEYEfifhIH(GDRXdUDklKFEYEfifhIH) , 
AuqaQHxmPQSyYRemQvyX(AuqaQHxmPQSyYRemQvyX) , 
BHuHNDGoRwGRouCxeMbw(BHuHNDGoRwGRouCxeMbw) { setupIpArmTensors(); 
setCurrentLayerOpArmTensor(std::make_shared<arm_compute::Tensor>()); int 
eqUIJyhXTwRqtPfXapcx = numChnls * CCKWXUFWgrbBMjwfpOBN * numFilts * 
BdqURaHPmdnfzvtUvocl * BkwhtPQUCQKchmmimoXs; if (CCKWXUFWgrbBMjwfpOBN != 1 
&& numChnls == 1 && numFilts == 1) { 
m_fusedConvLayerWgtTensor.allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape( (long unsigned int)BkwhtPQUCQKchmmimoXs, (long 
unsigned int)BdqURaHPmdnfzvtUvocl, (long unsigned int)CCKWXUFWgrbBMjwfpOBN), 
1, arm_compute::DataType::F32)); } else { 
m_fusedConvLayerWgtTensor.allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape( (long unsigned int)BkwhtPQUCQKchmmimoXs, (long 
unsigned int)BdqURaHPmdnfzvtUvocl, (long unsigned int)numChnls, (long 
unsigned int)numFilts * CCKWXUFWgrbBMjwfpOBN), 1, arm_compute::DataType::F32)); 
} m_fusedConvLayerBiasTensor.allocator()->init( 
arm_compute::TensorInfo(arm_compute::TensorShape((long unsigned int)numFilts * 
CCKWXUFWgrbBMjwfpOBN), 1, arm_compute::DataType::F32)); vpXxoeEhdEosLSsYXkNG = 
CREATE_BUFFER(eqUIJyhXTwRqtPfXapcx); KHjdvykTFbUxdfZTFbqy = 
CREATE_BUFFER(CCKWXUFWgrbBMjwfpOBN * numFilts); 
loadWeights(zFaEOIBQYqPoaerpaixN, eqUIJyhXTwRqtPfXapcx); 
loadBias(MgAiRWiTutoTMxKXjmHQ, CCKWXUFWgrbBMjwfpOBN * numFilts); } 
MWFusedConvReLULayerImpl::~MWFusedConvReLULayerImpl() { } void 
MWFusedConvReLULayerImpl::propagateSize() { MWFusedConvReLULayer* 
FusedconvLayer = static_cast<MWFusedConvReLULayer*>(getLayer()); MWTensorBase* 
ipTensor = FusedconvLayer->getInputTensor(0); MWTensorBase* opTensor = 
FusedconvLayer->getOutputTensor(0); configureIpArmTensors(); 
arm_compute::Tensor* prevLayerarmTensor = getCurrentLayerIpArmTensor(); 
getCurrentLayerOpArmTensor()->allocator()->init(arm_compute::TensorInfo(arm_compute::TensorShape((long 
unsigned int)opTensor->getWidth(), (long unsigned int)opTensor->getHeight(), 
(long unsigned int)opTensor->getChannels(), (long unsigned 
int)opTensor->getBatchSize()), 1, arm_compute::DataType::F32)); if 
(CCKWXUFWgrbBMjwfpOBN != 1) { if (CCKWXUFWgrbBMjwfpOBN == 
ipTensor->getChannels()) {
#if defined(USE_18_05_LIBRARY) | defined(USE_18_08_LIBRARY)
 if (BkwhtPQUCQKchmmimoXs == 3 && BdqURaHPmdnfzvtUvocl == 3) { 
m_fusedDepthwiseconvLayer3x3 = 
std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer3x3>( new 
arm_compute::NEDepthwiseConvolutionLayer3x3); 
m_fusedDepthwiseconvLayer3x3->configure( prevLayerarmTensor, 
&m_fusedConvLayerWgtTensor, &m_fusedConvLayerBiasTensor, 
getCurrentLayerOpArmTensor(), arm_compute::PadStrideInfo(GLpnVFeGjOSrhNqnkdCu, 
GLovsOhUpzOJhKgXUAJY, FshVHIJMRAhtQirYPlZd, GDRXdUDklKFEYEfifhIH, 
DRzwhbNPpftRRIXXfHzd, DCdZnqpcBnvXVgEsLBnz, 
arm_compute::DimensionRoundingType::FLOOR)); } else { m_fusedDepthwiseconvLayer 
= std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer>( new 
arm_compute::NEDepthwiseConvolutionLayer); 
m_fusedDepthwiseconvLayer->configure( prevLayerarmTensor, 
&m_fusedConvLayerWgtTensor, &m_fusedConvLayerBiasTensor, 
getCurrentLayerOpArmTensor(), arm_compute::PadStrideInfo(GLpnVFeGjOSrhNqnkdCu, 
GLovsOhUpzOJhKgXUAJY, FshVHIJMRAhtQirYPlZd, GDRXdUDklKFEYEfifhIH, 
DRzwhbNPpftRRIXXfHzd, DCdZnqpcBnvXVgEsLBnz, 
arm_compute::DimensionRoundingType::FLOOR)); } m_actLayer = 
std::unique_ptr<arm_compute::NEActivationLayer>(new 
arm_compute::NEActivationLayer); 
m_actLayer->configure(getCurrentLayerOpArmTensor(), nullptr, arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo::ActivationFunction::RELU));
#else
 if (BkwhtPQUCQKchmmimoXs == 3 && BdqURaHPmdnfzvtUvocl == 3) { 
m_fusedDepthwiseconvLayer3x3 = 
std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer3x3>( new 
arm_compute::NEDepthwiseConvolutionLayer3x3); 
m_fusedDepthwiseconvLayer3x3->configure( prevLayerarmTensor, 
&m_fusedConvLayerWgtTensor, &m_fusedConvLayerBiasTensor, 
getCurrentLayerOpArmTensor(), arm_compute::PadStrideInfo(GLpnVFeGjOSrhNqnkdCu, 
GLovsOhUpzOJhKgXUAJY, FshVHIJMRAhtQirYPlZd, GDRXdUDklKFEYEfifhIH, 
DRzwhbNPpftRRIXXfHzd, DCdZnqpcBnvXVgEsLBnz, 
arm_compute::DimensionRoundingType::FLOOR), 1, 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo::ActivationFunction::RELU)); 
} else { m_fusedDepthwiseconvLayer = 
std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer>( new 
arm_compute::NEDepthwiseConvolutionLayer); 
m_fusedDepthwiseconvLayer->configure( prevLayerarmTensor, 
&m_fusedConvLayerWgtTensor, &m_fusedConvLayerBiasTensor, 
getCurrentLayerOpArmTensor(), arm_compute::PadStrideInfo(GLpnVFeGjOSrhNqnkdCu, 
GLovsOhUpzOJhKgXUAJY, FshVHIJMRAhtQirYPlZd, GDRXdUDklKFEYEfifhIH, 
DRzwhbNPpftRRIXXfHzd, DCdZnqpcBnvXVgEsLBnz, 
arm_compute::DimensionRoundingType::FLOOR), 1, 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo::ActivationFunction::RELU)); 
}
#endif
 } else { m_fusedConvLayer = 
std::unique_ptr<arm_compute::NEConvolutionLayer>(new 
arm_compute::NEConvolutionLayer); m_fusedConvLayerSecondGroup = 
std::unique_ptr<arm_compute::NEConvolutionLayer>(new 
arm_compute::NEConvolutionLayer); m_prevLayer1 = new arm_compute::SubTensor( 
prevLayerarmTensor, arm_compute::TensorShape((long unsigned 
int)ipTensor->getWidth(), (long unsigned int)ipTensor->getHeight(), (long 
unsigned int)(ipTensor->getChannels() / CCKWXUFWgrbBMjwfpOBN), (long unsigned 
int)ipTensor->getBatchSize()), arm_compute::Coordinates()); m_prevLayer2 = new 
arm_compute::SubTensor( prevLayerarmTensor, arm_compute::TensorShape((long 
unsigned int)ipTensor->getWidth(), (long unsigned int)ipTensor->getHeight(), 
(long unsigned int)(ipTensor->getChannels() / CCKWXUFWgrbBMjwfpOBN), (long 
unsigned int)ipTensor->getBatchSize()), arm_compute::Coordinates(0, 0, 
ipTensor->getChannels() / CCKWXUFWgrbBMjwfpOBN)); m_curLayer1 = new 
arm_compute::SubTensor( getCurrentLayerOpArmTensor(), 
arm_compute::TensorShape((long unsigned int)opTensor->getWidth(), (long 
unsigned int)opTensor->getHeight(), (long unsigned int)(opTensor->getChannels() 
/ CCKWXUFWgrbBMjwfpOBN), (long unsigned int)opTensor->getBatchSize()), 
arm_compute::Coordinates()); m_curLayer2 = new arm_compute::SubTensor( 
getCurrentLayerOpArmTensor(), arm_compute::TensorShape((long unsigned 
int)opTensor->getWidth(), (long unsigned int)opTensor->getHeight(), (long 
unsigned int)(opTensor->getChannels() / CCKWXUFWgrbBMjwfpOBN), (long unsigned 
int)opTensor->getBatchSize()), arm_compute::Coordinates(0, 0, 
opTensor->getChannels() / CCKWXUFWgrbBMjwfpOBN)); m_fusedConvLayerWgtMWTensor = 
new arm_compute::SubTensor( &m_fusedConvLayerWgtTensor, 
arm_compute::TensorShape((long unsigned int)BdqURaHPmdnfzvtUvocl, (long 
unsigned int)BkwhtPQUCQKchmmimoXs, (long unsigned 
int)(ipTensor->getChannels() / CCKWXUFWgrbBMjwfpOBN), (long unsigned 
int)(opTensor->getChannels() / CCKWXUFWgrbBMjwfpOBN)), 
arm_compute::Coordinates()); m_fusedConvLayerWgtTensor2 = new 
arm_compute::SubTensor( &m_fusedConvLayerWgtTensor, 
arm_compute::TensorShape((long unsigned int)BdqURaHPmdnfzvtUvocl, (long 
unsigned int)BkwhtPQUCQKchmmimoXs, (long unsigned 
int)(ipTensor->getChannels() / CCKWXUFWgrbBMjwfpOBN), (long unsigned 
int)(opTensor->getChannels() / CCKWXUFWgrbBMjwfpOBN)), 
arm_compute::Coordinates(0, 0, 0, opTensor->getChannels() / 
CCKWXUFWgrbBMjwfpOBN)); m_fusedConvLayerBiasMWTensor = new 
arm_compute::SubTensor( &m_fusedConvLayerBiasTensor, 
arm_compute::TensorShape((long unsigned int)(opTensor->getChannels() / 
CCKWXUFWgrbBMjwfpOBN)), arm_compute::Coordinates()); 
m_fusedConvLayerBiasTensor2 = new arm_compute::SubTensor( 
&m_fusedConvLayerBiasTensor, arm_compute::TensorShape((long unsigned 
int)(opTensor->getChannels() / CCKWXUFWgrbBMjwfpOBN)), 
arm_compute::Coordinates(opTensor->getChannels() / CCKWXUFWgrbBMjwfpOBN)); 
m_fusedConvLayer->configure( m_prevLayer1, m_fusedConvLayerWgtMWTensor, 
m_fusedConvLayerBiasMWTensor, m_curLayer1, 
arm_compute::PadStrideInfo(GLpnVFeGjOSrhNqnkdCu, GLovsOhUpzOJhKgXUAJY, 
FshVHIJMRAhtQirYPlZd, GDRXdUDklKFEYEfifhIH, DRzwhbNPpftRRIXXfHzd, 
DCdZnqpcBnvXVgEsLBnz, arm_compute::DimensionRoundingType::FLOOR), 
arm_compute::WeightsInfo(false, (long unsigned int)BkwhtPQUCQKchmmimoXs, 
(long unsigned int)BdqURaHPmdnfzvtUvocl, (long unsigned 
int)opTensor->getChannels()), 
arm_compute::Size2D((size_t)(BHuHNDGoRwGRouCxeMbw), 
(size_t)(AuqaQHxmPQSyYRemQvyX)), 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo::ActivationFunction::RELU)); 
m_fusedConvLayerSecondGroup->configure( m_prevLayer2, 
m_fusedConvLayerWgtTensor2, m_fusedConvLayerBiasTensor2, m_curLayer2, 
arm_compute::PadStrideInfo(GLpnVFeGjOSrhNqnkdCu, GLovsOhUpzOJhKgXUAJY, 
FshVHIJMRAhtQirYPlZd, GDRXdUDklKFEYEfifhIH, DRzwhbNPpftRRIXXfHzd, 
DCdZnqpcBnvXVgEsLBnz, arm_compute::DimensionRoundingType::FLOOR), 
arm_compute::WeightsInfo(false, (long unsigned int)BkwhtPQUCQKchmmimoXs, 
(long unsigned int)BdqURaHPmdnfzvtUvocl, (long unsigned 
int)opTensor->getChannels()), 
arm_compute::Size2D((size_t)(BHuHNDGoRwGRouCxeMbw), 
(size_t)(AuqaQHxmPQSyYRemQvyX)), 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo::ActivationFunction::RELU)); 
} } else { m_fusedConvLayer = 
std::unique_ptr<arm_compute::NEConvolutionLayer>(new 
arm_compute::NEConvolutionLayer); m_fusedConvLayer->configure( 
prevLayerarmTensor, &m_fusedConvLayerWgtTensor, &m_fusedConvLayerBiasTensor, 
getCurrentLayerOpArmTensor(), arm_compute::PadStrideInfo(GLpnVFeGjOSrhNqnkdCu, 
GLovsOhUpzOJhKgXUAJY, FshVHIJMRAhtQirYPlZd, GDRXdUDklKFEYEfifhIH, 
DRzwhbNPpftRRIXXfHzd, DCdZnqpcBnvXVgEsLBnz, 
arm_compute::DimensionRoundingType::FLOOR), arm_compute::WeightsInfo(false, 
(long unsigned int)BkwhtPQUCQKchmmimoXs, (long unsigned 
int)BdqURaHPmdnfzvtUvocl, (long unsigned int)opTensor->getChannels()), 
arm_compute::Size2D((size_t)(BHuHNDGoRwGRouCxeMbw), 
(size_t)(AuqaQHxmPQSyYRemQvyX)), 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo::ActivationFunction::RELU)); 
} return; } void MWFusedConvReLULayerImpl::predict() { MWFusedConvReLULayer* 
FusedconvLayer = static_cast<MWFusedConvReLULayer*>(getLayer()); MWTensorBase* 
opTensorBase = FusedconvLayer->getOutputTensor(0); MWTensorBase* ipTensorBase = 
FusedconvLayer->getInputTensor(0); prepareIpArmTensorsForPredict(); if 
(CCKWXUFWgrbBMjwfpOBN == 1) { m_fusedConvLayer->run(); } else { if 
(CCKWXUFWgrbBMjwfpOBN == ipTensorBase->getChannels()) { if 
(BkwhtPQUCQKchmmimoXs == 3 && BdqURaHPmdnfzvtUvocl == 3) { 
m_fusedDepthwiseconvLayer3x3->run(); } else { m_fusedDepthwiseconvLayer->run(); }
#if defined(USE_18_05_LIBRARY) | defined(USE_18_08_LIBRARY)
 m_actLayer->run();
#endif
 } else { m_fusedConvLayer->run(); m_fusedConvLayerSecondGroup->run(); } }
#if MW_CONV_TAP
 mw_interm_tap(*getCurrentLayerOpArmTensor(), opTensorBase->getNumElements(), tap_count++);
#endif
 return; } void MWFusedConvReLULayerImpl::allocate() { MWFusedConvReLULayer* 
FusedconvLayer = static_cast<MWFusedConvReLULayer*>(getLayer()); MWTensorBase* 
opTensor = FusedconvLayer->getOutputTensor(0); MWTensorBase* ipTensor = 
FusedconvLayer->getInputTensor(0); int eqUIJyhXTwRqtPfXapcx = ipTensor->getChannels() 
/ CCKWXUFWgrbBMjwfpOBN * opTensor->getChannels() * BdqURaHPmdnfzvtUvocl * 
BkwhtPQUCQKchmmimoXs;  
MWACLUtils::allocateAndFillTensor(m_fusedConvLayerWgtTensor, vpXxoeEhdEosLSsYXkNG, 
eqUIJyhXTwRqtPfXapcx, isWgtsPadding); 
MWACLUtils::allocateAndFillTensor(m_fusedConvLayerBiasTensor, KHjdvykTFbUxdfZTFbqy, 
opTensor->getChannels(), isBiasPadding); return; } void 
MWFusedConvReLULayerImpl::deallocate() { if (CCKWXUFWgrbBMjwfpOBN != 1) { 
delete m_prevLayer1; delete m_prevLayer2; delete m_curLayer1; delete 
m_curLayer2; delete m_fusedConvLayerWgtMWTensor; delete 
m_fusedConvLayerWgtTensor2; delete m_fusedConvLayerBiasMWTensor; delete 
m_fusedConvLayerBiasTensor2; } if(isWgtsPadding){ 
m_fusedConvLayerWgtTensor.allocator()->free(); isWgtsPadding = false; } 
if(isBiasPadding){ m_fusedConvLayerWgtTensor.allocator()->free(); isWgtsPadding 
= false; } return; } void MWFusedConvReLULayerImpl::cleanup(){ 
FREE_BUFFER_MEMORY(vpXxoeEhdEosLSsYXkNG); FREE_BUFFER_MEMORY(KHjdvykTFbUxdfZTFbqy); return; } 
void MWFusedConvReLULayerImpl::loadWeights(const char* QTXuPiGKeBUnmRzhlIDp, int 
eqUIJyhXTwRqtPfXapcx) { float* wvufwFZlsnpjbxmTBVYE = GET_BUFFER(vpXxoeEhdEosLSsYXkNG); std::string 
fileString = getLinuxPath(QTXuPiGKeBUnmRzhlIDp); FILE* RQSttSyDKXCHDWSijmNk = 
MWCNNLayer::openBinaryFile(fileString.c_str()); call_fread(wvufwFZlsnpjbxmTBVYE, 
sizeof(float), eqUIJyhXTwRqtPfXapcx, RQSttSyDKXCHDWSijmNk, QTXuPiGKeBUnmRzhlIDp); 
fclose(RQSttSyDKXCHDWSijmNk); return; } void MWFusedConvReLULayerImpl::loadBias(const 
char* QTXuPiGKeBUnmRzhlIDp, int eqUIJyhXTwRqtPfXapcx) { float* KZWeXiYFmdpQdsgidKeG = 
GET_BUFFER(KHjdvykTFbUxdfZTFbqy); std::string fileString = 
getLinuxPath(QTXuPiGKeBUnmRzhlIDp); FILE* RQSttSyDKXCHDWSijmNk = 
MWCNNLayer::openBinaryFile(fileString.c_str()); call_fread(KZWeXiYFmdpQdsgidKeG, 
sizeof(float), eqUIJyhXTwRqtPfXapcx, RQSttSyDKXCHDWSijmNk, QTXuPiGKeBUnmRzhlIDp); 
fclose(RQSttSyDKXCHDWSijmNk); return; }