module top (
    input clk,
    input reset,
    input i_wb_slave_ack,
    input i_wb_slave_stall,
    input [31:0] i_wb_slave_miso_data,
    output o_wb_slave_cycle,
    output o_wb_slave_stb,
    output o_wb_slave_we,
    output wire [3:0] o_wb_slave_sel,
    output wire [29:0] o_wb_slave_addr,
    output wire [31:0] o_wb_slave_mosi_data
);

    wire [31:0] if_id_pc, if_id_instruction;

    wire [31:0] id_rr_pc, id_rr_immediate;
    wire [4:0] id_rr_sr1_number, id_rr_sr2_number, id_rr_rd_number;
    wire [6:0] id_rr_func7, id_rr_opcode;
    wire [2:0] id_rr_func3;

    wire [4:0] dest_addr;
    wire [31:0] data, reg_file_rr_a_val, reg_file_rr_b_val;
    wire id_pipeline_stall, rr_pipeline_stall, 
            ex_pipeline_stall, mem_pipeline_stall;

    wire load_new_pc;
    wire [31:0] new_pc;


    wire wb_fetch_cycle, wb_fetch_stb, wb_fetch_we, wb_fetch_ack, wb_fetch_stall;
    wire [3:0] wb_fetch_sel;
    wire [29:0] wb_fetch_addr;
    wire [31:0] wb_fetch_mosi_data, wb_fetch_miso_data;

    fetch fetch (.clk, .reset, 
                .i_pipeline_stall(id_pipeline_stall), 
                .i_load_new_pc(load_new_pc), 
                .i_new_pc(new_pc), 
                .o_instruction(if_id_instruction), 
                .o_pc(if_id_pc),
                .i_wb_ack(wb_fetch_ack), 
                .i_wb_data(wb_fetch_miso_data), 
                .i_wb_stall(wb_fetch_stall),
                .o_wb_cycle(wb_fetch_cyc), 
                .o_wb_stb(wb_fetch_stb), 
                .o_wb_we(wb_fetch_we), 
                .o_wb_sel(wb_fetch_sel), 
                .o_wb_addr(wb_fetch_addr), 
                .o_wb_data(wb_fetch_mosi_data)
        );

    dual_port_reg_file reg_file (.clk, 
                                .i_dest_addr(dest_addr),
                                .i_data(data), 
                                .i_a_addr(id_rr_sr1_number), 
                                .i_b_addr(id_rr_sr2_number), 
                                .o_a(reg_file_rr_a_val), 
                                .o_b(reg_file_rr_b_val));

    id id (.clk, .reset, 
            .i_pc(if_id_pc), 
            .i_instruction(if_id_instruction), 
            .i_pipeline_stall(rr_pipeline_stall), 
            .i_load_new_pc(load_new_pc), 
            .o_pc(id_rr_pc), 
            .o_rs1_number(id_rr_sr1_number), 
            .o_rs2_number(id_rr_sr2_number), 
            .o_rd_number(id_rr_rd_number), 
            .o_immediate(id_rr_immediate), 
            .o_func7(id_rr_func7), 
            .o_func3(id_rr_func3), 
            .o_opcode(id_rr_opcode), 
            .o_pipeline_stall(id_pipeline_stall));

    wire [31:0] rr_ex_pc, rr_ex_rs1_val, rr_ex_rs2_val, rr_ex_immediate;
    wire [4:0] rr_ex_rd_number;
    wire [6:0] rr_ex_func7, rr_ex_opcode;
    wire [2:0] rr_ex_func3;

    wire [31:0] ex_mem_result, ex_mem_pc, ex_mem_rs1_val, 
                ex_mem_rs2_val, ex_mem_immediate;
    wire [4:0] ex_mem_rd_number;
    wire [6:0] ex_mem_opcode;
    wire [2:0] ex_mem_func3;
    wire [4:0] mem_rd;

    wire [4:0] df_mem_rd_number, df_ex_rd_number;
    wire [31:0] df_mem_result, df_ex_result;
    wire df_mem_valid, df_ex_valid;

    rr rr (.clk, .reset, 
            .i_pc(id_rr_pc), 
            .i_rs1_number(id_rr_sr1_number), 
            .i_rs2_number(id_rr_sr2_number), 
            .i_rd_number(id_rr_rd_number), 
            .i_immediate(id_rr_immediate), 
            .i_func7(id_rr_func7), 
            .i_func3(id_rr_func3), 
            .i_a_val(reg_file_rr_a_val), 
            .i_b_val(reg_file_rr_b_val), 
            .i_opcode(id_rr_opcode), 
            .i_pipeline_stall(ex_pipeline_stall), 
            .i_ex_buf_rd_number(ex_mem_rd_number), 
            .i_mem_buf_rd_number(mem_rd), 
            .i_ex_rd_number(df_ex_rd_number), 
            .i_ex_result(df_ex_result), 
            .i_ex_valid(df_ex_valid), 
            .i_mem_rd_number(df_mem_rd_number), 
            .i_mem_result(df_mem_result), 
            .i_mem_valid(df_mem_valid), 
            .i_load_new_pc(load_new_pc), 
            .o_pc(rr_ex_pc), 
            .o_rs1_val(rr_ex_rs1_val), 
            .o_rs2_val(rr_ex_rs2_val), 
            .o_rd_number(rr_ex_rd_number), 
            .o_immediate(rr_ex_immediate), 
            .o_func7(rr_ex_func7), 
            .o_func3(rr_ex_func3), 
            .o_opcode(rr_ex_opcode), 
            .o_pipeline_stall(rr_pipeline_stall));

    ex ex (.clk, .reset, 
            .i_pc(rr_ex_pc), 
            .i_rs1_val(rr_ex_rs1_val), 
            .i_rs2_val(rr_ex_rs2_val), 
            .i_rd_number(rr_ex_rd_number), 
            .i_immediate(rr_ex_immediate), 
            .i_func7(rr_ex_func7), 
            .i_func3(rr_ex_func3), 
            .i_opcode(rr_ex_opcode), 
            .i_pipeline_stall(mem_pipeline_stall), 
            .o_ex_rd_number(df_ex_rd_number), 
            .o_ex_result(df_ex_result), 
            .o_ex_valid(df_ex_valid), 
            .o_rd_number(ex_mem_rd_number), 
            .o_result(ex_mem_result), 
            .o_load_new_pc(load_new_pc), 
            .o_new_pc(new_pc), 
            .o_pc(ex_mem_pc), 
            .o_rs1_val(ex_mem_rs1_val), 
            .o_rs2_val(ex_mem_rs2_val), 
            .o_immediate(ex_mem_immediate), 
            .o_opcode(ex_mem_opcode), 
            .o_func3(ex_mem_func3), 
            .o_pipeline_stall(ex_pipeline_stall));

    wire wb_mem_cycle, wb_mem_stb, wb_mem_we, wb_mem_ack, wb_mem_stall;
    wire [3:0] wb_mem_sel;
    wire [29:0] wb_mem_addr;
    wire [31:0] wb_mem_mosi_data, wb_mem_miso_data;

    mem mem (.clk, .reset, 
            .i_rd_number(ex_mem_rd_number), 
            .i_result(ex_mem_result), 
            .i_pc(ex_mem_pc), 
            .i_rs1_val(ex_mem_rs1_val), 
            .i_rs2_val(ex_mem_rs2_val), 
            .i_immediate(ex_mem_immediate), 
            .i_opcode(ex_mem_opcode), 
            .i_func3(ex_mem_func3), 
            .i_wb_ack(wb_mem_ack), 
            .i_wb_data(wb_mem_miso_data), 
            .i_wb_stall(wb_mem_stall), 
            .o_mem_rd_number(df_mem_rd_number), 
            .o_mem_result(df_mem_result), 
            .o_mem_valid(df_mem_valid), 
            .o_wb_cycle(wb_mem_cyc), 
            .o_wb_stb(wb_mem_stb), 
            .o_wb_we(wb_mem_we), 
            .o_wb_sel(wb_mem_sel), 
            .o_wb_addr(wb_mem_addr), 
            .o_wb_data(wb_mem_mosi_data), 
            .o_rd_number(dest_addr), 
            .o_result(data), 
            .o_pipeline_stall(mem_pipeline_stall));

    arbiter arbiter (.clk, .reset,
                    .i_wb_a_cycle(wb_fetch_cycle),
                    .i_wb_a_stb(wb_fetch_stb),
                    .i_wb_a_we(wb_fetch_we),
                    .i_wb_a_sel(wb_fetch_sel),
                    .i_wb_a_addr(wb_fetch_addr),
                    .i_wb_a_mosi_data(wb_fetch_mosi_data),
                    .o_wb_a_ack(wb_fetch_ack),
                    .o_wb_a_stall(wb_fetch_stall),
                    .o_wb_a_miso_data(wb_fetch_miso_data),
                    .i_wb_b_cycle(wb_mem_cycle),
                    .i_wb_b_stb(wb_mem_stb),
                    .i_wb_b_we(wb_mem_we),
                    .i_wb_b_sel(wb_mem_sel),
                    .i_wb_b_addr(wb_mem_addr),
                    .i_wb_b_mosi_data(wb_mem_mosi_data),
                    .o_wb_b_ack(wb_mem_ack),
                    .o_wb_b_stall(wb_mem_stall),
                    .o_wb_b_miso_data(wb_mem_miso_data),
                    .i_wb_slave_ack(i_wb_slave_ack),
                    .i_wb_slave_stall(i_wb_slave_stall),
                    .i_wb_slave_miso_data(i_wb_slave_miso_data),
                    .o_wb_slave_cycle(o_wb_slave_cycle),
                    .o_wb_slave_stb(o_wb_slave_stb),
                    .o_wb_slave_we(o_wb_slave_we),
                    .o_wb_slave_sel(o_wb_slave_sel),
                    .o_wb_slave_addr(o_wb_slave_addr),
                    .o_wb_slave_mosi_data(o_wb_slave_mosi_data));

// `ifdef VERILATOR
//     memdev #(20) my_mem2(
//         .i_clk(clk),
//         .i_wb_cyc(wb2_cyc),
//         .i_wb_stb(wb2_stb),
//         .i_wb_we(wb2_we),
//         .i_wb_addr(wb2_addr[17:0]),
//         .i_wb_data(wb2_mosi_data),
//         .i_wb_sel(wb2_sel),
//         .o_wb_ack(wb2_ack),
//         .o_wb_stall(wb2_stall),
//         .o_wb_data(wb2_miso_data)
//     );

//     memdev #(20) my_mem(
//         .i_clk(clk),
//         .i_wb_cyc(wb_cyc),
//         .i_wb_stb(wb_stb),
//         .i_wb_we(wb_we),
//         .i_wb_addr(wb_addr[17:0]),
//         .i_wb_data(wb_mosi_data),
//         .i_wb_sel(wb_sel),
//         .o_wb_ack(wb_ack),
//         .o_wb_stall(wb_stall),
//         .o_wb_data(wb_miso_data)
//     );
// `endif
endmodule