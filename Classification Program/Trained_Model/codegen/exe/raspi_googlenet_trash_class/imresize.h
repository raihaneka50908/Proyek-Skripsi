//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  imresize.h
//
//  Code generation for function 'imresize'
//


#ifndef IMRESIZE_H
#define IMRESIZE_H

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
  void imresize(const unsigned char Ain[230400], unsigned char Bout[150528]);
}

#endif

// End of code generation (imresize.h)
