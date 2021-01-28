#ifndef Juego_hpp
#define Juego_hpp

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include "Personaje.h"
#include "ABB.hpp"
#include "Casillero.hpp"
#include "ElementalAgua.h"
#include "ElementalAire.h"
#include "ElementalFuego.h"
#include "ElementalTierra.h"

#define MAX_PERSONAJES 3
#define MAX_FILAS 8
#define MAX_COLUMNAS 8
#define NOMBRE_TABLERO "tablero.csv"
#define MONTANIA "M"
#define PRECIPICIO "P"
#define LAGO "L"
#define VOLCAN "V"
#define CAMINO "C"
#define VACIO "O"

using namespace std;

class Juego {
private:
    Personaje* personajesJugador1[MAX_PERSONAJES];
    Personaje* personajesJugador2[MAX_PERSONAJES];
    ABB* personajes;
    int eleccion;
    int turno; //1 Jugador1 y 2 Jugador2.
    Casillero* tablero[MAX_FILAS][MAX_COLUMNAS];
    
public:
    Juego();
    Juego(ABB* personajes);
    
    void mostrarMenu();
    void accionMenu();
    
    void buscar();
    void mostrarPersonajes();
    void seleccionarPersonaje(); // Antes de llamarla hay que fijarse la cantidad de personajes que ya eligio cada uno.
    void cargarTablero();
    void mostrarTablero(); //Todavia falta agregar que muestre los personajes.
    
    
};

#endif /* Juego_hpp */
