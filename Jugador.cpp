#include "Jugador.h"

Jugador::Jugador(){
    personajesJugador[0] = NULL;
    personajesJugador[1] = NULL;
    personajesJugador[2] = NULL;
    cantidadPersonajes = 0;
}

Personaje* Jugador::getPersonaje(int posicion){
    return this->personajesJugador[posicion];
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

bool Jugador::perdio() {
    bool resultado = true;
    for (int i = 0; i < MAX_PERSONAJES; i++) {
        if (personajesJugador[i]->getVida() > 0) {
            resultado = false;
        }
    }
    return resultado;
}
