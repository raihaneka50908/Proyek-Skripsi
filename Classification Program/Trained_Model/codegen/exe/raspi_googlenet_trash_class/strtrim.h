//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  strtrim.h
//
//  Code generation for function 'strtrim'
//


#ifndef STRTRIM_H
#define STRTRIM_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Function Declarations
namespace coder
{
  void strtrim(const char x_data[], const int x_size[2], char y_data[], int
               y_size[2]);
}

#endif

// End of code generation (strtrim.h)
