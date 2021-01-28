#ifndef TP2_ELEMENTALAGUA_H
#define TP2_ELEMENTALAGUA_H

#include <iostream>
#include "Personaje.h"
#include <vector>

#define AUMENTO_ENERGIA_AGUA 10
#define TOPE_ALIMENTACIONES 3
#define MINIMO_ENERGIA_AGUA 5
#define DANIO_AGUA 20
#define MODIFICADOR_AGUA 10

using namespace std;

class ElementalAgua: public Personaje{
private:
    int vecesAlimentado;

public:
    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalAgua cargando sus atributos
    ElementalAgua(string nombre, string elemento, int escudo, float vida);

    // PRE: -
    // POS: Notifica al usuario cómo fue alimentado el Personaje y aumenta la energía en AUMENTO_ENERGIA_AGUA
    //      En caso de ser efectuada la alimentación aumenta en 1 las vecesAlimentado
    void alimentar();
    
    void atacar(Personaje* enemigos[MAX_PERSONAJES]);
};

#endif //TP2_ELEMENTALAGUA_H
