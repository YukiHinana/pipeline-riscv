module fetch (
    input clk,
    input reset,
    input i_pipeline_stall,
    input i_load_new_pc,
    input [31:0] i_new_pc,
    input i_wb_ack,
    input [31:0] i_wb_data,
    input i_wb_stall,
    output reg [31:0] o_instruction,
    output reg [31:0] o_pc,
    output reg o_wb_cycle, // wb bus
    output reg o_wb_stb,
    output reg o_wb_we,
    output reg [3:0] o_wb_sel,
    output reg [29:0] o_wb_addr,
    output reg [31:0] o_wb_data
);

reg [31:0] pc;
//reg [31:0] i_mem [0:16383]; // 14 bit mem depth

reg [3:0] state;

localparam  IDLE = 0,
            REQUEST = 1,
            WAIT = 2;

always @ (posedge clk) begin
    if (reset) begin
        pc <= 0;
        o_instruction <= 0;
        o_pc <= 0;
        state <= IDLE;
    end
    else begin
        if (i_pipeline_stall == 0) begin
            o_pc <= 0;
            o_instruction <= 0;
        end

        if (i_pipeline_stall == 0 && i_load_new_pc) begin
            o_pc <= 0;
            o_instruction <= 0;
            pc <= i_new_pc;
            state <= REQUEST;
        end

        if (state == IDLE && !i_pipeline_stall) begin
            state <= REQUEST;
        end
        else if (state == REQUEST) begin
            if (i_wb_ack == 1 && i_wb_stall == 0) begin
                state <= IDLE;
                if (!i_pipeline_stall) begin
                    state <= REQUEST;
                    o_pc <= pc;
                    pc <= pc + 4;
                    o_instruction <= i_wb_data;
                end
            end
            else if (i_wb_stall == 0) begin
                state <= WAIT;
            end
        end
        else if (state == WAIT) begin
            if (i_wb_ack == 1) begin
                state <= IDLE;
                if (!i_pipeline_stall) begin
                    state <= REQUEST;
                    o_pc <= pc;
                    pc <= pc + 4;
                    o_instruction <= i_wb_data;
                end
            end
        end
    end
    if (i_load_new_pc == 1) begin
        pc <= i_new_pc;
        o_pc <= 0;
        o_instruction <= 0;
        state <= IDLE;
    end
end

always @* begin
    o_wb_cycle = 0;
    o_wb_stb = 0;
    o_wb_we = 0;
    o_wb_addr = pc[31:2];
    o_wb_data = 0;
    o_wb_sel = 4'b1111;
    if (state == REQUEST) begin
        o_wb_cycle = 1;
        o_wb_stb = 1;
    end   
    else if (state == WAIT) begin
        o_wb_cycle = 1;
    end 
end
    
endmodule