#include "Jugador.h"

Jugador::Jugador() {
    personajesJugador[0] = nullptr;
    personajesJugador[1] = nullptr;
    personajesJugador[2] = nullptr;
    cantidadPersonajes = 0;
}

Personaje** Jugador::getPersonajes() {
    return this->personajesJugador;
}

void Jugador::setPersonaje(int posicion, Personaje* personaje) {
    cantidadPersonajes++;
    this->personajesJugador[posicion] = personaje;
}

int Jugador::getCantidadPersonajes() {
    return this->cantidadPersonajes;
}

bool Jugador::jugadorMuerto() {
    for (int i = 0; i < MAX_PERSONAJES; i++) {
        if (personajesJugador[i]->getVida() > 0) {
            return false;
        }
    }
    return true;
}

void Jugador::comprobarFuegoYAire() {
    for(int i = 0; i < MAX_PERSONAJES; i++) {
        if(personajesJugador[i]->getElemento() == ELEMENTO_AIRE) {
            personajesJugador[i]->setEnergia(personajesJugador[i]->getEnergia() + 10);
        }
        else if(personajesJugador[i]->getElemento() == ELEMENTO_FUEGO) {
            if(personajesJugador[i]->getEnergia() <= 0) {
                personajesJugador[i]->setVida(personajesJugador[i]->getVida() - 5);
            }
        }
    }
}

void Jugador::matarPersonajes() {
    for(int i = 0; i < MAX_PERSONAJES; i++) {
        if(personajesJugador[i]->getVida() <= 0) {
            personajesJugador[i]->setVida(-10000);
            personajesJugador[i]->setColumna(-1);
            personajesJugador[i]->setFila(-1);
        }
    }
}




