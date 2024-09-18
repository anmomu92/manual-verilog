/*
 * INCLUDES
 */
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <verilated.h>
#include "Vtop.h"

/* 
 * MAIN
 */
int main(int argc, char** argv){

	// iniciamos el contexto
	const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};

	// instanciamos el modelo verilado
	const std::unique_ptr<Vtop> top{new Vtop{contextp.get(), "TOP"}};

	// inicializamos las señales de reloj y reseteo
	top->clk = 0;
	top->rst = 1;

	// simulamos 20 pasos
	while(contextp->time() < 20){

		// incrementamos el tiempo de simulación en una unidad
		contextp->timeInc(1);

		// alternamos la señal de reloj
		top->clk = !top->clk;

		// en los primeros 10 pasos de simulación activamos el reset
		// después, alternamos la señal a
		if(!top->clk){
			if(contextp->time() > 1 && contextp->time() < 10){
				top->rst = 1;
			} else{
				top->rst = 0;
			}
			top->a = !top->a;
		}

		// evaluamos el modelo
		top->eval();

		// mostramos las salidas
		VL_PRINTF("[%" PRId64 "] clk=%x rst=%x a=%x -> b=%x\n", contextp->time(), top->clk, top->rst, top->a, top->b);
	}

	top->final();

	return 0;
}
