//
// Created by daniel on 23/11/20.
//

#ifndef TP2_PERSONAJE_H
#define TP2_PERSONAJE_H

const int TOPE_ENERGIA = 20;

using namespace std;
#include <iostream>

class Personaje{

protected:
    //Atributos

    string nombre;
    short escudo;
    short vida;
    short energia;

public:
    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un personaje cargando sus atributos con lo recibido
    Personaje(std::string nombre, short escudo, short vida);

    // PRE: -
    // POS: Alimenta al personaje, notifica al usuario
    virtual void alimentar() = 0;

    // PRE: -
    // POS: Devuelve el nombre del personaje
    std::string obtenerNombre();

    // PRE: -
    // POS: Devuelve el escudo del personaje
    short obtenerEscudo();

    // PRE: -
    // POS: Devuelve la vida del personaje
    short obtenerVida();

    // PRE: -
    // POS: Devuelve la energia del personaje
    short obtenerEnergia();
};

#endif //TP2_PERSONAJE_H
