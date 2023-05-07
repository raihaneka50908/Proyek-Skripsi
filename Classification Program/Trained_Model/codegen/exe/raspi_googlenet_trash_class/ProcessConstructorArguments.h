//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  ProcessConstructorArguments.h
//
//  Code generation for function 'ProcessConstructorArguments'
//


#ifndef PROCESSCONSTRUCTORARGUMENTS_H
#define PROCESSCONSTRUCTORARGUMENTS_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Type Declarations
namespace coder
{
  namespace raspi
  {
    namespace internal
    {
      class ServoBlock;
    }
  }
}

// Type Definitions
namespace coder
{
  namespace matlab
  {
    namespace system
    {
      namespace coder
      {
        class ProcessConstructorArguments
        {
         public:
          static void b_do(raspi::internal::ServoBlock *obj);
        };
      }
    }
  }
}

#endif

// End of code generation (ProcessConstructorArguments.h)
