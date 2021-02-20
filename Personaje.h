#ifndef TP2_PERSONAJE_H
#define TP2_PERSONAJE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define TOPE_ENERGIA 20
#define MAX_PERSONAJES 3
#define MAX_TABLERO 8
#define ELEMENTO_TIERRA "tierra"
#define ELEMENTO_AIRE "tire"
#define ELEMENTO_AGUA "agua"
#define ELEMENTO_FUEGO "fuego"

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
    Personaje(string nombre, string elemento, int escudo, int vida);

    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un personaje cargando sus atributos con lo recibido (se utiliza al cargar partida)
    Personaje(string nombre, string elemento, int escudo, int vida, int energia, int fila, int columna);

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

    virtual void defender(Personaje* aliados[MAX_PERSONAJES]) = 0;

    virtual bool energiaNecesariaAtaque() = 0;
    virtual bool energiaNecesariaDefensa() = 0;
};

#endif //TP2_PERSONAJE_H
