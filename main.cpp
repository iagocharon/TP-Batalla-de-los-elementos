#include "Jugar.h"
#include <iostream>

using namespace std;


/*
 * PRE Y POS QUE FALTAN
 *      Algunas en juego
 *      grafo
 *      datosGrafo
 *      casillero
 */
int main() {
    srand(unsigned(time(NULL)));
    auto* jugar = new Jugar();

    jugar->flujoDeJuego();

    return 0;
}
