//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  sprintf.cpp
//
//  Code generation for function 'sprintf'
//


// Include files
#include "sprintf.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>
#include <stddef.h>
#include <stdio.h>

// Function Definitions
namespace coder
{
  void snPrint(const char varargin_1_data[], const int varargin_1_size[2], float
               varargin_2, const char *varargin_3, ::coder::array<char, 2U> &str)
  {
    int loop_ub_tmp;
    int nbytes;
    char b_varargin_1_data[12];
    loop_ub_tmp = varargin_1_size[0] * varargin_1_size[1];
    if (0 <= loop_ub_tmp - 1) {
      std::memcpy(&b_varargin_1_data[0], &varargin_1_data[0], loop_ub_tmp *
                  sizeof(char));
    }

    nbytes = snprintf(NULL, 0, "Label : %s \n Score : %f \n Action : %s",
                      &b_varargin_1_data[0], varargin_2, varargin_3);
    str.set_size(1, nbytes + 1);
    if (0 <= loop_ub_tmp - 1) {
      std::memcpy(&b_varargin_1_data[0], &varargin_1_data[0], loop_ub_tmp *
                  sizeof(char));
    }

    snprintf(&str[0], (size_t)(nbytes + 1),
             "Label : %s \n Score : %f \n Action : %s", &b_varargin_1_data[0],
             varargin_2, varargin_3);
    if (1 > nbytes) {
      nbytes = 0;
    }

    str.set_size(str.size(0), nbytes);
  }
}

// End of code generation (sprintf.cpp)
