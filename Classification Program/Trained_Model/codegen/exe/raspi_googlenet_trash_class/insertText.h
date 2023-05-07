//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  insertText.h
//
//  Code generation for function 'insertText'
//


#ifndef INSERTTEXT_H
#define INSERTTEXT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Function Declarations
namespace coder
{
  void insertTextBox(unsigned char RGB[230400], const ::coder::array<unsigned
                     short, 2U> &ucTextU16, int *textLocationXY_x, int
                     *textLocationXY_y);
}

#endif

// End of code generation (insertText.h)
