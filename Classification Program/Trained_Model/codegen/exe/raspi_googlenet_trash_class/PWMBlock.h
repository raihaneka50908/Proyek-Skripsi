//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  PWMBlock.h
//
//  Code generation for function 'PWMBlock'
//


#ifndef PWMBLOCK_H
#define PWMBLOCK_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Type Definitions
namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      class PWMBlock
      {
       public:
        PWMBlock *init();
        void matlabCodegenDestructor();
        void release();
        ~PWMBlock();
        PWMBlock();
        bool matlabCodegenIsDeleted;
       private:
        int isInitialized;
      };
    }
  }
}

#endif

// End of code generation (PWMBlock.h)
