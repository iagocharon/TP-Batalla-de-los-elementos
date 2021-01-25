//
// Created by daniel on 6/12/20.
//

#include "ElementalAgua.h"

using namespace std;

ElementalAgua::ElementalAgua(string nombre, short escudo, short vida) : Personaje(nombre, escudo, vida) {

    vecesAlimentado = 0;
}

void ElementalAgua::alimentar() {

    if(vecesAlimentado < TOPE_ALIMENTACIONES) {

        vecesAlimentado ++;

        cout << "Estas alimentando a " << nombre << " un elemental de agua, que consume plancton para recuperar " << AUMENTO_ENERGIA_AGUA << " de energia" << endl;
        cout << "Se utilizo plancton para realizar este proceso, por lo que solo se puede alimentar al personaje " << 3 - vecesAlimentado << " veces mas" << endl;

        if(energia + AUMENTO_ENERGIA_AGUA > TOPE_ENERGIA)
            energia = TOPE_ENERGIA;
        else
            energia += AUMENTO_ENERGIA_AGUA;

    } else
        cout << "Ya no hay plancton suficiente para alimentar de nuevo al personaje" << endl;
}