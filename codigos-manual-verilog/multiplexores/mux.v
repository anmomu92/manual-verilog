module mux4 #(
                parameter WIDTH = 8
            )
            (
                input wire en,
                input wire [1:0] sel,
                input wire [WIDTH-1:0] e0,
                input wire [WIDTH-1:0] e1,
                input wire [WIDTH-1:0] e2,
                input wire [WIDTH-1:0] e3,

                output reg [WIDTH-1:0] s
            );

    always @(*) begin
        s = 0;
        if(en) begin
            case(sel)
                2'b00: s = e0;
                2'b01: s = e1;
                2'b10: s = e2;
                2'b11: s = e3;
                default: s = 0;
            endcase
        end
    end
endmodule
