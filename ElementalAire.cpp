//
// Created by nicolas on 26/11/20.
//

#include "ElementalAire.h"

ElementalAire::ElementalAire(std::string nombre, short escudo, short vida) : Personaje( nombre, escudo, vida){}


void ElementalAire::alimentar(){

    cout << nombre << " al ser un elemental de aire no recupera energía, es decir que no se alimenta" << endl;
}