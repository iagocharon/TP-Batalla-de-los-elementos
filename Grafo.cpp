#include "Grafo.hpp"

Grafo::Grafo() {
    this->primero = NULL;
    this->ultimo = NULL;
    this->criterioBusqueda = 0;
    this->tamanio = 0;
}

void Grafo::agregarVertice(Casillero* casillero) {
    Vertice* ingresante = new Vertice(casillero);
    if (!this->primero) {
        this->primero = ingresante;
        this->ultimo = ingresante;
        this->tamanio++;
        return;
    }
    this->ultimo->setSiguiente(ingresante);
    this->ultimo = ingresante;
    this->tamanio++;
}

Vertice* Grafo::getVertice(Casillero* casillero) {
    Vertice* auxiliar = this->primero;
    for (int i = 0; i < this->tamanio; i++) {
        if (auxiliar->getSiguiente()->getCasillero() == casillero) {
            return auxiliar;
        }
        auxiliar = auxiliar->getSiguiente();
    }
    return NULL;
}

bool Grafo::existeVertice(Casillero* casillero) {
    if (this->getVertice(casillero) != NULL) {
        return true;
    }
    else {
        return false;
    }
}

void Grafo::agregarArista(Vertice* inicio, Vertice* destino, int costoAgua, int costoAire, int costoFuego, int costoTierra) {
    Arista* nueva = new Arista(destino);
    nueva->setCostoAgua(costoAgua);
    nueva->setCostoAire(costoAire);
    nueva->setCostoFuego(costoFuego);
    nueva->setCostoTierra(costoTierra);
    inicio->agregarArista(nueva);
}

int Grafo::getCostoAgua(Vertice* inicio, Vertice* destino) {
    Arista* auxiliar = inicio->getArista();
    while (auxiliar != NULL) {
        if (auxiliar->getDestino() == destino) {
            return auxiliar->getCostoAgua();
        }
        auxiliar = auxiliar->getSiguiente();
    }
    return -1;
}

int Grafo::getCostoAire(Vertice* inicio, Vertice* destino) {
    Arista* auxiliar = inicio->getArista();
    while (auxiliar != NULL) {
        if (auxiliar->getDestino() == destino) {
            return auxiliar->getCostoAire();
        }
        auxiliar = auxiliar->getSiguiente();
    }
    return -1;
}

int Grafo::getCostoFuego(Vertice* inicio, Vertice* destino) {
    Arista* auxiliar = inicio->getArista();
    while (auxiliar != NULL) {
        if (auxiliar->getDestino() == destino) {
            return auxiliar->getCostoFuego();
        }
        auxiliar = auxiliar->getSiguiente();
    }
    return -1;
}

int Grafo::getCostoTierra(Vertice* inicio, Vertice* destino) {
    Arista* auxiliar = inicio->getArista();
    while (auxiliar != NULL) {
        if (auxiliar->getDestino() == destino) {
            return auxiliar->getCostoTierra();
        }
        auxiliar = auxiliar->getSiguiente();
    }
    return -1;
}

int Grafo::getTamanio() {
    return this->tamanio;
}

void Grafo::etiquetarVertices() {
    Vertice* vertice = this->primero;
    Etiqueta* nuevaEtiqueta;
    while(vertice != NULL){
        nuevaEtiqueta = new Etiqueta(vertice);
        this->etiquetados.push_back(nuevaEtiqueta);
        vertice = vertice->getSiguiente();
    }
}

bool Grafo::fueVisitado(list<Vertice*> yaVisitados, Vertice* evaluado) {
    list<Vertice*>::iterator i;
    i = yaVisitados.begin();
    while(i != yaVisitados.end()) {
        if(*i == evaluado) {
            return true;
        }
        i++;
    }
    return false;
}

Etiqueta* Grafo::getEtiqueta(Vertice* buscado) {
    list<Etiqueta*>::iterator i;
    i = this->etiquetados.begin();
    while(i != this->etiquetados.end()) {
        if((*i)->getVertice() == buscado) {
            return *i;
        }
        i++;
    }
    return NULL;
}


bool Grafo::caminoPorAgua() {
    if (this->criterioBusqueda == CRITERIO_AGUA) {
        return true;
    }
    else {
        return false;
    }
}

bool Grafo::caminoPorAire() {
    if (this->criterioBusqueda == CRITERIO_AIRE) {
        return true;
    }
    else {
        return false;
    }
}

bool Grafo::caminoPorFuego() {
    if (this->criterioBusqueda == CRITERIO_FUEGO) {
        return true;
    }
    else {
        return false;
    }
}

bool Grafo::caminoPorTierra() {
    if (this->criterioBusqueda == CRITERIO_TIERRA) {
        return true;
    }
    else {
        return false;
    }
}

