// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->top__DOT__rr_pipeline_stall));
        vcdp->chgBit(c+9,(vlTOPp->top__DOT__mem_pipeline_stall));
        vcdp->chgBit(c+17,(vlTOPp->top__DOT__load_new_pc));
        vcdp->chgBus(c+25,(vlTOPp->top__DOT__new_pc),32);
        vcdp->chgBit(c+33,(vlTOPp->top__DOT__wb2_cyc));
        vcdp->chgBit(c+41,(vlTOPp->top__DOT__wb2_stb));
        vcdp->chgBit(c+49,(vlTOPp->top__DOT__wb2_ack));
        vcdp->chgBus(c+57,(vlTOPp->top__DOT__wb2_miso_data),32);
        vcdp->chgBus(c+65,(vlTOPp->top__DOT__df_mem_result),32);
        vcdp->chgBus(c+73,(vlTOPp->top__DOT__df_ex_result),32);
        vcdp->chgBit(c+81,(vlTOPp->top__DOT__df_ex_valid));
        vcdp->chgBit(c+89,(vlTOPp->top__DOT__wb_ack));
        vcdp->chgBus(c+97,(vlTOPp->top__DOT__wb_miso_data),32);
        vcdp->chgBus(c+105,(vlTOPp->top__DOT__id__DOT__branch_offset),12);
        vcdp->chgBus(c+113,(((0xffffe000U & (VL_NEGATE_I((IData)(
                                                                 (1U 
                                                                  & ((IData)(vlTOPp->top__DOT__id__DOT__branch_offset) 
                                                                     >> 0xbU)))) 
                                             << 0xdU)) 
                             | ((IData)(vlTOPp->top__DOT__id__DOT__branch_offset) 
                                << 1U))),32);
        vcdp->chgBit(c+121,(vlTOPp->top__DOT__rr__DOT__pipeline_stall));
        vcdp->chgBus(c+129,(vlTOPp->top__DOT__rr__DOT__rs1_val),32);
        vcdp->chgBus(c+137,(vlTOPp->top__DOT__rr__DOT__rs2_val),32);
        vcdp->chgBus(c+145,(vlTOPp->top__DOT__ex__DOT__sign_extended),32);
        vcdp->chgBus(c+153,(vlTOPp->top__DOT__mem__DOT__rs1_and_offset),32);
        vcdp->chgBus(c+161,(vlTOPp->top__DOT__mem__DOT__load_result),32);
        vcdp->chgBit(c+169,(vlTOPp->top__DOT__my_mem__DOT__w_wstb));
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+177,(vlTOPp->top__DOT__if_id_pc),32);
        vcdp->chgBus(c+185,(vlTOPp->top__DOT__if_id_instruction),32);
        vcdp->chgBus(c+193,(vlTOPp->top__DOT__id_rr_pc),32);
        vcdp->chgBus(c+201,(vlTOPp->top__DOT__id_rr_immediate),32);
        vcdp->chgBus(c+209,(vlTOPp->top__DOT__id_rr_sr1_number),5);
        vcdp->chgBus(c+217,(vlTOPp->top__DOT__id_rr_sr2_number),5);
        vcdp->chgBus(c+225,(vlTOPp->top__DOT__id_rr_rd_number),5);
        vcdp->chgBus(c+233,(vlTOPp->top__DOT__id_rr_func7),7);
        vcdp->chgBus(c+241,(vlTOPp->top__DOT__id_rr_opcode),7);
        vcdp->chgBus(c+249,(vlTOPp->top__DOT__id_rr_func3),3);
        vcdp->chgBus(c+257,(vlTOPp->top__DOT__dest_addr),5);
        vcdp->chgBus(c+265,(vlTOPp->top__DOT__data),32);
        vcdp->chgBus(c+273,(((0U == (IData)(vlTOPp->top__DOT__id_rr_sr1_number))
                              ? 0U : (((IData)(vlTOPp->top__DOT__id_rr_sr1_number) 
                                       == (IData)(vlTOPp->top__DOT__dest_addr))
                                       ? vlTOPp->top__DOT__data
                                       : vlTOPp->top__DOT__reg_file__DOT__reg_file
                                      [vlTOPp->top__DOT__id_rr_sr1_number]))),32);
        vcdp->chgBus(c+281,(((0U == (IData)(vlTOPp->top__DOT__id_rr_sr2_number))
                              ? 0U : (((IData)(vlTOPp->top__DOT__id_rr_sr2_number) 
                                       == (IData)(vlTOPp->top__DOT__dest_addr))
                                       ? vlTOPp->top__DOT__data
                                       : vlTOPp->top__DOT__reg_file__DOT__reg_file
                                      [vlTOPp->top__DOT__id_rr_sr2_number]))),32);
        vcdp->chgBus(c+289,((0x3fffffffU & (vlTOPp->top__DOT__fetch__DOT__pc 
                                            >> 2U))),30);
        vcdp->chgBus(c+297,(vlTOPp->top__DOT__rr_ex_pc),32);
        vcdp->chgBus(c+305,(vlTOPp->top__DOT__rr_ex_rs1_val),32);
        vcdp->chgBus(c+313,(vlTOPp->top__DOT__rr_ex_rs2_val),32);
        vcdp->chgBus(c+321,(vlTOPp->top__DOT__rr_ex_immediate),32);
        vcdp->chgBus(c+329,(vlTOPp->top__DOT__rr_ex_rd_number),5);
        vcdp->chgBus(c+337,(vlTOPp->top__DOT__rr_ex_func7),7);
        vcdp->chgBus(c+345,(vlTOPp->top__DOT__rr_ex_opcode),7);
        vcdp->chgBus(c+353,(vlTOPp->top__DOT__rr_ex_func3),3);
        vcdp->chgBus(c+361,(vlTOPp->top__DOT__ex_mem_result),32);
        vcdp->chgBus(c+369,(vlTOPp->top__DOT__ex_mem_pc),32);
        vcdp->chgBus(c+377,(vlTOPp->top__DOT__ex_mem_rs1_val),32);
        vcdp->chgBus(c+385,(vlTOPp->top__DOT__ex_mem_rs2_val),32);
        vcdp->chgBus(c+393,(vlTOPp->top__DOT__ex_mem_immediate),32);
        vcdp->chgBus(c+401,(vlTOPp->top__DOT__ex_mem_rd_number),5);
        vcdp->chgBus(c+409,(vlTOPp->top__DOT__ex_mem_opcode),7);
        vcdp->chgBus(c+417,(vlTOPp->top__DOT__ex_mem_func3),3);
        vcdp->chgBit(c+425,(vlTOPp->top__DOT__wb_cyc));
        vcdp->chgBit(c+433,(vlTOPp->top__DOT__wb_stb));
        vcdp->chgBit(c+441,(vlTOPp->top__DOT__wb_we));
        vcdp->chgBus(c+449,(vlTOPp->top__DOT__wb_sel),4);
        vcdp->chgBus(c+457,(vlTOPp->top__DOT__wb_addr),30);
        vcdp->chgBus(c+465,(vlTOPp->top__DOT__wb_mosi_data),32);
        vcdp->chgBus(c+473,(vlTOPp->top__DOT__fetch__DOT__pc),32);
        vcdp->chgBus(c+481,(vlTOPp->top__DOT__fetch__DOT__state),4);
        vcdp->chgBus(c+489,(vlTOPp->top__DOT__reg_file__DOT__reg_file[0]),32);
        vcdp->chgBus(c+490,(vlTOPp->top__DOT__reg_file__DOT__reg_file[1]),32);
        vcdp->chgBus(c+491,(vlTOPp->top__DOT__reg_file__DOT__reg_file[2]),32);
        vcdp->chgBus(c+492,(vlTOPp->top__DOT__reg_file__DOT__reg_file[3]),32);
        vcdp->chgBus(c+493,(vlTOPp->top__DOT__reg_file__DOT__reg_file[4]),32);
        vcdp->chgBus(c+494,(vlTOPp->top__DOT__reg_file__DOT__reg_file[5]),32);
        vcdp->chgBus(c+495,(vlTOPp->top__DOT__reg_file__DOT__reg_file[6]),32);
        vcdp->chgBus(c+496,(vlTOPp->top__DOT__reg_file__DOT__reg_file[7]),32);
        vcdp->chgBus(c+497,(vlTOPp->top__DOT__reg_file__DOT__reg_file[8]),32);
        vcdp->chgBus(c+498,(vlTOPp->top__DOT__reg_file__DOT__reg_file[9]),32);
        vcdp->chgBus(c+499,(vlTOPp->top__DOT__reg_file__DOT__reg_file[10]),32);
        vcdp->chgBus(c+500,(vlTOPp->top__DOT__reg_file__DOT__reg_file[11]),32);
        vcdp->chgBus(c+501,(vlTOPp->top__DOT__reg_file__DOT__reg_file[12]),32);
        vcdp->chgBus(c+502,(vlTOPp->top__DOT__reg_file__DOT__reg_file[13]),32);
        vcdp->chgBus(c+503,(vlTOPp->top__DOT__reg_file__DOT__reg_file[14]),32);
        vcdp->chgBus(c+504,(vlTOPp->top__DOT__reg_file__DOT__reg_file[15]),32);
        vcdp->chgBus(c+505,(vlTOPp->top__DOT__reg_file__DOT__reg_file[16]),32);
        vcdp->chgBus(c+506,(vlTOPp->top__DOT__reg_file__DOT__reg_file[17]),32);
        vcdp->chgBus(c+507,(vlTOPp->top__DOT__reg_file__DOT__reg_file[18]),32);
        vcdp->chgBus(c+508,(vlTOPp->top__DOT__reg_file__DOT__reg_file[19]),32);
        vcdp->chgBus(c+509,(vlTOPp->top__DOT__reg_file__DOT__reg_file[20]),32);
        vcdp->chgBus(c+510,(vlTOPp->top__DOT__reg_file__DOT__reg_file[21]),32);
        vcdp->chgBus(c+511,(vlTOPp->top__DOT__reg_file__DOT__reg_file[22]),32);
        vcdp->chgBus(c+512,(vlTOPp->top__DOT__reg_file__DOT__reg_file[23]),32);
        vcdp->chgBus(c+513,(vlTOPp->top__DOT__reg_file__DOT__reg_file[24]),32);
        vcdp->chgBus(c+514,(vlTOPp->top__DOT__reg_file__DOT__reg_file[25]),32);
        vcdp->chgBus(c+515,(vlTOPp->top__DOT__reg_file__DOT__reg_file[26]),32);
        vcdp->chgBus(c+516,(vlTOPp->top__DOT__reg_file__DOT__reg_file[27]),32);
        vcdp->chgBus(c+517,(vlTOPp->top__DOT__reg_file__DOT__reg_file[28]),32);
        vcdp->chgBus(c+518,(vlTOPp->top__DOT__reg_file__DOT__reg_file[29]),32);
        vcdp->chgBus(c+519,(vlTOPp->top__DOT__reg_file__DOT__reg_file[30]),32);
        vcdp->chgBus(c+520,(vlTOPp->top__DOT__reg_file__DOT__reg_file[31]),32);
        vcdp->chgBus(c+745,(vlTOPp->top__DOT__reg_file__DOT__reg_file
                            [0U]),32);
        vcdp->chgBus(c+753,(vlTOPp->top__DOT__reg_file__DOT__reg_file
                            [1U]),32);
        vcdp->chgBus(c+761,(vlTOPp->top__DOT__reg_file__DOT__reg_file
                            [2U]),32);
        vcdp->chgBus(c+769,(vlTOPp->top__DOT__reg_file__DOT__reg_file
                            [3U]),32);
        vcdp->chgBus(c+777,(vlTOPp->top__DOT__reg_file__DOT__reg_file
                            [4U]),32);
        vcdp->chgBus(c+785,(vlTOPp->top__DOT__reg_file__DOT__reg_file
                            [0xaU]),32);
        vcdp->chgBus(c+793,(vlTOPp->top__DOT__reg_file__DOT__reg_file
                            [0xbU]),32);
        vcdp->chgBus(c+801,((0x7fU & vlTOPp->top__DOT__if_id_instruction)),7);
        vcdp->chgBus(c+809,((0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                      >> 0xfU))),5);
        vcdp->chgBus(c+817,((0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                      >> 0x14U))),5);
        vcdp->chgBus(c+825,((0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                      >> 7U))),5);
        vcdp->chgBus(c+833,((7U & (vlTOPp->top__DOT__if_id_instruction 
                                   >> 0xcU))),3);
        vcdp->chgBus(c+841,((0x7fU & (vlTOPp->top__DOT__if_id_instruction 
                                      >> 0x19U))),7);
        vcdp->chgBit(c+849,((0x33U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))));
        vcdp->chgBit(c+857,((0x13U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))));
        vcdp->chgBit(c+865,((3U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))));
        vcdp->chgBit(c+873,((0x23U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))));
        vcdp->chgBit(c+881,((0x63U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))));
        vcdp->chgBit(c+889,((0x6fU == (0x7fU & vlTOPp->top__DOT__if_id_instruction))));
        vcdp->chgBit(c+897,((0x67U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))));
        vcdp->chgBit(c+905,((0x17U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))));
        vcdp->chgBit(c+913,((0x37U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))));
        vcdp->chgBit(c+921,((0x33U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+929,((0x13U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+937,((3U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+945,((0x23U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+953,((0x63U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+961,((0x6fU == (IData)(vlTOPp->top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+969,((0x67U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+977,((0x17U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))));
        vcdp->chgBit(c+985,((0x37U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))));
        vcdp->chgBus(c+993,(vlTOPp->top__DOT__mem__DOT__state),4);
        vcdp->chgBus(c+1001,(((0xfffff000U & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlTOPp->top__DOT__ex_mem_immediate 
                                                                      >> 0xbU)))) 
                                              << 0xcU)) 
                              | (0xfffU & vlTOPp->top__DOT__ex_mem_immediate))),32);
        vcdp->chgBit(c+1009,((0U == (IData)(vlTOPp->top__DOT__ex_mem_func3))));
        vcdp->chgBit(c+1017,((1U == (IData)(vlTOPp->top__DOT__ex_mem_func3))));
        vcdp->chgBit(c+1025,((2U == (IData)(vlTOPp->top__DOT__ex_mem_func3))));
        vcdp->chgBit(c+1033,((4U == (IData)(vlTOPp->top__DOT__ex_mem_func3))));
        vcdp->chgBit(c+1041,((5U == (IData)(vlTOPp->top__DOT__ex_mem_func3))));
        vcdp->chgBit(c+1049,((3U == (IData)(vlTOPp->top__DOT__ex_mem_opcode))));
        vcdp->chgBit(c+1057,((0x23U == (IData)(vlTOPp->top__DOT__ex_mem_opcode))));
        vcdp->chgBus(c+1065,((0x3ffffU & (vlTOPp->top__DOT__fetch__DOT__pc 
                                          >> 2U))),18);
        vcdp->chgBus(c+1073,((0x3ffffU & vlTOPp->top__DOT__wb_addr)),18);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1081,(vlTOPp->clk));
        vcdp->chgBit(c+1089,(vlTOPp->reset));
    }
}
