#ifndef TP2_ELEMENTALAIRE_H
#define TP2_ELEMENTALAIRE_H

#include <iostream>
#include "Personaje.h"

#define ENERGIA_ATAQUE_AIRE 8
#define DANIO_AIRE 15
#define ENERGIA_DEFENSA_AIRE 15
#define MODIFICADOR_AIRE 5

using namespace std;

class ElementalAire: public Personaje{
public:
      // PRE: Los parámetros recibidos son válidos
      // POS: Crea un ElementalAire cargando sus atributos
      ElementalAire(string nombre, string elemento, int escudo, int vida);

    // PRE: Los parámetros recibidos son válidos
    // POS: Crea un ElementalFuego cargando sus atributos (se utiliza al cargar partida);
    ElementalAire(string nombre, string elemento, int escudo, int vida, int energia, int fila, int columna);

    // PRE: -
    // POS: Notifica al usuario el estado de la alimentación del personaje
    void alimentar();

    // PRE: -
    // POS: Realiza un ataque con las características del ataque aire si tiene energia suficiente,
    //      sino notifica al ususario que no es posible efectuar el mismo
    void atacar(Personaje* enemigos[MAX_PERSONAJES]);

    // PRE: -
    // POS: Se desplaza a la posición deseada en el tablero elegida por el usuario en caso de
    //      tener energia >= ENERGIA_DEFENSA_AIRE, de otro modo notifica al usuario la
    //      imposibilidad de defenderse
    void defender(Personaje* aliados[MAX_PERSONAJES]);

    // PRE: -
    // POS: devuelve true si la energia es suficiente para realizar su ataque
    bool energiaNecesariaAtaque();

    // PRE: -
    // POS: devuelve true si la energia es suficiente para realizar su defensa
    bool energiaNecesariaDefensa();
};


#endif //TP2_ELEMENTALAIRE_H
