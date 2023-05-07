//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  hcsr04_sensor_try_terminate.cpp
//
//  Code generation for function 'hcsr04_sensor_try_terminate'
//


// Include files
#include "hcsr04_sensor_try_terminate.h"
#include "hcsr04_sensor_try_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void hcsr04_sensor_try_terminate()
{
  // user code (Terminate function Body)
  {
    MW_killPyserver();
    mwRaspiTerminate();
  }

  isInitialized_hcsr04_sensor_try = false;
}

// End of code generation (hcsr04_sensor_try_terminate.cpp)
