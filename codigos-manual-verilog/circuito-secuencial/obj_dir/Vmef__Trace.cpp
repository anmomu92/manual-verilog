// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmef__Syms.h"


void Vmef::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vmef__Syms* __restrict vlSymsp = static_cast<Vmef__Syms*>(userp);
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vmef::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vmef__Syms* __restrict vlSymsp = static_cast<Vmef__Syms*>(userp);
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk));
        tracep->chgBit(oldp+1,(vlTOPp->rst));
        tracep->chgBit(oldp+2,(vlTOPp->A));
        tracep->chgBit(oldp+3,(vlTOPp->B));
        tracep->chgBit(oldp+4,(vlTOPp->Z));
        tracep->chgCData(oldp+5,(vlTOPp->estado_depurado),3);
        tracep->chgCData(oldp+6,(vlTOPp->mef__DOT__estado),3);
        tracep->chgCData(oldp+7,(vlTOPp->mef__DOT__estado_siguiente),3);
    }
}

void Vmef::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vmef__Syms* __restrict vlSymsp = static_cast<Vmef__Syms*>(userp);
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
