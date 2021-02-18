#include "Casillero.h"

string Casillero::getNombre() {
    return this->nombre;
}

int Casillero::getCostoTierra() {
    return this->costoTierra;
}
int Casillero::getCostoAire() {
    return this->costoAire;
}

int Casillero::getCostoAgua() {
    return this->costoAgua;
}

int Casillero::getCostoFuego() {
    return this->costoFuego;
}

int Casillero::getFila() {
    return this->fila;
}

int Casillero::getColumna() {
    return this->columna;
}

void Casillero::setNombre(string nombre) {
    this->nombre = nombre;
}

void Casillero::setCostoTierra(int costo) {
    this->costoTierra = costo;
}

void Casillero::setCostoAire(int costo) {
    this->costoAire = costo;
}

void Casillero::setCostoAgua(int costo) {
    this->costoAgua = costo;
}

void Casillero::setCostoFuego(int costo) {
    this->costoFuego = costo;
}

void Casillero::setFila(int fila) {
    this->fila = fila;
}

void Casillero::setColumna(int columna) {
    this->columna = columna;
}

CasilleroMontania::CasilleroMontania() : Casillero() {
    this->setNombre("Montania");
    this->setCostoTierra(0);
    this->setCostoAire(2);
    this->setCostoAgua(1);
    this->setCostoFuego(1);
}

CasilleroPrecipicio::CasilleroPrecipicio() : Casillero() {
    this->setNombre("Precipicio");
    this->setCostoTierra(2);
    this->setCostoAire(1);
    this->setCostoAgua(1);
    this->setCostoFuego(1);
}

CasilleroLago::CasilleroLago() : Casillero() {
    this->setNombre("Lago");
    this->setCostoTierra(1);
    this->setCostoAire(1);
    this->setCostoAgua(0);
    this->setCostoFuego(2);
}

CasilleroVolcan::CasilleroVolcan() : Casillero() {
    this->setNombre("Volcan");
    this->setCostoTierra(1);
    this->setCostoAire(1);
    this->setCostoAgua(2);
    this->setCostoFuego(0);
}

CasilleroCamino::CasilleroCamino() : Casillero() {
    this->setNombre("Camino");
    this->setCostoTierra(1);
    this->setCostoAire(1);
    this->setCostoAgua(1);
    this->setCostoFuego(1);
}

CasilleroVacio::CasilleroVacio() : Casillero() {
    this->setNombre("Vacio");
    this->setCostoTierra(15);
    this->setCostoAire(15);
    this->setCostoAgua(15);
    this->setCostoFuego(15);
}

