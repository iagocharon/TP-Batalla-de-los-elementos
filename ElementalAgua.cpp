#include "ElementalAgua.h"

ElementalAgua::ElementalAgua(string nombre, string elemento, int escudo, int vida)
 : Personaje(nombre, elemento, escudo, vida) {
    vecesAlimentado = 0;
}

ElementalAgua::ElementalAgua(string nombre, string elemento, int escudo, int vida, int energia, int fila, int columna)
 : Personaje(nombre, elemento, escudo, vida, energia, fila, columna) {
    vecesAlimentado = 0;
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
    }
    this->energia -= ENERGIA_ATAQUE_AGUA;
}

void ElementalAgua::defender(Personaje* aliados[MAX_PERSONAJES]) {
    cout << "DEFENSA DE ELEMENTAL DE AGUA" << endl;

    this->vida += RECUPERACION_AGUA;
    for (int i = 0; i < MAX_PERSONAJES; i++) {
        if (aliados[i]->getNombre() != this->nombre) {
            aliados[i]->setVida(aliados[i]->getVida() + RECUPERACION_ALIADOS_AGUA);
        }
    }
}

bool ElementalAgua::energiaNecesariaAtaque() {

    return this->energia >= ENERGIA_ATAQUE_AGUA;
}

bool ElementalAgua::energiaNecesariaDefensa() {

    return this->energia >= ENERGIA_DEFENSA_AGUA;
}

void ElementalAgua::caracteristicasPrimerMenu() {

    cout << nombre << " es un elemental de agua, cuando se alimenta regenera 10 de energía" << endl;
    cout << "El costo de desplazarse dependerá del lugar" << endl;
}


void ElementalAgua::caracteristicasSegundoMenu() {

    cout << nombre << " es un elemental de agua, su ataque es dirigido a una posición específica e inflige "
                      "30 de daño a los elementales de fuego, 10 a los de tierra y 20 a los de agua y aire."
                      " Consume 5 puntos de energía." << endl;

    cout << "La defensa consiste en gastar 12 puntos de energía para regenerarse 50 puntos de vida y "
            "curar a todos los aliados aún vivos por 10 puntos de vitalidad." << endl;
}

ElementalAgua::~ElementalAgua() {
    
}
