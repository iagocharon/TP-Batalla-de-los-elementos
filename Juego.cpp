#include "Juego.h"

Juego::Juego(ABB *personajes) {
    jugador1 = new Jugador();
    jugador2 = new Jugador();
    this->personajes = personajes;
    salir = false;
    this->turno = 1;
}

ABB *Juego::getPersonajes() {
    return personajes;
}

bool Juego::getSalir() {
    return salir;
}

void Juego::setSalir(bool salir) {
    this->salir = salir;
}

Jugador *Juego::getJugador1() {
    return jugador1;
}

Jugador *Juego::getJugador2() {
    return jugador2;
}

int Juego::getTurno() {
    return this->turno;
}

void Juego::randomizarTurno() {
    this->turno = 1 + rand() % 2;
}

void Juego::cambiarTurno() {
    if (turno == 1) {
        turno = 2;
    }
    else {
        turno = 1;
    }
}

bool Juego::posicionValida(int fila, int columna) {
    if(fila < MIN_FILA || fila > MAX_FILA || columna < MIN_COLUMNA || columna > MAX_COLUMNA)
        return false;

    for(int i = 0; i < MAX_PERSONAJES; i++) {
        if((jugador1->getPersonajes()[i]->getFila() == fila-1 &&
           jugador1->getPersonajes()[i]->getColumna() == columna-1) ||
          (jugador2->getPersonajes()[i]->getFila() == fila-1 &&
           jugador2->getPersonajes()[i]->getColumna() == columna-1))
            return false;
    }

    return true;
}

void Juego::posicionarPersonajeJugador1(int personaje) {
    int fila;
    int columna;
    Utiles utiles;

    do {
        cout << "Personaje " << this->jugador1->getPersonajes()[personaje]->getNombre()<< " (" << personaje + 1  << "/3):" << endl;
        cout << "Ingrese la fila del personaje(1-8): " << endl;
        cin >> fila;
        cout << "Ingrese la columna del personaje (1-8): " << endl;
        cin >> columna;

        if(!posicionValida(fila, columna)) {
            cout << "Posicion inválida." << endl;
        }

    } while(!posicionValida(fila, columna));

    fila--;
    columna--;

    jugador1->getPersonajes()[personaje]->setFila(fila);
    jugador1->getPersonajes()[personaje]->setColumna(columna);
    cambiarTurno();
    utiles.limpiarPantalla();
}

void Juego::posicionarPersonajeJugador2(int personaje) {
    int fila;
    int columna;
    Utiles utiles;

    do {
        cout << "Personaje " << this->jugador2->getPersonajes()[personaje]->getNombre()<< " (" << personaje + 1  << "/3):" << endl;
        cout << "Ingrese la fila del personaje(1-8): " << endl;
        cin >> fila;
        cout << "Ingrese la columna del personaje (1-8): " << endl;
        cin >> columna;

        if(!posicionValida(fila, columna)) {
            cout << "Posicion inválida." << endl;
        }

    } while(!posicionValida(fila, columna));

    fila--;
    columna--;

    jugador2->getPersonajes()[personaje]->setFila(fila);
    jugador2->getPersonajes()[personaje]->setColumna(columna);
    cambiarTurno();
    utiles.limpiarPantalla();
}

void Juego::criterioDeBusqueda(Personaje* personaje, Grafo* tablero) {
    if (personaje->getElemento() == ELEMENTO_AGUA) {
        tablero->setCriterioBusqueda(1);
    }
    else if (personaje->getElemento() == ELEMENTO_AIRE) {
        tablero->setCriterioBusqueda(2);
    }
    else if (personaje->getElemento() == ELEMENTO_FUEGO) {
        tablero->setCriterioBusqueda(3);
    }
    else if (personaje->getElemento() == ELEMENTO_TIERRA) {
        tablero->setCriterioBusqueda(4);
    }
}

bool Juego::actualizarPosicion(Personaje* personaje, int energiaNecesaria, int fila, int columna) {

    bool energiaSuficiente = false;

    if (personaje->getEnergia() >= energiaNecesaria) {
        personaje->setFila(fila);
        personaje->setColumna(columna);
        personaje->setEnergia(personaje->getEnergia() - energiaNecesaria);
        energiaSuficiente = true;
    }
    else {
        cout << "No tiene la energia necesaria." << endl;
    }
    return energiaSuficiente;
}


bool Juego::moverPersonaje(Personaje* personaje, Grafo* tablero) {
    int fila = 0;
    int columna = 0;
    Vertice* salida;
    Vertice* destino;
    int energiaNecesaria;
    bool ingresoValido;

    do{
        ingresoValido = true;
        cout << "\nIngrese la fila a la cual mover el personaje (1 - 8): ";
        cin >> fila;
        cout << "\nIngrese la columna a la cual mover el personaje (1 - 8): ";
        cin >> columna;

        if(!posicionValida(fila, columna)) {
            cout << "\nPosicion invalida, vuelva a ingresarla." << endl;
            ingresoValido = false;
        }

        fila--;
        columna--;
    }while(!ingresoValido);

    salida = tablero->getVertice(personaje->getFila(), personaje->getColumna());
    destino = tablero->getVertice(fila, columna);
    criterioDeBusqueda(personaje, tablero);
    energiaNecesaria = tablero->caminoMinimo(salida, destino);
    bool energiaSuficiente = actualizarPosicion(personaje, energiaNecesaria, fila, columna);
    return energiaSuficiente;
}

