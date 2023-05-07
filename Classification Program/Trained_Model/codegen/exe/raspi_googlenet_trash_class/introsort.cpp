//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  introsort.cpp
//
//  Code generation for function 'introsort'
//


// Include files
#include "introsort.h"
#include "anonymous_function.h"
#include "insertionsort.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  namespace internal
  {
    void introsort(int x_data[], int xend, const anonymous_function *cmp)
    {
      if (1 < xend) {
        insertionsort(x_data, cmp);
      }
    }
  }
}

// End of code generation (introsort.cpp)
