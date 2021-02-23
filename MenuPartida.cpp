#include "MenuPartida.h"

MenuPartida::MenuPartida() {}

void MenuPartida::mostrarMenu() {
    cout << "\t1- Cargar partida guardada." << endl;
    cout << "\t2- Borrar partida guardada y comenzar una nueva." << endl;
    cout << "\t3- Salir." << endl;
}

void MenuPartida::accionMenu(int eleccion, Juego *juego) {
    switch (eleccion) {
        case MP_CARGAR_PARTIDA:
            break;

        case MP_BORRAR_Y_CONTINUAR:
            juego->borrarPartidaGuardada();
            break;

        case MP_SALIR:
            juego->setSalir(true);
            break;

        default:
            cout << "Opcion inválida" << endl;
    }
}
