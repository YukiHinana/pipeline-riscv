// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsystem__Syms.h"


//======================

void Vsystem::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vsystem* t = (Vsystem*)userthis;
    Vsystem__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vsystem::traceChgThis(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vsystem::traceChgThis__2(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_cyc));
        vcdp->chgBit(c+9,(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_stb));
        vcdp->chgBit(c+17,(((2U != (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                            | (0U != (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT___io_master_stall_T)))));
        vcdp->chgBit(c+25,(vlTOPp->system__DOT__top__DOT__arbiter_io_masters_1_ack));
        vcdp->chgBit(c+33,(((1U != (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                            | (0U != (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT___io_master_stall_T)))));
        vcdp->chgBit(c+41,(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_cyc));
        vcdp->chgBit(c+49,(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_1_stb));
        vcdp->chgBit(c+57,(vlTOPp->system__DOT__top__DOT__arbiter_io_output_we));
        vcdp->chgBus(c+65,(vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data),32);
        vcdp->chgBus(c+73,(vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel),4);
        vcdp->chgBit(c+81,(vlTOPp->system__DOT__top__DOT__leds_io_wb_ack));
        vcdp->chgBit(c+89,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m_o_tx));
        vcdp->chgBit(c+97,(vlSymsp->TOP__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb.cyc));
        vcdp->chgBit(c+105,((0xeU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))));
        vcdp->chgBit(c+113,(((0U != (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                             | (0U != (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT___io_master_stall_T)))));
        vcdp->chgBit(c+121,(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_2_cyc));
        vcdp->chgBit(c+129,(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_2_stb));
        vcdp->chgBus(c+137,((1U & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)),32);
        vcdp->chgBit(c+145,((2U == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state))));
        vcdp->chgBit(c+153,((0U != (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state))));
        vcdp->chgBit(c+161,(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc));
        vcdp->chgBit(c+169,(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb));
        vcdp->chgBus(c+177,((0x1fffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)),32);
        vcdp->chgBit(c+185,(vlTOPp->system__DOT__top__DOT__arbiter__DOT___GEN_32));
        vcdp->chgBit(c+193,(vlTOPp->system__DOT__top__DOT__arbiter_io_output_stb));
        vcdp->chgBus(c+201,(vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr),32);
        vcdp->chgBit(c+209,((0U != (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT___io_master_stall_T))));
        vcdp->chgBit(c+217,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_pipeline_stall));
        vcdp->chgBit(c+225,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem_pipeline_stall));
        vcdp->chgBit(c+233,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__load_new_pc));
        vcdp->chgBus(c+241,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__new_pc),32);
        vcdp->chgBus(c+249,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_mem_result),32);
        vcdp->chgBus(c+257,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_result),32);
        vcdp->chgBit(c+265,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__df_ex_valid));
        vcdp->chgBus(c+273,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id__DOT__branch_offset),12);
        vcdp->chgBus(c+281,(((0xffffe000U & (VL_NEGATE_I((IData)(
                                                                 (1U 
                                                                  & ((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id__DOT__branch_offset) 
                                                                     >> 0xbU)))) 
                                             << 0xdU)) 
                             | ((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id__DOT__branch_offset) 
                                << 1U))),32);
        vcdp->chgBit(c+289,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__pipeline_stall));
        vcdp->chgBus(c+297,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs1_val),32);
        vcdp->chgBus(c+305,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr__DOT__rs2_val),32);
        vcdp->chgBus(c+313,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex__DOT__sign_extended),32);
        vcdp->chgBus(c+321,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset),32);
        vcdp->chgBus(c+329,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__load_result),32);
        vcdp->chgBus(c+337,((3U & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__rs1_and_offset)),6);
        vcdp->chgBus(c+345,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__a),32);
        vcdp->chgBus(c+353,((1U & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)),30);
        vcdp->chgBit(c+361,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode));
        vcdp->chgBus(c+369,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_data),8);
        vcdp->chgBit(c+377,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_stb));
        vcdp->chgBus(c+385,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_data),8);
        vcdp->chgBit(c+393,(((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode)
                              ? (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_stb)
                              : (0xdU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state)))));
        vcdp->chgBit(c+401,((0U != (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state))));
        vcdp->chgBit(c+409,(((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode)
                              ? 1U : (1U & (IData)(vlTOPp->system__DOT__reset)))));
        vcdp->chgBit(c+417,((0xdU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state))));
        vcdp->chgBit(c+425,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_stb));
        vcdp->chgBit(c+433,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_db));
        vcdp->chgBit(c+441,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_int));
        vcdp->chgBit(c+449,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__i_rx_prev));
        vcdp->chgBus(c+457,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter),32);
        vcdp->chgBit(c+465,(VL_LTES_III(1,32,32, 0x1b1U, vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__clk_counter)));
        vcdp->chgBus(c+473,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_part__DOT__internal_state),4);
        vcdp->chgBus(c+481,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__counter),32);
        vcdp->chgBus(c+489,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__state),4);
        vcdp->chgBit(c+497,(((IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__rx_stb) 
                             & (~ (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__slave_mode)))));
        vcdp->chgBus(c+505,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state),4);
        vcdp->chgBus(c+513,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr_offset),16);
        vcdp->chgBus(c+521,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__write_addr),16);
        vcdp->chgBit(c+529,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT____Vcellinp__uart_ctrlr____pinNumber4));
        vcdp->chgBus(c+537,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_read_pointer),9);
        vcdp->chgBus(c+545,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer),9);
        vcdp->chgBit(c+553,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_overrun));
        vcdp->chgBus(c+561,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_size),9);
        vcdp->chgBus(c+569,((0x1ffU & ((IData)(1U) 
                                       + (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_write_pointer)))),9);
        vcdp->chgBit(c+577,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__rx_full));
        vcdp->chgBus(c+585,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state),4);
        vcdp->chgBus(c+593,((0x1fffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr)),13);
        vcdp->chgBit(c+601,((((((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_we) 
                                & (~ (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state))) 
                               & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb)) 
                              & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc)) 
                             & (IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel))));
        vcdp->chgBus(c+609,((0xffU & vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data)),8);
        vcdp->chgBit(c+617,((((((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_we) 
                                & (~ (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state))) 
                               & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb)) 
                              & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc)) 
                             & ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel) 
                                >> 1U))));
        vcdp->chgBus(c+625,((0xffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data 
                                      >> 8U))),8);
        vcdp->chgBit(c+633,((((((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_we) 
                                & (~ (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state))) 
                               & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb)) 
                              & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc)) 
                             & ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel) 
                                >> 2U))));
        vcdp->chgBus(c+641,((0xffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data 
                                      >> 0x10U))),8);
        vcdp->chgBit(c+649,((((((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_we) 
                                & (~ (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state))) 
                               & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_stb)) 
                              & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___05Fio_devices_0_cyc)) 
                             & ((IData)(vlTOPp->system__DOT__top__DOT__arbiter_io_output_sel) 
                                >> 3U))));
        vcdp->chgBus(c+657,((0xffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_mosi_data 
                                      >> 0x18U))),8);
        vcdp->chgBus(c+665,((((IData)(vlSymsp->TOP__system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_wb.cyc) 
                              & (0xeU == (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__state)))
                              ? 0U : (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_cyc) 
                                       & (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_stb))
                                       ? 1U : (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_cyc) 
                                                & (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb2_stb))
                                                ? 2U
                                                : 0U)))),4);
        vcdp->chgBit(c+673,((0U == (0x1ffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                                >> 0xdU)))));
        vcdp->chgBit(c+681,((0x3c000000U == (0x3fffffffU 
                                             & vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr))));
        vcdp->chgBit(c+689,((0x1e000200U == (0x1fffffffU 
                                             & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                                >> 1U)))));
        vcdp->chgBit(c+697,(((0U == (0x1ffffU & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                                 >> 0xdU))) 
                             & (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__state))));
        vcdp->chgBit(c+705,(((0x1e000200U == (0x1fffffffU 
                                              & (vlTOPp->system__DOT__top__DOT__arbiter_io_output_addr 
                                                 >> 1U))) 
                             & (0U != (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_ctrlr__DOT__wb_state)))));
    }
}

