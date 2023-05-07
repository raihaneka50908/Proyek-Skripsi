//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  toc.cpp
//
//  Code generation for function 'toc'
//


// Include files
#include "toc.h"
#include "rt_nonfinite.h"
#include "coder_posix_time.h"

// Function Definitions
namespace coder
{
  double toc(double tstart_tv_sec, double tstart_tv_nsec)
  {
    struct timespec b_timespec;
    clock_gettime(CLOCK_MONOTONIC, &b_timespec);
    return ((double)b_timespec.tv_sec - tstart_tv_sec) + ((double)
      b_timespec.tv_nsec - tstart_tv_nsec) / 1.0E+9;
  }
}

// End of code generation (toc.cpp)
