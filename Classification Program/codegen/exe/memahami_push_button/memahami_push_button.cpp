//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  memahami_push_button.cpp
//
//  Code generation for function 'memahami_push_button'
//


// Include files
#include "memahami_push_button.h"
#include "SDLVideoDisplay.h"
#include "memahami_push_button_data.h"
#include "memahami_push_button_initialize.h"
#include "raspi.h"

// Function Definitions
void memahami_push_button()
{
  coder::b_raspi myPi;
  if (!isInitialized_memahami_push_button) {
    memahami_push_button_initialize();
  }

  myPi.RaspiDisplay.matlabCodegenIsDeleted = true;
  myPi.matlabCodegenIsDeleted = true;
  myPi.init();
  myPi.configurePin();
  myPi.b_configurePin();
  while (1) {
    if (myPi.readDigitalPin()) {
      myPi.writeDigitalPin();
    } else {
      myPi.b_writeDigitalPin();
    }
  }
}

// End of code generation (memahami_push_button.cpp)
