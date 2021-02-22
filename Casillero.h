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

    // PRE:
    // POS:
    string getNombre();

    // PRE:
    // POS:
    int getCostoTierra();

    // PRE:
    // POS:
    int getCostoAire();

    // PRE:
    // POS:
    int getCostoAgua();

    // PRE:
    // POS:
    int getCostoFuego();

    // PRE:
    // POS:
    int getFila();

    // PRE:
    // POS:
    int getColumna();

    // PRE:
    // POS:
    void setNombre(string nombre);

    // PRE:
    // POS:
    void setCostoTierra(int costo);

    // PRE:
    // POS:
    void setCostoAire(int costo);

    // PRE:
    // POS:
    void setCostoAgua(int costo);

    // PRE:
    // POS:
    void setCostoFuego(int costo);

    // PRE:
    // POS:
    void setFila(int fila);

    // PRE:
    // POS:
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
