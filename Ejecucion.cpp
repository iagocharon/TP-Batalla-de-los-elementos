#include <iostream>
#include <string>
#include "Ejecucion.h"
#include "Menu.h"
#include "Accion.h"
#include "ArchivoPersonajes.h"

ABB* personajes(int tipo) {
    string ruta;
    if (tipo == IDE)
        ruta = "../personajes.csv";
    else
        ruta = "personajes.csv";

    ArchivoPersonaje archivo(ruta);
    ABB* personajes = new ABB();
    if (archivo.aperturaValida()) {
        archivo.cargarPersonajes(personajes);
        return personajes;
    }
    return nullptr;
}

void ejecucion(ABB* personajes) {

    Menu menu;
    int opcionElegida = 0;
    string ruta;


    if(personajes != nullptr){

        menu.bienvenida();

        while (opcionElegida != SALIR) {

            opcionElegida = menu.opcion();
            Accion accion(opcionElegida, personajes);

            accion.determinarAccion();
            menu.espaciado();
        }

        menu.despedida();
    }
}
