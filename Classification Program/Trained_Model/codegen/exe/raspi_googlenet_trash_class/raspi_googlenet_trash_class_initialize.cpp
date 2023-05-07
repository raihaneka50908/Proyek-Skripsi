//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  raspi_googlenet_trash_class_initialize.cpp
//
//  Code generation for function 'raspi_googlenet_trash_class_initialize'
//


// Include files
#include "raspi_googlenet_trash_class_initialize.h"
#include "raspi_googlenet_trash_class_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void raspi_googlenet_trash_class_initialize()
{
  // user code (Initialize function Body)
  {
    mwRaspiInit();
    MW_launchPyserver();
  }

  isInitialized_raspi_googlenet_trash_class = true;
}

// End of code generation (raspi_googlenet_trash_class_initialize.cpp)
