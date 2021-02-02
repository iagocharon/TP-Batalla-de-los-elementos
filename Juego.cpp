#include "Juego.hpp"

Juego::Juego() {
    jugador1 = nullptr;
    jugador2 = nullptr;
    personajes = nullptr;
    srand(unsigned(time(NULL)));
    turno = 1 + rand()%2;
}

Juego::Juego(ABB* personajes) {
    jugador1 = nullptr;
    jugador2 = nullptr;
    this->personajes = personajes;
    salir = false;
    srand(unsigned(time(NULL)));
    this->turno = 1 + rand()%2;
}

Jugador* Juego::getJugador1(){
    return jugador1;
}

Jugador* Juego::getJugador2(){
    return jugador2;
}

void Juego::partidaCargar(){
    ifstream partida(PARTIDA);

    if(!partida.is_open())
    {
        cout << "No se encontro una partida guardada" << endl;
        return;
    }

    string elemento = "";
    string nombre = "";
    string escudo = "";
    string vida = "";
    string energia = "";
    string fila = "";
    string columna = "";
    string turno = "";
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

void Juego::seleccionJugador1(string nombre){
    cout << "JUGADOR 1." << jugador1->getCantidadPersonajes()+1 << "/" << MAX_PERSONAJES << endl;
    cout << "\nIngrese el nombre del personaje a seleccionar: ";
    cin >> nombre;
    cout << endl;
    jugador1->setPersonaje(jugador1->getCantidadPersonajes(), personajes->buscar(nombre)->getDato());
    personajes->eliminar(nombre);
    system("CLS");
}

void Juego::seleccionJugador2(string nombre){
    cout << "JUGADOR 2." << jugador2->getCantidadPersonajes()+1 << "/" << MAX_PERSONAJES << endl;
    cout << "\nIngrese el nombre del personaje a seleccionar: ";
    cin >> nombre;
    cout << endl;
    jugador2->setPersonaje(jugador2->getCantidadPersonajes(), personajes->buscar(nombre)->getDato());
    personajes->eliminar(nombre);
    system("CLS");
}

void Juego::seleccionPersonajes(){
    string nombre = "";

    if(turno == 1){
        cout << "Jugador 1\n" << endl;
        seleccionJugador1(nombre);
    }else{
        cout << "Jugador 2\n" << endl;
        seleccionJugador1(nombre);
    }
}

void Juego::setSalir(bool salir){
    this->salir = salir;
}

ABB* Juego::getPersonajes(){
    return personajes;
}

void Juego::partidaGuardar(){
    ofstream partida(PARTIDA);
    partida << turno << "\n";
    for(int i = 0; i <= 2; i++){
        partida << jugador1->getPersonajes()[i]->getElemento() << ",";
        partida << jugador1->getPersonajes()[i]->getNombre() << ",";
        partida << jugador1->getPersonajes()[i]->getEscudo() << ",";
        partida << jugador1->getPersonajes()[i]->getVida() << ",";
        partida << jugador1->getPersonajes()[i]->getEnergia() << ",";
        partida << jugador1->getPersonajes()[i]->getFila() << ",";
        partida << jugador1->getPersonajes()[i]->getColumna() << "\n";
    }

    for(int i = 0; i <= 2; i++){
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


