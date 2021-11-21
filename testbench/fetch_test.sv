module fetch_test;
    reg clk = 0, reset = 0;
    wire [31:0] instruction, pc;    
    

    fetch a (.clk(clk), .reset, .instruction_out(instruction), .pc_out(pc));

    initial begin
        a.i_mem[0] = 32'hFFFF0000;
    end

    always begin
        #1 clk = !clk;
    end

    initial begin
        $dumpfile("fetch-test.vcd");
        $dumpvars;
        #10
        reset = 1;
        #2
        reset = 0;
        #50
        $finish;
    end
    
endmodule