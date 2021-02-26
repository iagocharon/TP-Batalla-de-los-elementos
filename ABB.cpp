#include "ABB.hpp"

ABB::ABB() {

    this->raiz = nullptr;
    cantidadCargados = 0;
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
    raiz->setPadre(NULL);
}

int ABB::cantidadElementos() {

    return cantidadCargados;
}

NodoABB* ABB::insertar(NodoABB* nodo, Personaje* dato, string clave) {
    if (nodo == NULL) {
        nodo = new NodoABB(clave, dato);
        setRaiz(nodo);

    }
    else if (clave > nodo->getClave()) {
        nodo->setDerecha(insertar(nodo->getDerecha(), dato, clave));
        nodo->getDerecha()->setPadre(nodo);

    }
    else {
        nodo->setIzquierda(insertar(nodo->getIzquierda(), dato, clave));
        nodo->getIzquierda()->setPadre(nodo);
    }

    return nodo;
}

void ABB::insertar(Personaje* dato, string clave) {
    this->raiz = insertar(this->raiz, dato, clave);
    cantidadCargados++;
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

void ABB::mostrarEnOrden(NodoABB *nodo) {

    if (nodo != NULL) {
        this->mostrarEnOrden(nodo->getIzquierda());
        cout << "\t-" << nodo->getClave() << "." << endl;
        this->mostrarEnOrden(nodo->getDerecha());
    }
}

void ABB::mostrarEnOrden() {

    this->mostrarEnOrden(this->raiz);
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
    delete nodo->getDato();

    if (nodo->esHoja()) {
        delete nodo;
    }

    else if (nodo->soloHijoDerecho()) {
        if (nodo->esRaiz()) {
            setRaiz(nodo->getDerecha());
            delete nodo;
        }
        else {
            nodo->getDerecha()->setPadre(nodo->getPadre());
            nodo->getPadre()->setDerecha(nodo->getDerecha());
            NodoABB *auxiliar = nodo;
            nodo = nodo->getDerecha();
            delete auxiliar;
        }
    }
    else if (nodo->soloHijoIzquierdo()) {
        if(nodo->esRaiz()) {
            setRaiz(nodo->getIzquierda());
            delete nodo;
        }
        else {
            nodo->getIzquierda()->setPadre(nodo->getPadre());
            nodo->getPadre()->setIzquierda(nodo->getIzquierda());
            NodoABB *auxiliar = nodo;
            nodo = nodo->getIzquierda();
            delete auxiliar;
        }
    }
    else {
        NodoABB* minimo = this->hallarMinimo(nodo->getDerecha());
        nodo->setDato(minimo->getDato());
        nodo->setClave(minimo->getClave());
        this->eliminarNodo(minimo);
    }
}

NodoABB* ABB::eliminar(NodoABB* nodo, string clave, bool* eliminado) {
    if (nodo == NULL) {
        return NULL;
    }

    if (nodo->getClave() == clave) {
        eliminarNodo(nodo);
        *eliminado = true;
        return nodo;

    }
    else if (nodo->getClave() < clave) {
        eliminar(nodo->getDerecha(), clave, eliminado);
        return nodo;

    }
    else {
        eliminar(nodo->getIzquierda(), clave, eliminado);
        return nodo;
    }
}

bool ABB::eliminar(string clave) {

    bool eliminado = false;

    this->eliminar(this->raiz, clave, &eliminado);

    if(!eliminado)
        cout << "No se encontró a " << clave << " entre las posibles opciones." << endl;

    else {
        //cout << "Se eliminó a " << clave << "." << endl;
        cantidadCargados--;
    }
    return eliminado;
}

void ABB::eliminarTodo(NodoABB* nodo) {
    if (nodo == NULL) {
        return;
    }
    this->eliminarTodo(nodo->getDerecha());
    this->eliminarTodo(nodo->getIzquierda());
    delete nodo->getDato();
    delete nodo;
}

void ABB::eliminarTodo() {
    this->eliminarTodo(this->raiz);
}

bool ABB::vacio() {
    return (this->raiz == NULL);
}


ABB::~ABB() {
    this->eliminarTodo();
}