void Grafo::evaluarVerticeDestino(Etiqueta* partida, Etiqueta* destino, int iteracion) {
    int partidaAcumulaAgua = 0, costoAristaAgua, pesoTotalAgua;
    int partidaAcumulaAire = 0, costoAristaAire, pesoTotalAire;
    int partidaAcumulaFuego = 0, costoAristaFuego, pesoTotalFuego;
    int partidaAcumulaTierra = 0, costoAristaTierra, pesoTotalTierra;
    if (!partida->getAnterior().empty()) {
        partidaAcumulaAgua = partida->getPesoAguaAcumulado();
        partidaAcumulaAire = partida->getPesoAireAcumulado();
        partidaAcumulaFuego = partida->getPesoFuegoAcumulado();
        partidaAcumulaTierra = partida->getPesoTierraAcumulado();
    }
    costoAristaAgua = this->getCostoAgua(partida->getVertice(), destino->getVertice());
    costoAristaAire = this->getCostoAire(partida->getVertice(), destino->getVertice());
    costoAristaFuego = this->getCostoFuego(partida->getVertice(), destino->getVertice());
    costoAristaTierra = this->getCostoTierra(partida->getVertice(), destino->getVertice());
    pesoTotalAgua = partidaAcumulaAgua + costoAristaAgua;
    pesoTotalAire = partidaAcumulaAire + costoAristaAire;
    pesoTotalFuego = partidaAcumulaFuego + costoAristaFuego;
    pesoTotalTierra = partidaAcumulaTierra + costoAristaTierra;
    if (destino->getAnterior().empty()) {
        destino->setPesoAguaAcumulado(pesoTotalAgua);
        destino->setPesoAireAcumulado(pesoTotalAire);
        destino->setPesoFuegoAcumulado(pesoTotalFuego);
        destino->setPesoTierraAcumulado(pesoTotalTierra);
        destino->setIteracion(iteracion);
    }
    else {
        int destinoAcumulaAgua = destino->getPesoAguaAcumulado();
        int destinoAcumulaAire = destino->getPesoAireAcumulado();
        int destinoAcumulaFuego = destino->getPesoFuegoAcumulado();
        int destinoAcumulaTierra = destino->getPesoTierraAcumulado();
        if (this->caminoPorAgua() && (pesoTotalAgua < destinoAcumulaAgua)) {
            destino->setPesoAguaAcumulado(pesoTotalAgua);
        }
        else if (this->caminoPorAire() && (pesoTotalAire < destinoAcumulaAire)) {
            destino->setPesoAireAcumulado(pesoTotalAire);
        }
        else if (this->caminoPorFuego() && (pesoTotalFuego < destinoAcumulaFuego)) {
            destino->setPesoFuegoAcumulado(pesoTotalFuego);
        }
        else if (this->caminoPorTierra() && (pesoTotalTierra < destinoAcumulaTierra)) {
            destino->getPesoTierraAcumulado();
        }
    }
}

void Grafo::verificarPesoVerticeMarcado(Vertice* visitado, Vertice* destino, int iteracion, list<Vertice*> &vistos, ColaPrioridad &cola){
    Etiqueta* auxiliar;
    int costoAguaVertMarcado, costoAguaVertPrevio;
    int costoAireVertMarcado, costoAireVertPrevio;
    int costoFuegoVertMarcado, costoFuegoVertPrevio;
    int costoTierraVertMarcado, costoTierraVertPrevio;
    
    int costoAguaArista = this->getCostoAgua(visitado, destino);
    int costoAireArista = this->getCostoAire(visitado, destino);
    int costoFuegoArista = this->getCostoFuego(visitado, destino);
    int costoTierraArista = this->getCostoTierra(visitado, destino);
    
    costoAguaVertPrevio = getEtiqueta(visitado)->getPesoAguaAcumulado();
    costoAireVertPrevio = getEtiqueta(visitado)->getPesoAireAcumulado();
    costoFuegoVertPrevio = getEtiqueta(visitado)->getPesoFuegoAcumulado();
    costoTierraVertPrevio = getEtiqueta(visitado)->getPesoTierraAcumulado();
    
    costoAguaVertMarcado = getEtiqueta(visitado)->getPesoAguaAcumulado();
    costoAireVertMarcado = getEtiqueta(visitado)->getPesoAireAcumulado();
    costoFuegoVertMarcado = getEtiqueta(visitado)->getPesoFuegoAcumulado();
    costoTierraVertMarcado = getEtiqueta(visitado)->getPesoTierraAcumulado();
    
    bool costoAguaMenorEncontrado = (costoAguaVertPrevio + costoAguaArista < costoAguaVertMarcado);
    bool costoAireMenorEncontrado = (costoAireVertPrevio + costoAireArista < costoAireVertMarcado);
    bool costoFuegoMenorEncontrado = (costoFuegoVertPrevio + costoFuegoArista < costoFuegoVertMarcado);
    bool costoTierraMenorEncontrado = (costoTierraVertPrevio + costoTierraArista < costoTierraVertMarcado);
    
    if ((this->caminoPorAgua() && costoAguaMenorEncontrado) || (this->caminoPorAire() && costoAireMenorEncontrado) || (this->caminoPorFuego() && costoFuegoMenorEncontrado) || (this->caminoPorTierra() && costoTierraMenorEncontrado)) {
        auxiliar = this->getEtiqueta(destino);
        auxiliar->setPesoAguaAcumulado(costoAguaVertPrevio + costoAguaArista);
        auxiliar->setPesoAireAcumulado(costoAireVertPrevio + costoAireArista);
        auxiliar->setPesoAguaAcumulado(costoFuegoVertPrevio + costoFuegoArista);
        auxiliar->setPesoAguaAcumulado(costoTierraVertPrevio + costoTierraArista);
        auxiliar->setIteracion(iteracion);
        vistos.remove(destino);
        cola.push(destino, costoAguaVertPrevio + costoAguaArista, costoAireVertPrevio + costoAireArista, costoFuegoVertPrevio + costoFuegoArista, costoTierraVertPrevio + costoTierraArista, iteracion);
    }
}

