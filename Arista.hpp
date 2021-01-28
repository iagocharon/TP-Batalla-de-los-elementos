#ifndef Arista_hpp
#define Arista_hpp

#include <iostream>

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

#endif /* Arista_hpp */
