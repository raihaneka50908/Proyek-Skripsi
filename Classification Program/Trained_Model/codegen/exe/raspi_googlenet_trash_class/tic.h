//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  tic.h
//
//  Code generation for function 'tic'
//


#ifndef TIC_H
#define TIC_H

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
  void tic(double *tstart_tv_sec, double *tstart_tv_nsec);
}

#endif

// End of code generation (tic.h)
