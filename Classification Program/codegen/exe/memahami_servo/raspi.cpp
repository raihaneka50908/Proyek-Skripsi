//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  raspi.cpp
//
//  Code generation for function 'raspi'
//


// Include files
#include "raspi.h"
#include "SDLVideoDisplay.h"
#include "ServoBlock.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  b_raspi::b_raspi()
  {
    this->matlabCodegenIsDeleted = true;
  }

  b_raspi::~b_raspi()
  {
    this->matlabCodegenDestructor();
  }

  b_raspi *b_raspi::init()
  {
    b_raspi *obj;
    obj = this;
    obj->RaspiDisplay.init();
    obj->matlabCodegenIsDeleted = false;
    return obj;
  }

  void b_raspi::matlabCodegenDestructor()
  {
    if (!this->matlabCodegenIsDeleted) {
      this->matlabCodegenIsDeleted = true;
    }
  }

  raspi::internal::ServoBlock *b_raspi::servo(raspi::internal::ServoBlock
    *iobj_0)
  {
    raspi::internal::ServoBlock *servoObj;
    servoObj = iobj_0->init();
    servoObj->initServo();
    return servoObj;
  }
}

// End of code generation (raspi.cpp)
