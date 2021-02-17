#include "Accion.h"

Accion::Accion(int opcion, ABB* personajes) {
    elegida = opcion;
    this->personajes = personajes;
}


void Accion::determinarAccion() {

    if (elegida == AGREGAR_PERSONAJE)
        agregarNuevo();

    else if(!personajes->vacio()) {

        if (elegida == ELIMINAR_PERSONAJE)
            eliminarPersonaje();

        else if (elegida == MOSTRAR_NOMBRES)
            mostrarNombres();

        else if (elegida == BUSCAR_POR_NOMBRE)
            buscarPorNombre();

        /*else if ((elegida == JUGAR_JUEGO) && (personajes->cantidadPersonajes() > PERSONAJES_MINIMOS))
            jugarPartida();
        */
        else if ((elegida == JUGAR_JUEGO) && (personajes->cantidadPersonajes() <= PERSONAJES_MINIMOS))
            cout << "Debe haber por lo menos 6 personajes para poder comenzar una partida, agregue "
                 << PERSONAJES_MINIMOS - personajes->cantidadPersonajes() << " personajes más para comenzar." << endl;
    }
    else if (elegida == SALIR);

    else
        cout << "La opción elegida no es válida para el estado de la lista" << endl;
}

void Accion::agregarNuevo() {

    Utiles util;
    Tipo personaje;
    
    string elemento = ingresoElemento();
    string nombre = ingresoNombre();

    personaje = util.establecerTipo(elemento, nombre);

    personajes->insertar(personaje, personaje->getNombre());
    cout << "Se agrego a " << personaje->getNombre() << " a la lista" << endl;
}

void Accion::eliminarPersonaje() {

    string nombre = ingresoNombre();
    this->personajes->eliminar(nombre);
}

void Accion::mostrarNombres() {

    this->personajes->mostrarEnOrden();
}


void Accion::buscarPorNombre() {

    string nombre = ingresoNombre();
    cout << personajes->cantidadPersonajes() << endl;
    this->personajes->buscar(nombre)->getDato()->mostrar();
}


void Accion::alimentarPersonaje() {

    string nombre = ingresoNombre();

    if (!(this->personajes->buscar(nombre))) {
        cout << "No hay un personaje con ese nombre" << endl;
    }
    else {
        this->personajes->buscar(nombre)->getDato()->alimentar();

    }
}

const int SALIR_JUEGO = 4;

/*
void Accion::jugarPartida(){

    Juego* juego = new Juego;
    MenuSeleccion menu;

    int eleccion = 0;

    while(eleccion != SALIR_JUEGO){

        eleccion = menu.determinarOpcion();

        if(eleccion == BUSCAR_POR_NOMBRE_JUEGO)
            buscarPorNombre();

        else if(eleccion == MOSTRAR_NOMBRES_JUEGO)
            mostrarNombres();

        else if(eleccion == ELEGIR_PERSONAJE)
            juego -> seleccionPersonajes();

        else
            juego -> setSalir(true);
    }

}
*/

string Accion::ingresoNombre() {
    string nombre;

    cout << "Ingrese el nombre del personaje" << endl;
    cin >> nombre;

    return nombre;
}


string Accion::ingresoElemento() {
    string elemento;

    cout << "Ingrese el elemento del personaje (agua, tierra, fuego o aire)" << endl;
    cin >> elemento;
    while(!elementoValido(elemento)) {
        cout << "El elemento ingresado no es válido, ingrese alguno de los posibles" << endl;
        cin >> elemento;
    }

    return elemento;
}


bool Accion::elementoValido(string elemento) {
    return(elemento == "agua" || elemento == "tierra" || elemento == "fuego" || elemento == "aire");
}
