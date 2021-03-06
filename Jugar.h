#ifndef BDE_JUGAR_H
#define BDE_JUGAR_H

#include "Juego.h"
#include "MenuInicio.h"
#include "MenuSeleccion.h"
#include "MenuJuego.h"
#include "MenuPartida.h"
#include "Personaje.h"
#include "Tablero.h"

#define VIDA_MUERTO 0

using namespace std;

class Jugar {
public:
    // PRE: -
    // POS: Inicializa lo necesario para el juego y maneja el flujo de la partida.
    void flujoDeJuego();

private:
    // PRE: Recibe un puntero a juego cargado.
    // POS: Controla el flujo del primer menu para agregar o eliminar personajes.
    void inicio(Juego* juego);

    // PRE: Recibe un puntero a juego cargado.
    // POS: Controla el flujo del menu para cargar partida o iniciar una nueva.
    int menuPartida(Juego* juego);

    // PRE: Recibe un puntero a un juego y un MenuSeleccion.
    // POS: Controla el flujo de seleccion de personajes para que cada jugador pueda
    //      seleccionar 3 para poder empezar a jugar.
    void menuPersonajes(Juego* juego);

    // PRE: Recibe un juego y un tablero completamente cargados.
    // POS: Llama a la funcion correspondiente para posicionar a los personajes de cada jugador y muestra el tablero.
    void posicionarPersonajes(Juego* juego, Tablero* tablero);

    // PRE: Recibe un puntero a juego completamente cargado, un MenuJuego, y un puntero a tablero
    //      cargado.
    // POS: Llama a los menus de accion necesarios para el desarrollo del juego (acciones de cada personaje).
    //      Muestra el tablero y las estadisticas del personaje en juego, y actualiza las muertes.
    void jugar(Juego* juego, Tablero* tablero, Grafo* grafo);

    // PRE: Recibe un juego completamente cargado.
    // POS: Verifica si el juego termino comprobando la salud de todos los personajes de cada jugador.
    //      En caso de que un jugador no tenga personajes devuelve true y anuncia al ganador, en otro caso false.
    bool finDelJuego(Juego* juego);

    // PRE: Recibe un entero inicializado.
    // POS: Devuelve true si la eleccion es valida o false en caso contrario.
    void primerMenuJuego(Juego* juego, Tablero* tablero, Personaje* personaje, Grafo* grafo);

    // PRE: Recibe un entero inicializado.
    // POS: Devuelve true si la eleccion es valida o false en caso contrario.
    void segundoMenuJuego(Juego* juego, Tablero* tablero, Personaje* personaje);

    // PRE: Recibe un puntero a juego cargado.
    // POS: Llama a la función matar personajes para cada jugador.
    void actualizarMuertes(Juego* juego);

    // PRE: Recibe un puntero juego cargado.
    // POS: Muestra por pantalla que jugador tiene el turno.
    void anunciarTurnoJugador(Juego* juego);

    // PRE: Recibe un juego completamente cargado y un entero entre 0 y 2.
    // POS: Devuelve el personaje de la posicion que indique el entero del jugador que tenga el turno.
    Personaje* determinarPersonaje(Juego* juego, int personaje);

    // PRE: Recibe un puntero a juego cargado.
    // POS: Llama a la funcion comprobarFuegoYAires del jugador correspondiente.
    void comprobarFuegoYAire(Juego* juego);

    //PRE: Recibe un juego y un personaje cargados.
    //POS: Muestra por pantalla el tablero y las estadisticas del personaje en juego.
    void tableroYPersonaje(Juego* juego, Tablero* tablero, Personaje* personaje);

    // PRE: Recibe un juego cargado.
    // POS: Muestra por pantalla al ganador de la partida.
    void anunciarGanador(Juego* juego);
};


#endif //BDE_JUGAR_H
