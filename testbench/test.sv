module test;
    reg [31:0] data;
    reg [2:0] immediate = 110;

    initial begin
        $display("imm %b",  {{2{immediate[2]}}, immediate[2:0]});
    end
    
endmodule