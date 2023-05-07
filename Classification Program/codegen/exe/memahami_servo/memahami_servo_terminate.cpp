//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  memahami_servo_terminate.cpp
//
//  Code generation for function 'memahami_servo_terminate'
//


// Include files
#include "memahami_servo_terminate.h"
#include "memahami_servo_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void memahami_servo_terminate()
{
  // user code (Terminate function Body)
  {
    MW_killPyserver();
    mwRaspiTerminate();
  }

  isInitialized_memahami_servo = false;
}

// End of code generation (memahami_servo_terminate.cpp)
