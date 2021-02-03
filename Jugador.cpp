#include "Jugador.h"

Jugador::Jugador(){
    personajesJugador[0] = NULL;
    personajesJugador[1] = NULL;
    personajesJugador[2] = NULL;
    cantidadPersonajes = 0;
}

vector<Personaje*> Jugador::getPersonajes(){
    return this->personajesJugador;
}

void Jugador::setPersonaje(int posicion, Personaje* personaje){
    this->personajesJugador[posicion] = personaje;
}

int Jugador::getCantidadPersonajes(){
    return this->cantidadPersonajes;
}

void Jugador::incrementarCantidadPersonajes(){
    this->cantidadPersonajes++;
}
