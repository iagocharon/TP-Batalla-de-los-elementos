//
// Created by nicolas on 25/11/20.
//

#ifndef TP2_MENU_H
#define TP2_MENU_H


class Menu {

public:
    //Muestra un mensaje por pantalla de bienvenida al programa
    void bienvenida();

    //Imprime en pantalla un menu de opciones
    void mostrarMenu();

    // PRE: La opción ingresada es un entero
    // POS: Devuelve una opción válida elegida
    int opcion();

    // PRE: -
    // POS: True si la opción recibida es alguna de las posibles, False de otro modo.
    bool opcionValida(int opcion);

    // PRE: -
    // POS: Muestra al ususario un mensaje de despedida
    void despedida();

    // PRE: -
    // POS: Imprime espacios en blanco en la terminal, para la legibilidad de lo mostrado
    void espaciado();
};


#endif //TP2_MENU_H