void Juego::seleccionJugador1() {
    string nombre;
    bool eliminado;
    Utiles utiles;

    do {
        cout << jugador1->getCantidadPersonajes() + 1 << "/" << MAX_PERSONAJES << endl;
        cout << "\nIngrese el nombre del personaje a seleccionar: ";
        cin >> nombre;
        cout << endl;

        NodoABB* buscado = personajes->buscar(nombre);

        if(buscado == NULL)
            cout << "Personaje inválido" << endl;

        else {
            jugador1->setPersonaje(jugador1->getCantidadPersonajes(), buscado->getDato());
            eliminado = personajes->eliminar(nombre);
        }

    } while (!eliminado);
    cambiarTurno();
    utiles.limpiarPantalla();
}

void Juego::seleccionJugador2() {
    string nombre;
    bool eliminado;
    Utiles utiles;

    do {
        cout << jugador2->getCantidadPersonajes() + 1 << "/" << MAX_PERSONAJES << endl;
        cout << "\nIngrese el nombre del personaje a seleccionar: ";
        cin >> nombre;
        cout << endl;

        NodoABB* buscado = personajes->buscar(nombre);

        if(buscado == NULL)
            cout << "Personaje inválido" << endl;

        else {
            jugador2->setPersonaje(jugador2->getCantidadPersonajes(), buscado->getDato());
            eliminado = personajes->eliminar(nombre);
        }

    } while (!eliminado);

    cambiarTurno();
    utiles.limpiarPantalla();
}

void Juego::seleccionPersonajes() {
    if (turno == JUGADOR1) {
        seleccionJugador1();
    }
    else {
        seleccionJugador2();
    }
}

void Juego::posicionPersonajes(int personaje) {
    if(turno == JUGADOR1) {
        posicionarPersonajeJugador1(personaje);
    }
    else {
        posicionarPersonajeJugador2(personaje);
    }
}


int Juego::partidaCargar() {
    ifstream partida(PARTIDA);

    if (!partida.is_open()) {
        cout << "No se encontro una partida guardada" << endl;
        return PARTIDA_NO_ENCONTRADA;
    }

    string elemento;
    string nombre;
    string escudo;
    string vida;
    string energia;
    string fila;
    string columna;
    string turno;
    Personaje *personaje;

    getline(partida, turno, '\n');
    this->turno = stoi(turno);

    for (int i = 0; i < 2 * MAX_PERSONAJES; i++) {
        getline(partida, elemento, ',');
        getline(partida, nombre, ',');
        getline(partida, escudo, ',');
        getline(partida, vida, ',');
        getline(partida, energia, ',');
        getline(partida, fila, ',');
        getline(partida, columna, '\n');

        if (elemento == ELEMENTO_AIRE) {
            personaje = new ElementalAire(nombre, elemento, stoi(escudo), stoi(vida), stoi(energia), stoi(fila),
                                          stoi(columna));
        }
        else if (elemento == ELEMENTO_AGUA) {
            personaje = new ElementalAgua(nombre, elemento, stoi(escudo), stoi(vida), stoi(energia), stoi(fila),
                                          stoi(columna));
        }
        else if (elemento == ELEMENTO_TIERRA) {
            personaje = new ElementalTierra(nombre, elemento, stoi(escudo), stoi(vida), stoi(energia), stoi(fila),
                                            stoi(columna));
        }
        else {
            personaje = new ElementalFuego(nombre, elemento, stoi(escudo), stoi(vida), stoi(energia), stoi(fila),
                                           stoi(columna));
        }

        if (i < MAX_PERSONAJES) {
            jugador1->setPersonaje(i, personaje);
        }
        else {
            jugador2->setPersonaje(i - MAX_PERSONAJES, personaje);
        }
    }
    partida.close();
    cout << "Partida cargada" << endl;
    return PARTIDA_ENCONTRADA;
}

void Juego::partidaGuardar() {
    ofstream partida(PARTIDA);
    partida << turno << "\n";
    for (int i = 0; i <= 2; i++) {
        partida << jugador1->getPersonajes()[i]->getElemento() << ",";
        partida << jugador1->getPersonajes()[i]->getNombre() << ",";
        partida << jugador1->getPersonajes()[i]->getEscudo() << ",";
        partida << jugador1->getPersonajes()[i]->getVida() << ",";
        partida << jugador1->getPersonajes()[i]->getEnergia() << ",";
        partida << jugador1->getPersonajes()[i]->getFila() << ",";
        partida << jugador1->getPersonajes()[i]->getColumna() << "\n";
    }

    for (int i = 0; i <= 2; i++) {
        partida << jugador2->getPersonajes()[i]->getElemento() << ",";
        partida << jugador2->getPersonajes()[i]->getNombre() << ",";
        partida << jugador2->getPersonajes()[i]->getEscudo() << ",";
        partida << jugador2->getPersonajes()[i]->getVida() << ",";
        partida << jugador2->getPersonajes()[i]->getEnergia() << ",";
        partida << jugador2->getPersonajes()[i]->getFila() << ",";
        partida << jugador2->getPersonajes()[i]->getColumna() << "\n";
    }
    partida.close();
}

void Juego::borrarPartidaGuardada() {
    remove(PARTIDA);
}

bool Juego::personajesListos() {
    return (jugador1->getCantidadPersonajes() == MAX_PERSONAJES && jugador2->getCantidadPersonajes() == MAX_PERSONAJES);
}

Juego::~Juego() {
    for(int i = 0; i < MAX_PERSONAJES; i++) {
        delete jugador1->getPersonajes()[i];
        delete jugador2->getPersonajes()[i];
    }
    delete jugador1;
    delete jugador2;
}
