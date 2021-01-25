//
// Created by daniel on 6/12/20.
//

#include"Archivo.h"

using namespace std;


Archivo::Archivo(string ruta){

    archivo.open(ruta);
    if(!archivo){
        cout << "El archivo no pudo ser abierto" << endl;
        apertura = false;
    } else
        apertura = true;

}


bool Archivo::aperturaValida(){

    return apertura;
}


void Archivo::leerLinea(){

    string escudoLeido;
    string vidaLeida;

    getline(archivo, nombre, ',');
    getline(archivo, escudoLeido, ',');
    this -> escudo = (short)stoi(escudoLeido);
    getline(archivo, vidaLeida);
    this -> vida = (short)stoi(vidaLeida);
}


void Archivo::cargarLista(Lista* lista){

    Personaje* personaje;
    Utiles util;

    if(aperturaValida()){

        while(getline(archivo, elemento, ',')){

            leerLinea();

            personaje = util.establecerTipo(elemento, nombre, escudo, vida);

            lista -> alta(personaje);
        }
    }
}

Archivo::~Archivo(){

    archivo.close();
}