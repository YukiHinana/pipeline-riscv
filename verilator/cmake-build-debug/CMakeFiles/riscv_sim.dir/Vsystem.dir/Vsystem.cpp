// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystem.h for the primary calling header

#include "Vsystem.h"
#include "Vsystem__Syms.h"

//==========

VL_CTOR_IMP(Vsystem) {
    Vsystem__Syms* __restrict vlSymsp = __VlSymsp = new Vsystem__Syms(this, name());
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(__PVT__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb, Vsystem_wishbone);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vsystem::__Vconfigure(Vsystem__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vsystem::~Vsystem() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vsystem::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsystem::eval\n"); );
    Vsystem__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("../rtl/../rtl/system.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vsystem::_eval_initial_loop(Vsystem__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("../rtl/../rtl/system.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vsystem::_initial__TOP__1(Vsystem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystem::_initial__TOP__1\n"); );
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_sdram_addr = 0U;
    vlTOPp->io_sdram_bank = 0U;
    vlTOPp->io_sdram_dqm = 0U;
    vlTOPp->io_sdram_clk = 0U;
    vlTOPp->io_sdram_cke = 0U;
    vlTOPp->io_sdram_cs_n = 0U;
    vlTOPp->io_sdram_ras_n = 0U;
    vlTOPp->io_sdram_cas_n = 0U;
    vlTOPp->io_sdram_we_n = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m_o_tx = 1U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_stb = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_prev = 1U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_db = 1U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_int = 1U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter = 0U;
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_overrun = 0U;
}

void Vsystem::_settle__TOP__2(Vsystem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystem::_settle__TOP__2\n"); );
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_sdram_data = 0U;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum_tcmp 
        = (0xffU & ((IData)(1U) + (~ (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum))));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr 
        = (0xffffU & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr) 
                      + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill)));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset 
        = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs1_val 
           + ((0xfffff000U & (VL_NEGATE_I((IData)((1U 
                                                   & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_immediate 
                                                      >> 0xbU)))) 
                              << 0xcU)) | (0xfffU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_immediate)));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended 
        = ((0xfffff000U & (VL_NEGATE_I((IData)((1U 
                                                & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate 
                                                   >> 0xbU)))) 
                           << 0xcU)) | (0xfffU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid = 0U;
    if (((0x33U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode)) 
         | (0x13U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode)))) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid = 1U;
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__new_pc 
        = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc 
           + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate);
    if ((0x33U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
        if ((0x13U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
            if ((0x63U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                if ((0x6fU != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                    if ((0x67U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__new_pc 
                            = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate 
                               + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val);
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__new_pc 
                            = (0xfffffffeU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__new_pc);
                    }
                }
            }
        }
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id__DOT__branch_offset 
        = ((0x800U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                      >> 0x14U)) | ((0x400U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                               << 3U)) 
                                    | ((0x3f0U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                                  >> 0x15U)) 
                                       | (0xfU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                                  >> 8U)))));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_cyc = 0U;
    if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state))) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_cyc = 1U;
    } else {
        if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_cyc = 1U;
        }
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_stb = 0U;
    if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state))) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_stb = 1U;
    }
    vlTOPp->system__DOT__top__DOT__blockram__DOT___rams_0_io_we_T 
        = (1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state)));
    vlTOPp->system__DOT__top__DOT__arbiter_io_masters_1_ack 
        = ((1U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
           & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wback));
    vlTOPp->system__DOT__top__DOT__arbiter_io_output_we 
        = ((2U != (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
           & ((1U != (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
              | (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_we)));
    vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data 
        = ((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
            ? 0U : ((1U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
                     ? vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_mosi_data
                     : vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_mosi_data));
    vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel 
        = ((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
            ? 0xfU : ((1U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
                       ? (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_sel)
                       : (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_sel)));
    vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
        = ((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
            ? (0x3fffffffU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc 
                              >> 2U)) : ((1U == (3U 
                                                 & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
                                          ? vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_addr
                                          : vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_addr));
    vlTOPp->io_leds = (((IData)(vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_1) 
                        << 8U) | (IData)(vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_0));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset 
        = ((IData)(vlTOPp->system__DOT__reset) | (IData)(vlTOPp->proc_reset));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_data 
        = ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode)
            ? (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_data)
            : (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data));
    vlSymsp->TOP__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb.cyc 
        = ((0xeU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state)) 
           | (0xfU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state)));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__sample 
        = VL_LTES_III(1,32,32, 0x1b1U, vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter);
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_stb 
        = ((0xbU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state)) 
           & (0U == vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m_o_tx 
        = ((2U != (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state)) 
           & (((0U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state)) 
               | (0xbU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state))) 
              | ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__data) 
                 >> (7U & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state) 
                           - (IData)(3U))))));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_next_write 
        = (0x1ffU & ((IData)(1U) + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer)));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_size 
        = (0x1ffU & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer) 
                     - (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer)));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_full 
        = ((0x1ffU & ((IData)(1U) + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer))) 
           == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a 
        = ((0x1fU >= (0x18U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset 
                               << 3U))) ? (vlTOPp->system__DOT__top__DOT__interconnect___DOT__wbdata 
                                           >> (0x18U 
                                               & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset 
                                                  << 3U)))
            : 0U);
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result = 0U;
    if ((0x33U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
        if ((0x20U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7))) {
            if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                    = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                       - vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val);
            }
            if ((5U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                    = VL_SHIFTRS_III(32,32,5, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val, 
                                     (0x1fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val));
            }
        } else {
            if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7))) {
                if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                        = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                           + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val);
                } else {
                    if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                            = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                               << (0x1fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val));
                    } else {
                        if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                = (VL_LTS_III(1,32,32, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val)
                                    ? 1U : 0U);
                        } else {
                            if ((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                    = ((vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                        < vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val)
                                        ? 1U : 0U);
                            } else {
                                if ((4U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                        = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                           ^ vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val);
                                } else {
                                    if ((5U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                            = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                               >> (0x1fU 
                                                   & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val));
                                    } else {
                                        if ((6U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                                = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                                   | vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val);
                                        } else {
                                            if ((7U 
                                                 == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                                    = 
                                                    (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                                     & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x13U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
            if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                    = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                       + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended);
            } else {
                if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                        = (VL_LTS_III(1,32,32, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended)
                            ? 1U : 0U);
                } else {
                    if ((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                            = ((vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                < vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended)
                                ? 1U : 0U);
                    } else {
                        if ((4U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended 
                                   ^ vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val);
                        } else {
                            if ((6U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                    = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended 
                                       | vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val);
                            } else {
                                if ((7U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                        = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended 
                                           & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val);
                                } else {
                                    if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                            = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                               << (0x1fU 
                                                   & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate));
                                    } else {
                                        if (((5U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                                             | (5U 
                                                == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)))) {
                                            if ((0U 
                                                 == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7))) {
                                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                                    = 
                                                    (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                                     >> 
                                                     (0x1fU 
                                                      & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate));
                                            } else {
                                                if (
                                                    (0x20U 
                                                     == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7))) {
                                                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                                        = 
                                                        VL_SHIFTRS_III(32,32,5, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val, 
                                                                       (0x1fU 
                                                                        & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x63U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                if ((0x6fU == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                        = ((IData)(4U) + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc);
                } else {
                    if ((0x67U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                            = ((IData)(4U) + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc);
                    } else {
                        if ((0x37U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate;
                        } else {
                            if ((0x17U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                    = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate 
                                       + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc);
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->system__DOT__top__DOT__arbiter_io_output_stb 
        = ((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
            ? (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_stb)
            : ((1U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
                ? (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_stb)
                : (0xeU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall = 0U;
    if (((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)) 
         | (0x23U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)))) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall = 1U;
    }
    if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_cyc) 
         & (IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_masters_1_ack))) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall = 0U;
    }
    vlTOPp->system__DOT__top__DOT__interconnect___DOT___io_master_stall_T 
        = ((((0x1e000200U == (0x1fffffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                             >> 1U))) 
             & (0U != (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state))) 
            << 2U) | ((0U == (0x1ffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                          >> 0xdU))) 
                      & (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state)));
    vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_31 
        = ((1U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
            ? (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_cyc)
            : (IData)(vlSymsp->TOP__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb.cyc));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT____Vcellinp__uart_ctrlr____pinNumber4 
        = ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_stb) 
           & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode));
    vlTOPp->io_tx = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m_o_tx;
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result = 0U;
    if ((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode))) {
        if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result 
                = ((0xffffff00U & (VL_NEGATE_I((IData)(
                                                       (1U 
                                                        & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a 
                                                           >> 7U)))) 
                                   << 8U)) | (0xffU 
                                              & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a));
        } else {
            if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result 
                    = ((0xffff0000U & (VL_NEGATE_I((IData)(
                                                           (1U 
                                                            & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a 
                                                               >> 0xfU)))) 
                                       << 0x10U)) | 
                       (0xffffU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a));
            } else {
                if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result 
                        = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a;
                } else {
                    if ((4U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result 
                            = (0xffU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a);
                    } else {
                        if ((5U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result 
                                = (0xffffU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a);
                        }
                    }
                }
            }
        }
    }
    vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_2_stb 
        = ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_stb) 
           & (0x1e000200U == (0x1fffffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                             >> 1U))));
    vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_stb 
        = ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_stb) 
           & (0x3c000000U == (0x3fffffffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)));
    vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb 
        = ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_stb) 
           & (0U == (0x1ffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                 >> 0xdU))));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 0U;
    if ((0x33U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
        if ((0x13U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
            if ((0x63U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                if (((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                     & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                        == vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                } else {
                    if (((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                         & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                            != vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                    } else {
                        if (((4U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                             & VL_LTS_III(1,32,32, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                        } else {
                            if (((5U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                                 & VL_GTES_III(1,32,32, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                            } else {
                                if (((6U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                                     & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                        < vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val))) {
                                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                                } else {
                                    if (((7U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                                         & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                            >= vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val))) {
                                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if ((0x6fU == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                } else {
                    if ((0x67U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                    }
                }
            }
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 0U;
    }
    vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_32 
        = ((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
            ? (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_cyc)
            : (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_31));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_mem_result 
        = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_result;
    if (((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)) 
         | (0x23U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)))) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_mem_result 
            = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result;
    }
    vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_2_cyc 
        = ((IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_32) 
           & (0x1e000200U == (0x1fffffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                             >> 1U))));
    vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_cyc 
        = ((IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_32) 
           & (0x3c000000U == (0x3fffffffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)));
    vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc 
        = ((IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_32) 
           & (0U == (0x1ffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                 >> 0xdU))));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs1_val 
        = ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number))
            ? 0U : (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number) 
                     == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__dest_addr))
                     ? vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__data
                     : vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                    [vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number]));
    if ((0U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number))) {
        if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number) 
             == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number))) {
            if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs1_val 
                    = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result;
            }
        } else {
            if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number) 
                 == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rd_number))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs1_val 
                    = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_mem_result;
            }
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall = 0U;
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall = 0U;
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs2_val 
        = ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number))
            ? 0U : (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number) 
                     == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__dest_addr))
                     ? vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__data
                     : vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                    [vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number]));
    if ((0U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number))) {
        if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number) 
             == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number))) {
            if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall = 1U;
            }
        }
    }
    if (((0U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number)) 
         & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall)))) {
        if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number) 
             == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number))) {
            if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs2_val 
                    = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result;
            } else {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall = 1U;
            }
        } else {
            if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number) 
                 == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rd_number))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs2_val 
                    = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_mem_result;
            }
        }
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall 
        = ((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall) 
           | (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall));
    vlTOPp->system__DOT__top__DOT__leds_io_wb_ack = 
        ((IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_cyc) 
         & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_stb));
    vlTOPp->system__DOT__top__DOT__blockram__DOT___GEN_0 
        = (((IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb) 
            & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc)) 
           | (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state));
}

