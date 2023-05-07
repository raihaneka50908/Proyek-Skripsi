//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  raspi_googlenet_trash_class_terminate.cpp
//
//  Code generation for function 'raspi_googlenet_trash_class_terminate'
//


// Include files
#include "raspi_googlenet_trash_class_terminate.h"
#include "raspi_googlenet_trash_class_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void raspi_googlenet_trash_class_terminate()
{
  // user code (Terminate function Body)
  {
    MW_killPyserver();
    mwRaspiTerminate();
  }

  isInitialized_raspi_googlenet_trash_class = false;
}

// End of code generation (raspi_googlenet_trash_class_terminate.cpp)