void Vsystem::traceChgThis__3(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+713,(vlTOPp->system__DOT__top__DOT__proc__DOT__top_reset));
    }
}

void Vsystem::traceChgThis__4(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+721,(vlTOPp->system__DOT__reset));
        vcdp->chgBit(c+729,(vlTOPp->system__DOT__reset_int));
        vcdp->chgBus(c+737,((0x3fffffffU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc 
                                            >> 2U))),32);
        vcdp->chgBus(c+745,(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wbdata),32);
        vcdp->chgBit(c+753,(((2U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                             & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wback))));
        vcdp->chgBit(c+761,(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_cyc));
        vcdp->chgBit(c+769,(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_stb));
        vcdp->chgBit(c+777,(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_we));
        vcdp->chgBus(c+785,(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_addr),32);
        vcdp->chgBus(c+793,(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_mosi_data),32);
        vcdp->chgBus(c+801,(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_sel),4);
        vcdp->chgBus(c+809,((((IData)(vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_1) 
                              << 8U) | (IData)(vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_0))),16);
        vcdp->chgBus(c+817,((((IData)(vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_1) 
                              << 8U) | (IData)(vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_0))),32);
        vcdp->chgBus(c+825,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_addr),32);
        vcdp->chgBus(c+833,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_mosi_data),32);
        vcdp->chgBus(c+841,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_sel),4);
        vcdp->chgBit(c+849,(((0U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                             & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wback))));
        vcdp->chgBit(c+857,(((0U == (3U & (IData)(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster))) 
                             & (IData)(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wberr))));
        vcdp->chgBus(c+865,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m_o_wb_data),32);
        vcdp->chgBus(c+873,(((((IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_3_data_out) 
                               << 0x18U) | ((IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_2_data_out) 
                                            << 0x10U)) 
                             | (((IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_1_data_out) 
                                 << 8U) | (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_0_data_out)))),32);
        vcdp->chgBit(c+881,(vlTOPp->system__DOT__top__DOT__blockram__DOT__state));
        vcdp->chgBit(c+889,(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wback));
        vcdp->chgBit(c+897,(vlTOPp->system__DOT__top__DOT__interconnect___DOT__wberr));
        vcdp->chgBus(c+905,((0x3fffffffU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc 
                                            >> 2U))),30);
        vcdp->chgBus(c+913,(vlTOPp->system__DOT__top__DOT__proc__DOT__top_wb_addr),30);
        vcdp->chgBus(c+921,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_pc),32);
        vcdp->chgBus(c+929,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction),32);
        vcdp->chgBus(c+937,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_pc),32);
        vcdp->chgBus(c+945,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_immediate),32);
        vcdp->chgBus(c+953,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number),5);
        vcdp->chgBus(c+961,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number),5);
        vcdp->chgBus(c+969,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_rd_number),5);
        vcdp->chgBus(c+977,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func7),7);
        vcdp->chgBus(c+985,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_opcode),7);
        vcdp->chgBus(c+993,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_func3),3);
        vcdp->chgBus(c+1001,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__dest_addr),5);
        vcdp->chgBus(c+1009,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__data),32);
        vcdp->chgBus(c+1017,(((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number))
                               ? 0U : (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number) 
                                        == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__dest_addr))
                                        ? vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__data
                                        : vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                                       [vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr1_number]))),32);
        vcdp->chgBus(c+1025,(((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number))
                               ? 0U : (((IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number) 
                                        == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__dest_addr))
                                        ? vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__data
                                        : vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                                       [vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__id_rr_sr2_number]))),32);
        vcdp->chgBus(c+1033,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_pc),32);
        vcdp->chgBus(c+1041,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs1_val),32);
        vcdp->chgBus(c+1049,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rs2_val),32);
        vcdp->chgBus(c+1057,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_immediate),32);
        vcdp->chgBus(c+1065,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_rd_number),5);
        vcdp->chgBus(c+1073,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func7),7);
        vcdp->chgBus(c+1081,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode),7);
        vcdp->chgBus(c+1089,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_func3),3);
        vcdp->chgBus(c+1097,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_result),32);
        vcdp->chgBus(c+1105,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_pc),32);
        vcdp->chgBus(c+1113,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs1_val),32);
        vcdp->chgBus(c+1121,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rs2_val),32);
        vcdp->chgBus(c+1129,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_immediate),32);
        vcdp->chgBus(c+1137,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_rd_number),5);
        vcdp->chgBus(c+1145,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode),7);
        vcdp->chgBus(c+1153,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3),3);
        vcdp->chgBus(c+1161,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__pc),32);
        vcdp->chgBus(c+1169,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__fetch__DOT__state),4);
        vcdp->chgBus(c+1177,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[0]),32);
        vcdp->chgBus(c+1178,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[1]),32);
        vcdp->chgBus(c+1179,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[2]),32);
        vcdp->chgBus(c+1180,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[3]),32);
        vcdp->chgBus(c+1181,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[4]),32);
        vcdp->chgBus(c+1182,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[5]),32);
        vcdp->chgBus(c+1183,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[6]),32);
        vcdp->chgBus(c+1184,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[7]),32);
        vcdp->chgBus(c+1185,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[8]),32);
        vcdp->chgBus(c+1186,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[9]),32);
        vcdp->chgBus(c+1187,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[10]),32);
        vcdp->chgBus(c+1188,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[11]),32);
        vcdp->chgBus(c+1189,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[12]),32);
        vcdp->chgBus(c+1190,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[13]),32);
        vcdp->chgBus(c+1191,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[14]),32);
        vcdp->chgBus(c+1192,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[15]),32);
        vcdp->chgBus(c+1193,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[16]),32);
        vcdp->chgBus(c+1194,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[17]),32);
        vcdp->chgBus(c+1195,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[18]),32);
        vcdp->chgBus(c+1196,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[19]),32);
        vcdp->chgBus(c+1197,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[20]),32);
        vcdp->chgBus(c+1198,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[21]),32);
        vcdp->chgBus(c+1199,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[22]),32);
        vcdp->chgBus(c+1200,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[23]),32);
        vcdp->chgBus(c+1201,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[24]),32);
        vcdp->chgBus(c+1202,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[25]),32);
        vcdp->chgBus(c+1203,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[26]),32);
        vcdp->chgBus(c+1204,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[27]),32);
        vcdp->chgBus(c+1205,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[28]),32);
        vcdp->chgBus(c+1206,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[29]),32);
        vcdp->chgBus(c+1207,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[30]),32);
        vcdp->chgBus(c+1208,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file[31]),32);
        vcdp->chgBus(c+1433,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                             [0U]),32);
        vcdp->chgBus(c+1441,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                             [1U]),32);
        vcdp->chgBus(c+1449,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                             [2U]),32);
        vcdp->chgBus(c+1457,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                             [3U]),32);
        vcdp->chgBus(c+1465,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                             [4U]),32);
        vcdp->chgBus(c+1473,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                             [0xaU]),32);
        vcdp->chgBus(c+1481,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__reg_file__DOT__reg_file
                             [0xbU]),32);
        vcdp->chgBus(c+1489,((0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction)),7);
        vcdp->chgBus(c+1497,((0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                       >> 0xfU))),5);
        vcdp->chgBus(c+1505,((0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                       >> 0x14U))),5);
        vcdp->chgBus(c+1513,((0x1fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                       >> 7U))),5);
        vcdp->chgBus(c+1521,((7U & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                    >> 0xcU))),3);
        vcdp->chgBus(c+1529,((0x7fU & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction 
                                       >> 0x19U))),7);
        vcdp->chgBit(c+1537,((0x33U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))));
        vcdp->chgBit(c+1545,((0x13U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))));
        vcdp->chgBit(c+1553,((3U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))));
        vcdp->chgBit(c+1561,((0x23U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))));
        vcdp->chgBit(c+1569,((0x63U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))));
        vcdp->chgBit(c+1577,((0x6fU == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))));
        vcdp->chgBit(c+1585,((0x67U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))));
        vcdp->chgBit(c+1593,((0x17U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))));
        vcdp->chgBit(c+1601,((0x37U == (0x7fU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__if_id_instruction))));
        vcdp->chgBit(c+1609,((0x33U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+1617,((0x13U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+1625,((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+1633,((0x23U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+1641,((0x63U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+1649,((0x6fU == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+1657,((0x67U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+1665,((0x17U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+1673,((0x37U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__rr_ex_opcode))));
        vcdp->chgBus(c+1681,(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__mem__DOT__state),4);
        vcdp->chgBus(c+1689,(((0xfffff000U & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_immediate 
                                                                      >> 0xbU)))) 
                                              << 0xcU)) 
                              | (0xfffU & vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_immediate))),32);
        vcdp->chgBit(c+1697,((0U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))));
        vcdp->chgBit(c+1705,((1U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))));
        vcdp->chgBit(c+1713,((2U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))));
        vcdp->chgBit(c+1721,((4U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))));
        vcdp->chgBit(c+1729,((5U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_func3))));
        vcdp->chgBit(c+1737,((3U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode))));
        vcdp->chgBit(c+1745,((0x23U == (IData)(vlTOPp->system__DOT__top__DOT__proc__DOT__top__DOT__ex_mem_opcode))));
        vcdp->chgBus(c+1753,(vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_0),8);
        vcdp->chgBus(c+1761,(vlTOPp->system__DOT__top__DOT__leds__DOT__ledBuf_1),8);
        vcdp->chgBus(c+1769,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__wb_addr),30);
        vcdp->chgBus(c+1777,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__ihex_tx_data),8);
        vcdp->chgBus(c+1785,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__uart_tx_data),8);
        vcdp->chgBus(c+1793,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__tx_part__DOT__data),8);
        vcdp->chgBus(c+1801,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum),8);
        vcdp->chgBus(c+1809,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmd),8);
        vcdp->chgBus(c+1817,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__len),8);
        vcdp->chgBus(c+1825,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__addr),16);
        vcdp->chgBus(c+1833,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__buffer_fill),8);
        vcdp->chgBit(c+1841,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__filled_high));
        vcdp->chgBus(c+1849,(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__cmp_sum),8);
        vcdp->chgBus(c+1857,((0xffU & ((IData)(1U) 
                                       + (~ (IData)(vlTOPp->system__DOT__top__DOT__ihexUart__DOT__m__DOT__intel_hex_controller__DOT__computed_sum))))),8);
        vcdp->chgBus(c+1865,(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_0_data_out),8);
        vcdp->chgBus(c+1873,(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_1_data_out),8);
        vcdp->chgBus(c+1881,(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_2_data_out),8);
        vcdp->chgBus(c+1889,(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_3_data_out),8);
        vcdp->chgBus(c+1897,((((IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_1_data_out) 
                               << 8U) | (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_0_data_out))),16);
        vcdp->chgBus(c+1905,((((IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_3_data_out) 
                               << 8U) | (IData)(vlTOPp->system__DOT__top__DOT__blockram__DOT__rams_2_data_out))),16);
        vcdp->chgBus(c+1913,(vlTOPp->system__DOT__top__DOT__arbiter__DOT__currentMaster),4);
    }
}

