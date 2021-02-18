#ifndef Juego_hpp
#define Juego_hpp

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "ColaPrioridad.h"
#include <fstream>
#include <string>
#include "Personaje.h"
#include "ABB.hpp"
#include "Casillero.h"
#include "Jugador.h"
#include "Personaje.h"
#include "ElementalAire.h"
#include "ElementalAgua.h"
#include "ElementalFuego.h"
#include "ElementalTierra.h"

#define PARTIDA "partida.csv"
#define PARTIDA_ENCONTRADA 0
#define PARTIDA_NO_ENCONTRADA -1

using namespace std;

class Juego {
private:
    Jugador* jugador1;
    Jugador* jugador2;
    ABB* personajes;
    bool salir;
    int turno;

public:
    //Constructor con un árbol de personajes y un tablero.
    Juego(ABB* personajes);

    // PRE: -
    // POS: Devuelve un puntero al árbol de personajes.
    ABB* getPersonajes();

    // PRE: -
    // POS: Devuelve un booleano que indica si se quiere salir o no.
    bool getSalir();

    // PRE: Recibe un booleano.
    // POS: Cambia salir que es false por default (se debe llamar solo cuando se quiera salir del juego).
    void setSalir(bool salir);

    // PRE: -
    // POS: Devuelve un puntero al jugador 1.
    Jugador* getJugador1();

    // PRE: -
    // POS: Devuelve un puntero al jugador 2.
    Jugador* getJugador2();

    // PRE: -
    // POS: Devuelve el turno actual.
    int getTurno();

    // PRE:
    // POS:
    void posicionarPersonajeJugador1(int personaje);
    void posicionarPersonajeJugador2(int personaje);

    //void moverPersonaje(Personaje* personaje);

    // PRE: -
    // POS: Cambia el turno entre 1 y 2 aleatoriamente.
    void randomizarTurno();

    // PRE: -
    // POS: Cambia el turno entre 1 y 2 según corresponda.
    void cambiarTurno();

    // PRE:
    // POS:
    void seleccionPersonajes();

    // PRE: -
    // POS: Intenta cargar una partida ya empezada. Devuelve 0 si tiene exito o -1 en caso contraro.
    //  También muestra un mensaje por pantalla para ambos casos.
    int partidaCargar();

    // PRE: -
    // POS: Crea un archivo con el turno actual y los personajes de cada jugador.
    void partidaGuardar();

private:
    

    //PRE:
    //POS:
    bool posicionValida(int fila, int columna);

    // PRE: -
    // POS: El jugador 1 ingresa el nombre del personaje del árbol que desea conservar. Luego
    //  se elimina este personaje del árbol.
    void seleccionJugador1();

    // PRE: -
    // POS: El jugador 2 ingresa el nombre del personaje del árbol que desea conservar. Luego
    //  se elimina este personaje del árbol.
    void seleccionJugador2();
};

#endif /* Juego_hpp */
