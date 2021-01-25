//
// Created by daniel on 24/11/20.
//

#ifndef TP2_LISTA_H
#define TP2_LISTA_H

#include "Nodo.h"
#include <iostream>
#include <string>

class Lista {

private:
    int elementos;
    Nodo* primero;
    Nodo* actual;

public:
    // PRE: -
    // POS: Crea un objeto Lista
    Lista();

    // PRE: El dato es válido
    // POS: Inserta un Nodo cargado con dato en la primera posición de la lista
    void alta(Tipo dato);

    // PRE: 0 < posición < elementos, La lista no esta vacía
    // POS: Elimina el posición Nodo de la lista
    void baja(int posicion);

    // PRE: -
    // POS: Devuelve la cantidad de elementos de la lista
    int obtenerLongitud();

    // PRE: 0 < posicion < elementos, la lista no está vacía
    // POS: Devuelve un puntero al posición Nodo
    Nodo* obtenerNodo(int posicion);

    // PRE: La lista no está vacía
    // POS: Devuelve el nombre apuntado por el actual
    string nombreActual();

    // PRE: La lista no está vacía
    // POS: Avanza el actual en una posición
    void avanzar();

    // PRE: La lista no está vacía
    // POS: Devuelve la posición en que fue encontrado el Personaje con nombre nombre
    int buscarNombre(std::string nombre);

    // PRE: -
    // POS: Mueve el actual a la primera posición
    void reiniciar();

    // PRE: -
    // POS: true si la lista está vacia, false si no lo está
    bool vacia();

    // PRE: -
    // POS: Da de baja todos los elementos de la lista hasta quedar vacia
    ~Lista();
};


#endif //TP2_LISTA_H
