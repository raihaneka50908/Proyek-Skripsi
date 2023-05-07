//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  hcsr04_sensor_try_initialize.cpp
//
//  Code generation for function 'hcsr04_sensor_try_initialize'
//


// Include files
#include "hcsr04_sensor_try_initialize.h"
#include "fileManager.h"
#include "hcsr04_sensor_try_data.h"
#include "pause.h"
#include "rt_nonfinite.h"

// Function Definitions
void hcsr04_sensor_try_initialize()
{
  filedata_init();
  cpause_init();

  // user code (Initialize function Body)
  {
    mwRaspiInit();
    MW_launchPyserver();
  }

  isInitialized_hcsr04_sensor_try = true;
}

// End of code generation (hcsr04_sensor_try_initialize.cpp)
