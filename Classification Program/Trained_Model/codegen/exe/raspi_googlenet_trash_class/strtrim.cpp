//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  strtrim.cpp
//
//  Code generation for function 'strtrim'
//


// Include files
#include "strtrim.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  void strtrim(const char x_data[], const int x_size[2], char y_data[], int
               y_size[2])
  {
    static const bool bv[128] = { false, false, false, false, false, false,
      false, false, false, true, true, true, true, true, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, true, true, true, true, true, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false };

    int b_j1;
    int j2;
    b_j1 = 0;
    while ((b_j1 + 1 <= x_size[1]) && bv[static_cast<unsigned char>(x_data[b_j1])
           & 127] && (!(x_data[b_j1] == '\x00'))) {
      b_j1++;
    }

    j2 = x_size[1] - 1;
    while ((j2 + 1 > 0) && bv[static_cast<unsigned char>(x_data[j2]) & 127] && (
            !(x_data[j2] == '\x00'))) {
      j2--;
    }

    if (b_j1 + 1 > j2 + 1) {
      b_j1 = 0;
      j2 = -1;
    }

    y_size[0] = 1;
    j2 -= b_j1;
    y_size[1] = j2 + 1;
    for (int i = 0; i <= j2; i++) {
      y_data[i] = x_data[b_j1 + i];
    }
  }
}

// End of code generation (strtrim.cpp)
