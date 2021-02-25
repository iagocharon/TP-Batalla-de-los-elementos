#include "ElementalFuego.h"

ElementalFuego::ElementalFuego(string nombre, string elemento, int escudo, int vida)
 : Personaje(nombre, elemento, escudo, vida) {}

ElementalFuego::ElementalFuego(string nombre, string elemento, int escudo, int vida, int energia, int fila, int columna)
: Personaje(nombre, elemento, escudo, vida, energia, fila, columna) {}

void ElementalFuego::alimentar() {
    cout << "Estas alimentando a " << this->nombre << " un elemental de fuego, que consume madera para recuperar " << AUMENTO_ENERGIA_FUEGO << " de energia" << endl;
    if ((this->energia + AUMENTO_ENERGIA_FUEGO) > TOPE_ENERGIA) {
        this->energia = TOPE_ENERGIA;
    }
    else {
        energia += AUMENTO_ENERGIA_FUEGO;
    }
}

void ElementalFuego::atacar(Personaje* enemigos[MAX_PERSONAJES]) {
    cout << "ATAQUE DE ELEMENTAL DE FUEGO" << endl;

    for (int i = 0; i < MAX_PERSONAJES; i++) {
        if (abs(enemigos[i]->getFila() - this->fila) <= 1) {
            float danio = DANIO_FUEGO;
            if (enemigos[i]->getElemento() == ELEMENTO_AIRE) {
                danio += MODIFICADOR_FUEGO;
            }
            else if (enemigos[i]->getElemento() == ELEMENTO_AGUA) {
                danio -= MODIFICADOR_FUEGO;
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
    }
    this->energia -= ENERGIA_ATAQUE_FUEGO;
}

void ElementalFuego::defender(Personaje* aliados[MAX_PERSONAJES]) {
    cout << "DEFENSA DE ELEMENTAL DE FUEGO" << endl;

    this->vida += RECUPERACION_FUEGO;
    this->energia -= ENERGIA_DEFENSA_FUEGO;
}

bool ElementalFuego::energiaNecesariaAtaque() {

    return this->energia >= ENERGIA_ATAQUE_FUEGO;
}

bool ElementalFuego::energiaNecesariaDefensa() {

    return this->energia >= ENERGIA_DEFENSA_FUEGO;
}

void ElementalFuego::caracteristicasPrimerMenu() {

    cout << nombre << " es un elemental de fuego, cuando se alimenta regenera 10 de energía y se cura "
                      "5 puntos de vida" << endl;
    cout << "El costo de desplazarse dependerá del lugar" << endl;
    cout << "CUIDADO: Si un personaje de fuego queda a 0 puntos de energía, pierde 5 puntos de vida." << endl;
}


void ElementalFuego::caracteristicasSegundoMenu() {
    cout << nombre << " es un elemental de fuego, su ataque consume 5 de energía y dañará a todos los enemigos "
                      "que se encuentren entre las filas " << fila - 1  << " y " << fila + 1 << " inclusive. "
                                                                                                "Los enemigos tipo aire perderán 30 puntos de vida, los tipo agua 10, y los tipo tierra o fuego 20 puntos"<< endl;

    cout << "La defensa consiste en gastar 10 puntos de energía para regenerarse 10 puntos de vida. " << endl;
}

ElementalFuego::~ElementalFuego() {
    
}
