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

    // PRE: Tiene energía suficiente.
    // POS: Realiza un ataque con las características del ataque aire.
    void atacar(Personaje* enemigos[MAX_PERSONAJES]);

    // PRE: Tiene energía suficiente.
    // POS: Se desplaza a la posición deseada en el tablero elegida por el usuario.
    void defender(Personaje* aliados[MAX_PERSONAJES]);

    // PRE: -
    // POS: devuelve true si la energia es suficiente para realizar su ataque
    bool energiaNecesariaAtaque();

    // PRE: -
    // POS: devuelve true si la energia es suficiente para realizar su defensa
    bool energiaNecesariaDefensa();


    // PRE: -
    // POS: Muestra las características del elemental para las acciones del primer menú
    void caracteristicasPrimerMenu();

    // PRE: -
    // POS: Muestra las características del elemental para las acciones del segundo menú
    void caracteristicasSegundoMenu();
    
    ~ElementalAire();
};


#endif //TP2_ELEMENTALAIRE_H
