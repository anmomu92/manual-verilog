module mef (
            // reloj y reset
            input clk,
            input rst,

            // entradas
            input A,
            input B,

            // salidas (como vamos a usar codigo procedural, hay que declarar la salida como reg)
            output reg Z,

            // depuración
            output [2:0] estado_depurado
           );

// DPI
export "DPI-C" function sv_get_estado;

/*verilator lint_off WIDTH*/
function byte sv_get_estado(); 
    return estado;
endfunction
/*verilator lint_on WIDTH*/

// senales internas
reg [2:0] estado;
reg [2:0] estado_siguiente;

// asignacion de variables de estado a parametros
parameter [2:0] INIT = 3'b000,
                A0 = 3'b001,
                A1 = 3'b010,
                OK0 = 3'b011,
                OK1 = 3'b100;

// comportamiento del estado siguiente
always @(*) begin
    case(estado)
        INIT: begin
                if (A == 0) estado_siguiente = A0;
                else estado_siguiente = A1;
              end
        A0: begin 
                if (A == 0) estado_siguiente = OK0;
                else estado_siguiente = A1;
            end
        A1: begin
                if (A == 0) estado_siguiente = A0;
                else estado_siguiente = OK1;
            end
        OK0: begin
                if (A == 0) estado_siguiente = OK0;
                else if ((A == 1) && (B == 1)) estado_siguiente = OK1;
                else estado_siguiente = A1;
            end
        OK1: begin
                if ((A == 0) && (B == 0)) estado_siguiente = A0;
                else if ((A == 0) && (B == 1)) estado_siguiente = OK0;
                else estado_siguiente = OK1;
            end
        default: estado_siguiente = INIT;
    endcase
end

// logica de salida
always @(estado) begin
    case(estado)
        INIT: Z = 0;
        A0: Z = 0;
        A1: Z = 0;
        OK0: Z = 1;
        OK1: Z = 1;
        default: Z = 0;
    endcase
end

// memoria de estado
always @(posedge clk) begin
    if(rst)
        estado <= INIT;
    else
        estado <= estado_siguiente;
end

// depuración
assign estado_depurado = estado;

endmodule
