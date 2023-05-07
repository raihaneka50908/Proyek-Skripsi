//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  raspi.h
//
//  Code generation for function 'raspi'
//


#ifndef RASPI_H
#define RASPI_H

// Include files
#include "SDLVideoDisplay.h"
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Type Definitions
struct struct_T
{
  bool Available;
  bool Inuse;
  double Mode;
};

namespace coder
{
  class b_raspi
  {
   public:
    b_raspi *init();
    void configurePin();
    void configurePinUnset(double pinNumber);
    void registerPinMode(double pinNumber, double mode);
    void b_configurePin();
    bool readDigitalPin();
    void writeDigitalPin();
    void b_writeDigitalPin();
    void matlabCodegenDestructor();
    ~b_raspi();
    b_raspi();
    bool matlabCodegenIsDeleted;
    raspi::internal::codegen::SDLVideoDisplay RaspiDisplay;
    struct_T DigitalPin[40];
  };
}

#endif

// End of code generation (raspi.h)
