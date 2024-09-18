/*
*	Módulo basico de ejemplo
*	Descripcion: conexion de la entrada negada a la salida
*	Dependencias:
*/
module top (
				input	wire	clk,
				input	wire	rst,
				input	wire	a,
				output	wire	b
				);
	reg aux;

	always @(posedge clk) begin
		if(rst)
			aux <= 0;
		else
			aux <= ~a;
	end

	assign b = aux;

endmodule
