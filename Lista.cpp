//
// Created by daniel on 23/11/20.
//

const int PRIMERO = 1;

#include "Lista.h"

Lista::Lista() {
    elementos = 0;
    primero = nullptr;
    actual = primero;
}

void Lista::avanzar(){

    actual = actual -> obtenerSiguiente();
}


string Lista::nombreActual(){

    return actual -> obtenerDato() -> obtenerNombre();
}

void Lista::alta(Tipo dato) {

    Nodo* nuevo = new Nodo(dato);

    if(primero != nullptr){

        nuevo->asignarSiguiente(primero);
    }

    primero = nuevo;
    elementos++;
}


void Lista::baja(int posicion) {

    Nodo* borrar = primero;

    if(vacia()) {
        std::cout << "No se puede buscar un elemento en una lista vacía" << std::endl;

    } else if (posicion > elementos){
        std::cout << "La posición en que se busca el elemento no es válida" << std::endl;

    } else if(posicion == PRIMERO){
        primero = primero -> obtenerSiguiente();

    } else {
            Nodo* anterior = obtenerNodo(posicion - 1);
            borrar = anterior -> obtenerSiguiente();
            anterior -> asignarSiguiente(borrar -> obtenerSiguiente());
    }

    elementos--;
    delete borrar;
}

int Lista::buscarNombre(std::string nombre){

    int i = 0;
    bool nombreHallado = false;

    reiniciar();

    while(!nombreHallado && (actual != nullptr)){

        if(nombre == actual -> obtenerDato() -> obtenerNombre())
            nombreHallado = true;

        avanzar();

        i++;
    }
    if(nombreHallado)
        return i;
    return -1;
}


void Lista::reiniciar(){

    actual = primero;
}


bool Lista::vacia(){

    return (primero == nullptr);
}


int Lista::obtenerLongitud() {

    return elementos;
}


Nodo* Lista::obtenerNodo(int posicion) {

    Nodo* aux = primero;

    for(int i = 1; i < posicion; i++){
        aux = aux -> obtenerSiguiente();
    }

    return aux;
}


Lista::~Lista(){

    while(!vacia()){
        baja(1);
    }
}
