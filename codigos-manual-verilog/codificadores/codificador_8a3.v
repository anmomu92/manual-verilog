module codificador_8a3 (
                                 input wire en,
                                 input wire [7:0] e,
                                 output reg [2:0] s
                               );

    always @(*) begin
        s = 3'b000;
        if(en) begin
            s[0] = e[1] + e[3] + e[5] + e[7];
            s[1] = e[2] + e[3] + e[6] + e[7];
            s[2] = e[4] + e[5] + e[6] + e[7];
        end
    end
endmodule
