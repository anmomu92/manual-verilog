module tb_mux4 ();
    localparam WIDTH = 8;

    reg en;
    reg [1:0] sel;
    reg [WIDTH-1:0] e0;
    reg [WIDTH-1:0] e1;
    reg [WIDTH-1:0] e2;
    reg [WIDTH-1:0] e3;
    wire [WIDTH-1:0] s;
    integer j, errores;
    reg [WIDTH-1:0] resultado_esperado;

    mux4 #(.WIDTH(WIDTH)) UBP (.en(en), .e0(e0), .e1(e1), .e2(e2), .e3(e3), .sel(sel), .s(s));

    initial begin
        errores = 0;
        // inicializamos las señales de datos
        e0 = {{WIDTH-1{1'b0}}, {1{1'b1}}};
        e1 = {{WIDTH-2{1'b0}}, {2{1'b1}}};
        e2 = {{WIDTH-3{1'b0}}, {3{1'b1}}};
        e3 = {{WIDTH-4{1'b0}}, {4{1'b1}}};

        $display("Las fuentes son: ");
        $display("e0: %b", e0);
        $display("e1: %b", e1);
        $display("e2: %b", e2);
        $display("e3: %b", e3);

        // inicializamos las señales de control
        for(j = 0; j<8; j=j+1) begin
            {en,sel} = j;
            #10

            if(en) begin
                case(sel)
                    2'b00: resultado_esperado = e0;
                    2'b01: resultado_esperado = e1;
                    2'b10: resultado_esperado = e2;
                    2'b11: resultado_esperado = e3;
                endcase
            end else begin
                resultado_esperado = 0;
            end
            if(s === resultado_esperado) begin
                $display("ACIERTO. en = %b, sel = %b - s = %b - resultado esperado = %b", en, sel, s, resultado_esperado);
            end
            if(s !== resultado_esperado) begin
                $display("ERROR.");
                errores = errores + 1;
            end
        end
        $display("Simulacion terminada. Errores: %d", errores);
    end

endmodule
