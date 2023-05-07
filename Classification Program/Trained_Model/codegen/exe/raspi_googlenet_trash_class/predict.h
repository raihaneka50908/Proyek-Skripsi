//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  predict.h
//
//  Code generation for function 'predict'
//


#ifndef PREDICT_H
#define PREDICT_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Type Declarations
class Googlenet_Trained_Network0_0;

// Function Declarations
namespace coder
{
  void DeepLearningNetwork_predict(Googlenet_Trained_Network0_0 *obj, const
    unsigned char varargin_1[150528], float varargout_1[2]);
}

#endif

// End of code generation (predict.h)
