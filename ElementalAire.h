#ifndef TP2_ELEMENTALAIRE_H
#define TP2_ELEMENTALAIRE_H

#include <iostream>
#include "Personaje.h"

using namespace std;

class ElementalAire: public Personaje{
public:
    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalAire cargando sus atributos
    ElementalAire(string nombre, string elemento, int escudo, int vida);

    // PRE: -
    // POS: Notifica al usuario el estado de la alimentación del personaje
    void alimentar();
};


#endif //TP2_ELEMENTALAIRE_H
