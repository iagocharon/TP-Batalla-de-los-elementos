#include "ElementalAire.h"

ElementalAire::ElementalAire(string nombre, string elemento, int escudo, int vida) : Personaje(nombre, elemento, escudo, vida) {
    
}


void ElementalAire::alimentar() {
    cout << this->nombre << " al ser un elemental de aire no recupera energía, es decir que no se alimenta" << endl;
}
