//
// Created by nicolas on 24/11/20.
//

#include "Personaje.h"
#include <iostream>
Personaje::Personaje(string nombre, short escudo, short vida){

    this -> nombre = nombre;
    this -> escudo = escudo;
    this -> vida = vida;
    energia = rand() % 20;
}

std::string Personaje::obtenerNombre(){

    return nombre;
}

short Personaje::obtenerEscudo() {

    return escudo;
}

short Personaje::obtenerVida() {

    return vida;
}

short Personaje::obtenerEnergia() {

    return energia;
}
