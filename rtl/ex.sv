module ex (
    input clk,
    input reset,
    input [31:0] i_pc,
    input [31:0] i_rs1_val,
    input [31:0] i_rs2_val,
    input [4:0] i_rd_number,
    input [31:0] i_immediate,
    input [6:0] i_func7,
    input [2:0] i_func3,
    input [6:0] i_opcode,
    input i_pipeline_stall, // from mem
    output reg [4:0] o_ex_rd_number, // forward to rr
    output reg [31:0] o_ex_result,
    output reg o_ex_valid,
    output reg [4:0] o_rd_number, // for ex_buffer
    output reg [31:0] o_result,
    output reg o_load_new_pc,
    output reg [31:0] o_new_pc,
    output reg [31:0] o_pc,
    output reg [31:0] o_rs1_val,
    output reg [31:0] o_rs2_val,
    output reg [31:0] o_immediate,
    output reg [6:0] o_opcode,
    output reg [2:0] o_func3,
    output reg o_pipeline_stall // to rr
);

reg pipeline_stall = 0;

localparam  ALU = 7'b0110011, //ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND
            ALUI = 7'b0010011, //ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI
            LOAD = 7'b0000011,
            STORE = 7'b0100011,
            BRANCH = 7'b1100011,
            JAL = 7'b1101111,
            JALR = 7'b1100111,
            AUIPC = 7'b0010111,
            LUI = 7'b0110111;

localparam  ADD = 3'b000, 
            SUB = 3'b000, 
            SLL = 3'b001, 
            SLT = 3'b010, 
            SLTU = 3'b011, 
            XOR = 3'b100, 
            SRL = 3'b101, 
            SRA = 3'b101, 
            OR = 3'b110, 
            AND = 3'b111;

localparam  ADDI = 3'b000,
            SLTI = 3'b010,
            SLTIU = 3'b011,
            XORI = 3'b100,
            ORI = 3'b110,
            ANDI = 3'b111,
            SLLI = 3'b001,
            SRLI = 3'b101,
            SRAI = 3'b101;

localparam  BEQ = 3'b000,
            BNE = 3'b001, 
            BLT = 3'b100, 
            BGE = 3'b101, 
            BLTU = 3'b110, 
            BGEU = 3'b111;

wire is_alu = (i_opcode == ALU);
wire is_alui = (i_opcode == ALUI);
wire is_load = (i_opcode == LOAD);
wire is_store = (i_opcode == STORE);
wire is_branch = (i_opcode == BRANCH);
wire is_jal = (i_opcode == JAL);
wire is_jalr = (i_opcode == JALR);
wire is_auipc = (i_opcode == AUIPC);
wire is_lui = (i_opcode == LUI);

wire [31:0] sign_extended = {{20{i_immediate[11]}}, i_immediate[11:0]};

