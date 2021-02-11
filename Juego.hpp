#ifndef Juego_hpp
#define Juego_hpp

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "ColaPrioridad.hpp"
#include <fstream>
#include <string>
#include "Personaje.h"
#include "ABB.hpp"
#include "Casillero.hpp"
#include "Jugador.h"
#include "Personaje.h"
#include "ElementalAire.h"
#include "ElementalAgua.h"
#include "ElementalFuego.h"
#include "ElementalTierra.h"

#define PARTIDA "partida.csv"

using namespace std;

class Juego {
private:
    Jugador* jugador1;
    Jugador* jugador2;
    ABB* personajes;
    bool salir;
    int turno;

public:
    Juego();
    Juego(ABB* personajes);

    void seleccionPersonajes();
    void setSalir(bool salir);
    ABB* getPersonajes();
    Jugador* getJugador1();
    Jugador* getJugador2();
    int getTurno();
    void moverPersonaje(Personaje* personaje);
    void partidaGuardar();
    void partidaCargar();

private:
    void seleccionJugador1(string nombre);
    void seleccionJugador2(string nombre);
};

#endif /* Juego_hpp */
