// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSYSTEM_H_
#define _VSYSTEM_H_  // guard

#include "verilated.h"

//==========

class Vsystem__Syms;
class Vsystem_VerilatedVcd;
class Vsystem_wishbone;


//----------

VL_MODULE(Vsystem) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vsystem_wishbone* __PVT__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(i_reset,0,0);
    VL_IN8(io_rx,0,0);
    VL_OUT8(io_tx,0,0);
    VL_OUT8(io_sdram_bank,1,0);
    VL_OUT8(io_sdram_dqm,1,0);
    VL_OUT8(io_sdram_clk,0,0);
    VL_OUT8(io_sdram_cke,0,0);
    VL_OUT8(io_sdram_cs_n,0,0);
    VL_OUT8(io_sdram_ras_n,0,0);
    VL_OUT8(io_sdram_cas_n,0,0);
    VL_OUT8(io_sdram_we_n,0,0);
    VL_IN8(proc_reset,0,0);
    VL_OUT16(io_leds,15,0);
    VL_OUT16(io_sdram_addr,11,0);
    VL_INOUT16(io_sdram_data,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ system__DOT__reset;
        CData/*0:0*/ system__DOT__reset_int;
        CData/*0:0*/ system__DOT__top__DOT__leds_io_wb_ack;
        CData/*0:0*/ system__DOT__top__DOT__arbiter_io_masters_1_ack;
        CData/*0:0*/ system__DOT__top__DOT__arbiter_io_output_stb;
        CData/*0:0*/ system__DOT__top__DOT__arbiter_io_output_we;
        CData/*3:0*/ system__DOT__top__DOT__arbiter_io_output_sel;
        CData/*0:0*/ system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc;
        CData/*0:0*/ system__DOT__top__DOT__interconnect___05Fio_devices_0_stb;
        CData/*0:0*/ system__DOT__top__DOT__interconnect___05Fio_devices_1_cyc;
        CData/*0:0*/ system__DOT__top__DOT__interconnect___05Fio_devices_1_stb;
        CData/*0:0*/ system__DOT__top__DOT__interconnect___05Fio_devices_2_cyc;
        CData/*0:0*/ system__DOT__top__DOT__interconnect___05Fio_devices_2_stb;
        CData/*0:0*/ system__DOT__top__DOT__proc__DOT__top_reset;
        CData/*0:0*/ system__DOT__top__DOT__proc__DOT__top_wb2_cyc;
        CData/*0:0*/ system__DOT__top__DOT__proc__DOT__top_wb2_stb;
        CData/*0:0*/ system__DOT__top__DOT__proc__DOT__top_wb_cyc;
        CData/*0:0*/ system__DOT__top__DOT__proc__DOT__top_wb_stb;
        CData/*0:0*/ system__DOT__top__DOT__proc__DOT__top_wb_we;
        CData/*3:0*/ system__DOT__top__DOT__proc__DOT__top_wb_sel;
        CData/*4:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number;
        CData/*4:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number;
        CData/*4:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_rd_number;
        CData/*6:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func7;
        CData/*6:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_opcode;
        CData/*2:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func3;
        CData/*4:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__dest_addr;
        CData/*0:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall;
        CData/*0:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall;
        CData/*0:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc;
        CData/*4:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number;
        CData/*6:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7;
        CData/*6:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode;
        CData/*2:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3;
        CData/*4:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rd_number;
        CData/*6:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode;
        CData/*2:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3;
        CData/*4:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__mem_rd;
        CData/*0:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid;
        CData/*3:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state;
        CData/*0:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall;
        CData/*3:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state;
        CData/*7:0*/ system__DOT__top__DOT__leds__DOT__ledBuf_0;
        CData/*7:0*/ system__DOT__top__DOT__leds__DOT__ledBuf_1;
        CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m_o_tx;
        CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m_o_wb_err;
        CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode;
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
        CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_stb;
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_data;
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data;
        CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_stb;
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_data;
        CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_db;
        CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_int;
        CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_prev;
        CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__sample;
        CData/*3:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state;
        CData/*3:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state;
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__data;
        CData/*3:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state;
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum;
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd;
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len;
    };
    struct {
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill;
        CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__filled_high;
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmp_sum;
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum_tcmp;
        CData/*3:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_sel;
        CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_overrun;
        CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_full;
        CData/*3:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state;
        CData/*7:0*/ system__DOT__top__DOT__blockram__DOT__rams_0_data_out;
        CData/*7:0*/ system__DOT__top__DOT__blockram__DOT__rams_1_data_out;
        CData/*7:0*/ system__DOT__top__DOT__blockram__DOT__rams_2_data_out;
        CData/*7:0*/ system__DOT__top__DOT__blockram__DOT__rams_3_data_out;
        CData/*0:0*/ system__DOT__top__DOT__blockram__DOT__state;
        CData/*0:0*/ system__DOT__top__DOT__blockram__DOT___rams_0_io_we_T;
        CData/*0:0*/ system__DOT__top__DOT__blockram__DOT___GEN_0;
        CData/*3:0*/ system__DOT__top__DOT__arbiter__DOT__currentMaster;
        CData/*0:0*/ system__DOT__top__DOT__arbiter__DOT___GEN_31;
        CData/*0:0*/ system__DOT__top__DOT__arbiter__DOT___GEN_32;
        CData/*0:0*/ system__DOT__top__DOT__interconnect___DOT__wback;
        CData/*0:0*/ system__DOT__top__DOT__interconnect___DOT__wberr;
        CData/*2:0*/ system__DOT__top__DOT__interconnect___DOT___io_master_stall_T;
        SData/*11:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__id__DOT__branch_offset;
        SData/*15:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr;
        SData/*15:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset;
        SData/*15:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr;
        SData/*8:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer;
        SData/*8:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer;
        SData/*8:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_size;
        SData/*8:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_next_write;
        IData/*31:0*/ system__DOT__top__DOT__arbiter_io_output_addr;
        IData/*31:0*/ system__DOT__top__DOT__arbiter_io_output_mosi_data;
        IData/*29:0*/ system__DOT__top__DOT__proc__DOT__top_wb_addr;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top_wb_mosi_data;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__if_id_pc;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_pc;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__data;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__new_pc;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_result;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_pc;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs1_val;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs2_val;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_immediate;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__df_mem_result;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs1_val;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs2_val;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a;
        IData/*31:0*/ system__DOT__top__DOT__ihexUart__DOT__m_o_wb_data;
        IData/*31:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter;
        IData/*31:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter;
        IData/*29:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_addr;
        IData/*31:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_mosi_data;
        IData/*31:0*/ system__DOT__top__DOT__interconnect___DOT__wbdata;
        IData/*31:0*/ system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[32];
    };
    struct {
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer[256];
        CData/*7:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer[512];
        CData/*7:0*/ system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem[8192];
        CData/*7:0*/ system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem[8192];
        CData/*7:0*/ system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem[8192];
        CData/*7:0*/ system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem[8192];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ system__DOT__top__DOT__ihexUart__DOT__m__DOT____Vcellinp__uart_ctrlr____pinNumber4;
    CData/*0:0*/ __Vclklast__TOP__clock;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vsystem__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vsystem);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vsystem(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vsystem();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vsystem__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vsystem__Syms* symsp, bool first);
  private:
    static QData _change_request(Vsystem__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vsystem__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vsystem__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vsystem__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vsystem__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vsystem__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vsystem__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vsystem__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1__2(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code, const char* scopep) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
