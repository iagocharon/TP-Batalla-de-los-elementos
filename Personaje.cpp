#include "Personaje.h"

Personaje::Personaje(string nombre, string elemento, int escudo, int vida) {
    this->nombre = nombre;
    this->elemento = elemento;
    this->escudo = escudo;
    this->vida = vida;
    srand(unsigned(time(NULL)));
    this->energia = rand() % TOPE_ENERGIA;
    this->fila = -1;
    this->columna = -1;
}

Personaje::Personaje(string nombre, string elemento, int escudo, int vida, int energia, int fila, int columna) {
    this->nombre = nombre;
    this->elemento = elemento;
    this->escudo = escudo;
    this->vida = vida;
    this->energia = energia;
    this->fila = fila;
    this->columna = columna;
}

string Personaje::getNombre() {
    return this->nombre;
}

string Personaje::getElemento() {
    return this->elemento;
}

int Personaje::getEscudo() {
    return this->escudo;
}

int Personaje::getVida() {
    return this->vida;
}

int Personaje::getEnergia() {
    return this->energia;
}

int Personaje::getFila() {
    return this->fila;
}

int Personaje::getColumna() {
    return this->columna;
}

void Personaje::setNombre(string nombre) {
    this->nombre = nombre;
}

void Personaje::setElemento(string elemento) {
    this->elemento = elemento;
}

void Personaje::setEscudo(int escudo) {
    this->escudo = escudo;
}

void Personaje::setVida(int vida) {
    this->vida = vida;
}

void Personaje::setEnergia(int energia) {
    this->energia = energia;
}

void Personaje::setFila(int fila) {
    this->fila = fila;
}

void Personaje::setColumna(int columna) {
    this->columna = columna;
}


void Personaje::mostrar() {
    cout << "\tELEMENTO: " << this->elemento << endl;
    cout << "\tNOMBRE: " << this->nombre << endl;
    cout << "\tESCUDO: " << this->escudo << endl;
    cout << "\tVIDA: " << this->vida << endl;
    cout << "\tENERGIA: " << this->energia << endl;
}
