module YJTopWrapper(
  input         clock,
  input         reset,
  input         io_procReset,
  output        io_fetchWb_cyc,
  output        io_fetchWb_stb,
  output        io_fetchWb_we,
  output [31:0] io_fetchWb_addr,
  output [31:0] io_fetchWb_mosi_data,
  input  [31:0] io_fetchWb_miso_data,
  output [3:0]  io_fetchWb_sel,
  input         io_fetchWb_ack,
  input         io_fetchWb_stall,
  output        io_memWb_cyc,
  output        io_memWb_stb,
  output        io_memWb_we,
  output [31:0] io_memWb_addr,
  output [31:0] io_memWb_mosi_data,
  input  [31:0] io_memWb_miso_data,
  output [3:0]  io_memWb_sel,
  input         io_memWb_ack,
  input         io_memWb_stall
);
  wire  top_clk; // @[YJTopWrapper.scala 13:19]
  wire  top_reset; // @[YJTopWrapper.scala 13:19]
  wire  top_wb2_cyc; // @[YJTopWrapper.scala 13:19]
  wire  top_wb2_stb; // @[YJTopWrapper.scala 13:19]
  wire  top_wb2_we; // @[YJTopWrapper.scala 13:19]
  wire [3:0] top_wb2_sel; // @[YJTopWrapper.scala 13:19]
  wire  top_wb2_stall; // @[YJTopWrapper.scala 13:19]
  wire  top_wb2_ack; // @[YJTopWrapper.scala 13:19]
  wire [29:0] top_wb2_addr; // @[YJTopWrapper.scala 13:19]
  wire [31:0] top_wb2_mosi_data; // @[YJTopWrapper.scala 13:19]
  wire [31:0] top_wb2_miso_data; // @[YJTopWrapper.scala 13:19]
  wire  top_wb_cyc; // @[YJTopWrapper.scala 13:19]
  wire  top_wb_stb; // @[YJTopWrapper.scala 13:19]
  wire  top_wb_we; // @[YJTopWrapper.scala 13:19]
  wire [3:0] top_wb_sel; // @[YJTopWrapper.scala 13:19]
  wire  top_wb_stall; // @[YJTopWrapper.scala 13:19]
  wire  top_wb_ack; // @[YJTopWrapper.scala 13:19]
  wire [29:0] top_wb_addr; // @[YJTopWrapper.scala 13:19]
  wire [31:0] top_wb_mosi_data; // @[YJTopWrapper.scala 13:19]
  wire [31:0] top_wb_miso_data; // @[YJTopWrapper.scala 13:19]
  top top ( // @[YJTopWrapper.scala 13:19]
    .clk(top_clk),
    .reset(top_reset),
    .wb2_cyc(top_wb2_cyc),
    .wb2_stb(top_wb2_stb),
    .wb2_we(top_wb2_we),
    .wb2_sel(top_wb2_sel),
    .wb2_stall(top_wb2_stall),
    .wb2_ack(top_wb2_ack),
    .wb2_addr(top_wb2_addr),
    .wb2_mosi_data(top_wb2_mosi_data),
    .wb2_miso_data(top_wb2_miso_data),
    .wb_cyc(top_wb_cyc),
    .wb_stb(top_wb_stb),
    .wb_we(top_wb_we),
    .wb_sel(top_wb_sel),
    .wb_stall(top_wb_stall),
    .wb_ack(top_wb_ack),
    .wb_addr(top_wb_addr),
    .wb_mosi_data(top_wb_mosi_data),
    .wb_miso_data(top_wb_miso_data)
  );
  assign io_fetchWb_cyc = top_wb2_cyc; // @[YJTopWrapper.scala 19:15]
  assign io_fetchWb_stb = top_wb2_stb; // @[YJTopWrapper.scala 20:15]
  assign io_fetchWb_we = top_wb2_we; // @[YJTopWrapper.scala 21:14]
  assign io_fetchWb_addr = {{2'd0}, top_wb2_addr}; // @[YJTopWrapper.scala 25:16]
  assign io_fetchWb_mosi_data = top_wb2_mosi_data; // @[YJTopWrapper.scala 26:21]
  assign io_fetchWb_sel = top_wb2_sel; // @[YJTopWrapper.scala 22:15]
  assign io_memWb_cyc = top_wb_cyc; // @[YJTopWrapper.scala 30:13]
  assign io_memWb_stb = top_wb_stb; // @[YJTopWrapper.scala 31:13]
  assign io_memWb_we = top_wb_we; // @[YJTopWrapper.scala 32:12]
  assign io_memWb_addr = {{2'd0}, top_wb_addr}; // @[YJTopWrapper.scala 36:14]
  assign io_memWb_mosi_data = top_wb_mosi_data; // @[YJTopWrapper.scala 37:19]
  assign io_memWb_sel = top_wb_sel; // @[YJTopWrapper.scala 33:13]
  assign top_clk = clock; // @[YJTopWrapper.scala 15:14]
  assign top_reset = reset | io_procReset; // @[YJTopWrapper.scala 16:35]
  assign top_wb2_stall = io_fetchWb_stall; // @[YJTopWrapper.scala 23:17]
  assign top_wb2_ack = io_fetchWb_ack; // @[YJTopWrapper.scala 24:15]
  assign top_wb2_miso_data = io_fetchWb_miso_data; // @[YJTopWrapper.scala 27:21]
  assign top_wb_stall = io_memWb_stall; // @[YJTopWrapper.scala 34:15]
  assign top_wb_ack = io_memWb_ack; // @[YJTopWrapper.scala 35:13]
  assign top_wb_miso_data = io_memWb_miso_data; // @[YJTopWrapper.scala 38:19]
endmodule
module WBLeds(
  input         clock,
  input         reset,
  output [15:0] io_leds,
  input         io_wb_cyc,
  input         io_wb_stb,
  input         io_wb_we,
  input  [31:0] io_wb_mosi_data,
  output [31:0] io_wb_miso_data,
  input  [3:0]  io_wb_sel,
  output        io_wb_ack
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] ledBuf_0; // @[WBLeds.scala 19:23]
  reg [7:0] ledBuf_1; // @[WBLeds.scala 19:23]
  wire [15:0] _io_leds_T = {ledBuf_1,ledBuf_0}; // @[WBLeds.scala 23:29]
  assign io_leds = {ledBuf_1,ledBuf_0}; // @[WBLeds.scala 23:29]
  assign io_wb_miso_data = {{16'd0}, _io_leds_T}; // @[WBLeds.scala 26:35]
  assign io_wb_ack = io_wb_cyc & io_wb_stb; // @[WBLeds.scala 28:18]
  always @(posedge clock) begin
    if (reset) begin // @[WBLeds.scala 19:23]
      ledBuf_0 <= 8'h0; // @[WBLeds.scala 19:23]
    end else if (io_wb_cyc & io_wb_stb) begin // @[WBLeds.scala 28:32]
      if (io_wb_we) begin // @[WBLeds.scala 30:20]
        if (io_wb_sel[0]) begin // @[WBLeds.scala 32:28]
          ledBuf_0 <= io_wb_mosi_data[7:0]; // @[WBLeds.scala 33:21]
        end
      end
    end
    if (reset) begin // @[WBLeds.scala 19:23]
      ledBuf_1 <= 8'h0; // @[WBLeds.scala 19:23]
    end else if (io_wb_cyc & io_wb_stb) begin // @[WBLeds.scala 28:32]
      if (io_wb_we) begin // @[WBLeds.scala 30:20]
        if (io_wb_sel[1]) begin // @[WBLeds.scala 32:28]
          ledBuf_1 <= io_wb_mosi_data[15:8]; // @[WBLeds.scala 33:21]
        end
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  ledBuf_0 = _RAND_0[7:0];
  _RAND_1 = {1{`RANDOM}};
  ledBuf_1 = _RAND_1[7:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module WBUartIhexWrapper(
  input         clock,
  input         reset,
  input         io_rx,
  output        io_tx,
  output        io_masterWb_cyc,
  output        io_masterWb_stb,
  output        io_masterWb_we,
  output [31:0] io_masterWb_addr,
  output [31:0] io_masterWb_mosi_data,
  input  [31:0] io_masterWb_miso_data,
  output [3:0]  io_masterWb_sel,
  input         io_masterWb_ack,
  input         io_masterWb_stall,
  input         io_masterWb_error,
  input         io_slaveWb_cyc,
  input         io_slaveWb_stb,
  input         io_slaveWb_we,
  input  [31:0] io_slaveWb_addr,
  input  [31:0] io_slaveWb_mosi_data,
  output [31:0] io_slaveWb_miso_data,
  input  [3:0]  io_slaveWb_sel,
  output        io_slaveWb_ack,
  output        io_slaveWb_stall
);
  wire  m_i_clk; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_i_reset; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_i_rx; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_o_tx; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_o_mwb_cyc; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_o_mwb_stb; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_o_mwb_we; // @[WBUartIhexWrapper.scala 15:17]
  wire [3:0] m_o_mwb_sel; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_i_mwb_stall; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_i_mwb_ack; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_i_mwb_err; // @[WBUartIhexWrapper.scala 15:17]
  wire [29:0] m_o_mwb_addr; // @[WBUartIhexWrapper.scala 15:17]
  wire [31:0] m_o_mwb_data; // @[WBUartIhexWrapper.scala 15:17]
  wire [31:0] m_i_mwb_data; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_i_wb_cyc; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_i_wb_stb; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_i_wb_we; // @[WBUartIhexWrapper.scala 15:17]
  wire [3:0] m_i_wb_sel; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_o_wb_stall; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_o_wb_ack; // @[WBUartIhexWrapper.scala 15:17]
  wire  m_o_wb_err; // @[WBUartIhexWrapper.scala 15:17]
  wire [29:0] m_i_wb_addr; // @[WBUartIhexWrapper.scala 15:17]
  wire [31:0] m_i_wb_data; // @[WBUartIhexWrapper.scala 15:17]
  wire [31:0] m_o_wb_data; // @[WBUartIhexWrapper.scala 15:17]
  WBUartWithIhex #(.I_CLOCK_FREQ(50000000), .BAUD_RATE(115200)) m ( // @[WBUartIhexWrapper.scala 15:17]
    .i_clk(m_i_clk),
    .i_reset(m_i_reset),
    .i_rx(m_i_rx),
    .o_tx(m_o_tx),
    .o_mwb_cyc(m_o_mwb_cyc),
    .o_mwb_stb(m_o_mwb_stb),
    .o_mwb_we(m_o_mwb_we),
    .o_mwb_sel(m_o_mwb_sel),
    .i_mwb_stall(m_i_mwb_stall),
    .i_mwb_ack(m_i_mwb_ack),
    .i_mwb_err(m_i_mwb_err),
    .o_mwb_addr(m_o_mwb_addr),
    .o_mwb_data(m_o_mwb_data),
    .i_mwb_data(m_i_mwb_data),
    .i_wb_cyc(m_i_wb_cyc),
    .i_wb_stb(m_i_wb_stb),
    .i_wb_we(m_i_wb_we),
    .i_wb_sel(m_i_wb_sel),
    .o_wb_stall(m_o_wb_stall),
    .o_wb_ack(m_o_wb_ack),
    .o_wb_err(m_o_wb_err),
    .i_wb_addr(m_i_wb_addr),
    .i_wb_data(m_i_wb_data),
    .o_wb_data(m_o_wb_data)
  );
  assign io_tx = m_o_tx; // @[WBUartIhexWrapper.scala 20:9]
  assign io_masterWb_cyc = m_o_mwb_cyc; // @[WBUartIhexWrapper.scala 23:11]
  assign io_masterWb_stb = m_o_mwb_stb; // @[WBUartIhexWrapper.scala 24:11]
  assign io_masterWb_we = m_o_mwb_we; // @[WBUartIhexWrapper.scala 25:10]
  assign io_masterWb_addr = {{2'd0}, m_o_mwb_addr}; // @[WBUartIhexWrapper.scala 30:12]
  assign io_masterWb_mosi_data = m_o_mwb_data; // @[WBUartIhexWrapper.scala 31:17]
  assign io_masterWb_sel = m_o_mwb_sel; // @[WBUartIhexWrapper.scala 26:11]
  assign io_slaveWb_miso_data = m_o_wb_data; // @[WBUartIhexWrapper.scala 44:17]
  assign io_slaveWb_ack = m_o_wb_ack; // @[WBUartIhexWrapper.scala 40:11]
  assign io_slaveWb_stall = m_o_wb_stall; // @[WBUartIhexWrapper.scala 39:13]
  assign m_i_clk = clock; // @[WBUartIhexWrapper.scala 16:14]
  assign m_i_reset = reset; // @[WBUartIhexWrapper.scala 17:16]
  assign m_i_rx = io_rx; // @[WBUartIhexWrapper.scala 19:13]
  assign m_i_mwb_stall = io_masterWb_stall; // @[WBUartIhexWrapper.scala 27:13]
  assign m_i_mwb_ack = io_masterWb_ack; // @[WBUartIhexWrapper.scala 28:11]
  assign m_i_mwb_err = io_masterWb_error; // @[WBUartIhexWrapper.scala 29:13]
  assign m_i_mwb_data = io_masterWb_miso_data; // @[WBUartIhexWrapper.scala 32:17]
  assign m_i_wb_cyc = io_slaveWb_cyc; // @[WBUartIhexWrapper.scala 35:11]
  assign m_i_wb_stb = io_slaveWb_stb; // @[WBUartIhexWrapper.scala 36:11]
  assign m_i_wb_we = io_slaveWb_we; // @[WBUartIhexWrapper.scala 37:10]
  assign m_i_wb_sel = io_slaveWb_sel; // @[WBUartIhexWrapper.scala 38:11]
  assign m_i_wb_addr = io_slaveWb_addr[29:0]; // @[WBUartIhexWrapper.scala 42:12]
  assign m_i_wb_data = io_slaveWb_mosi_data; // @[WBUartIhexWrapper.scala 43:17]
endmodule
module BlockRam(
  input         clock,
  input         reset,
  input         io_wb_cyc,
  input         io_wb_stb,
  input         io_wb_we,
  input  [31:0] io_wb_addr,
  input  [31:0] io_wb_mosi_data,
  output [31:0] io_wb_miso_data,
  input  [3:0]  io_wb_sel,
  output        io_wb_ack,
  output        io_wb_stall
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  wire  rams_0_clock; // @[BlockRam.scala 14:11]
  wire [12:0] rams_0_addr; // @[BlockRam.scala 14:11]
  wire  rams_0_we; // @[BlockRam.scala 14:11]
  wire [7:0] rams_0_data_out; // @[BlockRam.scala 14:11]
  wire [7:0] rams_0_data_in; // @[BlockRam.scala 14:11]
  wire  rams_1_clock; // @[BlockRam.scala 14:11]
  wire [12:0] rams_1_addr; // @[BlockRam.scala 14:11]
  wire  rams_1_we; // @[BlockRam.scala 14:11]
  wire [7:0] rams_1_data_out; // @[BlockRam.scala 14:11]
  wire [7:0] rams_1_data_in; // @[BlockRam.scala 14:11]
  wire  rams_2_clock; // @[BlockRam.scala 14:11]
  wire [12:0] rams_2_addr; // @[BlockRam.scala 14:11]
  wire  rams_2_we; // @[BlockRam.scala 14:11]
  wire [7:0] rams_2_data_out; // @[BlockRam.scala 14:11]
  wire [7:0] rams_2_data_in; // @[BlockRam.scala 14:11]
  wire  rams_3_clock; // @[BlockRam.scala 14:11]
  wire [12:0] rams_3_addr; // @[BlockRam.scala 14:11]
  wire  rams_3_we; // @[BlockRam.scala 14:11]
  wire [7:0] rams_3_data_out; // @[BlockRam.scala 14:11]
  wire [7:0] rams_3_data_in; // @[BlockRam.scala 14:11]
  reg  state; // @[BlockRam.scala 21:22]
  wire  _rams_0_io_we_T = ~state; // @[BlockRam.scala 29:36]
  wire [15:0] io_wb_miso_data_lo = {rams_1_data_out,rams_0_data_out}; // @[Cat.scala 30:58]
  wire [15:0] io_wb_miso_data_hi = {rams_3_data_out,rams_2_data_out}; // @[Cat.scala 30:58]
  wire  _GEN_0 = io_wb_stb & io_wb_cyc | state; // @[BlockRam.scala 38:34 BlockRam.scala 39:13 BlockRam.scala 21:22]
  SinglePortRam #(.AW(13)) rams_0 ( // @[BlockRam.scala 14:11]
    .clock(rams_0_clock),
    .addr(rams_0_addr),
    .we(rams_0_we),
    .data_out(rams_0_data_out),
    .data_in(rams_0_data_in)
  );
  SinglePortRam #(.AW(13)) rams_1 ( // @[BlockRam.scala 14:11]
    .clock(rams_1_clock),
    .addr(rams_1_addr),
    .we(rams_1_we),
    .data_out(rams_1_data_out),
    .data_in(rams_1_data_in)
  );
  SinglePortRam #(.AW(13)) rams_2 ( // @[BlockRam.scala 14:11]
    .clock(rams_2_clock),
    .addr(rams_2_addr),
    .we(rams_2_we),
    .data_out(rams_2_data_out),
    .data_in(rams_2_data_in)
  );
  SinglePortRam #(.AW(13)) rams_3 ( // @[BlockRam.scala 14:11]
    .clock(rams_3_clock),
    .addr(rams_3_addr),
    .we(rams_3_we),
    .data_out(rams_3_data_out),
    .data_in(rams_3_data_in)
  );
  assign io_wb_miso_data = {io_wb_miso_data_hi,io_wb_miso_data_lo}; // @[Cat.scala 30:58]
  assign io_wb_ack = state; // @[BlockRam.scala 24:22]
  assign io_wb_stall = state; // @[BlockRam.scala 23:24]
  assign rams_0_clock = clock; // @[BlockRam.scala 28:18]
  assign rams_0_addr = io_wb_addr[12:0]; // @[BlockRam.scala 30:17]
  assign rams_0_we = io_wb_we & ~state & io_wb_stb & io_wb_cyc & io_wb_sel[0]; // @[BlockRam.scala 29:73]
  assign rams_0_data_in = io_wb_mosi_data[7:0]; // @[BlockRam.scala 31:38]
  assign rams_1_clock = clock; // @[BlockRam.scala 28:18]
  assign rams_1_addr = io_wb_addr[12:0]; // @[BlockRam.scala 30:17]
  assign rams_1_we = io_wb_we & ~state & io_wb_stb & io_wb_cyc & io_wb_sel[1]; // @[BlockRam.scala 29:73]
  assign rams_1_data_in = io_wb_mosi_data[15:8]; // @[BlockRam.scala 31:38]
  assign rams_2_clock = clock; // @[BlockRam.scala 28:18]
  assign rams_2_addr = io_wb_addr[12:0]; // @[BlockRam.scala 30:17]
  assign rams_2_we = io_wb_we & ~state & io_wb_stb & io_wb_cyc & io_wb_sel[2]; // @[BlockRam.scala 29:73]
  assign rams_2_data_in = io_wb_mosi_data[23:16]; // @[BlockRam.scala 31:38]
  assign rams_3_clock = clock; // @[BlockRam.scala 28:18]
  assign rams_3_addr = io_wb_addr[12:0]; // @[BlockRam.scala 30:17]
  assign rams_3_we = io_wb_we & ~state & io_wb_stb & io_wb_cyc & io_wb_sel[3]; // @[BlockRam.scala 29:73]
  assign rams_3_data_in = io_wb_mosi_data[31:24]; // @[BlockRam.scala 31:38]
  always @(posedge clock) begin
    if (reset) begin // @[BlockRam.scala 21:22]
      state <= 1'h0; // @[BlockRam.scala 21:22]
    end else if (state) begin // @[BlockRam.scala 42:25]
      state <= 1'h0; // @[BlockRam.scala 43:11]
    end else if (_rams_0_io_we_T) begin // @[BlockRam.scala 37:26]
      state <= _GEN_0;
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  state = _RAND_0[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module WBArbiter(
  input         clock,
  input         reset,
  input         io_masters_0_cyc,
  input         io_masters_0_stb,
  input         io_masters_0_we,
  input  [31:0] io_masters_0_addr,
  input  [31:0] io_masters_0_mosi_data,
  output [31:0] io_masters_0_miso_data,
  input  [3:0]  io_masters_0_sel,
  output        io_masters_0_ack,
  output        io_masters_0_stall,
  output        io_masters_0_error,
  input         io_masters_1_cyc,
  input         io_masters_1_stb,
  input         io_masters_1_we,
  input  [31:0] io_masters_1_addr,
  input  [31:0] io_masters_1_mosi_data,
  output [31:0] io_masters_1_miso_data,
  input  [3:0]  io_masters_1_sel,
  output        io_masters_1_ack,
  output        io_masters_1_stall,
  input         io_masters_2_cyc,
  input         io_masters_2_stb,
  input         io_masters_2_we,
  input  [31:0] io_masters_2_addr,
  input  [31:0] io_masters_2_mosi_data,
  output [31:0] io_masters_2_miso_data,
  input  [3:0]  io_masters_2_sel,
  output        io_masters_2_ack,
  output        io_masters_2_stall,
  output        io_output_cyc,
  output        io_output_stb,
  output        io_output_we,
  output [31:0] io_output_addr,
  output [31:0] io_output_mosi_data,
  input  [31:0] io_output_miso_data,
  output [3:0]  io_output_sel,
  input         io_output_ack,
  input         io_output_stall,
  input         io_output_error
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [3:0] currentMaster; // @[WBArbiter.scala 20:30]
  wire [1:0] _GEN_0 = io_masters_2_cyc & io_masters_2_stb ? 2'h2 : 2'h0; // @[WBArbiter.scala 25:50 WBArbiter.scala 26:18 WBArbiter.scala 23:14]
  wire [1:0] _GEN_1 = io_masters_1_cyc & io_masters_1_stb ? 2'h1 : _GEN_0; // @[WBArbiter.scala 25:50 WBArbiter.scala 26:18]
  wire [1:0] _GEN_2 = io_masters_0_cyc & io_masters_0_stb ? 2'h0 : _GEN_1; // @[WBArbiter.scala 25:50 WBArbiter.scala 26:18]
  wire  _GEN_37 = 2'h0 == currentMaster[1:0]; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13 WBArbiter.scala 16:25]
  wire  _GEN_38 = 2'h1 == currentMaster[1:0]; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13 WBArbiter.scala 16:25]
  wire  _GEN_39 = 2'h2 == currentMaster[1:0]; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13 WBArbiter.scala 16:25]
  wire [3:0] _GEN_13 = 2'h1 == currentMaster[1:0] ? io_masters_1_sel : io_masters_0_sel; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  wire [31:0] _GEN_19 = 2'h1 == currentMaster[1:0] ? io_masters_1_mosi_data : io_masters_0_mosi_data; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  wire [31:0] _GEN_22 = 2'h1 == currentMaster[1:0] ? io_masters_1_addr : io_masters_0_addr; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  wire  _GEN_25 = 2'h1 == currentMaster[1:0] ? io_masters_1_we : io_masters_0_we; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  wire  _GEN_28 = 2'h1 == currentMaster[1:0] ? io_masters_1_stb : io_masters_0_stb; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  wire  _GEN_31 = 2'h1 == currentMaster[1:0] ? io_masters_1_cyc : io_masters_0_cyc; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  wire  _GEN_32 = 2'h2 == currentMaster[1:0] ? io_masters_2_cyc : _GEN_31; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  wire [3:0] nextMaster = {{2'd0}, _GEN_2}; // @[WBArbiter.scala 22:24]
  assign io_masters_0_miso_data = io_output_miso_data; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  assign io_masters_0_ack = _GEN_37 & io_output_ack; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13 WBArbiter.scala 14:23]
  assign io_masters_0_stall = 2'h0 == currentMaster[1:0] ? io_output_stall : 1'h1; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13 WBArbiter.scala 17:25]
  assign io_masters_0_error = 2'h0 == currentMaster[1:0] & io_output_error; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13 WBArbiter.scala 16:25]
  assign io_masters_1_miso_data = io_output_miso_data; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  assign io_masters_1_ack = _GEN_38 & io_output_ack; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13 WBArbiter.scala 14:23]
  assign io_masters_1_stall = 2'h1 == currentMaster[1:0] ? io_output_stall : 1'h1; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13 WBArbiter.scala 17:25]
  assign io_masters_2_miso_data = io_output_miso_data; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  assign io_masters_2_ack = _GEN_39 & io_output_ack; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13 WBArbiter.scala 14:23]
  assign io_masters_2_stall = 2'h2 == currentMaster[1:0] ? io_output_stall : 1'h1; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13 WBArbiter.scala 17:25]
  assign io_output_cyc = 2'h2 == currentMaster[1:0] ? io_masters_2_cyc : _GEN_31; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  assign io_output_stb = 2'h2 == currentMaster[1:0] ? io_masters_2_stb : _GEN_28; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  assign io_output_we = 2'h2 == currentMaster[1:0] ? io_masters_2_we : _GEN_25; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  assign io_output_addr = 2'h2 == currentMaster[1:0] ? io_masters_2_addr : _GEN_22; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  assign io_output_mosi_data = 2'h2 == currentMaster[1:0] ? io_masters_2_mosi_data : _GEN_19; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  assign io_output_sel = 2'h2 == currentMaster[1:0] ? io_masters_2_sel : _GEN_13; // @[WBArbiter.scala 30:13 WBArbiter.scala 30:13]
  always @(posedge clock) begin
    if (reset) begin // @[WBArbiter.scala 20:30]
      currentMaster <= 4'h0; // @[WBArbiter.scala 20:30]
    end else if (~_GEN_32) begin // @[WBArbiter.scala 31:40]
      currentMaster <= nextMaster; // @[WBArbiter.scala 32:19]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  currentMaster = _RAND_0[3:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module WBInterconnect(
  input         clock,
  input         reset,
  output        io_devices_0_cyc,
  output        io_devices_0_stb,
  output        io_devices_0_we,
  output [31:0] io_devices_0_addr,
  output [31:0] io_devices_0_mosi_data,
  input  [31:0] io_devices_0_miso_data,
  output [3:0]  io_devices_0_sel,
  input         io_devices_0_ack,
  input         io_devices_0_stall,
  output        io_devices_1_cyc,
  output        io_devices_1_stb,
  output        io_devices_1_we,
  output [31:0] io_devices_1_mosi_data,
  input  [31:0] io_devices_1_miso_data,
  output [3:0]  io_devices_1_sel,
  input         io_devices_1_ack,
  output        io_devices_2_cyc,
  output        io_devices_2_stb,
  output        io_devices_2_we,
  output [31:0] io_devices_2_addr,
  output [31:0] io_devices_2_mosi_data,
  input  [31:0] io_devices_2_miso_data,
  output [3:0]  io_devices_2_sel,
  input         io_devices_2_ack,
  input         io_devices_2_stall,
  input         io_master_cyc,
  input         io_master_stb,
  input         io_master_we,
  input  [31:0] io_master_addr,
  input  [31:0] io_master_mosi_data,
  output [31:0] io_master_miso_data,
  input  [3:0]  io_master_sel,
  output        io_master_ack,
  output        io_master_stall,
  output        io_master_error
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
`endif // RANDOMIZE_REG_INIT
  reg  wback; // @[WBInterconnect.scala 33:22]
  reg [31:0] wbdata; // @[WBInterconnect.scala 34:19]
  reg  wberr; // @[WBInterconnect.scala 38:22]
  wire [2:0] _wback_T = {io_devices_2_ack,io_devices_1_ack,io_devices_0_ack}; // @[WBInterconnect.scala 43:25]
  wire  deviceSels_0 = io_master_addr[29:13] == 17'h0; // @[WBInterconnect.scala 55:59]
  wire  deviceSels_1 = io_master_addr[29:0] == 30'h3c000000; // @[WBInterconnect.scala 55:59]
  wire  deviceSels_2 = io_master_addr[29:1] == 29'h1e000200; // @[WBInterconnect.scala 55:59]
  wire [2:0] _T = {deviceSels_2,deviceSels_1,deviceSels_0}; // @[WBInterconnect.scala 57:43]
  wire  _T_3 = io_master_stb & ~(|_T); // @[WBInterconnect.scala 57:22]
  wire  stalls_0 = deviceSels_0 & io_devices_0_stall; // @[WBInterconnect.scala 63:32]
  wire  stalls_2 = deviceSels_2 & io_devices_2_stall; // @[WBInterconnect.scala 63:32]
  wire [2:0] _io_master_stall_T = {stalls_2,1'h0,stalls_0}; // @[WBInterconnect.scala 65:35]
  assign io_devices_0_cyc = io_master_cyc & deviceSels_0; // @[WBInterconnect.scala 77:40]
  assign io_devices_0_stb = io_master_stb & deviceSels_0; // @[WBInterconnect.scala 69:40]
  assign io_devices_0_we = io_master_we; // @[WBInterconnect.scala 76:22]
  assign io_devices_0_addr = {{19'd0}, io_master_addr[12:0]}; // @[WBInterconnect.scala 72:43]
  assign io_devices_0_mosi_data = io_master_mosi_data; // @[WBInterconnect.scala 78:29]
  assign io_devices_0_sel = io_master_sel; // @[WBInterconnect.scala 70:23]
  assign io_devices_1_cyc = io_master_cyc & deviceSels_1; // @[WBInterconnect.scala 77:40]
  assign io_devices_1_stb = io_master_stb & deviceSels_1; // @[WBInterconnect.scala 69:40]
  assign io_devices_1_we = io_master_we; // @[WBInterconnect.scala 76:22]
  assign io_devices_1_mosi_data = io_master_mosi_data; // @[WBInterconnect.scala 78:29]
  assign io_devices_1_sel = io_master_sel; // @[WBInterconnect.scala 70:23]
  assign io_devices_2_cyc = io_master_cyc & deviceSels_2; // @[WBInterconnect.scala 77:40]
  assign io_devices_2_stb = io_master_stb & deviceSels_2; // @[WBInterconnect.scala 69:40]
  assign io_devices_2_we = io_master_we; // @[WBInterconnect.scala 76:22]
  assign io_devices_2_addr = {{31'd0}, io_master_addr[0]}; // @[WBInterconnect.scala 72:43]
  assign io_devices_2_mosi_data = io_master_mosi_data; // @[WBInterconnect.scala 78:29]
  assign io_devices_2_sel = io_master_sel; // @[WBInterconnect.scala 70:23]
  assign io_master_miso_data = wbdata; // @[WBInterconnect.scala 36:23]
  assign io_master_ack = wback; // @[WBInterconnect.scala 37:17]
  assign io_master_stall = |_io_master_stall_T; // @[WBInterconnect.scala 65:41]
  assign io_master_error = wberr; // @[WBInterconnect.scala 40:19]
  always @(posedge clock) begin
    if (reset) begin // @[WBInterconnect.scala 33:22]
      wback <= 1'h0; // @[WBInterconnect.scala 33:22]
    end else begin
      wback <= |_wback_T; // @[WBInterconnect.scala 43:9]
    end
    if (io_devices_2_ack) begin // @[WBInterconnect.scala 46:29]
      wbdata <= io_devices_2_miso_data; // @[WBInterconnect.scala 47:14]
    end else if (io_devices_1_ack) begin // @[WBInterconnect.scala 46:29]
      wbdata <= io_devices_1_miso_data; // @[WBInterconnect.scala 47:14]
    end else if (io_devices_0_ack) begin // @[WBInterconnect.scala 46:29]
      wbdata <= io_devices_0_miso_data; // @[WBInterconnect.scala 47:14]
    end else begin
      wbdata <= 32'h0; // @[WBInterconnect.scala 35:10]
    end
    if (reset) begin // @[WBInterconnect.scala 38:22]
      wberr <= 1'h0; // @[WBInterconnect.scala 38:22]
    end else begin
      wberr <= _T_3;
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  wback = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  wbdata = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  wberr = _RAND_2[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module YJTop(
  input         clock,
  input         reset,
  output [11:0] io_sdram_addr,
  output [1:0]  io_sdram_bank,
  output [15:0] io_sdram_dataOut,
  output [1:0]  io_sdram_dqm,
  output        io_sdram_clk,
  output        io_sdram_cke,
  output        io_sdram_cs_n,
  output        io_sdram_ras_n,
  output        io_sdram_cas_n,
  output        io_sdram_we_n,
  output        io_sdram_output_en,
  input  [15:0] io_dqIn,
  output [15:0] io_leds,
  input         io_rx,
  output        io_tx,
  input         io_procReset
);
  wire  proc_clock; // @[YJTop.scala 25:20]
  wire  proc_reset; // @[YJTop.scala 25:20]
  wire  proc_io_procReset; // @[YJTop.scala 25:20]
  wire  proc_io_fetchWb_cyc; // @[YJTop.scala 25:20]
  wire  proc_io_fetchWb_stb; // @[YJTop.scala 25:20]
  wire  proc_io_fetchWb_we; // @[YJTop.scala 25:20]
  wire [31:0] proc_io_fetchWb_addr; // @[YJTop.scala 25:20]
  wire [31:0] proc_io_fetchWb_mosi_data; // @[YJTop.scala 25:20]
  wire [31:0] proc_io_fetchWb_miso_data; // @[YJTop.scala 25:20]
  wire [3:0] proc_io_fetchWb_sel; // @[YJTop.scala 25:20]
  wire  proc_io_fetchWb_ack; // @[YJTop.scala 25:20]
  wire  proc_io_fetchWb_stall; // @[YJTop.scala 25:20]
  wire  proc_io_memWb_cyc; // @[YJTop.scala 25:20]
  wire  proc_io_memWb_stb; // @[YJTop.scala 25:20]
  wire  proc_io_memWb_we; // @[YJTop.scala 25:20]
  wire [31:0] proc_io_memWb_addr; // @[YJTop.scala 25:20]
  wire [31:0] proc_io_memWb_mosi_data; // @[YJTop.scala 25:20]
  wire [31:0] proc_io_memWb_miso_data; // @[YJTop.scala 25:20]
  wire [3:0] proc_io_memWb_sel; // @[YJTop.scala 25:20]
  wire  proc_io_memWb_ack; // @[YJTop.scala 25:20]
  wire  proc_io_memWb_stall; // @[YJTop.scala 25:20]
  wire  leds_clock; // @[YJTop.scala 28:20]
  wire  leds_reset; // @[YJTop.scala 28:20]
  wire [15:0] leds_io_leds; // @[YJTop.scala 28:20]
  wire  leds_io_wb_cyc; // @[YJTop.scala 28:20]
  wire  leds_io_wb_stb; // @[YJTop.scala 28:20]
  wire  leds_io_wb_we; // @[YJTop.scala 28:20]
  wire [31:0] leds_io_wb_mosi_data; // @[YJTop.scala 28:20]
  wire [31:0] leds_io_wb_miso_data; // @[YJTop.scala 28:20]
  wire [3:0] leds_io_wb_sel; // @[YJTop.scala 28:20]
  wire  leds_io_wb_ack; // @[YJTop.scala 28:20]
  wire  ihexUart_clock; // @[YJTop.scala 31:24]
  wire  ihexUart_reset; // @[YJTop.scala 31:24]
  wire  ihexUart_io_rx; // @[YJTop.scala 31:24]
  wire  ihexUart_io_tx; // @[YJTop.scala 31:24]
  wire  ihexUart_io_masterWb_cyc; // @[YJTop.scala 31:24]
  wire  ihexUart_io_masterWb_stb; // @[YJTop.scala 31:24]
  wire  ihexUart_io_masterWb_we; // @[YJTop.scala 31:24]
  wire [31:0] ihexUart_io_masterWb_addr; // @[YJTop.scala 31:24]
  wire [31:0] ihexUart_io_masterWb_mosi_data; // @[YJTop.scala 31:24]
  wire [31:0] ihexUart_io_masterWb_miso_data; // @[YJTop.scala 31:24]
  wire [3:0] ihexUart_io_masterWb_sel; // @[YJTop.scala 31:24]
  wire  ihexUart_io_masterWb_ack; // @[YJTop.scala 31:24]
  wire  ihexUart_io_masterWb_stall; // @[YJTop.scala 31:24]
  wire  ihexUart_io_masterWb_error; // @[YJTop.scala 31:24]
  wire  ihexUart_io_slaveWb_cyc; // @[YJTop.scala 31:24]
  wire  ihexUart_io_slaveWb_stb; // @[YJTop.scala 31:24]
  wire  ihexUart_io_slaveWb_we; // @[YJTop.scala 31:24]
  wire [31:0] ihexUart_io_slaveWb_addr; // @[YJTop.scala 31:24]
  wire [31:0] ihexUart_io_slaveWb_mosi_data; // @[YJTop.scala 31:24]
  wire [31:0] ihexUart_io_slaveWb_miso_data; // @[YJTop.scala 31:24]
  wire [3:0] ihexUart_io_slaveWb_sel; // @[YJTop.scala 31:24]
  wire  ihexUart_io_slaveWb_ack; // @[YJTop.scala 31:24]
  wire  ihexUart_io_slaveWb_stall; // @[YJTop.scala 31:24]
  wire  blockram_clock; // @[YJTop.scala 41:24]
  wire  blockram_reset; // @[YJTop.scala 41:24]
  wire  blockram_io_wb_cyc; // @[YJTop.scala 41:24]
  wire  blockram_io_wb_stb; // @[YJTop.scala 41:24]
  wire  blockram_io_wb_we; // @[YJTop.scala 41:24]
  wire [31:0] blockram_io_wb_addr; // @[YJTop.scala 41:24]
  wire [31:0] blockram_io_wb_mosi_data; // @[YJTop.scala 41:24]
  wire [31:0] blockram_io_wb_miso_data; // @[YJTop.scala 41:24]
  wire [3:0] blockram_io_wb_sel; // @[YJTop.scala 41:24]
  wire  blockram_io_wb_ack; // @[YJTop.scala 41:24]
  wire  blockram_io_wb_stall; // @[YJTop.scala 41:24]
  wire  arbiter_clock; // @[YJTop.scala 43:23]
  wire  arbiter_reset; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_0_cyc; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_0_stb; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_0_we; // @[YJTop.scala 43:23]
  wire [31:0] arbiter_io_masters_0_addr; // @[YJTop.scala 43:23]
  wire [31:0] arbiter_io_masters_0_mosi_data; // @[YJTop.scala 43:23]
  wire [31:0] arbiter_io_masters_0_miso_data; // @[YJTop.scala 43:23]
  wire [3:0] arbiter_io_masters_0_sel; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_0_ack; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_0_stall; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_0_error; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_1_cyc; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_1_stb; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_1_we; // @[YJTop.scala 43:23]
  wire [31:0] arbiter_io_masters_1_addr; // @[YJTop.scala 43:23]
  wire [31:0] arbiter_io_masters_1_mosi_data; // @[YJTop.scala 43:23]
  wire [31:0] arbiter_io_masters_1_miso_data; // @[YJTop.scala 43:23]
  wire [3:0] arbiter_io_masters_1_sel; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_1_ack; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_1_stall; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_2_cyc; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_2_stb; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_2_we; // @[YJTop.scala 43:23]
  wire [31:0] arbiter_io_masters_2_addr; // @[YJTop.scala 43:23]
  wire [31:0] arbiter_io_masters_2_mosi_data; // @[YJTop.scala 43:23]
  wire [31:0] arbiter_io_masters_2_miso_data; // @[YJTop.scala 43:23]
  wire [3:0] arbiter_io_masters_2_sel; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_2_ack; // @[YJTop.scala 43:23]
  wire  arbiter_io_masters_2_stall; // @[YJTop.scala 43:23]
  wire  arbiter_io_output_cyc; // @[YJTop.scala 43:23]
  wire  arbiter_io_output_stb; // @[YJTop.scala 43:23]
  wire  arbiter_io_output_we; // @[YJTop.scala 43:23]
  wire [31:0] arbiter_io_output_addr; // @[YJTop.scala 43:23]
  wire [31:0] arbiter_io_output_mosi_data; // @[YJTop.scala 43:23]
  wire [31:0] arbiter_io_output_miso_data; // @[YJTop.scala 43:23]
  wire [3:0] arbiter_io_output_sel; // @[YJTop.scala 43:23]
  wire  arbiter_io_output_ack; // @[YJTop.scala 43:23]
  wire  arbiter_io_output_stall; // @[YJTop.scala 43:23]
  wire  arbiter_io_output_error; // @[YJTop.scala 43:23]
  wire  interconnect__clock; // @[YJTop.scala 48:28]
  wire  interconnect__reset; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_0_cyc; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_0_stb; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_0_we; // @[YJTop.scala 48:28]
  wire [31:0] interconnect__io_devices_0_addr; // @[YJTop.scala 48:28]
  wire [31:0] interconnect__io_devices_0_mosi_data; // @[YJTop.scala 48:28]
  wire [31:0] interconnect__io_devices_0_miso_data; // @[YJTop.scala 48:28]
  wire [3:0] interconnect__io_devices_0_sel; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_0_ack; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_0_stall; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_1_cyc; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_1_stb; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_1_we; // @[YJTop.scala 48:28]
  wire [31:0] interconnect__io_devices_1_mosi_data; // @[YJTop.scala 48:28]
  wire [31:0] interconnect__io_devices_1_miso_data; // @[YJTop.scala 48:28]
  wire [3:0] interconnect__io_devices_1_sel; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_1_ack; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_2_cyc; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_2_stb; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_2_we; // @[YJTop.scala 48:28]
  wire [31:0] interconnect__io_devices_2_addr; // @[YJTop.scala 48:28]
  wire [31:0] interconnect__io_devices_2_mosi_data; // @[YJTop.scala 48:28]
  wire [31:0] interconnect__io_devices_2_miso_data; // @[YJTop.scala 48:28]
  wire [3:0] interconnect__io_devices_2_sel; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_2_ack; // @[YJTop.scala 48:28]
  wire  interconnect__io_devices_2_stall; // @[YJTop.scala 48:28]
  wire  interconnect__io_master_cyc; // @[YJTop.scala 48:28]
  wire  interconnect__io_master_stb; // @[YJTop.scala 48:28]
  wire  interconnect__io_master_we; // @[YJTop.scala 48:28]
  wire [31:0] interconnect__io_master_addr; // @[YJTop.scala 48:28]
  wire [31:0] interconnect__io_master_mosi_data; // @[YJTop.scala 48:28]
  wire [31:0] interconnect__io_master_miso_data; // @[YJTop.scala 48:28]
  wire [3:0] interconnect__io_master_sel; // @[YJTop.scala 48:28]
  wire  interconnect__io_master_ack; // @[YJTop.scala 48:28]
  wire  interconnect__io_master_stall; // @[YJTop.scala 48:28]
  wire  interconnect__io_master_error; // @[YJTop.scala 48:28]
  YJTopWrapper proc ( // @[YJTop.scala 25:20]
    .clock(proc_clock),
    .reset(proc_reset),
    .io_procReset(proc_io_procReset),
    .io_fetchWb_cyc(proc_io_fetchWb_cyc),
    .io_fetchWb_stb(proc_io_fetchWb_stb),
    .io_fetchWb_we(proc_io_fetchWb_we),
    .io_fetchWb_addr(proc_io_fetchWb_addr),
    .io_fetchWb_mosi_data(proc_io_fetchWb_mosi_data),
    .io_fetchWb_miso_data(proc_io_fetchWb_miso_data),
    .io_fetchWb_sel(proc_io_fetchWb_sel),
    .io_fetchWb_ack(proc_io_fetchWb_ack),
    .io_fetchWb_stall(proc_io_fetchWb_stall),
    .io_memWb_cyc(proc_io_memWb_cyc),
    .io_memWb_stb(proc_io_memWb_stb),
    .io_memWb_we(proc_io_memWb_we),
    .io_memWb_addr(proc_io_memWb_addr),
    .io_memWb_mosi_data(proc_io_memWb_mosi_data),
    .io_memWb_miso_data(proc_io_memWb_miso_data),
    .io_memWb_sel(proc_io_memWb_sel),
    .io_memWb_ack(proc_io_memWb_ack),
    .io_memWb_stall(proc_io_memWb_stall)
  );
  WBLeds leds ( // @[YJTop.scala 28:20]
    .clock(leds_clock),
    .reset(leds_reset),
    .io_leds(leds_io_leds),
    .io_wb_cyc(leds_io_wb_cyc),
    .io_wb_stb(leds_io_wb_stb),
    .io_wb_we(leds_io_wb_we),
    .io_wb_mosi_data(leds_io_wb_mosi_data),
    .io_wb_miso_data(leds_io_wb_miso_data),
    .io_wb_sel(leds_io_wb_sel),
    .io_wb_ack(leds_io_wb_ack)
  );
  WBUartIhexWrapper ihexUart ( // @[YJTop.scala 31:24]
    .clock(ihexUart_clock),
    .reset(ihexUart_reset),
    .io_rx(ihexUart_io_rx),
    .io_tx(ihexUart_io_tx),
    .io_masterWb_cyc(ihexUart_io_masterWb_cyc),
    .io_masterWb_stb(ihexUart_io_masterWb_stb),
    .io_masterWb_we(ihexUart_io_masterWb_we),
    .io_masterWb_addr(ihexUart_io_masterWb_addr),
    .io_masterWb_mosi_data(ihexUart_io_masterWb_mosi_data),
    .io_masterWb_miso_data(ihexUart_io_masterWb_miso_data),
    .io_masterWb_sel(ihexUart_io_masterWb_sel),
    .io_masterWb_ack(ihexUart_io_masterWb_ack),
    .io_masterWb_stall(ihexUart_io_masterWb_stall),
    .io_masterWb_error(ihexUart_io_masterWb_error),
    .io_slaveWb_cyc(ihexUart_io_slaveWb_cyc),
    .io_slaveWb_stb(ihexUart_io_slaveWb_stb),
    .io_slaveWb_we(ihexUart_io_slaveWb_we),
    .io_slaveWb_addr(ihexUart_io_slaveWb_addr),
    .io_slaveWb_mosi_data(ihexUart_io_slaveWb_mosi_data),
    .io_slaveWb_miso_data(ihexUart_io_slaveWb_miso_data),
    .io_slaveWb_sel(ihexUart_io_slaveWb_sel),
    .io_slaveWb_ack(ihexUart_io_slaveWb_ack),
    .io_slaveWb_stall(ihexUart_io_slaveWb_stall)
  );
  BlockRam blockram ( // @[YJTop.scala 41:24]
    .clock(blockram_clock),
    .reset(blockram_reset),
    .io_wb_cyc(blockram_io_wb_cyc),
    .io_wb_stb(blockram_io_wb_stb),
    .io_wb_we(blockram_io_wb_we),
    .io_wb_addr(blockram_io_wb_addr),
    .io_wb_mosi_data(blockram_io_wb_mosi_data),
    .io_wb_miso_data(blockram_io_wb_miso_data),
    .io_wb_sel(blockram_io_wb_sel),
    .io_wb_ack(blockram_io_wb_ack),
    .io_wb_stall(blockram_io_wb_stall)
  );
  WBArbiter arbiter ( // @[YJTop.scala 43:23]
    .clock(arbiter_clock),
    .reset(arbiter_reset),
    .io_masters_0_cyc(arbiter_io_masters_0_cyc),
    .io_masters_0_stb(arbiter_io_masters_0_stb),
    .io_masters_0_we(arbiter_io_masters_0_we),
    .io_masters_0_addr(arbiter_io_masters_0_addr),
    .io_masters_0_mosi_data(arbiter_io_masters_0_mosi_data),
    .io_masters_0_miso_data(arbiter_io_masters_0_miso_data),
    .io_masters_0_sel(arbiter_io_masters_0_sel),
    .io_masters_0_ack(arbiter_io_masters_0_ack),
    .io_masters_0_stall(arbiter_io_masters_0_stall),
    .io_masters_0_error(arbiter_io_masters_0_error),
    .io_masters_1_cyc(arbiter_io_masters_1_cyc),
    .io_masters_1_stb(arbiter_io_masters_1_stb),
    .io_masters_1_we(arbiter_io_masters_1_we),
    .io_masters_1_addr(arbiter_io_masters_1_addr),
    .io_masters_1_mosi_data(arbiter_io_masters_1_mosi_data),
    .io_masters_1_miso_data(arbiter_io_masters_1_miso_data),
    .io_masters_1_sel(arbiter_io_masters_1_sel),
    .io_masters_1_ack(arbiter_io_masters_1_ack),
    .io_masters_1_stall(arbiter_io_masters_1_stall),
    .io_masters_2_cyc(arbiter_io_masters_2_cyc),
    .io_masters_2_stb(arbiter_io_masters_2_stb),
    .io_masters_2_we(arbiter_io_masters_2_we),
    .io_masters_2_addr(arbiter_io_masters_2_addr),
    .io_masters_2_mosi_data(arbiter_io_masters_2_mosi_data),
    .io_masters_2_miso_data(arbiter_io_masters_2_miso_data),
    .io_masters_2_sel(arbiter_io_masters_2_sel),
    .io_masters_2_ack(arbiter_io_masters_2_ack),
    .io_masters_2_stall(arbiter_io_masters_2_stall),
    .io_output_cyc(arbiter_io_output_cyc),
    .io_output_stb(arbiter_io_output_stb),
    .io_output_we(arbiter_io_output_we),
    .io_output_addr(arbiter_io_output_addr),
    .io_output_mosi_data(arbiter_io_output_mosi_data),
    .io_output_miso_data(arbiter_io_output_miso_data),
    .io_output_sel(arbiter_io_output_sel),
    .io_output_ack(arbiter_io_output_ack),
    .io_output_stall(arbiter_io_output_stall),
    .io_output_error(arbiter_io_output_error)
  );
  WBInterconnect interconnect_ ( // @[YJTop.scala 48:28]
    .clock(interconnect__clock),
    .reset(interconnect__reset),
    .io_devices_0_cyc(interconnect__io_devices_0_cyc),
    .io_devices_0_stb(interconnect__io_devices_0_stb),
    .io_devices_0_we(interconnect__io_devices_0_we),
    .io_devices_0_addr(interconnect__io_devices_0_addr),
    .io_devices_0_mosi_data(interconnect__io_devices_0_mosi_data),
    .io_devices_0_miso_data(interconnect__io_devices_0_miso_data),
    .io_devices_0_sel(interconnect__io_devices_0_sel),
    .io_devices_0_ack(interconnect__io_devices_0_ack),
    .io_devices_0_stall(interconnect__io_devices_0_stall),
    .io_devices_1_cyc(interconnect__io_devices_1_cyc),
    .io_devices_1_stb(interconnect__io_devices_1_stb),
    .io_devices_1_we(interconnect__io_devices_1_we),
    .io_devices_1_mosi_data(interconnect__io_devices_1_mosi_data),
    .io_devices_1_miso_data(interconnect__io_devices_1_miso_data),
    .io_devices_1_sel(interconnect__io_devices_1_sel),
    .io_devices_1_ack(interconnect__io_devices_1_ack),
    .io_devices_2_cyc(interconnect__io_devices_2_cyc),
    .io_devices_2_stb(interconnect__io_devices_2_stb),
    .io_devices_2_we(interconnect__io_devices_2_we),
    .io_devices_2_addr(interconnect__io_devices_2_addr),
    .io_devices_2_mosi_data(interconnect__io_devices_2_mosi_data),
    .io_devices_2_miso_data(interconnect__io_devices_2_miso_data),
    .io_devices_2_sel(interconnect__io_devices_2_sel),
    .io_devices_2_ack(interconnect__io_devices_2_ack),
    .io_devices_2_stall(interconnect__io_devices_2_stall),
    .io_master_cyc(interconnect__io_master_cyc),
    .io_master_stb(interconnect__io_master_stb),
    .io_master_we(interconnect__io_master_we),
    .io_master_addr(interconnect__io_master_addr),
    .io_master_mosi_data(interconnect__io_master_mosi_data),
    .io_master_miso_data(interconnect__io_master_miso_data),
    .io_master_sel(interconnect__io_master_sel),
    .io_master_ack(interconnect__io_master_ack),
    .io_master_stall(interconnect__io_master_stall),
    .io_master_error(interconnect__io_master_error)
  );
  assign io_sdram_addr = 12'h0;
  assign io_sdram_bank = 2'h0;
  assign io_sdram_dataOut = 16'h0;
  assign io_sdram_dqm = 2'h0;
  assign io_sdram_clk = 1'h0;
  assign io_sdram_cke = 1'h0;
  assign io_sdram_cs_n = 1'h0;
  assign io_sdram_ras_n = 1'h0;
  assign io_sdram_cas_n = 1'h0;
  assign io_sdram_we_n = 1'h0;
  assign io_sdram_output_en = 1'h0; // @[YJTop.scala 39:22]
  assign io_leds = leds_io_leds; // @[YJTop.scala 29:16]
  assign io_tx = ihexUart_io_tx; // @[YJTop.scala 33:9]
  assign proc_clock = clock;
  assign proc_reset = reset;
  assign proc_io_procReset = io_procReset; // @[YJTop.scala 26:21]
  assign proc_io_fetchWb_miso_data = arbiter_io_masters_2_miso_data; // @[YJTop.scala 46:25]
  assign proc_io_fetchWb_ack = arbiter_io_masters_2_ack; // @[YJTop.scala 46:25]
  assign proc_io_fetchWb_stall = arbiter_io_masters_2_stall; // @[YJTop.scala 46:25]
  assign proc_io_memWb_miso_data = arbiter_io_masters_1_miso_data; // @[YJTop.scala 45:25]
  assign proc_io_memWb_ack = arbiter_io_masters_1_ack; // @[YJTop.scala 45:25]
  assign proc_io_memWb_stall = arbiter_io_masters_1_stall; // @[YJTop.scala 45:25]
  assign leds_clock = clock;
  assign leds_reset = reset;
  assign leds_io_wb_cyc = interconnect__io_devices_1_cyc; // @[YJTop.scala 55:30]
  assign leds_io_wb_stb = interconnect__io_devices_1_stb; // @[YJTop.scala 55:30]
  assign leds_io_wb_we = interconnect__io_devices_1_we; // @[YJTop.scala 55:30]
  assign leds_io_wb_mosi_data = interconnect__io_devices_1_mosi_data; // @[YJTop.scala 55:30]
  assign leds_io_wb_sel = interconnect__io_devices_1_sel; // @[YJTop.scala 55:30]
  assign ihexUart_clock = clock;
  assign ihexUart_reset = reset;
  assign ihexUart_io_rx = io_rx; // @[YJTop.scala 32:18]
  assign ihexUart_io_masterWb_miso_data = arbiter_io_masters_0_miso_data; // @[YJTop.scala 44:25]
  assign ihexUart_io_masterWb_ack = arbiter_io_masters_0_ack; // @[YJTop.scala 44:25]
  assign ihexUart_io_masterWb_stall = arbiter_io_masters_0_stall; // @[YJTop.scala 44:25]
  assign ihexUart_io_masterWb_error = arbiter_io_masters_0_error; // @[YJTop.scala 44:25]
  assign ihexUart_io_slaveWb_cyc = interconnect__io_devices_2_cyc; // @[YJTop.scala 56:30]
  assign ihexUart_io_slaveWb_stb = interconnect__io_devices_2_stb; // @[YJTop.scala 56:30]
  assign ihexUart_io_slaveWb_we = interconnect__io_devices_2_we; // @[YJTop.scala 56:30]
  assign ihexUart_io_slaveWb_addr = interconnect__io_devices_2_addr; // @[YJTop.scala 56:30]
  assign ihexUart_io_slaveWb_mosi_data = interconnect__io_devices_2_mosi_data; // @[YJTop.scala 56:30]
  assign ihexUart_io_slaveWb_sel = interconnect__io_devices_2_sel; // @[YJTop.scala 56:30]
  assign blockram_clock = clock;
  assign blockram_reset = reset;
  assign blockram_io_wb_cyc = interconnect__io_devices_0_cyc; // @[YJTop.scala 54:30]
  assign blockram_io_wb_stb = interconnect__io_devices_0_stb; // @[YJTop.scala 54:30]
  assign blockram_io_wb_we = interconnect__io_devices_0_we; // @[YJTop.scala 54:30]
  assign blockram_io_wb_addr = interconnect__io_devices_0_addr; // @[YJTop.scala 54:30]
  assign blockram_io_wb_mosi_data = interconnect__io_devices_0_mosi_data; // @[YJTop.scala 54:30]
  assign blockram_io_wb_sel = interconnect__io_devices_0_sel; // @[YJTop.scala 54:30]
  assign arbiter_clock = clock;
  assign arbiter_reset = reset;
  assign arbiter_io_masters_0_cyc = ihexUart_io_masterWb_cyc; // @[YJTop.scala 44:25]
  assign arbiter_io_masters_0_stb = ihexUart_io_masterWb_stb; // @[YJTop.scala 44:25]
  assign arbiter_io_masters_0_we = ihexUart_io_masterWb_we; // @[YJTop.scala 44:25]
  assign arbiter_io_masters_0_addr = ihexUart_io_masterWb_addr; // @[YJTop.scala 44:25]
  assign arbiter_io_masters_0_mosi_data = ihexUart_io_masterWb_mosi_data; // @[YJTop.scala 44:25]
  assign arbiter_io_masters_0_sel = ihexUart_io_masterWb_sel; // @[YJTop.scala 44:25]
  assign arbiter_io_masters_1_cyc = proc_io_memWb_cyc; // @[YJTop.scala 45:25]
  assign arbiter_io_masters_1_stb = proc_io_memWb_stb; // @[YJTop.scala 45:25]
  assign arbiter_io_masters_1_we = proc_io_memWb_we; // @[YJTop.scala 45:25]
  assign arbiter_io_masters_1_addr = proc_io_memWb_addr; // @[YJTop.scala 45:25]
  assign arbiter_io_masters_1_mosi_data = proc_io_memWb_mosi_data; // @[YJTop.scala 45:25]
  assign arbiter_io_masters_1_sel = proc_io_memWb_sel; // @[YJTop.scala 45:25]
  assign arbiter_io_masters_2_cyc = proc_io_fetchWb_cyc; // @[YJTop.scala 46:25]
  assign arbiter_io_masters_2_stb = proc_io_fetchWb_stb; // @[YJTop.scala 46:25]
  assign arbiter_io_masters_2_we = proc_io_fetchWb_we; // @[YJTop.scala 46:25]
  assign arbiter_io_masters_2_addr = proc_io_fetchWb_addr; // @[YJTop.scala 46:25]
  assign arbiter_io_masters_2_mosi_data = proc_io_fetchWb_mosi_data; // @[YJTop.scala 46:25]
  assign arbiter_io_masters_2_sel = proc_io_fetchWb_sel; // @[YJTop.scala 46:25]
  assign arbiter_io_output_miso_data = interconnect__io_master_miso_data; // @[YJTop.scala 58:26]
  assign arbiter_io_output_ack = interconnect__io_master_ack; // @[YJTop.scala 58:26]
  assign arbiter_io_output_stall = interconnect__io_master_stall; // @[YJTop.scala 58:26]
  assign arbiter_io_output_error = interconnect__io_master_error; // @[YJTop.scala 58:26]
  assign interconnect__clock = clock;
  assign interconnect__reset = reset;
  assign interconnect__io_devices_0_miso_data = blockram_io_wb_miso_data; // @[YJTop.scala 54:30]
  assign interconnect__io_devices_0_ack = blockram_io_wb_ack; // @[YJTop.scala 54:30]
  assign interconnect__io_devices_0_stall = blockram_io_wb_stall; // @[YJTop.scala 54:30]
  assign interconnect__io_devices_1_miso_data = leds_io_wb_miso_data; // @[YJTop.scala 55:30]
  assign interconnect__io_devices_1_ack = leds_io_wb_ack; // @[YJTop.scala 55:30]
  assign interconnect__io_devices_2_miso_data = ihexUart_io_slaveWb_miso_data; // @[YJTop.scala 56:30]
  assign interconnect__io_devices_2_ack = ihexUart_io_slaveWb_ack; // @[YJTop.scala 56:30]
  assign interconnect__io_devices_2_stall = ihexUart_io_slaveWb_stall; // @[YJTop.scala 56:30]
  assign interconnect__io_master_cyc = arbiter_io_output_cyc; // @[YJTop.scala 58:26]
  assign interconnect__io_master_stb = arbiter_io_output_stb; // @[YJTop.scala 58:26]
  assign interconnect__io_master_we = arbiter_io_output_we; // @[YJTop.scala 58:26]
  assign interconnect__io_master_addr = arbiter_io_output_addr; // @[YJTop.scala 58:26]
  assign interconnect__io_master_mosi_data = arbiter_io_output_mosi_data; // @[YJTop.scala 58:26]
  assign interconnect__io_master_sel = arbiter_io_output_sel; // @[YJTop.scala 58:26]
endmodule
