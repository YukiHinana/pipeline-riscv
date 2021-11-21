module dual_port_reg_file (
    input clk,
    input write,
    input [4:0] dest_addr, // 32 regs
    input [31:0] data,
    input [4:0] a_addr,
    output reg [31:0] a_output,
    input [4:0] b_addr,
    output reg [31:0] b_output
);

reg [31:0] reg_file [0:31]; // 32 regs, 32-bit/reg

always @ (posedge clk) begin
    if (write == 1) begin
        reg_file[dest_addr] <= data;
    end
end

always @ * begin
    if (a_addr == 5'h0) begin
        a_output = 5'h0;
    end
    else begin
        a_output = reg_file[a_addr];
    end
end

always @ * begin
    if (b_addr == 5'h0) begin
        b_output = 5'h0;
    end
    else begin
        b_output = reg_file[b_addr];
    end
end
    
endmodule