#ifndef Etiqueta_hpp
#define Etiqueta_hpp

#include <iostream>
#include <list>
#include "Vertice.hpp"

#define INFINITO 99999

using namespace std;

class Etiqueta {
private:
    Vertice* vertice;
    list<Vertice*> anterior;
    int pesoAguaAcumulado;
    int pesoAireAcumulado;
    int pesoFuegoAcumulado;
    int pesoTierraAcumulado;
    int iteracion;
    
public:
    Etiqueta(Vertice* actual);
    
    Vertice* getVertice();
    list<Vertice*> getAnterior();
    int getPesoAguaAcumulado();
    int getPesoAireAcumulado();
    int getPesoFuegoAcumulado();
    int getPesoTierraAcumulado();
    int getIteracion();
    
    void setVertice(Vertice* vertice);
    void setAnterior(list<Vertice*> anterior);
    void setPesoAguaAcumulado(int pesoAguaAcumulado);
    void setPesoAireAcumulado(int pesoAireAcumulado);
    void setPesoFuegoAcumulado(int pesoFuegoAcumulado);
    void setPesoTierraAcumulado(int pesoTierraAcumulado);
    void setIteracion(int iteracion);
    
    void sumoAnterior(Vertice* anterior);
    
    ~Etiqueta();
};

#endif /* Etiqueta_hpp */
