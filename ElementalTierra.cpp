#include "ElementalTierra.h"


ElementalTierra::ElementalTierra(string nombre, string elemento, int escudo, int vida)
 : Personaje(nombre, elemento, escudo, vida){
   this->bonificacion = false;
 }

ElementalTierra::ElementalTierra(string nombre, string elemento, int escudo, int vida, int energia, int fila, int columna)
 : Personaje(nombre, elemento, escudo, vida, energia, fila, columna){
   this->bonificacion = false;
 }


bool ElementalTierra::getBonificacion() {
    return this->bonificacion;
}

void ElementalTierra::setBonificacion(bool bonificacion) {
    this->bonificacion = bonificacion;
}

void ElementalTierra::alimentar() {
    cout << "Estas alimentando a " << nombre << " un elemental de tierra, que consume hierbas para recuperar " << AUMENTO_ENERGIA_TIERRA << " de energia" << endl;
    if (energia + AUMENTO_ENERGIA_TIERRA > TOPE_ENERGIA)
        energia = TOPE_ENERGIA;
    else
        energia += AUMENTO_ENERGIA_TIERRA;
}

void ElementalTierra::atacar(Personaje* enemigos[MAX_PERSONAJES]) {
    cout << "ATAQUE DE ELEMENTAL DE TIERRA" << endl;

    for (int i = 0; i < MAX_PERSONAJES; i++) {
        float danio;
        if (abs(enemigos[i]->getFila() - this->fila) <= 2) {
            if (abs(enemigos[i]->getColumna() - this->columna) <= 2) {
                danio = DANIO_TIERRA_BASE * 3;
            }
            else if (abs(enemigos[i]->getColumna() - this->columna) <= 4) {
                danio = DANIO_TIERRA_BASE * 2;
            }
            else {
                danio = DANIO_TIERRA_BASE;
            }
        }
        else if (abs(enemigos[i]->getFila() - this->fila) <= 4) {
            if (abs(enemigos[i]->getColumna() - this->columna) <= 4) {
                danio = DANIO_TIERRA_BASE * 2;
            }
            else {
                danio = DANIO_TIERRA_BASE;
            }
        }
        else {
            danio = DANIO_TIERRA_BASE;
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
        if(enemigos[i]->getElemento() == ELEMENTO_AGUA)
            danio += MODIFICADOR_TIERRA_AGUA;

        else if(enemigos[i]->getElemento() == ELEMENTO_AGUA)
            danio = MODIFICADOR_TIERRA_AIRE;

        enemigos[i]->setVida(enemigos[i]->getVida() - danio);
    }
    this->energia -= ENERGIA_ATAQUE_TIERRA;
}

void ElementalTierra::defender(Personaje* aliados[MAX_PERSONAJES]) {
    cout << "DEFENSA DE ELEMENTAL DE TIERRA" << endl;

    this->escudo =+ BONIFICACION_ESCUDO_TIERRA;
    setBonificacion(true);
    this->energia -= ENERGIA_DEFENSA_TIERRA;
}

bool ElementalTierra::energiaNecesariaAtaque(){

    return this->energia >= ENERGIA_ATAQUE_TIERRA;
}

bool ElementalTierra::energiaNecesariaDefensa(){

    return this->energia >= ENERGIA_DEFENSA_TIERRA;
}

void ElementalTierra::caracteristicasPrimerMenu(){
    cout << nombre << " es un elemental de tierra, cuando se alimenta regenera 8 de energía" << endl;
    cout << "El costo de desplazarse dependerá del lugar" << endl;
}


void ElementalTierra::caracteristicasSegundoMenu(){

    cout << nombre << " es un elemental de tierra, su ataque consume 6 de energía y dañará a todos los enemigos"
                      " su daño cambia según la cercanía con el enemigo." << endl;
    cout << "La defensa consiste en gastar 5 puntos de energía para obtener 2 puntos de escudo hasta luego de "
            "ser atacado, lo que disminuirá el daño recidio a un 20%." << endl;
}