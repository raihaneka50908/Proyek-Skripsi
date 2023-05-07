//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  postProcessOutputToReturnCategorical.cpp
//
//  Code generation for function 'postProcessOutputToReturnCategorical'
//


// Include files
#include "postProcessOutputToReturnCategorical.h"
#include "categorical.h"
#include "raspi_googlenet_trash_class_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  void DeepLearningNetwork_postProcessOutputToReturnCategorical(const
    cell_wrap_22 scores[1], categorical processedOutput[1])
  {
    static const char classNames[18] = { 'A', 'O', 'n', 'r', 'o', 'g', 'r', 'a',
      'g', 'n', 'a', 'i', 'n', 'k', 'i', '\x00', 'k', '\x00' };

    bounded_array<cell_wrap_7, 2U, 2U> labelsCells;
    cell_wrap_7 predictedClassNames[1];
    int b_i;
    int iindx;
    int k;
    char v_data[9];
    if ((scores[0].f1[0] < scores[0].f1[1]) || (rtIsNaNF(scores[0].f1[0]) &&
         (!rtIsNaNF(scores[0].f1[1])))) {
      iindx = 1;
    } else {
      iindx = 0;
    }

    labelsCells.size[0] = 1;
    labelsCells.size[1] = 0;
    for (int i = 0; i < 2; i++) {
      int n;
      n = 0;
      b_i = -1;
      for (k = 0; k < 9; k++) {
        char c;
        c = classNames[i + (k << 1)];
        if (c != 0) {
          n++;
          b_i++;
          v_data[b_i] = c;
        }
      }

      b_i = labelsCells.size[1] + 1;
      labelsCells.size[0] = 1;
      labelsCells.size[1]++;
      k = labelsCells.size[0] * (labelsCells.size[1] - 1);
      labelsCells.data[k].f1.set_size(1, labelsCells.data[k].f1.size(1));
      k = labelsCells.size[0] * (b_i - 1);
      labelsCells.data[k].f1.set_size(labelsCells.data[k].f1.size(0), n);
      for (k = 0; k < n; k++) {
        labelsCells.data[b_i - 1].f1[k] = v_data[k];
      }
    }

    predictedClassNames[0].f1.set_size(1, labelsCells.data[labelsCells.size[0] *
      iindx].f1.size(1));
    b_i = labelsCells.data[iindx].f1.size(0) * labelsCells.data[iindx].f1.size(1);
    for (k = 0; k < b_i; k++) {
      predictedClassNames[0].f1[k] = labelsCells.data[iindx].f1[k];
    }

    processedOutput[0].init(predictedClassNames, labelsCells.data,
      labelsCells.size);
  }
}

// End of code generation (postProcessOutputToReturnCategorical.cpp)
