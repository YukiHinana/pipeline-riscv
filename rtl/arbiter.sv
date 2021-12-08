module arbiter (
    input clk,
    input reset,
    input i_wb_a_cycle,
    input i_wb_a_stb,
    input i_wb_a_we,
    input [3:0] i_wb_a_sel,
    input [29:0] i_wb_a_addr,
    input [31:0] i_wb_a_mosi_data,
    output o_wb_a_ack, // output to a
    output o_wb_a_stall,
    output wire [31:0] o_wb_a_miso_data,

    input i_wb_b_cycle,
    input i_wb_b_stb,
    input i_wb_b_we,
    input [3:0] i_wb_b_sel,
    input [29:0] i_wb_b_addr,
    input [31:0] i_wb_b_mosi_data,
    output o_wb_b_ack, // output to b
    output o_wb_b_stall,
    output wire [31:0] o_wb_b_miso_data,

    input i_wb_slave_ack,
    input i_wb_slave_stall,
    input [31:0] i_wb_slave_miso_data,

    output o_wb_slave_cycle, // output to a slave
    output o_wb_slave_stb,
    output o_wb_slave_we,
    output wire [3:0] o_wb_slave_sel,
    output wire [29:0] o_wb_slave_addr,
    output wire [31:0] o_wb_slave_mosi_data
);

reg b_own_bus = 1;

assign o_wb_b_stall = b_own_bus ? i_wb_slave_stall : 1'b1;
assign o_wb_a_stall = (!b_own_bus) ? i_wb_slave_stall : 1'b1;
assign o_wb_b_ack = b_own_bus ? i_wb_slave_ack : 1'b0;
assign o_wb_a_ack = (!b_own_bus) ? i_wb_slave_ack : 1'b0;
assign o_wb_b_miso_data = i_wb_slave_miso_data;
assign o_wb_a_miso_data = i_wb_slave_miso_data;
assign o_wb_slave_mosi_data = b_own_bus ? i_wb_b_mosi_data : i_wb_a_mosi_data;
assign o_wb_slave_cycle = b_own_bus ? i_wb_b_cycle : i_wb_a_cycle;
assign o_wb_slave_stb = b_own_bus ? i_wb_b_stb : i_wb_a_stb;
assign o_wb_slave_we = b_own_bus ? i_wb_b_we : i_wb_a_we;
assign o_wb_slave_addr = b_own_bus ? i_wb_b_addr : i_wb_a_addr;
assign o_wb_slave_sel = b_own_bus ? i_wb_b_sel : i_wb_a_sel;

always @(posedge clk) begin
    if (b_own_bus == 1) begin
        if (i_wb_a_cycle == 1 && i_wb_b_cycle == 0) begin
            b_own_bus <= 0;
        end
    end
    if (b_own_bus == 0) begin
        if (i_wb_a_cycle == 0) begin
            b_own_bus <= 1;
        end
    end
end
    
endmodule