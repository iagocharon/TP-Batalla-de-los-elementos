#include "Juego.h"
#include "Jugar.h"
#include "Tablero.h"
#include <iostream>
#include "Utiles.h"

using namespace std;

int main() {
    srand(unsigned(time(NULL)));
    Utiles utiles;
    ABB* arbolPersonajes = utiles.personajes();
    auto* juego = new Juego(arbolPersonajes);
    auto* jugar = new Jugar();
    auto* tablero = new Tablero();
    auto* grafo = new Grafo();
    tablero->cargarGrafo(grafo);

    jugar->inicio(juego);

    if(!juego->getSalir()){
        if(juego->partidaCargar() == PARTIDA_NO_ENCONTRADA){
            jugar->seleccionarPersonajes(juego);
            if(!juego->getSalir())
                jugar->posicionarPersonajes(juego, tablero);
        }


        if(!juego->getSalir()){
            juego->randomizarTurno();

            while(!jugar->finDelJuego(juego) && !juego->getSalir()){
                jugar->jugar(juego, tablero, grafo);
            }
        }
    }

    delete tablero;
    delete juego;
    return 0;
}
