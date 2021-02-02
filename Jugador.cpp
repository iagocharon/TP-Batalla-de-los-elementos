#include "Jugador.h"

Jugador::Jugador(){
    personajesJugador[0] = NULL;
    personajesJugador[1] = NULL;
    personajesJugador[2] = NULL;
    cantidadPersonajes = 0;
}

vector<Personaje*> Jugador::getPersonajes(){
    return personajesJugador;
}

vector<Personaje*> Jugador::setPersonaje(int posicion, Personaje* personaje){
    personajesJugador[posicion] = personaje;
}

int Jugador::getCantidadPersonajes(){
    return cantidadPersonajes;
}

void Jugador::incrementarCantidadPersonajes(){
    cantidadPersonajes++;
}
