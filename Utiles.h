#ifndef TP2_UTILES_H
#define TP2_UTILES_H

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

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define ANCHO_PANTALLA 54
#define RUTA "personajes.csv"

typedef Personaje* Tipo;

using namespace std;

class Utiles{

public:
    // PRE: -
    // POS: Crea un *ABB, para luego devolverlo cargado con los personajes leidos del archivo correspondiente
    ABB* personajes();

    // PRE: Los valores recibidos son válidos
    // POS: Devuelve un Tipo personaje cargando lo recibido en sus atributos
    Tipo establecerTipo(string elemento, string nombre, int escudo, int vida);

    // PRE: Los valores recibidos son válidos
    // POS: Devuelve un Tipo personaje cargando lo recibido en sus atributos y lo no recibido de forma default
    Tipo establecerTipo(string elemento, string nombre);

    // PRE: minimo < maximo
    // POS: Devuelve un numero aleatorio entre minimo y maximo
    int randomizar(int minimo, int maximo);

    // PRE: -
    // POS: Limpia la pantalla
    void limpiarPantalla();

    // PRE: -
    // POS: Hace una pausa en la ejecución del programa
    void pausa();

    // PRE: -
    // POS: Muestra el texto recidido enmarcado
    void enmarcar(string texto);
};


#endif //TP2_UTILES_H
