#ifndef BDE_MENUJUEGO_H
#define BDE_MENUJUEGO_H

#include <iostream>
#include "Juego.h"
#include "Personaje.h"
#include "Tablero.h"
#include "Utiles.h"

#define MJ_ALIMENTAR 1
#define MJ_MOVER 2
#define MJ_PASAR 3
#define MJ_SALIR 4
#define MJ_ATACAR 1
#define MJ_DEFENDER 2

using namespace std;

class MenuJuego {
public:
    // Constructor vacío.
    MenuJuego();

    // PRE: -
    // POS: Muestra un menu de opciones por pantalla.
    void mostrarMenu1();

    // PRE: Recibe un entero entre 1 y 4 inclusive, un juego cargado, y un personaje cargado.
    // POS: Llama a la función correspondiente según el entero recibido.
    void accionMenu1(int eleccion, Juego* juego, Personaje* personaje, Grafo* grafo, Tablero* tablero);

    // PRE: -
    // POS: Muestra un menu de opciones por pantalla.
    void mostrarMenu2();

    // PRE: Recibe un entero entre 1 y 4 inclusive, un juego cargado, y un personaje cargado.
    // POS: Llama a la función correspondiente según el entero recibido.
    void accionMenu2(int eleccion, Juego* juego, Personaje* personaje, Grafo* grafo, Tablero* tablero);
};


#endif //BDE_MENUJUEGO_H
