#ifndef DatoGrafo_hpp
#define DatoGrafo_hpp

#include <iostream>
#include "Casillero.hpp"

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
    Arista(Vertice* destino);

    Arista* getSiguiente();
    Vertice* getDestino();
    int getCostoAire();
    int getCostoAgua();
    int getCostoFuego();
    int getCostoTierra();
    
    void setSiguiente(Arista* siguiente);
    void setDestino(Vertice* destino);
    void setCostoAire(int costoAire);
    void setCostoAgua(int costoAgua);
    void setCostoFuego(int costoFuego);
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
