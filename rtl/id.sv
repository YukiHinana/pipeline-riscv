module id (
    input clk,
    input reset,
    input [31:0] i_pc,
    input [31:0] i_instruction,
    input i_pipeline_stall,
    input i_load_new_pc,
    output reg [31:0] o_pc, // for id_buffer
    output reg [4:0] o_rs1_number,
    output reg [4:0] o_rs2_number,
    output reg [4:0] o_rd_number,
    output reg [31:0] o_immediate,
    output reg [6:0] o_func7,
    output reg [2:0] o_func3,
    output reg [6:0] o_opcode,
    output reg o_pipeline_stall
);

always @(*) begin
    o_pipeline_stall = i_pipeline_stall;
end

wire [6:0] opcode;
assign opcode = i_instruction[6:0];

wire [4:0] rs1_number;
wire [4:0] rs2_number;
wire [4:0] rd_number;
assign rs1_number = i_instruction[19:15];
assign rs2_number = i_instruction[24:20];
assign rd_number = i_instruction[11:7];

wire [2:0] func3;
assign func3 = i_instruction[14:12];
wire [6:0] func7;
assign func7 = i_instruction[31:25];


localparam  ALU = 7'b0110011, //ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND
            ALUI = 7'b0010011, //ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI
            LOAD = 7'b0000011,
            STORE = 7'b0100011,
            BRANCH = 7'b1100011,
            JAL = 7'b1101111,
            JALR = 7'b1100111,
            AUIPC = 7'b0010111,
            LUI = 7'b0110111;

wire is_alu = (opcode == ALU);
wire is_alui = (opcode == ALUI);
wire is_load = (opcode == LOAD);
wire is_store = (opcode == STORE);
wire is_branch = (opcode == BRANCH);
wire is_jal = (opcode == JAL);
wire is_jalr = (opcode == JALR);
wire is_auipc = (opcode == AUIPC);
wire is_lui = (opcode == LUI);

wire [11:0] branch_offset = {i_instruction[31], i_instruction[7], i_instruction[30:25], i_instruction[11:8]};
wire [31:0] sign_extended_branch_offset = {{19{branch_offset[11]}}, branch_offset, 1'b0};

always @ (posedge clk) begin
    if (reset) begin
        o_pc <= 0;
        o_rs1_number <= 0;
        o_rs2_number <= 0;
        o_rd_number <= 0;
        o_immediate <= 0;
        o_func7 <= 0;
        o_func3 <= 0;
        o_opcode <= 0;
    end
    else if (o_pipeline_stall == 0) begin
        o_pc <= i_pc;
        o_opcode <= opcode;
        o_rs1_number <= 0;
        o_rs2_number <= 0;
        o_rd_number <= 0;
        o_immediate <= 0;
        o_func7 <= 0;
        o_func3 <= 0;
        // no func3 for JAL, LUI, and AUIPC
        if (!is_jal && !is_lui && !is_auipc)
            o_func3 <= func3;
        if (is_alui || is_load) begin // ALUI, LOAD
            if (is_alui && (func3 == 3'b001 || func3 == 3'b101)) begin
                // has 5-bit shift amount
                o_immediate <= {28'h0, i_instruction[24:20]};
                o_func7 <= func7;
            end
            else
                // 12-bit immediate
                o_immediate <= {20'h0, i_instruction[31:20]};
            o_rs1_number <= rs1_number;
            o_rd_number <= rd_number;
        end
        else if (is_alu || is_store) begin // ALU, STORE
            if (is_store)
                o_immediate <= {20'h0, i_instruction[31:25], i_instruction[11:7]};
            else if (is_alu) begin
                o_func7 <= func7;
                o_rd_number <= rd_number;
            end
            o_rs2_number <= rs2_number;
            o_rs1_number <= rs1_number;
        end
        else if (is_branch) begin // BRANCH
            o_immediate <= sign_extended_branch_offset;
            o_rs2_number <= rs2_number;
            o_rs1_number <= rs1_number;
            o_func3 <= func3;
        end
        else if (is_jal) begin // JAL
            o_immediate <= {{11{i_instruction[31]}}, i_instruction[31], i_instruction[19:12], i_instruction[20], i_instruction[30:21], 1'b0};
            o_rd_number <= rd_number;
        end
        else if (is_jalr) begin // JALR
            o_immediate <= {{20{i_instruction[31]}}, i_instruction[31:20]};
            o_rd_number <= rd_number;
            o_rs1_number <= rs1_number;
            o_func3 <= func3;
        end
        else if (is_lui || is_auipc) begin // LUI, AUIPC
            o_immediate <= {i_instruction[31:12], 12'b0};
            o_rd_number <= rd_number;
        end
    end
    if (i_load_new_pc == 1) begin
        o_pc <= 0;
        o_rs1_number <= 0;
        o_rs2_number <= 0;
        o_rd_number <= 0;
        o_immediate <= 0;
        o_func7 <= 0;
        o_func3 <= 0;
        o_opcode <= 0;
    end
end
    
endmodule