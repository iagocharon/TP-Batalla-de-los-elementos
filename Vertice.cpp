#include "Vertice.hpp"

Vertice::Vertice(string nombre) {
    this->siguiente = NULL;
    this->arista = NULL;
    this->nombre = nombre;
}

Vertice* Vertice::getSiguiente(){
    return this->siguiente;
}

Arista* Vertice::getArista() {
    return this->arista;
}

string Vertice::getNombre() {
    return this->nombre;
}

void Vertice::setSiguiente(Vertice* siguiente) {
    this->siguiente = siguiente;
}

void Vertice::setArista(Arista* arista) {
    this->arista = arista;
}

void Vertice::setNombre(string nombre) {
    this->nombre = nombre;
}

void Vertice::eliminarArista(Arista* aEliminar) {
    if (this->arista == aEliminar) {
        this->arista = aEliminar->getSiguiente();
        delete aEliminar;
    }
    else {
        Arista* previa = this->arista;
        Arista* eliminamos = previa->getSiguiente();
        while (eliminamos != NULL) {
            if (eliminamos == aEliminar) {
                previa->setSiguiente(eliminamos->getSiguiente());
                delete eliminamos;
                return;
            }
            previa = eliminamos;
            eliminamos = eliminamos->getSiguiente();
        }
    }
}

void Vertice::agregarArista(Arista* nueva) {
    Arista* auxiliar = this->arista;
    if (arista == NULL) {
        this->arista = nueva;
        return;
    }
    while (auxiliar->getSiguiente() != NULL) {
        auxiliar = auxiliar->getSiguiente();
    }
    auxiliar->setSiguiente(nueva);
}

Vertice::~Vertice() {
    
}
