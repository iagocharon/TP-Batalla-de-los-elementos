
#ifndef TP2_EJECUCION_H
#define TP2_EJECUCION_H

#include "ABB.hpp"

const int IDE = 1;
const int TERMINAL = 2;

ABB* personajes(int tipo);

//Funcion auxiliar para los distintos posibles tipos de compilacion
void ejecucion(ABB* personajes);

#endif //TP2_EJECUCION_H
