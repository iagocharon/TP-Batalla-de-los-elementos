#include "Ejecucion.h"
#include "Juego.h"
#include "Jugar.h"
#include "Tablero.h"
#include <iostream>

using namespace std;

int main() {
    srand(unsigned(time(NULL)));
    int opcion;

    cout << "Ingrese: " << endl;
    cout << "1) Si va a correr el programa en una IDE con makefile" << endl;
    cout << "2) Si se va a correr en una terminal" << endl;
    cin >> opcion;

    while (opcion != IDE && opcion != TERMINAL) {
        cout << "La opción no es válida, ingrese alguna según las opciones dadas" << endl;
        cin >> opcion;
    }
    ABB* arbolPersonajes = personajes(opcion);
    ejecucion(arbolPersonajes);

    //FLUJO DE JUEGO

    auto* juego = new Juego(arbolPersonajes);
    auto* menuJuego = new MenuJuego();
    auto* menuSeleccion = new MenuSeleccion();
    auto* jugar = new Jugar();

    if(juego->partidaCargar() == PARTIDA_NO_ENCONTRADA){
        jugar->seleccionarPersonajes(juego, *menuSeleccion);
    }

    auto* tablero = new Tablero();

    if(juego->getSalir()){
        juego->randomizarTurno();

        while(!jugar->finDelJuego(juego) && !juego->getSalir()){
            jugar->jugar(juego, *menuJuego, tablero);
        }
    }

    return 0;
}
