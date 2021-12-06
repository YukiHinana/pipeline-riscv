;buildInfoPackage: chisel3, version: 3.4.3, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit YJTop : 
  extmodule top : 
    input clk : Clock
    input reset : Reset
    output wb2_cyc : UInt<1>
    output wb2_stb : UInt<1>
    output wb2_we : UInt<1>
    output wb2_sel : UInt<4>
    input wb2_stall : UInt<1>
    input wb2_ack : UInt<1>
    output wb2_addr : UInt<30>
    output wb2_mosi_data : UInt<32>
    input wb2_miso_data : UInt<32>
    output wb_cyc : UInt<1>
    output wb_stb : UInt<1>
    output wb_we : UInt<1>
    output wb_sel : UInt<4>
    input wb_stall : UInt<1>
    input wb_ack : UInt<1>
    output wb_addr : UInt<30>
    output wb_mosi_data : UInt<32>
    input wb_miso_data : UInt<32>
    
    defname = top
    
    
  module YJTopWrapper : 
    input clock : Clock
    input reset : Reset
    output io : {flip procReset : UInt<1>, flip fetchWb : {flip cyc : UInt<1>, flip stb : UInt<1>, flip we : UInt<1>, flip addr : UInt<32>, flip mosi_data : UInt<32>, miso_data : UInt<32>, flip sel : UInt<4>, ack : UInt<1>, stall : UInt<1>, error : UInt<1>}, flip memWb : {flip cyc : UInt<1>, flip stb : UInt<1>, flip we : UInt<1>, flip addr : UInt<32>, flip mosi_data : UInt<32>, miso_data : UInt<32>, flip sel : UInt<4>, ack : UInt<1>, stall : UInt<1>, error : UInt<1>}}
    
    inst top of top @[YJTopWrapper.scala 13:19]
    top.wb_miso_data is invalid
    top.wb_mosi_data is invalid
    top.wb_addr is invalid
    top.wb_ack is invalid
    top.wb_stall is invalid
    top.wb_sel is invalid
    top.wb_we is invalid
    top.wb_stb is invalid
    top.wb_cyc is invalid
    top.wb2_miso_data is invalid
    top.wb2_mosi_data is invalid
    top.wb2_addr is invalid
    top.wb2_ack is invalid
    top.wb2_stall is invalid
    top.wb2_sel is invalid
    top.wb2_we is invalid
    top.wb2_stb is invalid
    top.wb2_cyc is invalid
    top.reset is invalid
    top.clk is invalid
    top.clk <= clock @[YJTopWrapper.scala 15:14]
    node _top_io_reset_T = asUInt(reset) @[YJTopWrapper.scala 16:32]
    node _top_io_reset_T_1 = or(_top_io_reset_T, io.procReset) @[YJTopWrapper.scala 16:35]
    top.reset <= _top_io_reset_T_1 @[YJTopWrapper.scala 16:16]
    io.fetchWb.cyc <= top.wb2_cyc @[YJTopWrapper.scala 19:15]
    io.fetchWb.stb <= top.wb2_stb @[YJTopWrapper.scala 20:15]
    io.fetchWb.we <= top.wb2_we @[YJTopWrapper.scala 21:14]
    io.fetchWb.sel <= top.wb2_sel @[YJTopWrapper.scala 22:15]
    top.wb2_stall <= io.fetchWb.stall @[YJTopWrapper.scala 23:17]
    top.wb2_ack <= io.fetchWb.ack @[YJTopWrapper.scala 24:15]
    io.fetchWb.addr <= top.wb2_addr @[YJTopWrapper.scala 25:16]
    io.fetchWb.mosi_data <= top.wb2_mosi_data @[YJTopWrapper.scala 26:21]
    top.wb2_miso_data <= io.fetchWb.miso_data @[YJTopWrapper.scala 27:21]
    io.memWb.cyc <= top.wb_cyc @[YJTopWrapper.scala 30:13]
    io.memWb.stb <= top.wb_stb @[YJTopWrapper.scala 31:13]
    io.memWb.we <= top.wb_we @[YJTopWrapper.scala 32:12]
    io.memWb.sel <= top.wb_sel @[YJTopWrapper.scala 33:13]
    top.wb_stall <= io.memWb.stall @[YJTopWrapper.scala 34:15]
    top.wb_ack <= io.memWb.ack @[YJTopWrapper.scala 35:13]
    io.memWb.addr <= top.wb_addr @[YJTopWrapper.scala 36:14]
    io.memWb.mosi_data <= top.wb_mosi_data @[YJTopWrapper.scala 37:19]
    top.wb_miso_data <= io.memWb.miso_data @[YJTopWrapper.scala 38:19]
    
  module WBLeds : 
    input clock : Clock
    input reset : Reset
    output io : {leds : UInt<16>, wb : {flip cyc : UInt<1>, flip stb : UInt<1>, flip we : UInt<1>, flip addr : UInt<32>, flip mosi_data : UInt<32>, miso_data : UInt<32>, flip sel : UInt<4>, ack : UInt<1>, stall : UInt<1>, error : UInt<1>}}
    
    io.wb.stall <= UInt<1>("h00") @[WBLeds.scala 16:15]
    io.wb.error <= UInt<1>("h00") @[WBLeds.scala 17:15]
    wire _ledBuf_WIRE : UInt<8>[2] @[WBLeds.scala 19:31]
    _ledBuf_WIRE[0] <= UInt<8>("h00") @[WBLeds.scala 19:31]
    _ledBuf_WIRE[1] <= UInt<8>("h00") @[WBLeds.scala 19:31]
    reg ledBuf : UInt<8>[2], clock with : (reset => (reset, _ledBuf_WIRE)) @[WBLeds.scala 19:23]
    node _io_leds_T = cat(ledBuf[1], ledBuf[0]) @[WBLeds.scala 23:29]
    io.leds <= _io_leds_T @[WBLeds.scala 23:13]
    node _io_wb_miso_data_T = cat(ledBuf[1], ledBuf[0]) @[WBLeds.scala 26:35]
    io.wb.miso_data <= _io_wb_miso_data_T @[WBLeds.scala 26:19]
    io.wb.ack <= UInt<1>("h00") @[WBLeds.scala 27:13]
    node _T = and(io.wb.cyc, io.wb.stb) @[WBLeds.scala 28:18]
    when _T : @[WBLeds.scala 28:32]
      io.wb.ack <= UInt<1>("h01") @[WBLeds.scala 29:15]
      when io.wb.we : @[WBLeds.scala 30:20]
        node _T_1 = bits(io.wb.sel, 0, 0) @[WBLeds.scala 32:23]
        when _T_1 : @[WBLeds.scala 32:28]
          node _ledBuf_0_T = bits(io.wb.mosi_data, 7, 0) @[WBLeds.scala 33:39]
          ledBuf[0] <= _ledBuf_0_T @[WBLeds.scala 33:21]
          skip @[WBLeds.scala 32:28]
        node _T_2 = bits(io.wb.sel, 1, 1) @[WBLeds.scala 32:23]
        when _T_2 : @[WBLeds.scala 32:28]
          node _ledBuf_1_T = bits(io.wb.mosi_data, 15, 8) @[WBLeds.scala 33:39]
          ledBuf[1] <= _ledBuf_1_T @[WBLeds.scala 33:21]
          skip @[WBLeds.scala 32:28]
        skip @[WBLeds.scala 30:20]
      skip @[WBLeds.scala 28:32]
    
  extmodule WBUartWithIhex : 
    input i_clk : Clock
    input i_reset : Reset
    input i_rx : UInt<1>
    output o_tx : UInt<1>
    output o_mwb_cyc : UInt<1>
    output o_mwb_stb : UInt<1>
    output o_mwb_we : UInt<1>
    output o_mwb_sel : UInt<4>
    input i_mwb_stall : UInt<1>
    input i_mwb_ack : UInt<1>
    input i_mwb_err : UInt<1>
    output o_mwb_addr : UInt<30>
    output o_mwb_data : UInt<32>
    input i_mwb_data : UInt<32>
    input i_wb_cyc : UInt<1>
    input i_wb_stb : UInt<1>
    input i_wb_we : UInt<1>
    input i_wb_sel : UInt<4>
    output o_wb_stall : UInt<1>
    output o_wb_ack : UInt<1>
    output o_wb_err : UInt<1>
    input i_wb_addr : UInt<30>
    input i_wb_data : UInt<32>
    output o_wb_data : UInt<32>
    
    defname = WBUartWithIhex
    parameter I_CLOCK_FREQ = 50000000
    parameter BAUD_RATE = 115200
    
  module WBUartIhexWrapper : 
    input clock : Clock
    input reset : Reset
    output io : {flip rx : UInt<1>, tx : UInt<1>, flip masterWb : {flip cyc : UInt<1>, flip stb : UInt<1>, flip we : UInt<1>, flip addr : UInt<32>, flip mosi_data : UInt<32>, miso_data : UInt<32>, flip sel : UInt<4>, ack : UInt<1>, stall : UInt<1>, error : UInt<1>}, slaveWb : {flip cyc : UInt<1>, flip stb : UInt<1>, flip we : UInt<1>, flip addr : UInt<32>, flip mosi_data : UInt<32>, miso_data : UInt<32>, flip sel : UInt<4>, ack : UInt<1>, stall : UInt<1>, error : UInt<1>}}
    
    inst m of WBUartWithIhex @[WBUartIhexWrapper.scala 15:17]
    m.o_wb_data is invalid
    m.i_wb_data is invalid
    m.i_wb_addr is invalid
    m.o_wb_err is invalid
    m.o_wb_ack is invalid
    m.o_wb_stall is invalid
    m.i_wb_sel is invalid
    m.i_wb_we is invalid
    m.i_wb_stb is invalid
    m.i_wb_cyc is invalid
    m.i_mwb_data is invalid
    m.o_mwb_data is invalid
    m.o_mwb_addr is invalid
    m.i_mwb_err is invalid
    m.i_mwb_ack is invalid
    m.i_mwb_stall is invalid
    m.o_mwb_sel is invalid
    m.o_mwb_we is invalid
    m.o_mwb_stb is invalid
    m.o_mwb_cyc is invalid
    m.o_tx is invalid
    m.i_rx is invalid
    m.i_reset is invalid
    m.i_clk is invalid
    m.i_clk <= clock @[WBUartIhexWrapper.scala 16:14]
    m.i_reset <= reset @[WBUartIhexWrapper.scala 17:16]
    m.i_rx <= io.rx @[WBUartIhexWrapper.scala 19:13]
    io.tx <= m.o_tx @[WBUartIhexWrapper.scala 20:9]
    io.masterWb.cyc <= m.o_mwb_cyc @[WBUartIhexWrapper.scala 23:11]
    io.masterWb.stb <= m.o_mwb_stb @[WBUartIhexWrapper.scala 24:11]
    io.masterWb.we <= m.o_mwb_we @[WBUartIhexWrapper.scala 25:10]
    io.masterWb.sel <= m.o_mwb_sel @[WBUartIhexWrapper.scala 26:11]
    m.i_mwb_stall <= io.masterWb.stall @[WBUartIhexWrapper.scala 27:13]
    m.i_mwb_ack <= io.masterWb.ack @[WBUartIhexWrapper.scala 28:11]
    m.i_mwb_err <= io.masterWb.error @[WBUartIhexWrapper.scala 29:13]
    io.masterWb.addr <= m.o_mwb_addr @[WBUartIhexWrapper.scala 30:12]
    io.masterWb.mosi_data <= m.o_mwb_data @[WBUartIhexWrapper.scala 31:17]
    m.i_mwb_data <= io.masterWb.miso_data @[WBUartIhexWrapper.scala 32:17]
    m.i_wb_cyc <= io.slaveWb.cyc @[WBUartIhexWrapper.scala 35:11]
    m.i_wb_stb <= io.slaveWb.stb @[WBUartIhexWrapper.scala 36:11]
    m.i_wb_we <= io.slaveWb.we @[WBUartIhexWrapper.scala 37:10]
    m.i_wb_sel <= io.slaveWb.sel @[WBUartIhexWrapper.scala 38:11]
    io.slaveWb.stall <= m.o_wb_stall @[WBUartIhexWrapper.scala 39:13]
    io.slaveWb.ack <= m.o_wb_ack @[WBUartIhexWrapper.scala 40:11]
    io.slaveWb.error <= m.o_wb_err @[WBUartIhexWrapper.scala 41:13]
    m.i_wb_addr <= io.slaveWb.addr @[WBUartIhexWrapper.scala 42:12]
    m.i_wb_data <= io.slaveWb.mosi_data @[WBUartIhexWrapper.scala 43:17]
    io.slaveWb.miso_data <= m.o_wb_data @[WBUartIhexWrapper.scala 44:17]
    
  extmodule SinglePortRam : 
    input clock : Clock
    input addr : UInt<13>
    input we : UInt<1>
    output data_out : UInt<8>
    input data_in : UInt<8>
    
    defname = SinglePortRam
    parameter AW = 13
    
  extmodule SinglePortRam_1 : 
    input clock : Clock
    input addr : UInt<13>
    input we : UInt<1>
    output data_out : UInt<8>
    input data_in : UInt<8>
    
    defname = SinglePortRam
    parameter AW = 13
    
  extmodule SinglePortRam_2 : 
    input clock : Clock
    input addr : UInt<13>
    input we : UInt<1>
    output data_out : UInt<8>
    input data_in : UInt<8>
    
    defname = SinglePortRam
    parameter AW = 13
    
  extmodule SinglePortRam_3 : 
    input clock : Clock
    input addr : UInt<13>
    input we : UInt<1>
    output data_out : UInt<8>
    input data_in : UInt<8>
    
    defname = SinglePortRam
    parameter AW = 13
    
  module BlockRam : 
    input clock : Clock
    input reset : Reset
    output io : {wb : {flip cyc : UInt<1>, flip stb : UInt<1>, flip we : UInt<1>, flip addr : UInt<32>, flip mosi_data : UInt<32>, miso_data : UInt<32>, flip sel : UInt<4>, ack : UInt<1>, stall : UInt<1>, error : UInt<1>}}
    
    inst rams_0 of SinglePortRam @[BlockRam.scala 14:11]
    rams_0.data_in is invalid
    rams_0.data_out is invalid
    rams_0.we is invalid
    rams_0.addr is invalid
    rams_0.clock is invalid
    inst rams_1 of SinglePortRam_1 @[BlockRam.scala 14:11]
    rams_1.data_in is invalid
    rams_1.data_out is invalid
    rams_1.we is invalid
    rams_1.addr is invalid
    rams_1.clock is invalid
    inst rams_2 of SinglePortRam_2 @[BlockRam.scala 14:11]
    rams_2.data_in is invalid
    rams_2.data_out is invalid
    rams_2.we is invalid
    rams_2.addr is invalid
    rams_2.clock is invalid
    inst rams_3 of SinglePortRam_3 @[BlockRam.scala 14:11]
    rams_3.data_in is invalid
    rams_3.data_out is invalid
    rams_3.we is invalid
    rams_3.addr is invalid
    rams_3.clock is invalid
    reg state : UInt<1>, clock with : (reset => (reset, UInt<1>("h00"))) @[BlockRam.scala 21:22]
    node _io_wb_stall_T = neq(state, UInt<1>("h00")) @[BlockRam.scala 23:24]
    io.wb.stall <= _io_wb_stall_T @[BlockRam.scala 23:15]
    node _io_wb_ack_T = eq(state, UInt<1>("h01")) @[BlockRam.scala 24:22]
    io.wb.ack <= _io_wb_ack_T @[BlockRam.scala 24:13]
    rams_0.clock <= clock @[BlockRam.scala 28:18]
    node _rams_0_io_we_T = eq(state, UInt<1>("h00")) @[BlockRam.scala 29:36]
    node _rams_0_io_we_T_1 = and(io.wb.we, _rams_0_io_we_T) @[BlockRam.scala 29:27]
    node _rams_0_io_we_T_2 = and(_rams_0_io_we_T_1, io.wb.stb) @[BlockRam.scala 29:47]
    node _rams_0_io_we_T_3 = and(_rams_0_io_we_T_2, io.wb.cyc) @[BlockRam.scala 29:60]
    node _rams_0_io_we_T_4 = bits(io.wb.sel, 0, 0) @[BlockRam.scala 29:85]
    node _rams_0_io_we_T_5 = bits(_rams_0_io_we_T_4, 0, 0) @[BlockRam.scala 29:95]
    node _rams_0_io_we_T_6 = and(_rams_0_io_we_T_3, _rams_0_io_we_T_5) @[BlockRam.scala 29:73]
    rams_0.we <= _rams_0_io_we_T_6 @[BlockRam.scala 29:15]
    rams_0.addr <= io.wb.addr @[BlockRam.scala 30:17]
    node _rams_0_io_data_in_T = bits(io.wb.mosi_data, 7, 0) @[BlockRam.scala 31:38]
    rams_0.data_in <= _rams_0_io_data_in_T @[BlockRam.scala 31:20]
    rams_1.clock <= clock @[BlockRam.scala 28:18]
    node _rams_1_io_we_T = eq(state, UInt<1>("h00")) @[BlockRam.scala 29:36]
    node _rams_1_io_we_T_1 = and(io.wb.we, _rams_1_io_we_T) @[BlockRam.scala 29:27]
    node _rams_1_io_we_T_2 = and(_rams_1_io_we_T_1, io.wb.stb) @[BlockRam.scala 29:47]
    node _rams_1_io_we_T_3 = and(_rams_1_io_we_T_2, io.wb.cyc) @[BlockRam.scala 29:60]
    node _rams_1_io_we_T_4 = bits(io.wb.sel, 1, 1) @[BlockRam.scala 29:85]
    node _rams_1_io_we_T_5 = bits(_rams_1_io_we_T_4, 0, 0) @[BlockRam.scala 29:95]
    node _rams_1_io_we_T_6 = and(_rams_1_io_we_T_3, _rams_1_io_we_T_5) @[BlockRam.scala 29:73]
    rams_1.we <= _rams_1_io_we_T_6 @[BlockRam.scala 29:15]
    rams_1.addr <= io.wb.addr @[BlockRam.scala 30:17]
    node _rams_1_io_data_in_T = bits(io.wb.mosi_data, 15, 8) @[BlockRam.scala 31:38]
    rams_1.data_in <= _rams_1_io_data_in_T @[BlockRam.scala 31:20]
    rams_2.clock <= clock @[BlockRam.scala 28:18]
    node _rams_2_io_we_T = eq(state, UInt<1>("h00")) @[BlockRam.scala 29:36]
    node _rams_2_io_we_T_1 = and(io.wb.we, _rams_2_io_we_T) @[BlockRam.scala 29:27]
    node _rams_2_io_we_T_2 = and(_rams_2_io_we_T_1, io.wb.stb) @[BlockRam.scala 29:47]
    node _rams_2_io_we_T_3 = and(_rams_2_io_we_T_2, io.wb.cyc) @[BlockRam.scala 29:60]
    node _rams_2_io_we_T_4 = bits(io.wb.sel, 2, 2) @[BlockRam.scala 29:85]
    node _rams_2_io_we_T_5 = bits(_rams_2_io_we_T_4, 0, 0) @[BlockRam.scala 29:95]
    node _rams_2_io_we_T_6 = and(_rams_2_io_we_T_3, _rams_2_io_we_T_5) @[BlockRam.scala 29:73]
    rams_2.we <= _rams_2_io_we_T_6 @[BlockRam.scala 29:15]
    rams_2.addr <= io.wb.addr @[BlockRam.scala 30:17]
    node _rams_2_io_data_in_T = bits(io.wb.mosi_data, 23, 16) @[BlockRam.scala 31:38]
    rams_2.data_in <= _rams_2_io_data_in_T @[BlockRam.scala 31:20]
    rams_3.clock <= clock @[BlockRam.scala 28:18]
    node _rams_3_io_we_T = eq(state, UInt<1>("h00")) @[BlockRam.scala 29:36]
    node _rams_3_io_we_T_1 = and(io.wb.we, _rams_3_io_we_T) @[BlockRam.scala 29:27]
    node _rams_3_io_we_T_2 = and(_rams_3_io_we_T_1, io.wb.stb) @[BlockRam.scala 29:47]
    node _rams_3_io_we_T_3 = and(_rams_3_io_we_T_2, io.wb.cyc) @[BlockRam.scala 29:60]
    node _rams_3_io_we_T_4 = bits(io.wb.sel, 3, 3) @[BlockRam.scala 29:85]
    node _rams_3_io_we_T_5 = bits(_rams_3_io_we_T_4, 0, 0) @[BlockRam.scala 29:95]
    node _rams_3_io_we_T_6 = and(_rams_3_io_we_T_3, _rams_3_io_we_T_5) @[BlockRam.scala 29:73]
    rams_3.we <= _rams_3_io_we_T_6 @[BlockRam.scala 29:15]
    rams_3.addr <= io.wb.addr @[BlockRam.scala 30:17]
    node _rams_3_io_data_in_T = bits(io.wb.mosi_data, 31, 24) @[BlockRam.scala 31:38]
    rams_3.data_in <= _rams_3_io_data_in_T @[BlockRam.scala 31:20]
    node io_wb_miso_data_lo = cat(rams_1.data_out, rams_0.data_out) @[Cat.scala 30:58]
    node io_wb_miso_data_hi = cat(rams_3.data_out, rams_2.data_out) @[Cat.scala 30:58]
    node _io_wb_miso_data_T = cat(io_wb_miso_data_hi, io_wb_miso_data_lo) @[Cat.scala 30:58]
    io.wb.miso_data <= _io_wb_miso_data_T @[BlockRam.scala 34:19]
    io.wb.error <= UInt<1>("h00") @[BlockRam.scala 35:15]
    node _T = eq(state, UInt<1>("h00")) @[BlockRam.scala 37:14]
    when _T : @[BlockRam.scala 37:26]
      node _T_1 = and(io.wb.stb, io.wb.cyc) @[BlockRam.scala 38:20]
      when _T_1 : @[BlockRam.scala 38:34]
        state <= UInt<1>("h01") @[BlockRam.scala 39:13]
        skip @[BlockRam.scala 38:34]
      skip @[BlockRam.scala 37:26]
    node _T_2 = eq(state, UInt<1>("h01")) @[BlockRam.scala 42:14]
    when _T_2 : @[BlockRam.scala 42:25]
      state <= UInt<1>("h00") @[BlockRam.scala 43:11]
      skip @[BlockRam.scala 42:25]
    
  module WBArbiter : 
    input clock : Clock
    input reset : Reset
    output io : {masters : {flip cyc : UInt<1>, flip stb : UInt<1>, flip we : UInt<1>, flip addr : UInt<32>, flip mosi_data : UInt<32>, miso_data : UInt<32>, flip sel : UInt<4>, ack : UInt<1>, stall : UInt<1>, error : UInt<1>}[3], flip output : {flip cyc : UInt<1>, flip stb : UInt<1>, flip we : UInt<1>, flip addr : UInt<32>, flip mosi_data : UInt<32>, miso_data : UInt<32>, flip sel : UInt<4>, ack : UInt<1>, stall : UInt<1>, error : UInt<1>}}
    
    io.masters[0].ack <= UInt<1>("h00") @[WBArbiter.scala 14:23]
    io.masters[0].miso_data is invalid @[WBArbiter.scala 15:29]
    io.masters[0].error <= UInt<1>("h00") @[WBArbiter.scala 16:25]
    io.masters[0].stall <= UInt<1>("h01") @[WBArbiter.scala 17:25]
    io.masters[1].ack <= UInt<1>("h00") @[WBArbiter.scala 14:23]
    io.masters[1].miso_data is invalid @[WBArbiter.scala 15:29]
    io.masters[1].error <= UInt<1>("h00") @[WBArbiter.scala 16:25]
    io.masters[1].stall <= UInt<1>("h01") @[WBArbiter.scala 17:25]
    io.masters[2].ack <= UInt<1>("h00") @[WBArbiter.scala 14:23]
    io.masters[2].miso_data is invalid @[WBArbiter.scala 15:29]
    io.masters[2].error <= UInt<1>("h00") @[WBArbiter.scala 16:25]
    io.masters[2].stall <= UInt<1>("h01") @[WBArbiter.scala 17:25]
    reg currentMaster : UInt<4>, clock with : (reset => (reset, UInt<4>("h00"))) @[WBArbiter.scala 20:30]
    wire nextMaster : UInt<4> @[WBArbiter.scala 22:24]
    nextMaster <= UInt<1>("h00") @[WBArbiter.scala 23:14]
    node _T = and(io.masters[2].cyc, io.masters[2].stb) @[WBArbiter.scala 25:28]
    when _T : @[WBArbiter.scala 25:50]
      nextMaster <= UInt<2>("h02") @[WBArbiter.scala 26:18]
      skip @[WBArbiter.scala 25:50]
    node _T_1 = and(io.masters[1].cyc, io.masters[1].stb) @[WBArbiter.scala 25:28]
    when _T_1 : @[WBArbiter.scala 25:50]
      nextMaster <= UInt<1>("h01") @[WBArbiter.scala 26:18]
      skip @[WBArbiter.scala 25:50]
    node _T_2 = and(io.masters[0].cyc, io.masters[0].stb) @[WBArbiter.scala 25:28]
    when _T_2 : @[WBArbiter.scala 25:50]
      nextMaster <= UInt<1>("h00") @[WBArbiter.scala 26:18]
      skip @[WBArbiter.scala 25:50]
    node _io_output_T = bits(currentMaster, 1, 0)
    io.masters[_io_output_T].error <= io.output.error @[WBArbiter.scala 30:13]
    io.masters[_io_output_T].stall <= io.output.stall @[WBArbiter.scala 30:13]
    io.masters[_io_output_T].ack <= io.output.ack @[WBArbiter.scala 30:13]
    io.output.sel <= io.masters[_io_output_T].sel @[WBArbiter.scala 30:13]
    io.masters[_io_output_T].miso_data <= io.output.miso_data @[WBArbiter.scala 30:13]
    io.output.mosi_data <= io.masters[_io_output_T].mosi_data @[WBArbiter.scala 30:13]
    io.output.addr <= io.masters[_io_output_T].addr @[WBArbiter.scala 30:13]
    io.output.we <= io.masters[_io_output_T].we @[WBArbiter.scala 30:13]
    io.output.stb <= io.masters[_io_output_T].stb @[WBArbiter.scala 30:13]
    io.output.cyc <= io.masters[_io_output_T].cyc @[WBArbiter.scala 30:13]
    node _T_3 = bits(currentMaster, 1, 0)
    node _T_4 = eq(io.masters[_T_3].cyc, UInt<1>("h00")) @[WBArbiter.scala 31:8]
    when _T_4 : @[WBArbiter.scala 31:40]
      currentMaster <= nextMaster @[WBArbiter.scala 32:19]
      skip @[WBArbiter.scala 31:40]
    
  module WBInterconnect : 
    input clock : Clock
    input reset : Reset
    output io : {flip devices : {flip cyc : UInt<1>, flip stb : UInt<1>, flip we : UInt<1>, flip addr : UInt<32>, flip mosi_data : UInt<32>, miso_data : UInt<32>, flip sel : UInt<4>, ack : UInt<1>, stall : UInt<1>, error : UInt<1>}[3], master : {flip cyc : UInt<1>, flip stb : UInt<1>, flip we : UInt<1>, flip addr : UInt<32>, flip mosi_data : UInt<32>, miso_data : UInt<32>, flip sel : UInt<4>, ack : UInt<1>, stall : UInt<1>, error : UInt<1>}}
    
    reg wback : UInt<1>, clock with : (reset => (reset, UInt<1>("h00"))) @[WBInterconnect.scala 33:22]
    reg wbdata : UInt<32>, clock @[WBInterconnect.scala 34:19]
    wbdata <= UInt<1>("h00") @[WBInterconnect.scala 35:10]
    io.master.miso_data <= wbdata @[WBInterconnect.scala 36:23]
    io.master.ack <= wback @[WBInterconnect.scala 37:17]
    reg wberr : UInt<1>, clock with : (reset => (reset, UInt<1>("h00"))) @[WBInterconnect.scala 38:22]
    wberr <= UInt<1>("h00") @[WBInterconnect.scala 39:9]
    io.master.error <= wberr @[WBInterconnect.scala 40:19]
    wire wbAcks : UInt<1>[3] @[WBInterconnect.scala 42:20]
    node wback_hi = cat(wbAcks[2], wbAcks[1]) @[WBInterconnect.scala 43:25]
    node _wback_T = cat(wback_hi, wbAcks[0]) @[WBInterconnect.scala 43:25]
    node _wback_T_1 = orr(_wback_T) @[WBInterconnect.scala 43:31]
    wback <= _wback_T_1 @[WBInterconnect.scala 43:9]
    wbAcks[0] <= io.devices[0].ack @[WBInterconnect.scala 45:15]
    when io.devices[0].ack : @[WBInterconnect.scala 46:29]
      wbdata <= io.devices[0].miso_data @[WBInterconnect.scala 47:14]
      skip @[WBInterconnect.scala 46:29]
    wbAcks[1] <= io.devices[1].ack @[WBInterconnect.scala 45:15]
    when io.devices[1].ack : @[WBInterconnect.scala 46:29]
      wbdata <= io.devices[1].miso_data @[WBInterconnect.scala 47:14]
      skip @[WBInterconnect.scala 46:29]
    wbAcks[2] <= io.devices[2].ack @[WBInterconnect.scala 45:15]
    when io.devices[2].ack : @[WBInterconnect.scala 46:29]
      wbdata <= io.devices[2].miso_data @[WBInterconnect.scala 47:14]
      skip @[WBInterconnect.scala 46:29]
    wire deviceSels : UInt<1>[3] @[WBInterconnect.scala 52:24]
    node _deviceSels_0_T = bits(io.master.addr, 29, 13) @[WBInterconnect.scala 55:36]
    node _deviceSels_0_T_1 = eq(_deviceSels_0_T, UInt<1>("h00")) @[WBInterconnect.scala 55:59]
    deviceSels[0] <= _deviceSels_0_T_1 @[WBInterconnect.scala 55:19]
    node _deviceSels_1_T = bits(io.master.addr, 29, 0) @[WBInterconnect.scala 55:36]
    node _deviceSels_1_T_1 = eq(_deviceSels_1_T, UInt<30>("h03c000000")) @[WBInterconnect.scala 55:59]
    deviceSels[1] <= _deviceSels_1_T_1 @[WBInterconnect.scala 55:19]
    node _deviceSels_2_T = bits(io.master.addr, 29, 1) @[WBInterconnect.scala 55:36]
    node _deviceSels_2_T_1 = eq(_deviceSels_2_T, UInt<29>("h01e000200")) @[WBInterconnect.scala 55:59]
    deviceSels[2] <= _deviceSels_2_T_1 @[WBInterconnect.scala 55:19]
    node hi = cat(deviceSels[2], deviceSels[1]) @[WBInterconnect.scala 57:43]
    node _T = cat(hi, deviceSels[0]) @[WBInterconnect.scala 57:43]
    node _T_1 = orr(_T) @[WBInterconnect.scala 57:49]
    node _T_2 = eq(_T_1, UInt<1>("h00")) @[WBInterconnect.scala 57:25]
    node _T_3 = and(io.master.stb, _T_2) @[WBInterconnect.scala 57:22]
    when _T_3 : @[WBInterconnect.scala 57:53]
      wberr <= UInt<1>("h01") @[WBInterconnect.scala 58:11]
      skip @[WBInterconnect.scala 57:53]
    wire stalls : UInt<1>[3] @[WBInterconnect.scala 61:20]
    node _stalls_0_T = and(deviceSels[0], io.devices[0].stall) @[WBInterconnect.scala 63:32]
    stalls[0] <= _stalls_0_T @[WBInterconnect.scala 63:15]
    node _stalls_1_T = and(deviceSels[1], io.devices[1].stall) @[WBInterconnect.scala 63:32]
    stalls[1] <= _stalls_1_T @[WBInterconnect.scala 63:15]
    node _stalls_2_T = and(deviceSels[2], io.devices[2].stall) @[WBInterconnect.scala 63:32]
    stalls[2] <= _stalls_2_T @[WBInterconnect.scala 63:15]
    node io_master_stall_hi = cat(stalls[2], stalls[1]) @[WBInterconnect.scala 65:35]
    node _io_master_stall_T = cat(io_master_stall_hi, stalls[0]) @[WBInterconnect.scala 65:35]
    node _io_master_stall_T_1 = orr(_io_master_stall_T) @[WBInterconnect.scala 65:41]
    io.master.stall <= _io_master_stall_T_1 @[WBInterconnect.scala 65:19]
    node _io_devices_0_stb_T = and(io.master.stb, deviceSels[0]) @[WBInterconnect.scala 69:40]
    io.devices[0].stb <= _io_devices_0_stb_T @[WBInterconnect.scala 69:23]
    io.devices[0].sel <= io.master.sel @[WBInterconnect.scala 70:23]
    node _io_devices_0_addr_T = bits(io.master.addr, 12, 0) @[WBInterconnect.scala 72:43]
    io.devices[0].addr <= _io_devices_0_addr_T @[WBInterconnect.scala 72:26]
    io.devices[0].we <= io.master.we @[WBInterconnect.scala 76:22]
    node _io_devices_0_cyc_T = and(io.master.cyc, deviceSels[0]) @[WBInterconnect.scala 77:40]
    io.devices[0].cyc <= _io_devices_0_cyc_T @[WBInterconnect.scala 77:23]
    io.devices[0].mosi_data <= io.master.mosi_data @[WBInterconnect.scala 78:29]
    node _io_devices_1_stb_T = and(io.master.stb, deviceSels[1]) @[WBInterconnect.scala 69:40]
    io.devices[1].stb <= _io_devices_1_stb_T @[WBInterconnect.scala 69:23]
    io.devices[1].sel <= io.master.sel @[WBInterconnect.scala 70:23]
    io.devices[1].addr <= UInt<1>("h00") @[WBInterconnect.scala 74:26]
    io.devices[1].we <= io.master.we @[WBInterconnect.scala 76:22]
    node _io_devices_1_cyc_T = and(io.master.cyc, deviceSels[1]) @[WBInterconnect.scala 77:40]
    io.devices[1].cyc <= _io_devices_1_cyc_T @[WBInterconnect.scala 77:23]
    io.devices[1].mosi_data <= io.master.mosi_data @[WBInterconnect.scala 78:29]
    node _io_devices_2_stb_T = and(io.master.stb, deviceSels[2]) @[WBInterconnect.scala 69:40]
    io.devices[2].stb <= _io_devices_2_stb_T @[WBInterconnect.scala 69:23]
    io.devices[2].sel <= io.master.sel @[WBInterconnect.scala 70:23]
    node _io_devices_2_addr_T = bits(io.master.addr, 0, 0) @[WBInterconnect.scala 72:43]
    io.devices[2].addr <= _io_devices_2_addr_T @[WBInterconnect.scala 72:26]
    io.devices[2].we <= io.master.we @[WBInterconnect.scala 76:22]
    node _io_devices_2_cyc_T = and(io.master.cyc, deviceSels[2]) @[WBInterconnect.scala 77:40]
    io.devices[2].cyc <= _io_devices_2_cyc_T @[WBInterconnect.scala 77:23]
    io.devices[2].mosi_data <= io.master.mosi_data @[WBInterconnect.scala 78:29]
    
  module YJTop : 
    input clock : Clock
    input reset : UInt<1>
    output io : {sdram : {addr : UInt<12>, bank : UInt<2>, dataOut : UInt<16>, dqm : UInt<2>, clk : UInt<1>, cke : UInt<1>, cs_n : UInt<1>, ras_n : UInt<1>, cas_n : UInt<1>, we_n : UInt<1>, output_en : UInt<1>}, flip dqIn : UInt<16>, leds : UInt<16>, flip rx : UInt<1>, tx : UInt<1>, flip procReset : UInt<1>}
    
    io.procReset is invalid @[YJTop.scala 22:6]
    io.tx is invalid @[YJTop.scala 22:6]
    io.rx is invalid @[YJTop.scala 22:6]
    io.leds is invalid @[YJTop.scala 22:6]
    io.dqIn is invalid @[YJTop.scala 22:6]
    io.sdram.output_en is invalid @[YJTop.scala 22:6]
    io.sdram.we_n is invalid @[YJTop.scala 22:6]
    io.sdram.cas_n is invalid @[YJTop.scala 22:6]
    io.sdram.ras_n is invalid @[YJTop.scala 22:6]
    io.sdram.cs_n is invalid @[YJTop.scala 22:6]
    io.sdram.cke is invalid @[YJTop.scala 22:6]
    io.sdram.clk is invalid @[YJTop.scala 22:6]
    io.sdram.dqm is invalid @[YJTop.scala 22:6]
    io.sdram.dataOut is invalid @[YJTop.scala 22:6]
    io.sdram.bank is invalid @[YJTop.scala 22:6]
    io.sdram.addr is invalid @[YJTop.scala 22:6]
    inst proc of YJTopWrapper @[YJTop.scala 25:20]
    proc.clock <= clock
    proc.reset <= reset
    proc.io.procReset <= io.procReset @[YJTop.scala 26:21]
    inst leds of WBLeds @[YJTop.scala 28:20]
    leds.clock <= clock
    leds.reset <= reset
    io.leds <= leds.io.leds @[YJTop.scala 29:16]
    inst ihexUart of WBUartIhexWrapper @[YJTop.scala 31:24]
    ihexUart.clock <= clock
    ihexUart.reset <= reset
    ihexUart.io.rx <= io.rx @[YJTop.scala 32:18]
    io.tx <= ihexUart.io.tx @[YJTop.scala 33:9]
    ihexUart.io.slaveWb.cyc <= UInt<1>("h00") @[YJTop.scala 34:27]
    io.sdram.output_en <= UInt<1>("h00") @[YJTop.scala 39:22]
    inst blockram of BlockRam @[YJTop.scala 41:24]
    blockram.clock <= clock
    blockram.reset <= reset
    inst arbiter of WBArbiter @[YJTop.scala 43:23]
    arbiter.clock <= clock
    arbiter.reset <= reset
    ihexUart.io.masterWb.error <= arbiter.io.masters[0].error @[YJTop.scala 44:25]
    ihexUart.io.masterWb.stall <= arbiter.io.masters[0].stall @[YJTop.scala 44:25]
    ihexUart.io.masterWb.ack <= arbiter.io.masters[0].ack @[YJTop.scala 44:25]
    arbiter.io.masters[0].sel <= ihexUart.io.masterWb.sel @[YJTop.scala 44:25]
    ihexUart.io.masterWb.miso_data <= arbiter.io.masters[0].miso_data @[YJTop.scala 44:25]
    arbiter.io.masters[0].mosi_data <= ihexUart.io.masterWb.mosi_data @[YJTop.scala 44:25]
    arbiter.io.masters[0].addr <= ihexUart.io.masterWb.addr @[YJTop.scala 44:25]
    arbiter.io.masters[0].we <= ihexUart.io.masterWb.we @[YJTop.scala 44:25]
    arbiter.io.masters[0].stb <= ihexUart.io.masterWb.stb @[YJTop.scala 44:25]
    arbiter.io.masters[0].cyc <= ihexUart.io.masterWb.cyc @[YJTop.scala 44:25]
    proc.io.memWb.error <= arbiter.io.masters[1].error @[YJTop.scala 45:25]
    proc.io.memWb.stall <= arbiter.io.masters[1].stall @[YJTop.scala 45:25]
    proc.io.memWb.ack <= arbiter.io.masters[1].ack @[YJTop.scala 45:25]
    arbiter.io.masters[1].sel <= proc.io.memWb.sel @[YJTop.scala 45:25]
    proc.io.memWb.miso_data <= arbiter.io.masters[1].miso_data @[YJTop.scala 45:25]
    arbiter.io.masters[1].mosi_data <= proc.io.memWb.mosi_data @[YJTop.scala 45:25]
    arbiter.io.masters[1].addr <= proc.io.memWb.addr @[YJTop.scala 45:25]
    arbiter.io.masters[1].we <= proc.io.memWb.we @[YJTop.scala 45:25]
    arbiter.io.masters[1].stb <= proc.io.memWb.stb @[YJTop.scala 45:25]
    arbiter.io.masters[1].cyc <= proc.io.memWb.cyc @[YJTop.scala 45:25]
    proc.io.fetchWb.error <= arbiter.io.masters[2].error @[YJTop.scala 46:25]
    proc.io.fetchWb.stall <= arbiter.io.masters[2].stall @[YJTop.scala 46:25]
    proc.io.fetchWb.ack <= arbiter.io.masters[2].ack @[YJTop.scala 46:25]
    arbiter.io.masters[2].sel <= proc.io.fetchWb.sel @[YJTop.scala 46:25]
    proc.io.fetchWb.miso_data <= arbiter.io.masters[2].miso_data @[YJTop.scala 46:25]
    arbiter.io.masters[2].mosi_data <= proc.io.fetchWb.mosi_data @[YJTop.scala 46:25]
    arbiter.io.masters[2].addr <= proc.io.fetchWb.addr @[YJTop.scala 46:25]
    arbiter.io.masters[2].we <= proc.io.fetchWb.we @[YJTop.scala 46:25]
    arbiter.io.masters[2].stb <= proc.io.fetchWb.stb @[YJTop.scala 46:25]
    arbiter.io.masters[2].cyc <= proc.io.fetchWb.cyc @[YJTop.scala 46:25]
    inst interconnect of WBInterconnect @[YJTop.scala 48:28]
    interconnect.clock <= clock
    interconnect.reset <= reset
    interconnect.io.devices[0].error <= blockram.io.wb.error @[YJTop.scala 54:30]
    interconnect.io.devices[0].stall <= blockram.io.wb.stall @[YJTop.scala 54:30]
    interconnect.io.devices[0].ack <= blockram.io.wb.ack @[YJTop.scala 54:30]
    blockram.io.wb.sel <= interconnect.io.devices[0].sel @[YJTop.scala 54:30]
    interconnect.io.devices[0].miso_data <= blockram.io.wb.miso_data @[YJTop.scala 54:30]
    blockram.io.wb.mosi_data <= interconnect.io.devices[0].mosi_data @[YJTop.scala 54:30]
    blockram.io.wb.addr <= interconnect.io.devices[0].addr @[YJTop.scala 54:30]
    blockram.io.wb.we <= interconnect.io.devices[0].we @[YJTop.scala 54:30]
    blockram.io.wb.stb <= interconnect.io.devices[0].stb @[YJTop.scala 54:30]
    blockram.io.wb.cyc <= interconnect.io.devices[0].cyc @[YJTop.scala 54:30]
    interconnect.io.devices[1].error <= leds.io.wb.error @[YJTop.scala 55:30]
    interconnect.io.devices[1].stall <= leds.io.wb.stall @[YJTop.scala 55:30]
    interconnect.io.devices[1].ack <= leds.io.wb.ack @[YJTop.scala 55:30]
    leds.io.wb.sel <= interconnect.io.devices[1].sel @[YJTop.scala 55:30]
    interconnect.io.devices[1].miso_data <= leds.io.wb.miso_data @[YJTop.scala 55:30]
    leds.io.wb.mosi_data <= interconnect.io.devices[1].mosi_data @[YJTop.scala 55:30]
    leds.io.wb.addr <= interconnect.io.devices[1].addr @[YJTop.scala 55:30]
    leds.io.wb.we <= interconnect.io.devices[1].we @[YJTop.scala 55:30]
    leds.io.wb.stb <= interconnect.io.devices[1].stb @[YJTop.scala 55:30]
    leds.io.wb.cyc <= interconnect.io.devices[1].cyc @[YJTop.scala 55:30]
    interconnect.io.devices[2].error <= ihexUart.io.slaveWb.error @[YJTop.scala 56:30]
    interconnect.io.devices[2].stall <= ihexUart.io.slaveWb.stall @[YJTop.scala 56:30]
    interconnect.io.devices[2].ack <= ihexUart.io.slaveWb.ack @[YJTop.scala 56:30]
    ihexUart.io.slaveWb.sel <= interconnect.io.devices[2].sel @[YJTop.scala 56:30]
    interconnect.io.devices[2].miso_data <= ihexUart.io.slaveWb.miso_data @[YJTop.scala 56:30]
    ihexUart.io.slaveWb.mosi_data <= interconnect.io.devices[2].mosi_data @[YJTop.scala 56:30]
    ihexUart.io.slaveWb.addr <= interconnect.io.devices[2].addr @[YJTop.scala 56:30]
    ihexUart.io.slaveWb.we <= interconnect.io.devices[2].we @[YJTop.scala 56:30]
    ihexUart.io.slaveWb.stb <= interconnect.io.devices[2].stb @[YJTop.scala 56:30]
    ihexUart.io.slaveWb.cyc <= interconnect.io.devices[2].cyc @[YJTop.scala 56:30]
    arbiter.io.output.error <= interconnect.io.master.error @[YJTop.scala 58:26]
    arbiter.io.output.stall <= interconnect.io.master.stall @[YJTop.scala 58:26]
    arbiter.io.output.ack <= interconnect.io.master.ack @[YJTop.scala 58:26]
    interconnect.io.master.sel <= arbiter.io.output.sel @[YJTop.scala 58:26]
    arbiter.io.output.miso_data <= interconnect.io.master.miso_data @[YJTop.scala 58:26]
    interconnect.io.master.mosi_data <= arbiter.io.output.mosi_data @[YJTop.scala 58:26]
    interconnect.io.master.addr <= arbiter.io.output.addr @[YJTop.scala 58:26]
    interconnect.io.master.we <= arbiter.io.output.we @[YJTop.scala 58:26]
    interconnect.io.master.stb <= arbiter.io.output.stb @[YJTop.scala 58:26]
    interconnect.io.master.cyc <= arbiter.io.output.cyc @[YJTop.scala 58:26]
    
