#ifndef TP2_UTILES_H
#define TP2_UTILES_H

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif


#include "Personaje.h"
#include "ElementalAgua.h"
#include "ElementalTierra.h"
#include "ElementalAire.h"
#include "ElementalFuego.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include "ABB.hpp"
#include "ArchivoPersonajes.h"


#define RUTA "personajes.csv"
#define ANCHO_PANTALLA 54

typedef Personaje* Tipo;

using namespace std;

class Utiles{

public:
    // PRE:
    // POS:
    ABB* personajes();

    // PRE: los valores recibidos son válidos
    // POS: devuelve un Tipo personaje cargando lo recibido en sus atributos
    Tipo establecerTipo(string elemento, string nombre, int escudo, int vida);

    // PRE: los valores recibidos son válidos
    // POS: devuelve un Tipo personaje cargando lo recibido en sus atributos y lo no recibido de forma default
    Tipo establecerTipo(string elemento, string nombre);

    // PRE: minimo < maximo
    // POS: devuelve un numero aleatorio entre minimo y maximo
    int randomizar(int minimo, int maximo);
    
    void limpiarPantalla();
    
    void pausa();
    
    void enmarcar(string texto);
};


#endif //TP2_UTILES_H
