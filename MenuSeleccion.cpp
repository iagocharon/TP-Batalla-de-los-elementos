#include "MenuSeleccion.h"

MenuSeleccion::MenuSeleccion() {}


void MenuSeleccion::mostrarMenu() {
    cout << "\t1- Buscar por nombre los detalles de un personaje en particular." << endl;
    cout << "\t2- Mostrar todos los nombres de los personajes." << endl;
    cout << "\t3- Seleccionar personaje." << endl;
    cout << "\t4- Salir." << endl;
}

void MenuSeleccion::accionMenu(int eleccion, Juego *juego) {
    switch (eleccion) {
        case MS_BUSCAR_POR_NOMBRE:
            buscar(juego->getPersonajes());
            break;

        case MS_MOSTRAR_NOMBRES:
            juego->getPersonajes()->mostrarEnOrden();
            break;

        case MS_SELECCIONAR_PERSONAJE:
            juego->seleccionPersonajes();
            break;

        case MS_SALIR:
            juego->setSalir(true);
            break;

        default:
            cout << "Opcion inválida" << endl;
    }
}

void MenuSeleccion::buscar(ABB *personajes) {
    string nombre;
    cout << "\tIngrese el nombre del personaje a buscar: ";
    cin >> nombre;
    if (personajes->buscar(nombre) != nullptr) {
        personajes->buscar(nombre)->getDato()->mostrar();
    } else {
        cout << "El personaje ingresado no es alguno de los posibles" << endl;
    }
}


void MenuSeleccion::espaciado(){

    cout << "\n\n\n";
}
