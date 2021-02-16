#include "Juego.hpp"

Juego::Juego() {

    jugador1 = new Jugador();
    jugador2 = new Jugador();
    personajes = nullptr;
    turno = 1;
}

Juego::Juego(ABB* personajes) {

    jugador1 = new Jugador();
    jugador2 = new Jugador();
    this->personajes = personajes;
    salida = false;
    turno = 1;
}

void Juego::cambiarTurno(){

    if(turno == 1)
        turno = 2;
    else
        turno = 1;
}

void Juego::randomizarTurno(){

    srand(unsigned(time(NULL)));
    this->turno = 1 + rand()%2;
}

void Juego::jugar(){

}

bool Juego::salir(){

    return salida;
}
Jugador* Juego::getJugador1(){
    return jugador1;
}

Jugador* Juego::getJugador2(){
    return jugador2;
}

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
            if((x == jugador1->getPersonaje(i)->getFila() && y == jugador1->getPersonaje(i)->getFila()) ||
               (x == jugador2->getPersonaje(i)->getFila() && y == jugador2->getPersonaje(i)->getFila())){
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

int Juego::getTurno(){
    return this->turno;
}

void Juego::partidaCargar(){
    ifstream partida(PARTIDA);

    if(!partida.is_open())
    {
        cout << "No se encontro una partida guardada" << endl;
        return;
    }

    string elemento;
    string nombre;
    string escudo;
    string vida;
    string energia;
    string fila;
    string columna;
    string turno;
    Personaje* personaje = nullptr;


    getline(partida, turno, '\n');
    this->turno = stoi(turno);

    for(int i = 0; i < 2*MAX_PERSONAJES; i++){
        getline(partida, elemento, ',');
        getline(partida, nombre, ',');
        getline(partida, escudo, ',');
        getline(partida, vida, ',');
        getline(partida, energia, ',');
        getline(partida, fila, ',');
        getline(partida, columna, '\n');

        if(elemento == ELEMENTO_AIRE)
        {
            personaje = new ElementalAire(nombre, elemento, stoi(escudo), stoi(vida), stoi(energia), stoi(fila),
                    stoi(columna));
        }
        else if(elemento == ELEMENTO_AGUA)
        {
            personaje = new ElementalAgua(nombre, elemento, stoi(escudo), stoi(vida), stoi(energia), stoi(fila),
                    stoi(columna));
        }
        else if(elemento == ELEMENTO_TIERRA)
        {
            personaje = new ElementalTierra(nombre, elemento, stoi(escudo), stoi(vida), stoi(energia), stoi(fila),
                    stoi(columna));
        }
        else
        {
            personaje = new ElementalFuego(nombre, elemento, stoi(escudo), stoi(vida), stoi(energia), stoi(fila),
                    stoi(columna));
        }

        if(i < MAX_PERSONAJES){
            jugador1->setPersonaje(i, personaje);
        }else{
            jugador2->setPersonaje(i-MAX_PERSONAJES, personaje);
        }
    }
    partida.close();
    cout << "Partida cargada" << endl;
}

void Juego::seleccionJugador1(){
    cout << "JUGADOR 1" << jugador1->getCantidadPersonajes()+1 << "/" << MAX_PERSONAJES << endl;
    string nombre;

    cout << "\nIngrese el nombre del personaje a seleccionar: ";
    cin >> nombre;
    cout << endl;
    jugador1->setPersonaje(jugador1->getCantidadPersonajes(), personajes->buscar(nombre)->getDato());
    jugador1->incrementarCantidadPersonajes();

    bool eliminado = personajes->eliminar(nombre);

    if(eliminado)
        cambiarTurno();

    system("CLS");
}

void Juego::seleccionJugador2(){
    cout << "JUGADOR 2" << jugador2->getCantidadPersonajes()+1 << "/" << MAX_PERSONAJES << endl;
    string nombre;

    cout << "\nIngrese el nombre del personaje a seleccionar: ";
    cin >> nombre;
    cout << endl;
    jugador2->setPersonaje(jugador2->getCantidadPersonajes(), personajes->buscar(nombre)->getDato());
    jugador2->incrementarCantidadPersonajes();

    bool eliminado = personajes->eliminar(nombre);

    if(eliminado)
        cambiarTurno();

    system("CLS");
}

void Juego::seleccionPersonajes(){

    if(turno == 1){
        seleccionJugador1();

    } else {
        seleccionJugador2();
    }
}

void Juego::posicionJugador1(int posicion) {
    cout << "JUGADOR 1";
    
    int fila, columna;
    cout << "Ingrese fila para el personaje " << jugador1->getPersonaje(posicion)->getNombre() << ": ";
    cin >> fila;
    jugador1->getPersonaje(posicion)->setFila(fila);
    cout << "Ingrese columna para el personaje " << jugador1->getPersonaje(posicion)->getNombre() << ": ";
    cin >> columna;
    jugador1->getPersonaje(posicion)->setColumna(columna);

}

void Juego::posicionJugador2(int posicion) {
    cout << "JUGADOR 2";
    
    int fila, columna;
    cout << "Ingrese fila para el personaje " << jugador2->getPersonaje(posicion)->getNombre() << ": ";
    cin >> fila;
    jugador2->getPersonaje(posicion)->setFila(fila);
    cout << "Ingrese columna para el personaje " << jugador2->getPersonaje(posicion)->getNombre() << ": ";
    cin >> columna;
    jugador2->getPersonaje(posicion)->setColumna(columna);

}

void Juego::posicionarPersonaje(int posicion) {
    if(turno == 1){
        posicionJugador1(posicion);
        posicionJugador2(posicion);

    }
    else {
        posicionJugador2(posicion);
        posicionJugador1(posicion);
    }

}


void Juego::setSalir(bool salir){
    this->salida = salir;
}

ABB* Juego::getPersonajes(){
    return personajes;
}

void Juego::partidaGuardar(){
    ofstream partida(PARTIDA);
    partida << turno << "\n";
    for(int i = 0; i <= 2; i++){
        partida << jugador1->getPersonaje(i)->getElemento() << ",";
        partida << jugador1->getPersonaje(i)->getNombre() << ",";
        partida << jugador1->getPersonaje(i)->getEscudo() << ",";
        partida << jugador1->getPersonaje(i)->getVida() << ",";
        partida << jugador1->getPersonaje(i)->getEnergia() << ",";
        partida << jugador1->getPersonaje(i)->getFila() << ",";
        partida << jugador1->getPersonaje(i)->getColumna() << "\n";
    }

    for(int i = 0; i <= 2; i++){
        partida << jugador2->getPersonaje(i)->getElemento() << ",";
        partida << jugador2->getPersonaje(i)->getNombre() << ",";
        partida << jugador2->getPersonaje(i)->getEscudo() << ",";
        partida << jugador2->getPersonaje(i)->getVida() << ",";
        partida << jugador2->getPersonaje(i)->getEnergia() << ",";
        partida << jugador2->getPersonaje(i)->getFila() << ",";
        partida << jugador2->getPersonaje(i)->getColumna() << "\n";
    }
    partida.close();
}


