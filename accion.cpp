//
// Created by daniel on 6/12/20.
//

#include "Accion.h"


Accion::Accion(int opcion, Lista* lista){

    elegida = opcion;
    this -> lista = lista;
}


void Accion::determinarAccion(){

    if(elegida == AGREGAR_PERSONAJE)
        agregarNuevo();

    else if(elegida == ELIMINAR_PERSONAJE && !(lista -> vacia()))
        eliminarPersonaje();

    else if(elegida == MOSTRAR_NOMBRES && !(lista -> vacia()))
        mostrarNombres();

    else if(elegida == BUSCAR_POR_NOMBRE && !(lista -> vacia()))
        buscarPorNombre();

    else if(elegida == ALIMENTAR_PERSONAJE && !(lista -> vacia()))
        alimentarPersonaje();

    else if(elegida == SALIR);

    else
        cout << "La opción elegida no es válida para el estado de la lista" << endl;
}


void Accion::agregarNuevo(){

    Utiles util;
    Tipo personaje;

    string elemento = ingresoElemento();
    string nombre = ingresoNombre();

    personaje = util.establecerTipo(elemento, nombre);

    lista -> alta(personaje);
    cout << "Se agrego a " << personaje -> obtenerNombre() << " a la lista" << endl;

}


void Accion::eliminarPersonaje(){

    int posicionNombre = 0;

    string nombre = ingresoNombre();

    posicionNombre = lista -> buscarNombre(nombre);

    if(posicionNombre == NO_ENCONTRADO)
        cout << "El nombre buscado no se encuentra en la lista" << endl;

    else{
        cout << "Se eliminará a " << nombre << " de la lista" << endl;
        lista -> baja(posicionNombre);
    }
}


void Accion::mostrarNombres(){

    string nombreActual;
    lista -> reiniciar();

    for(int i = 1; i <= lista -> obtenerLongitud(); i++){

        nombreActual = lista -> nombreActual();

        cout << i << ") " << nombreActual << endl;

        lista -> avanzar();
    }
}


void Accion::buscarPorNombre(){

    int posicionNombre = 0;

    string nombre = ingresoNombre();

    posicionNombre = lista -> buscarNombre(nombre);

    if(posicionNombre == NO_ENCONTRADO)
        cout << "No hay un personaje con ese nombre" << endl;

    else {
        cout << "Nombre: " << lista->obtenerNodo(posicionNombre)->obtenerDato()->obtenerNombre() << endl;
        cout << "Escudo: " << lista->obtenerNodo(posicionNombre)->obtenerDato()->obtenerEscudo() << endl;
        cout << "Vida: " << lista->obtenerNodo(posicionNombre)->obtenerDato()->obtenerVida() << endl;
        cout << "Energia: " << lista->obtenerNodo(posicionNombre)->obtenerDato()->obtenerEnergia() << endl;
    }
}


void Accion::alimentarPersonaje(){

    int posicionNombre = 0;

    string nombre = ingresoNombre();

    posicionNombre = lista -> buscarNombre(nombre);

    if(posicionNombre == NO_ENCONTRADO)
        cout << "No hay un personaje con ese nombre" << endl;

    else
        lista -> obtenerNodo(posicionNombre) -> obtenerDato() -> alimentar();

}



string Accion::ingresoNombre(){

    string nombre;

    cout << "Ingrese el nombre del personaje" << endl;
    cin >> nombre;

    return nombre;
}


string Accion::ingresoElemento(){

    string elemento;

    cout << "Ingrese el elemento del personaje (agua, tierra, fuego o aire)" << endl;
    cin >> elemento;
    while(!elementoValido(elemento)){
        cout << "El elemento ingresado no es válido, ingrese alguno de los posibles" << endl;
        cin >> elemento;
    }

    return elemento;
}


bool Accion::elementoValido(string elemento){

    return(elemento == "agua" || elemento == "tierra" || elemento == "fuego" || elemento == "aire");
}