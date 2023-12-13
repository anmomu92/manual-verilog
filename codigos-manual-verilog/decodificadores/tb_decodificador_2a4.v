`timescale 1 ns / 1 ps
module tb_decodificador_2a4();

    // declaracion de tipos de datos
    reg a0_p, a1_p, en_p;
    wire y0_p, y1_p, y2_p, y3_p;
    integer i, errores;
    reg [3:0] resultado_esperado;

    decodificador_2a4 UBP (.a0(a0_p),
                     .a1(a1_p),
                     .en(en_p),
                     .y0(y0_p),
                     .y1(y1_p),
                     .y2(y2_p),
                     .y3(y3_p)
                    );
    initial begin
        errores = 0;
        for(i = 0; i < 8; i=i+1) begin
            {en_p, a0_p, a1_p} = i;
            #10;
            resultado_esperado = 4'b0000;
            if(en_p) resultado_esperado[{a1_p,a0_p}] = 1'b1;
            if ({y3_p,y2_p,y1_p,y0_p} !== resultado_esperado) begin
                errores = errores + 1;
            end
        end
        $display("Test completado con \%d errores", errores);
    end
    
endmodule
