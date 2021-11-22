module mem (
    input clk,
    input reset,
    input [4:0] rd_number,
    input [31:0] result,
    input [31:0] pc,
    input [31:0] rs1_val,
    input [31:0] rs2_val,
    input [31:0] immediate,
    input [6:0] opcode,
    input [2:0] func3,
    input i_wb_ack,
    input [31:0] i_wb_data,
    input i_wb_stall,
    output reg o_wb_cycle,
    output reg o_wb_stb,
    output reg o_wb_we,
    output reg [3:0] o_wb_sel,
    output reg [29:0] o_wb_addr,
    output reg [31:0] o_wb_data,
    output reg [31:0] result_out,
    output reg [31:0] rd_val_out,
    output reg o_pipeline_stall
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

wire [31:0] sign_extended_imm = {{20{immediate[11]}}, immediate[11:0]};
wire [31:0] rs1_and_offset = rs1_val + sign_extended_imm;

always @(posedge clk) begin
    if (reset) begin
        state <= IDLE;
    end
    else begin
        if (opcode == STORE || opcode == LOAD) begin
            state <= REQUEST;
            o_wb_cycle <= 1;
            o_wb_stb <= 1;
            if (opcode == LOAD) begin
                o_wb_addr <= rs1_and_offset;
                case (func3)
                    FUNC3_BYTE : o_wb_sel <= 4'b0001 << rs1_and_offset[1:0]; //LB
                    FUNC3_HALF : o_wb_sel <= 4'b0011 << rs1_and_offset[1:0]; //LH
                    FUNC3_WORD : o_wb_sel <= 4'b1111;
            end
            if (opcode == STORE) begin
                o_wb_we <= 1;
            end
        end
    end
end


reg [31:0] d_mem [0:16383]; // 14 bit depth

wire [4:0] remainder_byte = rs1_and_offset[1:0] * 8;
wire [4:0] remainder_half_word = rs1_and_offset[1:0] * 16;

always @ (posedge clk) begin
    if (reset) begin
        result_out <= 0;
        rd_val_out <= 0;
    end
    else begin
        result_out <= result;
        if (opcode == 7'b0000011) begin
            case (func3)
                3'b000 : rd_val_out <= {d_mem[rs1_and_offset[15:2]][remainder_byte+7:remainder_byte]}; //LB
                3'b001 : rd_val_out <= d_mem[rs1_and_offset[15:2]][remainder_half_word+15:remainder_half_word]; //LH
                3'b010 : rd_val_out <= d_mem[rs1_and_offset[15:2]]; //LW
                3'b100 : rd_val_out <= 
        end
    end
end
    
endmodule