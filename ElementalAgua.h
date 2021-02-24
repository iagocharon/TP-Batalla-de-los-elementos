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

    // PRE: Tiene energía suficiente.
    // POS: Realiza un ataque con las características del ataque agua.
    void atacar(Personaje* enemigos[MAX_PERSONAJES]);


    // PRE: Tiene energía suficiente.
    // POS: Se cura a si mismo y a sus aliados por RECUPERACION_AGUA y RECUPERACION_ALIADOS_AGUA
    //      respectivamente.
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
};

#endif //TP2_ELEMENTALAGUA_H
