#include "ElementalAire.h"

ElementalAire::ElementalAire(string nombre, string elemento, int escudo, int vida) : Personaje(nombre, elemento, escudo, vida) {
    
}

void ElementalAire::alimentar() {
    cout << this->nombre << " al ser un elemental de aire no recupera energía, es decir que no se alimenta" << endl;
}

void ElementalAire::atacar(Personaje* enemigos[MAX_PERSONAJES]) {
    cout << "ATAQUE DE ELEMENTAL DE AIRE" << endl;
    if (this->energia >= ENERGIA_ATAQUE_AIRE) {
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
    else {
        cout << "\tNo tiene energia suficiente para atacar." << endl;
    }
}

void ElementalAire::defender(Personaje* aliados[MAX_PERSONAJES]) {
    cout << "DEFENSA DE ELEMENTAL DE AIRE" << endl;
    if (this->energia >= ENERGIA_DEFENSA_AIRE) {
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
            cout << "\t\tIngrese una fila valida: ";
            cin >> this->columna;
        }
    }
    else {
        cout << "\tNo tiene energia suficiente para defender." << endl;
    }
}
