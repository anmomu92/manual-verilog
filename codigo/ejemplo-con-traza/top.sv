/*
*	Módulo para el ejemplo con trazas
*	Descripción: multiplexor 4 a 1
*	Dependencias
*/

module top(
	input wire clk,
	input wire rst,
	input wire [3:0] a,
	input wire [1:0] sel,
	output reg		 b 
);

	// señales intermedias
	reg aux;

	// lógica de salida
	always @(posedge clk) begin
		if(rst)
			b <= 0;
		else
			b <= aux; 
	end

	// lógica del módulo
	always @(*) begin
		case(sel)
			2'b00: aux = a[0];
			2'b01: aux = a[1];
			2'b10: aux = a[2];
			2'b11: aux = a[3];
			default: aux = 0;
		endcase
	end

endmodule