void Grafo::trabajoAdyacente(Arista* auxAristas, list<Vertice*>* vistos, Vertice* verticeVisitado, ColaPrioridad* cola, Etiqueta* auxActual, int iteracion) {
    Etiqueta* auxDestino = getEtiqueta(auxAristas->getDestino());
    if (!fueVisitado(*vistos, auxAristas->getDestino())) {
        int costoAguaArista = this->getCostoAgua(verticeVisitado, auxAristas->getDestino());
        int costoAireArista = this->getCostoAire(verticeVisitado, auxAristas->getDestino());
        int costoFuegoArista = this->getCostoFuego(verticeVisitado, auxAristas->getDestino());
        int costoTierraArista = this->getCostoTierra(verticeVisitado, auxAristas->getDestino());
        cola->push(auxAristas->getDestino(), costoAguaArista, costoAireArista, costoFuegoArista, costoTierraArista, iteracion);
        this->evaluarVerticeDestino(auxActual, auxDestino, iteracion);
    }
    else {
        this->verificarPesoVerticeMarcado(verticeVisitado, auxAristas->getDestino(), iteracion, *vistos, *cola);
    }
    auxDestino->sumoAnterior(verticeVisitado);
}

bool Grafo::existeCamino(Vertice* destino) {
    if (this->getEtiqueta(destino)->getAnterior().empty()) {
        return false;
    }
    else {
        return true;
    }
}

int Grafo::getPesoAguaAcumulado(Vertice* consultado) {
    return this->getEtiqueta(consultado)->getPesoAguaAcumulado();
}

int Grafo::getPesoAireAcumulado(Vertice* consultado) {
    return this->getEtiqueta(consultado)->getPesoAireAcumulado();
}

int Grafo::getPesoFuegoAcumulado(Vertice* consultado) {
    return this->getEtiqueta(consultado)->getPesoFuegoAcumulado();
}

int Grafo::getPesoTierraAcumulado(Vertice* consultado) {
    return this->getEtiqueta(consultado)->getPesoTierraAcumulado();
}

int Grafo::caminoMinimo(Vertice *salida, Vertice *destino) {
    int iteracion = 1;
    list<Vertice*> vistos;
    this->etiquetarVertices();
    ColaPrioridad cola(this->criterioBusqueda);
    cola.push(salida, 0, 0, 0, 0, 0);
    while (!cola.vacia()) {
        Vertice* visitado = cola.topAndPop();
        if (!fueVisitado(vistos, visitado)) {
            Arista* auxAristas = visitado->getArista();
            Etiqueta* auxActual = getEtiqueta(visitado);
            while (auxAristas != NULL) {
                this->trabajoAdyacente(auxAristas, &vistos, visitado, &cola, auxActual, iteracion);
                auxAristas = auxAristas->getSiguiente();
            }
            vistos.push_back(visitado);
            iteracion++;
        }
    }
    if (this->existeCamino(destino)) {
        switch (this->criterioBusqueda) {
            case CRITERIO_AGUA:
                return this->getPesoAguaAcumulado(destino);
            case CRITERIO_AIRE:
                return this->getPesoAireAcumulado(destino);
            case CRITERIO_FUEGO:
                return this->getPesoFuegoAcumulado(destino);
            case CRITERIO_TIERRA:
                return this->getPesoTierraAcumulado(destino);
        }
    }
    return -1;
}

