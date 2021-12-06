// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystem.h for the primary calling header

#include "Vsystem_wishbone.h"
#include "Vsystem__Syms.h"

//==========

VL_CTOR_IMP(Vsystem_wishbone) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vsystem_wishbone::__Vconfigure(Vsystem__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vsystem_wishbone::~Vsystem_wishbone() {
}

void Vsystem_wishbone::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vsystem_wishbone::_ctor_var_reset\n"); );
    // Body
    cyc = VL_RAND_RESET_I(1);
}
