#ifndef BDE_MENUJUEGO_H
#define BDE_MENUJUEGO_H

#include <iostream>
#include "Juego.hpp"
#include "Personaje.h"

using namespace std;

class MenuJuego {
public:
    void mostrarMenu1();
    void accionMenu1(int eleccion, Juego* juego, Personaje* personaje);
    void mostrarMenu2();
    void accionMenu2(int eleccion, Juego* juego, Personaje* personaje);
};


#endif //BDE_MENUJUEGO_H