void Vsystem::traceChgThis__5(Vsystem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vsystem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1921,(vlTOPp->clock));
        vcdp->chgBit(c+1929,(vlTOPp->i_reset));
        vcdp->chgBus(c+1937,(vlTOPp->io_leds),16);
        vcdp->chgBit(c+1945,(vlTOPp->io_rx));
        vcdp->chgBit(c+1953,(vlTOPp->io_tx));
        vcdp->chgBus(c+1961,(vlTOPp->io_sdram_addr),12);
        vcdp->chgBus(c+1969,(vlTOPp->io_sdram_bank),2);
        vcdp->chgBus(c+1977,(vlTOPp->io_sdram_data),16);
        vcdp->chgBus(c+1985,(vlTOPp->io_sdram_dqm),2);
        vcdp->chgBit(c+1993,(vlTOPp->io_sdram_clk));
        vcdp->chgBit(c+2001,(vlTOPp->io_sdram_cke));
        vcdp->chgBit(c+2009,(vlTOPp->io_sdram_cs_n));
        vcdp->chgBit(c+2017,(vlTOPp->io_sdram_ras_n));
        vcdp->chgBit(c+2025,(vlTOPp->io_sdram_cas_n));
        vcdp->chgBit(c+2033,(vlTOPp->io_sdram_we_n));
        vcdp->chgBit(c+2041,(vlTOPp->proc_reset));
    }
}