VL_INLINE_OPT void Vsystem::_sequent__TOP__3(Vsystem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystem::_sequent__TOP__3\n"); );
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii;
    CData/*3:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__Vfuncout;
    CData/*7:0*/ __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii;
    CData/*3:0*/ __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state;
    CData/*4:0*/ __Vdlyvdim0__system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file__v0;
    CData/*3:0*/ __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state;
    CData/*3:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state;
    CData/*7:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
    CData/*3:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state;
    CData/*7:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum;
    CData/*7:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd;
    CData/*3:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state;
    CData/*7:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill;
    CData/*0:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__filled_high;
    CData/*7:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len;
    CData/*7:0*/ __Vdlyvdim0__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v0;
    CData/*7:0*/ __Vdlyvval__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v0;
    CData/*0:0*/ __Vdlyvset__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v0;
    CData/*7:0*/ __Vdlyvdim0__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v1;
    CData/*7:0*/ __Vdlyvval__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v1;
    CData/*0:0*/ __Vdlyvset__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v1;
    CData/*7:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmp_sum;
    CData/*7:0*/ __Vdlyvval__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer__v0;
    CData/*0:0*/ __Vdlyvset__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer__v0;
    CData/*3:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state;
    CData/*0:0*/ __Vdly__system__DOT__top__DOT__blockram__DOT__state;
    CData/*7:0*/ __Vdlyvval__system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem__v0;
    CData/*3:0*/ __Vdly__system__DOT__top__DOT__arbiter__DOT__currentMaster;
    SData/*15:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr;
    SData/*15:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset;
    SData/*8:0*/ __Vdlyvdim0__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer__v0;
    SData/*8:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer;
    SData/*12:0*/ __Vdlyvdim0__system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem__v0;
    SData/*12:0*/ __Vdlyvdim0__system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem__v0;
    SData/*12:0*/ __Vdlyvdim0__system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem__v0;
    SData/*12:0*/ __Vdlyvdim0__system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem__v0;
    IData/*31:0*/ __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc;
    IData/*31:0*/ __Vdlyvval__system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file__v0;
    IData/*31:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter;
    IData/*31:0*/ __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter;
    // Body
    __Vdly__system__DOT__top__DOT__blockram__DOT__state 
        = vlTOPp->system__DOT__top__DOT__blockram__DOT__state;
    __Vdlyvset__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer__v0 = 0U;
    __Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem__v0 = 0U;
    __Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem__v0 = 0U;
    __Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem__v0 = 0U;
    __Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem__v0 = 0U;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmp_sum 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmp_sum;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__filled_high 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__filled_high;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill;
    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state;
    __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc 
        = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc;
    __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state 
        = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state;
    __Vdlyvset__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v0 = 0U;
    __Vdlyvset__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v1 = 0U;
    __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state 
        = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state;
    __Vdly__system__DOT__top__DOT__arbiter__DOT__currentMaster 
        = vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster;
    if (vlTOPp->system__DOT__reset) {
        __Vdly__system__DOT__top__DOT__blockram__DOT__state = 0U;
    } else {
        if (vlTOPp->system__DOT__top__DOT__blockram__DOT__state) {
            __Vdly__system__DOT__top__DOT__blockram__DOT__state = 0U;
        } else {
            if (vlTOPp->system__DOT__top__DOT__blockram__DOT___rams_0_io_we_T) {
                __Vdly__system__DOT__top__DOT__blockram__DOT__state 
                    = vlTOPp->system__DOT__top__DOT__blockram__DOT___GEN_0;
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->system__DOT__reset)))) {
        if (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT____Vcellinp__uart_ctrlr____pinNumber4) {
            __Vdlyvval__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer__v0 
                = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
            __Vdlyvset__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer__v0 = 1U;
            __Vdlyvdim0__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer__v0 
                = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer;
        }
    }
    if ((((((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_we) 
            & (~ (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state))) 
           & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb)) 
          & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc)) 
         & (IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel))) {
        __Vdlyvval__system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem__v0 
            = (0xffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data);
        __Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem__v0 
            = (0x1fffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr);
    }
    if ((((((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_we) 
            & (~ (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state))) 
           & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb)) 
          & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc)) 
         & ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel) 
            >> 1U))) {
        __Vdlyvval__system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem__v0 
            = (0xffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data 
                        >> 8U));
        __Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem__v0 = 1U;
        __Vdlyvdim0__system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem__v0 
            = (0x1fffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr);
    }
    if ((((((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_we) 
            & (~ (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state))) 
           & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb)) 
          & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc)) 
         & ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel) 
            >> 2U))) {
        __Vdlyvval__system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem__v0 
            = (0xffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data 
                        >> 0x10U));
        __Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem__v0 = 1U;
        __Vdlyvdim0__system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem__v0 
            = (0x1fffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr);
    }
    if ((((((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_we) 
            & (~ (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state))) 
           & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb)) 
          & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc)) 
         & ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel) 
            >> 3U))) {
        __Vdlyvval__system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem__v0 
            = (0xffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data 
                        >> 0x18U));
        __Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem__v0 = 1U;
        __Vdlyvdim0__system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem__v0 
            = (0x1fffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr);
    }
    if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state))) {
        if (((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_prev) 
             & (~ (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_db)))) {
            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter = 0U;
            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state = 2U;
        }
    } else {
        if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state))) {
            if (VL_GTS_III(1,32,32, 0x6cU, vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter)) {
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter 
                    = ((IData)(1U) + vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter);
            } else {
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter = 0U;
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state = 3U;
            }
        } else {
            if (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__sample) {
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state 
                    = ((0xbU > (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state))
                        ? (0xfU & ((IData)(1U) + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state)))
                        : 0U);
                if (((2U < (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state)) 
                     & (0xbU > (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state)))) {
                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data 
                        = (((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_db) 
                            << 7U) | (0x7fU & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data) 
                                               >> 1U)));
                }
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter = 0U;
            } else {
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter 
                    = ((IData)(1U) + vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter);
            }
        }
    }
    if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state))) {
        if (((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode)
              ? (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_stb)
              : (0xdU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state)))) {
            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter = 0U;
            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state = 2U;
            vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__data 
                = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_data;
        }
    } else {
        if ((0x1b1U == vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter)) {
            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state 
                = ((0xbU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state))));
            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter = 0U;
        } else {
            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter 
                = ((IData)(1U) + vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter);
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs1_val = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs1_val 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number = 0U;
            if ((1U & (~ ((0x13U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                          | (3U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))))) {
                if (((0x33U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                     | (0x23U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number 
                        = (0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                    >> 0x14U));
                } else {
                    if ((0x63U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number 
                            = (0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                        >> 0x14U));
                    }
                }
            }
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number = 0U;
            if (((0x13U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                 | (3U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number 
                    = (0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                >> 0xfU));
            } else {
                if (((0x33U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                     | (0x23U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number 
                        = (0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                    >> 0xfU));
                } else {
                    if ((0x63U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number 
                            = (0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                        >> 0xfU));
                    } else {
                        if ((0x6fU != (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                            if ((0x67U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number 
                                    = (0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                                >> 0xfU));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7 = 0U;
    } else {
        if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7 = 0U;
            }
        } else {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func7;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7 = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_pc = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_pc 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc;
        }
    }
    if (((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_stb) 
         & (~ (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode)))) {
        if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
            if ((0x3aU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data))) {
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum = 0U;
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd = 0U;
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 3U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
                __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii 
                    = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__Vfuncout 
                    = ((0x80U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                        ? 0U : ((0x40U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                 ? ((0x10U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                     ? 0U : ((8U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                              ? 0U : 
                                             ((4U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                               ? ((2U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                    ? 0U
                                                    : 0xfU)
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                    ? 0xeU
                                                    : 0xdU))
                                               : ((2U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                    ? 0xcU
                                                    : 0xbU)
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                    ? 0xaU
                                                    : 0U)))))
                                 : ((0x20U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                     ? ((0x10U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                         ? ((8U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                             ? ((4U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                 ? 0U
                                                 : 
                                                ((2U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                  ? 0U
                                                  : 
                                                 ((1U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                   ? 9U
                                                   : 8U)))
                                             : ((4U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                 ? 
                                                ((2U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                   ? 7U
                                                   : 6U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                   ? 5U
                                                   : 4U))
                                                 : 
                                                ((2U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                   ? 3U
                                                   : 2U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__ascii))
                                                   ? 1U
                                                   : 0U))))
                                         : 0U) : 0U)));
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd 
                    = ((IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__0__Vfuncout) 
                       << 4U);
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 2U;
            } else {
                if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii 
                        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__Vfuncout 
                        = ((0x80U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                            ? 0U : ((0x40U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                     ? ((0x10U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                         ? 0U : ((8U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                  ? 0U
                                                  : 
                                                 ((4U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                     ? 0U
                                                     : 0xfU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                     ? 0xeU
                                                     : 0xdU))
                                                   : 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                     ? 0xcU
                                                     : 0xbU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                     ? 0xaU
                                                     : 0U)))))
                                     : ((0x20U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                         ? ((0x10U 
                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                             ? ((8U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                 ? 
                                                ((4U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                    ? 9U
                                                    : 8U)))
                                                 : 
                                                ((4U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                    ? 7U
                                                    : 6U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                    ? 5U
                                                    : 4U))
                                                  : 
                                                 ((2U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                    ? 3U
                                                    : 2U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__ascii))
                                                    ? 1U
                                                    : 0U))))
                                             : 0U) : 0U)));
                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd 
                        = ((0xf0U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd)) 
                           | (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__1__Vfuncout));
                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill = 0U;
                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__filled_high = 0U;
                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state 
                        = ((0U < (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len))
                            ? 9U : 0xbU);
                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii 
                        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__Vfuncout 
                        = ((0x80U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                            ? 0U : ((0x40U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                     ? ((0x10U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                         ? 0U : ((8U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                  ? 0U
                                                  : 
                                                 ((4U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                     ? 0U
                                                     : 0xfU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                     ? 0xeU
                                                     : 0xdU))
                                                   : 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                     ? 0xcU
                                                     : 0xbU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                     ? 0xaU
                                                     : 0U)))))
                                     : ((0x20U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                         ? ((0x10U 
                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                             ? ((8U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                 ? 
                                                ((4U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                    ? 9U
                                                    : 8U)))
                                                 : 
                                                ((4U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                    ? 7U
                                                    : 6U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                    ? 5U
                                                    : 4U))
                                                  : 
                                                 ((2U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                    ? 3U
                                                    : 2U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__ascii))
                                                    ? 1U
                                                    : 0U))))
                                             : 0U) : 0U)));
                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum 
                        = (0xffU & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum) 
                                    + ((0xf0U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd)) 
                                       | (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__2__Vfuncout))));
                } else {
                    if ((3U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
                        __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii 
                            = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                        __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__Vfuncout 
                            = ((0x80U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                ? 0U : ((0x40U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                         ? ((0x10U 
                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                             ? 0U : 
                                            ((8U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                              ? 0U : 
                                             ((4U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                               ? ((2U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                    ? 0U
                                                    : 0xfU)
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                    ? 0xeU
                                                    : 0xdU))
                                               : ((2U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                    ? 0xcU
                                                    : 0xbU)
                                                   : 
                                                  ((1U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                    ? 0xaU
                                                    : 0U)))))
                                         : ((0x20U 
                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                             ? ((0x10U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                 ? 
                                                ((8U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                     ? 9U
                                                     : 8U)))
                                                  : 
                                                 ((4U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                     ? 7U
                                                     : 6U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                     ? 5U
                                                     : 4U))
                                                   : 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                     ? 3U
                                                     : 2U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__ascii))
                                                     ? 1U
                                                     : 0U))))
                                                 : 0U)
                                             : 0U)));
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len 
                            = ((IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__3__Vfuncout) 
                               << 4U);
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 4U;
                    } else {
                        if ((4U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
                            __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii 
                                = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                            __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__Vfuncout 
                                = ((0x80U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                    ? 0U : ((0x40U 
                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                             ? ((0x10U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                 ? 0U
                                                 : 
                                                ((8U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                  ? 0U
                                                  : 
                                                 ((4U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                     ? 0U
                                                     : 0xfU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                     ? 0xeU
                                                     : 0xdU))
                                                   : 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                     ? 0xcU
                                                     : 0xbU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                     ? 0xaU
                                                     : 0U)))))
                                             : ((0x20U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                 ? 
                                                ((0x10U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                  ? 
                                                 ((8U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                     ? 0U
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                      ? 9U
                                                      : 8U)))
                                                   : 
                                                  ((4U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                      ? 7U
                                                      : 6U)
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                      ? 5U
                                                      : 4U))
                                                    : 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                      ? 3U
                                                      : 2U)
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__ascii))
                                                      ? 1U
                                                      : 0U))))
                                                  : 0U)
                                                 : 0U)));
                            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len 
                                = ((0xf0U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len)) 
                                   | (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__4__Vfuncout));
                            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 5U;
                            __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii 
                                = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                            __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__Vfuncout 
                                = ((0x80U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                    ? 0U : ((0x40U 
                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                             ? ((0x10U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                 ? 0U
                                                 : 
                                                ((8U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                  ? 0U
                                                  : 
                                                 ((4U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                     ? 0U
                                                     : 0xfU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                     ? 0xeU
                                                     : 0xdU))
                                                   : 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                     ? 0xcU
                                                     : 0xbU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                     ? 0xaU
                                                     : 0U)))))
                                             : ((0x20U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                 ? 
                                                ((0x10U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                  ? 
                                                 ((8U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                     ? 0U
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                      ? 9U
                                                      : 8U)))
                                                   : 
                                                  ((4U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                      ? 7U
                                                      : 6U)
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                      ? 5U
                                                      : 4U))
                                                    : 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                      ? 3U
                                                      : 2U)
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__ascii))
                                                      ? 1U
                                                      : 0U))))
                                                  : 0U)
                                                 : 0U)));
                            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum 
                                = (0xffU & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum) 
                                            + ((0xf0U 
                                                & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len)) 
                                               | (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__5__Vfuncout))));
                        } else {
                            if ((5U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
                                __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii 
                                    = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                                __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__Vfuncout 
                                    = ((0x80U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                        ? 0U : ((0x40U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                 ? 
                                                ((0x10U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                  ? 0U
                                                  : 
                                                 ((8U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                      ? 0U
                                                      : 0xfU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                      ? 0xeU
                                                      : 0xdU))
                                                    : 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                      ? 0xcU
                                                      : 0xbU)
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                      ? 0xaU
                                                      : 0U)))))
                                                 : 
                                                ((0x20U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                  ? 
                                                 ((0x10U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                   ? 
                                                  ((8U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                       ? 9U
                                                       : 8U)))
                                                    : 
                                                   ((4U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                       ? 7U
                                                       : 6U)
                                                      : 
                                                     ((1U 
                                                       & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                       ? 5U
                                                       : 4U))
                                                     : 
                                                    ((2U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                       ? 3U
                                                       : 2U)
                                                      : 
                                                     ((1U 
                                                       & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__ascii))
                                                       ? 1U
                                                       : 0U))))
                                                   : 0U)
                                                  : 0U)));
                                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr 
                                    = ((IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__6__Vfuncout) 
                                       << 0xcU);
                                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 6U;
                            } else {
                                if ((6U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
                                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii 
                                        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__Vfuncout 
                                        = ((0x80U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                            ? 0U : 
                                           ((0x40U 
                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                             ? ((0x10U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                 ? 0U
                                                 : 
                                                ((8U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                  ? 0U
                                                  : 
                                                 ((4U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                     ? 0U
                                                     : 0xfU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                     ? 0xeU
                                                     : 0xdU))
                                                   : 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                     ? 0xcU
                                                     : 0xbU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                     ? 0xaU
                                                     : 0U)))))
                                             : ((0x20U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                 ? 
                                                ((0x10U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                  ? 
                                                 ((8U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                     ? 0U
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                      ? 9U
                                                      : 8U)))
                                                   : 
                                                  ((4U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                      ? 7U
                                                      : 6U)
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                      ? 5U
                                                      : 4U))
                                                    : 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                      ? 3U
                                                      : 2U)
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__ascii))
                                                      ? 1U
                                                      : 0U))))
                                                  : 0U)
                                                 : 0U)));
                                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr 
                                        = ((0xf000U 
                                            & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr)) 
                                           | ((IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__7__Vfuncout) 
                                              << 8U));
                                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 7U;
                                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii 
                                        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__Vfuncout 
                                        = ((0x80U & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                            ? 0U : 
                                           ((0x40U 
                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                             ? ((0x10U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                 ? 0U
                                                 : 
                                                ((8U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                  ? 0U
                                                  : 
                                                 ((4U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                     ? 0U
                                                     : 0xfU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                     ? 0xeU
                                                     : 0xdU))
                                                   : 
                                                  ((2U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                     ? 0xcU
                                                     : 0xbU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                     ? 0xaU
                                                     : 0U)))))
                                             : ((0x20U 
                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                 ? 
                                                ((0x10U 
                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                  ? 
                                                 ((8U 
                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                     ? 0U
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                      ? 9U
                                                      : 8U)))
                                                   : 
                                                  ((4U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                      ? 7U
                                                      : 6U)
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                      ? 5U
                                                      : 4U))
                                                    : 
                                                   ((2U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                      ? 3U
                                                      : 2U)
                                                     : 
                                                    ((1U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__ascii))
                                                      ? 1U
                                                      : 0U))))
                                                  : 0U)
                                                 : 0U)));
                                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum 
                                        = (0xffU & 
                                           ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum) 
                                            + ((0xf0U 
                                                & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr) 
                                                   >> 8U)) 
                                               | (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__8__Vfuncout))));
                                } else {
                                    if ((7U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
                                        __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii 
                                            = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                                        __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__Vfuncout 
                                            = ((0x80U 
                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                ? 0U
                                                : (
                                                   (0x40U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                    ? 
                                                   ((0x10U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                     ? 0U
                                                     : 
                                                    ((8U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                         ? 0U
                                                         : 0xfU)
                                                        : 
                                                       ((1U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                         ? 0xeU
                                                         : 0xdU))
                                                       : 
                                                      ((2U 
                                                        & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                         ? 0xcU
                                                         : 0xbU)
                                                        : 
                                                       ((1U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                         ? 0xaU
                                                         : 0U)))))
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                     ? 
                                                    ((0x10U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                         ? 0U
                                                         : 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                          ? 9U
                                                          : 8U)))
                                                       : 
                                                      ((4U 
                                                        & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                          ? 7U
                                                          : 6U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                          ? 5U
                                                          : 4U))
                                                        : 
                                                       ((2U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                          ? 3U
                                                          : 2U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__ascii))
                                                          ? 1U
                                                          : 0U))))
                                                      : 0U)
                                                     : 0U)));
                                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr 
                                            = ((0xff00U 
                                                & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr)) 
                                               | ((IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__9__Vfuncout) 
                                                  << 4U));
                                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 8U;
                                    } else {
                                        if ((8U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
                                            __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii 
                                                = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                                            __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__Vfuncout 
                                                = (
                                                   (0x80U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                    ? 0U
                                                    : 
                                                   ((0x40U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                     ? 
                                                    ((0x10U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                          ? 0U
                                                          : 0xfU)
                                                         : 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                          ? 0xeU
                                                          : 0xdU))
                                                        : 
                                                       ((2U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                          ? 0xcU
                                                          : 0xbU)
                                                         : 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                          ? 0xaU
                                                          : 0U)))))
                                                     : 
                                                    ((0x20U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                      ? 
                                                     ((0x10U 
                                                       & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                       ? 
                                                      ((8U 
                                                        & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                        ? 
                                                       ((4U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                         ? 0U
                                                         : 
                                                        ((2U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                          ? 0U
                                                          : 
                                                         ((1U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                           ? 9U
                                                           : 8U)))
                                                        : 
                                                       ((4U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                         ? 
                                                        ((2U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                           ? 7U
                                                           : 6U)
                                                          : 
                                                         ((1U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                           ? 5U
                                                           : 4U))
                                                         : 
                                                        ((2U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                           ? 3U
                                                           : 2U)
                                                          : 
                                                         ((1U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__ascii))
                                                           ? 1U
                                                           : 0U))))
                                                       : 0U)
                                                      : 0U)));
                                            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr 
                                                = (
                                                   (0xfff0U 
                                                    & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr)) 
                                                   | (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__10__Vfuncout));
                                            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 1U;
                                            __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii 
                                                = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                                            __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__Vfuncout 
                                                = (
                                                   (0x80U 
                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                    ? 0U
                                                    : 
                                                   ((0x40U 
                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                     ? 
                                                    ((0x10U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                          ? 0U
                                                          : 0xfU)
                                                         : 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                          ? 0xeU
                                                          : 0xdU))
                                                        : 
                                                       ((2U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                          ? 0xcU
                                                          : 0xbU)
                                                         : 
                                                        ((1U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                          ? 0xaU
                                                          : 0U)))))
                                                     : 
                                                    ((0x20U 
                                                      & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                      ? 
                                                     ((0x10U 
                                                       & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                       ? 
                                                      ((8U 
                                                        & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                        ? 
                                                       ((4U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                         ? 0U
                                                         : 
                                                        ((2U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                          ? 0U
                                                          : 
                                                         ((1U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                           ? 9U
                                                           : 8U)))
                                                        : 
                                                       ((4U 
                                                         & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                         ? 
                                                        ((2U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                           ? 7U
                                                           : 6U)
                                                          : 
                                                         ((1U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                           ? 5U
                                                           : 4U))
                                                         : 
                                                        ((2U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                           ? 3U
                                                           : 2U)
                                                          : 
                                                         ((1U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__ascii))
                                                           ? 1U
                                                           : 0U))))
                                                       : 0U)
                                                      : 0U)));
                                            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum 
                                                = (0xffU 
                                                   & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum) 
                                                      + 
                                                      ((0xf0U 
                                                        & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr)) 
                                                       | (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__11__Vfuncout))));
                                        } else {
                                            if ((9U 
                                                 == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
                                                if (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__filled_high) {
                                                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii 
                                                        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                                                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__Vfuncout 
                                                        = 
                                                        ((0x80U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                          ? 0U
                                                          : 
                                                         ((0x40U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                           ? 
                                                          ((0x10U 
                                                            & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                            ? 0U
                                                            : 
                                                           ((8U 
                                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                             ? 0U
                                                             : 
                                                            ((4U 
                                                              & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                              ? 
                                                             ((2U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                               ? 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                                ? 0U
                                                                : 0xfU)
                                                               : 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                                ? 0xeU
                                                                : 0xdU))
                                                              : 
                                                             ((2U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                               ? 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                                ? 0xcU
                                                                : 0xbU)
                                                               : 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                                ? 0xaU
                                                                : 0U)))))
                                                           : 
                                                          ((0x20U 
                                                            & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                            ? 
                                                           ((0x10U 
                                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                             ? 
                                                            ((8U 
                                                              & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                              ? 
                                                             ((4U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                               ? 0U
                                                               : 
                                                              ((2U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                                ? 0U
                                                                : 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                                 ? 9U
                                                                 : 8U)))
                                                              : 
                                                             ((4U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                               ? 
                                                              ((2U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                                ? 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                                 ? 7U
                                                                 : 6U)
                                                                : 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                                 ? 5U
                                                                 : 4U))
                                                               : 
                                                              ((2U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                                ? 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                                 ? 3U
                                                                 : 2U)
                                                                : 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__ascii))
                                                                 ? 1U
                                                                 : 0U))))
                                                             : 0U)
                                                            : 0U)));
                                                    __Vdlyvval__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v0 
                                                        = 
                                                        ((0xf0U 
                                                          & vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                                          [vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill]) 
                                                         | (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__12__Vfuncout));
                                                    __Vdlyvset__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v0 = 1U;
                                                    __Vdlyvdim0__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v0 
                                                        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill;
                                                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__filled_high = 0U;
                                                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii 
                                                        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                                                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__Vfuncout 
                                                        = 
                                                        ((0x80U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                          ? 0U
                                                          : 
                                                         ((0x40U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                           ? 
                                                          ((0x10U 
                                                            & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                            ? 0U
                                                            : 
                                                           ((8U 
                                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                             ? 0U
                                                             : 
                                                            ((4U 
                                                              & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                              ? 
                                                             ((2U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                               ? 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                                ? 0U
                                                                : 0xfU)
                                                               : 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                                ? 0xeU
                                                                : 0xdU))
                                                              : 
                                                             ((2U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                               ? 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                                ? 0xcU
                                                                : 0xbU)
                                                               : 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                                ? 0xaU
                                                                : 0U)))))
                                                           : 
                                                          ((0x20U 
                                                            & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                            ? 
                                                           ((0x10U 
                                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                             ? 
                                                            ((8U 
                                                              & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                              ? 
                                                             ((4U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                               ? 0U
                                                               : 
                                                              ((2U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                                ? 0U
                                                                : 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                                 ? 9U
                                                                 : 8U)))
                                                              : 
                                                             ((4U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                               ? 
                                                              ((2U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                                ? 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                                 ? 7U
                                                                 : 6U)
                                                                : 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                                 ? 5U
                                                                 : 4U))
                                                               : 
                                                              ((2U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                                ? 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                                 ? 3U
                                                                 : 2U)
                                                                : 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__ascii))
                                                                 ? 1U
                                                                 : 0U))))
                                                             : 0U)
                                                            : 0U)));
                                                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum 
                                                        = 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum) 
                                                            + 
                                                            ((0xf0U 
                                                              & vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                                              [vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill]) 
                                                             | (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__13__Vfuncout))));
                                                    if (
                                                        (((IData)(1U) 
                                                          + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill)) 
                                                         < (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len))) {
                                                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill 
                                                            = 
                                                            (0xffU 
                                                             & ((IData)(1U) 
                                                                + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill)));
                                                    } else {
                                                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xbU;
                                                    }
                                                } else {
                                                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii 
                                                        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                                                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__Vfuncout 
                                                        = 
                                                        ((0x80U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                          ? 0U
                                                          : 
                                                         ((0x40U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                           ? 
                                                          ((0x10U 
                                                            & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                            ? 0U
                                                            : 
                                                           ((8U 
                                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                             ? 0U
                                                             : 
                                                            ((4U 
                                                              & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                              ? 
                                                             ((2U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                               ? 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                                ? 0U
                                                                : 0xfU)
                                                               : 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                                ? 0xeU
                                                                : 0xdU))
                                                              : 
                                                             ((2U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                               ? 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                                ? 0xcU
                                                                : 0xbU)
                                                               : 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                                ? 0xaU
                                                                : 0U)))))
                                                           : 
                                                          ((0x20U 
                                                            & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                            ? 
                                                           ((0x10U 
                                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                             ? 
                                                            ((8U 
                                                              & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                              ? 
                                                             ((4U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                               ? 0U
                                                               : 
                                                              ((2U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                                ? 0U
                                                                : 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                                 ? 9U
                                                                 : 8U)))
                                                              : 
                                                             ((4U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                               ? 
                                                              ((2U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                                ? 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                                 ? 7U
                                                                 : 6U)
                                                                : 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                                 ? 5U
                                                                 : 4U))
                                                               : 
                                                              ((2U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                                ? 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                                 ? 3U
                                                                 : 2U)
                                                                : 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__ascii))
                                                                 ? 1U
                                                                 : 0U))))
                                                             : 0U)
                                                            : 0U)));
                                                    __Vdlyvval__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v1 
                                                        = 
                                                        ((IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__14__Vfuncout) 
                                                         << 4U);
                                                    __Vdlyvset__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v1 = 1U;
                                                    __Vdlyvdim0__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v1 
                                                        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill;
                                                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__filled_high = 1U;
                                                }
                                            } else {
                                                if (
                                                    (0xbU 
                                                     == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
                                                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii 
                                                        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                                                    __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__Vfuncout 
                                                        = 
                                                        ((0x80U 
                                                          & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                          ? 0U
                                                          : 
                                                         ((0x40U 
                                                           & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                           ? 
                                                          ((0x10U 
                                                            & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                            ? 0U
                                                            : 
                                                           ((8U 
                                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                             ? 0U
                                                             : 
                                                            ((4U 
                                                              & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                              ? 
                                                             ((2U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                               ? 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                                ? 0U
                                                                : 0xfU)
                                                               : 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                                ? 0xeU
                                                                : 0xdU))
                                                              : 
                                                             ((2U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                               ? 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                                ? 0xcU
                                                                : 0xbU)
                                                               : 
                                                              ((1U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                                ? 0xaU
                                                                : 0U)))))
                                                           : 
                                                          ((0x20U 
                                                            & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                            ? 
                                                           ((0x10U 
                                                             & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                             ? 
                                                            ((8U 
                                                              & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                              ? 
                                                             ((4U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                               ? 0U
                                                               : 
                                                              ((2U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                                ? 0U
                                                                : 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                                 ? 9U
                                                                 : 8U)))
                                                              : 
                                                             ((4U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                               ? 
                                                              ((2U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                                ? 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                                 ? 7U
                                                                 : 6U)
                                                                : 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                                 ? 5U
                                                                 : 4U))
                                                               : 
                                                              ((2U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                                ? 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                                 ? 3U
                                                                 : 2U)
                                                                : 
                                                               ((1U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__ascii))
                                                                 ? 1U
                                                                 : 0U))))
                                                             : 0U)
                                                            : 0U)));
                                                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmp_sum 
                                                        = 
                                                        ((IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__15__Vfuncout) 
                                                         << 4U);
                                                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xcU;
                                                } else {
                                                    if (
                                                        (0xcU 
                                                         == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
                                                        __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii 
                                                            = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
                                                        __Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__Vfuncout 
                                                            = 
                                                            ((0x80U 
                                                              & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                              ? 0U
                                                              : 
                                                             ((0x40U 
                                                               & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                               ? 
                                                              ((0x10U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                ? 0U
                                                                : 
                                                               ((8U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                 ? 0U
                                                                 : 
                                                                ((4U 
                                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                  ? 
                                                                 ((2U 
                                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                   ? 
                                                                  ((1U 
                                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                    ? 0U
                                                                    : 0xfU)
                                                                   : 
                                                                  ((1U 
                                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                    ? 0xeU
                                                                    : 0xdU))
                                                                  : 
                                                                 ((2U 
                                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                   ? 
                                                                  ((1U 
                                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                    ? 0xcU
                                                                    : 0xbU)
                                                                   : 
                                                                  ((1U 
                                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                    ? 0xaU
                                                                    : 0U)))))
                                                               : 
                                                              ((0x20U 
                                                                & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                ? 
                                                               ((0x10U 
                                                                 & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                 ? 
                                                                ((8U 
                                                                  & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                  ? 
                                                                 ((4U 
                                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                   ? 0U
                                                                   : 
                                                                  ((2U 
                                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                    ? 0U
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                     ? 9U
                                                                     : 8U)))
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                   ? 
                                                                  ((2U 
                                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                    ? 
                                                                   ((1U 
                                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                     ? 7U
                                                                     : 6U)
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                     ? 5U
                                                                     : 4U))
                                                                   : 
                                                                  ((2U 
                                                                    & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                    ? 
                                                                   ((1U 
                                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                     ? 3U
                                                                     : 2U)
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__ascii))
                                                                     ? 1U
                                                                     : 0U))))
                                                                 : 0U)
                                                                : 0U)));
                                                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmp_sum 
                                                            = 
                                                            ((0xf0U 
                                                              & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmp_sum)) 
                                                             | (IData)(__Vfunc_system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__hex_to_val__16__Vfuncout));
                                                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xaU;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0xaU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
        if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state))) {
            if (((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum_tcmp) 
                 == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmp_sum))) {
                if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd))) {
                    if ((0U < (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len))) {
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill = 1U;
                        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_addr 
                            = (((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset) 
                                << 0xeU) | (0x3fffU 
                                            & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr) 
                                               >> 2U)));
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xeU;
                        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_sel 
                            = ((2U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr))
                                ? ((1U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr))
                                    ? 8U : 4U) : ((1U 
                                                   & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr))
                                                   ? 2U
                                                   : 1U));
                        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_mosi_data 
                            = ((2U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr))
                                ? ((1U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr))
                                    ? (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                       [0U] << 0x18U)
                                    : (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                       [0U] << 0x10U))
                                : ((1U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr))
                                    ? (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                       [0U] << 8U) : 
                                   vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                   [0U]));
                    } else {
                        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data = 0x4bU;
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xdU;
                    }
                } else {
                    if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd))) {
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset = 0U;
                        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data = 0x52U;
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xdU;
                    } else {
                        if ((4U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd))) {
                            if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len))) {
                                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset 
                                    = ((vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                        [0U] << 8U) 
                                       | vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                       [1U]);
                                vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data = 0x53U;
                                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xdU;
                            } else {
                                vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data = 0x4dU;
                                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xdU;
                            }
                        } else {
                            vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data = 0x55U;
                            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xdU;
                        }
                    }
                }
            } else {
                vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data = 0x45U;
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xdU;
            }
        }
    }
    if ((0xeU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
        if ((1U & (~ ((0U != (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                      | (0U != (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT___io_master_stall_T)))))) {
            if (((0U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                 & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wberr))) {
                vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data = 0x57U;
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xdU;
            } else {
                if (((0U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                     & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wback))) {
                    if (((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill) 
                         < (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len))) {
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill)));
                        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_addr 
                            = (((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset) 
                                << 0xeU) | (0x3fffU 
                                            & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr) 
                                               >> 2U)));
                        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_sel 
                            = ((2U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr))
                                ? ((1U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr))
                                    ? 8U : 4U) : ((1U 
                                                   & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr))
                                                   ? 2U
                                                   : 1U));
                        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_mosi_data 
                            = ((2U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr))
                                ? ((1U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr))
                                    ? (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                       [vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill] 
                                       << 0x18U) : 
                                   (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                    [vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill] 
                                    << 0x10U)) : ((1U 
                                                   & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr))
                                                   ? 
                                                  (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                                   [vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill] 
                                                   << 8U)
                                                   : 
                                                  vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                                  [vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill]));
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xeU;
                    } else {
                        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data = 0x4bU;
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xdU;
                    }
                } else {
                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xfU;
                }
            }
        }
    }
    if ((0xfU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
        if (((0U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
             & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wberr))) {
            vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data = 0x57U;
            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xdU;
        } else {
            if (((0U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                 & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wback))) {
                if (((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill) 
                     < (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len))) {
                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill 
                        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill)));
                    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_addr 
                        = (((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset) 
                            << 0xeU) | (0x3fffU & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr) 
                                                   >> 2U)));
                    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_sel 
                        = ((2U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr))
                            ? ((1U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr))
                                ? 8U : 4U) : ((1U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr))
                                               ? 2U
                                               : 1U));
                    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_mosi_data 
                        = ((2U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr))
                            ? ((1U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr))
                                ? (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                   [vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill] 
                                   << 0x18U) : (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                                [vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill] 
                                                << 0x10U))
                            : ((1U & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr))
                                ? (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                                   [vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill] 
                                   << 8U) : vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer
                               [vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill]));
                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xeU;
                } else {
                    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data = 0x4bU;
                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0xdU;
                }
            }
        }
    }
    if ((0xdU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))) {
        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0U;
    }
    if (((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode)
          ? 1U : (1U & (IData)(vlTOPp->system__DOT__reset)))) {
        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_immediate = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_immediate 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate;
        }
    }
    __Vdlyvval__system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file__v0 
        = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__data;
    __Vdlyvdim0__system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file__v0 
        = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__dest_addr;
    if (vlTOPp->system__DOT__reset) {
        __Vdly__system__DOT__top__DOT__arbiter__DOT__currentMaster = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_32)))) {
            __Vdly__system__DOT__top__DOT__arbiter__DOT__currentMaster 
                = (((IData)(vlSymsp->TOP__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb.cyc) 
                    & (0xeU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state)))
                    ? 0U : (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_cyc) 
                             & (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_stb))
                             ? 1U : (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_cyc) 
                                      & (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_stb))
                                      ? 2U : 0U)));
        }
    }
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__filled_high 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__filled_high;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmp_sum 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmp_sum;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset;
    if (__Vdlyvset__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v0) {
        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer[__Vdlyvdim0__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v0] 
            = __Vdlyvval__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v0;
    }
    if (__Vdlyvset__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v1) {
        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer[__Vdlyvdim0__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v1] 
            = __Vdlyvval__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer__v1;
    }
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data;
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[__Vdlyvdim0__system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file__v0] 
        = __Vdlyvval__system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file__v0;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state;
    if (vlTOPp->system__DOT__reset) {
        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer = 0U;
    } else {
        if (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT____Vcellinp__uart_ctrlr____pinNumber4) {
            vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer 
                = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_next_write;
        }
    }
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__sample 
        = VL_LTES_III(1,32,32, 0x1b1U, vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter);
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_stb 
        = ((0xbU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state)) 
           & (0U == vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_prev 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_db;
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val = 0U;
    } else {
        if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val = 0U;
            }
        } else {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs1_val;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func7 = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func7 = 0U;
            if (((0x13U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                 | (3U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))) {
                if (((0x13U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                     & ((1U == (7U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                      >> 0xcU))) | 
                        (5U == (7U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                      >> 0xcU)))))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func7 
                        = (0x7fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                    >> 0x19U));
                }
            } else {
                if (((0x33U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                     | (0x23U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))) {
                    if ((0x23U != (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                        if ((0x33U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func7 
                                = (0x7fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                            >> 0x19U));
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func7 = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc = 0U;
    } else {
        if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc = 0U;
            }
        } else {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_pc;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc = 0U;
    }
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum_tcmp 
        = (0xffU & ((IData)(1U) + (~ (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum))));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr 
        = (0xffffU & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr) 
                      + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill)));
    if (vlTOPp->system__DOT__reset) {
        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode = 0U;
    } else {
        if ((((IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_2_stb) 
              & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_2_cyc)) 
             & (IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_we))) {
            vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode = 1U;
        }
    }
    vlTOPp->system__DOT__top__DOT__interconnect___DOT__wberr 
        = ((~ (IData)(vlTOPp->system__DOT__reset)) 
           & ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_stb) 
              & (~ ((0x1e000200U == (0x1fffffffU & 
                                     (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                      >> 1U))) | ((0x3c000000U 
                                                   == 
                                                   (0x3fffffffU 
                                                    & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)) 
                                                  | (0U 
                                                     == 
                                                     (0x1ffffU 
                                                      & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                                         >> 0xdU))))))));
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate = 0U;
    } else {
        if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate = 0U;
            }
        } else {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate = 0U;
    }
    if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset)))) {
        if ((1U & (~ ((0x23U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)) 
                      | (3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)))))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__dest_addr 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rd_number;
        }
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__dest_addr 
        = ((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)
            ? 0U : (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rd_number));
    vlSymsp->TOP__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb.cyc 
        = ((0xeU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state)) 
           | (0xfU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state)));
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state = 0U;
        vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_cyc = 0U;
        vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_stb = 0U;
    } else {
        if (((0x23U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)) 
             | (3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)))) {
            if (((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state)) 
                 & ((0x23U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)) 
                    | (3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode))))) {
                __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state = 1U;
                vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_cyc = 1U;
                vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_stb = 1U;
                vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_we = 0U;
                vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_addr 
                    = (0x3fffffffU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset 
                                      >> 2U));
                if ((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_sel = 0xfU;
                } else {
                    if ((0x23U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_we = 1U;
                        if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_sel 
                                = (0xfU & ((IData)(1U) 
                                           << (3U & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset)));
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_mosi_data 
                                = ((0x1fU >= (0x18U 
                                              & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset 
                                                 << 3U)))
                                    ? ((0xffU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs2_val) 
                                       << (0x18U & 
                                           (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset 
                                            << 3U)))
                                    : 0U);
                        } else {
                            if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_sel 
                                    = (0xfU & ((IData)(3U) 
                                               << (3U 
                                                   & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset)));
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_mosi_data 
                                    = ((0x1fU >= (0x18U 
                                                  & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset 
                                                     << 3U)))
                                        ? ((0xffffU 
                                            & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs2_val) 
                                           << (0x18U 
                                               & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset 
                                                  << 3U)))
                                        : 0U);
                            } else {
                                if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
                                    vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_sel = 0xfU;
                                    vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_mosi_data 
                                        = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs2_val;
                                }
                            }
                        }
                    }
                }
            } else {
                if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state))) {
                    if (((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_masters_1_ack) 
                         & (~ ((1U != (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                               | (0U != (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT___io_master_stall_T)))))) {
                        __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state = 0U;
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_cyc = 0U;
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_stb = 0U;
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__data 
                            = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result;
                    } else {
                        if ((1U & (~ ((1U != (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                                      | (0U != (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT___io_master_stall_T)))))) {
                            __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state = 2U;
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_cyc = 1U;
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_stb = 0U;
                        }
                    }
                } else {
                    if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state))) {
                        if (vlTOPp->system__DOT__top__DOT__arbiter_io_masters_1_ack) {
                            __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state = 0U;
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_cyc = 0U;
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_stb = 0U;
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__data 
                                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result;
                        }
                    }
                }
            }
        } else {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__data 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_result;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__data = 0U;
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state 
        = __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state;
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset 
        = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs1_val 
           + ((0xfffff000U & (VL_NEGATE_I((IData)((1U 
                                                   & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_immediate 
                                                      >> 0xbU)))) 
                              << 0xcU)) | (0xfffU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_immediate)));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_next_write 
        = (0x1ffU & ((IData)(1U) + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer)));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_db 
        = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_int;
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_pc = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_pc 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_pc;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_pc = 0U;
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended 
        = ((0xfffff000U & (VL_NEGATE_I((IData)((1U 
                                                & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate 
                                                   >> 0xbU)))) 
                           << 0xcU)) | (0xfffU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate));
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate = 0U;
            if (((0x13U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                 | (3U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate 
                    = (((0x13U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                        & ((1U == (7U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                         >> 0xcU))) 
                           | (5U == (7U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                           >> 0xcU)))))
                        ? (IData)((QData)((IData)((0x1fU 
                                                   & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                                      >> 0x14U)))))
                        : (0xfffU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                     >> 0x14U)));
            } else {
                if (((0x33U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                     | (0x23U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))) {
                    if ((0x23U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate 
                            = ((0xfe0U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                          >> 0x14U)) 
                               | (0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                           >> 7U)));
                    }
                } else {
                    if ((0x63U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate 
                            = ((0xffffe000U & (VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & ((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id__DOT__branch_offset) 
                                                                       >> 0xbU)))) 
                                               << 0xdU)) 
                               | ((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id__DOT__branch_offset) 
                                  << 1U));
                    } else {
                        if ((0x6fU == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate 
                                = ((0xffe00000U & (
                                                   VL_NEGATE_I((IData)(
                                                                       (1U 
                                                                        & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                                                           >> 0x1fU)))) 
                                                   << 0x15U)) 
                                   | ((0x100000U & 
                                       (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                        >> 0xbU)) | 
                                      ((0xff000U & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction) 
                                       | ((0x800U & 
                                           (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                            >> 9U)) 
                                          | (0x7feU 
                                             & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                                >> 0x14U))))));
                        } else {
                            if ((0x67U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate 
                                    = ((0xfffff000U 
                                        & (VL_NEGATE_I((IData)(
                                                               (1U 
                                                                & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                                                   >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | (0xfffU & 
                                          (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                           >> 0x14U)));
                            } else {
                                if (((0x37U == (0x7fU 
                                                & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                                     | (0x17U == (0x7fU 
                                                  & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))) {
                                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate 
                                        = (0xfffff000U 
                                           & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rd_number = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rd_number 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number;
        }
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_result = 0U;
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_result = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_result 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs2_val = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs2_val 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3 = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode;
        }
    }
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_int 
        = vlTOPp->io_rx;
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number = 0U;
    } else {
        if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number = 0U;
            }
        } else {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_rd_number;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val = 0U;
    } else {
        if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val = 0U;
            }
        } else {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs2_val;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3 = 0U;
    } else {
        if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3 = 0U;
            }
        } else {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func3;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3 = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode = 0U;
    } else {
        if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode = 0U;
            }
        } else {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_opcode;
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_rd_number = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_rd_number = 0U;
            if (((0x13U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                 | (3U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_rd_number 
                    = (0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                >> 7U));
            } else {
                if (((0x33U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                     | (0x23U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))) {
                    if ((0x23U != (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                        if ((0x33U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_rd_number 
                                = (0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                            >> 7U));
                        }
                    }
                } else {
                    if ((0x63U != (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                        if ((0x6fU == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_rd_number 
                                = (0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                            >> 7U));
                        } else {
                            if ((0x67U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_rd_number 
                                    = (0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                                >> 7U));
                            } else {
                                if (((0x37U == (0x7fU 
                                                & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                                     | (0x17U == (0x7fU 
                                                  & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))) {
                                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_rd_number 
                                        = (0x1fU & 
                                           (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                            >> 7U));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_rd_number = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func3 = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func3 = 0U;
            if ((((0x6fU != (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                  & (0x37U != (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) 
                 & (0x17U != (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func3 
                    = (7U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                             >> 0xcU));
            }
            if ((1U & (~ ((0x13U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                          | (3U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))))) {
                if ((1U & (~ ((0x33U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)) 
                              | (0x23U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)))))) {
                    if ((0x63U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func3 
                            = (7U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                     >> 0xcU));
                    } else {
                        if ((0x6fU != (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                            if ((0x67U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func3 
                                    = (7U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                             >> 0xcU));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func3 = 0U;
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid = 0U;
    if (((0x33U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode)) 
         | (0x13U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode)))) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid = 1U;
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result = 0U;
    if ((0x33U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
        if ((0x20U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7))) {
            if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                    = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                       - vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val);
            }
            if ((5U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                    = VL_SHIFTRS_III(32,32,5, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val, 
                                     (0x1fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val));
            }
        } else {
            if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7))) {
                if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                        = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                           + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val);
                } else {
                    if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                            = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                               << (0x1fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val));
                    } else {
                        if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                = (VL_LTS_III(1,32,32, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val)
                                    ? 1U : 0U);
                        } else {
                            if ((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                    = ((vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                        < vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val)
                                        ? 1U : 0U);
                            } else {
                                if ((4U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                        = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                           ^ vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val);
                                } else {
                                    if ((5U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                            = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                               >> (0x1fU 
                                                   & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val));
                                    } else {
                                        if ((6U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                                = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                                   | vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val);
                                        } else {
                                            if ((7U 
                                                 == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                                    = 
                                                    (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                                     & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x13U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
            if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                    = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                       + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended);
            } else {
                if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                        = (VL_LTS_III(1,32,32, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended)
                            ? 1U : 0U);
                } else {
                    if ((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                            = ((vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                < vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended)
                                ? 1U : 0U);
                    } else {
                        if ((4U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended 
                                   ^ vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val);
                        } else {
                            if ((6U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                    = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended 
                                       | vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val);
                            } else {
                                if ((7U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                        = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended 
                                           & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val);
                                } else {
                                    if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3))) {
                                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                            = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                               << (0x1fU 
                                                   & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate));
                                    } else {
                                        if (((5U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                                             | (5U 
                                                == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)))) {
                                            if ((0U 
                                                 == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7))) {
                                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                                    = 
                                                    (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                                     >> 
                                                     (0x1fU 
                                                      & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate));
                                            } else {
                                                if (
                                                    (0x20U 
                                                     == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7))) {
                                                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                                        = 
                                                        VL_SHIFTRS_III(32,32,5, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val, 
                                                                       (0x1fU 
                                                                        & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x63U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                if ((0x6fU == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                        = ((IData)(4U) + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc);
                } else {
                    if ((0x67U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                            = ((IData)(4U) + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc);
                    } else {
                        if ((0x37U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate;
                        } else {
                            if ((0x17U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result 
                                    = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate 
                                       + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc);
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_opcode = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_opcode 
                = (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction);
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_opcode = 0U;
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset) {
        __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc = 0U;
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction = 0U;
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_pc = 0U;
        __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_pc = 0U;
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction = 0U;
        }
        if (((~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)) 
             & (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_pc = 0U;
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction = 0U;
            __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc 
                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__new_pc;
            __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state = 1U;
        }
        if (((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state)) 
             & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)))) {
            __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state = 1U;
        } else {
            if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state))) {
                if ((((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                      & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wback)) 
                     & (~ ((2U != (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                           | (0U != (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT___io_master_stall_T)))))) {
                    __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state = 0U;
                    if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)))) {
                        __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state = 1U;
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_pc 
                            = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc;
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                            = vlTOPp->system__DOT__top__DOT__interconnect___DOT__wbdata;
                        __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc 
                            = ((IData)(4U) + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc);
                    }
                } else {
                    if ((1U & (~ ((2U != (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                                  | (0U != (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT___io_master_stall_T)))))) {
                        __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state = 2U;
                    }
                }
            } else {
                if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state))) {
                    if (((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                         & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wback))) {
                        __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state = 0U;
                        if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall)))) {
                            __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state = 1U;
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_pc 
                                = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc;
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                = vlTOPp->system__DOT__top__DOT__interconnect___DOT__wbdata;
                            __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc 
                                = ((IData)(4U) + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc);
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc 
            = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__new_pc;
        __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state = 0U;
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_pc = 0U;
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction = 0U;
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__new_pc 
        = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc 
           + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate);
    if ((0x33U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
        if ((0x13U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
            if ((0x63U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                if ((0x6fU != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                    if ((0x67U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__new_pc 
                            = (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate 
                               + vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val);
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__new_pc 
                            = (0xfffffffeU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__new_pc);
                    }
                }
            }
        }
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc 
        = __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc;
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state 
        = __Vdly__system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state;
    vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster 
        = __Vdly__system__DOT__top__DOT__arbiter__DOT__currentMaster;
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id__DOT__branch_offset 
        = ((0x800U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                      >> 0x14U)) | ((0x400U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                               << 3U)) 
                                    | ((0x3f0U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                                  >> 0x15U)) 
                                       | (0xfU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                                  >> 8U)))));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_cyc = 0U;
    if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state))) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_cyc = 1U;
    } else {
        if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_cyc = 1U;
        }
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_stb = 0U;
    if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state))) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_stb = 1U;
    }
    vlTOPp->system__DOT__top__DOT__interconnect___DOT__wback 
        = ((~ (IData)(vlTOPp->system__DOT__reset)) 
           & ((2U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state)) 
              | ((IData)(vlTOPp->system__DOT__top__DOT__leds_io_wb_ack) 
                 | (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state))));
    vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_31 
        = ((1U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
            ? (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_cyc)
            : (IData)(vlSymsp->TOP__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb.cyc));
    vlTOPp->system__DOT__top__DOT__interconnect___DOT__wbdata 
        = ((2U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state))
            ? vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m_o_wb_data
            : ((IData)(vlTOPp->system__DOT__top__DOT__leds_io_wb_ack)
                ? (((IData)(vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_1) 
                    << 8U) | (IData)(vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_0))
                : ((IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state)
                    ? ((((IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_3_data_out) 
                         << 0x18U) | ((IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_2_data_out) 
                                      << 0x10U)) | 
                       (((IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_1_data_out) 
                         << 8U) | (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_0_data_out)))
                    : 0U)));
    vlTOPp->system__DOT__top__DOT__arbiter_io_output_stb 
        = ((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
            ? (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_stb)
            : ((1U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
                ? (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_stb)
                : (0xeU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))));
    vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_32 
        = ((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
            ? (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_cyc)
            : (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_31));
    vlTOPp->system__DOT__top__DOT__blockram__DOT__state 
        = __Vdly__system__DOT__top__DOT__blockram__DOT__state;
    vlTOPp->system__DOT__top__DOT__arbiter_io_masters_1_ack 
        = ((1U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
           & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wback));
    vlTOPp->system__DOT__top__DOT__blockram__DOT___rams_0_io_we_T 
        = (1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state)));
    if (vlTOPp->system__DOT__reset) {
        vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_1 = 0U;
    } else {
        if (((IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_cyc) 
             & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_stb))) {
            if (vlTOPp->system__DOT__top__DOT__arbiter_io_output_we) {
                if ((2U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel))) {
                    vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_1 
                        = (0xffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data 
                                    >> 8U));
                }
            }
        }
    }
    if (vlTOPp->system__DOT__reset) {
        vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_0 = 0U;
    } else {
        if (((IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_cyc) 
             & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_stb))) {
            if (vlTOPp->system__DOT__top__DOT__arbiter_io_output_we) {
                if ((1U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel))) {
                    vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_0 
                        = (0xffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data);
                }
            }
        }
    }
    vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_3_data_out 
        = vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem
        [(0x1fffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)];
    vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_2_data_out 
        = vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem
        [(0x1fffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)];
    vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_1_data_out 
        = vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem
        [(0x1fffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)];
    vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_0_data_out 
        = vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem
        [(0x1fffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)];
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a 
        = ((0x1fU >= (0x18U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset 
                               << 3U))) ? (vlTOPp->system__DOT__top__DOT__interconnect___DOT__wbdata 
                                           >> (0x18U 
                                               & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset 
                                                  << 3U)))
            : 0U);
    if (vlTOPp->system__DOT__reset) {
        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer = 0U;
    } else {
        if (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT____Vcellinp__uart_ctrlr____pinNumber4) {
            if (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_full) {
                __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer)));
            }
        }
    }
    if ((1U & ((IData)(vlTOPp->system__DOT__reset) 
               | (~ (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_2_cyc))))) {
        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state = 0U;
        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_stb = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state))) {
            if (((IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_2_stb) 
                 & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_2_cyc))) {
                if ((1U & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)) {
                    if (vlTOPp->system__DOT__top__DOT__arbiter_io_output_we) {
                        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_data 
                            = (0xffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data);
                        if ((0U != (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state))) {
                            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state = 1U;
                        } else {
                            vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_stb = 1U;
                            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state = 2U;
                        }
                    } else {
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state = 2U;
                        if ((0U < (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_size))) {
                            vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m_o_wb_data 
                                = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer
                                [vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer];
                            __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer 
                                = (0x1ffU & ((IData)(1U) 
                                             + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer)));
                        } else {
                            vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m_o_wb_data = 0U;
                        }
                    }
                } else {
                    if (vlTOPp->system__DOT__top__DOT__arbiter_io_output_we) {
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state = 2U;
                    } else {
                        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m_o_wb_data 
                            = (((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_overrun) 
                                << 0x1fU) | (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_size));
                        __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state = 2U;
                    }
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state))) {
                if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state))) {
                    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_stb = 1U;
                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state))) {
                    __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state = 0U;
                    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_stb = 0U;
                }
            }
        }
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall = 0U;
    if (((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)) 
         | (0x23U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)))) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall = 1U;
    }
    if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_cyc) 
         & (IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_masters_1_ack))) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall = 0U;
    }
    vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel 
        = ((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
            ? 0xfU : ((1U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
                       ? (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_sel)
                       : (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_sel)));
    if (__Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem__v0) {
        vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem[__Vdlyvdim0__system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem__v0] 
            = __Vdlyvval__system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem__v0;
    }
    if (__Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem__v0) {
        vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem[__Vdlyvdim0__system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem__v0] 
            = __Vdlyvval__system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem__v0;
    }
    if (__Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem__v0) {
        vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem[__Vdlyvdim0__system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem__v0] 
            = __Vdlyvval__system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem__v0;
    }
    if (__Vdlyvset__system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem__v0) {
        vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem[__Vdlyvdim0__system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem__v0] 
            = __Vdlyvval__system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem__v0;
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result = 0U;
    if ((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode))) {
        if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result 
                = ((0xffffff00U & (VL_NEGATE_I((IData)(
                                                       (1U 
                                                        & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a 
                                                           >> 7U)))) 
                                   << 8U)) | (0xffU 
                                              & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a));
        } else {
            if ((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result 
                    = ((0xffff0000U & (VL_NEGATE_I((IData)(
                                                           (1U 
                                                            & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a 
                                                               >> 0xfU)))) 
                                       << 0x10U)) | 
                       (0xffffU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a));
            } else {
                if ((2U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result 
                        = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a;
                } else {
                    if ((4U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result 
                            = (0xffU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a);
                    } else {
                        if ((5U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result 
                                = (0xffffU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a);
                        }
                    }
                }
            }
        }
    }
    if (__Vdlyvset__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer__v0) {
        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer[__Vdlyvdim0__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer__v0] 
            = __Vdlyvval__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer__v0;
    }
    vlTOPp->system__DOT__top__DOT__arbiter_io_output_we 
        = ((2U != (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
           & ((1U != (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
              | (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_we)));
    vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data 
        = ((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
            ? 0U : ((1U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
                     ? vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_mosi_data
                     : vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_mosi_data));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer 
        = __Vdly__system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer;
    vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
        = ((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
            ? (0x3fffffffU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc 
                              >> 2U)) : ((1U == (3U 
                                                 & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster)))
                                          ? vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_addr
                                          : vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_addr));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 0U;
    if ((0x33U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
        if ((0x13U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
            if ((0x63U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                if (((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                     & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                        == vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                } else {
                    if (((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                         & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                            != vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                    } else {
                        if (((4U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                             & VL_LTS_III(1,32,32, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val))) {
                            vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                        } else {
                            if (((5U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                                 & VL_GTES_III(1,32,32, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val, vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val))) {
                                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                            } else {
                                if (((6U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                                     & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                        < vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val))) {
                                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                                } else {
                                    if (((7U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3)) 
                                         & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val 
                                            >= vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val))) {
                                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if ((0x6fU == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                } else {
                    if ((0x67U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))) {
                        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 1U;
                    }
                }
            }
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = 0U;
    }
    vlTOPp->io_leds = (((IData)(vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_1) 
                        << 8U) | (IData)(vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_0));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_mem_result 
        = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_result;
    if (((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)) 
         | (0x23U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode)))) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_mem_result 
            = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result;
    }
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_data 
        = ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode)
            ? (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_data)
            : (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m_o_tx 
        = ((2U != (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state)) 
           & (((0U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state)) 
               | (0xbU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state))) 
              | ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__data) 
                 >> (7U & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state) 
                           - (IData)(3U))))));
    if (vlTOPp->system__DOT__reset) {
        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_overrun = 0U;
    } else {
        if (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT____Vcellinp__uart_ctrlr____pinNumber4) {
            if (vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_full) {
                vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_overrun = 1U;
            }
        }
    }
    if ((0U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_size))) {
        vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_overrun = 0U;
    }
    vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_2_cyc 
        = ((IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_32) 
           & (0x1e000200U == (0x1fffffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                             >> 1U))));
    vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_2_stb 
        = ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_stb) 
           & (0x1e000200U == (0x1fffffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                             >> 1U))));
    vlTOPp->system__DOT__top__DOT__interconnect___DOT___io_master_stall_T 
        = ((((0x1e000200U == (0x1fffffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                             >> 1U))) 
             & (0U != (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state))) 
            << 2U) | ((0U == (0x1ffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                          >> 0xdU))) 
                      & (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state)));
    vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_cyc 
        = ((IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_32) 
           & (0x3c000000U == (0x3fffffffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)));
    vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_stb 
        = ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_stb) 
           & (0x3c000000U == (0x3fffffffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)));
    vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc 
        = ((IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_32) 
           & (0U == (0x1ffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                 >> 0xdU))));
    vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb 
        = ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_stb) 
           & (0U == (0x1ffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                 >> 0xdU))));
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs1_val 
        = ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number))
            ? 0U : (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number) 
                     == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__dest_addr))
                     ? vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__data
                     : vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                    [vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number]));
    if ((0U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number))) {
        if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number) 
             == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number))) {
            if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs1_val 
                    = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result;
            }
        } else {
            if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number) 
                 == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rd_number))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs1_val 
                    = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_mem_result;
            }
        }
    }
    if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc) {
        vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall = 0U;
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall = 0U;
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs2_val 
        = ((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number))
            ? 0U : (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number) 
                     == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__dest_addr))
                     ? vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__data
                     : vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                    [vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number]));
    if ((0U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number))) {
        if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number) 
             == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number))) {
            if ((1U & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid)))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall = 1U;
            }
        }
    }
    if (((0U != (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number)) 
         & (~ (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall)))) {
        if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number) 
             == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number))) {
            if (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs2_val 
                    = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result;
            } else {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall = 1U;
            }
        } else {
            if (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number) 
                 == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rd_number))) {
                vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs2_val 
                    = vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_mem_result;
            }
        }
    }
    vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall 
        = ((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall) 
           | (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall));
    vlTOPp->io_tx = vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m_o_tx;
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_full 
        = ((0x1ffU & ((IData)(1U) + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer))) 
           == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_size 
        = (0x1ffU & ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer) 
                     - (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer)));
    vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT____Vcellinp__uart_ctrlr____pinNumber4 
        = ((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_stb) 
           & (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode));
    vlTOPp->system__DOT__top__DOT__leds_io_wb_ack = 
        ((IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_cyc) 
         & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_stb));
    vlTOPp->system__DOT__top__DOT__blockram__DOT___GEN_0 
        = (((IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb) 
            & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc)) 
           | (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state));
    vlTOPp->system__DOT__reset = vlTOPp->system__DOT__reset_int;
    vlTOPp->system__DOT__reset_int = (1U & (~ (IData)(vlTOPp->i_reset)));
}

