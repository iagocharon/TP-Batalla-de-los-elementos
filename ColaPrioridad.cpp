#include "ColaPrioridad.hpp"

ColaPrioridad::ColaPrioridad(int criterioOrden) {
    this->primero = NULL;
    this->primeroSegunPrioridad = NULL;
    this->ultimo = NULL;
    this->criterioOrden = criterioOrden;
}

bool ColaPrioridad::vacia() {
    if (this->primero == NULL) {
        return true;
    }
    else {
        return false;
    }
}

int ColaPrioridad::topPesoAgua() {
    return this->primero->getPesoAgua();
}

int ColaPrioridad::topPesoAire() {
    return this->primero->getPesoAire();
}

int ColaPrioridad::topPesoFuego() {
    return this->primero->getPesoFuego();
}

int ColaPrioridad::topPesoTierra() {
    return this->primero->getPesoTierra();
}

int ColaPrioridad::topPrioridad() {
    return this->primero->getPrioridad();
}

bool ColaPrioridad::ordenPorAgua() {
    if (this->criterioOrden == ORDEN_AGUA) {
        return true;
    }
    else {
        return false;
    }
}

bool ColaPrioridad::ordenPorAire() {
    if (this->criterioOrden == ORDEN_AIRE) {
        return true;
    }
    else {
        return false;
    }
}

bool ColaPrioridad::ordenPorFuego() {
    if (this->criterioOrden == ORDEN_FUEGO) {
        return true;
    }
    else {
        return false;
    }
}

bool ColaPrioridad::ordenPorTierra() {
    if (this->criterioOrden == ORDEN_TIERRA) {
        return true;
    }
    else {
        return false;
    }
}

void ColaPrioridad::actualizarPrioridad(NodoColaPrioridad *aInsertar) {
    this->primeroSegunPrioridad = aInsertar;
}
 
void ColaPrioridad::insertarAlFinal(NodoColaPrioridad *aInsertar) {
    this->ultimo->setSiguiente(aInsertar);
    this->ultimo = aInsertar;
}

void ColaPrioridad::insertarNuevoEnPrioridad(NodoColaPrioridad* aInsertar){
    NodoColaPrioridad* auxiliar = this->primero;
    while(auxiliar->getSiguiente() != this->primeroSegunPrioridad) {
        auxiliar = auxiliar->getSiguiente();
    }
    aInsertar->setSiguiente(this->primeroSegunPrioridad);
    auxiliar->setSiguiente(aInsertar);
}

void ColaPrioridad::insertarOrdenado(NodoColaPrioridad* aInsertar){
    NodoColaPrioridad* auxiliar = this->primeroSegunPrioridad;
    bool hecho = false;
    while (!hecho && auxiliar->getSiguiente()) {
        if ((ordenPorAgua() && (aInsertar->getPesoAgua() <= auxiliar->getSiguiente()->getPesoAgua())) || (ordenPorAire() && (aInsertar->getPesoAire() <= auxiliar->getSiguiente()->getPesoAire())) || (ordenPorFuego() && (aInsertar->getPesoFuego() <= auxiliar->getSiguiente()->getPesoFuego())) || (ordenPorTierra() && (aInsertar->getPesoTierra() <= auxiliar->getSiguiente()->getPesoTierra()))) {
            aInsertar->setSiguiente(auxiliar->getSiguiente());
            auxiliar->setSiguiente(aInsertar);
            hecho = true;
        }
        auxiliar = auxiliar->getSiguiente();
    }
    if (!hecho){
        cout << "Ha ocurrido un error ordenando dentro de la prioridad " << this->primeroSegunPrioridad->getPrioridad() << endl;
        cin.get();
    }
}

void ColaPrioridad::insertarElemento(NodoColaPrioridad *aInsertar) {
    int prioridadActual = primeroSegunPrioridad->getPrioridad();
    int iteracion = aInsertar->getPrioridad();
    int pesoAgua = aInsertar->getPesoAgua();
    int pesoAire = aInsertar->getPesoAire();
    int pesoFuego = aInsertar->getPesoFuego();
    int pesoTierra = aInsertar->getPesoTierra();
    
    if (iteracion > prioridadActual) {
        this->insertarAlFinal(aInsertar);
        this->actualizarPrioridad(aInsertar);
    }
    else if (iteracion == prioridadActual) {
        if ((ordenPorAgua() && (pesoAgua >= this->ultimo->getPesoAgua())) || (ordenPorAire() && (pesoAire >= this->ultimo->getPesoAire())) || (ordenPorFuego() && (pesoFuego >= this->ultimo->getPesoFuego())) || (ordenPorTierra() && (pesoTierra >= this->ultimo->getPesoTierra()))) {
            this->insertarAlFinal(aInsertar);
        }
        else {
            if ((ordenPorAgua() && (pesoAgua >= this->primeroSegunPrioridad->getPesoAgua())) || (ordenPorAire() && (pesoAire >= this->primeroSegunPrioridad->getPesoAire())) || (ordenPorFuego() && (pesoFuego >= this->primeroSegunPrioridad->getPesoFuego())) || (ordenPorTierra() && (pesoTierra >= this->primeroSegunPrioridad->getPesoTierra()))) {
                if (this->primero == this->primeroSegunPrioridad) {
                    aInsertar->setSiguiente(this->primero);
                    this->primero = aInsertar;
                }
                else {
                    this->insertarNuevoEnPrioridad(aInsertar);
                }
                this->actualizarPrioridad(aInsertar);
            }
            else {
                insertarOrdenado(aInsertar);
            }
        }
    }
    else {
        cout << "ERROR - Iteracion no permitida" << endl;
        cin.get();
    }
}

void ColaPrioridad::push(Vertice* evaluado, int pesoAgua, int pesoAire, int pesoFuego, int pesoTierra, int iteracion) {
    if (this->primero == NULL) {
        this->primero = new NodoColaPrioridad(evaluado, iteracion, pesoAgua, pesoAire, pesoFuego, pesoTierra);
        this->primeroSegunPrioridad = this->primero;
        this->ultimo = this->primero;
    }
    else {
        NodoColaPrioridad* auxiliar = new NodoColaPrioridad(evaluado, iteracion, pesoAgua, pesoAire, pesoFuego, pesoTierra);
        insertarElemento(auxiliar);
    }
}

void ColaPrioridad::pop() {
    NodoColaPrioridad* auxiliar = this->primero;
    this->primero = auxiliar->getSiguiente();
    if (this->primeroSegunPrioridad == auxiliar){
        this->primeroSegunPrioridad = this->primero;
    }
    if(this->vacia()){
        ultimo = NULL;
    }
    delete auxiliar;
}

Vertice* ColaPrioridad::topAndPop() {
    Vertice* auxiliar = this->primero->getVertice();
    this->pop();
    return auxiliar;
}

ColaPrioridad::~ColaPrioridad() {
    while(!vacia()){
        this->pop();
    }
}
