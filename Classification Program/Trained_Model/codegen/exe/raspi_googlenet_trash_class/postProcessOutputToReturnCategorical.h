//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  postProcessOutputToReturnCategorical.h
//
//  Code generation for function 'postProcessOutputToReturnCategorical'
//


#ifndef POSTPROCESSOUTPUTTORETURNCATEGORICAL_H
#define POSTPROCESSOUTPUTTORETURNCATEGORICAL_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Type Declarations
struct cell_wrap_22;
namespace coder
{
  class categorical;
}

// Function Declarations
namespace coder
{
  void DeepLearningNetwork_postProcessOutputToReturnCategorical(const
    cell_wrap_22 scores[1], categorical processedOutput[1]);
}

#endif

// End of code generation (postProcessOutputToReturnCategorical.h)
