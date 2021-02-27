#ifndef TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_JUGADOR_H
#define TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_JUGADOR_H

#include <iostream>
#include <string>
#include "Personaje.h"
#include "ABB.hpp"

#define MAX_PERSONAJES 3

using namespace std;

class Jugador {
private:
    Personaje* personajesJugador[MAX_PERSONAJES];
    int cantidadPersonajes;

public:
    // Constructor
    Jugador();

    // PRE: -
    // POS: Devuelve un puntero al vector de personajes del jugador.
    Personaje** getPersonajes();

    // PRE: Recibe un entero con valores entre 0 y 2, y un personaje cargado.
    // POS: Agrega al personaje al vector de personajes en la posicion indicada y aumenta la
    //      cantidad de personajes.
    void setPersonaje(int posicion, Personaje* personaje);

    // PRE: -
    // POS: Devuelve la cantidad de personajes del jugador.
    int getCantidadPersonajes();

    // -
    // Devuelve true si todos los personajes del jugador estan muertos o false en caso contrario.
    bool jugadorMuerto();

    // PRE: -
    // POS: Comprueba si hay elementales de aire o fuego en el equipo, y si los hay aumenta
    //      la energía de los de aire y daña a los de fuego sin energía.
    void comprobarFuegoYAire();

    // PRE: -
    // POS: Reduce mucho la vida de un personaje muerto y lo quita del tablero para que no interfiera
    //      con el resto del juego.
    void matarPersonajes();
};


#endif //TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_JUGADOR_H
