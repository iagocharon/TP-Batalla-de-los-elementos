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
#define INICIAL_AGUA 'W'
#define INICIAL_AIRE 'A'
#define INICIAL_TIERRA 'T'
#define INICIAL_FUEGO 'F'


using namespace std;

class Tablero {
private:
    Casillero* tablero[MAX_FILAS][MAX_COLUMNAS];
public:
    // CONSTRUCTOR
    // PRE: -.
    // POS: Lee del archivo de tablero y crea el objeto con esta informacion.
    Tablero();

    // PRE: Recibe la informacion del juego mediante un objeto de este tipo.
    // POS: Muestra el tablero y los personajes.
    void mostrarTablero(Juego* juego);

    // PRE: Recibe un grafo al cual cargar la informacion del tablero.
    // POS: Carga la informacion al grafo.
    void cargarGrafo(Grafo* grafo);

private:

    // PRE: Recibe las coordenadas de fila y columna, asi como el elemento del personaje.
    // POS: Muestra el casillero del tablero, con el elemento del personaje con el color que corresponde.
    //      Si el elemento es un char vacio, muestra solo el casillero.
    void mostrarPersonajeJugador1(int columna, int fila, char elemento);

    // PRE: Recibe las coordenadas de fila y columna, asi como el elemento del personaje.
    // POS: Muestra el casillero del tablero, con el elemento del personaje con el color que corresponde.
    //      Si el elemento es un char ' ', muestra solo el casillero.
    void mostrarPersonajeJugador2(int columna, int fila, char elemento);

    // PRE: Recibe las coordenadas, el juego y el jugador.
    // POS: Devuelve un char con la inicial del elemento en esa posicion.
    //      Si no hay personaje en esa posicion, devuelve ' '.
    char personajeJugado(int columna, int fila, Juego* juego, int& jugador);

    // PRE: Recibe un personaje.
    // POS: Devuelve un char con la inicial del mismo.
    char elementoPersonaje(Personaje* personaje);

    // PRE: -
    // POS: Muestra a que hace referencia cada color del tablero.
    void mostrarGlosario();
};


#endif //TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_TABLERO_H
