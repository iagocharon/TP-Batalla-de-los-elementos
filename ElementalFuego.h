#ifndef TP2_ELEMENTALFUEGO_H
#define TP2_ELEMENTALFUEGO_H

#include <iostream>
#include "Personaje.h"

using namespace std;

const int AUMENTO_ENERGIA_FUEGO = 15;

class ElementalFuego: public Personaje{
public:
    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalFuego cargando sus atributos
    ElementalFuego(string nombre, string elemento, int escudo, int vida);

    // PRE: -
    // POS: Notifica al usuario cómo fue alimentado el Personaje y aumenta la energía en AUMENTO_ENERGIA_FUEGO
    void alimentar();
};


#endif //TP2_ELEMENTALFUEGO_H
