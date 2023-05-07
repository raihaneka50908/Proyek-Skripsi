//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  memahami_push_button_terminate.cpp
//
//  Code generation for function 'memahami_push_button_terminate'
//


// Include files
#include "memahami_push_button_terminate.h"
#include "memahami_push_button_data.h"

// Function Definitions
void memahami_push_button_terminate()
{
  // user code (Terminate function Body)
  {
    MW_killPyserver();
    mwRaspiTerminate();
  }

  isInitialized_memahami_push_button = false;
}

// End of code generation (memahami_push_button_terminate.cpp)
