/*
 * INCLUDES
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

int comprueba_resultado(int b, Vtop top);

/*
 * MAIN
 */
int main(int argc, char** argv){

	// variables
	int a = 8;
	int sel = 4;

	// iniciamos el contexto
	const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
	contextp->commandArgs(argc, argv);

	// habilitamos el trazado
	contextp->traceEverOn(true);

	// instanciamos el modelo verilado
	const std::unique_ptr<Vtop> top {new Vtop{contextp.get(), "TOP"}};

	// instanciamos el objeto para crear las trazas
	VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("simx.vcd");

	// inicializamos las señales de reloj y de reseteo
	top->clk = 0;
	top->rst = 1;

	// simulamos 20 pasos
	while(contextp->time() < 50){
		contextp->timeInc(1);
		top->clk = !top->clk;

		if(!top->clk){
			if(contextp->time() > 1 && contextp->time() < 10){
				top->rst = 1;
			}else{
				top->rst = 0;
			}
			
			// estimulamos el modelo
			top->a = a;
			top->sel = sel;

			sel++;

			// cambiamos el valor de la entrada a
			if(sel == 8){
				sel = 4;
				a++;
			}
		}

		// evaluamos el modelo
		top->eval();
		tfp->dump(contextp->time());

		// mostramos las salidas
		VL_PRINTF("[%" PRId64 "} clk=%x rst=%x a=%b and sel=%b -> b=%b\n", contextp->time(), top->clk, top->rst, top->a, top->sel, top->b);
	}

	tfp->close();
	top->final();

	return 0;
}

int comprueba_resultado(int b, Vtop top){
	
	return 0;
}
