// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmef.h for the primary calling header

#include "Vmef.h"
#include "Vmef__Syms.h"

#include "verilated_dpi.h"

//==========
CData/*2:0*/ Vmef::__Vtable1_mef__DOT__estado_siguiente[32];
CData/*0:0*/ Vmef::__Vtable2_Z[8];

VL_CTOR_IMP(Vmef) {
    Vmef__Syms* __restrict vlSymsp = __VlSymsp = new Vmef__Syms(this, name());
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmef::__Vconfigure(Vmef__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vmef::~Vmef() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vmef::_settle__TOP__2(Vmef__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::_settle__TOP__2\n"); );
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->estado_depurado = vlTOPp->mef__DOT__estado;
    vlTOPp->__Vtableidx2 = vlTOPp->mef__DOT__estado;
    vlTOPp->Z = vlTOPp->__Vtable2_Z[vlTOPp->__Vtableidx2];
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->B) << 4U) 
                            | (((IData)(vlTOPp->A) 
                                << 3U) | (IData)(vlTOPp->mef__DOT__estado)));
    vlTOPp->mef__DOT__estado_siguiente = vlTOPp->__Vtable1_mef__DOT__estado_siguiente
        [vlTOPp->__Vtableidx1];
}

void Vmef::_eval_initial(Vmef__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::_eval_initial\n"); );
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vmef::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::final\n"); );
    // Variables
    Vmef__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmef::_eval_settle(Vmef__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::_eval_settle\n"); );
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vmef::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    A = VL_RAND_RESET_I(1);
    B = VL_RAND_RESET_I(1);
    Z = VL_RAND_RESET_I(1);
    estado_depurado = VL_RAND_RESET_I(3);
    mef__DOT__estado = VL_RAND_RESET_I(3);
    mef__DOT__estado_siguiente = VL_RAND_RESET_I(3);
    __Vtableidx1 = 0;
    __Vtable1_mef__DOT__estado_siguiente[0] = 1U;
    __Vtable1_mef__DOT__estado_siguiente[1] = 3U;
    __Vtable1_mef__DOT__estado_siguiente[2] = 1U;
    __Vtable1_mef__DOT__estado_siguiente[3] = 3U;
    __Vtable1_mef__DOT__estado_siguiente[4] = 1U;
    __Vtable1_mef__DOT__estado_siguiente[5] = 0U;
    __Vtable1_mef__DOT__estado_siguiente[6] = 0U;
    __Vtable1_mef__DOT__estado_siguiente[7] = 0U;
    __Vtable1_mef__DOT__estado_siguiente[8] = 2U;
    __Vtable1_mef__DOT__estado_siguiente[9] = 2U;
    __Vtable1_mef__DOT__estado_siguiente[10] = 4U;
    __Vtable1_mef__DOT__estado_siguiente[11] = 2U;
    __Vtable1_mef__DOT__estado_siguiente[12] = 4U;
    __Vtable1_mef__DOT__estado_siguiente[13] = 0U;
    __Vtable1_mef__DOT__estado_siguiente[14] = 0U;
    __Vtable1_mef__DOT__estado_siguiente[15] = 0U;
    __Vtable1_mef__DOT__estado_siguiente[16] = 1U;
    __Vtable1_mef__DOT__estado_siguiente[17] = 3U;
    __Vtable1_mef__DOT__estado_siguiente[18] = 1U;
    __Vtable1_mef__DOT__estado_siguiente[19] = 3U;
    __Vtable1_mef__DOT__estado_siguiente[20] = 3U;
    __Vtable1_mef__DOT__estado_siguiente[21] = 0U;
    __Vtable1_mef__DOT__estado_siguiente[22] = 0U;
    __Vtable1_mef__DOT__estado_siguiente[23] = 0U;
    __Vtable1_mef__DOT__estado_siguiente[24] = 2U;
    __Vtable1_mef__DOT__estado_siguiente[25] = 2U;
    __Vtable1_mef__DOT__estado_siguiente[26] = 4U;
    __Vtable1_mef__DOT__estado_siguiente[27] = 2U;
    __Vtable1_mef__DOT__estado_siguiente[28] = 4U;
    __Vtable1_mef__DOT__estado_siguiente[29] = 0U;
    __Vtable1_mef__DOT__estado_siguiente[30] = 0U;
    __Vtable1_mef__DOT__estado_siguiente[31] = 0U;
    __Vtableidx2 = 0;
    __Vtable2_Z[0] = 0U;
    __Vtable2_Z[1] = 0U;
    __Vtable2_Z[2] = 0U;
    __Vtable2_Z[3] = 1U;
    __Vtable2_Z[4] = 1U;
    __Vtable2_Z[5] = 0U;
    __Vtable2_Z[6] = 0U;
    __Vtable2_Z[7] = 0U;
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
