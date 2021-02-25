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

    // PRE: -
    // POS: Devuelve true si la bonificacion esta activada, false de otro modo
    bool getBonificacion();

    // PRE: -
    // POS: Cambia el estado de la bonificacion a lo pasado por parametro
    void setBonificacion(bool bonificacion);

    // PRE: -
    // POS: Notifica al usuario cómo fue alimentado el Personaje y aumenta la energía en AUMENTO_ENERGIA_TIERRA
    void alimentar();

    // PRE: Tiene energía suficiente.
    // POS: Realiza un ataque con las características del ataque tierra.
    void atacar(Personaje* enemigos[MAX_PERSONAJES]);

    // PRE: Tiene energía suficiente.
    // POS: Obtiene 2 puntos de escudo y activa la bonificación del mismo si este supera
    //      BONIFICACION_ESCUDO_TIERRA.
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
    
    ~ElementalTierra();
};


#endif //TP2_ELEMENTALTIERRA_H
