#include "Menu.h"
#include <iostream>

const int PRIMERA_OPCION = 1;
const int ULTIMA_OPCION = 6;

using namespace std;

void Menu::bienvenida() {
    cout << "Bienvenido al programa, que le sea leve \u263A" << endl;
}

void Menu::mostrarMenuInicial() {
    cout << "Elija alguna de las siguientes opciones (ingrese el número): " << endl;
    cout << "\t1) Agregar un nuevo personaje " << endl;
    cout << "\t2) Eliminar un personaje" << endl;
    cout << "\t3) Mostrar nombres de los personajes" << endl;
    cout << "\t4) Buscar por nombre los detalles de un personaje en particular" << endl;
    cout << "\t5) Comenzar juego" << endl;
    cout << "\t6) Salir" << endl;
}

int Menu::opcion() {
    int elegida = 0;
    mostrarMenuInicial();
    cout << "Ingrese su valor aqui: " << endl;
    cin >> elegida;
    while(!opcionValida(elegida)) {
        cout << "La opción " << elegida << " no es válida, ingrese alguna de las posibles por favor" << endl;
        mostrarMenuInicial();
        cin >> elegida;
    }
    return elegida;
}

bool Menu::opcionValida(int opcion) {
    return(opcion >= PRIMERA_OPCION && opcion <= ULTIMA_OPCION);
}

void Menu::despedida() {
    cout << "Gracias por utilizar el programa, ojala no haya causado inconvenientes." << endl;
}

void Menu::espaciado() {
    cout << "\n\n\n" << endl;
}
