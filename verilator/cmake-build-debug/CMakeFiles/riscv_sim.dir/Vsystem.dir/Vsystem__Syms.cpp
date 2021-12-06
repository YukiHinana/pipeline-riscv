// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsystem__Syms.h"
#include "Vsystem.h"
#include "Vsystem_wishbone.h"



// FUNCTIONS
Vsystem__Syms::Vsystem__Syms(Vsystem* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_didInit(false)
    // Setup submodule names
    , TOP__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb(Verilated::catName(topp->name(), "system.top.ihexUart.m.ihex_wb"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->__PVT__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb = &TOP__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb.__Vconfigure(this, true);
}
