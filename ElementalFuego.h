#ifndef TP2_ELEMENTALFUEGO_H
#define TP2_ELEMENTALFUEGO_H

#include <iostream>
#include "Personaje.h"

using namespace std;

#define AUMENTO_ENERGIA_FUEGO 15
#define ENERGIA_ATAQUE_FUEGO 5
#define DANIO_FUEGO 20
#define MODIFICADOR_FUEGO 10
#define ENERGIA_DEFENSA_FUEGO 10
#define RECUPERACION_FUEGO 10

class ElementalFuego: public Personaje{
public:
    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalFuego cargando sus atributos
    ElementalFuego(string nombre, string elemento, int escudo, int vida);

    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalFuego cargando sus atributos (se utiliza al cargar partida);
    ElementalFuego(string nombre, string elemento, int escudo, int vida, int energia, int fila, int columna);

    // PRE: -
    // POS: Notifica al usuario cómo fue alimentado el Personaje y aumenta la energía en AUMENTO_ENERGIA_FUEGO
    void alimentar();

    void atacar(Personaje* enemigos[MAX_PERSONAJES]);

    void defender(Personaje* aliados[MAX_PERSONAJES]);
};


#endif //TP2_ELEMENTALFUEGO_H
