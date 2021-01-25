//
// Created by daniel on 23/11/20.
//

#ifndef TP2_ELEMENTALAGUA_H
#define TP2_ELEMENTALAGUA_H

const int AUMENTO_ENERGIA_AGUA = 10;
const int TOPE_ALIMENTACIONES = 3;

#include "Personaje.h"

class ElementalAgua: public Personaje{
private:
    int vecesAlimentado;

public:
    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalAgua cargando sus atributos
    ElementalAgua(std::string nombre, short escudo, short vida);

    // PRE: -
    // POS: Notifica al usuario cómo fue alimentado el Personaje y aumenta la energía en AUMENTO_ENERGIA_AGUA
    //      En caso de ser efectuada la alimentación aumenta en 1 las vecesAlimentado
    void alimentar();
};

#endif //TP2_ELEMENTALAGUA_H
