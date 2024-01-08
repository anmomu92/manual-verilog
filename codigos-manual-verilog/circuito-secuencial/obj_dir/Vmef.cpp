// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmef.h for the primary calling header

#include "Vmef.h"
#include "Vmef__Syms.h"

#include "verilated_dpi.h"

//==========

void Vmef::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmef::eval\n"); );
    Vmef__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mef.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmef::_eval_initial_loop(Vmef__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mef.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmef::__Vdpiexp_mef__DOT__sv_get_estado_TOP(Vmef__Syms* __restrict vlSymsp, CData/*7:0*/ (&sv_get_estado__Vfuncrtn)) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::__Vdpiexp_mef__DOT__sv_get_estado_TOP\n"); );
    // Variables
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    sv_get_estado__Vfuncrtn = vlTOPp->mef__DOT__estado;
}

char Vmef::sv_get_estado() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::sv_get_estado\n"); );
    // Variables
    CData/*7:0*/ sv_get_estado__Vfuncrtn__Vcvt;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum==-1)) { __Vfuncnum = Verilated::exportFuncNum("sv_get_estado"); }
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    Vmef__Vcb_sv_get_estado_t __Vcb = (Vmef__Vcb_sv_get_estado_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((Vmef__Syms*)(__Vscopep->symsp()), sv_get_estado__Vfuncrtn__Vcvt);
    char sv_get_estado__Vfuncrtn;
    sv_get_estado__Vfuncrtn = sv_get_estado__Vfuncrtn__Vcvt;
    return sv_get_estado__Vfuncrtn;
}

VL_INLINE_OPT void Vmef::_sequent__TOP__1(Vmef__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::_sequent__TOP__1\n"); );
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mef__DOT__estado = ((IData)(vlTOPp->rst)
                                 ? 0U : (IData)(vlTOPp->mef__DOT__estado_siguiente));
    vlTOPp->estado_depurado = vlTOPp->mef__DOT__estado;
    vlTOPp->__Vtableidx2 = vlTOPp->mef__DOT__estado;
    vlTOPp->Z = vlTOPp->__Vtable2_Z[vlTOPp->__Vtableidx2];
}

VL_INLINE_OPT void Vmef::_combo__TOP__3(Vmef__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::_combo__TOP__3\n"); );
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->B) << 4U) 
                            | (((IData)(vlTOPp->A) 
                                << 3U) | (IData)(vlTOPp->mef__DOT__estado)));
    vlTOPp->mef__DOT__estado_siguiente = vlTOPp->__Vtable1_mef__DOT__estado_siguiente
        [vlTOPp->__Vtableidx1];
}

void Vmef::_eval(Vmef__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::_eval\n"); );
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vmef::_change_request(Vmef__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::_change_request\n"); );
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vmef::_change_request_1(Vmef__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::_change_request_1\n"); );
    Vmef* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmef::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmef::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((A & 0xfeU))) {
        Verilated::overWidthError("A");}
    if (VL_UNLIKELY((B & 0xfeU))) {
        Verilated::overWidthError("B");}
}
#endif  // VL_DEBUG
