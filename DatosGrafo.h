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
    // CONSTRUCTOR
    // PRE: Recibe el vertice de destino.
    // POS: Crea un objeto arista, asignandole los atributos segun corresponda.
    Arista(Vertice* destino);

    // PRE: -
    // POS: Devuelve el atributo siguiente.
    Arista* getSiguiente();

    // PRE: -
    // POS: Devuelve el atributo destino.
    Vertice* getDestino();

    // PRE: -
    // POS: Devuelve el atributo costoAire.
    int getCostoAire();

    // PRE: -
    // POS: Devuelve el atributo costoAgua.
    int getCostoAgua();

    // PRE: -
    // POS: Devuelve el atributo costoFuego.
    int getCostoFuego();

    // PRE: -
    // POS: Devuelve el atributo costoTierra.
    int getCostoTierra();

    // PRE: Recibe un objeto arista para asignar a siguiente.
    // POS: Asigna el atributo.
    void setSiguiente(Arista* siguiente);

    // PRE: Recibe un objeto vertice para asignar a destino.
    // POS: Asigna el atributo.
    void setDestino(Vertice* destino);

    // PRE: Recibe un int para asignar a costoAire.
    // POS: Asigna el atributo.
    void setCostoAire(int costoAire);

    // PRE: Recibe un int para asignar a costoAgua.
    // POS: Asigna el atributo.
    void setCostoAgua(int costoAgua);

    // PRE: Recibe un int para asignar a costoFuego.
    // POS: Asigna el atributo.
    void setCostoFuego(int costoFuego);

    // PRE: Recibe un int para asignar a costoTierra.
    // POS: Asigna el atributo.
    void setCostoTierra(int costoTierra);
    
    // DESTRUCTOR
    // PRE: -
    // POS: Destruye el objeto.
    ~Arista();
};

class Vertice {
private:
    Vertice* siguiente;
    Arista* arista;
    Casillero* casillero;
    
public:
    // CONSTRUCTOR
    // PRE: Recibe un objeto del tipo casillero.
    // POS: Crea el objeto e inicializa los atributos seguin corresponda.
    Vertice(Casillero* casillero);
    
    // PRE: -
    // POS: Devuelve el atributo siguiente.
    Vertice* getSiguiente();

    // PRE: -
    // POS: Devuelve el atributo arista.
    Arista* getArista();

    // PRE: -
    // POS: Devuelve el atributo casillero.
    Casillero* getCasillero();
    
    // PRE: Recibe un objeto vertice para asignar a siguiente.
    // POS: Asigna el atributo.
    void setSiguiente(Vertice* siguiente);

    // PRE: Recibe un objeto arista para asignar a siguiente.
    // POS: Asigna el atributo.
    void setArista(Arista* arista);

    // PRE: Recibe un objeto casillero para asignar a casillero.
    // POS: Asigna el atributo.
    void setCasillero(Casillero* casillero);

    // PRE: Recibe un objeto arista para remover del conjunto de aristas del vertice.
    // POS: Elimina la arista del conjunto de aristas.
    void eliminarArista(Arista* eliminar);

    // PRE: Recibe un objeto arista para agregar al conjunto de aristas del vertice.
    // POS: Agrega la arista al conjunto de aristas.
    void agregarArista(Arista* nueva);
    
    // DESTRUCTOR
    // PRE: -
    // POS: Destruye el objeto.
    ~Vertice();
};

#endif /* Arista_hpp */
