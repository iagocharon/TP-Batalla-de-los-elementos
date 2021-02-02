#ifndef TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_TABLERO_H
#define TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_TABLERO_H

#include <iostream>
#include "Casillero.hpp"
#include <fstream>
#include "Jugador.h"
#include "Juego.hpp"

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
    void cargarTablero();
    void mostrarTablero(Juego* juego);
private:
    void mostrarPersonajeJugador1(int columna, int fila, char elemento);
    void mostrarPersonajeJugador2(int columna, int fila, char elemento);
    char personajeJugado(int columna, int fila, Juego* juego, int& jugador);
    char elementoPersonaje(Personaje* personaje);
};


#endif //TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_TABLERO_H
