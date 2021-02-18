#include "NodoColaPrioridad.h"

NodoColaPrioridad::NodoColaPrioridad(Vertice* vertice, int prioridad, int pesoAgua, int pesoAire, int pesoFuego, int pesoTierra) {
    this->vertice = vertice;
    this->prioridad = prioridad;
    this->pesoAgua = pesoAgua;
    this->pesoAire = pesoAire;
    this->pesoFuego = pesoFuego;
    this->pesoTierra = pesoTierra;
    this->siguiente = NULL;
}

Vertice* NodoColaPrioridad::getVertice() {
    return this->vertice;
}

int NodoColaPrioridad::getPrioridad() {
    return this->prioridad;
}

int NodoColaPrioridad::getPesoAgua() {
    return this->pesoAgua;
}

int NodoColaPrioridad::getPesoAire() {
    return this->pesoAire;
}
int NodoColaPrioridad::getPesoFuego() {
    return this->pesoFuego;
}

int NodoColaPrioridad::getPesoTierra() {
    return this->pesoTierra;
}

NodoColaPrioridad* NodoColaPrioridad::getSiguiente() {
    return this->siguiente;
}

void NodoColaPrioridad::setVertice(Vertice* vertice) {
    this->vertice = vertice;
}

void NodoColaPrioridad::setPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

void NodoColaPrioridad::setPesoAgua(int pesoAgua) {
    this->pesoAgua = pesoAgua;
}

void NodoColaPrioridad::setPesoAire(int pesoAire) {
    this->pesoAire = pesoAire;
}

void NodoColaPrioridad::setPesoFuego(int pesoFuego) {
    this->pesoFuego = pesoFuego;
}

void NodoColaPrioridad::setPesoTierra(int pesoTierra) {
    this->pesoTierra = pesoTierra;
}

void NodoColaPrioridad::setSiguiente(NodoColaPrioridad* siguiente) {
    this->siguiente = siguiente;
}

NodoColaPrioridad::~NodoColaPrioridad() {
    
}
