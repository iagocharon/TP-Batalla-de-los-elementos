#ifndef Casillero_hpp
#define Casillero_hpp

#include <iostream>



using namespace std;

class Casillero {
private:
    int costoTierra;
    int costoAire;
    int costoAgua;
    int costoFuego;
    string nombre;
    int fila;
    int columna;
public:

    // PRE: -
    // POS: Devuelve el atrubuto nombre.
    string getNombre();

    // PRE: -
    // POS: Devuelve el atrubuto costoTierra.
    int getCostoTierra();

    // PRE: -
    // POS: Devuelve el atrubuto costoAire.
    int getCostoAire();

    // PRE: -
    // POS: Devuelve el atrubuto costoAgua.
    int getCostoAgua();

    // PRE: -
    // POS: Devuelve el atrubuto costoFuego.
    int getCostoFuego();

    // PRE: -
    // POS: Devuelve el atrubuto fila.
    int getFila();

    // PRE: -
    // POS: Devuelve el atrubuto columna.
    int getColumna();

    // PRE: Recibe un string con el nombre al cual cambiar
    // POS: Cambia el atributo nombre por el que se le paso por parametro.
    void setNombre(string nombre);

    // PRE: Recibe un int con el costo al cual cambiar
    // POS: Cambia el atributo costoTierra por el que se le paso por parametro.
    void setCostoTierra(int costo);

    // PRE: Recibe un int con el costo al cual cambiar
    // POS: Cambia el atributo costoAire por el que se le paso por parametro.
    void setCostoAire(int costo);

    // PRE: Recibe un int con el costo al cual cambiar
    // POS: Cambia el atributo costoAgua por el que se le paso por parametro.
    void setCostoAgua(int costo);

    // PRE: Recibe un int con el costo al cual cambiar
    // POS: Cambia el atributo costoFuego por el que se le paso por parametro.
    void setCostoFuego(int costo);

    // PRE: Recibe un string con el nombre al cual cambiar
    // POS: Cambia el atributo nombre por el que se le paso por parametro.
    void setFila(int fila);

    // PRE: Recibe un string con el nombre al cual cambiar
    // POS: Cambia el atributo nombre por el que se le paso por parametro.
    void setColumna(int columna);
    
};

class CasilleroMontania : public Casillero {
public :
    CasilleroMontania();
};

class CasilleroPrecipicio : public Casillero {
public :
    CasilleroPrecipicio();
};

class CasilleroLago : public Casillero {
public :
    CasilleroLago();
};

class CasilleroVolcan : public Casillero {
public :
    CasilleroVolcan();
};

class CasilleroCamino : public Casillero {
public :
    CasilleroCamino();
};

class CasilleroVacio : public Casillero {
public :
    CasilleroVacio();
};


#endif /* Casillero_hpp */
