//
// Created by nicolas on 28/11/20.
//

#ifndef TP2_UTILES_H
#define TP2_UTILES_H
#include "Personaje.h"
#include "ElementalAgua.h"
#include "ElementalTierra.h"
#include "ElementalAire.h"
#include "ElementalFuego.h"
#include "Lista.h"
#include <cstdlib>
#include <ctime>
#include <string>

typedef Personaje* Tipo;

using namespace std;

class Utiles{

public:
    // PRE: los valores recibidos son válidos
    // POS: devuelve un Tipo personaje cargando lo recibido en sus atributos
    Tipo establecerTipo(string elemento, string nombre, short escudo, short vida);

    // PRE: los valores recibidos son válidos
    // POS: devuelve un Tipo personaje cargando lo recibido en sus atributos y lo no recibido de forma default
    Tipo establecerTipo(string elemento, string nombre);

    // PRE: minimo < maximo
    // POS: devuelve un numero aleatorio entre minimo y maximo
    short randomizar(short minimo, short maximo);
};


#endif //TP2_UTILES_H