VL_INLINE_OPT void Vsystem::_combo__TOP__4(Vsystem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystem::_combo__TOP__4\n"); );
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset 
        = ((IData)(vlTOPp->system__DOT__reset) | (IData)(vlTOPp->proc_reset));
}

void Vsystem::_eval(Vsystem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystem::_eval\n"); );
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vsystem::_eval_initial(Vsystem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystem::_eval_initial\n"); );
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vsystem::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystem::final\n"); );
    // Variables
    Vsystem__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsystem::_eval_settle(Vsystem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystem::_eval_settle\n"); );
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vsystem::_change_request(Vsystem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystem::_change_request\n"); );
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vsystem::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystem::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((i_reset & 0xfeU))) {
        Verilated::overWidthError("i_reset");}
    if (VL_UNLIKELY((io_rx & 0xfeU))) {
        Verilated::overWidthError("io_rx");}
    if (VL_UNLIKELY((proc_reset & 0xfeU))) {
        Verilated::overWidthError("proc_reset");}
}
#endif  // VL_DEBUG

void Vsystem::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystem::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    i_reset = VL_RAND_RESET_I(1);
    io_leds = VL_RAND_RESET_I(16);
    io_rx = VL_RAND_RESET_I(1);
    io_tx = VL_RAND_RESET_I(1);
    io_sdram_addr = VL_RAND_RESET_I(12);
    io_sdram_bank = VL_RAND_RESET_I(2);
    io_sdram_data = VL_RAND_RESET_I(16);
    io_sdram_dqm = VL_RAND_RESET_I(2);
    io_sdram_clk = VL_RAND_RESET_I(1);
    io_sdram_cke = VL_RAND_RESET_I(1);
    io_sdram_cs_n = VL_RAND_RESET_I(1);
    io_sdram_ras_n = VL_RAND_RESET_I(1);
    io_sdram_cas_n = VL_RAND_RESET_I(1);
    io_sdram_we_n = VL_RAND_RESET_I(1);
    proc_reset = VL_RAND_RESET_I(1);
    system__DOT__reset = VL_RAND_RESET_I(1);
    system__DOT__reset_int = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__leds_io_wb_ack = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__arbiter_io_masters_1_ack = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__arbiter_io_output_stb = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__arbiter_io_output_we = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__arbiter_io_output_addr = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__arbiter_io_output_mosi_data = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__arbiter_io_output_sel = VL_RAND_RESET_I(4);
    system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__interconnect___05Fio_devices_0_stb = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__interconnect___05Fio_devices_1_cyc = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__interconnect___05Fio_devices_1_stb = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__interconnect___05Fio_devices_2_cyc = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__interconnect___05Fio_devices_2_stb = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__proc__DOT__top_reset = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__proc__DOT__top_wb2_cyc = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__proc__DOT__top_wb2_stb = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__proc__DOT__top_wb_cyc = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__proc__DOT__top_wb_stb = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__proc__DOT__top_wb_we = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__proc__DOT__top_wb_sel = VL_RAND_RESET_I(4);
    system__DOT__top__DOT__proc__DOT__top_wb_addr = VL_RAND_RESET_I(30);
    system__DOT__top__DOT__proc__DOT__top_wb_mosi_data = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__if_id_pc = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_pc = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number = VL_RAND_RESET_I(5);
    system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number = VL_RAND_RESET_I(5);
    system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_rd_number = VL_RAND_RESET_I(5);
    system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func7 = VL_RAND_RESET_I(7);
    system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_opcode = VL_RAND_RESET_I(7);
    system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func3 = VL_RAND_RESET_I(3);
    system__DOT__top__DOT__proc__DOT__top__DOT__dest_addr = VL_RAND_RESET_I(5);
    system__DOT__top__DOT__proc__DOT__top__DOT__data = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__proc__DOT__top__DOT__new_pc = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number = VL_RAND_RESET_I(5);
    system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7 = VL_RAND_RESET_I(7);
    system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode = VL_RAND_RESET_I(7);
    system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3 = VL_RAND_RESET_I(3);
    system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_result = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_pc = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs1_val = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs2_val = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_immediate = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rd_number = VL_RAND_RESET_I(5);
    system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode = VL_RAND_RESET_I(7);
    system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3 = VL_RAND_RESET_I(3);
    system__DOT__top__DOT__proc__DOT__top__DOT__mem_rd = VL_RAND_RESET_I(5);
    system__DOT__top__DOT__proc__DOT__top__DOT__df_mem_result = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[__Vi0] = VL_RAND_RESET_I(32);
    }}
    system__DOT__top__DOT__proc__DOT__top__DOT__id__DOT__branch_offset = VL_RAND_RESET_I(12);
    system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs1_val = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs2_val = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state = VL_RAND_RESET_I(4);
    system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__leds__DOT__ledBuf_0 = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__leds__DOT__ledBuf_1 = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__ihexUart__DOT__m_o_tx = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m_o_wb_err = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m_o_wb_data = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_stb = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_data = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_stb = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_data = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT____Vcellinp__uart_ctrlr____pinNumber4 = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_db = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_int = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_prev = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__sample = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state = VL_RAND_RESET_I(4);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state = VL_RAND_RESET_I(4);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__data = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer[__Vi0] = VL_RAND_RESET_I(8);
    }}
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr = VL_RAND_RESET_I(16);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__filled_high = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmp_sum = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset = VL_RAND_RESET_I(16);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum_tcmp = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr = VL_RAND_RESET_I(16);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_sel = VL_RAND_RESET_I(4);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_addr = VL_RAND_RESET_I(30);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_mosi_data = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<512; ++__Vi0) {
            system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_buffer[__Vi0] = VL_RAND_RESET_I(8);
    }}
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer = VL_RAND_RESET_I(9);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer = VL_RAND_RESET_I(9);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_overrun = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_size = VL_RAND_RESET_I(9);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_next_write = VL_RAND_RESET_I(9);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_full = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state = VL_RAND_RESET_I(4);
    system__DOT__top__DOT__blockram__DOT__rams_0_data_out = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__blockram__DOT__rams_1_data_out = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__blockram__DOT__rams_2_data_out = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__blockram__DOT__rams_3_data_out = VL_RAND_RESET_I(8);
    system__DOT__top__DOT__blockram__DOT__state = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__blockram__DOT___rams_0_io_we_T = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__blockram__DOT___GEN_0 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<8192; ++__Vi0) {
            system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8192; ++__Vi0) {
            system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8192; ++__Vi0) {
            system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8192; ++__Vi0) {
            system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    system__DOT__top__DOT__arbiter__DOT__currentMaster = VL_RAND_RESET_I(4);
    system__DOT__top__DOT__arbiter__DOT___GEN_31 = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__arbiter__DOT___GEN_32 = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__interconnect___DOT__wback = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__interconnect___DOT__wbdata = VL_RAND_RESET_I(32);
    system__DOT__top__DOT__interconnect___DOT__wberr = VL_RAND_RESET_I(1);
    system__DOT__top__DOT__interconnect___DOT___io_master_stall_T = VL_RAND_RESET_I(3);
    __Vm_traceActivity = 0;
}
