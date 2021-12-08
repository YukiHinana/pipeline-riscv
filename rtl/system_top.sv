module system_top (
    input clk,
    input reset,
    output wire [15:0] led_data
);

wire wb_slave_ack, wb_slave_stall, wb_slave_cycle, wb_slave_stb, wb_slave_we;
wire [31:0] wb_slave_miso_data, wb_slave_mosi_data;
wire [3:0] wb_slave_sel;
wire [29:0] wb_slave_addr;

top top (.clk,
        .reset,
        .i_wb_slave_ack(wb_slave_ack),
        .i_wb_slave_stall(wb_slave_stall),
        .i_wb_slave_miso_data(wb_slave_miso_data),
        .o_wb_slave_cycle(wb_slave_cycle),
        .o_wb_slave_stb(wb_slave_stb),
        .o_wb_slave_we(wb_slave_we),
        .o_wb_slave_sel(wb_slave_sel),
        .o_wb_slave_addr(wb_slave_addr),
        .o_wb_slave_mosi_data(wb_slave_mosi_data));

memdev #(20) my_mem2(
        .i_clk(clk),
        .i_wb_cyc(wb_slave_cycle),
        .i_wb_stb(wb_slave_stb),
        .i_wb_we(wb_slave_we),
        .i_wb_addr(wb_slave_addr[17:0]),
        .i_wb_data(wb_slave_mosi_data),
        .i_wb_sel(wb_slave_sel),
        .o_wb_ack(wb_slave_ack),
        .o_wb_stall(wb_slave_stall),
        .o_wb_data(wb_slave_miso_data)
    );

led led (.i_clk(clk),
        .i_reset(reset),
        .i_wb_cycle(wb_slave_cycle)
        .i_wb_stb(wb_slave_stb),
        .i_wb_we(wb_slave_we),
        .i_wb_data(wb_slave_mosi_data),
        .o_wb_stall(wb_slave_stall),
        .o_wb_ack(wb_slave_ack),
        .o_led_data(led_data));

assign mem_addr_sel = (wb_slave_addr[29:18] == 12'b0);
assign led_addr_sel = (wb_slave_addr[29:0] == 30'b1111_1111_1111_1111_1111_1111_1111_11);
assign switch_addr_sel = (wb_slave_addr[29:0] == 30'b1111_1111_1111_1111_1111_1111_1111_10);


    
endmodule