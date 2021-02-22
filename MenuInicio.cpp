#include "MenuInicio.h"
#include <iostream>

const int PRIMERA_OPCION = 1;
const int ULTIMA_OPCION = 6;

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

void MenuInicio::agregarNuevo(ABB* personajes){

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
    cout << personajes->cantidadElementos() << endl;
    if (personajes->buscar(nombre) != NULL) {
        personajes->buscar(nombre)->getDato()->mostrar();
    }
    else {
        cout << "No se encontro el personaje." << endl;
    }
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
    return(elemento == "agua" || elemento == "tierra" || elemento == "fuego" || elemento == "aire");
}

void MenuInicio::accionMenu(int& eleccion, Juego* juego) {
    switch(eleccion)
    {
        case MI_AGREGAR_PERSONAJE:
            agregarNuevo(juego->getPersonajes());
            break;
        case MI_ELIMINAR_PERSONAJE:
            eliminarPersonaje(juego->getPersonajes());
            break;
        case MI_MOSTRAR_NOMBRES:
            mostrarNombres(juego->getPersonajes());
            break;
        case MI_BUSCAR_POR_NOMBRE:
            buscarPorNombre(juego->getPersonajes());
            break;
        case MI_COMENZAR:
            if(juego->getPersonajes()->cantidadElementos() < MI_PERSONAJES_MINIMOS){
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
