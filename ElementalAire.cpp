#include "ElementalAire.h"

ElementalAire::ElementalAire(string nombre, string elemento, int escudo, int vida)
 : Personaje(nombre, elemento, escudo, vida) {}

ElementalAire::ElementalAire(string nombre, string elemento, int escudo, int vida, int energia, int fila, int columna)
 : Personaje(nombre, elemento, escudo, vida, energia, fila, columna) {}


void ElementalAire::alimentar() {
    cout << this->nombre << " al ser un elemental de aire no recupera energía, es decir que no se alimenta" << endl;
}

void ElementalAire::atacar(Personaje* enemigos[MAX_PERSONAJES]) {
    cout << "ATAQUE DE ELEMENTAL DE AIRE" << endl;

    for (int i = 0; i < MAX_PERSONAJES; i++) {
        float danio = DANIO_AIRE;
        if (enemigos[i]->getElemento() == ELEMENTO_TIERRA) {
            danio += MODIFICADOR_AIRE;
        }
        else if (enemigos[i]->getElemento() == ELEMENTO_FUEGO) {
            danio -= MODIFICADOR_AIRE;
        }
        if (enemigos[i]->getEscudo() == 1) {
            danio = danio * 0.9;
        }
        else if (enemigos[i]->getEscudo() == 2) {
            danio = danio * 0.8;
        }
        else if (enemigos[i]->getEscudo() > 2) {
            danio = danio * 0.2;
        }
        enemigos[i]->setVida(enemigos[i]->getVida() - danio);
    }
    this->energia -= ENERGIA_ATAQUE_AIRE;
}

void ElementalAire::defender(Personaje* aliados[MAX_PERSONAJES]) {

    cout << "DEFENSA DE ELEMENTAL DE AIRE" << endl;

    cout << "\tIngrese las coordenadas de la casilla a la que desea desplazarse: " << endl;
    cout << "\t\tFila: ";
    cin >> this->fila;
    while (this->fila < 0 || this->fila >= MAX_TABLERO) {
        cout << "\t\tIngrese una fila valida: ";
        cin >> this->fila;
    }
    cout << "\t\tColumna: ";
    cin >> this->columna;
    while (this->columna < 0 || this->columna >= MAX_TABLERO) {
        cout << "\t\tIngrese una columna valida: ";
        cin >> this->columna;
    }

}

bool ElementalAire::energiaNecesariaAtaque() {

    return this->energia >= ENERGIA_ATAQUE_AIRE;
}

bool ElementalAire::energiaNecesariaDefensa() {

    return this->energia >= ENERGIA_DEFENSA_AIRE;
}

void ElementalAire::caracteristicasPrimerMenu() {

    cout << nombre << " es un elemental de aire, no se alimenta. Recuperará 5 puntos de energía al finalizar el turno." << endl;
    cout << "El costo de desplazarse dependerá del lugar." << endl;
}


void ElementalAire::caracteristicasSegundoMenu() {

    cout << nombre << " es un elemental de aire, su ataque consume 8 de energía y dañará a todos los enemigos "
                      "tipo tierra por 20 puntos, 10 a los de fuego y 15 a los de aire o agua" << endl;

    cout << "La defensa consiste en gastar 15 puntos de energía para desplazarse a cualquier otro "
            "punto del tablero." << endl;
}

ElementalAire::~ElementalAire() {
    
}
