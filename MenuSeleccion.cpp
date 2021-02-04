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

void MenuSeleccion::accionMenu(int eleccion, Juego* juego){
    system("CLS");

    switch (eleccion){
        case BUSCAR_POR_NOMBRE:
            buscar(juego->getPersonajes());
            mostrarMenu();
            break;

        case MOSTRAR_NOMBRES:
            juego->getPersonajes()->mostrarEnOrden();
            mostrarMenu();
            break;

        case SELECCIONAR_PERSONAJE:
            juego->seleccionPersonajes();
            mostrarMenu();
            break;

        case SALIR:
            juego->setSalir(true);
            break;

        default:
            cout << "Opcion inválida" << endl;
            mostrarMenu();
    }
}

void MenuSeleccion::buscar(ABB* personajes){
    string nombre = "";
    cout << "\tIngrese el nombre del personaje a buscar: ";
    cin >> nombre;
    personajes->buscar(nombre)->getDato()->mostrar();
}
