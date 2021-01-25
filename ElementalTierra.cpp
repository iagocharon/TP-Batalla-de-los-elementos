//
// Created by nicolas on 26/11/20.
//

#include "ElementalTierra.h"

ElementalTierra::ElementalTierra(std::string nombre, short escudo, short vida) : Personaje(nombre, escudo, vida){}

void ElementalTierra::alimentar() {

    cout << "Estas alimentando a " << nombre << " un elemental de tierra, que consume hierbas para recuperar " << AUMENTO_ENERGIA_TIERRA << " de energia" << endl;

    if(energia + AUMENTO_ENERGIA_TIERRA > TOPE_ENERGIA)
        energia = TOPE_ENERGIA;
    else
        energia += AUMENTO_ENERGIA_TIERRA;
}