#include "ElementalAgua.h"

ElementalAgua::ElementalAgua(string nombre, string elemento, int escudo, float vida) : Personaje(nombre, elemento, escudo, vida) {
    this->vecesAlimentado = 0;
}

void ElementalAgua::alimentar() {
    if (this->vecesAlimentado < TOPE_ALIMENTACIONES) {
        vecesAlimentado ++;
        cout << "Estas alimentando a " << this->nombre << " un elemental de agua, que consume plancton para recuperar " << AUMENTO_ENERGIA_AGUA << " de energia" << endl;
        cout << "Se utilizo plancton para realizar este proceso, por lo que solo se puede alimentar al personaje " << 3 - vecesAlimentado << " veces mas" << endl;
        if ((this->energia + AUMENTO_ENERGIA_AGUA) > TOPE_ENERGIA) {
            energia = TOPE_ENERGIA;
        }
        else {
            energia += AUMENTO_ENERGIA_AGUA;
        }

    }
    else {
        cout << "Ya no hay plancton suficiente para alimentar de nuevo al personaje" << endl;
    }
}

void ElementalAgua::atacar(Personaje* enemigos[MAX_PERSONAJES]) {
    cout << "ATAQUE DE ELEMENTAL DE AGUA" << endl;
    int filaObjetivo, columnaObjetivo;
    cout << "\tIngrese las coordenadas del destino del ataque: " << endl;
    cout << "\t\tFila: ";
    cin >> filaObjetivo;
    cout << "\t\tColumna: ";
    cin >> columnaObjetivo;
    
    for (int i = 0; i < MAX_PERSONAJES; i++) {
        if ((enemigos[i]->getFila() == filaObjetivo) && (enemigos[i]->getColumna() == columnaObjetivo)) {
            if (this->energia > MINIMO_ENERGIA_AGUA) {
                float danio = DANIO_AGUA;
                if (enemigos[i]->getElemento() == ELEMENTO_FUEGO) {
                    danio += MODIFICADOR_AGUA;
                }
                else if (enemigos[i]->getElemento() == ELEMENTO_TIERRA) {
                    danio -= MODIFICADOR_AGUA;
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
            else {
                cout << "\tNo tiene energia suficiente para atacar." << endl;
            }
        }
    }
}
