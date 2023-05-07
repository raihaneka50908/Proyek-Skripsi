//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  memahami_push_button_initialize.cpp
//
//  Code generation for function 'memahami_push_button_initialize'
//


// Include files
#include "memahami_push_button_initialize.h"
#include "memahami_push_button_data.h"

// Function Definitions
void memahami_push_button_initialize()
{
  // user code (Initialize function Body)
  {
    mwRaspiInit();
    MW_launchPyserver();
  }

  isInitialized_memahami_push_button = true;
}

// End of code generation (memahami_push_button_initialize.cpp)
