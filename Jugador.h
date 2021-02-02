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
    vector<Personaje*> personajesJugador;
    int cantidadPersonajes;

public:
    Jugador();
    vector<Personaje*> getPersonajes();
    vector<Personaje*> setPersonaje(int posicion, Personaje* personaje);
    int getCantidadPersonajes();
    void incrementarCantidadPersonajes();
};


#endif //TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_JUGADOR_H