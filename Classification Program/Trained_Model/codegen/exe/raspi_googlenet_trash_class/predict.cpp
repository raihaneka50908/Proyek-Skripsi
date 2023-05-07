//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  predict.cpp
//
//  Code generation for function 'predict'
//


// Include files
#include "predict.h"
#include "DeepLearningNetwork.h"
#include "raspi_googlenet_trash_class_internal_types.h"
#include "rt_nonfinite.h"
#include "cnn_api.hpp"
#include <cstring>

// Type Definitions
struct cell_wrap_23
{
  float f1[2];
};

struct cell_wrap_21
{
  float f1[150528];
};

// Function Definitions
namespace coder
{
  void DeepLearningNetwork_predict(Googlenet_Trained_Network0_0 *obj, const
    unsigned char varargin_1[150528], float varargout_1[2])
  {
    static cell_wrap_21 dataInputsSingle[1];
    static cell_wrap_21 miniBatchT[1];
    cell_wrap_23 outputsMiniBatch[1];
    int i;
    for (i = 0; i < 150528; i++) {
      dataInputsSingle[0].f1[i] = varargin_1[i];
    }

    for (int p = 0; p < 3; p++) {
      for (i = 0; i < 224; i++) {
        for (int i1 = 0; i1 < 224; i1++) {
          miniBatchT[0].f1[(i1 + 224 * i) + 50176 * p] = dataInputsSingle[0].f1
            [(i + 224 * i1) + 50176 * p];
        }
      }
    }

    memcpy(obj->getInputDataPointer(0), miniBatchT[0].f1, obj->layers[0]
           ->getOutputTensor(0)->getNumElements() * sizeof(float));
    obj->predict();
    memcpy(outputsMiniBatch[0].f1, obj->getLayerOutput(77, 0), obj->layers[77]
           ->getOutputTensor(0)->getNumElements() * sizeof(float));
    varargout_1[0] = outputsMiniBatch[0].f1[0];
    varargout_1[1] = outputsMiniBatch[0].f1[1];
  }
}

// End of code generation (predict.cpp)
