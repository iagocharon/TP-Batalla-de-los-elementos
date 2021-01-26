#include "Casillero.hpp"

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

void Casillero::setCostoTierra(int costo){
    this->costoTierra = costo;
}

void Casillero::setCostoAire(int costo){
    this->costoAire = costo;
}

void Casillero::setCostoAgua(int costo){
    this->costoAgua = costo;
}

void Casillero::setCostoFuego(int costo){
    this->costoFuego = costo;
}


CasilleroMontania::CasilleroMontania() : Casillero() {
    this->setCostoTierra(0);
    this->setCostoAire(2);
    this->setCostoAgua(1);
    this->setCostoFuego(1);
}

CasilleroPrecipicio::CasilleroPrecipicio() : Casillero() {
    this->setCostoTierra(2);
    this->setCostoAire(1);
    this->setCostoAgua(1);
    this->setCostoFuego(1);
}

CasilleroLago::CasilleroLago() : Casillero() {
    this->setCostoTierra(1);
    this->setCostoAire(1);
    this->setCostoAgua(0);
    this->setCostoFuego(2);
}

CasilleroVolcan::CasilleroVolcan() : Casillero() {
    this->setCostoTierra(1);
    this->setCostoAire(1);
    this->setCostoAgua(2);
    this->setCostoFuego(0);
}

CasilleroCamino::CasilleroCamino() : Casillero() {
    this->setCostoTierra(1);
    this->setCostoAire(1);
    this->setCostoAgua(1);
    this->setCostoFuego(1);
}

CasilleroVacio::CasilleroVacio() : Casillero() {
    this->setCostoTierra(15);
    this->setCostoAire(15);
    this->setCostoAgua(15);
    this->setCostoFuego(15);
}

