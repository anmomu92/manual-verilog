// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vmef__Syms.h"
#include "Vmef.h"



// FUNCTIONS
Vmef__Syms::Vmef__Syms(Vmef* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scopes
    __Vscope_mef.configure(this, name(), "mef", "mef", -12, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
        __Vscope_mef.exportInsert(__Vfinal, "sv_get_estado", (void*)(&Vmef::__Vdpiexp_mef__DOT__sv_get_estado_TOP));
    }
}
