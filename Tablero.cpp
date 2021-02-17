#include "Tablero.h"

Tablero::Tablero() {
    string letra;
    ifstream archivo(NOMBRE_TABLERO);
    if (!archivo.is_open()) {
        cout << "Error al cargar el tablero\n" << endl;
        return;
    }

    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {

            if(j < MAX_COLUMNAS-1)
                getline(archivo, letra, ',');
            else
                getline(archivo, letra, '\n');

            if (letra == MONTANIA) {
                this->tablero[i][j] = new CasilleroMontania();
            }
            else if (letra == PRECIPICIO) {
                this->tablero[i][j] = new CasilleroPrecipicio();
            }
            else if (letra == LAGO) {
                this->tablero[i][j] = new CasilleroLago();
            }
            else if (letra == VOLCAN) {
                this->tablero[i][j] = new CasilleroVolcan();
            }
            else if (letra == CAMINO) {
                this->tablero[i][j] = new CasilleroCamino();
            }
            else{
                this->tablero[i][j] = new CasilleroVacio();
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
                this->mostrarPersonajeJugador1(j, i, personaje);
            }
            else {
                this->mostrarPersonajeJugador2(j, i, personaje);
            }
        }
        cout << "\n";
    }
}

void Tablero::mostrarPersonajeJugador1(int columna, int fila, char elemento){
    if (tablero[fila][columna]->getNombre() == "Montania") {
        printf("\033[1;43;97m %c \033[0m", elemento);
    }
    else if (tablero[fila][columna]->getNombre() == "Precipicio") {
        printf("\033[1;100;97m %c \033[0m", elemento);
    }
    else if (tablero[fila][columna]->getNombre() == "Lago") {
        printf("\033[1;46;97m %c \033[0m", elemento);
    }
    else if (tablero[fila][columna]->getNombre() == "Volcan") {
        printf("\033[1;41;97m %c \033[0m", elemento);
    }
    else if (tablero[fila][columna]->getNombre() == "Camino") {
        printf("\033[1;42;97m %c \033[0m", elemento);
    }
    else{
        printf("\033[1;45;97m %c \033[0m", elemento);
    }
}

void Tablero::mostrarPersonajeJugador2(int columna, int fila, char elemento){
    if (tablero[columna][fila]->getNombre() == "Montania") {
        printf("\033[1;43;30m %c \033[0m", elemento);
    }
    else if (tablero[columna][fila]->getNombre() == "Precipicio") {
        printf("\033[1;100;30m %c \033[0m", elemento);
    }
    else if (tablero[columna][fila]->getNombre() == "Lago") {
        printf("\033[1;46;30m %c \033[0m", elemento);
    }
    else if (tablero[columna][fila]->getNombre() == "Volcan") {
        printf("\033[1;41;30m %c \033[0m", elemento);
    }
    else if (tablero[columna][fila]->getNombre() == "Camino") {
        printf("\033[1;42;30m %c \033[0m", elemento);
    }
    else{
        printf("\033[1;45;30m %c \033[0m", elemento);
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

void Tablero::cargarGrafo(Grafo* grafo) {
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            grafo->agregarVertice(this->tablero[i][j]);
        }
    }
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            if (i < (MAX_FILAS - 1)) {
                grafo->agregarArista(grafo->getVertice(tablero[i][j]), grafo->getVertice(tablero[i+1][j]), grafo->getVertice(tablero[i+1][j])->getCasillero()->getCostoAgua(), grafo->getVertice(tablero[i+1][j])->getCasillero()->getCostoAire(), grafo->getVertice(tablero[i+1][j])->getCasillero()->getCostoFuego(), grafo->getVertice(tablero[i+1][j])->getCasillero()->getCostoTierra());
            }
            if (i > 0) {
                grafo->agregarArista(grafo->getVertice(tablero[i][j]), grafo->getVertice(tablero[i-1][j]), grafo->getVertice(tablero[i-1][j])->getCasillero()->getCostoAgua(), grafo->getVertice(tablero[i-1][j])->getCasillero()->getCostoAire(), grafo->getVertice(tablero[i-1][j])->getCasillero()->getCostoFuego(), grafo->getVertice(tablero[i-1][j])->getCasillero()->getCostoTierra());
            }
            if (j < (MAX_COLUMNAS - 1)) {
                grafo->agregarArista(grafo->getVertice(tablero[i][j]), grafo->getVertice(tablero[i][j+1]), grafo->getVertice(tablero[i][j+1])->getCasillero()->getCostoAgua(), grafo->getVertice(tablero[i][j+1])->getCasillero()->getCostoAire(), grafo->getVertice(tablero[i][j+1])->getCasillero()->getCostoFuego(), grafo->getVertice(tablero[i][j+1])->getCasillero()->getCostoTierra());

            }
            if (j > 0) {
                grafo->agregarArista(grafo->getVertice(tablero[i][j]), grafo->getVertice(tablero[i][j-1]), grafo->getVertice(tablero[i][j-1])->getCasillero()->getCostoAgua(), grafo->getVertice(tablero[i][j-1])->getCasillero()->getCostoAire(), grafo->getVertice(tablero[i][j-1])->getCasillero()->getCostoFuego(), grafo->getVertice(tablero[i][j-1])->getCasillero()->getCostoTierra());

            }
        }
    }
}
