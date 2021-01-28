#ifndef Vertice_hpp
#define Vertice_hpp

#include <iostream>
#include "Arista.hpp"

class Vertice {
private:
    Vertice* siguiente;
    Arista* arista;
    string nombre;
    
public:
    Vertice(string nombre);
    
    Vertice* getSiguiente();
    Arista* getArista();
    string getNombre();
    
    void setSiguiente(Vertice* siguiente);
    void setArista(Arista* arista);
    void setNombre(string nombre);
    void eliminarArista(Arista* aEliminar);
    void agregarArista(Arista* nueva);
    
    ~Vertice();
};
#endif /* Vertice_hpp */
