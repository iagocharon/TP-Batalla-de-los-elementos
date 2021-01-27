#ifndef TP2_PERSONAJE_H
#define TP2_PERSONAJE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MAX_ENERGIA 20;

using namespace std;

class Personaje{

protected:
    //Atributos

    string nombre;
    int escudo;
    int vida;
    int energia;
    int fila;
    int columna;

public:
    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un personaje cargando sus atributos con lo recibido
    Personaje(string nombre, int escudo, int vida);

    // PRE: -
    // POS: Alimenta al personaje, notifica al usuario
    virtual void alimentar() = 0;

    // PRE: -
    // POS: Devuelve el nombre del personaje
    string getNombre();

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
    
    void setEscudo(int escudo);
    
    void setVida(int vida);
    
    void setEnergia(int energia);
    
    void setFila(int fila);
    
    void setColumna(int columna);
    
    void mostrar();
};

#endif //TP2_PERSONAJE_H
