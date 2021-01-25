//
// Created by daniel on 24/11/20.
//
#include "Personaje.h"
#ifndef TP2_NODO_H
#define TP2_NODO_H

typedef Personaje* Tipo;

class Nodo {

private:
    Tipo dato;
    Nodo* siguiente;

public:
    //Crea un nuevo Nodo sin dato y un puntero a NULL
    Nodo();

    // Crea un nuevo Nodo con tipo de dato y un puntero a NULL
    Nodo(Tipo dato);

    // PRE: -
    // POS: Devuelve el dato del Nodo
    Tipo obtenerDato();

    // PRE: -
    // POS: Devuelve un puntero al siguiente Nodo
    Nodo* obtenerSiguiente();

    // PRE: Recibe un puntero a Nodo o NULL
    // POS: Asigna el siguiente recibido al puntero siguiente del Nodo
    void asignarSiguiente(Nodo* siguiente);

    //bool haySiguiente();
    ~Nodo();
};


#endif //TP2_NODO_H
