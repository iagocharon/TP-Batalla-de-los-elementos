#ifndef ABB_hpp
#define ABB_hpp

#include <iostream>
#include "Personaje.h"
#include "ElementalAgua.h"
#include "ElementalAire.h"
#include "ElementalFuego.h"
#include "ElementalTierra.h"
#include "NodoABB.h"

using namespace std;

class ABB {
private:

    NodoABB* raiz;
    int cantidadCargados;

    // PRE: -
    // POS: Inserta un nodo con clave y dato, de forma ordenada
    //      Si el árbol es vacío, crea su primer nodo, haciéndolo su raíz
    //      (El retorno de la función es para poder utilizar recursión)
    NodoABB* insertar(NodoABB* nodo, Personaje* dato, string clave);

    // PRE: El árbol no esta vacío
    // POS: Devuelve un nodo con la clave buscada o NULL en caso de no ser encontrado
    NodoABB* buscar(NodoABB* nodo, string clave);

    // PRE: El árbol no está vacio
    // POS: Muestra ordenadamente el árbol en orden alfabético, de menor a mayor (de derecha a izquierda)
    void mostrarEnOrden(NodoABB* nodo);

    // PRE: El árbol no está vacio
    // POS: Halla el mínimo, siendo este, el ínfimo valor del subárbol izquierdo de nodo
    //      (El retorno de la función es para poder utilizar recursión)
    NodoABB* hallarMinimo(NodoABB* nodo);

    // PRE: -
    // POS: Elimina nodo dejando ordenada y conectada la secuencia.
    void eliminarNodo(NodoABB* nodo);

    // PRE: El árbol no esta vacio
    // POS: Busca el nodo a eliminar mediante su clave para luego llamar a eliminarNodo, en caso
    //      de haber encontrado la clave en el árbol, *eliminado = true
    //      (El retorno de la función es para poder utilizar recursión)
    NodoABB* eliminar(NodoABB* nodo, string clave, bool* eliminado);

    // PRE: -
    // POS: Elimina todos los nodos del árbol, liberando su memoria
    void eliminarTodo(NodoABB* nodo);
    
public:

    // PRE: -
    // POS: Crea un ABB vacío
    ABB();

    // PRE: -
    // POS: Crea un ABB con this->raiz = raiz
    ABB(NodoABB* raiz);

    // PRE: -
    // POS: Crea un ABB con su raíz conteniendo un dato y una clave
    ABB(Personaje* dato, string clave);

    // PRE: -
    // POS: Devuelve la cantidad de elementos en el árbol
    int cantidadElementos();

    // PRE: -
    // POS: Devuelve un NodoABB* = raiz
    NodoABB* getRaiz();

    // PRE: -
    // POS: Cambia la raiz actual por la recibida en el método, o en caso de ser un árbol vacío,
    //      inserta la raíz
    void setRaiz(NodoABB* raiz);

    // PRE: -
    // POS: Llama al método privado insertar y aumenta en uno la cantidadElementos
    void insertar(Personaje* dato, string clave);

    // PRE: -
    // POS: LLama al método privado buscar y devuelve el nodo
    NodoABB* buscar(string clave);

    // PRE: -
    // POS: LLama al método privado mostrarEnOrden
    void mostrarEnOrden();

    // PRE: -
    // POS: LLama al método privado eliminar, disminuye en uno cantidadElementos si en efecto se eliminó
    //      algo, o muestra un mensaje por pantalla informando al usuario que no se pudo eliminar lo buscado
    bool eliminar(string clave);

    // PRE: -
    // POS: LLama al método privado eliminarTodo
    void eliminarTodo();

    // PRE: -
    // POS: true si el árbol está vacío, false de otro modo
    bool vacio();
    
//    void reemplazarNodo(NodoABB* aReemplazar, NodoABB* reemplazante);

    // PRE: -
    // POS: Borra el árbol completo
    ~ABB();
};



#endif /* ABB_hpp */
