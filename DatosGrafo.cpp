#include "DatosGrafo.hpp"

Arista::Arista(Vertice* destino) {
    this->siguiente = NULL;
    this->destino = destino;
    this->costoAgua = destino->getCasillero()->getCostoAgua();
    this->costoAire = destino->getCasillero()->getCostoAire();
    this->costoFuego = destino->getCasillero()->getCostoFuego();
    this->costoTierra = destino->getCasillero()->getCostoTierra();
}

Arista* Arista::getSiguiente() {
    return this->siguiente;
}

Vertice* Arista::getDestino() {
    return this->destino;
}

int Arista::getCostoAire() {
    return this->costoAire;
}

int Arista::getCostoAgua() {
    return this->costoAgua;
}

int Arista::getCostoFuego() {
    return this->costoFuego;
}

int Arista::getCostoTierra() {
    return this->costoTierra;
}

void Arista::setSiguiente(Arista* siguiente) {
    this->siguiente = siguiente;
}

void Arista::setDestino(Vertice* destino) {
    this->destino = destino;
}

void Arista::setCostoAire(int costoAire) {
    this->costoAire = costoAire;
}

void Arista::setCostoAgua(int costoAgua) {
    this->costoAgua = costoAgua;
}

void Arista::setCostoFuego(int costoFuego) {
    this->costoFuego = costoFuego;
}

void Arista::setCostoTierra(int costoTierra) {
    this->costoTierra = costoTierra;
}

Arista::~Arista() {
    
}

Vertice::Vertice(Casillero* casillero) {
    this->siguiente = NULL;
    this->arista = NULL;
    this->casillero = casillero;
}

Vertice* Vertice::getSiguiente(){
    return this->siguiente;
}

Arista* Vertice::getArista() {
    return this->arista;
}

Casillero* Vertice::getCasillero() {
    return this->casillero;
}

void Vertice::setSiguiente(Vertice* siguiente) {
    this->siguiente = siguiente;
}

void Vertice::setArista(Arista* arista) {
    this->arista = arista;
}

void Vertice::setCasillero(Casillero* casillero) {
    this->casillero = casillero;
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
    if (this->arista == NULL) {
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
