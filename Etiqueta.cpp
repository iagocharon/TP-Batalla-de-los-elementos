#include "Etiqueta.hpp"

Etiqueta::Etiqueta(Vertice* actual) {
    this->vertice = actual;
    this->pesoAguaAcumulado = INFINITO;
    this->pesoAireAcumulado = INFINITO;
    this->pesoFuegoAcumulado = INFINITO;
    this->pesoTierraAcumulado = INFINITO;
    this->iteracion = 0;
}

Vertice* Etiqueta::getVertice() {
    return this->vertice;
}

list<Vertice*> Etiqueta::getAnterior() {
    return this->anterior;
}

int Etiqueta::getPesoAguaAcumulado() {
    return this->pesoAguaAcumulado;
}

int Etiqueta::getPesoAireAcumulado() {
    return this->pesoAireAcumulado;
}

int Etiqueta::getPesoFuegoAcumulado() {
    return this->pesoFuegoAcumulado;
}

int Etiqueta::getPesoTierraAcumulado() {
    return this->pesoTierraAcumulado;
}

int Etiqueta::getIteracion() {
    return this->iteracion;
}

void Etiqueta::setVertice(Vertice* vertice) {
    this->vertice = vertice;
}

void Etiqueta::setAnterior(list<Vertice*> anterior) {
    this->anterior = anterior;
}

void Etiqueta::setPesoAguaAcumulado(int pesoAguaAcumulado) {
    this->pesoAguaAcumulado = pesoAguaAcumulado;
}

void Etiqueta::setPesoAireAcumulado(int pesoAireAcumulado) {
    this->pesoAireAcumulado = pesoAireAcumulado;
}

void Etiqueta::setPesoFuegoAcumulado(int pesoFuegoAcumulado) {
    this->pesoFuegoAcumulado = pesoFuegoAcumulado;
}

void Etiqueta::setPesoTierraAcumulado(int pesoTierraAcumulado) {
    this->pesoTierraAcumulado = pesoTierraAcumulado;
}

void Etiqueta::setIteracion(int iteracion) {
    this->iteracion = iteracion;
}

void Etiqueta::sumoAnterior(Vertice *anterior) {
    bool eraPadre = false;
    list<Vertice*>::iterator i;
    i = this->anterior.begin();
    while (!eraPadre && i != this->anterior.end()) {
        if (*i == anterior) {
            eraPadre = true;
        }
        i++;
    }
    if (eraPadre) {
        this->anterior.push_front(anterior);
    }
}

Etiqueta::~Etiqueta() {
    
}
