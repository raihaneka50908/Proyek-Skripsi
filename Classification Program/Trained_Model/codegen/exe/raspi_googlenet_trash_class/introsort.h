//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  introsort.h
//
//  Code generation for function 'introsort'
//


#ifndef INTROSORT_H
#define INTROSORT_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Type Declarations
namespace coder
{
  class anonymous_function;
}

// Function Declarations
namespace coder
{
  namespace internal
  {
    void introsort(int x_data[], int xend, const anonymous_function *cmp);
  }
}

#endif

// End of code generation (introsort.h)
