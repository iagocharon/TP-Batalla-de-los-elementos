#ifndef NodoABB_hpp
#define NodoABB_hpp

#include <iostream>
#include "Personaje.h"

using namespace std;

class NodoABB {
private:
    string clave;
    NodoABB* derecha;
    NodoABB* izquierda;
    NodoABB* padre;
    Personaje* dato;

public:

    // PRE: -
    // POS: Crea un NodoABB con this->clave = clave y this->dato = dato, hijos y padres = NULL
    NodoABB(string clave, Personaje* dato);

    // PRE: -
    // POS: Devuelve la clave del nodo
    string getClave();

    // PRE: -
    // POS: Devuelve el dato del nodo
    Personaje* getDato();

    // PRE: -
    // POS: Devuelve el hijo derecho del nodo o NULL si no lo tiene
    NodoABB* getDerecha();

    // PRE: -
    // POS: Devuelve el hijo izquierdo del nodo o NULL si no lo tiene
    NodoABB* getIzquierda();

    // PRE: -
    // POS: Devuelve el padre del nodo o NULL si es raíz
    NodoABB* getPadre();

    // PRE: -
    // POS: La clave del nodo pasa a ser this->clave = clave
    void setClave(string clave);

    // PRE: -
    // POS: El dato del nodo pasa a ser this->dato = dato
    void setDato(Personaje* dato);

    // PRE: -
    // POS: Cambia el hijo derecho del nodo al recibido en la función
    void setDerecha(NodoABB* derecha);

    // PRE: -
    // POS: Cambia el hijo derecho del nodo al recibido en la función, lo mismo con el padre
    void setDerecha(NodoABB* derecha, NodoABB* padre);

    // PRE: -
    // POS: Cambia el hijo izquierdo del nodo al recibido en la función
    void setIzquierda(NodoABB* izquierda);

    // PRE: -
    // POS: Cambia el hijo izquierdo del nodo al recibido en la función, lo mismo con el padre
    void setIzquierda(NodoABB* izquierda, NodoABB* padre);

    // PRE: -
    // POS: Cambia el padre del nodo al recibido en la función
    void setPadre(NodoABB* padre);

    // PRE: -
    // POS: true si el nodo es hijo izquierdo de algún otro nodo, false si no lo es
    bool esHijoIzquierdo(NodoABB* hijo);

    // PRE: -
    // POS: true si el nodo no tiene hijos
    bool esHoja();

    // PRE: -
    // POS: true si el nodo solo tiene hijo derecho
    bool soloHijoDerecho();

    // PRE: -
    // POS: true si el nodo solo tiene hijo izquierdo
    bool soloHijoIzquierdo();

    // PRE: -
    // POS: true si el nodo no tiene padres
    bool esRaiz();

    // PRE: -
    // POS: Destruye el nodo y libera su memoria, en caso de ser necesario cambia las conexiones entre
    //      nodos necesarias para que el árbol quede ordenado
    ~NodoABB();
};

#endif /* NodoABB_hpp */
