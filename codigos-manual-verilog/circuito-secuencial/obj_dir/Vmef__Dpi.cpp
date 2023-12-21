// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
// Verilator compiles this file in when DPI functions are used.
// If you have multiple Verilated designs with the same DPI exported
// function names, you will get multiple definition link errors from here.
// This is an unfortunate result of the DPI specification.
// To solve this, either
//    1. Call Vmef::{export_function} instead,
//       and do not even bother to compile this file
// or 2. Compile all __Dpi.cpp files in the same compiler run,
//       and #ifdefs already inserted here will sort everything out.

#include "Vmef__Dpi.h"
#include "Vmef.h"

#ifndef _VL_DPIDECL_sv_get_estado
#define _VL_DPIDECL_sv_get_estado
void sv_get_estado() {
    // DPI export at mef.sv:21:15
    return Vmef::sv_get_estado();
}
#endif

