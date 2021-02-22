#include "Jugar.h"
#include <iostream>

using namespace std;

int main() {
    srand(unsigned(time(NULL)));
    auto* jugar = new Jugar();

    jugar->flujoDeJuego();

    return 0;
}
