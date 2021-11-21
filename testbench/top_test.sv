module top_test;
    reg clk = 0, reset = 1;
    wire [31:0] instruction, pc;    
    

    top a (.clk, .reset);

    initial begin
        a.fetch.i_mem[0] = 32'h3e800093;
        a.fetch.i_mem[1] = 32'h00108133;
    end

    always begin
        #1 clk = !clk;
    end

    initial begin
        $dumpfile("fetch-test.vcd");
        $dumpvars;
        #4
        reset = 0;
        #50
        $finish;
    end
    
endmodule