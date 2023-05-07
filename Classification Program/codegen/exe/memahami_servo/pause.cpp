//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  pause.cpp
//
//  Code generation for function 'pause'
//


// Include files
#include "pause.h"
#include "rt_nonfinite.h"
#include "coder_posix_time.h"
#include "rt_nonfinite.h"
#include <cmath>

// Variable Definitions
static unsigned char pauseState;

// Function Definitions
namespace coder
{
  void pause(double varargin_1)
  {
    struct timespec b_timespec;
    double delay;
    if (pauseState == 0) {
      double delayInt;
      delay = varargin_1;
      if ((varargin_1 < 0.0) || rtIsNaN(varargin_1)) {
        delay = 0.0;
      }

      delayInt = std::floor(delay);
      if (delayInt > 4.294967295E+9) {
        delayInt = 4.294967295E+9;
      }

      delay -= delayInt;
      b_timespec.tv_sec = (time_t)delayInt;
      if (delay > 0.0) {
        b_timespec.tv_nsec = (long)std::floor(delay * 1.0E+9);
      } else {
        b_timespec.tv_nsec = (long)0.0;
      }

      nanosleep(&b_timespec, NULL);
    }
  }
}

void cpause_init()
{
  pauseState = 0U;
}

// End of code generation (pause.cpp)
