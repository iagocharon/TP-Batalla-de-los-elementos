#include "Personaje.h"

Personaje::Personaje(string nombre, short escudo, short vida){
    
    this->nombre = nombre;
    this->escudo = escudo;
    this->vida = vida;
    srand(unsigned(time(NULL)));
    this->energia = rand() % MAX_ENERGIA;
}

std::string Personaje::obtenerNombre(){
    return nombre;
}

short Personaje::obtenerEscudo() {
    return escudo;
}

short Personaje::obtenerVida() {
    return vida;
}

short Personaje::obtenerEnergia() {
    return energia;
}

void Personaje::mostrar() {
    cout << "\tNOMBRE: " << this->nombre << endl;
    cout << "\tESCUDO: " << this->escudo << endl;
    cout << "\tVIDA: " << this->vida << endl;
    cout << "\tENERGIA: " << this->energia << endl;
}
