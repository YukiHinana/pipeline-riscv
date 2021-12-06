// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;


//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*4:0*/ top__DOT__id_rr_sr1_number;
    CData/*4:0*/ top__DOT__id_rr_sr2_number;
    CData/*4:0*/ top__DOT__id_rr_rd_number;
    CData/*6:0*/ top__DOT__id_rr_func7;
    CData/*6:0*/ top__DOT__id_rr_opcode;
    CData/*2:0*/ top__DOT__id_rr_func3;
    CData/*4:0*/ top__DOT__dest_addr;
    CData/*0:0*/ top__DOT__rr_pipeline_stall;
    CData/*0:0*/ top__DOT__mem_pipeline_stall;
    CData/*0:0*/ top__DOT__load_new_pc;
    CData/*0:0*/ top__DOT__wb2_cyc;
    CData/*0:0*/ top__DOT__wb2_stb;
    CData/*0:0*/ top__DOT__wb2_ack;
    CData/*4:0*/ top__DOT__rr_ex_rd_number;
    CData/*6:0*/ top__DOT__rr_ex_func7;
    CData/*6:0*/ top__DOT__rr_ex_opcode;
    CData/*2:0*/ top__DOT__rr_ex_func3;
    CData/*4:0*/ top__DOT__ex_mem_rd_number;
    CData/*6:0*/ top__DOT__ex_mem_opcode;
    CData/*2:0*/ top__DOT__ex_mem_func3;
    CData/*4:0*/ top__DOT__mem_rd;
    CData/*0:0*/ top__DOT__df_ex_valid;
    CData/*0:0*/ top__DOT__wb_cyc;
    CData/*0:0*/ top__DOT__wb_stb;
    CData/*0:0*/ top__DOT__wb_we;
    CData/*0:0*/ top__DOT__wb_ack;
    CData/*3:0*/ top__DOT__wb_sel;
    CData/*3:0*/ top__DOT__fetch__DOT__state;
    CData/*0:0*/ top__DOT__rr__DOT__pipeline_stall;
    CData/*3:0*/ top__DOT__mem__DOT__state;
    CData/*0:0*/ top__DOT__my_mem__DOT__w_wstb;
    SData/*11:0*/ top__DOT__id__DOT__branch_offset;
    IData/*31:0*/ top__DOT__if_id_pc;
    IData/*31:0*/ top__DOT__if_id_instruction;
    IData/*31:0*/ top__DOT__id_rr_pc;
    IData/*31:0*/ top__DOT__id_rr_immediate;
    IData/*31:0*/ top__DOT__data;
    IData/*31:0*/ top__DOT__new_pc;
    IData/*31:0*/ top__DOT__wb2_miso_data;
    IData/*31:0*/ top__DOT__rr_ex_pc;
    IData/*31:0*/ top__DOT__rr_ex_rs1_val;
    IData/*31:0*/ top__DOT__rr_ex_rs2_val;
    IData/*31:0*/ top__DOT__rr_ex_immediate;
    IData/*31:0*/ top__DOT__ex_mem_result;
    IData/*31:0*/ top__DOT__ex_mem_pc;
    IData/*31:0*/ top__DOT__ex_mem_rs1_val;
    IData/*31:0*/ top__DOT__ex_mem_rs2_val;
    IData/*31:0*/ top__DOT__ex_mem_immediate;
    IData/*31:0*/ top__DOT__df_mem_result;
    IData/*31:0*/ top__DOT__df_ex_result;
    IData/*29:0*/ top__DOT__wb_addr;
    IData/*31:0*/ top__DOT__wb_mosi_data;
    IData/*31:0*/ top__DOT__wb_miso_data;
    IData/*31:0*/ top__DOT__mem_result;
    IData/*31:0*/ top__DOT__fetch__DOT__pc;
    IData/*31:0*/ top__DOT__rr__DOT__rs1_val;
    IData/*31:0*/ top__DOT__rr__DOT__rs2_val;
    IData/*31:0*/ top__DOT__ex__DOT__sign_extended;
    IData/*31:0*/ top__DOT__mem__DOT__rs1_and_offset;
    IData/*31:0*/ top__DOT__mem__DOT__load_result;
    IData/*31:0*/ top__DOT__reg_file__DOT__reg_file[32];
    IData/*31:0*/ top__DOT__my_mem2__DOT__mem[262144];
    IData/*31:0*/ top__DOT__my_mem__DOT__mem[262144];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__3(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
