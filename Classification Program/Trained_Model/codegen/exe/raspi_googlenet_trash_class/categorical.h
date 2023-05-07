//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  categorical.h
//
//  Code generation for function 'categorical'
//


#ifndef CATEGORICAL_H
#define CATEGORICAL_H

// Include files
#include "raspi_googlenet_trash_class_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Type Definitions
struct cell_wrap_7
{
  coder::array<char, 2U> f1;
};

namespace coder
{
  class categorical
  {
   public:
    void init(const cell_wrap_7 inputData[1], const cell_wrap_7 varargin_1_data[],
              const int varargin_1_size[2]);
    void cellstr(cell_wrap_7 b[1]) const;
   protected:
    uint64m_T codes;
    bounded_array<cell_wrap_7, 2U, 1U> categoryNames;
  };
}

#endif

// End of code generation (categorical.h)
