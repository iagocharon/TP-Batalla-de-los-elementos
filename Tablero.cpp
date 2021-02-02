#include "Tablero.h"

void Tablero::cargarTablero() {
    ifstream archivo(NOMBRE_TABLERO);
    if (!archivo.is_open()) {
        cout << "Error al cargar el tablero\n" << endl;
        return;
    }

    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            string letra;
            getline(archivo, letra, ',');
            if (letra == MONTANIA) {
                tablero[i][j] = new CasilleroMontania();
            }
            else if (letra == PRECIPICIO) {
                tablero[i][j] = new CasilleroPrecipicio();
            }
            else if (letra == LAGO) {
                tablero[i][j] = new CasilleroLago();
            }
            else if (letra == VOLCAN) {
                tablero[i][j] = new CasilleroVolcan();
            }
            else if (letra == CAMINO) {
                tablero[i][j] = new CasilleroCamino();
            }
            else{
                tablero[i][j] = new CasilleroVacio();
            }
        }
    }
    archivo.close();
}

void Tablero::mostrarTablero(Juego* juego){
    char personaje = ' ';
    int jugador = 0;

    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            personaje = personajeJugado(j, i, juego, jugador);
            if (jugador == 1) {
                mostrarPersonajeJugador1(j, i, personaje);
            } else {
                mostrarPersonajeJugador2(j, i, personaje);
            }
        }
        cout << "\n";
    }
}

void Tablero::mostrarPersonajeJugador1(int columna, int fila, char elemento){
    if (tablero[columna][fila]->getNombre() == "Montania") {
        printf("\033[1;43;107m %c \033[0m");
    }
    else if (tablero[columna][fila]->getNombre() == "Precipicio") {
        printf("\033[1;100;107m %c \033[0m");
    }
    else if (tablero[columna][fila]->getNombre() == "Lago") {
        printf("\033[1;46;107m %c \033[0m");
    }
    else if (tablero[columna][fila]->getNombre() == "Volcan") {
        printf("\033[1;41;107m %c \033[0m");
    }
    else if (tablero[columna][fila]->getNombre() == "Camino") {
        printf("\033[1;42;107m %c \033[0m");
    }
    else{
        printf("\033[1;45;107m %c \033[0m");
    }
}

void Tablero::mostrarPersonajeJugador2(int columna, int fila, char elemento){
    if (tablero[columna][fila]->getNombre() == "Montania") {
        printf("\033[1;43;30m %c \033[0m");
    }
    else if (tablero[columna][fila]->getNombre() == "Precipicio") {
        printf("\033[1;100;30m %c \033[0m");
    }
    else if (tablero[columna][fila]->getNombre() == "Lago") {
        printf("\033[1;46;30m %c \033[0m");
    }
    else if (tablero[columna][fila]->getNombre() == "Volcan") {
        printf("\033[1;41;30m %c \033[0m");
    }
    else if (tablero[columna][fila]->getNombre() == "Camino") {
        printf("\033[1;42;30m %c \033[0m");
    }
    else{
        printf("\033[1;45;30m %c \033[0m");
    }
}


char Tablero::personajeJugado(int columna, int fila, Juego* juego, int& jugador){
    for(int i = 0; i < MAX_PERSONAJES; i++){
        if(juego->getJugador1()->getPersonajes()[i]->getColumna() == columna &&
        juego->getJugador1()->getPersonajes()[i]->getFila() == fila) {
            jugador = 1;
            return elementoPersonaje(juego->getJugador1()->getPersonajes()[i]);
        }
        if(juego->getJugador2()->getPersonajes()[i]->getColumna() == columna &&
        juego->getJugador2()->getPersonajes()[i]->getFila() == fila){
            jugador = 2;
            return elementoPersonaje(juego->getJugador2()->getPersonajes()[i]);
        }
    }
    jugador = 0;
    return ' ';
}

char Tablero::elementoPersonaje(Personaje* personaje){
    if(personaje->getElemento() == ELEMENTO_AIRE){
        return 'A';
    }
    else if(personaje->getElemento() == ELEMENTO_TIERRA){
        return 'T';
    }
    else if(personaje->getElemento() == ELEMENTO_AGUA){
        return 'W';
    }
    return 'F';
}
