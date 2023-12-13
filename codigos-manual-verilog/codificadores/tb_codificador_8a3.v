/*
* Banco de pruebas para un codificador 8 a 3
*/

module tb_codificador_8a3();
    reg en;
    reg [7:0] e;
    wire [2:0] s;
    integer i, errores;
    reg [2:0] resultado_esperado;

    // instanciamos la unidad bajo prueba
    codificador_8a3 UBP (
                                 .en(en),
                                 .e(e),
                                 .s(s)
                                );

    // asignamos valores a las variables declaradas
    initial begin
        errores = 0;
        for (i = 0; i<512; i=i+1) begin
            {en,e} = i;
            resultado_esperado = 0;
            #10
            if(en) begin
                resultado_esperado [0] = e[1] + e[3] + e[5] + e[7]; 
                resultado_esperado [1] = e[2] + e[3] + e[6] + e[7]; 
                resultado_esperado [2] = e[4] + e[5] + e[6] + e[7]; 
            end
            
            // comparamos el resultado obtenido con el esperado
            if(s !== resultado_esperado) begin
                errores = errores + 1;
            end
        end

        // informamos del numero de errores durante la simulacion
        $display("Simulacion completada con %d errores", errores);
    end
endmodule
