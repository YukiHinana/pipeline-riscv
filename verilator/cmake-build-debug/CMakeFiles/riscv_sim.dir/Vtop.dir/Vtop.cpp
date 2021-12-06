// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("../rtl/../rtl/top.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("../rtl/../rtl/top.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__top__DOT__fetch__DOT__state;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__reg_file__DOT__reg_file__v0;
    CData/*3:0*/ __Vdly__top__DOT__mem__DOT__state;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__my_mem__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__my_mem__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__my_mem__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__my_mem__DOT__mem__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__my_mem__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__my_mem__DOT__mem__v1;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__my_mem__DOT__mem__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__my_mem__DOT__mem__v2;
    CData/*0:0*/ __Vdlyvset__top__DOT__my_mem__DOT__mem__v2;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__my_mem__DOT__mem__v3;
    CData/*7:0*/ __Vdlyvval__top__DOT__my_mem__DOT__mem__v3;
    CData/*0:0*/ __Vdlyvset__top__DOT__my_mem__DOT__mem__v3;
    IData/*31:0*/ __Vdly__top__DOT__fetch__DOT__pc;
    IData/*31:0*/ __Vdlyvval__top__DOT__reg_file__DOT__reg_file__v0;
    IData/*17:0*/ __Vdlyvdim0__top__DOT__my_mem__DOT__mem__v0;
    IData/*17:0*/ __Vdlyvdim0__top__DOT__my_mem__DOT__mem__v1;
    IData/*17:0*/ __Vdlyvdim0__top__DOT__my_mem__DOT__mem__v2;
    IData/*17:0*/ __Vdlyvdim0__top__DOT__my_mem__DOT__mem__v3;
    // Body
    __Vdly__top__DOT__fetch__DOT__pc = vlTOPp->top__DOT__fetch__DOT__pc;
    __Vdly__top__DOT__fetch__DOT__state = vlTOPp->top__DOT__fetch__DOT__state;
    __Vdly__top__DOT__mem__DOT__state = vlTOPp->top__DOT__mem__DOT__state;
    __Vdlyvset__top__DOT__my_mem__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__my_mem__DOT__mem__v1 = 0U;
    __Vdlyvset__top__DOT__my_mem__DOT__mem__v2 = 0U;
    __Vdlyvset__top__DOT__my_mem__DOT__mem__v3 = 0U;
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__id_rr_sr2_number = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)))) {
            vlTOPp->top__DOT__id_rr_sr2_number = 0U;
            if ((1U & (~ ((0x13U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                          | (3U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)))))) {
                if (((0x33U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                     | (0x23U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)))) {
                    vlTOPp->top__DOT__id_rr_sr2_number 
                        = (0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                    >> 0x14U));
                } else {
                    if ((0x63U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                        vlTOPp->top__DOT__id_rr_sr2_number 
                            = (0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                        >> 0x14U));
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__id_rr_sr2_number = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__id_rr_sr1_number = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)))) {
            vlTOPp->top__DOT__id_rr_sr1_number = 0U;
            if (((0x13U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                 | (3U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)))) {
                vlTOPp->top__DOT__id_rr_sr1_number 
                    = (0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                >> 0xfU));
            } else {
                if (((0x33U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                     | (0x23U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)))) {
                    vlTOPp->top__DOT__id_rr_sr1_number 
                        = (0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                    >> 0xfU));
                } else {
                    if ((0x63U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                        vlTOPp->top__DOT__id_rr_sr1_number 
                            = (0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                        >> 0xfU));
                    } else {
                        if ((0x6fU != (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                            if ((0x67U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                                vlTOPp->top__DOT__id_rr_sr1_number 
                                    = (0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                                >> 0xfU));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__id_rr_sr1_number = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__ex_mem_rs1_val = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
            vlTOPp->top__DOT__ex_mem_rs1_val = vlTOPp->top__DOT__rr_ex_rs1_val;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__rr_ex_func7 = 0U;
    } else {
        if (vlTOPp->top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
                vlTOPp->top__DOT__rr_ex_func7 = 0U;
            }
        } else {
            vlTOPp->top__DOT__rr_ex_func7 = vlTOPp->top__DOT__id_rr_func7;
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__rr_ex_func7 = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__ex_mem_pc = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
            vlTOPp->top__DOT__ex_mem_pc = vlTOPp->top__DOT__rr_ex_pc;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__ex_mem_immediate = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
            vlTOPp->top__DOT__ex_mem_immediate = vlTOPp->top__DOT__rr_ex_immediate;
        }
    }
    __Vdlyvval__top__DOT__reg_file__DOT__reg_file__v0 
        = vlTOPp->top__DOT__data;
    __Vdlyvdim0__top__DOT__reg_file__DOT__reg_file__v0 
        = vlTOPp->top__DOT__dest_addr;
    if (((IData)(vlTOPp->top__DOT__wb_cyc) & (IData)(vlTOPp->top__DOT__my_mem__DOT__w_wstb))) {
        if ((1U & (IData)(vlTOPp->top__DOT__wb_sel))) {
            __Vdlyvval__top__DOT__my_mem__DOT__mem__v0 
                = (0xffU & vlTOPp->top__DOT__wb_mosi_data);
            __Vdlyvset__top__DOT__my_mem__DOT__mem__v0 = 1U;
            __Vdlyvlsb__top__DOT__my_mem__DOT__mem__v0 = 0U;
            __Vdlyvdim0__top__DOT__my_mem__DOT__mem__v0 
                = (0x3ffffU & vlTOPp->top__DOT__wb_addr);
        }
        if ((2U & (IData)(vlTOPp->top__DOT__wb_sel))) {
            __Vdlyvval__top__DOT__my_mem__DOT__mem__v1 
                = (0xffU & (vlTOPp->top__DOT__wb_mosi_data 
                            >> 8U));
            __Vdlyvset__top__DOT__my_mem__DOT__mem__v1 = 1U;
            __Vdlyvlsb__top__DOT__my_mem__DOT__mem__v1 = 8U;
            __Vdlyvdim0__top__DOT__my_mem__DOT__mem__v1 
                = (0x3ffffU & vlTOPp->top__DOT__wb_addr);
        }
        if ((4U & (IData)(vlTOPp->top__DOT__wb_sel))) {
            __Vdlyvval__top__DOT__my_mem__DOT__mem__v2 
                = (0xffU & (vlTOPp->top__DOT__wb_mosi_data 
                            >> 0x10U));
            __Vdlyvset__top__DOT__my_mem__DOT__mem__v2 = 1U;
            __Vdlyvlsb__top__DOT__my_mem__DOT__mem__v2 = 0x10U;
            __Vdlyvdim0__top__DOT__my_mem__DOT__mem__v2 
                = (0x3ffffU & vlTOPp->top__DOT__wb_addr);
        }
        if ((8U & (IData)(vlTOPp->top__DOT__wb_sel))) {
            __Vdlyvval__top__DOT__my_mem__DOT__mem__v3 
                = (0xffU & (vlTOPp->top__DOT__wb_mosi_data 
                            >> 0x18U));
            __Vdlyvset__top__DOT__my_mem__DOT__mem__v3 = 1U;
            __Vdlyvlsb__top__DOT__my_mem__DOT__mem__v3 = 0x18U;
            __Vdlyvdim0__top__DOT__my_mem__DOT__mem__v3 
                = (0x3ffffU & vlTOPp->top__DOT__wb_addr);
        }
    }
    vlTOPp->top__DOT__reg_file__DOT__reg_file[__Vdlyvdim0__top__DOT__reg_file__DOT__reg_file__v0] 
        = __Vdlyvval__top__DOT__reg_file__DOT__reg_file__v0;
    if (__Vdlyvset__top__DOT__my_mem__DOT__mem__v0) {
        vlTOPp->top__DOT__my_mem__DOT__mem[__Vdlyvdim0__top__DOT__my_mem__DOT__mem__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__my_mem__DOT__mem__v0))) 
                & vlTOPp->top__DOT__my_mem__DOT__mem
                [__Vdlyvdim0__top__DOT__my_mem__DOT__mem__v0]) 
               | ((IData)(__Vdlyvval__top__DOT__my_mem__DOT__mem__v0) 
                  << (IData)(__Vdlyvlsb__top__DOT__my_mem__DOT__mem__v0)));
    }
    if (__Vdlyvset__top__DOT__my_mem__DOT__mem__v1) {
        vlTOPp->top__DOT__my_mem__DOT__mem[__Vdlyvdim0__top__DOT__my_mem__DOT__mem__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__my_mem__DOT__mem__v1))) 
                & vlTOPp->top__DOT__my_mem__DOT__mem
                [__Vdlyvdim0__top__DOT__my_mem__DOT__mem__v1]) 
               | ((IData)(__Vdlyvval__top__DOT__my_mem__DOT__mem__v1) 
                  << (IData)(__Vdlyvlsb__top__DOT__my_mem__DOT__mem__v1)));
    }
    if (__Vdlyvset__top__DOT__my_mem__DOT__mem__v2) {
        vlTOPp->top__DOT__my_mem__DOT__mem[__Vdlyvdim0__top__DOT__my_mem__DOT__mem__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__my_mem__DOT__mem__v2))) 
                & vlTOPp->top__DOT__my_mem__DOT__mem
                [__Vdlyvdim0__top__DOT__my_mem__DOT__mem__v2]) 
               | ((IData)(__Vdlyvval__top__DOT__my_mem__DOT__mem__v2) 
                  << (IData)(__Vdlyvlsb__top__DOT__my_mem__DOT__mem__v2)));
    }
    if (__Vdlyvset__top__DOT__my_mem__DOT__mem__v3) {
        vlTOPp->top__DOT__my_mem__DOT__mem[__Vdlyvdim0__top__DOT__my_mem__DOT__mem__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__my_mem__DOT__mem__v3))) 
                & vlTOPp->top__DOT__my_mem__DOT__mem
                [__Vdlyvdim0__top__DOT__my_mem__DOT__mem__v3]) 
               | ((IData)(__Vdlyvval__top__DOT__my_mem__DOT__mem__v3) 
                  << (IData)(__Vdlyvlsb__top__DOT__my_mem__DOT__mem__v3)));
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__rr_ex_rs1_val = 0U;
    } else {
        if (vlTOPp->top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
                vlTOPp->top__DOT__rr_ex_rs1_val = 0U;
            }
        } else {
            vlTOPp->top__DOT__rr_ex_rs1_val = vlTOPp->top__DOT__rr__DOT__rs1_val;
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__rr_ex_rs1_val = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__id_rr_func7 = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)))) {
            vlTOPp->top__DOT__id_rr_func7 = 0U;
            if (((0x13U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                 | (3U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)))) {
                if (((0x13U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                     & ((1U == (7U & (vlTOPp->top__DOT__if_id_instruction 
                                      >> 0xcU))) | 
                        (5U == (7U & (vlTOPp->top__DOT__if_id_instruction 
                                      >> 0xcU)))))) {
                    vlTOPp->top__DOT__id_rr_func7 = 
                        (0x7fU & (vlTOPp->top__DOT__if_id_instruction 
                                  >> 0x19U));
                }
            } else {
                if (((0x33U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                     | (0x23U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)))) {
                    if ((0x23U != (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                        if ((0x33U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                            vlTOPp->top__DOT__id_rr_func7 
                                = (0x7fU & (vlTOPp->top__DOT__if_id_instruction 
                                            >> 0x19U));
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__id_rr_func7 = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__rr_ex_pc = 0U;
    } else {
        if (vlTOPp->top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
                vlTOPp->top__DOT__rr_ex_pc = 0U;
            }
        } else {
            vlTOPp->top__DOT__rr_ex_pc = vlTOPp->top__DOT__id_rr_pc;
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__rr_ex_pc = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__rr_ex_immediate = 0U;
    } else {
        if (vlTOPp->top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
                vlTOPp->top__DOT__rr_ex_immediate = 0U;
            }
        } else {
            vlTOPp->top__DOT__rr_ex_immediate = vlTOPp->top__DOT__id_rr_immediate;
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__rr_ex_immediate = 0U;
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if ((1U & (~ ((0x23U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)) 
                      | (3U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)))))) {
            vlTOPp->top__DOT__dest_addr = vlTOPp->top__DOT__ex_mem_rd_number;
        }
    }
    vlTOPp->top__DOT__dest_addr = ((IData)(vlTOPp->top__DOT__mem_pipeline_stall)
                                    ? 0U : (IData)(vlTOPp->top__DOT__ex_mem_rd_number));
    if (vlTOPp->reset) {
        __Vdly__top__DOT__mem__DOT__state = 0U;
        vlTOPp->top__DOT__wb_cyc = 0U;
        vlTOPp->top__DOT__wb_stb = 0U;
    } else {
        if (((0x23U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)) 
             | (3U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)))) {
            if (((0U == (IData)(vlTOPp->top__DOT__mem__DOT__state)) 
                 & ((0x23U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)) 
                    | (3U == (IData)(vlTOPp->top__DOT__ex_mem_opcode))))) {
                __Vdly__top__DOT__mem__DOT__state = 1U;
                vlTOPp->top__DOT__wb_cyc = 1U;
                vlTOPp->top__DOT__wb_stb = 1U;
                vlTOPp->top__DOT__wb_we = 0U;
                if ((3U == (IData)(vlTOPp->top__DOT__ex_mem_opcode))) {
                    vlTOPp->top__DOT__wb_addr = (0x3fffffffU 
                                                 & (vlTOPp->top__DOT__mem__DOT__rs1_and_offset 
                                                    >> 2U));
                    vlTOPp->top__DOT__wb_sel = 0xfU;
                } else {
                    if ((0x23U == (IData)(vlTOPp->top__DOT__ex_mem_opcode))) {
                        vlTOPp->top__DOT__wb_we = 1U;
                        vlTOPp->top__DOT__wb_addr = 
                            (0x3fffffffU & (vlTOPp->top__DOT__mem__DOT__rs1_and_offset 
                                            >> 2U));
                        if ((0U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
                            vlTOPp->top__DOT__wb_sel 
                                = (0xfU & ((IData)(1U) 
                                           << (3U & vlTOPp->top__DOT__mem__DOT__rs1_and_offset)));
                            vlTOPp->top__DOT__wb_mosi_data 
                                = (0xffU & vlTOPp->top__DOT__ex_mem_rs2_val);
                        } else {
                            if ((1U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
                                vlTOPp->top__DOT__wb_sel 
                                    = (0xfU & ((IData)(3U) 
                                               << (3U 
                                                   & vlTOPp->top__DOT__mem__DOT__rs1_and_offset)));
                                vlTOPp->top__DOT__wb_mosi_data 
                                    = (0xffffU & vlTOPp->top__DOT__ex_mem_rs2_val);
                            } else {
                                if ((2U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
                                    vlTOPp->top__DOT__wb_sel = 0xfU;
                                    vlTOPp->top__DOT__wb_mosi_data 
                                        = vlTOPp->top__DOT__ex_mem_rs2_val;
                                }
                            }
                        }
                    }
                }
            } else {
                if ((1U == (IData)(vlTOPp->top__DOT__mem__DOT__state))) {
                    if (vlTOPp->top__DOT__wb_ack) {
                        __Vdly__top__DOT__mem__DOT__state = 0U;
                        vlTOPp->top__DOT__wb_cyc = 0U;
                        vlTOPp->top__DOT__wb_stb = 0U;
                        vlTOPp->top__DOT__data = vlTOPp->top__DOT__mem__DOT__load_result;
                    } else {
                        __Vdly__top__DOT__mem__DOT__state = 2U;
                        vlTOPp->top__DOT__wb_cyc = 1U;
                        vlTOPp->top__DOT__wb_stb = 0U;
                    }
                } else {
                    if ((2U == (IData)(vlTOPp->top__DOT__mem__DOT__state))) {
                        if (vlTOPp->top__DOT__wb_ack) {
                            __Vdly__top__DOT__mem__DOT__state = 0U;
                            vlTOPp->top__DOT__wb_cyc = 0U;
                            vlTOPp->top__DOT__wb_stb = 0U;
                            vlTOPp->top__DOT__data 
                                = vlTOPp->top__DOT__mem__DOT__load_result;
                        }
                    }
                }
            }
        } else {
            vlTOPp->top__DOT__data = vlTOPp->top__DOT__ex_mem_result;
        }
    }
    if (vlTOPp->top__DOT__mem_pipeline_stall) {
        vlTOPp->top__DOT__data = 0U;
    }
    vlTOPp->top__DOT__mem__DOT__state = __Vdly__top__DOT__mem__DOT__state;
    vlTOPp->top__DOT__mem__DOT__rs1_and_offset = (vlTOPp->top__DOT__ex_mem_rs1_val 
                                                  + 
                                                  ((0xfffff000U 
                                                    & (VL_NEGATE_I((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->top__DOT__ex_mem_immediate 
                                                                               >> 0xbU)))) 
                                                       << 0xcU)) 
                                                   | (0xfffU 
                                                      & vlTOPp->top__DOT__ex_mem_immediate)));
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__id_rr_pc = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)))) {
            vlTOPp->top__DOT__id_rr_pc = vlTOPp->top__DOT__if_id_pc;
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__id_rr_pc = 0U;
    }
    vlTOPp->top__DOT__ex__DOT__sign_extended = ((0xfffff000U 
                                                 & (VL_NEGATE_I((IData)(
                                                                        (1U 
                                                                         & (vlTOPp->top__DOT__rr_ex_immediate 
                                                                            >> 0xbU)))) 
                                                    << 0xcU)) 
                                                | (0xfffU 
                                                   & vlTOPp->top__DOT__rr_ex_immediate));
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__id_rr_immediate = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)))) {
            vlTOPp->top__DOT__id_rr_immediate = 0U;
            if (((0x13U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                 | (3U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)))) {
                vlTOPp->top__DOT__id_rr_immediate = 
                    (((0x13U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                      & ((1U == (7U & (vlTOPp->top__DOT__if_id_instruction 
                                       >> 0xcU))) | 
                         (5U == (7U & (vlTOPp->top__DOT__if_id_instruction 
                                       >> 0xcU)))))
                      ? (IData)((QData)((IData)((0x1fU 
                                                 & (vlTOPp->top__DOT__if_id_instruction 
                                                    >> 0x14U)))))
                      : (0xfffU & (vlTOPp->top__DOT__if_id_instruction 
                                   >> 0x14U)));
            } else {
                if (((0x33U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                     | (0x23U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)))) {
                    if ((0x23U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                        vlTOPp->top__DOT__id_rr_immediate 
                            = ((0xfe0U & (vlTOPp->top__DOT__if_id_instruction 
                                          >> 0x14U)) 
                               | (0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                           >> 7U)));
                    }
                } else {
                    if ((0x63U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                        vlTOPp->top__DOT__id_rr_immediate 
                            = ((0xffffe000U & (VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & ((IData)(vlTOPp->top__DOT__id__DOT__branch_offset) 
                                                                       >> 0xbU)))) 
                                               << 0xdU)) 
                               | ((IData)(vlTOPp->top__DOT__id__DOT__branch_offset) 
                                  << 1U));
                    } else {
                        if ((0x6fU == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                            vlTOPp->top__DOT__id_rr_immediate 
                                = ((0xffe00000U & (
                                                   VL_NEGATE_I((IData)(
                                                                       (1U 
                                                                        & (vlTOPp->top__DOT__if_id_instruction 
                                                                           >> 0x1fU)))) 
                                                   << 0x15U)) 
                                   | ((0x100000U & 
                                       (vlTOPp->top__DOT__if_id_instruction 
                                        >> 0xbU)) | 
                                      ((0xff000U & vlTOPp->top__DOT__if_id_instruction) 
                                       | ((0x800U & 
                                           (vlTOPp->top__DOT__if_id_instruction 
                                            >> 9U)) 
                                          | (0x7feU 
                                             & (vlTOPp->top__DOT__if_id_instruction 
                                                >> 0x14U))))));
                        } else {
                            if ((0x67U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                                vlTOPp->top__DOT__id_rr_immediate 
                                    = ((0xfffff000U 
                                        & (VL_NEGATE_I((IData)(
                                                               (1U 
                                                                & (vlTOPp->top__DOT__if_id_instruction 
                                                                   >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | (0xfffU & 
                                          (vlTOPp->top__DOT__if_id_instruction 
                                           >> 0x14U)));
                            } else {
                                if (((0x37U == (0x7fU 
                                                & vlTOPp->top__DOT__if_id_instruction)) 
                                     | (0x17U == (0x7fU 
                                                  & vlTOPp->top__DOT__if_id_instruction)))) {
                                    vlTOPp->top__DOT__id_rr_immediate 
                                        = (0xfffff000U 
                                           & vlTOPp->top__DOT__if_id_instruction);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__id_rr_immediate = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__ex_mem_rd_number = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
            vlTOPp->top__DOT__ex_mem_rd_number = vlTOPp->top__DOT__rr_ex_rd_number;
        }
    }
    vlTOPp->top__DOT__ex_mem_result = 0U;
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__ex_mem_result = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
            vlTOPp->top__DOT__ex_mem_result = vlTOPp->top__DOT__df_ex_result;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__ex_mem_rs2_val = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
            vlTOPp->top__DOT__ex_mem_rs2_val = vlTOPp->top__DOT__rr_ex_rs2_val;
        }
    }
    vlTOPp->top__DOT__wb_ack = 0U;
    if (((IData)(vlTOPp->top__DOT__wb_cyc) & (IData)(vlTOPp->top__DOT__wb_stb))) {
        vlTOPp->top__DOT__wb_ack = 1U;
    }
    vlTOPp->top__DOT__my_mem__DOT__w_wstb = ((IData)(vlTOPp->top__DOT__wb_stb) 
                                             & (IData)(vlTOPp->top__DOT__wb_we));
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__ex_mem_func3 = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
            vlTOPp->top__DOT__ex_mem_func3 = vlTOPp->top__DOT__rr_ex_func3;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__ex_mem_opcode = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
            vlTOPp->top__DOT__ex_mem_opcode = vlTOPp->top__DOT__rr_ex_opcode;
        }
    }
    vlTOPp->top__DOT__wb_miso_data = 0U;
    if ((((IData)(vlTOPp->top__DOT__wb_cyc) & (IData)(vlTOPp->top__DOT__wb_stb)) 
         & (~ (IData)(vlTOPp->top__DOT__my_mem__DOT__w_wstb)))) {
        vlTOPp->top__DOT__wb_miso_data = vlTOPp->top__DOT__my_mem__DOT__mem
            [(0x3ffffU & vlTOPp->top__DOT__wb_addr)];
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__rr_ex_rd_number = 0U;
    } else {
        if (vlTOPp->top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
                vlTOPp->top__DOT__rr_ex_rd_number = 0U;
            }
        } else {
            vlTOPp->top__DOT__rr_ex_rd_number = vlTOPp->top__DOT__id_rr_rd_number;
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__rr_ex_rd_number = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__rr_ex_rs2_val = 0U;
    } else {
        if (vlTOPp->top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
                vlTOPp->top__DOT__rr_ex_rs2_val = 0U;
            }
        } else {
            vlTOPp->top__DOT__rr_ex_rs2_val = vlTOPp->top__DOT__rr__DOT__rs2_val;
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__rr_ex_rs2_val = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__rr_ex_func3 = 0U;
    } else {
        if (vlTOPp->top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
                vlTOPp->top__DOT__rr_ex_func3 = 0U;
            }
        } else {
            vlTOPp->top__DOT__rr_ex_func3 = vlTOPp->top__DOT__id_rr_func3;
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__rr_ex_func3 = 0U;
    }
    vlTOPp->top__DOT__mem__DOT__load_result = 0U;
    if ((3U == (IData)(vlTOPp->top__DOT__ex_mem_opcode))) {
        if ((0U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
            vlTOPp->top__DOT__mem__DOT__load_result 
                = ((0xffffff00U & (VL_NEGATE_I((IData)(
                                                       (1U 
                                                        & (vlTOPp->top__DOT__wb_miso_data 
                                                           >> 7U)))) 
                                   << 8U)) | (0xffU 
                                              & vlTOPp->top__DOT__wb_miso_data));
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
                vlTOPp->top__DOT__mem__DOT__load_result 
                    = ((0xffff0000U & (VL_NEGATE_I((IData)(
                                                           (1U 
                                                            & (vlTOPp->top__DOT__wb_miso_data 
                                                               >> 0xfU)))) 
                                       << 0x10U)) | 
                       (0xffffU & vlTOPp->top__DOT__wb_miso_data));
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
                    vlTOPp->top__DOT__mem__DOT__load_result 
                        = vlTOPp->top__DOT__wb_miso_data;
                } else {
                    if ((4U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
                        vlTOPp->top__DOT__mem__DOT__load_result 
                            = (0xffU & vlTOPp->top__DOT__wb_miso_data);
                    } else {
                        if ((5U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
                            vlTOPp->top__DOT__mem__DOT__load_result 
                                = (0xffffU & vlTOPp->top__DOT__wb_miso_data);
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__rr_ex_opcode = 0U;
    } else {
        if (vlTOPp->top__DOT__rr_pipeline_stall) {
            if (((IData)(vlTOPp->top__DOT__rr__DOT__pipeline_stall) 
                 & (~ (IData)(vlTOPp->top__DOT__mem_pipeline_stall)))) {
                vlTOPp->top__DOT__rr_ex_opcode = 0U;
            }
        } else {
            vlTOPp->top__DOT__rr_ex_opcode = vlTOPp->top__DOT__id_rr_opcode;
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__rr_ex_opcode = 0U;
    }
    vlTOPp->top__DOT__df_mem_result = vlTOPp->top__DOT__ex_mem_result;
    if (((3U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)) 
         | (0x23U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)))) {
        vlTOPp->top__DOT__df_mem_result = vlTOPp->top__DOT__mem__DOT__load_result;
    }
    vlTOPp->top__DOT__mem_pipeline_stall = 0U;
    if (((3U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)) 
         | (0x23U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)))) {
        vlTOPp->top__DOT__mem_pipeline_stall = 1U;
    }
    if (((IData)(vlTOPp->top__DOT__wb_cyc) & (IData)(vlTOPp->top__DOT__wb_ack))) {
        vlTOPp->top__DOT__mem_pipeline_stall = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__id_rr_rd_number = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)))) {
            vlTOPp->top__DOT__id_rr_rd_number = 0U;
            if (((0x13U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                 | (3U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)))) {
                vlTOPp->top__DOT__id_rr_rd_number = 
                    (0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                              >> 7U));
            } else {
                if (((0x33U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                     | (0x23U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)))) {
                    if ((0x23U != (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                        if ((0x33U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                            vlTOPp->top__DOT__id_rr_rd_number 
                                = (0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                            >> 7U));
                        }
                    }
                } else {
                    if ((0x63U != (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                        if ((0x6fU == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                            vlTOPp->top__DOT__id_rr_rd_number 
                                = (0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                            >> 7U));
                        } else {
                            if ((0x67U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                                vlTOPp->top__DOT__id_rr_rd_number 
                                    = (0x1fU & (vlTOPp->top__DOT__if_id_instruction 
                                                >> 7U));
                            } else {
                                if (((0x37U == (0x7fU 
                                                & vlTOPp->top__DOT__if_id_instruction)) 
                                     | (0x17U == (0x7fU 
                                                  & vlTOPp->top__DOT__if_id_instruction)))) {
                                    vlTOPp->top__DOT__id_rr_rd_number 
                                        = (0x1fU & 
                                           (vlTOPp->top__DOT__if_id_instruction 
                                            >> 7U));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__id_rr_rd_number = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__id_rr_func3 = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)))) {
            vlTOPp->top__DOT__id_rr_func3 = 0U;
            if ((((0x6fU != (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                  & (0x37U != (0x7fU & vlTOPp->top__DOT__if_id_instruction))) 
                 & (0x17U != (0x7fU & vlTOPp->top__DOT__if_id_instruction)))) {
                vlTOPp->top__DOT__id_rr_func3 = (7U 
                                                 & (vlTOPp->top__DOT__if_id_instruction 
                                                    >> 0xcU));
            }
            if ((1U & (~ ((0x13U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                          | (3U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)))))) {
                if ((1U & (~ ((0x33U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)) 
                              | (0x23U == (0x7fU & vlTOPp->top__DOT__if_id_instruction)))))) {
                    if ((0x63U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                        vlTOPp->top__DOT__id_rr_func3 
                            = (7U & (vlTOPp->top__DOT__if_id_instruction 
                                     >> 0xcU));
                    } else {
                        if ((0x6fU != (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                            if ((0x67U == (0x7fU & vlTOPp->top__DOT__if_id_instruction))) {
                                vlTOPp->top__DOT__id_rr_func3 
                                    = (7U & (vlTOPp->top__DOT__if_id_instruction 
                                             >> 0xcU));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__id_rr_func3 = 0U;
    }
    vlTOPp->top__DOT__df_ex_valid = 0U;
    if (((0x33U == (IData)(vlTOPp->top__DOT__rr_ex_opcode)) 
         | (0x13U == (IData)(vlTOPp->top__DOT__rr_ex_opcode)))) {
        vlTOPp->top__DOT__df_ex_valid = 1U;
    }
    vlTOPp->top__DOT__df_ex_result = 0U;
    if ((0x33U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
        if ((0x20U == (IData)(vlTOPp->top__DOT__rr_ex_func7))) {
            if ((0U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                vlTOPp->top__DOT__df_ex_result = (vlTOPp->top__DOT__rr_ex_rs1_val 
                                                  - vlTOPp->top__DOT__rr_ex_rs2_val);
            }
            if ((5U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                vlTOPp->top__DOT__df_ex_result = VL_SHIFTRS_III(32,32,5, vlTOPp->top__DOT__rr_ex_rs1_val, 
                                                                (0x1fU 
                                                                 & vlTOPp->top__DOT__rr_ex_rs2_val));
            }
        } else {
            if ((0U == (IData)(vlTOPp->top__DOT__rr_ex_func7))) {
                if ((0U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                    vlTOPp->top__DOT__df_ex_result 
                        = (vlTOPp->top__DOT__rr_ex_rs1_val 
                           + vlTOPp->top__DOT__rr_ex_rs2_val);
                } else {
                    if ((1U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                        vlTOPp->top__DOT__df_ex_result 
                            = (vlTOPp->top__DOT__rr_ex_rs1_val 
                               << (0x1fU & vlTOPp->top__DOT__rr_ex_rs2_val));
                    } else {
                        if ((2U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                            vlTOPp->top__DOT__df_ex_result 
                                = (VL_LTS_III(1,32,32, vlTOPp->top__DOT__rr_ex_rs1_val, vlTOPp->top__DOT__rr_ex_rs2_val)
                                    ? 1U : 0U);
                        } else {
                            if ((3U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                vlTOPp->top__DOT__df_ex_result 
                                    = ((vlTOPp->top__DOT__rr_ex_rs1_val 
                                        < vlTOPp->top__DOT__rr_ex_rs2_val)
                                        ? 1U : 0U);
                            } else {
                                if ((4U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                    vlTOPp->top__DOT__df_ex_result 
                                        = (vlTOPp->top__DOT__rr_ex_rs1_val 
                                           ^ vlTOPp->top__DOT__rr_ex_rs2_val);
                                } else {
                                    if ((5U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                        vlTOPp->top__DOT__df_ex_result 
                                            = (vlTOPp->top__DOT__rr_ex_rs1_val 
                                               >> (0x1fU 
                                                   & vlTOPp->top__DOT__rr_ex_rs2_val));
                                    } else {
                                        if ((6U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                            vlTOPp->top__DOT__df_ex_result 
                                                = (vlTOPp->top__DOT__rr_ex_rs1_val 
                                                   | vlTOPp->top__DOT__rr_ex_rs2_val);
                                        } else {
                                            if ((7U 
                                                 == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                                vlTOPp->top__DOT__df_ex_result 
                                                    = 
                                                    (vlTOPp->top__DOT__rr_ex_rs1_val 
                                                     & vlTOPp->top__DOT__rr_ex_rs2_val);
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
        if ((0x13U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
            if ((0U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                vlTOPp->top__DOT__df_ex_result = (vlTOPp->top__DOT__rr_ex_rs1_val 
                                                  + vlTOPp->top__DOT__ex__DOT__sign_extended);
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                    vlTOPp->top__DOT__df_ex_result 
                        = (VL_LTS_III(1,32,32, vlTOPp->top__DOT__rr_ex_rs1_val, vlTOPp->top__DOT__ex__DOT__sign_extended)
                            ? 1U : 0U);
                } else {
                    if ((3U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                        vlTOPp->top__DOT__df_ex_result 
                            = ((vlTOPp->top__DOT__rr_ex_rs1_val 
                                < vlTOPp->top__DOT__ex__DOT__sign_extended)
                                ? 1U : 0U);
                    } else {
                        if ((4U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                            vlTOPp->top__DOT__df_ex_result 
                                = (vlTOPp->top__DOT__ex__DOT__sign_extended 
                                   ^ vlTOPp->top__DOT__rr_ex_rs1_val);
                        } else {
                            if ((6U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                vlTOPp->top__DOT__df_ex_result 
                                    = (vlTOPp->top__DOT__ex__DOT__sign_extended 
                                       | vlTOPp->top__DOT__rr_ex_rs1_val);
                            } else {
                                if ((7U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                    vlTOPp->top__DOT__df_ex_result 
                                        = (vlTOPp->top__DOT__ex__DOT__sign_extended 
                                           & vlTOPp->top__DOT__rr_ex_rs1_val);
                                } else {
                                    if ((1U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                        vlTOPp->top__DOT__df_ex_result 
                                            = (vlTOPp->top__DOT__rr_ex_rs1_val 
                                               << (0x1fU 
                                                   & vlTOPp->top__DOT__rr_ex_immediate));
                                    } else {
                                        if (((5U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                                             | (5U 
                                                == (IData)(vlTOPp->top__DOT__rr_ex_func3)))) {
                                            if ((0U 
                                                 == (IData)(vlTOPp->top__DOT__rr_ex_func7))) {
                                                vlTOPp->top__DOT__df_ex_result 
                                                    = 
                                                    (vlTOPp->top__DOT__rr_ex_rs1_val 
                                                     >> 
                                                     (0x1fU 
                                                      & vlTOPp->top__DOT__rr_ex_immediate));
                                            } else {
                                                if (
                                                    (0x20U 
                                                     == (IData)(vlTOPp->top__DOT__rr_ex_func7))) {
                                                    vlTOPp->top__DOT__df_ex_result 
                                                        = 
                                                        VL_SHIFTRS_III(32,32,5, vlTOPp->top__DOT__rr_ex_rs1_val, 
                                                                       (0x1fU 
                                                                        & vlTOPp->top__DOT__rr_ex_immediate));
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
            if ((0x63U != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                if ((0x6fU == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                    vlTOPp->top__DOT__df_ex_result 
                        = ((IData)(4U) + vlTOPp->top__DOT__rr_ex_pc);
                } else {
                    if ((0x67U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                        vlTOPp->top__DOT__df_ex_result 
                            = ((IData)(4U) + vlTOPp->top__DOT__rr_ex_pc);
                    } else {
                        if ((0x37U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                            vlTOPp->top__DOT__df_ex_result 
                                = vlTOPp->top__DOT__rr_ex_immediate;
                        } else {
                            if ((0x17U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                                vlTOPp->top__DOT__df_ex_result 
                                    = (vlTOPp->top__DOT__rr_ex_immediate 
                                       + vlTOPp->top__DOT__rr_ex_pc);
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__id_rr_opcode = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)))) {
            vlTOPp->top__DOT__id_rr_opcode = (0x7fU 
                                              & vlTOPp->top__DOT__if_id_instruction);
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__id_rr_opcode = 0U;
    }
    vlTOPp->top__DOT__rr__DOT__rs1_val = ((0U == (IData)(vlTOPp->top__DOT__id_rr_sr1_number))
                                           ? 0U : (
                                                   ((IData)(vlTOPp->top__DOT__id_rr_sr1_number) 
                                                    == (IData)(vlTOPp->top__DOT__dest_addr))
                                                    ? vlTOPp->top__DOT__data
                                                    : 
                                                   vlTOPp->top__DOT__reg_file__DOT__reg_file
                                                   [vlTOPp->top__DOT__id_rr_sr1_number]));
    if ((0U != (IData)(vlTOPp->top__DOT__id_rr_sr1_number))) {
        if (((IData)(vlTOPp->top__DOT__id_rr_sr1_number) 
             == (IData)(vlTOPp->top__DOT__rr_ex_rd_number))) {
            if (vlTOPp->top__DOT__df_ex_valid) {
                vlTOPp->top__DOT__rr__DOT__rs1_val 
                    = vlTOPp->top__DOT__df_ex_result;
            }
        } else {
            if (((IData)(vlTOPp->top__DOT__id_rr_sr1_number) 
                 == (IData)(vlTOPp->top__DOT__ex_mem_rd_number))) {
                vlTOPp->top__DOT__rr__DOT__rs1_val 
                    = vlTOPp->top__DOT__df_mem_result;
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top__DOT__fetch__DOT__pc = 0U;
        vlTOPp->top__DOT__if_id_instruction = 0U;
        vlTOPp->top__DOT__if_id_pc = 0U;
        __Vdly__top__DOT__fetch__DOT__state = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)))) {
            vlTOPp->top__DOT__if_id_pc = 0U;
            vlTOPp->top__DOT__if_id_instruction = 0U;
        }
        if (((~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)) 
             & (IData)(vlTOPp->top__DOT__load_new_pc))) {
            vlTOPp->top__DOT__if_id_pc = 0U;
            vlTOPp->top__DOT__if_id_instruction = 0U;
            __Vdly__top__DOT__fetch__DOT__pc = vlTOPp->top__DOT__new_pc;
            __Vdly__top__DOT__fetch__DOT__state = 1U;
        }
        if (((0U == (IData)(vlTOPp->top__DOT__fetch__DOT__state)) 
             & (~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)))) {
            __Vdly__top__DOT__fetch__DOT__state = 1U;
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__fetch__DOT__state))) {
                if (vlTOPp->top__DOT__wb2_ack) {
                    __Vdly__top__DOT__fetch__DOT__state = 0U;
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)))) {
                        __Vdly__top__DOT__fetch__DOT__state = 1U;
                        vlTOPp->top__DOT__if_id_pc 
                            = vlTOPp->top__DOT__fetch__DOT__pc;
                        vlTOPp->top__DOT__if_id_instruction 
                            = vlTOPp->top__DOT__wb2_miso_data;
                        __Vdly__top__DOT__fetch__DOT__pc 
                            = ((IData)(4U) + vlTOPp->top__DOT__fetch__DOT__pc);
                    }
                } else {
                    __Vdly__top__DOT__fetch__DOT__state = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__fetch__DOT__state))) {
                    if (vlTOPp->top__DOT__wb2_ack) {
                        __Vdly__top__DOT__fetch__DOT__state = 0U;
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__rr_pipeline_stall)))) {
                            __Vdly__top__DOT__fetch__DOT__state = 1U;
                            vlTOPp->top__DOT__if_id_pc 
                                = vlTOPp->top__DOT__fetch__DOT__pc;
                            vlTOPp->top__DOT__if_id_instruction 
                                = vlTOPp->top__DOT__wb2_miso_data;
                            __Vdly__top__DOT__fetch__DOT__pc 
                                = ((IData)(4U) + vlTOPp->top__DOT__fetch__DOT__pc);
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        __Vdly__top__DOT__fetch__DOT__pc = vlTOPp->top__DOT__new_pc;
        vlTOPp->top__DOT__if_id_pc = 0U;
        vlTOPp->top__DOT__if_id_instruction = 0U;
    }
    vlTOPp->top__DOT__new_pc = (vlTOPp->top__DOT__rr_ex_pc 
                                + vlTOPp->top__DOT__rr_ex_immediate);
    if ((0x33U != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
        if ((0x13U != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
            if ((0x63U != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                if ((0x6fU != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                    if ((0x67U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                        vlTOPp->top__DOT__new_pc = 
                            (vlTOPp->top__DOT__rr_ex_immediate 
                             + vlTOPp->top__DOT__rr_ex_rs1_val);
                        vlTOPp->top__DOT__new_pc = 
                            (0xfffffffeU & vlTOPp->top__DOT__new_pc);
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__fetch__DOT__pc = __Vdly__top__DOT__fetch__DOT__pc;
    vlTOPp->top__DOT__fetch__DOT__state = __Vdly__top__DOT__fetch__DOT__state;
    vlTOPp->top__DOT__load_new_pc = 0U;
    if ((0x33U != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
        if ((0x13U != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
            if ((0x63U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                if (((0U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                     & (vlTOPp->top__DOT__rr_ex_rs1_val 
                        == vlTOPp->top__DOT__rr_ex_rs2_val))) {
                    vlTOPp->top__DOT__load_new_pc = 1U;
                } else {
                    if (((1U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                         & (vlTOPp->top__DOT__rr_ex_rs1_val 
                            != vlTOPp->top__DOT__rr_ex_rs2_val))) {
                        vlTOPp->top__DOT__load_new_pc = 1U;
                    } else {
                        if (((4U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                             & VL_LTS_III(1,32,32, vlTOPp->top__DOT__rr_ex_rs1_val, vlTOPp->top__DOT__rr_ex_rs2_val))) {
                            vlTOPp->top__DOT__load_new_pc = 1U;
                        } else {
                            if (((5U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                                 & VL_GTES_III(1,32,32, vlTOPp->top__DOT__rr_ex_rs1_val, vlTOPp->top__DOT__rr_ex_rs2_val))) {
                                vlTOPp->top__DOT__load_new_pc = 1U;
                            } else {
                                if (((6U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                                     & (vlTOPp->top__DOT__rr_ex_rs1_val 
                                        < vlTOPp->top__DOT__rr_ex_rs2_val))) {
                                    vlTOPp->top__DOT__load_new_pc = 1U;
                                } else {
                                    if (((7U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                                         & (vlTOPp->top__DOT__rr_ex_rs1_val 
                                            >= vlTOPp->top__DOT__rr_ex_rs2_val))) {
                                        vlTOPp->top__DOT__load_new_pc = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if ((0x6fU == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                    vlTOPp->top__DOT__load_new_pc = 1U;
                } else {
                    if ((0x67U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                        vlTOPp->top__DOT__load_new_pc = 1U;
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__mem_pipeline_stall) {
        vlTOPp->top__DOT__load_new_pc = 0U;
    }
    vlTOPp->top__DOT__id__DOT__branch_offset = ((0x800U 
                                                 & (vlTOPp->top__DOT__if_id_instruction 
                                                    >> 0x14U)) 
                                                | ((0x400U 
                                                    & (vlTOPp->top__DOT__if_id_instruction 
                                                       << 3U)) 
                                                   | ((0x3f0U 
                                                       & (vlTOPp->top__DOT__if_id_instruction 
                                                          >> 0x15U)) 
                                                      | (0xfU 
                                                         & (vlTOPp->top__DOT__if_id_instruction 
                                                            >> 8U)))));
    vlTOPp->top__DOT__wb2_cyc = 0U;
    if ((1U == (IData)(vlTOPp->top__DOT__fetch__DOT__state))) {
        vlTOPp->top__DOT__wb2_cyc = 1U;
    } else {
        if ((2U == (IData)(vlTOPp->top__DOT__fetch__DOT__state))) {
            vlTOPp->top__DOT__wb2_cyc = 1U;
        }
    }
    vlTOPp->top__DOT__wb2_stb = 0U;
    if ((1U == (IData)(vlTOPp->top__DOT__fetch__DOT__state))) {
        vlTOPp->top__DOT__wb2_stb = 1U;
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__rr_pipeline_stall = 0U;
    }
    vlTOPp->top__DOT__rr__DOT__pipeline_stall = 0U;
    vlTOPp->top__DOT__rr__DOT__rs2_val = ((0U == (IData)(vlTOPp->top__DOT__id_rr_sr2_number))
                                           ? 0U : (
                                                   ((IData)(vlTOPp->top__DOT__id_rr_sr2_number) 
                                                    == (IData)(vlTOPp->top__DOT__dest_addr))
                                                    ? vlTOPp->top__DOT__data
                                                    : 
                                                   vlTOPp->top__DOT__reg_file__DOT__reg_file
                                                   [vlTOPp->top__DOT__id_rr_sr2_number]));
    if ((0U != (IData)(vlTOPp->top__DOT__id_rr_sr1_number))) {
        if (((IData)(vlTOPp->top__DOT__id_rr_sr1_number) 
             == (IData)(vlTOPp->top__DOT__rr_ex_rd_number))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__df_ex_valid)))) {
                vlTOPp->top__DOT__rr__DOT__pipeline_stall = 1U;
            }
        }
    }
    if (((0U != (IData)(vlTOPp->top__DOT__id_rr_sr2_number)) 
         & (~ (IData)(vlTOPp->top__DOT__rr__DOT__pipeline_stall)))) {
        if (((IData)(vlTOPp->top__DOT__id_rr_sr2_number) 
             == (IData)(vlTOPp->top__DOT__rr_ex_rd_number))) {
            if (vlTOPp->top__DOT__df_ex_valid) {
                vlTOPp->top__DOT__rr__DOT__rs2_val 
                    = vlTOPp->top__DOT__df_ex_result;
            } else {
                vlTOPp->top__DOT__rr__DOT__pipeline_stall = 1U;
            }
        } else {
            if (((IData)(vlTOPp->top__DOT__id_rr_sr2_number) 
                 == (IData)(vlTOPp->top__DOT__ex_mem_rd_number))) {
                vlTOPp->top__DOT__rr__DOT__rs2_val 
                    = vlTOPp->top__DOT__df_mem_result;
            }
        }
    }
    vlTOPp->top__DOT__rr_pipeline_stall = ((IData)(vlTOPp->top__DOT__rr__DOT__pipeline_stall) 
                                           | (IData)(vlTOPp->top__DOT__mem_pipeline_stall));
    vlTOPp->top__DOT__wb2_ack = 0U;
    if (((IData)(vlTOPp->top__DOT__wb2_cyc) & (IData)(vlTOPp->top__DOT__wb2_stb))) {
        vlTOPp->top__DOT__wb2_ack = 1U;
    }
    vlTOPp->top__DOT__wb2_miso_data = 0U;
    if (((IData)(vlTOPp->top__DOT__wb2_cyc) & (IData)(vlTOPp->top__DOT__wb2_stb))) {
        vlTOPp->top__DOT__wb2_miso_data = vlTOPp->top__DOT__my_mem2__DOT__mem
            [(0x3ffffU & (vlTOPp->top__DOT__fetch__DOT__pc 
                          >> 2U))];
    }
}

void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__mem__DOT__rs1_and_offset = (vlTOPp->top__DOT__ex_mem_rs1_val 
                                                  + 
                                                  ((0xfffff000U 
                                                    & (VL_NEGATE_I((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->top__DOT__ex_mem_immediate 
                                                                               >> 0xbU)))) 
                                                       << 0xcU)) 
                                                   | (0xfffU 
                                                      & vlTOPp->top__DOT__ex_mem_immediate)));
    vlTOPp->top__DOT__ex__DOT__sign_extended = ((0xfffff000U 
                                                 & (VL_NEGATE_I((IData)(
                                                                        (1U 
                                                                         & (vlTOPp->top__DOT__rr_ex_immediate 
                                                                            >> 0xbU)))) 
                                                    << 0xcU)) 
                                                | (0xfffU 
                                                   & vlTOPp->top__DOT__rr_ex_immediate));
    vlTOPp->top__DOT__wb_ack = 0U;
    if (((IData)(vlTOPp->top__DOT__wb_cyc) & (IData)(vlTOPp->top__DOT__wb_stb))) {
        vlTOPp->top__DOT__wb_ack = 1U;
    }
    vlTOPp->top__DOT__my_mem__DOT__w_wstb = ((IData)(vlTOPp->top__DOT__wb_stb) 
                                             & (IData)(vlTOPp->top__DOT__wb_we));
    vlTOPp->top__DOT__df_ex_valid = 0U;
    if (((0x33U == (IData)(vlTOPp->top__DOT__rr_ex_opcode)) 
         | (0x13U == (IData)(vlTOPp->top__DOT__rr_ex_opcode)))) {
        vlTOPp->top__DOT__df_ex_valid = 1U;
    }
    vlTOPp->top__DOT__new_pc = (vlTOPp->top__DOT__rr_ex_pc 
                                + vlTOPp->top__DOT__rr_ex_immediate);
    if ((0x33U != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
        if ((0x13U != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
            if ((0x63U != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                if ((0x6fU != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                    if ((0x67U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                        vlTOPp->top__DOT__new_pc = 
                            (vlTOPp->top__DOT__rr_ex_immediate 
                             + vlTOPp->top__DOT__rr_ex_rs1_val);
                        vlTOPp->top__DOT__new_pc = 
                            (0xfffffffeU & vlTOPp->top__DOT__new_pc);
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__id__DOT__branch_offset = ((0x800U 
                                                 & (vlTOPp->top__DOT__if_id_instruction 
                                                    >> 0x14U)) 
                                                | ((0x400U 
                                                    & (vlTOPp->top__DOT__if_id_instruction 
                                                       << 3U)) 
                                                   | ((0x3f0U 
                                                       & (vlTOPp->top__DOT__if_id_instruction 
                                                          >> 0x15U)) 
                                                      | (0xfU 
                                                         & (vlTOPp->top__DOT__if_id_instruction 
                                                            >> 8U)))));
    vlTOPp->top__DOT__wb2_cyc = 0U;
    if ((1U == (IData)(vlTOPp->top__DOT__fetch__DOT__state))) {
        vlTOPp->top__DOT__wb2_cyc = 1U;
    } else {
        if ((2U == (IData)(vlTOPp->top__DOT__fetch__DOT__state))) {
            vlTOPp->top__DOT__wb2_cyc = 1U;
        }
    }
    vlTOPp->top__DOT__wb2_stb = 0U;
    if ((1U == (IData)(vlTOPp->top__DOT__fetch__DOT__state))) {
        vlTOPp->top__DOT__wb2_stb = 1U;
    }
    vlTOPp->top__DOT__df_ex_result = 0U;
    if ((0x33U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
        if ((0x20U == (IData)(vlTOPp->top__DOT__rr_ex_func7))) {
            if ((0U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                vlTOPp->top__DOT__df_ex_result = (vlTOPp->top__DOT__rr_ex_rs1_val 
                                                  - vlTOPp->top__DOT__rr_ex_rs2_val);
            }
            if ((5U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                vlTOPp->top__DOT__df_ex_result = VL_SHIFTRS_III(32,32,5, vlTOPp->top__DOT__rr_ex_rs1_val, 
                                                                (0x1fU 
                                                                 & vlTOPp->top__DOT__rr_ex_rs2_val));
            }
        } else {
            if ((0U == (IData)(vlTOPp->top__DOT__rr_ex_func7))) {
                if ((0U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                    vlTOPp->top__DOT__df_ex_result 
                        = (vlTOPp->top__DOT__rr_ex_rs1_val 
                           + vlTOPp->top__DOT__rr_ex_rs2_val);
                } else {
                    if ((1U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                        vlTOPp->top__DOT__df_ex_result 
                            = (vlTOPp->top__DOT__rr_ex_rs1_val 
                               << (0x1fU & vlTOPp->top__DOT__rr_ex_rs2_val));
                    } else {
                        if ((2U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                            vlTOPp->top__DOT__df_ex_result 
                                = (VL_LTS_III(1,32,32, vlTOPp->top__DOT__rr_ex_rs1_val, vlTOPp->top__DOT__rr_ex_rs2_val)
                                    ? 1U : 0U);
                        } else {
                            if ((3U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                vlTOPp->top__DOT__df_ex_result 
                                    = ((vlTOPp->top__DOT__rr_ex_rs1_val 
                                        < vlTOPp->top__DOT__rr_ex_rs2_val)
                                        ? 1U : 0U);
                            } else {
                                if ((4U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                    vlTOPp->top__DOT__df_ex_result 
                                        = (vlTOPp->top__DOT__rr_ex_rs1_val 
                                           ^ vlTOPp->top__DOT__rr_ex_rs2_val);
                                } else {
                                    if ((5U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                        vlTOPp->top__DOT__df_ex_result 
                                            = (vlTOPp->top__DOT__rr_ex_rs1_val 
                                               >> (0x1fU 
                                                   & vlTOPp->top__DOT__rr_ex_rs2_val));
                                    } else {
                                        if ((6U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                            vlTOPp->top__DOT__df_ex_result 
                                                = (vlTOPp->top__DOT__rr_ex_rs1_val 
                                                   | vlTOPp->top__DOT__rr_ex_rs2_val);
                                        } else {
                                            if ((7U 
                                                 == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                                vlTOPp->top__DOT__df_ex_result 
                                                    = 
                                                    (vlTOPp->top__DOT__rr_ex_rs1_val 
                                                     & vlTOPp->top__DOT__rr_ex_rs2_val);
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
        if ((0x13U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
            if ((0U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                vlTOPp->top__DOT__df_ex_result = (vlTOPp->top__DOT__rr_ex_rs1_val 
                                                  + vlTOPp->top__DOT__ex__DOT__sign_extended);
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                    vlTOPp->top__DOT__df_ex_result 
                        = (VL_LTS_III(1,32,32, vlTOPp->top__DOT__rr_ex_rs1_val, vlTOPp->top__DOT__ex__DOT__sign_extended)
                            ? 1U : 0U);
                } else {
                    if ((3U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                        vlTOPp->top__DOT__df_ex_result 
                            = ((vlTOPp->top__DOT__rr_ex_rs1_val 
                                < vlTOPp->top__DOT__ex__DOT__sign_extended)
                                ? 1U : 0U);
                    } else {
                        if ((4U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                            vlTOPp->top__DOT__df_ex_result 
                                = (vlTOPp->top__DOT__ex__DOT__sign_extended 
                                   ^ vlTOPp->top__DOT__rr_ex_rs1_val);
                        } else {
                            if ((6U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                vlTOPp->top__DOT__df_ex_result 
                                    = (vlTOPp->top__DOT__ex__DOT__sign_extended 
                                       | vlTOPp->top__DOT__rr_ex_rs1_val);
                            } else {
                                if ((7U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                    vlTOPp->top__DOT__df_ex_result 
                                        = (vlTOPp->top__DOT__ex__DOT__sign_extended 
                                           & vlTOPp->top__DOT__rr_ex_rs1_val);
                                } else {
                                    if ((1U == (IData)(vlTOPp->top__DOT__rr_ex_func3))) {
                                        vlTOPp->top__DOT__df_ex_result 
                                            = (vlTOPp->top__DOT__rr_ex_rs1_val 
                                               << (0x1fU 
                                                   & vlTOPp->top__DOT__rr_ex_immediate));
                                    } else {
                                        if (((5U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                                             | (5U 
                                                == (IData)(vlTOPp->top__DOT__rr_ex_func3)))) {
                                            if ((0U 
                                                 == (IData)(vlTOPp->top__DOT__rr_ex_func7))) {
                                                vlTOPp->top__DOT__df_ex_result 
                                                    = 
                                                    (vlTOPp->top__DOT__rr_ex_rs1_val 
                                                     >> 
                                                     (0x1fU 
                                                      & vlTOPp->top__DOT__rr_ex_immediate));
                                            } else {
                                                if (
                                                    (0x20U 
                                                     == (IData)(vlTOPp->top__DOT__rr_ex_func7))) {
                                                    vlTOPp->top__DOT__df_ex_result 
                                                        = 
                                                        VL_SHIFTRS_III(32,32,5, vlTOPp->top__DOT__rr_ex_rs1_val, 
                                                                       (0x1fU 
                                                                        & vlTOPp->top__DOT__rr_ex_immediate));
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
            if ((0x63U != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                if ((0x6fU == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                    vlTOPp->top__DOT__df_ex_result 
                        = ((IData)(4U) + vlTOPp->top__DOT__rr_ex_pc);
                } else {
                    if ((0x67U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                        vlTOPp->top__DOT__df_ex_result 
                            = ((IData)(4U) + vlTOPp->top__DOT__rr_ex_pc);
                    } else {
                        if ((0x37U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                            vlTOPp->top__DOT__df_ex_result 
                                = vlTOPp->top__DOT__rr_ex_immediate;
                        } else {
                            if ((0x17U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                                vlTOPp->top__DOT__df_ex_result 
                                    = (vlTOPp->top__DOT__rr_ex_immediate 
                                       + vlTOPp->top__DOT__rr_ex_pc);
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__mem_pipeline_stall = 0U;
    if (((3U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)) 
         | (0x23U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)))) {
        vlTOPp->top__DOT__mem_pipeline_stall = 1U;
    }
    if (((IData)(vlTOPp->top__DOT__wb_cyc) & (IData)(vlTOPp->top__DOT__wb_ack))) {
        vlTOPp->top__DOT__mem_pipeline_stall = 0U;
    }
    vlTOPp->top__DOT__wb_miso_data = 0U;
    if ((((IData)(vlTOPp->top__DOT__wb_cyc) & (IData)(vlTOPp->top__DOT__wb_stb)) 
         & (~ (IData)(vlTOPp->top__DOT__my_mem__DOT__w_wstb)))) {
        vlTOPp->top__DOT__wb_miso_data = vlTOPp->top__DOT__my_mem__DOT__mem
            [(0x3ffffU & vlTOPp->top__DOT__wb_addr)];
    }
    vlTOPp->top__DOT__wb2_ack = 0U;
    if (((IData)(vlTOPp->top__DOT__wb2_cyc) & (IData)(vlTOPp->top__DOT__wb2_stb))) {
        vlTOPp->top__DOT__wb2_ack = 1U;
    }
    vlTOPp->top__DOT__wb2_miso_data = 0U;
    if (((IData)(vlTOPp->top__DOT__wb2_cyc) & (IData)(vlTOPp->top__DOT__wb2_stb))) {
        vlTOPp->top__DOT__wb2_miso_data = vlTOPp->top__DOT__my_mem2__DOT__mem
            [(0x3ffffU & (vlTOPp->top__DOT__fetch__DOT__pc 
                          >> 2U))];
    }
    vlTOPp->top__DOT__load_new_pc = 0U;
    if ((0x33U != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
        if ((0x13U != (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
            if ((0x63U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                if (((0U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                     & (vlTOPp->top__DOT__rr_ex_rs1_val 
                        == vlTOPp->top__DOT__rr_ex_rs2_val))) {
                    vlTOPp->top__DOT__load_new_pc = 1U;
                } else {
                    if (((1U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                         & (vlTOPp->top__DOT__rr_ex_rs1_val 
                            != vlTOPp->top__DOT__rr_ex_rs2_val))) {
                        vlTOPp->top__DOT__load_new_pc = 1U;
                    } else {
                        if (((4U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                             & VL_LTS_III(1,32,32, vlTOPp->top__DOT__rr_ex_rs1_val, vlTOPp->top__DOT__rr_ex_rs2_val))) {
                            vlTOPp->top__DOT__load_new_pc = 1U;
                        } else {
                            if (((5U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                                 & VL_GTES_III(1,32,32, vlTOPp->top__DOT__rr_ex_rs1_val, vlTOPp->top__DOT__rr_ex_rs2_val))) {
                                vlTOPp->top__DOT__load_new_pc = 1U;
                            } else {
                                if (((6U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                                     & (vlTOPp->top__DOT__rr_ex_rs1_val 
                                        < vlTOPp->top__DOT__rr_ex_rs2_val))) {
                                    vlTOPp->top__DOT__load_new_pc = 1U;
                                } else {
                                    if (((7U == (IData)(vlTOPp->top__DOT__rr_ex_func3)) 
                                         & (vlTOPp->top__DOT__rr_ex_rs1_val 
                                            >= vlTOPp->top__DOT__rr_ex_rs2_val))) {
                                        vlTOPp->top__DOT__load_new_pc = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if ((0x6fU == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                    vlTOPp->top__DOT__load_new_pc = 1U;
                } else {
                    if ((0x67U == (IData)(vlTOPp->top__DOT__rr_ex_opcode))) {
                        vlTOPp->top__DOT__load_new_pc = 1U;
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__mem_pipeline_stall) {
        vlTOPp->top__DOT__load_new_pc = 0U;
    }
    vlTOPp->top__DOT__mem__DOT__load_result = 0U;
    if ((3U == (IData)(vlTOPp->top__DOT__ex_mem_opcode))) {
        if ((0U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
            vlTOPp->top__DOT__mem__DOT__load_result 
                = ((0xffffff00U & (VL_NEGATE_I((IData)(
                                                       (1U 
                                                        & (vlTOPp->top__DOT__wb_miso_data 
                                                           >> 7U)))) 
                                   << 8U)) | (0xffU 
                                              & vlTOPp->top__DOT__wb_miso_data));
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
                vlTOPp->top__DOT__mem__DOT__load_result 
                    = ((0xffff0000U & (VL_NEGATE_I((IData)(
                                                           (1U 
                                                            & (vlTOPp->top__DOT__wb_miso_data 
                                                               >> 0xfU)))) 
                                       << 0x10U)) | 
                       (0xffffU & vlTOPp->top__DOT__wb_miso_data));
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
                    vlTOPp->top__DOT__mem__DOT__load_result 
                        = vlTOPp->top__DOT__wb_miso_data;
                } else {
                    if ((4U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
                        vlTOPp->top__DOT__mem__DOT__load_result 
                            = (0xffU & vlTOPp->top__DOT__wb_miso_data);
                    } else {
                        if ((5U == (IData)(vlTOPp->top__DOT__ex_mem_func3))) {
                            vlTOPp->top__DOT__mem__DOT__load_result 
                                = (0xffffU & vlTOPp->top__DOT__wb_miso_data);
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__df_mem_result = vlTOPp->top__DOT__ex_mem_result;
    if (((3U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)) 
         | (0x23U == (IData)(vlTOPp->top__DOT__ex_mem_opcode)))) {
        vlTOPp->top__DOT__df_mem_result = vlTOPp->top__DOT__mem__DOT__load_result;
    }
    vlTOPp->top__DOT__rr__DOT__rs1_val = ((0U == (IData)(vlTOPp->top__DOT__id_rr_sr1_number))
                                           ? 0U : (
                                                   ((IData)(vlTOPp->top__DOT__id_rr_sr1_number) 
                                                    == (IData)(vlTOPp->top__DOT__dest_addr))
                                                    ? vlTOPp->top__DOT__data
                                                    : 
                                                   vlTOPp->top__DOT__reg_file__DOT__reg_file
                                                   [vlTOPp->top__DOT__id_rr_sr1_number]));
    if ((0U != (IData)(vlTOPp->top__DOT__id_rr_sr1_number))) {
        if (((IData)(vlTOPp->top__DOT__id_rr_sr1_number) 
             == (IData)(vlTOPp->top__DOT__rr_ex_rd_number))) {
            if (vlTOPp->top__DOT__df_ex_valid) {
                vlTOPp->top__DOT__rr__DOT__rs1_val 
                    = vlTOPp->top__DOT__df_ex_result;
            }
        } else {
            if (((IData)(vlTOPp->top__DOT__id_rr_sr1_number) 
                 == (IData)(vlTOPp->top__DOT__ex_mem_rd_number))) {
                vlTOPp->top__DOT__rr__DOT__rs1_val 
                    = vlTOPp->top__DOT__df_mem_result;
            }
        }
    }
    if (vlTOPp->top__DOT__load_new_pc) {
        vlTOPp->top__DOT__rr_pipeline_stall = 0U;
    }
    vlTOPp->top__DOT__rr__DOT__pipeline_stall = 0U;
    vlTOPp->top__DOT__rr__DOT__rs2_val = ((0U == (IData)(vlTOPp->top__DOT__id_rr_sr2_number))
                                           ? 0U : (
                                                   ((IData)(vlTOPp->top__DOT__id_rr_sr2_number) 
                                                    == (IData)(vlTOPp->top__DOT__dest_addr))
                                                    ? vlTOPp->top__DOT__data
                                                    : 
                                                   vlTOPp->top__DOT__reg_file__DOT__reg_file
                                                   [vlTOPp->top__DOT__id_rr_sr2_number]));
    if ((0U != (IData)(vlTOPp->top__DOT__id_rr_sr1_number))) {
        if (((IData)(vlTOPp->top__DOT__id_rr_sr1_number) 
             == (IData)(vlTOPp->top__DOT__rr_ex_rd_number))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__df_ex_valid)))) {
                vlTOPp->top__DOT__rr__DOT__pipeline_stall = 1U;
            }
        }
    }
    if (((0U != (IData)(vlTOPp->top__DOT__id_rr_sr2_number)) 
         & (~ (IData)(vlTOPp->top__DOT__rr__DOT__pipeline_stall)))) {
        if (((IData)(vlTOPp->top__DOT__id_rr_sr2_number) 
             == (IData)(vlTOPp->top__DOT__rr_ex_rd_number))) {
            if (vlTOPp->top__DOT__df_ex_valid) {
                vlTOPp->top__DOT__rr__DOT__rs2_val 
                    = vlTOPp->top__DOT__df_ex_result;
            } else {
                vlTOPp->top__DOT__rr__DOT__pipeline_stall = 1U;
            }
        } else {
            if (((IData)(vlTOPp->top__DOT__id_rr_sr2_number) 
                 == (IData)(vlTOPp->top__DOT__ex_mem_rd_number))) {
                vlTOPp->top__DOT__rr__DOT__rs2_val 
                    = vlTOPp->top__DOT__df_mem_result;
            }
        }
    }
    vlTOPp->top__DOT__rr_pipeline_stall = ((IData)(vlTOPp->top__DOT__rr__DOT__pipeline_stall) 
                                           | (IData)(vlTOPp->top__DOT__mem_pipeline_stall));
}

void Vtop::_initial__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__rr__DOT__pipeline_stall = 0U;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    top__DOT__if_id_pc = VL_RAND_RESET_I(32);
    top__DOT__if_id_instruction = VL_RAND_RESET_I(32);
    top__DOT__id_rr_pc = VL_RAND_RESET_I(32);
    top__DOT__id_rr_immediate = VL_RAND_RESET_I(32);
    top__DOT__id_rr_sr1_number = VL_RAND_RESET_I(5);
    top__DOT__id_rr_sr2_number = VL_RAND_RESET_I(5);
    top__DOT__id_rr_rd_number = VL_RAND_RESET_I(5);
    top__DOT__id_rr_func7 = VL_RAND_RESET_I(7);
    top__DOT__id_rr_opcode = VL_RAND_RESET_I(7);
    top__DOT__id_rr_func3 = VL_RAND_RESET_I(3);
    top__DOT__dest_addr = VL_RAND_RESET_I(5);
    top__DOT__data = VL_RAND_RESET_I(32);
    top__DOT__rr_pipeline_stall = VL_RAND_RESET_I(1);
    top__DOT__mem_pipeline_stall = VL_RAND_RESET_I(1);
    top__DOT__load_new_pc = VL_RAND_RESET_I(1);
    top__DOT__new_pc = VL_RAND_RESET_I(32);
    top__DOT__wb2_cyc = VL_RAND_RESET_I(1);
    top__DOT__wb2_stb = VL_RAND_RESET_I(1);
    top__DOT__wb2_ack = VL_RAND_RESET_I(1);
    top__DOT__wb2_miso_data = VL_RAND_RESET_I(32);
    top__DOT__rr_ex_pc = VL_RAND_RESET_I(32);
    top__DOT__rr_ex_rs1_val = VL_RAND_RESET_I(32);
    top__DOT__rr_ex_rs2_val = VL_RAND_RESET_I(32);
    top__DOT__rr_ex_immediate = VL_RAND_RESET_I(32);
    top__DOT__rr_ex_rd_number = VL_RAND_RESET_I(5);
    top__DOT__rr_ex_func7 = VL_RAND_RESET_I(7);
    top__DOT__rr_ex_opcode = VL_RAND_RESET_I(7);
    top__DOT__rr_ex_func3 = VL_RAND_RESET_I(3);
    top__DOT__ex_mem_result = VL_RAND_RESET_I(32);
    top__DOT__ex_mem_pc = VL_RAND_RESET_I(32);
    top__DOT__ex_mem_rs1_val = VL_RAND_RESET_I(32);
    top__DOT__ex_mem_rs2_val = VL_RAND_RESET_I(32);
    top__DOT__ex_mem_immediate = VL_RAND_RESET_I(32);
    top__DOT__ex_mem_rd_number = VL_RAND_RESET_I(5);
    top__DOT__ex_mem_opcode = VL_RAND_RESET_I(7);
    top__DOT__ex_mem_func3 = VL_RAND_RESET_I(3);
    top__DOT__mem_rd = VL_RAND_RESET_I(5);
    top__DOT__df_mem_result = VL_RAND_RESET_I(32);
    top__DOT__df_ex_result = VL_RAND_RESET_I(32);
    top__DOT__df_ex_valid = VL_RAND_RESET_I(1);
    top__DOT__wb_cyc = VL_RAND_RESET_I(1);
    top__DOT__wb_stb = VL_RAND_RESET_I(1);
    top__DOT__wb_we = VL_RAND_RESET_I(1);
    top__DOT__wb_ack = VL_RAND_RESET_I(1);
    top__DOT__wb_sel = VL_RAND_RESET_I(4);
    top__DOT__wb_addr = VL_RAND_RESET_I(30);
    top__DOT__wb_mosi_data = VL_RAND_RESET_I(32);
    top__DOT__wb_miso_data = VL_RAND_RESET_I(32);
    top__DOT__mem_result = VL_RAND_RESET_I(32);
    top__DOT__fetch__DOT__pc = VL_RAND_RESET_I(32);
    top__DOT__fetch__DOT__state = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            top__DOT__reg_file__DOT__reg_file[__Vi0] = VL_RAND_RESET_I(32);
    }}
    top__DOT__id__DOT__branch_offset = VL_RAND_RESET_I(12);
    top__DOT__rr__DOT__pipeline_stall = VL_RAND_RESET_I(1);
    top__DOT__rr__DOT__rs1_val = VL_RAND_RESET_I(32);
    top__DOT__rr__DOT__rs2_val = VL_RAND_RESET_I(32);
    top__DOT__ex__DOT__sign_extended = VL_RAND_RESET_I(32);
    top__DOT__mem__DOT__state = VL_RAND_RESET_I(4);
    top__DOT__mem__DOT__rs1_and_offset = VL_RAND_RESET_I(32);
    top__DOT__mem__DOT__load_result = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<262144; ++__Vi0) {
            top__DOT__my_mem2__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    top__DOT__my_mem__DOT__w_wstb = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<262144; ++__Vi0) {
            top__DOT__my_mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __Vm_traceActivity = 0;
}
