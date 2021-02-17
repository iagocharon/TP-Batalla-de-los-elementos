#ifndef TP2_ACCION_H
#define TP2_ACCION_H
#include <iostream>
#include "Utiles.h"
#include "ABB.hpp"
#include "Juego.h"
#include "MenuSeleccion.h"

const int NO_ENCONTRADO = -1;
const int AGREGAR_PERSONAJE = 1;
const int ELIMINAR_PERSONAJE = 2;
const int MOSTRAR_NOMBRES = 3;
const int BUSCAR_POR_NOMBRE = 4;
const int JUGAR_JUEGO= 5;
const int SALIR = 6;
const int PERSONAJES_MINIMOS = 6;
const int BUSCAR_POR_NOMBRE_JUEGO = 1;
const int MOSTRAR_NOMBRES_JUEGO = 2;
const int ELEGIR_PERSONAJE = 3;

using namespace std;

class Accion {
private:
    int elegida;
    ABB* personajes;

public:
    // PRE: opcion es válida
    // POS: Crea una acción con opcion como elegida
    Accion(int opcion, ABB* personajes);

    //PRE: La poción elegida es válida
    //POS: Ejecuta la acción determinada por el atributo elegida
    void determinarAccion();

    //PRE: -
    //POS: Añade un nuevo personaje a la lista
    void agregarNuevo();

    //PRE: La lista no está vacia
    //POS: Elimina un personaje de la lista
    void eliminarPersonaje();

    //PRE: La lista no está vacia
    //POS: Muestra los nombres de los personajes de la lista
    void mostrarNombres();

    //PRE: La lista no está vacia
    //POS: Muestra las características de un personaje
    void buscarPorNombre();

    // void jugarPartida();


    //PRE: La lista no está vacia
    //POS: Aumenta la energía del personaje según lo estipulado
    void alimentarPersonaje();

    //PRE: -
    //POS: Devuelve un nombre ingresado por el usuario
    string ingresoNombre();

    //PRE: -
    //POS: Devuelve un elemento válido ingresado por el usuario
    string ingresoElemento();

    //PRE: -
    //POS: true si el elemento es uno de los posibles, false de otro modo
    bool elementoValido(string elemento);
};


#endif //TP2_ACCION_H
