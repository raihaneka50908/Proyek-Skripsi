//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  insertionsort.h
//
//  Code generation for function 'insertionsort'
//


#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

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
    void insertionsort(int x_data[], const anonymous_function *cmp);
  }
}

#endif

// End of code generation (insertionsort.h)
