#include "Jugar.h"

void Jugar::seleccionarPersonajes(Juego* juego, MenuSeleccion menuSeleccion){
    int eleccion = 0;
    do{
        do{
            menuSeleccion.mostrarMenu();
            cin >> eleccion;
            system("clear");
            menuSeleccion.accionMenu(eleccion, juego);
            if(juego->getSalir()){
                return;
            }
        }while(eleccion != 3);

    }while(juego->getJugador1()->getCantidadPersonajes() < MAX_PERSONAJES ||
           juego->getJugador2()->getCantidadPersonajes() < MAX_PERSONAJES);
}

Personaje* Jugar::determinarPersonaje(Juego* juego, int personaje){
    if(juego->getTurno() == 1){
        return juego->getJugador1()->getPersonajes()[personaje];
    }else{
        return juego->getJugador1()->getPersonajes()[personaje];
    }
}

void Jugar::tableroYPersonaje(Juego* juego, Tablero* tablero, Personaje* personaje){
    tablero->mostrarTablero(juego);
    personaje->mostrar();
}

void Jugar::jugar(Juego* juego, MenuJuego menuJuego, Tablero* tablero) {
    int eleccion = 0;
    Personaje* personaje;

    for (int i = 0; i < MAX_PERSONAJES; i++){
        juego->getJugador1()->matarPersonajes();
        juego->getJugador2()->matarPersonajes();
        personaje = determinarPersonaje(juego, i);
        if(personaje->getVida() <= 0){
            continue;
        }

        do {
            tableroYPersonaje(juego, tablero, personaje);
            menuJuego.mostrarMenu1();
            cin >> eleccion;
            menuJuego.accionMenu1(eleccion, juego, personaje);
            if(!juego->getSalir()) {
                juego->partidaGuardar();
                system("clear");
                return;
            }
            system("clear");
        } while (eleccion < 1 || eleccion > 4);
        do {
            tableroYPersonaje(juego, tablero, personaje);
            menuJuego.mostrarMenu2();
            cin >> eleccion;
            menuJuego.accionMenu2(eleccion, juego, personaje);
            if(!juego->getSalir()) {
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
    for(int i = 0; i < MAX_PERSONAJES; i++){
        if(juego->getJugador1()->getPersonajes()[i]->getVida() > 0){
            jugador1Muerto = false;
        }
        if(juego->getJugador2()->getPersonajes()[i]->getVida() > 0){
            jugador2Muerto = false;
        }
    }
    anunciarGanador(jugador1Muerto, jugador2Muerto);
    return jugador1Muerto || jugador2Muerto;
}

void Jugar::anunciarGanador(bool jugador1Muerto, bool jugador2Muerto){
    if(jugador1Muerto){
        cout << "¡GANA EL JUGADOR 2!" << endl;
    }else if(jugador2Muerto){
        cout << "¡GANA EL JUGADOR 1!" << endl;
    }
}
