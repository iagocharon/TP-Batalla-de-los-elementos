#include "Arista.hpp"

Arista::Arista(Vertice* destino) {
    this->siguiente = NULL;
    this->destino = destino;
    this->costoAgua = -1;
    this->costoAire = -1;
    this->costoFuego = -1;
    this->costoTierra = -1;
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
