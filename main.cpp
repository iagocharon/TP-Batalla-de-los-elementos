#include "Jugar.h"
#include <iostream>

using namespace std;

int main() {
    srand(unsigned(time(NULL)));
    Jugar* jugar = new Jugar();

    jugar->flujoDeJuego();
    
    delete jugar;

    return 0;
}
