#include "MenuJuego.h"

MenuJuego::MenuJuego(){}

void MenuJuego::mostrarMenu1() {
    cout << "\t1- Alimentar personaje." << endl;
    cout << "\t2- Mover personaje." << endl;
    cout << "\t3- Saltear opción." << endl;
    cout << "\t4- Salir del juego." << endl;
}

bool MenuJuego::accionMenu1(int eleccion, Juego* juego, Personaje* personaje, Grafo* grafo){
    Utiles utiles;
    bool accionRealizada = false;
    switch (eleccion){
        case MJ_ALIMENTAR:
            personaje->alimentar();
            accionRealizada = true;
            break;

        case MJ_MOVER:
            accionRealizada = juego->moverPersonaje(personaje, grafo);
            utiles.pausa();
            break;

        case MJ_PASAR:
            accionRealizada = true;
            break;

        case MJ_SALIR:
            juego->setSalir(true);
            accionRealizada = true;
            break;

        default:
            cout << "Opcion inválida" << endl;
    }
    return accionRealizada;
}

void MenuJuego::mostrarMenu2() {
    cout << "\t1- Atacar." << endl;
    cout << "\t2- Defender." << endl;
    cout << "\t3- Saltar opción." << endl;
    cout << "\t4- Salir." << endl;
}

bool MenuJuego::accionMenu2(int eleccion, Juego* juego, Personaje* personaje){

    bool accionRealizada = false;
    switch (eleccion){
        case MJ_ATACAR:
            if(personaje ->energiaNecesariaAtaque()) {

                if (juego->getTurno() == JUGADOR1)
                    personaje->atacar(juego->getJugador2()->getPersonajes());

                else
                    personaje->atacar(juego->getJugador1()->getPersonajes());

                accionRealizada = true;
            } else
                cout << "El personaje no tiene la energía suficiente para atacar" << endl;
            break;

        case MJ_DEFENDER:
            if(personaje->energiaNecesariaDefensa()) {

                if (juego->getTurno() == JUGADOR1)
                    personaje->defender(juego->getJugador1()->getPersonajes());

                else
                    personaje->defender(juego->getJugador2()->getPersonajes());

                accionRealizada = true;
            } else
                cout << "El personaje no tiene la energía suficiente para defenderse" << endl;
            break;

        case MJ_PASAR:
            accionRealizada = true;
            break;

        case MJ_SALIR:
            juego->setSalir(true);
            accionRealizada = true;
            break;

        default:
            cout << "Opcion inválida" << endl;
    }
    return accionRealizada;
}

