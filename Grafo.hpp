#ifndef Grafo_hpp
#define Grafo_hpp

#include <iostream>
#include <list>
#include "ColaPrioridad.hpp"
#include "Vertice.hpp"
#include "Arista.hpp"
#include "Etiqueta.hpp"

#define CRITERIO_AGUA 1
#define CRITERIO_AIRE 2
#define CRITERIO_FUEGO 3
#define CRITERIO_TIERRA 4

using namespace std;

class Grafo {
private:
    Vertice* primero;
    Vertice* ultimo;
    list<Etiqueta*> etiquetados;
    int criterioBusqueda; //1-Agua, 2-Aire, 3-Fuego, 4-Tierra.
    int tamanio;
    
    void etiquetarVertices();
    bool fueVisitado(list<Vertice*> yaVisitados, Vertice* evaluado);
    Etiqueta* getEtiqueta(Vertice* buscado);
    void evaluarVerticeDestino(Etiqueta* partida, Etiqueta* destino, int iteracion);
    void verificarPesoVerticeMarcado(Vertice* visitado, Vertice* destino, int iteracion, list<Vertice*> &vistos, ColaPrioridad &cola);
    void trabajoAdyacente(Arista* auxAristas, list<Vertice*>* vistos, Vertice* visitado, ColaPrioridad* cola, Etiqueta* auxActual, int iteracion);
    bool existeCamino(Vertice* destino);
    int getPesoAguaAcumulado(Vertice* aCalcular);
    int getPesoAireAcumulado(Vertice* aCalcular);
    int getPesoFuegoAcumulado(Vertice* aCalcular);
    int getPesoTierraAcumulado(Vertice* aCalcular);
    
public:
    Grafo();
    
    void agregarVertice(string nombre);
    Vertice* getVertice(string nombre);
    bool existeVertice(string nombre);
    void agregarArista(Vertice* inicio, Vertice* destino, int costoAgua, int costoAire, int costoFuego, int costoTierra);
    int getCostoAgua(Vertice* incio, Vertice* destino);
    int getCostoAire(Vertice* incio, Vertice* destino);
    int getCostoFuego(Vertice* incio, Vertice* destino);
    int getCostoTierra(Vertice* incio, Vertice* destino);
    int getTamanio();
    bool caminoPorAgua();
    bool caminoPorAire();
    bool caminoPorFuego();
    bool caminoPorTierra();
    int caminoMinimo(Vertice* salida, Vertice* destino);
    
    ~Grafo();
};

#endif /* Grafo_hpp */
