#include "MenuJuego.h"

MenuJuego::MenuJuego(){}

void MenuJuego::mostrarMenu1() {
    cout << "\t1- Alimentar personaje." << endl;
    cout << "\t2- Mover personaje." << endl;
    cout << "\t3- Saltear opción." << endl;
    cout << "\t4- Salir del juego." << endl;
}

void MenuJuego::accionMenu1(int eleccion, Juego* juego, Personaje* personaje){
    system("clear");

    switch (eleccion){
        case 1:
            personaje->alimentar();
            break;

        case 2:
            //juego->moverPersonaje(personaje);
            //break;

        case 3:
            break;

        case 4:
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

void MenuJuego::accionMenu2(int eleccion, Juego* juego, Personaje* personaje){
    system("clear");

    switch (eleccion){
        case 1:
            if(juego->getTurno() == 1){
                personaje->atacar(juego->getJugador2()->getPersonajes());
            }else{
                personaje->atacar(juego->getJugador1()->getPersonajes());
            }
            break;

        case 2:
            if(juego->getTurno() == 1){
                personaje->defender(juego->getJugador1()->getPersonajes());
            }else{
                personaje->defender(juego->getJugador2()->getPersonajes());
            }
            break;

        case 3:
            break;

        case 4:
            juego->setSalir(true);
            break;

        default:
            cout << "Opcion inválida" << endl;
    }
}

