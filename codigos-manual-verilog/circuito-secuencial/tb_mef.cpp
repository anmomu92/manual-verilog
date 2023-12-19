#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vmef.h"

#define ESTADOS 5
vluint64_t estado = 0;

void reset(Vmef *dut);
void tic(Vmef *dut);
void prueba_estado(Vmef *dut, int a, int b, int init);

int main(int argc, char** argv, char** env) {
    // instanciamos la UBP
    Vmef *dut = new Vmef;

    // activamos la generación de traza
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    // reseteamos la UBP
    reset(dut);

    // generamos la lógica de la simulación
    while (estado < ESTADOS) {
        // generamos un tic
        tic(dut);

        // INIT
        prueba_estado(dut, 0, 0, 1);
        // A0
        prueba_estado(dut, 0, 0, 0);
        // A1
        prueba_estado(dut, 0, 0, 0);
        // OK0
        prueba_estado(dut, 0, 0, 0);
        // OK1
        prueba_estado(dut, 0, 0, 0);

        // interpretación binaria de las variables
        std::bitset<1> x(dut->A);
        std::bitset<1> y(dut->B);
        std::bitset<1> z(dut->Z);
        std::bitset<3> estado(dut->estado_depurado);

        std::cout << "Estado = " << estado << '\n';
        std::cout << "A = " << x << '\n';
        std::cout << "B = " << y << '\n';
        std::cout << "Z = " << z << "\n\n";

        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}

void reset(Vmef *dut){
    dut->rst = 1;
    dut->eval();
    dut->rst = 0;
    dut->eval();
}

void tic(Vmef *dut){
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

void prueba_estado(Vmef *dut, int a, int b, int init){
    int i,j;
    
    // for anidado para probar diferentes combinaciones de entrada
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            // nos movemos al estado que queremos probar (si no es INIT)
            if(!init){
                dut->A = a;
                dut->B = b;
            }
            // asignamos todas las combinaciones de entradas para dicho estado
            dut->A = i;
            dut->B = j;
            // para probar el estado INIT, hay que reiniciar
            if(init) reset(dut);
        }
    }
}
