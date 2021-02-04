#include "ArchivoPersonajes.h"

using namespace std;


ArchivoPersonaje::ArchivoPersonaje(string ruta) {
    this->archivo.open(ruta);
    if (!this->archivo) {
        cout << "Error al abrir archivo de personajes." << endl;
        this->apertura = false;
    }
    else {
        this->apertura = true;
    }
}


bool ArchivoPersonaje::aperturaValida() {
    return this->apertura;
}


void ArchivoPersonaje::leerLinea() {
    string escudoLeido;
    string vidaLeida;

    getline(this->archivo, this->nombre, ',');
    getline(this->archivo, escudoLeido, ',');
    this->escudo = (int)stoi(escudoLeido);
    getline(this->archivo, vidaLeida);
    this->vida = (int)stoi(vidaLeida);
}


void ArchivoPersonaje::cargarPersonajes(ABB* personajes) {

    if (this->aperturaValida()) {
        while(getline(archivo, elemento, ',')) {
            leerLinea();
            Personaje* auxiliar;
            if (elemento == ELEMENTO_AGUA) {
                auxiliar = new ElementalAgua(nombre, elemento, escudo, vida);
            }
            else if (elemento == ELEMENTO_AIRE) {
                auxiliar = new ElementalAire(nombre, elemento, escudo, vida);
            }
            else if (elemento == ELEMENTO_TIERRA) {
                auxiliar = new ElementalTierra(nombre, elemento, escudo, vida);
            }
            else if (elemento == ELEMENTO_FUEGO) {
                auxiliar = new ElementalFuego(nombre, elemento, escudo, vida);
            }
            else return;
            personajes->insertar(auxiliar, this->nombre);
        }
    }
}

ArchivoPersonaje::~ArchivoPersonaje() {
    this->archivo.close();
}
