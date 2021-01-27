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
public:
    string getNombre();
    int getCostoTierra();
    int getCostoAire();
    int getCostoAgua();
    int getCostoFuego();
    void setNombre(string nombre);
    void setCostoTierra(int costo);
    void setCostoAire(int costo);
    void setCostoAgua(int costo);
    void setCostoFuego(int costo);
    
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
