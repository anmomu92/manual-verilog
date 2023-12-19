// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmef__Syms.h"


//======================

void Vmef::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vmef::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmef__Syms* __restrict vlSymsp = static_cast<Vmef__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vmef::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vmef::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vmef__Syms* __restrict vlSymsp = static_cast<Vmef__Syms*>(userp);
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vmef::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vmef__Syms* __restrict vlSymsp = static_cast<Vmef__Syms*>(userp);
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"rst", false,-1);
        tracep->declBit(c+3,"A", false,-1);
        tracep->declBit(c+4,"B", false,-1);
        tracep->declBit(c+5,"Z", false,-1);
        tracep->declBus(c+6,"estado_depurado", false,-1, 2,0);
        tracep->declBit(c+1,"mef clk", false,-1);
        tracep->declBit(c+2,"mef rst", false,-1);
        tracep->declBit(c+3,"mef A", false,-1);
        tracep->declBit(c+4,"mef B", false,-1);
        tracep->declBit(c+5,"mef Z", false,-1);
        tracep->declBus(c+6,"mef estado_depurado", false,-1, 2,0);
        tracep->declBus(c+7,"mef estado", false,-1, 2,0);
        tracep->declBus(c+8,"mef estado_siguiente", false,-1, 2,0);
        tracep->declBus(c+9,"mef INIT", false,-1, 2,0);
        tracep->declBus(c+10,"mef A0", false,-1, 2,0);
        tracep->declBus(c+11,"mef A1", false,-1, 2,0);
        tracep->declBus(c+12,"mef OK0", false,-1, 2,0);
        tracep->declBus(c+13,"mef OK1", false,-1, 2,0);
    }
}

void Vmef::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vmef::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vmef__Syms* __restrict vlSymsp = static_cast<Vmef__Syms*>(userp);
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vmef::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vmef__Syms* __restrict vlSymsp = static_cast<Vmef__Syms*>(userp);
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk));
        tracep->fullBit(oldp+2,(vlTOPp->rst));
        tracep->fullBit(oldp+3,(vlTOPp->A));
        tracep->fullBit(oldp+4,(vlTOPp->B));
        tracep->fullBit(oldp+5,(vlTOPp->Z));
        tracep->fullCData(oldp+6,(vlTOPp->estado_depurado),3);
        tracep->fullCData(oldp+7,(vlTOPp->mef__DOT__estado),3);
        tracep->fullCData(oldp+8,(vlTOPp->mef__DOT__estado_siguiente),3);
        tracep->fullCData(oldp+9,(0U),3);
        tracep->fullCData(oldp+10,(1U),3);
        tracep->fullCData(oldp+11,(2U),3);
        tracep->fullCData(oldp+12,(3U),3);
        tracep->fullCData(oldp+13,(4U),3);
    }
}
