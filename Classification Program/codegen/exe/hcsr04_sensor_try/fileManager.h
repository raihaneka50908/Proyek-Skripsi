//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  fileManager.h
//
//  Code generation for function 'fileManager'
//


#ifndef FILEMANAGER_H
#define FILEMANAGER_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Custom Header Code
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

// Function Declarations
namespace coder
{
  int cfclose(double fid);
  signed char cfopen(const char *cfilename, const char *cpermission);
}

void filedata_init();

#endif

// End of code generation (fileManager.h)
