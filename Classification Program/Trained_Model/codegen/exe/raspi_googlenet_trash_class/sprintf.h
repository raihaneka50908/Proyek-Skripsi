//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  sprintf.h
//
//  Code generation for function 'sprintf'
//


#ifndef SPRINTF_H
#define SPRINTF_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Function Declarations
namespace coder
{
  void snPrint(const char varargin_1_data[], const int varargin_1_size[2], float
               varargin_2, const char *varargin_3, ::coder::array<char, 2U> &str);
}

#endif

// End of code generation (sprintf.h)
