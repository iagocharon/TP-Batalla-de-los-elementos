#include "Jugador.h"

Jugador::Jugador(){
    personajesJugador[0] = new ElementalAire(" ","aire",0,0,0,-1,-1);
    personajesJugador[1] = new ElementalAire(" ","aire",0,0,0,-1,-1);
    personajesJugador[2] = new ElementalAire(" ","aire",0,0,0,-1,-1);
    cantidadPersonajes = 0;
}

Personaje** Jugador::getPersonajes(){
    return this->personajesJugador;
}

void Jugador::setPersonaje(int posicion, Personaje* personaje){
    cantidadPersonajes++;
    this->personajesJugador[posicion] = personaje;
}

int Jugador::getCantidadPersonajes(){
    return this->cantidadPersonajes;
}

void Jugador::matarPersonajes(){
    for(int i = 0; i < MAX_PERSONAJES; i++){
        if(personajesJugador[i]->getVida() <= 0){
            personajesJugador[i]->setVida(-10000);
            personajesJugador[i]->setColumna(-1);
            personajesJugador[i]->setFila(-1);
        }
    }
}


