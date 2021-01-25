#include <iostream>
#include <string>
#include "ejecucion.h"
#include "Menu.h"
#include "Accion.h"
#include "Archivo.h"

void ejecucion(int tipo) {

    Menu menu;
    int opcionElegida = 0;
    string ruta;

    if(tipo == IDE)
        ruta = "../personajes.csv";
    else
        ruta = "personajes.csv";

    Archivo archivo(ruta);
    Lista* lista = new Lista();

    if(archivo.aperturaValida()) {

        archivo.cargarLista(lista);
        menu.bienvenida();

        while (opcionElegida != SALIR) {

            opcionElegida = menu.opcion();
            Accion accion(opcionElegida, lista);

            accion.determinarAccion();
            menu.espaciado();
        }

        menu.despedida();
    }

    delete lista;
}
