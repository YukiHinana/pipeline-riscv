module fetch (
    input   clk,
    input   reset,
    output  reg [31:0] instruction_out,
    output  reg [31:0] pc_out
);

reg [31:0] pc;
reg [31:0] i_mem [0:16383]; // 14 bit mem depth

always @ (posedge clk) begin
    if (reset) begin
        pc <= 0;
        instruction_out <= 0;
        pc_out <= 0;
    end
    else begin
        instruction_out <= i_mem[pc[15:2]];
        pc_out <= pc;
        pc <= pc + 4;
    end
end
    
endmodule