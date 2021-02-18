#ifndef ColaPrioridad_hpp
#define ColaPrioridad_hpp

#include <iostream>
#include "NodoColaPrioridad.h"

#define ORDEN_AGUA 1
#define ORDEN_AIRE 2
#define ORDEN_FUEGO 3
#define ORDEN_TIERRA 4

class ColaPrioridad {
private:
    NodoColaPrioridad* primero;
    NodoColaPrioridad* primeroSegunPrioridad;
    NodoColaPrioridad* ultimo;
    int criterioOrden;
    
    bool ordenPorAgua();
    bool ordenPorAire();
    bool ordenPorFuego();
    bool ordenPorTierra();
    void actualizarPrioridad(NodoColaPrioridad* aInsertar);
    void insertarAlFinal(NodoColaPrioridad* aInsertar);
    void insertarNuevoEnPrioridad(NodoColaPrioridad* aInsertar);
    void insertarOrdenado(NodoColaPrioridad* aInsertar);
    void insertarElemento(NodoColaPrioridad* aInsertar);
    
public:
    ColaPrioridad(int criterioOrden);
    
    bool vacia();
    int topPesoAgua();
    int topPesoAire();
    int topPesoFuego();
    int topPesoTierra();
    int topPrioridad();
    void push(Vertice* evaluado, int pesoAgua, int pesoAire, int pesoFuego, int pesoTierra, int iteracion);
    void pop();
    Vertice* topAndPop();
    
    ~ColaPrioridad();
};

#endif /* ColaPrioridad_hpp */
