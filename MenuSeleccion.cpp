#include "MenuSeleccion.h"

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
        case 1:
            buscar(juego->getPersonajes());
            mostrarMenu();
            break;
        case 2:
            juego->getPersonajes()->mostrarEnOrden();
            mostrarMenu();
            break;
        case 3:
            juego->seleccionPersonajes();
            mostrarMenu();
            break;
        case 4:
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
