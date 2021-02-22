#include "MenuInicio.h"
#include <iostream>

using namespace std;

void MenuInicio::mostrarMenu() {
    cout << "Elija alguna de las siguientes opciones (ingrese el número): " << endl;
    cout << "\t1) Agregar un nuevo personaje " << endl;
    cout << "\t2) Eliminar un personaje" << endl;
    cout << "\t3) Mostrar nombres de los personajes" << endl;
    cout << "\t4) Buscar por nombre los detalles de un personaje en particular" << endl;
    cout << "\t5) Comenzar juego" << endl;
    cout << "\t6) Salir" << endl;
}

void MenuInicio::agregarNuevo(ABB* personajes) {

    Utiles util;
    Tipo personaje;

    string elemento = ingresoElemento();
    string nombre = ingresoNombre();

    personaje = util.establecerTipo(elemento, nombre);

    personajes->insertar(personaje, personaje->getNombre());
    cout << "Se agrego a " << personaje->getNombre() << " a la lista" << endl;
}

void MenuInicio::eliminarPersonaje(ABB* personajes) {

    string nombre = ingresoNombre();
    personajes->eliminar(nombre);
}

void MenuInicio::mostrarNombres(ABB* personajes) {
    personajes->mostrarEnOrden();
}


void MenuInicio::buscarPorNombre(ABB* personajes) {

    string nombre = ingresoNombre();
    cout << personajes->cantidadPersonajes() << endl;
    personajes->buscar(nombre)->getDato()->mostrar();
}


string MenuInicio::ingresoNombre() {
    string nombre;

    cout << "Ingrese el nombre del personaje" << endl;
    cin >> nombre;

    return nombre;
}


string MenuInicio::ingresoElemento() {
    string elemento;

    cout << "Ingrese el elemento del personaje (agua, tierra, fuego o aire)" << endl;
    cin >> elemento;
    while(!elementoValido(elemento)) {
        cout << "El elemento ingresado no es válido, ingrese alguno de los posibles" << endl;
        cin >> elemento;
    }

    return elemento;
}


bool MenuInicio::elementoValido(string elemento) {
    return(elemento == ELEMENTO_AGUA || elemento == ELEMENTO_AIRE || elemento == ELEMENTO_TIERRA || elemento == ELEMENTO_AIRE);
}

void MenuInicio::accionMenu(int& eleccion, Juego* juego) {
    Utiles utiles;
    utiles.limpiarPantalla();
    switch(eleccion)
    {
        case MI_AGREGAR_PERSONAJE:
            utiles.enmarcar("AGREGAR UN PERSONAJE");
            agregarNuevo(juego->getPersonajes());
            utiles.pausa();
            break;
        case MI_ELIMINAR_PERSONAJE:
            utiles.enmarcar("ELIMINAR UN PERSONAJE");
            eliminarPersonaje(juego->getPersonajes());
            utiles.pausa();
            break;
        case MI_MOSTRAR_NOMBRES:
            utiles.enmarcar("MOSTRAR NOMBRES DE PERSONAJES");
            mostrarNombres(juego->getPersonajes());
            utiles.pausa();
            break;
        case MI_BUSCAR_POR_NOMBRE:
            utiles.enmarcar("BUSCAR PERSONAJE POR NOMBRE");
            buscarPorNombre(juego->getPersonajes());
            utiles.pausa();
            break;
        case MI_COMENZAR:
            if(juego->getPersonajes()->cantidadPersonajes() < MI_PERSONAJES_MINIMOS) {
                cout << "Se necesitan almenos 6 personajes para comenzar.\n" << endl;
                eleccion = 0;
            }
            break;
        case MI_SALIR:
            juego->setSalir(true);
            break;
        default:
            cout << "Ingreso inválido." << endl;
            break;
    }
}


void MenuInicio::espaciado() {
    cout << "\n" << endl;
}
