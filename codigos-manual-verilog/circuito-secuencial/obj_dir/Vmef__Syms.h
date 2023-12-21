// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VMEF__SYMS_H_
#define _VMEF__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vmef.h"

// DPI TYPES for DPI Export callbacks (Internal use)
typedef void (*Vmef__Vcb_sv_get_estado_t) (Vmef__Syms* __restrict vlSymsp);

// SYMS CLASS
class Vmef__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmef*                          TOPp;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_mef;
    
    // CREATORS
    Vmef__Syms(Vmef* topp, const char* namep);
    ~Vmef__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
