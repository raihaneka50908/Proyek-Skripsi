//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  raspi_googlenet_trash_class_internal_types.h
//
//  Code generation for function 'raspi_googlenet_trash_class'
//


#ifndef RASPI_GOOGLENET_TRASH_CLASS_INTERNAL_TYPES_H
#define RASPI_GOOGLENET_TRASH_CLASS_INTERNAL_TYPES_H

// Include files
#include "raspi_googlenet_trash_class_types.h"
#include "rtwtypes.h"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Type Definitions
struct cell_wrap_22
{
  float f1[2];
};

class Googlenet_Trained_Network0_0
{
 public:
  Googlenet_Trained_Network0_0();
  void setSize();
  void resetState();
  void setup();
  void predict();
  void cleanup();
  float *getLayerOutput(int layerIndex, int portIndex);
  float *getInputDataPointer(int b_index);
  float *getInputDataPointer();
  float *getOutputDataPointer(int b_index);
  float *getOutputDataPointer();
  int getBatchSize();
  ~Googlenet_Trained_Network0_0();
 private:
  void allocate();
  void postsetup();
  void deallocate();
 public:
  int numLayers;
  MWCNNLayer *layers[78];
 private:
  bool isInitialized;
  MWTensorBase *inputTensors[1];
  MWTensorBase *outputTensors[1];
  MWTargetNetworkImpl *targetImpl;
};

#endif

// End of code generation (raspi_googlenet_trash_class_internal_types.h)
