#ifndef TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_JUGADOR_H
#define TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_JUGADOR_H

#include <iostream>
#include <vector>
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
    Jugador();
    Personaje* getPersonaje(int posicion);
    void setPersonaje(int posicion, Personaje* personaje);
    int getCantidadPersonajes();
    void incrementarCantidadPersonajes();
};


#endif //TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_JUGADOR_H
