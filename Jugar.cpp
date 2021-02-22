#include "Jugar.h"

void Jugar::inicio(Juego *juego) {
    MenuInicio menu;
    Utiles utiles;
    int eleccion = 0;

    if (juego->getPersonajes() == nullptr) {
        cout << "No se encontro el archivo de personajes. Terminando ejecución." << endl;
        juego->setSalir(true);
        return;
    }

    while (eleccion != MI_SALIR && eleccion != MI_COMENZAR) {
        utiles.limpiarPantalla();
        utiles.enmarcar("BATALLA DE LOS ELEMENTOS");
        menu.mostrarMenu();
        menu.espaciado();
        cout << "Ingrese su eleccion: ";
        cin >> eleccion;
        menu.accionMenu(eleccion, juego);
    }
}

void Jugar::seleccionarPersonajes(Juego *juego) {
    MenuSeleccion menu;
    int eleccion = 0;
    

    for(int i = 0; i < MAX_PERSONAJES*2; i++) {
        while (eleccion != MS_SELECCIONAR_PERSONAJE) {
            menu.mostrarMenu();
            cin >> eleccion;
            menu.accionMenu(eleccion, juego);
            if (juego->getSalir()) {
                return;
            }
        }
        eleccion = 0;
    }
}

void Jugar::posicionarPersonajes(Juego *juego, Tablero *tablero) {
    Utiles utiles;
    for (int i = 0; i < MAX_PERSONAJES; i++) {
        for(int j = 0; j < JUGADORES; j++) {
            utiles.limpiarPantalla();
            utiles.enmarcar("POSICIONAR PERSONAJES");
            tablero->mostrarTablero(juego);
            juego->posicionPersonajes(i);
            utiles.pausa();
        }
    }
}

Personaje *Jugar::determinarPersonaje(Juego *juego, int personaje) {
    if (juego->getTurno() == JUGADOR1) {
        juego->cambiarTurno();
        return juego->getJugador1()->getPersonajes()[personaje];
    }
    else {
        juego->cambiarTurno();
        return juego->getJugador2()->getPersonajes()[personaje];
    }
}

void Jugar::tableroYPersonaje(Juego *juego, Tablero *tablero, Personaje *personaje) {
    tablero->mostrarTablero(juego);
    cout << endl << endl;
    personaje->mostrar();
    cout << endl << endl;
}

void Jugar::anunciarTurnoJugador(Juego* juego) {
    if(juego->getTurno() == JUGADOR1) {
        cout << "\n\t\tTURNO JUGADOR 1\n" << endl;
    }
    else{
        cout << "\n\t\tTURNO JUGADOR 2\n" << endl;
    }
}

void Jugar::actualizarMuertes(Juego* juego) {
    juego->getJugador1()->matarPersonajes();
    juego->getJugador2()->matarPersonajes();
}

bool Jugar::eleccionValida(int eleccion) {
    return (eleccion >= MINIMO && eleccion <= MAXIMO);
}

void Jugar::primerMenuJuego(Juego* juego, Tablero* tablero, Personaje* personaje, Grafo* grafo, int& eleccion) {
    MenuJuego menu;
    tableroYPersonaje(juego, tablero, personaje);
    menu.mostrarMenu1();
    cin >> eleccion;
    menu.accionMenu1(eleccion, juego, personaje, grafo, tablero);
}

void Jugar::segundoMenuJuego(Juego* juego, Tablero* tablero, Personaje* personaje, Grafo* grafo, int& eleccion) {
    MenuJuego menu;
    tableroYPersonaje(juego, tablero, personaje);
    menu.mostrarMenu2();
    cin >> eleccion;
    menu.accionMenu2(eleccion, juego, personaje, grafo);
}

void Jugar::jugar(Juego *juego, Tablero *tablero, Grafo* grafo) {
    int eleccion = 0;
    Personaje *personaje;
    Utiles utiles;

    for (int i = 0; i < MAX_PERSONAJES; i++) {
        actualizarMuertes(juego);
        if(finDelJuego(juego)) {
            return;
        }
        for (int j = 0; j < 2; j++) {
            personaje = determinarPersonaje(juego, i);
            if (personaje->getVida() <= VIDA_MUERTO) {
                continue;
            }
            do {
                utiles.limpiarPantalla();
                if (juego->getTurno() == 1) {
                    utiles.enmarcar("TURNO DEL JUGADOR 2");
                }
                else {
                    utiles.enmarcar("TURNO DEL JUGADOR 1");
                }
                primerMenuJuego(juego, tablero, personaje, grafo, eleccion);
                if (juego->getSalir()) {
                    juego->partidaGuardar();
                    return;
                }
            } while (!eleccionValida(eleccion));
            do {
                utiles.limpiarPantalla();
                if (juego->getTurno() == 1) {
                    utiles.enmarcar("TURNO DEL JUGADOR 2");
                }
                else {
                    utiles.enmarcar("TURNO DEL JUGADOR 1");
                }
                segundoMenuJuego(juego, tablero, personaje, grafo, eleccion);
                if (juego->getSalir()) {
                    juego->partidaGuardar();
                    return;
                }
            } while (!eleccionValida(eleccion));
        }
    }
}

bool Jugar::finDelJuego(Juego *juego) {
    return juego->getJugador1()->jugadorMuerto() || juego->getJugador2()->jugadorMuerto();
}

void Jugar::anunciarGanador(Juego* juego) {
    if (juego->getJugador1()->jugadorMuerto()) {
        cout << "\n\n\t\t¡GANA EL JUGADOR 2!\n\n" << endl;
    }
    else{
        cout << "\n\n\t\t¡GANA EL JUGADOR 1!\n\n" << endl;
    }
}


void Jugar::flujoDeJuego() {
    Utiles utiles;
    ABB* arbolPersonajes = utiles.personajes();
    Juego* juego = new Juego(arbolPersonajes);
    Tablero* tablero = new Tablero();
    Grafo* grafo = new Grafo();
    tablero->cargarGrafo(grafo);

    inicio(juego);

    if(!juego->getSalir()) {
        if(juego->partidaCargar() == PARTIDA_NO_ENCONTRADA) {
            seleccionarPersonajes(juego);
            if(!juego->getSalir())
                posicionarPersonajes(juego, tablero);
            juego->randomizarTurno();
        }

        if(!juego->getSalir()) {
            while(!finDelJuego(juego) && !juego->getSalir()) {
                anunciarTurnoJugador(juego);
                jugar(juego, tablero, grafo);
                juego->cambiarTurno();
            }
            if(finDelJuego(juego)) {
                tablero->mostrarTablero(juego);
                anunciarGanador(juego);
                juego->borrarPartidaGuardada();
            }
        }
    }

    delete arbolPersonajes;
    delete tablero;
    delete juego;
}
