#include "MenuJuego.h"

MenuJuego::MenuJuego(){}

void MenuJuego::mostrarMenu1() {
    cout << "\t1- Alimentar personaje." << endl;
    cout << "\t2- Mover personaje." << endl;
    cout << "\t3- Saltear opción." << endl;
    cout << "\t4- Salir del juego." << endl;
}

void MenuJuego::accionMenu1(int eleccion, Juego* juego, Personaje* personaje, Grafo* grafo){
    switch (eleccion){
        case MJ_ALIMENTAR:
            personaje->alimentar();
            break;

        case MJ_MOVER:
            juego->moverPersonaje(personaje, grafo);
            break;

        case MJ_PASAR:
            break;

        case MJ_SALIR:
            juego->setSalir(true);
            break;

        default:
            cout << "Opcion inválida" << endl;
    }
}

void MenuJuego::mostrarMenu2() {
    cout << "\t1- Atacar." << endl;
    cout << "\t2- Defender." << endl;
    cout << "\t3- Saltar opción." << endl;
    cout << "\t4- Salir." << endl;
}

void MenuJuego::accionMenu2(int eleccion, Juego* juego, Personaje* personaje, Grafo* grafo){
    switch (eleccion){
        case MJ_ATACAR:
            if(juego->getTurno() == JUGADOR1){
                personaje->atacar(juego->getJugador2()->getPersonajes());
            }else{
                personaje->atacar(juego->getJugador1()->getPersonajes());
            }
            break;

        case MJ_DEFENDER:
            if(juego->getTurno() == JUGADOR1){
                personaje->defender(juego->getJugador1()->getPersonajes());
            }else{
                personaje->defender(juego->getJugador2()->getPersonajes());
            }
            break;

        case MJ_PASAR:
            break;

        case MJ_SALIR:
            juego->setSalir(true);
            break;

        default:
            cout << "Opcion inválida" << endl;
    }
}