always @(*) begin
    o_ex_result = 0;
    o_ex_valid = 0;
    o_pipeline_stall = pipeline_stall | i_pipeline_stall;
    o_ex_rd_number = i_rd_number;
    o_load_new_pc = 0;
    o_new_pc = i_pc + i_immediate;
    if (is_alu || is_alui) 
        o_ex_valid = 1;
    if (is_alu) begin //ALU
        if (i_func7 == 7'b0100000) begin
            // SUB
            if (i_func3 == SUB) 
                o_ex_result = $signed(i_rs1_val) - $signed(i_rs2_val);
            // SRA
            if (i_func3 == SRA)
                o_ex_result = $signed(i_rs1_val) >>> i_rs2_val[4:0];
        end
        else if (i_func7 == 7'b0000000) begin
            // ADD
            if (i_func3 == ADD)
                o_ex_result = i_rs1_val + i_rs2_val;
            // SLL (shift left logical)
            else if (i_func3 == SLL)
                o_ex_result = i_rs1_val << i_rs2_val[4:0];
            // SLT (1 to rd if rs1 < rs2)
            else if (i_func3 == SLT) begin
                if ($signed(i_rs1_val) < $signed(i_rs2_val))
                    o_ex_result = 1;
                else
                    o_ex_result = 0;
            end
            // SLTU (unsigned compare)
            else if (i_func3 == SLTU) begin
                if (i_rs1_val < i_rs2_val)
                    o_ex_result = 1;
                else
                    o_ex_result = 0;
            end
            // XOR
            else if (i_func3 == XOR)
                o_ex_result = i_rs1_val ^ i_rs2_val;
            // SRL (shift logical right)
            else if (i_func3 == SRL)
                o_ex_result = i_rs1_val >> i_rs2_val[4:0];
            // OR
            else if (i_func3 == OR)
                o_ex_result = i_rs1_val | i_rs2_val;
            // AND
            else if (i_func3 == AND)
                o_ex_result = i_rs1_val & i_rs2_val;
        end
    end
    else if (is_alui) begin //ALUI
        // ADDI
        if (i_func3 == ADDI)
            o_ex_result = i_rs1_val + sign_extended;
        // SLTI
        else if (i_func3 == SLTI) begin
            if ($signed(i_rs1_val) < $signed(sign_extended))
                o_ex_result = 1;
            else
                o_ex_result = 0;
        end
        // SLTIU
        else if (i_func3 == SLTIU) begin
            if (i_rs1_val < sign_extended)
                o_ex_result = 1;
            else
                o_ex_result = 0;
        end
        // XORI
        else if (i_func3 == XORI) begin
            o_ex_result = sign_extended ^ i_rs1_val;
        end
        // ORI
        else if (i_func3 == ORI) begin
            o_ex_result = sign_extended | i_rs1_val;
        end
        // ANDI
        else if (i_func3 == ANDI) begin
            o_ex_result = sign_extended & i_rs1_val;
        end
        // SLLI
        else if (i_func3 == SLLI) begin
            o_ex_result = i_rs1_val << i_immediate[4:0];
        end
        // SRLI, SRAI
        else if (i_func3 == SRLI || i_func3 == SRAI) begin
            if (i_func7 == 7'b0000000) begin // SRLI
                o_ex_result = i_rs1_val >> i_immediate[4:0];
            end
            else if (i_func7 == 7'b0100000) begin // SRAI
                o_ex_result = $signed(i_rs1_val) >>> i_immediate[4:0];
            end
        end
    end
    else if (is_branch) begin // BRANCH
        // BEQ
        if (i_func3 == BEQ && (i_rs1_val == i_rs2_val)) begin
            o_load_new_pc = 1;
        end
        // BNE
        else if (i_func3 == BNE && (i_rs1_val != i_rs2_val)) begin
            o_load_new_pc = 1;
        end
        // BLT
        else if (i_func3 == BLT && 
                    ($signed(i_rs1_val) < $signed(i_rs2_val))) begin
            o_load_new_pc = 1;
        end
        // BGE
        else if (i_func3 == BGE && 
                    ($signed(i_rs1_val) >= $signed(i_rs2_val))) begin
            o_load_new_pc = 1;
        end
        // BLTU
        else if (i_func3 == BLTU && (i_rs1_val < i_rs2_val)) begin
            o_load_new_pc = 1;
        end
        // BGEU
        else if (i_func3 == BGEU && (i_rs1_val >= i_rs2_val)) begin
            o_load_new_pc = 1;
        end
    end
    else if (is_jal) begin // JAL
        // sign-extended offset + pc
        o_load_new_pc = 1;
        // save current pc + 4 into rd
        o_ex_result = i_pc + 4;
    end
    else if (is_jalr) begin // JALR
        o_load_new_pc = 1;
        o_new_pc = i_immediate + i_rs1_val;
        o_new_pc = {o_new_pc[31:1], 1'b0};
        o_ex_result = i_pc + 4;
    end
    else if (is_lui) begin // LUI
        o_ex_result = i_immediate;
    end
    else if (is_auipc) begin // AUIPC
        o_ex_result = i_immediate + i_pc;
    end

    if(i_pipeline_stall) begin
        o_load_new_pc = 0;
    end
end

always @(posedge clk) begin
    o_result <= 0;
    if (reset) begin
        o_rd_number <= 0;
        o_result <= 0;
        o_pc <= 0;
        o_rs1_val <= 0;
        o_rs2_val <= 0;
        o_immediate <= 0;
        o_opcode <= 0;
        o_func3 <= 0;
    end
    else if (pipeline_stall == 0 && i_pipeline_stall == 0) begin
        o_rd_number <= i_rd_number;
        o_pc <= i_pc;
        o_rs1_val <= i_rs1_val;
        o_rs2_val <= i_rs2_val;
        o_immediate <= i_immediate;
        o_opcode <= i_opcode;
        o_func3 <= i_func3;
        o_result <= o_ex_result;
    end
end
    
endmodule