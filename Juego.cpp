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
    } else {
        turno = 1;
    }
}

bool Juego::posicionValida(int fila, int columna){
    if(fila < 1 || fila > 8 || columna < 1 || columna > 8)
        return false;

    for(int i = 0; i < MAX_PERSONAJES; i++){
        if((jugador1->getPersonajes()[i]->getFila() == fila-1 &&
           jugador1->getPersonajes()[i]->getColumna() == columna-1) ||
          (jugador2->getPersonajes()[i]->getFila() == fila-1 &&
           jugador2->getPersonajes()[i]->getColumna() == columna-1))
            return false;
    }

    return true;
}

void Juego::posicionarPersonaje(int personaje) {
    int fila;
    int columna;

    for (int i = 0; i < 2; i++) {
        do {
            cout << "Personaje " << personaje + 1 << "/3 del jugador " << turno << endl;
            cout << "Ingrese la fila del personaje(1-8): " << endl;
            cin >> fila;
            cout << "Ingrese la columna del personaje (1-8): " << endl;
            cin >> columna;

            if(!posicionValida(fila, columna)) {
                system("clear");
                cout << "Posicion inválida." << endl;
            }

        } while(!posicionValida(fila, columna));

        fila--;
        columna--;

        if (turno == 1) {
            jugador1->getPersonajes()[personaje]->setFila(fila);
            jugador1->getPersonajes()[personaje]->setColumna(columna);
        } else {
            jugador2->getPersonajes()[personaje]->setFila(fila);
            jugador2->getPersonajes()[personaje]->setColumna(columna);
        }
        cambiarTurno();
    }
}


/*
void Juego::moverPersonaje(Personaje* personaje){
    int x = 0;
    int y = 0;
    bool ingresoValido = false;

    do{
        ingresoValido = true;
        cout << "\nIngrese la coordenada x a la que moverse (1 - 8): ";
        cin >> x;
        cout << "\nIngrese la coordenada y a la que moverse (1 - 8): ";
        cin >> y;
        x -= 1;
        y -= 1;

        if(x >= MAX_TABLERO || x < 0 || y >= MAX_TABLERO || y < 0){
            cout << "\nCoordenadas invalidas, vuelva a ingresarlas." << endl;
            continue;
        }

        for(int i = 0; i < MAX_PERSONAJES; i++){
            if((x == jugador1->getPersonajes()[i]->getFila() && y == jugador1->getPersonajes()[i]->getFila()) ||
               (x == jugador2->getPersonajes()[i]->getFila() && y == jugador2->getPersonajes()[i]->getFila())){
                cout << "\nYa hay un personaje en esas coordenadas." << endl;
                ingresoValido = false;
                break;
            }
        }

    //Falta comprobar que la energía sea suficiente para mover al personaje al casillero deseado.
    }while(!ingresoValido);

    //Hay que restar la energia al personaje
    personaje->setFila(x);
    personaje->setColumna(y);
}
*/

void Juego::seleccionJugador1() {
    string nombre;
    bool eliminado;

    do {
        cout << "JUGADOR 1.\n" << jugador1->getCantidadPersonajes() + 1 << "/" << MAX_PERSONAJES << endl;
        cout << "\nIngrese el nombre del personaje a seleccionar: ";
        cin >> nombre;
        cout << endl;
        jugador1->setPersonaje(jugador1->getCantidadPersonajes(), personajes->buscar(nombre)->getDato());
        eliminado = personajes->eliminar(nombre);

        if (!eliminado) {
            cout << "Personaje inválido" << endl;
        }
    } while (!eliminado);

    cambiarTurno();

    system("clear");
}

void Juego::seleccionJugador2() {
    string nombre;
    bool eliminado;

    do {
        cout << "JUGADOR 2.\n" << jugador2->getCantidadPersonajes() + 1 << "/" << MAX_PERSONAJES << endl;
        cout << "\nIngrese el nombre del personaje a seleccionar: ";
        cin >> nombre;
        cout << endl;
        jugador2->setPersonaje(jugador2->getCantidadPersonajes(), personajes->buscar(nombre)->getDato());
        eliminado = personajes->eliminar(nombre);

        if (!eliminado) {
            cout << "Personaje inválido" << endl;
        }
    } while (!eliminado);

    cambiarTurno();

    system("clear");
}

void Juego::seleccionPersonajes() {
    if (turno == 1) {
        seleccionJugador1();
    } else {
        seleccionJugador2();
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
        } else if (elemento == ELEMENTO_AGUA) {
            personaje = new ElementalAgua(nombre, elemento, stoi(escudo), stoi(vida), stoi(energia), stoi(fila),
                                          stoi(columna));
        } else if (elemento == ELEMENTO_TIERRA) {
            personaje = new ElementalTierra(nombre, elemento, stoi(escudo), stoi(vida), stoi(energia), stoi(fila),
                                            stoi(columna));
        } else {
            personaje = new ElementalFuego(nombre, elemento, stoi(escudo), stoi(vida), stoi(energia), stoi(fila),
                                           stoi(columna));
        }

        if (i < MAX_PERSONAJES) {
            jugador1->setPersonaje(i, personaje);
        } else {
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


