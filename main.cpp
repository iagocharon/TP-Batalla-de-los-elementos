//
// Created by daniel on 6/12/20.
//

#include "ejecucion.h"
#include <iostream>

using namespace std;

int main(){

    int opcion;

    cout << "Ingrese: " << endl;
    cout << "1) Si va a correr el programa en una IDE con makefile" << endl;
    cout << "2) Si se va a correr en una terminal" << endl;
    cin >> opcion;

    while(opcion != IDE && opcion != TERMINAL){
        cout << "La opción no es válida, ingrese alguna según las opciones dadas" << endl;
        cin >> opcion;
    }

    ejecucion(opcion);

    return 0;
}