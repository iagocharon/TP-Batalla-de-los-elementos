#ifndef NodoABB_hpp
#define NodoABB_hpp

#include <iostream>
#include "Personaje.h"

using namespace std;

class NodoABB {
private:
    string clave;
    Personaje* dato;
    NodoABB* derecha;
    NodoABB* izquierda;
    NodoABB* padre;
    
public:
    NodoABB(string clave, Personaje* dato);
    
    string getClave();
    Personaje* getDato();
    NodoABB* getDerecha();
    NodoABB* getIzquierda();
    NodoABB* getPadre();
    
    void setClave(string clave);
    void setDato(Personaje* dato);
    void setDerecha(NodoABB* derecha);
    void setDerecha(NodoABB* derecha, NodoABB* padre);
    void setIzquierda(NodoABB* izquierda);
    void setIzquierda(NodoABB* izquierda, NodoABB* padre);
    void setPadre(NodoABB* padre);

    bool esHijoIzquierdo(NodoABB* hijo);
    bool esHoja();
    bool soloHijoDerecho();
    bool soloHijoIzquierdo();
    bool esRaiz();
    
    ~NodoABB();
};

#endif /* NodoABB_hpp */
