#include "ElementalAgua.h"

ElementalAgua::ElementalAgua(string nombre, string elemento, int escudo, int vida) : Personaje(nombre, elemento, escudo, vida) {
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
