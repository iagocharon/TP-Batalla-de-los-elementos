#ifndef TP2_ELEMENTALAGUA_H
#define TP2_ELEMENTALAGUA_H

#include <iostream>
#include "Personaje.h"

using namespace std;

const int AUMENTO_ENERGIA_AGUA = 10;
const int TOPE_ALIMENTACIONES = 3;

class ElementalAgua: public Personaje{
private:
    int vecesAlimentado;

public:
    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalAgua cargando sus atributos
    ElementalAgua(string nombre, string elemento, int escudo, int vida);

    // PRE: -
    // POS: Notifica al usuario cómo fue alimentado el Personaje y aumenta la energía en AUMENTO_ENERGIA_AGUA
    //      En caso de ser efectuada la alimentación aumenta en 1 las vecesAlimentado
    void alimentar();
};

#endif //TP2_ELEMENTALAGUA_H
