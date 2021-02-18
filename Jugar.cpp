#include "Jugar.h"

void Jugar::inicio(Juego *juego){
    MenuInicio menu;
    int eleccion = 0;

    if (juego->getPersonajes() == nullptr) {
        cout << "No se encontro el archivo de personajes. Terminando ejecución." << endl;
        juego->setSalir(true);
        return;
    }

    while (eleccion != SALIR && eleccion != COMENZAR) {
        menu.mostrarMenu();
        menu.espaciado();
        cout << "Ingrese su eleccion: ";
        cin >> eleccion;
        menu.accionMenu(eleccion, juego);
        menu.espaciado();
    }
}

void Jugar::seleccionarPersonajes(Juego *juego) {
    MenuSeleccion menu;
    int eleccion = 0;

    for(int i = 0; i < MAX_PERSONAJES*2; i++){
        while (eleccion != 3) {
            menu.mostrarMenu();
            cin >> eleccion;
            system("clear");
            menu.accionMenu(eleccion, juego);
            if (juego->getSalir()) {
                system("clear");
                return;
            }
        }
        eleccion = 0;
    }
}

void Jugar::posicionarPersonajes(Juego *juego, Tablero *tablero) {
    for (int i = 0; i < MAX_PERSONAJES; i++){
        juego->posicionarPersonaje(i);
        tablero->mostrarTablero(juego);
    }
    system("clear");
}

Personaje *Jugar::determinarPersonaje(Juego *juego, int personaje) {
    if (juego->getTurno() == 1) {
        return juego->getJugador1()->getPersonajes()[personaje];
    } else {
        return juego->getJugador1()->getPersonajes()[personaje];
    }
}

void Jugar::tableroYPersonaje(Juego *juego, Tablero *tablero, Personaje *personaje) {
    tablero->mostrarTablero(juego);
    personaje->mostrar();
}

void Jugar::jugar(Juego *juego, Tablero *tablero) {
    int eleccion = 0;
    MenuJuego menu;
    Personaje *personaje;

    for (int i = 0; i < MAX_PERSONAJES; i++) {
        juego->getJugador1()->matarPersonajes();
        juego->getJugador2()->matarPersonajes();
        personaje = determinarPersonaje(juego, i);
        if (personaje->getVida() <= 0) {
            continue;
        }

        do {
            tableroYPersonaje(juego, tablero, personaje);
            menu.mostrarMenu1();
            cin >> eleccion;
            menu.accionMenu1(eleccion, juego, personaje);
            if (juego->getSalir()) {
                juego->partidaGuardar();
                system("clear");
                return;
            }
            system("clear");
        } while (eleccion < 1 || eleccion > 4);
        do {
            tableroYPersonaje(juego, tablero, personaje);
            menu.mostrarMenu2();
            cin >> eleccion;
            menu.accionMenu2(eleccion, juego, personaje);
            if (juego->getSalir()) {
                juego->partidaGuardar();
                system("clear");
                return;
            }
            system("clear");
        } while (eleccion < 1 || eleccion > 4);
    }
    juego->cambiarTurno();
}

bool Jugar::finDelJuego(Juego *juego) {
    bool jugador1Muerto = true;
    bool jugador2Muerto = true;
    for (int i = 0; i < MAX_PERSONAJES; i++) {
        if (juego->getJugador1()->getPersonajes()[i]->getVida() > 0) {
            jugador1Muerto = false;
        }
        if (juego->getJugador2()->getPersonajes()[i]->getVida() > 0) {
            jugador2Muerto = false;
        }
    }
    anunciarGanador(jugador1Muerto, jugador2Muerto);
    return jugador1Muerto || jugador2Muerto;
}

void Jugar::anunciarGanador(bool jugador1Muerto, bool jugador2Muerto) {
    if (jugador1Muerto) {
        cout << "¡GANA EL JUGADOR 2!" << endl;
    } else if (jugador2Muerto) {
        cout << "¡GANA EL JUGADOR 1!" << endl;
    }
}
