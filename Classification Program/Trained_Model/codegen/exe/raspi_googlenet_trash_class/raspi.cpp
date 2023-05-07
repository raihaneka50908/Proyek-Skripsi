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
#include "GPIOCodegen.h"
#include "PWMBase2.h"
#include "PWMBlock.h"
#include "SDLVideoDisplay.h"
#include "ServoBlock.h"
#include "SystemProp.h"
#include "rt_nonfinite.h"
#include "webcam.h"
#include <stdio.h>

// Function Definitions
namespace coder
{
  void b_raspi::configurePin()
  {
    raspi::internal::GPIOCodegen gpioObj;
    int ret;
    this->configurePinUnset();
    gpioObj.init();
    ret = raspi::internal::GPIOCodegen::initGPIO();
    if (ret == 0) {
      this->registerPinMode();
    }
  }

  void b_raspi::configurePinUnset()
  {
    raspi::internal::GPIOCodegen gpioObj;
    raspi::internal::PWMBlock pwmOjb;
    pwmOjb.matlabCodegenIsDeleted = true;
    if (this->DigitalPin[19].Inuse) {
      int ret;
      bool guard1 = false;
      bool guard2 = false;
      guard1 = false;
      guard2 = false;
      switch (static_cast<int>(this->DigitalPin[19].Mode)) {
       case 2:
        guard2 = true;
        break;

       case 3:
        guard2 = true;
        break;

       case 4:
        pwmOjb.init();
        ret = raspi::internal::PWMBase2::terminatePWM();
        if (ret == 0) {
          guard1 = true;
        }
        break;

       default:
        guard1 = true;
        break;
      }

      if (guard2) {
        gpioObj.init();
        ret = raspi::internal::GPIOCodegen::terminateGPIO();
        if (ret == 0) {
          guard1 = true;
        }
      }

      if (guard1) {
        this->DigitalPin[19].Inuse = false;
        this->DigitalPin[19].Mode = 1.0;
      }
    }
  }

  void b_raspi::matlabCodegenDestructor()
  {
    if (!this->matlabCodegenIsDeleted) {
      this->matlabCodegenIsDeleted = true;
    }
  }

  void b_raspi::registerPinMode()
  {
    this->DigitalPin[19].Inuse = true;
    this->DigitalPin[19].Mode = 2.0;
  }

  b_raspi::b_raspi()
  {
    this->matlabCodegenIsDeleted = true;
  }

  b_raspi::~b_raspi()
  {
    this->matlabCodegenDestructor();
  }

  void b_raspi::displayImage(const unsigned char img[230400])
  {
    matlab::system::coder::SystemProp::matlabCodegenNotifyAnyProp
      (&this->RaspiDisplay);
    raspi::internal::codegen::SDLVideoDisplay::set_windowTitle();
    this->RaspiDisplay.displayImage(img);
  }

  b_raspi *b_raspi::init()
  {
    static const struct_T r = { false, // Available
      false,                           // Inuse
      1.0                              // Mode
    };

    static const signed char b_iv[19] = { 4, 5, 6, 12, 13, 14, 15, 16, 17, 18,
      19, 20, 21, 22, 23, 24, 25, 26, 27 };

    b_raspi *obj;
    int pin;
    obj = this;
    for (pin = 0; pin < 40; pin++) {
      obj->DigitalPin[pin] = r;
    }

    for (pin = 0; pin < 19; pin++) {
      obj->DigitalPin[b_iv[pin] - 1].Available = true;
    }

    obj->RaspiDisplay.init();
    obj->matlabCodegenIsDeleted = false;
    return obj;
  }

  bool b_raspi::readDigitalPin()
  {
    raspi::internal::GPIOCodegen gpioObj;
    if (this->DigitalPin[19].Mode == 1.0) {
      this->configurePin();
    }

    if ((!this->DigitalPin[19].Available) || (!(this->DigitalPin[19].Mode == 2.0)))
    {
      printf("Pin number %d is not configured for GPIO input\n", 20);
      fflush(stdout);
      main_terminate();
    }

    gpioObj.init();
    return raspi::internal::GPIOCodegen::readGPIO();
  }

  raspi::internal::ServoBlock *b_raspi::servo(raspi::internal::ServoBlock
    *iobj_0)
  {
    raspi::internal::ServoBlock *servoObj;
    servoObj = iobj_0->init();
    servoObj->initServo();
    return servoObj;
  }

  ::coder::raspi::internal::codegen::webcam *b_raspi::webcam(::coder::raspi::
    internal::codegen::webcam *iobj_0)
  {
    return iobj_0->init();
  }
}

// End of code generation (raspi.cpp)
