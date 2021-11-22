module ex (
    input clk,
    input reset,
    input [31:0] pc,
    input [31:0] rs1_val,
    input [31:0] rs2_val,
    input [4:0] rd_number,
    input [31:0] immediate,
    input [6:0] func7,
    input [2:0] func3,
    input [6:0] opcode,
    output reg [4:0] rd_number_out,
    output reg [31:0] result_out,
    output reg [31:0] pc_out,
    output reg [31:0] rs1_val_out,
    output reg [31:0] rs2_val_out,
    output reg [31:0] immediate_out,
    output reg [6:0] opcode_out,
    output reg [2:0] func3_out
);

localparam  ALU = 7'b0110011, //ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND
            ALUI = 7'b0010011; //ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI

wire [31:0] sign_extended = {{20{immediate[11]}}, immediate[11:0]};

always @(posedge clk) begin
    if (reset) begin
        rd_number_out <= 0;
        result_out <= 0;
        pc_out <= 0;
        rs1_val_out <= 0;
        rs2_val_out <= 0;
        immediate_out <= 0;
        opcode_out <= 0;
        func3_out <= 0;
    end
    else begin
        rd_number_out <= rd_number;
        pc_out <= pc;
        rs1_val_out <= rs1_val;
        rs2_val_out <= rs2_val;
        immediate_out <= immediate;
        opcode_out <= opcode;
        func3_out <= func3;
        if (opcode == ALU) begin
            if (func7 == 7'b0100000) begin
                case (func3)
                    3'b000 : result_out <= $signed(rs1_val) - $signed(rs2_val); // SUB
                    3'b101 : result_out <= $signed(rs1_val) >>> rs2_val[4:0];
                endcase
            end
            else if (func7 == 7'b0000000) begin
                // ADD
                if (func3 == 3'b000) begin
                    result_out <= rs1_val + rs2_val;
                end
                // SLL (shift left logical)
                if (func3 == 3'b001) begin
                    result_out <= rs1_val << rs2_val[4:0];
                end
                // SLT (1 to rd if rs1 < rs2)
                else if (func3 == 3'b010) begin
                    if ($signed(rs1_val) < $signed(rs2_val)) begin
                        result_out <= 1;
                    end
                    else begin
                        result_out <= 0;
                    end
                end
                // SLTU (unsigned compare)
                else if (func3 == 3'b011) begin
                    if (rs1_val < rs2_val) begin
                        result_out <= 1;
                    end
                    else begin
                        result_out <= 0;
                    end
                end
                // XOR
                else if (func3 == 3'b100) begin
                    result_out <= rs1_val ^ rs2_val;
                end
                // SRL (shift logical right)
                else if (func3 == 3'b101) begin
                    result_out <= rs1_val >> rs2_val[4:0];
                end
                // OR
                else if (func3 == 3'b110) begin
                    result_out <= rs1_val | rs2_val;
                end
                // AND
                else if (func3 == 3'b111) begin
                    result_out <= rs1_val & rs2_val;
                end
            end
        end
        else if (opcode == ALUI) begin
            case (func3)
                3'b000 : result_out <= rs1_val + sign_extended; // ADDI
                3'b010 : begin // SLTI
                    if ($signed(rs1_val) < $signed(sign_extended))
                        result_out <= 1;
                    else
                        result_out <= 0;
                end
                3'b011 : begin // SLTIU
                    if (rs1_val < sign_extended)
                        result_out <= 1;
                    else
                        result_out <= 0;
                end
            endcase
        end
    end
end
    
endmodule