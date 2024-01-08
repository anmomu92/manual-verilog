#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <verilated.h>
#include <verilated_vcd_c.h>
//#include <verilated_dpi.h>
#include "Vmef.h"
#include "svdpi.h"
#include "Vmef__Dpi.h"

#define ESTADOS 5
char estado = 0;
vluint64_t tiempo = 0;
int errores = 0;

using namespace std;

// funciones
void reset(Vmef *dut, VerilatedVcdC *m_trace);
void tic(Vmef *dut, VerilatedVcdC *m_trace);
void prueba_estado(Vmef *dut, VerilatedVcdC *m_trace, int a, int b, int init);
void comprueba(const string salida, const string esperado, const string prueba, int i, int j);

// DPI
extern void sv_method();

int main(int argc, char** argv, char** env) {
    // instanciamos la UBP
    Vmef *dut = new Vmef;

    Verilated::scopesDump();

    // set the scope
    const svScope scope = svGetScopeFromName("TOP.mef");
    assert(scope);
    svSetScope(scope);

    // activamos la generación de traza
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    // reseteamos la UBP
    reset(dut, m_trace);

    // PRUEBAS 
    // generamos un tic
    tic(dut, m_trace);

    // INIT
    std::cout << "\n\n###################################";
    std::cout << "\nProbando INIT" << '\n';
    std::cout << "#################################";
    prueba_estado(dut, m_trace, 0, 0, 0);
    // A0
    std::cout << "\n\n###################################";
    std::cout << "\nProbando A0" << '\n';
    std::cout << "#################################";
    prueba_estado(dut, m_trace, 0, 0, 1);
    // A1
    std::cout << "\n\n###################################";
    std::cout << "\nProbando A1" << '\n';
    std::cout << "#################################";
    prueba_estado(dut, m_trace, 0, 0, 2);
    // OK0
    std::cout << "\n\n###################################";
    std::cout << "\nProbando OK0" << '\n';
    std::cout << "#################################";
    prueba_estado(dut, m_trace, 0, 0, 3);
    // OK1
    std::cout << "\n\n###################################";
    std::cout << "\nProbando OK1" << '\n';
    std::cout << "#################################";
    prueba_estado(dut, m_trace, 0, 0, 4);

    // FIN PRUEBAS
    cout << "El numero de errores totales es " << errores << "\n\n";


    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}

void reset(Vmef *dut, VerilatedVcdC *m_trace){
    dut->rst = 1;
    tic(dut, m_trace);
    dut->rst = 0;
    tic(dut, m_trace);
}

void tic(Vmef *dut, VerilatedVcdC *m_trace){
    dut->clk = 0;
    dut->eval();
    // volcamos 
    m_trace->dump(tiempo);
    tiempo++;
    dut->clk = 1;
    dut->eval();
    // volcamos 
    m_trace->dump(tiempo);
    tiempo++;

}

