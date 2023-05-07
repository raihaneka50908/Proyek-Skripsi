#include "MWACLUtils.hpp"
#include <assert.h>
#include "cnn_api.hpp"
#include "MWCNNLayerImpl.hpp"
 void MWACLUtils::fillBufferToTensor(float* input_data, arm_compute::ITensor& 
inputTensor) { arm_compute::Window inputWindow; 
inputWindow.use_tensor_dimensions(inputTensor.info()->tensor_shape()); 
arm_compute::Iterator inputIterator(&inputTensor, inputWindow); int counter = 
0; arm_compute::execute_window_loop( inputWindow, [&](const 
arm_compute::Coordinates& id) { *reinterpret_cast<float*>(inputIterator.ptr()) 
= input_data[counter]; counter++; }, inputIterator); } void 
MWACLUtils::fillTensorToBuffer(float* output_data, arm_compute::ITensor& 
outputTensor) { arm_compute::Window outputWindow; 
outputWindow.use_tensor_dimensions(outputTensor.info()->tensor_shape()); 
arm_compute::Iterator outputIterator(&outputTensor, outputWindow); int counter 
= 0; arm_compute::execute_window_loop( outputWindow, [&](const 
arm_compute::Coordinates& id) { output_data[counter] = 
*reinterpret_cast<float*>(outputIterator.ptr()); counter++; }, outputIterator); 
} void MWACLUtils::fillLSTMOutputTensor(arm_compute::ITensor& inputTensor, 
arm_compute::ITensor& outputTensor, int outputIteratorVal = 0) { 
assert(inputTensor.info()->num_dimensions() <= 2 && 
outputTensor.info()->num_dimensions() <= 2);  auto ip_w = 
inputTensor.info()->dimension(0); auto ip_h = inputTensor.info()->dimension(1); 
auto op_w = outputTensor.info()->dimension(0); auto op_h = 
outputTensor.info()->dimension(1); assert(ip_w == op_w); assert(op_h >= ip_h);  
float* ipArmTensorBuffer = (float*)(inputTensor.buffer() + 
inputTensor.info()->offset_first_element_in_bytes()); float* opArmTensorBuffer 
= (float*)(outputTensor.buffer() + 
outputTensor.info()->offset_first_element_in_bytes()); auto ipStridesInBytes = 
inputTensor.info()->strides_in_bytes(); int numElmntsPerRowInInputTensor = 
ipStridesInBytes.y() / 4; auto opStridesInBytes = 
outputTensor.info()->strides_in_bytes(); int numElmntsPerRowInOutputTensor = 
opStridesInBytes.y() / 4; int numElmntsCopiedInPrevTimeSteps = 
outputIteratorVal * ip_h * numElmntsPerRowInOutputTensor; int ipRowAxis = 0, 
opRowAxis = 0; while (ipRowAxis < ip_h) { int ipRowOffset = ipRowAxis * 
numElmntsPerRowInInputTensor; int opRowOffset = opRowAxis * 
numElmntsPerRowInOutputTensor; memcpy(opArmTensorBuffer + opRowOffset + 
numElmntsCopiedInPrevTimeSteps, ipArmTensorBuffer + ipRowOffset, ip_w * 
sizeof(float)); ipRowAxis++; opRowAxis++; } } void 
MWACLUtils::fillLSTMInputTensor(arm_compute::ITensor& inputTensor, 
arm_compute::ITensor& outputTensor, int inputIteratorVal = 0) { 
assert(inputTensor.info()->num_dimensions() <= 2 && 
outputTensor.info()->num_dimensions() <= 2);  auto ip_w = 
inputTensor.info()->dimension(0); auto ip_h = inputTensor.info()->dimension(1); 
auto op_w = outputTensor.info()->dimension(0); auto op_h = 
outputTensor.info()->dimension(1); assert(ip_w == op_w );  float* 
ipArmTensorBuffer = (float*)(inputTensor.buffer() + 
inputTensor.info()->offset_first_element_in_bytes()); float* opArmTensorBuffer 
= (float*)(outputTensor.buffer() + 
outputTensor.info()->offset_first_element_in_bytes()); auto ipStridesInBytes = 
inputTensor.info()->strides_in_bytes(); int numElmntsPerRowInInputTensor = 
ipStridesInBytes.y() / 4; auto opStridesInBytes = 
outputTensor.info()->strides_in_bytes(); int numElmntsPerRowInOutputTensor = 
opStridesInBytes.y() / 4; int numElmntsCopiedInPrevTimeSteps = inputIteratorVal 
* op_h * numElmntsPerRowInInputTensor; int opRowAxis = 0, ipRowAxis = 0; while 
(opRowAxis < op_h) { int opRowOffset = opRowAxis * 
numElmntsPerRowInOutputTensor; int ipRowOffset = ipRowAxis * 
numElmntsPerRowInInputTensor; memcpy(opArmTensorBuffer + opRowOffset, 
ipArmTensorBuffer + ipRowOffset + numElmntsCopiedInPrevTimeSteps, op_w * 
sizeof(float)); opRowAxis++; } } void MWACLUtils::fillValueToTensor(float 
value, arm_compute::ITensor& inputTensor) { arm_compute::Window inputWindow; 
inputWindow.use_tensor_dimensions(inputTensor.info()->tensor_shape()); 
arm_compute::Iterator inputIterator(&inputTensor, inputWindow); 
arm_compute::execute_window_loop( inputWindow, [&](const 
arm_compute::Coordinates& id) { *reinterpret_cast<float*>(inputIterator.ptr()) 
= value; }, inputIterator); } void MWACLUtils::fillLSTMOutputArmTensor(const 
float* ipBuffer, arm_compute::ITensor& outputTensor, int& batchSize, bool 
isLastMode, int outputIteratorVal = 0, bool isBiLSTM, bool isBwdLSTM) { 
assert(outputTensor.info()->num_dimensions() <= 2);  auto op_w = 
outputTensor.info()->dimension(0);  int ipBufSize = op_w; if(isBiLSTM){ 
ipBufSize = ipBufSize/2; } float* opArmTensorBuffer = 
(float*)(outputTensor.buffer() + 
outputTensor.info()->offset_first_element_in_bytes()); auto opStridesInBytes = 
outputTensor.info()->strides_in_bytes(); int numElmntsPerRowInOutputTensor = 
opStridesInBytes.y() / 4; int numElmntsCopiedInPrevTimeSteps; if(isLastMode){ 
numElmntsCopiedInPrevTimeSteps = 0; } else{ numElmntsCopiedInPrevTimeSteps = 
outputIteratorVal * batchSize * numElmntsPerRowInOutputTensor; } if(isBwdLSTM){ 
numElmntsCopiedInPrevTimeSteps = numElmntsCopiedInPrevTimeSteps + ipBufSize; } 
int ipRowAxis = 0, opRowAxis = 0; while (ipRowAxis < batchSize) { int 
ipRowOffset = ipRowAxis * batchSize; int opRowOffset = opRowAxis * 
numElmntsPerRowInOutputTensor; memcpy(opArmTensorBuffer + opRowOffset + 
numElmntsCopiedInPrevTimeSteps, ipBuffer + ipRowOffset, ipBufSize * 
sizeof(float)); ipRowAxis++; opRowAxis++; } } int tap_count = 0; void 
mw_interm_tap(float* memBuf, int size, int count) { FILE* fp; int i; char str[500];
#define TXT_FILE 1
#if TXT_FILE
 sprintf(str, "taps/mw_interm_tap_%d.txt", count); fp = fopen(str, "w"); for (i 
= 0; i < size; i++) { fprintf(fp, "%f\n", memBuf[i]); }
#else
 sprintf(str, "taps/mw_interm_tap_%d.bin", count); fp = fopen(str, "wb"); 
fwrite(inp, 4, size, fp);
#endif
 fclose(fp); } void mw_interm_tap(arm_compute::Tensor& armTensor, int size, int 
count) { float* memBuf = (float*)calloc(size, sizeof(float)); 
MWACLUtils::fillTensorToBuffer(memBuf, armTensor); mw_interm_tap(memBuf, size, 
count); free(memBuf); }
#if defined(USE_18_05_LIBRARY) | defined(USE_18_08_LIBRARY)
 void MWACLUtils::allocateAndFillTensor(arm_compute::Tensor& armTensor, 
arm_compute::MemoryRegion* memoryPtr, int size, bool& isPadded) { 
if(armTensor.info()->has_padding()){ armTensor.allocator()->allocate(); 
MWACLUtils::fillBufferToTensor((float*)memoryPtr->buffer(), armTensor); 
isPadded = true; }else{ 
armTensor.allocator()->import_memory(arm_compute::Memory(memoryPtr)); isPadded 
= false; } }
#else
 void MWACLUtils::allocateAndFillTensor(arm_compute::Tensor& armTensor, float* 
buffer, int size, bool& isPadded) { if(armTensor.info()->has_padding()){ 
armTensor.allocator()->allocate(); MWACLUtils::fillBufferToTensor(buffer, 
armTensor); isPadded = true; }else{
#if defined(USE_19_05_LIBRARY)
 armTensor.allocator()->import_memory(buffer);
#else
 armTensor.allocator()->import_memory(buffer, size * sizeof(float));
#endif
 isPadded = false; } }
