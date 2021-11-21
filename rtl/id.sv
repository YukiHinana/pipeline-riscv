module id (
    input clk,
    input reset,
    input [31:0] pc,
    input [31:0] instruction,
    output reg [31:0] pc_out,
    output reg [4:0] rs1_number_out,
    output reg [4:0] rs2_number_out,
    output reg [4:0] rd_number_out,
    output reg [31:0] immediate_out,
    output reg [6:0] func7_out,
    output reg [2:0] func3_out,
    output reg [6:0] opcode_out
);

wire [6:0] opcode;
assign opcode = instruction[6:0];

wire [4:0] rs1_number;
wire [4:0] rs2_number;
wire [4:0] rd_number;
assign rs1_number = instruction[19:15];
assign rs2_number = instruction[24:20];
assign rd_number = instruction[11:7];

wire [2:0] func3;
assign func3 = instruction[14:12];


localparam  ALU = 7'b0110011, //ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND
            ALUI = 7'b0010011; //ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI

always @ (posedge clk) begin
    if (reset) begin
        pc_out <= 0;
        rs1_number_out <= 0;
        rs2_number_out <= 0;
        rd_number_out <= 0;
        immediate_out <= 0;
        func7_out <= 0;
        func3_out <= 0;
        opcode_out <= 0;
    end
    else begin
        pc_out <= pc;
        opcode_out <= opcode;
        if (opcode == ALU || opcode == ALUI) begin
            rs1_number_out <= rs1_number;
            func3_out <= func3;    
            rd_number_out <= rd_number;
        end
        if (opcode == ALU) begin
            func7_out <= instruction[31:25];
            rs2_number_out <= rs2_number;
        end
        else if (opcode == ALUI) begin
            if (func3 == 3'b001 || func3 == 3'b101) begin
                func7_out <= instruction[31:25];
                rs2_number_out <= rs2_number;
            end
            else begin
                immediate_out <= {20'h0,instruction[31:20]};
            end
        end
    end
end
    
endmodule