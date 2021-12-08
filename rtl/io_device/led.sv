module led (
    input i_clk,
    input i_reset,
    input i_wb_cycle,
    input i_wb_stb,
    input i_wb_we,
    input [31:0] i_wb_data,
    output o_wb_stall,
    output o_wb_ack,
    output reg [15:0] o_led_data
);

assign o_wb_ack = i_wb_cycle && i_wb_stb;

always @(posedge i_clk) begin
    if (i_reset) begin
        o_led_data <= 0;
    end
    else begin
        if (i_wb_cycle && i_wb_stb) begin
            if (i_wb_we) begin
                o_led_data <= i_wb_data;
            end
        end
    end
end

    
endmodule