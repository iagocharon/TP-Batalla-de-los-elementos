#ifndef TP2_MENU_H
#define TP2_MENU_H

#include <iostream>
#include "Juego.h"
#include "Utiles.h"

#define MI_AGREGAR_PERSONAJE 1
#define MI_ELIMINAR_PERSONAJE 2
#define MI_MOSTRAR_NOMBRES 3
#define MI_BUSCAR_POR_NOMBRE 4
#define MI_PERSONAJES_MINIMOS 6
#define MI_COMENZAR 5
#define MI_SALIR 6

class MenuInicio {

public:
    //Imprime en pantalla un menu de opciones
    void mostrarMenu();

    // PRE: La opción ingresada es un entero
    // POS: Devuelve una opción válida elegida
    void accionMenu(int& eleccion, Juego* juego);

    // PRE: -
    // POS: Imprime espacios en blanco en la terminal, para la legibilidad de lo mostrado
    void espaciado();

private:
    //PRE: -
    //POS: Añade un nuevo personaje a la lista
    void agregarNuevo(ABB* personajes);

    //PRE: La lista no está vacia
    //POS: Elimina un personaje de la lista
    void eliminarPersonaje(ABB* personajes);

    //PRE: La lista no está vacia
    //POS: Muestra los nombres de los personajes de la lista
    void mostrarNombres(ABB* personajes);

    //PRE: La lista no está vacia
    //POS: Muestra las características de un personaje
    void buscarPorNombre(ABB* personajes);

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


#endif //TP2_MENU_H
