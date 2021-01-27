#ifndef ABB_hpp
#define ABB_hpp

#include <iostream>
#include "Personaje.h"
#include "NodoABB.hpp"

using namespace std;

class ABB {
private:
    NodoABB* raiz;
    
    NodoABB* insertar(NodoABB* nodo, Personaje* dato, string clave);
    NodoABB* buscar(NodoABB* nodo, string clave);
    void mostrarEnOrden(NodoABB* nodo);
    NodoABB* hallarMinimo(NodoABB* nodo);
    void eliminarNodo(NodoABB* nodo);
    NodoABB* eliminar(NodoABB* nodo, string clave);
    void eliminarTodo(NodoABB* nodo);
    
public:
    ABB();
    ABB(NodoABB* raiz);
    ABB(Personaje* dato, string clave);
    
    NodoABB* getRaiz();
    void setRaiz(NodoABB* raiz);

    void insertar(Personaje* dato, string clave);
    NodoABB* buscar(string clave);
    void mostrarEnOrden();
    void eliminar(string clave);
    void eliminarTodo();
    
    ~ABB();
};



#endif /* ABB_hpp */
