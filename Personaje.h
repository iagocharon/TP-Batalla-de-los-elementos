#ifndef TP2_PERSONAJE_H
#define TP2_PERSONAJE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define TOPE_ENERGIA 20
#define MAX_PERSONAJES 3
#define MAX_TABLERO 8
#define ELEMENTO_TIERRA "tierra"
#define ELEMENTO_AIRE "aire"
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

    // PRE: El personaje está posicionado
    // POS: Devuelve el número de fila en que está posicionado el personaje
    int getFila();

    // PRE: El personaje está posicionado
    // POS: Devuelve el número de columna en que está posicionado el personaje
    int getColumna();

    // PRE: -
    // POS: Cambia el nombre del personaje al recibido
    void setNombre(string nombre);

    // PRE: -
    // POS: Cambia el elemento del personaje al recibido
    void setElemento(string elemento);

    // PRE: -
    // POS: Cambia el escudo del personaje al recibido
    void setEscudo(int escudo);

    // PRE: -
    // POS: Cambia la vida del personaje a la recibida
    void setVida(int vida);

    // PRE: -
    // POS: Cambia la energia del personaje a la recibida
    void setEnergia(int energia);

    // PRE: -
    // POS: Cambia la fila del personaje a la recibida
    void setFila(int fila);

    // PRE: -
    // POS: Cambia la columna del personaje a la recibida
    void setColumna(int columna);

    // PRE: -
    // POS: Muestra por pantalla los atributos del personaje
    void mostrar();


    // Métodos virtuales implementados por los hijos (polimorfismo)
    virtual void alimentar() = 0;
    virtual void atacar(Personaje* enemigos[MAX_PERSONAJES]) = 0;
    virtual void defender(Personaje* aliados[MAX_PERSONAJES]) = 0;
    virtual bool energiaNecesariaAtaque() = 0;
    virtual bool energiaNecesariaDefensa() = 0;
    virtual void caracteristicasPrimerMenu() = 0;
    virtual void caracteristicasSegundoMenu() = 0;
    
    virtual ~Personaje();
};

#endif //TP2_PERSONAJE_H
