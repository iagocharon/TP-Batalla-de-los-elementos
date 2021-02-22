#ifndef Grafo_hpp
#define Grafo_hpp

#include <iostream>
#include <list>
#include "DatosGrafo.h"
#include "Casillero.h"

#define CRITERIO_AGUA 1
#define CRITERIO_AIRE 2
#define CRITERIO_FUEGO 3
#define CRITERIO_TIERRA 4
#define INFINITO 99999

using namespace std;

class Grafo {
private:
    Vertice* primero;
    Vertice* ultimo;
    int criterioBusqueda; //1-Agua, 2-Aire, 3-Fuego, 4-Tierra.
    int tamanio;
    
public:

    // PRE:
    // POS:
    Grafo();

    // PRE:
    // POS:
    Vertice* getPrimero();

    // PRE:
    // POS:
    Vertice* getUltimo();

    // PRE:
    // POS:
    int getCriterioBusqueda();

    // PRE:
    // POS:
    int getTamanio();

    // PRE:
    // POS:
    Vertice* getVertice(int fila, int columna);

    // PRE:
    // POS:
    Vertice* getVertice(int posicion);

    // PRE:
    // POS:
    Arista* getArista(Vertice* salida, Vertice* destino);

    // PRE:
    // POS:
    int getDistancia(Vertice* salida, Vertice* destino);

    // PRE:
    // POS:
    int getNumeroVertice(Vertice* vertice);

    // PRE:
    // POS:
    void setPrimero(Vertice* primero);

    // PRE:
    // POS:
    void setUltimo(Vertice* ultimo);

    // PRE:
    // POS:
    void setCriterioBusqueda(int criterioBusqueda);

    // PRE:
    // POS:
    void setTamanio(int tamanio);

    // PRE:
    // POS:
    void setSucesores(Vertice* vertice, Vertice* sucesores[], int* cantidadSucesores);

    // PRE:
    // POS:
    void agregarVertice(Casillero* casillero);

    // PRE:
    // POS:
    void agregarArista(Vertice* salida, Vertice* destino);

    // PRE:
    // POS:
    bool existeArista(Vertice* salida, Vertice* destino);

    // PRE:
    // POS:
    bool todosVistos(bool visitados[]);

    // PRE:
    // POS:
    int minimoNoVisitado(bool visitados[], int distancias[]);

    // PRE:
    // POS:
    void mostrarLista(list<Vertice*> lista);

    // PRE:
    // POS:
    int caminoMinimo(Vertice* salida, Vertice* destino);

    // PRE:
    // POS:
    ~Grafo();
};

#endif /* Grafo_hpp */
