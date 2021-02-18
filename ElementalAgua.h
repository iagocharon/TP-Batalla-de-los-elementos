#ifndef TP2_ELEMENTALAGUA_H
#define TP2_ELEMENTALAGUA_H

#include <iostream>
#include "Personaje.h"
#include <vector>

#define AUMENTO_ENERGIA_AGUA 10
#define TOPE_ALIMENTACIONES 3
#define ENERGIA_ATAQUE_AGUA 5
#define ENERGIA_DEFENSA_AGUA 12
#define DANIO_AGUA 20
#define RECUPERACION_AGUA 50
#define RECUPERACION_ALIADOS_AGUA 10
#define MODIFICADOR_AGUA 10

using namespace std;

class ElementalAgua: public Personaje{
private:
    int vecesAlimentado;

public:
    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalAgua cargando sus atributos
    ElementalAgua(string nombre, string elemento, int escudo, int vida);

    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalFuego cargando sus atributos (se utiliza al cargar partida);
    ElementalAgua(string nombre, string elemento, int escudo, int vida, int energia, int fila, int columna);

    // PRE: -
    // POS: Notifica al usuario cómo fue alimentado el Personaje y aumenta la energía en AUMENTO_ENERGIA_AGUA
    //      En caso de ser efectuada la alimentación aumenta en 1 las vecesAlimentado
    void alimentar();

    void atacar(Personaje* enemigos[MAX_PERSONAJES]);

    void defender(Personaje* aliados[MAX_PERSONAJES]);
};

#endif //TP2_ELEMENTALAGUA_H
