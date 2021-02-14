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

const int OPCION_MIN = 1;
const int OPCION_MAX = 4;
#define PARTIDA "partida.csv"

using namespace std;

class Juego {
private:
    Jugador* jugador1;
    Jugador* jugador2;
    ABB* personajes;
    bool salida;
    int turno;

public:
    Juego();
    Juego(ABB* personajes);
    void jugar();

    void randomizarTurno();
    void cambiarTurno();
    void seleccionPersonajes();
    void setSalir(bool salir);
    bool salir();
    ABB* getPersonajes();
    Jugador* getJugador1();
    Jugador* getJugador2();
    int getTurno();
    void moverPersonaje(Personaje* personaje);
    void partidaGuardar();
    void partidaCargar();
    int determinarOpcion();
    void mostrarMenuInicial();
    bool opcionValida(int elegida);

private:
    void seleccionJugador1();
    void seleccionJugador2();
};

#endif /* Juego_hpp */
