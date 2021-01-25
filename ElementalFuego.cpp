//
// Created by daniel on 23/11/20.
//

#include "ElementalFuego.h"
#include <iostream>

ElementalFuego::ElementalFuego(std::string nombre, short escudo, short vida) : Personaje( nombre, escudo, vida) {}

void ElementalFuego::alimentar() {

    cout << "Estas alimentando a " << nombre << " un elemental de fuego, que consume madera para recuperar " << AUMENTO_ENERGIA_FUEGO << " de energia" << endl;

    if(energia + AUMENTO_ENERGIA_FUEGO > TOPE_ENERGIA)
        energia = TOPE_ENERGIA;
    else
        energia += AUMENTO_ENERGIA_FUEGO;

}