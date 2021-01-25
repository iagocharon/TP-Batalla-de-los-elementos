//
// Created by nicolas on 26/11/20.
//

#ifndef TP2_ELEMENTALAIRE_H
#define TP2_ELEMENTALAIRE_H
#include "Personaje.h"

class ElementalAire: public Personaje{

public:

    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalAire cargando sus atributos
    ElementalAire(std::string nombre, short escudo, short vida);

    // PRE: -
    // POS: Notifica al usuario el estado de la alimentación del personaje
    void alimentar();
};


#endif //TP2_ELEMENTALAIRE_H
