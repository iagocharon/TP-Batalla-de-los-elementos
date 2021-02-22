#include "Utiles.h"

ABB* Utiles::personajes() {
    ArchivoPersonaje archivo(RUTA);
    ABB *personajes = new ABB();
    if (archivo.aperturaValida()) {
        archivo.cargarPersonajes(personajes);
        return personajes;
    }
    return nullptr;
}

Tipo Utiles::establecerTipo(string elemento, string nombre, int escudo, int vida) {

    Tipo personaje;

    if (elemento == ELEMENTO_AIRE)
        personaje = new ElementalAire(nombre, elemento, escudo, vida);

    else if (elemento == ELEMENTO_FUEGO)
        personaje = new ElementalFuego(nombre, elemento, escudo, vida);

    else if (elemento == ELEMENTO_TIERRA)
        personaje = new ElementalTierra(nombre, elemento, escudo, vida);

    else
        personaje = new ElementalAgua(nombre, elemento, escudo, vida);

    return personaje;
}

Tipo Utiles::establecerTipo(string elemento, string nombre) {

    Tipo personaje;

    int escudo = randomizar(0, 2);
    int vida = randomizar(10, 100);

    personaje = establecerTipo(elemento, nombre, escudo, vida);

    return personaje;
}

int Utiles::randomizar(int minimo, int maximo) {

    srand(unsigned(time(0)));
    int numero = 0;

    int rango = maximo - minimo + 1;
    numero = rand() % rango + minimo;

    return numero;
}

void Utiles::limpiarPantalla() {
    system(CLEAR);
}

void Utiles::pausa() {
    cout << endl << endl << "<Enter>";
    cin.get();
    cin.get();
}

void Utiles::enmarcar(string texto) {
    int margen;
    int tamanio = int(texto.length());
    margen = ((ANCHO_PANTALLA / 2) - (tamanio / 2));
    for ( int i = 0; i < margen; i++) cout << " ";
    cout << "┌";
    for ( int i = 0; i < tamanio; i++) cout << "─";
    cout << "┐" << endl;
    for ( int i = 0; i < margen; i++) cout << " ";
    cout << "│" << texto << "│" << endl;
    for ( int i = 0; i < margen; i++) cout << " ";
    cout << "└";
    for ( int i = 0; i < tamanio; i++) cout << "─";
    cout << "┘" << endl;

}
