module dual_port_reg_file (
    input clk,
    //input write,
    input [4:0] i_dest_addr, // 32 regs
    input [31:0] i_data,
    input [4:0] i_a_addr,
    output reg [31:0] o_a,
    input [4:0] i_b_addr,
    output reg [31:0] o_b
);

reg [31:0] reg_file [0:31]; // 32 regs, 32-bit/reg

always @(posedge clk) begin
    reg_file[i_dest_addr] <= i_data;
end

always @(*) begin
    // always output 0 for x0
    if (i_a_addr == 5'h0) begin
        o_a = 5'h0;
    end
    // forward the data to the output if reading addr = writing addr
    else if (i_a_addr == i_dest_addr)
        o_a = i_data;
    else begin
        o_a = reg_file[i_a_addr];
    end
end

always @(*) begin
    if (i_b_addr == 5'h0) begin
        o_b = 5'h0;
    end
    else if (i_b_addr == i_dest_addr)
        o_b = i_data;
    else begin
        o_b = reg_file[i_b_addr];
    end
end

`ifndef SYNTHESIS

wire [31:0] x0 = reg_file[0];
wire [31:0] x1 = reg_file[1];
wire [31:0] x2 = reg_file[2];
wire [31:0] x3 = reg_file[3];
wire [31:0] x4 = reg_file[4];
wire [31:0] x10 = reg_file[10];
wire [31:0] x11 = reg_file[11];

`endif


endmodule