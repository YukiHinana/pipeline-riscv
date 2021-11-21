module rr (
    input clk,
    input reset,
    input [31:0] pc, // from id
    input [4:0] rs1_number,
    input [4:0] rs2_number,
    input [4:0] rd_number,
    input [31:0] immediate,
    input [6:0] func7,
    input [2:0] func3,
    input [31:0] a_val, // from dprf
    input [31:0] b_val,
    input [6:0] opcode,
    output reg [31:0] pc_out,
    output reg [31:0] rs1_val_out,
    output reg [31:0] rs2_val_out,
    output reg [4:0] rd_number_out,
    output reg [31:0] immediate_out,
    output reg [6:0] func7_out,
    output reg [2:0] func3_out,
    output reg [6:0] opcode_out
);

always @ (posedge clk) begin
    if (reset) begin
        pc_out <= 0;
        rs1_val_out <= 0;
        rs2_val_out <= 0;
        rd_number_out <= 0;
        immediate_out <= 0;
        func7_out <= 0;
        func3_out <= 0;
        opcode_out <= 0;
    end
    else begin
        pc_out <= pc;
        rs1_val_out <= a_val;
        rs2_val_out <= b_val;
        rd_number_out <= rd_number;
        immediate_out <= immediate;
        func7_out <= func7;
        func3_out <= func3;
        opcode_out <= opcode;
    end
end
    
endmodule