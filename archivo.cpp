#include"Archivo.h"

using namespace std;


Archivo::Archivo(string ruta) {

    archivo.open(ruta);
    if (!archivo) {
        cout << "El archivo no pudo ser abierto" << endl;
        apertura = false;
    } else
        apertura = true;

}


bool Archivo::aperturaValida() {

    return apertura;
}


void Archivo::leerLinea() {

    string escudoLeido;
    string vidaLeida;

    getline(archivo, nombre, ',');
    getline(archivo, escudoLeido, ',');
    this->escudo = (int)stoi(escudoLeido);
    getline(archivo, vidaLeida);
    this->vida = (int)stoi(vidaLeida);
}


void Archivo::cargarPersonajes(ABB* personajes) {
    if (aperturaValida()) {
        while(getline(archivo, elemento, ',')) {
            leerLinea();
//            personaje = util.establecerTipo(elemento, nombre, escudo, vida);
            Personaje* auxiliar = NULL;
            auxiliar->setNombre(nombre);
            auxiliar->setElemento(elemento);
            auxiliar->setEscudo(escudo);
            auxiliar->setVida(vida);
            personajes->insertar(auxiliar, this->nombre);
        }
    }
}

Archivo::~Archivo() {

    archivo.close();
}
