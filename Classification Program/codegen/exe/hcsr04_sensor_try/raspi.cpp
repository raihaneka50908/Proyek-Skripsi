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
#include "rt_nonfinite.h"
#include <stdio.h>

// Function Definitions
namespace coder
{
  void b_raspi::configurePinUnset(double pinNumber)
  {
    raspi::internal::GPIOCodegen gpioObj;
    raspi::internal::PWMBlock pwmOjb;
    pwmOjb.matlabCodegenIsDeleted = true;
    if (this->DigitalPin[static_cast<int>(pinNumber) - 1].Inuse) {
      int ret;
      bool guard1 = false;
      bool guard2 = false;
      guard1 = false;
      guard2 = false;
      switch (static_cast<int>(this->DigitalPin[static_cast<int>(pinNumber) - 1]
               .Mode)) {
       case 2:
        guard2 = true;
        break;

       case 3:
        guard2 = true;
        break;

       case 4:
        pwmOjb.init();
        ret = raspi::internal::PWMBase2::terminatePWM(pinNumber);
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
        ret = raspi::internal::GPIOCodegen::terminateGPIO(pinNumber);
        if (ret == 0) {
          guard1 = true;
        }
      }

      if (guard1) {
        this->DigitalPin[static_cast<int>(pinNumber) - 1].Inuse = false;
        this->DigitalPin[static_cast<int>(pinNumber) - 1].Mode = 1.0;
      }
    }
  }

  void b_raspi::registerPinMode(double pinNumber, double mode)
  {
    this->DigitalPin[static_cast<int>(pinNumber) - 1].Inuse = true;
    this->DigitalPin[static_cast<int>(pinNumber) - 1].Mode = mode;
  }

  void b_raspi::b_configurePin()
  {
    raspi::internal::GPIOCodegen gpioObj;
    int ret;
    this->configurePinUnset(24.0);
    gpioObj.init();
    ret = raspi::internal::GPIOCodegen::initGPIO(24.0, 0.0);
    if (ret == 0) {
      this->registerPinMode(24.0, 2.0);
    }
  }

  void b_raspi::b_writeDigitalPin()
  {
    raspi::internal::GPIOCodegen gpioObj;
    if (this->DigitalPin[22].Mode == 1.0) {
      this->configurePin();
    }

    if ((!this->DigitalPin[22].Available) || (!(this->DigitalPin[22].Mode == 3.0)))
    {
      printf("Pin number %d is not configured for GPIO output\n", 23);
      fflush(stdout);
      main_terminate();
    }

    gpioObj.init();
    raspi::internal::GPIOCodegen::writeGPIO(23.0, 1.0);
  }

  void b_raspi::configurePin()
  {
    raspi::internal::GPIOCodegen raspiGPIO;
    int ret;
    this->configurePinUnset(23.0);
    raspiGPIO.init();
    ret = raspi::internal::GPIOCodegen::initGPIO(23.0, 1.0);
    if (ret == 0) {
      this->registerPinMode(23.0, 3.0);
    }
  }

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
    static const struct_T r = { false, // Available
      false,                           // Inuse
      1.0                              // Mode
    };

    static const signed char iv[19] = { 4, 5, 6, 12, 13, 14, 15, 16, 17, 18, 19,
      20, 21, 22, 23, 24, 25, 26, 27 };

    b_raspi *obj;
    int pin;
    obj = this;
    for (pin = 0; pin < 40; pin++) {
      obj->DigitalPin[pin] = r;
    }

    for (pin = 0; pin < 19; pin++) {
      obj->DigitalPin[iv[pin] - 1].Available = true;
    }

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

  bool b_raspi::readDigitalPin()
  {
    raspi::internal::GPIOCodegen gpioObj;
    if (this->DigitalPin[23].Mode == 1.0) {
      this->b_configurePin();
    }

    if ((!this->DigitalPin[23].Available) || (!(this->DigitalPin[23].Mode == 2.0)))
    {
      printf("Pin number %d is not configured for GPIO input\n", 24);
      fflush(stdout);
      main_terminate();
    }

    gpioObj.init();
    return raspi::internal::GPIOCodegen::readGPIO(24.0);
  }

  void b_raspi::writeDigitalPin()
  {
    raspi::internal::GPIOCodegen gpioObj;
    if (this->DigitalPin[22].Mode == 1.0) {
      this->configurePin();
    }

    if ((!this->DigitalPin[22].Available) || (!(this->DigitalPin[22].Mode == 3.0)))
    {
      printf("Pin number %d is not configured for GPIO output\n", 23);
      fflush(stdout);
      main_terminate();
    }

    gpioObj.init();
    raspi::internal::GPIOCodegen::writeGPIO(23.0, 0.0);
  }
}

// End of code generation (raspi.cpp)
