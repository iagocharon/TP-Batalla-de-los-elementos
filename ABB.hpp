#ifndef ABB_hpp
#define ABB_hpp

#include <iostream>
#include "Personaje.h"
#include "ElementalAgua.h"
#include "ElementalAire.h"
#include "ElementalFuego.h"
#include "ElementalTierra.h"
#include "NodoABB.hpp"

using namespace std;

class ABB {
private:
    NodoABB* raiz;
    int cantidadCargados;
    
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

    int cantidadPersonajes();
    
    NodoABB* getRaiz();
    void setRaiz(NodoABB* raiz);

    void insertar(Personaje* dato, string clave);
    NodoABB* buscar(string clave);
    void mostrarEnOrden();
    void eliminar(string clave);
    void eliminarTodo();
    bool vacio();
    
    ~ABB();
};



#endif /* ABB_hpp */
