#include "ElementalFuego.h"

ElementalFuego::ElementalFuego(string nombre, string elemento, int escudo, int vida) : Personaje(nombre, elemento, escudo, vida) {

}

void ElementalFuego::alimentar() {
    cout << "Estas alimentando a " << this->nombre << " un elemental de fuego, que consume madera para recuperar " << AUMENTO_ENERGIA_FUEGO << " de energia" << endl;
    if ((this->energia + AUMENTO_ENERGIA_FUEGO) > TOPE_ENERGIA) {
        this->energia = TOPE_ENERGIA;
    }
    else {
        energia += AUMENTO_ENERGIA_FUEGO;
    }
}
