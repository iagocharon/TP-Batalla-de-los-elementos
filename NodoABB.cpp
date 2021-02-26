#include "NodoABB.h"

NodoABB::NodoABB(string clave, Personaje* dato) {
    this->clave = clave;
    this->dato = dato;
    this->derecha = NULL;
    this->izquierda = NULL;
    this->padre = NULL;
}

string NodoABB::getClave() {
    return this->clave;
}

Personaje* NodoABB::getDato() {
    return this->dato;
}

NodoABB* NodoABB::getDerecha() {
    return this->derecha;
}

NodoABB* NodoABB::getIzquierda() {
    return this->izquierda;
}

NodoABB* NodoABB::getPadre() {
    return this->padre;
}

void NodoABB::setClave(string clave) {
    this->clave = clave;
}

void NodoABB::setDato(Personaje* dato) {
    this->dato = dato;
}

void NodoABB::setDerecha(NodoABB* derecha) {
    this->derecha = derecha;
}

void NodoABB::setDerecha(NodoABB* derecha, NodoABB* padre) {
    this->derecha = derecha;
    this->padre = padre;
}


void NodoABB::setIzquierda(NodoABB* izquierda) {
    this->izquierda = izquierda;
}

void NodoABB::setIzquierda(NodoABB* izquierda, NodoABB* padre) {
    this->izquierda = izquierda;
    this->padre = padre;
}

void NodoABB::setPadre(NodoABB* padre) {
    this->padre = padre;
}

bool NodoABB::esHoja() {
    if (this->derecha == NULL && this->izquierda == NULL) {
        return true;
    }
    else {
        return false;
    }
}

bool NodoABB::soloHijoDerecho() {
    if (this->derecha != NULL && this->izquierda == NULL) {
        return true;
    }
    else {
        return false;
    }
}

bool NodoABB::soloHijoIzquierdo() {
    if (this->derecha == NULL && this->izquierda != NULL) {
        return true;
    }
    else {
        return false;
    }
}
bool NodoABB::esRaiz() {
    return padre == NULL;
}
bool NodoABB::esHijoIzquierdo(NodoABB* hijo) {

    return (izquierda == hijo);
}

NodoABB::~NodoABB() {

}
