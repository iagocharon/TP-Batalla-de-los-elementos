#ifndef TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_TABLERO_H
#define TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_TABLERO_H

#include <iostream>
#include "Casillero.h"
#include <fstream>
#include "Jugador.h"
#include "Juego.h"
#include "Grafo.h"

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

class Tablero {
private:
    Casillero* tablero[MAX_FILAS][MAX_COLUMNAS];
public:

    // PRE:
    // POS:
    Tablero();

    // PRE:
    // POS:
    void mostrarTablero(Juego* juego);

    // PRE:
    // POS:
    void cargarGrafo(Grafo* grafo);

private:

    // PRE:
    // POS:
    void mostrarPersonajeJugador1(int columna, int fila, char elemento);

    // PRE:
    // POS:
    void mostrarPersonajeJugador2(int columna, int fila, char elemento);

    // PRE:
    // POS:
    char personajeJugado(int columna, int fila, Juego* juego, int& jugador);

    // PRE:
    // POS:
    char elementoPersonaje(Personaje* personaje);
};


#endif //TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_TABLERO_H
