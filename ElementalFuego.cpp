#include "ElementalFuego.h"

ElementalFuego::ElementalFuego(string nombre, string elemento, int escudo, int vida)
 : Personaje(nombre, elemento, escudo, vida){}

ElementalFuego::ElementalFuego(string nombre, string elemento, int escudo, int vida, int energia, int fila, int columna)
: Personaje(nombre, elemento, escudo, vida, energia, fila, columna){}

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

    if (energiaNecesariaAtaque()) {
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
    else {
        cout << "\tNo tiene energia suficiente para atacar." << endl;
    }
}

void ElementalFuego::defender(Personaje* aliados[MAX_PERSONAJES]) {
    cout << "DEFENSA DE ELEMENTAL DE FUEGO" << endl;

    if (energiaNecesariaDefensa()) {
        this->vida += RECUPERACION_FUEGO;
        this->energia -= ENERGIA_DEFENSA_FUEGO;
    }
    else {
        cout << "\tNo tiene energia suficiente para defender." << endl;
    }
}

bool ElementalFuego::energiaNecesariaAtaque(){

    return this->energia >= ENERGIA_ATAQUE_FUEGO;
}

bool ElementalFuego::energiaNecesariaDefensa(){

    return this->energia >= ENERGIA_DEFENSA_FUEGO;
}