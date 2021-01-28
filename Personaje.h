#ifndef TP2_PERSONAJE_H
#define TP2_PERSONAJE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define TOPE_ENERGIA 20
#define MAX_PERSONAJES 3
#define ELEMENTO_TIERRA "Tierra"
#define ELEMENTO_AIRE "Aire"
#define ELEMENTO_AGUA "Agua"
#define ELEMENTO_FUEGO "Fuego"

using namespace std;

class Personaje{
protected:
    //Atributos

    string nombre;
    string elemento;
    int escudo;
    float vida;
    int energia;
    int fila;
    int columna;

public:
    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un personaje cargando sus atributos con lo recibido
    Personaje(string nombre, string elemento, int escudo, float vida);

    // PRE: -
    // POS: Alimenta al personaje, notifica al usuario
    virtual void alimentar() = 0;

    // PRE: -
    // POS: Devuelve el nombre del personaje
    string getNombre();

    string getElemento();
    // PRE: -
    // POS: Devuelve el escudo del personaje
    int getEscudo();

    // PRE: -
    // POS: Devuelve la vida del personaje
    int getVida();

    // PRE: -
    // POS: Devuelve la energia del personaje
    int getEnergia();
    
    int getFila();
    
    int getColumna();
    
    void setNombre(string nombre);
    
    void setElemento(string elemento);
    
    void setEscudo(int escudo);
    
    void setVida(int vida);
    
    void setEnergia(int energia);
    
    void setFila(int fila);
    
    void setColumna(int columna);
    
    void mostrar();
    
    virtual void atacar(Personaje* enemigos[MAX_PERSONAJES]) = 0;
};

#endif //TP2_PERSONAJE_H
