#ifndef BDE_JUGAR_H
#define BDE_JUGAR_H

#include "Juego.h"
#include "MenuSeleccion.h"
#include "MenuJuego.h"
#include "Personaje.h"
#include "Tablero.h"

using namespace std;

class Jugar {
public:
    // PRE: Recibe un puntero a un juego y un MenuSeleccion.
    // POS: Controla el flujo de seleccion de personajes para que cada jugador pueda
    //  seleccionar 3 para poder empezar a jugar.
    void seleccionarPersonajes(Juego* juego, MenuSeleccion menuSeleccion);

    // PRE: Recibe un puntero a juego completamente cargado, un MenuJuego, y un puntero a tablero
    // cargado.
    // POS: Llama a los menus de accion necesarios para el desarrollo del juego (acciones de cada personaje).
    //  Al terminar de recibir las acciones de todos los personajes de un jugador cambia el turno del juego.
    //  Tambien muestra el tablero y las estadisticas del personaje en juego.
    void jugar(Juego* juego, MenuJuego menuJuego, Tablero* tablero);

    // PRE: Recibe un juego completamente cargado.
    // POS: Verifica si el juego termino comprobando la salud de todos los personajes de cada jugador.
    //  En caso de que un jugador no tenga personajes devuelve true y anuncia al ganador, en otro caso false.
    bool finDelJuego(Juego* juego);
private:

    // PRE: Recibe un juego completamente cargado y un entero entre 0 y 2.
    // POS: Devuelve el personaje de la posicion que indique el entero del jugador que tenga el turno.
    Personaje* determinarPersonaje(Juego* juego, int personaje);

    //PRE: Recibe un juego y un personaje cargados.
    //POS: Muestra por pantalla el tablero y las estadisticas del personaje en juego.
    void tableroYPersonaje(Juego* juego, Tablero* tablero, Personaje* personaje);

    // PRE: Recibe 2 booleanos.
    // POS: En caso de que uno de los booleanos sea true, muestra por pantalla un mensaje para anunciar al
    //  ganador de la partida.
    void anunciarGanador(bool jugador1Muerto, bool jugador2Muerto);
};


#endif //BDE_JUGAR_H
