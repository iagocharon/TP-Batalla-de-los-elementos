#ifndef TP2_ARCHIVO_H
#define TP2_ARCHIVO_H

#include <fstream>
#include <iostream>
#include <string>
#include "Utiles.h"
#include "ABB.hpp"
#include "Personaje.h"

using namespace std;

class ArchivoPersonaje {

    ifstream archivo;
    bool apertura;
    string elemento;
    string nombre;
    int escudo;
    int vida;

public:
    // PRE: -
    // POS: Abre un archivo y lo guarda en caso de ser posible, carga el estado de apertura
    ArchivoPersonaje(string ruta);

    // PRE: -
    // POS: true si la apertura fue válida, false de otro modo
    bool aperturaValida();

    // PRE: La apertura del archivo fue válida, el archivo está bien conformado
    // POS: Lee una linea del archivo guardando lo leído en los atributos
    void leerLinea();

    // PRE: La apertura del archivo fue válida
    // POS: Carga la lista inicial según lo leido del archivo
    void cargarPersonajes(ABB* personajes);

    // PRE: -
    // POS: Cierra el archivo
    ~ArchivoPersonaje();
};


#endif //TP2_ARCHIVO_H
