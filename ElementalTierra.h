#ifndef TP2_ELEMENTALTIERRA_H
#define TP2_ELEMENTALTIERRA_H

#include <iostream>
#include "Personaje.h"

using namespace std;

#define AUMENTO_ENERGIA_TIERRA 8
#define ENERGIA_ATAQUE_TIERRA 6
#define DANIO_TIERRA_BASE 10
#define MODIFICADOR_TIERRA_AGUA 20
#define MODIFICADOR_TIERRA_AIRE 10
#define ENERGIA_DEFENSA_TIERRA 5
#define BONIFICACION_ESCUDO_TIERRA 2

class ElementalTierra: public Personaje{
private:
    bool bonificacion;
public:
    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalTierra cargando sus atributos
    ElementalTierra(string nombre,string elemento, int escudo, int vida);

    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalFuego cargando sus atributos (se utiliza al cargar partida);
    ElementalTierra(string nombre, string elemento, int escudo, int vida, int energia, int fila, int columna);

    bool getBonificacion();

    void setBonificacion(bool bonificacion);

    // PRE: -
    // POS: Notifica al usuario cómo fue alimentado el Personaje y aumenta la energía en AUMENTO_ENERGIA_TIERRA
    void alimentar();

    void atacar(Personaje* enemigos[MAX_PERSONAJES]);

    void defender(Personaje* aliados[MAX_PERSONAJES]);
};


#endif //TP2_ELEMENTALTIERRA_H
