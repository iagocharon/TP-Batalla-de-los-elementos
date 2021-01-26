#include "ABB.hpp"

ABB::ABB() {
    this->raiz = NULL;
}

ABB::ABB(NodoABB* raiz) {
    this->raiz = raiz;
}

ABB::ABB(Personaje* dato, string clave) {
    insertar(dato, clave);
}

NodoABB* ABB::getRaiz() {
    return this->raiz;
}

void ABB::setRaiz(NodoABB* raiz) {
    this->raiz = raiz;
}

NodoABB* ABB::insertar(NodoABB* nodo, Personaje* dato, string clave) {
    if (nodo == NULL) {
        nodo = new NodoABB(clave, dato);
    }
    else if (clave > nodo->getClave()){
        nodo->setDerecha(insertar(nodo->getDerecha(), dato, clave), nodo);
    }
    else {
        nodo->setIzquierda(insertar(nodo->getIzquierda(), dato, clave), nodo);
    }
    return nodo;
}

void ABB::insertar(Personaje* dato, string clave) {
    this->raiz = insertar(this->raiz, dato, clave);
}

NodoABB* ABB::buscar(NodoABB* nodo, string clave) {
    if (nodo == NULL || nodo->getClave() == clave) {
        return nodo;
    }
    else if (clave > nodo->getClave()) {
        return buscar(nodo->getDerecha(), clave);
    }
    else {
        return buscar(nodo->getIzquierda(), clave);
    }
}

NodoABB* ABB::buscar(string clave) {
    return this->buscar(this->raiz, clave);
}

NodoABB* ABB::hallarMinimo(NodoABB* nodo) {
    if (nodo == NULL) {
        return NULL;
    }
    if (nodo->getIzquierda() != NULL) {
        return this->hallarMinimo(nodo->getIzquierda());
    }
    else {
        return nodo;
    }
}

void ABB::eliminarNodo(NodoABB* nodo) {
    if (nodo->esHoja()) {
        delete nodo;
    }
    else if (nodo->soloHijoDerecho()) {
        nodo->getDerecha()->setPadre(nodo->getPadre());
        NodoABB* auxiliar = nodo;
        nodo = nodo->getDerecha();
        delete auxiliar;
    }
    else if (nodo->soloHijoIzquierdo()) {
        nodo->getIzquierda()->setPadre(nodo->getPadre());
        NodoABB* auxiliar = nodo;
        nodo = nodo->getIzquierda();
        delete auxiliar;
    }
    else {
        NodoABB* minimo = this->hallarMinimo(nodo->getDerecha());
        nodo->setDato(minimo->getDato());
        nodo->setClave(minimo->getClave());
        this->eliminarNodo(minimo);
    }
}

NodoABB* ABB::eliminar(NodoABB* nodo, string clave) {
    if (nodo == NULL) {
        return NULL;
    }
    if (nodo->getClave() == clave) {
        this->eliminarNodo(nodo);
        return NULL;
    }
    else if (nodo->getClave() < clave) {
        nodo->setDerecha(eliminar(nodo->getDerecha(), clave));
        return nodo;
    }
    else {
        nodo->setIzquierda(eliminar(nodo->getIzquierda(), clave));
        return nodo;
    }
}

void ABB::eliminar(string clave) {
    this->eliminar(this->raiz, clave);
}

void ABB::eliminarTodo(NodoABB* nodo) {
    if (nodo == NULL) {
        return;
    }
    this->eliminarTodo(nodo->getDerecha());
    this->eliminarTodo(nodo->getIzquierda());
    //En caso de que haga falta, habria que agregar un delete para el personaje
    delete nodo;
}

void ABB::eliminarTodo() {
    this->eliminarTodo(this->raiz);
}

ABB::~ABB() {
    this->eliminarTodo();
}
