`default_nettype none

module mem (
    input clk,
    input reset,
    input [4:0] i_rd_number,
    input [31:0] i_result,
    input [31:0] i_pc,
    input [31:0] i_rs1_val,
    input [31:0] i_rs2_val,
    input [31:0] i_immediate,
    input [6:0] i_opcode,
    input [2:0] i_func3,
    input i_wb_ack,
    input [31:0] i_wb_data,
    input i_wb_stall,
    output reg [4:0] o_mem_rd_number, // data forwarding
    output reg [31:0] o_mem_result,
    output reg o_mem_valid,
    output reg o_wb_cycle, // wb bus
    output reg o_wb_stb,
    output reg o_wb_we,
    output reg [3:0] o_wb_sel,
    output reg [29:0] o_wb_addr,
    output reg [31:0] o_wb_data,
    output reg [4:0] o_rd_number, // for mem_buffer
    output reg [31:0] o_result,
    //output reg [31:0] o_rd_val,
    output reg o_pipeline_stall // to ex
);

reg [3:0] state;

localparam  IDLE = 0,
            REQUEST = 1,
            WAIT = 2;

localparam  STORE = 7'b0100011, 
            LOAD = 7'b0000011;

localparam  FUNC3_BYTE = 3'b000,
            FUNC3_HALF = 3'b001,
            FUNC3_WORD = 3'b010,
            FUNC3_BYTE_UNSIGNED = 3'b100,
            FUNC3_HALF_UNSIGNED = 3'b101;

wire [31:0] sign_extended_imm = {{20{i_immediate[11]}}, i_immediate[11:0]};
wire [31:0] rs1_and_offset = i_rs1_val + sign_extended_imm;

wire is_byte = (i_func3 == FUNC3_BYTE);
wire is_half = (i_func3 == FUNC3_HALF);
wire is_word = (i_func3 == FUNC3_WORD);
wire is_byte_unsigned = (i_func3 == FUNC3_BYTE_UNSIGNED);
wire is_half_unsigned = (i_func3 == FUNC3_HALF_UNSIGNED);
wire is_load = (i_opcode == LOAD);
wire is_store = (i_opcode == STORE);

reg [31:0] load_result;
wire [5:0] data_shft_amt = {3'b0, rs1_and_offset[1:0]};

always @(*) begin
    o_pipeline_stall = 0;
    o_mem_valid = 1;
    o_mem_result = i_result;
    o_mem_rd_number = i_rd_number;
    if (is_load || is_store) begin
        o_pipeline_stall = 1;
        o_mem_result = load_result;
    end
    if (o_wb_cycle && i_wb_ack) //
        o_pipeline_stall = 0;
end

always @(posedge clk) begin
    if (reset) begin
        state <= IDLE;
        o_wb_cycle <= 0;
        o_wb_stb <= 0;
    end
    else if (is_store || is_load) begin
        if (state == IDLE && (is_store || is_load)) begin
            state <= REQUEST;
            o_wb_cycle <= 1;
            o_wb_stb <= 1;
            o_wb_we <= 0;
            o_wb_addr <= rs1_and_offset[31:2];
            if (is_load) begin
                o_wb_sel <= 4'b1111;
            end
            else if (is_store) begin
                o_wb_we <= 1;
                if (is_byte) begin
                    o_wb_sel <= 4'b0001 << rs1_and_offset[1:0];
                    o_wb_data <= {24'b0, i_rs2_val[7:0]} << (data_shft_amt << 3); //SB
                end
                else if (is_half) begin
                    o_wb_sel <= 4'b0011 << rs1_and_offset[1:0];
                    o_wb_data <= {16'b0, i_rs2_val[15:0]} << (data_shft_amt << 3); //SH
                end
                else if (is_word) begin
                    o_wb_sel <= 4'b1111;
                    o_wb_data <= i_rs2_val; //SW
                end
            end
        end
        else if (state == REQUEST) begin
            if (i_wb_ack == 1 && i_wb_stall == 0) begin
                state <= IDLE;
                o_wb_cycle <= 0;
                o_wb_stb <= 0;
                o_result <= load_result;
            end
            else if (i_wb_stall == 0) begin
                state <= WAIT;
                o_wb_cycle <= 1;
                o_wb_stb <= 0;
            end
        end
        else if (state == WAIT) begin
            if (i_wb_ack == 1) begin
                state <= IDLE;
                o_wb_cycle <= 0;
                o_wb_stb <= 0;
                o_result <= load_result;
            end
        end
    end 
    else begin
        o_result <= i_result;
        o_rd_number <= i_rd_number;
    end
    if (o_pipeline_stall) begin
        o_rd_number <= 0;
        o_result <= 0;
    end else 
        o_rd_number <= i_rd_number;
end

wire [31:0] a = i_wb_data >> (data_shft_amt << 3);
always @* begin
    load_result = 0;
    if (is_load) begin
        if (is_byte) begin
            load_result = {{24{a[7]}}, a[7:0]};
        end
        else if (is_half) begin
            load_result = {{16{a[15]}}, a[15:0]};
        end
        else if (is_word) begin
            load_result = a;
        end
        else if (is_byte_unsigned) begin
            load_result = {24'b0, a[7:0]};
        end
        else if (is_half_unsigned) begin
            load_result = {16'b0, a[15:0]};
        end
    end
end

//reg [31:0] d_mem [0:16383]; // 14 bit depth
endmodule