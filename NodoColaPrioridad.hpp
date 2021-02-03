#ifndef NodoColaPrioridad_hpp
#define NodoColaPrioridad_hpp

#include <iostream>
#include "DatosGrafo.hpp"

class NodoColaPrioridad {
private:
    Vertice* vertice;
    int prioridad;
    int pesoAgua;
    int pesoAire;
    int pesoFuego;
    int pesoTierra;
    NodoColaPrioridad* siguiente;
    
public:
    NodoColaPrioridad(Vertice* vertice, int prioridad, int pesoAgua, int pesoAire, int pesoFuego, int pesoTierra);
    
    Vertice* getVertice();
    int getPrioridad();
    int getPesoAgua();
    int getPesoAire();
    int getPesoFuego();
    int getPesoTierra();
    NodoColaPrioridad* getSiguiente();
    
    void setVertice(Vertice* vertice);
    void setPrioridad(int prioridad);
    void setPesoAgua(int pesoAgua);
    void setPesoAire(int pesoAire);
    void setPesoFuego(int pesoFuego);
    void setPesoTierra(int pesoTierra);
    void setSiguiente(NodoColaPrioridad* siguiente);
    
    ~NodoColaPrioridad();

};

#endif /* NodoColaPrioridad_hpp */
