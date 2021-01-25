//
// Created by nicolas on 28/11/20.
//

#include "utiles.h"

Tipo Utiles::establecerTipo(string elemento, string nombre, short escudo, short vida){

    Tipo personaje;

    if(elemento == "aire")
        personaje = new ElementalAire(nombre, escudo, vida);

    else if(elemento == "fuego")
        personaje = new ElementalFuego(nombre, escudo, vida);

    else if(elemento == "tierra")
        personaje = new ElementalTierra(nombre, escudo, vida);

    else
        personaje = new ElementalAgua(nombre, escudo, vida);

    return personaje;
}

Tipo Utiles::establecerTipo(string elemento, string nombre){

    Tipo personaje;

    short escudo = randomizar(0, 2);
    short vida = randomizar(10, 100);

    personaje = establecerTipo(elemento, nombre, escudo, vida);

    return personaje;
}

short Utiles::randomizar(short minimo, short maximo){

    srand(time(0));
    short numero = 0;

    short rango = maximo - minimo + 1;
    numero = rand() % rango + minimo;

    return numero;
}