module top (
    input clk,
    input reset
);

    wire [31:0] if_id_pc, if_id_instruction;

    wire [31:0] id_rr_pc, id_rr_immediate;
    wire [4:0] id_rr_sr1_number, id_rr_sr2_number, id_rr_rd_number;
    wire [6:0] id_rr_func7, id_rr_opcode;
    wire [2:0] id_rr_func3;

    wire write = 1;
    wire [4:0] dest_addr;
    wire [31:0] data, reg_file_rr_a_val, reg_file_rr_b_val;

    fetch fetch (.clk, .reset, 
                .instruction_out(if_id_instruction), 
                .pc_out(if_id_pc));

    dual_port_reg_file reg_file (.clk, .write, .dest_addr,
                                .data, .a_addr(id_rr_sr1_number), 
                                .b_addr(id_rr_sr2_number), 
                                .a_output(reg_file_rr_a_val), 
                                .b_output(reg_file_rr_b_val));

    id id (.clk, .reset, .pc(if_id_pc), 
            .instruction(if_id_instruction), 
            .pc_out(id_rr_pc), .rs1_number_out(id_rr_sr1_number), 
            .rs2_number_out(id_rr_sr2_number), 
            .rd_number_out(id_rr_rd_number), 
            .immediate_out(id_rr_immediate), 
            .func7_out(id_rr_func7), .func3_out(id_rr_func3), 
            .opcode_out(id_rr_opcode));

    wire [31:0] rr_ex_pc, rr_ex_rs1_val, rr_ex_rs2_val, rr_ex_immediate;
    wire [4:0] rr_ex_rd_number;
    wire [6:0] rr_ex_func7, rr_ex_opcode;
    wire [2:0] rr_ex_func3;

    rr rr (.clk, .reset, .pc(id_rr_pc), 
            .rs1_number(id_rr_sr1_number), 
            .rs2_number(id_rr_sr2_number), 
            .rd_number(id_rr_rd_number), 
            .immediate(id_rr_immediate), .func7(id_rr_func7), 
            .func3(id_rr_func3), .a_val(reg_file_rr_a_val), 
            .b_val(reg_file_rr_b_val), .opcode(id_rr_opcode), 
            .pc_out(rr_ex_pc), .rs1_val_out(rr_ex_rs1_val), 
            .rs2_val_out(rr_ex_rs2_val), .rd_number_out(rr_ex_rd_number), 
            .immediate_out(rr_ex_immediate), .func7_out(rr_ex_func7), 
            .func3_out(rr_ex_func3), .opcode_out(rr_ex_opcode));

    ex ex (.clk, .reset, .pc(rr_ex_pc), 
            .rs1_val(rr_ex_rs1_val), .rs2_val(rr_ex_rs2_val), 
            .rd_number(rr_ex_rd_number), .immediate(rr_ex_immediate), 
            .func7(rr_ex_func7), .func3(rr_ex_func3), 
            .opcode(rr_ex_opcode), .rd_number_out(dest_addr), 
            .result_out(data));
endmodule