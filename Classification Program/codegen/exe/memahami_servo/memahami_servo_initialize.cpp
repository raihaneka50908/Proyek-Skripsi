//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  memahami_servo_initialize.cpp
//
//  Code generation for function 'memahami_servo_initialize'
//


// Include files
#include "memahami_servo_initialize.h"
#include "memahami_servo_data.h"
#include "pause.h"
#include "rt_nonfinite.h"

// Function Definitions
void memahami_servo_initialize()
{
  cpause_init();

  // user code (Initialize function Body)
  {
    mwRaspiInit();
    MW_launchPyserver();
  }

  isInitialized_memahami_servo = true;
}

// End of code generation (memahami_servo_initialize.cpp)
