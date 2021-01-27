#include "ElementalTierra.h"

ElementalTierra::ElementalTierra(string nombre, string elemento, int escudo, int vida) : Personaje(nombre, elemento, escudo, vida) {
    
}

void ElementalTierra::alimentar() {
    cout << "Estas alimentando a " << nombre << " un elemental de tierra, que consume hierbas para recuperar " << AUMENTO_ENERGIA_TIERRA << " de energia" << endl;
    if (energia + AUMENTO_ENERGIA_TIERRA > TOPE_ENERGIA)
        energia = TOPE_ENERGIA;
    else
        energia += AUMENTO_ENERGIA_TIERRA;
}