#endif
 arm_compute::Tensor* MWACLUtils::getLayerOpArmTensor(MWTensorBase* aTensor) { 
auto owningLayer = aTensor->getOwner(); if(owningLayer == nullptr){ return 
nullptr; } auto owningLayerImpl = owningLayer->getImpl(); int inIdx = 
aTensor->getSourcePortIndex(); if (owningLayerImpl == NULL) { if 
(owningLayer->isCustomLayer()){ return nullptr; }else{ 
assert(owningLayer->getNumInputs() == 1); return 
MWACLUtils::getLayerOpArmTensor(owningLayer->getInputTensor(inIdx)); } } else { 
auto layerOpArmTensor = owningLayerImpl->getCurrentLayerOpArmTensor(inIdx); 
if(layerOpArmTensor){ return layerOpArmTensor; }else{ return nullptr; } } } 
std::shared_ptr<arm_compute::Tensor> 
MWACLUtils::getLayerOpArmTensorsharedPtr(MWTensorBase* aTensor) { auto 
owningLayer = aTensor->getOwner(); if(owningLayer == nullptr){ return nullptr; 
} auto owningLayerImpl = owningLayer->getImpl(); int index = 
aTensor->getSourcePortIndex(); if (owningLayerImpl == NULL) { if 
(owningLayer->isCustomLayer()){ return nullptr; }else{ 
assert(owningLayer->getNumInputs() == 1); return 
MWACLUtils::getLayerOpArmTensorsharedPtr(owningLayer->getInputTensor(index)); } 
} else { auto layerOpArmTensorSharePtr = 
owningLayerImpl->getCurrentLayerOpArmTensorSharedPtr(index); 
if(layerOpArmTensorSharePtr){ return layerOpArmTensorSharePtr; }else{ return 
nullptr; } } } void MWACLUtils::doTranspose(float* inputBuf, float* outputBuf, 
const int opDims[]){ int opSeqLength = opDims[0]; int opBatchSize = opDims[1]; 
int opchannels = opDims[2]; int opHeight = opDims[3]; int opWidth = opDims[4]; 
int numElesPerChannel = opHeight*opWidth; int numElesPerBatch = 
opchannels*numElesPerChannel; int numElesPerSequence = opSeqLength*numElesPerBatch;
#pragma omp parallel for collapse(5)
 for(int seqIdx=0; seqIdx<opSeqLength; seqIdx++){ for(int bsIdx=0; 
bsIdx<opBatchSize; bsIdx++){ for(int chnlIdx=0; chnlIdx<opchannels; chnlIdx++){ 
for(int hIdx=0; hIdx<opHeight; hIdx++){ for(int wIdx=0; wIdx<opWidth; wIdx++){ 
int chnlOffset = 
(seqIdx*numElesPerSequence)+(bsIdx*numElesPerBatch)+(chnlIdx*numElesPerChannel); 
int outIdx = chnlOffset+(hIdx*opWidth)+ wIdx; int ipIdx = 
chnlOffset+(wIdx*opHeight)+ hIdx; outputBuf[outIdx] = inputBuf[ipIdx]; } } } } 
} }