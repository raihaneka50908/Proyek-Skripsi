//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  tic.cpp
//
//  Code generation for function 'tic'
//


// Include files
#include "tic.h"
#include "rt_nonfinite.h"
#include "coder_posix_time.h"
#include <time.h>

// Function Definitions
namespace coder
{
  void tic(double *tstart_tv_sec, double *tstart_tv_nsec)
  {
    struct timespec b_timespec;
    clock_gettime(CLOCK_MONOTONIC, &b_timespec);
    *tstart_tv_sec = (double)b_timespec.tv_sec;
    *tstart_tv_nsec = (double)b_timespec.tv_nsec;
  }
}

// End of code generation (tic.cpp)
