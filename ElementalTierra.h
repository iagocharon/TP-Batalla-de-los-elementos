#ifndef TP2_ELEMENTALTIERRA_H
#define TP2_ELEMENTALTIERRA_H

#include <iostream>
#include "Personaje.h"

using namespace std;

const int AUMENTO_ENERGIA_TIERRA = 8;

class ElementalTierra: public Personaje{

public:
    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalTierra cargando sus atributos
    ElementalTierra(string nombre,string elemento, int escudo, int vida);

    // PRE: -
    // POS: Notifica al usuario cómo fue alimentado el Personaje y aumenta la energía en AUMENTO_ENERGIA_TIERRA
    void alimentar();
};


#endif //TP2_ELEMENTALTIERRA_H
