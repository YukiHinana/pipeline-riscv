// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsystem.h for the primary calling header

#ifndef _VSYSTEM_WISHBONE_H_
#define _VSYSTEM_WISHBONE_H_  // guard

#include "verilated.h"

//==========

class Vsystem__Syms;
class Vsystem_VerilatedVcd;


//----------

VL_MODULE(Vsystem_wishbone) {
  public:
    
    // LOCAL SIGNALS
    CData/*0:0*/ cyc;
    
    // INTERNAL VARIABLES
  private:
    Vsystem__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vsystem_wishbone);  ///< Copying not allowed
  public:
    Vsystem_wishbone(const char* name = "TOP");
    ~Vsystem_wishbone();
    
    // INTERNAL METHODS
    void __Vconfigure(Vsystem__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
