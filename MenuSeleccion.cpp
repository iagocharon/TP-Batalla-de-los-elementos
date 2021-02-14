#include "MenuSeleccion.h"

const int BUSCAR_POR_NOMBRE = 1;
const int MOSTRAR_NOMBRES = 2;
const int SELECCIONAR_PERSONAJE = 3;
const int SALIR = 4;

MenuSeleccion::MenuSeleccion(){}


void MenuSeleccion::mostrarMenu() {
    cout << "\t1- Buscar por nombre los detalles de un personaje en particular." << endl;
    cout << "\t2- Mostrar todos los nombres de los personajes." << endl;
    cout << "\t3- Seleccionar personaje." << endl;
    cout << "\t4- Salir." << endl;
}

int MenuSeleccion::determinarOpcion(){

    int elegida = 0;

    mostrarMenu();
    cin >> elegida;

    if(!opcionValida(elegida)){
        cout << "La opción ingresada no es válida, por favor ingrese un número válido." << endl;
        mostrarMenu();
        cin >> elegida;
    }

    return elegida;
}

bool MenuSeleccion::opcionValida(int elegida){

    return (elegida >= OPCION_MIN && elegida <= OPCION_MAX);
}