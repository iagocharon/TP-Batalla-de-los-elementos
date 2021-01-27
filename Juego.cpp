#include "Juego.hpp"

Juego::Juego() {
    this->personajes = NULL;
    this->eleccion = 0;
    srand(unsigned(time(NULL)));
    this->turno = 1 + rand()%2;
}

Juego::Juego(ABB* personajes) {
    this->personajes = personajes;
    this->eleccion = 0;
    srand(unsigned(time(NULL)));
    this->turno = 1 + rand()%2;
}

void Juego::mostrarMenu() {
    cout << "Seleccione una opcion:" << endl;
    cout << "\t1- Buscar por nombre los detalles de un personaje en particular." << endl;
    cout << "\t2- Mostrar todos los nombres de los personajes." << endl;
    cout << "\t3- Seleccionar personaje." << endl;
    cout << "\t4- Salir." << endl;
    cout << "\n\tEleccion: ";
    cin >> this->eleccion;
    
    while (this->eleccion < 1 || this->eleccion > 4) {
        cout << "\tIngrese una opcion valida: ";
        cin >> this->eleccion;
    }
}

void Juego::accionMenu() {
    switch (this->eleccion) {
        case 1:
            this->buscar();
            break;
        case 2:
            this->mostrarPersonajes();
            break;
        case 3:
            
        default:
            break;
    }
}

void Juego::buscar() {
    cout << "BUSCANDO PERSONAJE" << endl;
    cout << "\tIngrese el nombre del personaje a buscar: ";
    string nombre;
    cin >> nombre;
    this->personajes->buscar(nombre)->getDato()->mostrar();
}

void Juego::mostrarPersonajes() {
    cout << "MOSTRANDO PERSONAJES" << endl;
    this->personajes->mostrarEnOrden();
}

void Juego::seleccionarPersonaje() {
    cout << "SELECCION DE PERSONAJE" << endl;
    cout << "\tIngrese el nombre del personaje seleccionado: ";
    string nombre;
    cin >> nombre;
    Personaje* auxiliar = this->personajes->buscar(nombre)->getDato();
    if (this->turno == 1) {
        this->personajesJugador1.push_back(auxiliar);
        this->turno = 2;
    }
    else {
        this->personajesJugador1.push_back(auxiliar);
        this->turno = 1;
    }
    personajes->eliminar(nombre);
}

void Juego::cargarTablero() {
    ifstream archivo(NOMBRE_TABLERO);
    if (!(archivo.fail())) {
        for (int i = 0; i < MAX_FILAS; i++) {
            for (int j = 0; j < MAX_COLUMNAS; j++) {
                string letra;
                getline(archivo, letra, ',');
                if (letra == MONTANIA) {
                    tablero[i][j] = new CasilleroMontania();
                }
                else if (letra == PRECIPICIO) {
                    tablero[i][j] = new CasilleroPrecipicio();
                }
                else if (letra == LAGO) {
                    tablero[i][j] = new CasilleroLago();
                }
                else if (letra == VOLCAN) {
                    tablero[i][j] = new CasilleroVolcan();
                }
                else if (letra == CAMINO) {
                    tablero[i][j] = new CasilleroCamino();
                }
                else if (letra == VACIO) {
                    tablero[i][j] = new CasilleroVacio();
                }
            }
        }
    }
}
