#ifndef TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_MENUJUEGO_H
#define TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_MENUJUEGO_H

#include <iostream>
#include "Juego.hpp"
#include "Jugador.h"

using namespace std;

class MenuSeleccion {
public:
    MenuSeleccion();
    void mostrarMenu();
    void accionMenu(int eleccion, Juego* juego);

private:
    void buscar(ABB* personajes);
};

#endif //TP_BATALLA_DE_LOS_ELEMENTOS_MAIN_MENUJUEGO_H
