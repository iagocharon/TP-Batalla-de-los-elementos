#ifndef TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_MENUJUEGO_H
#define TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_MENUJUEGO_H

#include <iostream>
#include "Juego.h"
#include "Jugador.h"

using namespace std;

class MenuSeleccion {

public:
    // Constructor vacío.
    MenuSeleccion();

    // PRE: -
    // POS: Muestra un menu de opciones por pantalla.
    void mostrarMenu();

    // PRE: Recibe un entero con valores entre 1 y 4 inclusive, y un puntero a juego inicializado.
    // POS: Llama a la función correspondiente según el entero recibido.
    void accionMenu(int eleccion, Juego* juego);

private:
    // PRE: Recibe un arbol cargado con personajes.
    // POS: Muestra por pantalla las estadisticas de un personaje.
    void buscar(ABB* personajes);
};

#endif //TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_MENUJUEGO_H
