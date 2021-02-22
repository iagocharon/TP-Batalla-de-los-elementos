#include "Grafo.h"

Grafo::Grafo() {
    this->primero = NULL;
    this->ultimo = NULL;
    this->criterioBusqueda = 0;
    this->tamanio = 0;
}

Vertice* Grafo::getPrimero() {
    return this->primero;
}

Vertice* Grafo::getUltimo() {
    return this->ultimo;
}

int Grafo::getCriterioBusqueda() {
    return this->criterioBusqueda;
}

int Grafo::getTamanio() {
    return this->tamanio;
}

Vertice* Grafo::getVertice(int fila, int columna) {
    Vertice* auxiliar = this->primero;
    for (int i = 0; i < this->tamanio; i++) {
        if (auxiliar->getCasillero()->getFila() == fila && auxiliar->getCasillero()->getColumna() == columna) {
            return auxiliar;
        }
        auxiliar = auxiliar->getSiguiente();
    }
    return NULL;
}

Vertice* Grafo::getVertice(int posicion) {
    Vertice* auxiliar = this->primero;
    for (int i = 0; i < posicion; i++) {
        auxiliar = auxiliar->getSiguiente();
    }
    return auxiliar;
}

Arista* Grafo::getArista(Vertice *salida, Vertice *destino) {
    Arista* auxiliar = salida->getArista();
    while (auxiliar != NULL) {
        if (auxiliar->getDestino() == destino) {
            return auxiliar;
        }
        auxiliar = auxiliar->getSiguiente();
    }
    return NULL;
}

int Grafo::getDistancia(Vertice *salida, Vertice *destino) {
    Arista* auxiliar = getArista(salida, destino);
    switch (this->criterioBusqueda) {
        case CRITERIO_AGUA:
            return auxiliar->getCostoAgua();
        case CRITERIO_AIRE:
            return auxiliar->getCostoAire();
        case CRITERIO_FUEGO:
            return auxiliar->getCostoFuego();
        case CRITERIO_TIERRA:
            return auxiliar->getCostoTierra();
    }
    return -1;;
}

int Grafo::getNumeroVertice(Vertice *vertice) {
    Vertice* auxiliar = this->primero;
    for (int i = 0; i < this->tamanio; i ++) {
        if (auxiliar == vertice) {
            return i;
        }
        auxiliar = auxiliar->getSiguiente();
    }
    return -1;;
}

void Grafo::setPrimero(Vertice* primero) {
    this->primero = primero;
}

void Grafo::setUltimo(Vertice* ultimo) {
    this->ultimo = ultimo;
}

void Grafo::setCriterioBusqueda(int criterioBusqueda) {
    this->criterioBusqueda = criterioBusqueda;
}

void Grafo::setTamanio(int tamanio) {
    this->tamanio = tamanio;
}

void Grafo::setSucesores(Vertice* vertice, Vertice* sucesores[], int *cantidadSucesores) {
    Vertice* auxiliar = this->primero;
    *(cantidadSucesores) = 0;
    for (int i = 0; i < this->tamanio; i++) {
        if (this->existeArista(vertice, auxiliar)) {
            sucesores[*(cantidadSucesores)] = auxiliar;
            *(cantidadSucesores) = *(cantidadSucesores) + 1;
        }
        auxiliar = auxiliar->getSiguiente();
    }
}

void Grafo::agregarVertice(Casillero* casillero) {
    Vertice* vertice = new Vertice(casillero);
    if (!this->primero) {
        this->primero = vertice;
        this->ultimo = vertice;
    }
    else {
        this->ultimo->setSiguiente(vertice);
        this->ultimo = vertice;
    }
    tamanio++;
}

void Grafo::agregarArista(Vertice* salida, Vertice* destino) {
    Arista* arista = new Arista(destino);
    salida->agregarArista(arista);
}

bool Grafo::existeArista(Vertice *salida, Vertice *destino) {
    if (this->getArista(salida, destino) != NULL) {
        return true;
    }
    else {
        return false;
    }
}

bool Grafo::todosVistos(bool visitados[]) {
    for (int i = 0; i < this->tamanio; i++) {
        if (visitados[i] == false) {
            return false;
        }
    }
    return true;
}

int Grafo::minimoNoVisitado(bool visitados[], int distancias[]) {
    int distanciaMinima = INFINITO;
    int posicionMinima = -1;
    for (int i = 0; i < this->tamanio; i++) {
        if (visitados[i] == false) {
            if (distancias[i] < distanciaMinima) {
                distanciaMinima = distancias[i];
                posicionMinima = i;
            }
        }
    }
    return posicionMinima;
}

int Grafo::caminoMinimo(Vertice* salida, Vertice* destino) {
    int distancias[this->tamanio];
    bool visitados[this->tamanio];
    for (int i = 0; i < this->tamanio; i++) {
        distancias[i] = INFINITO;
        visitados[i] = false;
    }
    
    Vertice* auxiliar = this->primero;
    
    for (int i = 0; i < this->tamanio; i++) {
        if (!this->existeArista(salida, auxiliar)) {
            distancias[i] = INFINITO;
        }
        else {
            distancias[i] = this->getDistancia(salida, auxiliar);
        }
        auxiliar = auxiliar->getSiguiente();
    }
    distancias[this->getNumeroVertice(salida)] = 0;
    visitados[this->getNumeroVertice(salida)] = true;
    
    Vertice* sucesores[this->tamanio];
    int cantidadSucesores;
    
    while (!this->todosVistos(visitados)) {
        auxiliar = this->getVertice(this->minimoNoVisitado(visitados, distancias));
        visitados[this->getNumeroVertice(auxiliar)] = true;
        this->setSucesores(auxiliar, sucesores, &cantidadSucesores);
        
        for (int i = 0; i < cantidadSucesores; i++) {
            if ((distancias[this->getNumeroVertice(sucesores[i])]) > (distancias[getNumeroVertice(auxiliar)] + this->getDistancia(auxiliar, sucesores[i]))) {
                distancias[this->getNumeroVertice(sucesores[i])] = distancias[getNumeroVertice(auxiliar)] + this->getDistancia(auxiliar, sucesores[i]);
            }
        }
    }
    return distancias[this->getNumeroVertice(destino)];
}

Grafo::~Grafo() {
    
}
