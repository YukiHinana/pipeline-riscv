module rr (
    input clk,
    input reset,
    input [31:0] i_pc, // from id
    input [4:0] i_rs1_number,
    input [4:0] i_rs2_number,
    input [4:0] i_rd_number,
    input [31:0] i_immediate,
    input [6:0] i_func7,
    input [2:0] i_func3,
    input [31:0] i_a_val, // from dprf
    input [31:0] i_b_val,
    input [6:0] i_opcode,
    input i_pipeline_stall, // from ex
    input [4:0] i_ex_buf_rd_number, // for stall
    input [4:0] i_mem_buf_rd_number,
    input [4:0] i_ex_rd_number, // data forwarding
    input [31:0] i_ex_result,
    input i_ex_valid,
    input [4:0] i_mem_rd_number,
    input [31:0] i_mem_result,
    input i_mem_valid,
    input i_load_new_pc,
    output reg [31:0] o_pc, // for rr_buffer
    output reg [31:0] o_rs1_val,
    output reg [31:0] o_rs2_val,
    output reg [4:0] o_rd_number,
    output reg [31:0] o_immediate,
    output reg [6:0] o_func7,
    output reg [2:0] o_func3,
    output reg [6:0] o_opcode,
    output reg o_pipeline_stall // to id
);

reg pipeline_stall = 0;
reg [31:0] rs1_val;
reg [31:0] rs2_val;

always @(*) begin
    if (i_load_new_pc == 1) begin
        o_pipeline_stall = 0;
    end
    pipeline_stall = 0;
    rs1_val = i_a_val;
    rs2_val = i_b_val;

    if (i_rs1_number != 0) begin
        if (i_rs1_number == i_ex_rd_number) begin
            if (i_ex_valid) 
                rs1_val = i_ex_result;
            else
                pipeline_stall = 1;
        end
        else if (i_rs1_number == i_mem_rd_number) begin
            if (i_mem_valid)
                rs1_val = i_mem_result;
            else
                pipeline_stall = 1;
        end
            // rs1_val = 0;
            // rs2_val = 0;
    end
    if (i_rs2_number != 0 && !pipeline_stall) begin
        if (i_rs2_number == i_ex_rd_number) begin
            if (i_ex_valid)
                rs2_val = i_ex_result;
            else 
                pipeline_stall = 1;
        end
        else if (i_rs2_number == i_mem_rd_number) begin
            if (i_mem_valid)
                rs2_val = i_mem_result;
            else
                pipeline_stall = 1;
        end
    end
    o_pipeline_stall = pipeline_stall | i_pipeline_stall;
end

always @(posedge clk) begin
    if (reset) begin
        o_pc <= 0;
        o_rs1_val <= 0;
        o_rs2_val <= 0;
        o_rd_number <= 0;
        o_immediate <= 0;
        o_func7 <= 0;
        o_func3 <= 0;
        o_opcode <= 0;
    end
    else if (o_pipeline_stall == 0) begin
        o_pc <= i_pc;
        o_rs1_val <= rs1_val;
        o_rs2_val <= rs2_val;
        o_rd_number <= i_rd_number;
        o_immediate <= i_immediate;
        o_func7 <= i_func7;
        o_func3 <= i_func3;
        o_opcode <= i_opcode;
    end
    else if (pipeline_stall && !i_pipeline_stall) begin
        o_pc <= 0;
        o_rs1_val <= 0;
        o_rs2_val <= 0;
        o_rd_number <= 0;
        o_immediate <= 0;
        o_func7 <= 0;
        o_func3 <= 0;
        o_opcode <= 0;
    end
    if (i_load_new_pc == 1) begin
        o_pc <= 0;
        o_rs1_val <= 0;
        o_rs2_val <= 0;
        o_rd_number <= 0;
        o_immediate <= 0;
        o_func7 <= 0;
        o_func3 <= 0;
        o_opcode <= 0;
    end
end
    
endmodule