void prueba_estado(Vmef *dut, VerilatedVcdC *m_trace, int a, int b, int inicial){
    int i,j, entrada = 0;
    int intEst, intEst2;
    int contador = 0;
    string estado_prueba = "INIT"; 
    string estado = "INIT", esperado = "INIT"; 

    // mostramos el estado al entrar en la función
    std::cout << "\n\n---------------------------------------";
    std::cout << "\nEl estado al entrar en la función es " << estado << '\n';
    std::cout << "---------------------------------------";
    
    // for anidado para probar diferentes combinaciones de entrada
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            dut->A = 0;
            dut->B = 0;
            // inicializamos el estado
            reset(dut, m_trace);
            // nos movemos al estado que queremos probar
            switch(inicial){
                case 0: reset(dut, m_trace);
                        tic(dut, m_trace);
                        break;
                case 1: dut->A = 0; 
                        tic(dut, m_trace);
                        break;
                case 2: dut->A = 1; 
                        tic(dut, m_trace);
                        break;
                case 3: dut->A = 0; 
                        tic(dut, m_trace);
                        dut->A = 0; 
                        tic(dut, m_trace);
                        break;
                case 4: dut->A = 1; 
                        tic(dut, m_trace);
                        dut->A = 1;
                        tic(dut, m_trace);
                        break;
                default: estado = "INIT";
                         tic(dut, m_trace);
            }

            // comprobamos que el estado inicial es el correcto 
            std::bitset<3> est(sv_get_estado());
            intEst = static_cast<int>(est[7]) ? (est.to_ulong() - 256) : est.to_ulong();

            switch(intEst){
                case 0: estado_prueba = "INIT"; break;
                case 1: estado_prueba = "A0"; break;
                case 2: estado_prueba = "A1"; break;
                case 3: estado_prueba = "OK0"; break;
                case 4: estado_prueba = "OK1"; break;
                default: estado_prueba = "INIT";
            }

            std::cout << "\n---------------------------------------\n";
            std::cout << "Estado inicializado a " << estado_prueba << '\n';
            std::cout << "---------------------------------------" << '\n';


            // calculamos el estado esperado
            switch(intEst){
                case 0: if((i == 0) && (j == 0)){
                                esperado = "A0";
                             } else if ((i == 0) && (j == 1)){
                                 esperado = "A0";
                             } else if ((i == 1) && (j == 0)){
                                 esperado = "A1";
                             } else if ((i == 1) && (j == 1)) {
                                 esperado = "A1";
                             } else esperado = "INIT";
                             break;
                case 1: if((i == 0) && (j == 0)){
                                esperado = "OK0";
                             } else if ((i == 0) && (j == 1)){
                                 esperado = "OK0";
                             } else if ((i == 1) && (j == 0)){
                                 esperado = "A1";
                             } else if ((i == 1) && (j == 1)) {
                                 esperado = "A1";
                             } else esperado = "INIT";
                             break;
                case 2: if((i == 0) && (j == 0)){
                                esperado = "A0";
                             } else if ((i == 0) && (j == 1)){
                                 esperado = "A0";
                             } else if ((i == 1) && (j == 0)){
                                 esperado = "OK1";
                             } else if ((i == 1) && (j == 1)) {
                                 esperado = "OK1";
                             } else esperado = "INIT";
                             break;
                case 3: if((i == 0) && (j == 0)){
                                esperado = "OK0";
                             } else if ((i == 0) && (j == 1)){
                                 esperado = "OK0";
                             } else if ((i == 1) && (j == 0)){
                                 esperado = "A1";
                             } else if ((i == 1) && (j == 1)) {
                                 esperado = "OK1";
                             } else esperado = "INIT";
                             break;
                case 4: if((i == 0) && (j == 0)){
                                esperado = "A0";
                             } else if ((i == 0) && (j == 1)){
                                 esperado = "OK0";
                             } else if ((i == 1) && (j == 0)){
                                 esperado = "OK1";
                             } else if ((i == 1) && (j == 1)) {
                                 esperado = "OK1";
                             } else esperado = "INIT";
                             break;
                default: esperado = "INIT";
            }

            
            // asignamos las combinaciones de entradas a dicho estado
            //std::cout << '\n' << "("<< estado_prueba << ") A = " << i << "\tB = " << j << '\n';
            //std::cout << "---------------------------------------" << '\n';
            dut->A = i;
            dut->B = j;
            tic(dut, m_trace);

           // comprobamos que el estado final es el correcto 
            std::bitset<3> est2(sv_get_estado());
            intEst2 = static_cast<int>(est2[7]) ? (est2.to_ulong() - 256) : est2.to_ulong();

            switch(intEst2){
                case 0: estado = "INIT"; break;
                case 1: estado = "A0"; break;
                case 2: estado = "A1"; break;
                case 3: estado = "OK0"; break;
                case 4: estado = "OK1"; break;
                default: estado = "INIT";
            }

            comprueba(estado, esperado, estado_prueba, i, j);

            contador++;
        }
    }
}

void comprueba(const string salida, const string esperado, const string prueba, int i, int j){
    if(salida.compare(esperado) != 0){
        cout << "\n¡¡¡¡DESGRACIADOOO!!!! El resultado es erroneo, fracasado";
        std::cout << "\n---------------------------------------\n";
        std::cout << "A=" << i << " B=" << j << " -> " << salida << " != " << esperado << ", inutil mas que inutil." << '\n';
        std::cout << "---------------------------------------" << '\n';

        errores++;
    }
}
