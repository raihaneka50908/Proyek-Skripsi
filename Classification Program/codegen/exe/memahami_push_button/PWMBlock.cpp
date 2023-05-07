//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  PWMBlock.cpp
//
//  Code generation for function 'PWMBlock'
//


// Include files
#include "PWMBlock.h"

// Function Definitions
namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      void PWMBlock::matlabCodegenDestructor()
      {
        if (!this->matlabCodegenIsDeleted) {
          this->matlabCodegenIsDeleted = true;
          this->release();
        }
      }

      void PWMBlock::release()
      {
        if (this->isInitialized == 1) {
          this->isInitialized = 2;
        }
      }

      PWMBlock::PWMBlock()
      {
        this->matlabCodegenIsDeleted = true;
      }

      PWMBlock::~PWMBlock()
      {
        this->matlabCodegenDestructor();
      }

      PWMBlock *PWMBlock::init()
      {
        PWMBlock *obj;
        obj = this;
        obj->matlabCodegenIsDeleted = false;
        return obj;
      }
    }
  }
}

// End of code generation (PWMBlock.cpp)
