#ifndef DatoGrafo_hpp
#define DatoGrafo_hpp

#include <iostream>
#include "Casillero.h"

#define NOMBRE_AGUA "Agua"
#define NOMBRE_AIRE "Aire"
#define NOMBRE_FUEGO "Fuego"
#define NOMBRE_TIERRA "Tierra"

using namespace std;

class Vertice;

class Arista{
private:
    Arista* siguiente;
    Vertice* destino;
    int costoAire;
    int costoAgua;
    int costoFuego;
    int costoTierra;
    
public:

    // PRE:
    // POS:
    Arista(Vertice* destino);

    // PRE:
    // POS:
    Arista* getSiguiente();

    // PRE:
    // POS:
    Vertice* getDestino();

    // PRE:
    // POS:
    int getCostoAire();

    // PRE:
    // POS:
    int getCostoAgua();

    // PRE:
    // POS:
    int getCostoFuego();

    // PRE:
    // POS:
    int getCostoTierra();

    // PRE:
    // POS:
    void setSiguiente(Arista* siguiente);

    // PRE:
    // POS:
    void setDestino(Vertice* destino);

    // PRE:
    // POS:
    void setCostoAire(int costoAire);

    // PRE:
    // POS:
    void setCostoAgua(int costoAgua);

    // PRE:
    // POS:
    void setCostoFuego(int costoFuego);

    // PRE:
    // POS:
    void setCostoTierra(int costoTierra);
    
    ~Arista();
};

class Vertice {
private:
    Vertice* siguiente;
    Arista* arista;
    Casillero* casillero;
    
public:
    Vertice(Casillero* casillero);
    
    Vertice* getSiguiente();
    Arista* getArista();
    Casillero* getCasillero();
    
    void setSiguiente(Vertice* siguiente);
    void setArista(Arista* arista);
    void setCasillero(Casillero* casillero);
    void eliminarArista(Arista* eliminar);
    void agregarArista(Arista* nueva);
    
    ~Vertice();
};

#endif /* Arista_hpp */
