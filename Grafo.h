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
    Grafo();
    
    Vertice* getPrimero();
    Vertice* getUltimo();
    int getCriterioBusqueda();
    int getTamanio();
    Vertice* getVertice(int fila, int columna);
    Vertice* getVertice(int posicion);
    Arista* getArista(Vertice* salida, Vertice* destino);
    int getDistancia(Vertice* salida, Vertice* destino);
    int getNumeroVertice(Vertice* vertice);

    void setPrimero(Vertice* primero);
    void setUltimo(Vertice* ultimo);
    void setCriterioBusqueda(int criterioBusqueda);
    void setTamanio(int tamanio);
    void setSucesores(Vertice* vertice, Vertice* sucesores[], int* cantidadSucesores);
    
    void agregarVertice(Casillero* casillero);
    void agregarArista(Vertice* salida, Vertice* destino);
    
    bool existeArista(Vertice* salida, Vertice* destino);
    bool todosVistos(bool visitados[]);
    int minimoNoVisitado(bool visitados[], int distancias[]);
    void mostrarLista(list<Vertice*> lista);
    int caminoMinimo(Vertice* salida, Vertice* destino);
    
    ~Grafo();
};

#endif /* Grafo_hpp */
