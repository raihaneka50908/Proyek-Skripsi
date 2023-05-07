//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  insertionsort.cpp
//
//  Code generation for function 'insertionsort'
//


// Include files
#include "insertionsort.h"
#include "anonymous_function.h"
#include "categorical.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder
{
  namespace internal
  {
    void insertionsort(int x_data[], const anonymous_function *cmp)
    {
      int idx;
      int k;
      int n;
      int xc;
      bool exitg1;
      bool varargout_1;
      xc = x_data[1] - 1;
      idx = 1;
      if (cmp->tunableEnvironment[0].f1.data[xc].f1.size(1) <
          cmp->tunableEnvironment[0].f1.data[x_data[0] - 1].f1.size(1)) {
        n = cmp->tunableEnvironment[0].f1.data[xc].f1.size(1);
      } else {
        n = cmp->tunableEnvironment[0].f1.data[x_data[0] - 1].f1.size(1);
      }

      varargout_1 = (cmp->tunableEnvironment[0].f1.data[xc].f1.size(1) <
                     cmp->tunableEnvironment[0].f1.data[x_data[0] - 1].f1.size(1));
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= n - 1)) {
        if (cmp->tunableEnvironment[0].f1.data[xc].f1[k] !=
            cmp->tunableEnvironment[0].f1.data[x_data[0] - 1].f1[k]) {
          varargout_1 = (cmp->tunableEnvironment[0].f1.data[xc].f1[k] <
                         cmp->tunableEnvironment[0].f1.data[x_data[0] - 1].f1[k]);
          exitg1 = true;
        } else {
          k++;
        }
      }

      if (varargout_1) {
        x_data[1] = x_data[0];
        idx = 0;
      }

      x_data[idx] = xc + 1;
    }
  }
}

// End of code generation (insertionsort.cpp)
