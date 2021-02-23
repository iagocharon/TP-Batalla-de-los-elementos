#ifndef BDE_MENUPARTIDA_H
#define BDE_MENUPARTIDA_H

#include "Juego.h"

#define MP_CARGAR_PARTIDA 1
#define MP_BORRAR_Y_CONTINUAR 2
#define MP_SALIR 3

class MenuPartida {
public:
    // Constructor vacío
    MenuPartida();

    // PRE: -
    // POS: Muestra un menu de opciones por pantalla.
    void mostrarMenu();

    // PRE: Recibe un entero y un juego cargados.
    // POS: Llama a la función correspondiente según la eleccion realizada.
    void accionMenu(int eleccion, Juego *juego);
};


#endif //BDE_MENUPARTIDA_H
