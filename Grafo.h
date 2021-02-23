#ifndef Grafo_hpp
#define Grafo_hpp

#include <iostream>
#include <list>
#include "DatosGrafo.h"
#include "Casillero.h"

#define CRITERIO_AGUA 1
#define CRITERIO_AIRE 2
#define CRITERIO_FUEGO 3
#define CRITERIO_TIERRA 4
#define INFINITO 99999

using namespace std;

class Grafo {
private:
    Vertice* primero;
    Vertice* ultimo;
    int criterioBusqueda; //1-Agua, 2-Aire, 3-Fuego, 4-Tierra.
    int tamanio;
    
public:
    // COSNTRUCTOR
    // PRE: -
    // POS: Crea un objeto de clase grafo, incializando los atributos.
    Grafo();

    // PRE: -
    // POS: Devuelve el atributo primero.
    Vertice* getPrimero();

    // PRE: -
    // POS: Devuelve el atributo ultimo.
    Vertice* getUltimo();

    // PRE: -
    // POS: Devuelve el atributo criterioBusqueda.
    int getCriterioBusqueda();

    // PRE: -
    // POS: Devuelve el atributo tamanio.
    int getTamanio();

    // PRE: Recibe dos int con las coordenadas del vertice buscado.
    // POS: Devuelve el vertice en esas coordenadas.
    Vertice* getVertice(int fila, int columna);

    // PRE: Recibe un int con la posicion del vertice dentro del conjunto de estos.
    // POS: Devuelve el vertice en esa posicion.
    Vertice* getVertice(int posicion);

    // PRE: Recibe dos vertices bien inicializados.
    // POS: Devuelve la arista que une los dos vertices
    //      Si no existe arista que los una, devuelve NULL
    Arista* getArista(Vertice* salida, Vertice* destino);

    // PRE: Recibe dos vertices que tengan una arista que los una.
    // POS: Devuelve la distancia entre las dos segun el criterio de busqueda.
    int getDistancia(Vertice* salida, Vertice* destino);

    // PRE: Recibe un vertice bien inicializado.
    // POS: Partiendo del primero, devuelve la posicion en la que se encuentra dentro del conjunto de vertices.
    int getNumeroVertice(Vertice* vertice);

    // PRE: Recibe un objeto vertice para asignar a primero.
    // POS: Asigna el atributo.
    void setPrimero(Vertice* primero);

    // PRE: Recibe un objeto vertice para asignar a ultimo.
    // POS: Asigna el atributo.
    void setUltimo(Vertice* ultimo);

    // PRE: Recibe un int para asignar a criterioBusqueda.
    // POS: Asigna el atributo.
    void setCriterioBusqueda(int criterioBusqueda);

    // PRE: Recibe un int para asignar a tamanio.
    // POS: Asigna el atributo.
    void setTamanio(int tamanio);

    // PRE: Recibe un vertice, un vector para almacenar los sucesores y un int para almacenar la cantidad de sucesores.
    // POS: Almacena la informacion de los sucesores en el vector y almacena la cantidad en la variable que corresponde.
    void setSucesores(Vertice* vertice, Vertice* sucesores[], int* cantidadSucesores);

    // PRE: Recibe un casillero bien inicializado.
    // POS: Agrega un vertice con la informacion del casillero recibido por parametro.
    void agregarVertice(Casillero* casillero);

    // PRE: Recibe dos vertices, uno de salida y uno de destino.
    // POS: Crea una arista que una estos vertices y la agrega al grafo.
    void agregarArista(Vertice* salida, Vertice* destino);

    // PRE: Recibe dos vertices, uno de salida y uno de destino.
    // POS: Devuelve true si existe una arista que los una y false si no.
    bool existeArista(Vertice* salida, Vertice* destino);

    // PRE: Recibe un vector booleano.
    // POS: Devuelve true si todos los elementos del vector son true, si no, devuelve false.
    bool todosVistos(bool visitados[]);

    // PRE: Recibe un vector booleano y un vector de int, que representan para cada vertice si fue visitado o no, y la distancia desde el vertice de salida.
    // POS: Devuelve la posicion del vertice que no fue visitado que tiene menor distancia.
    int minimoNoVisitado(bool visitados[], int distancias[]);

    // PRE: Recibe una lista con el recorrido desde un vertice a otro.
    // POS: Muestra el recorrido.
    void mostrarLista(list<Vertice*> lista);

    // PRE: Recibe dos vertices, uno de salida y uno de destino.
    // POS: Devuelve la distancia minima entre dos vertices y mustra el recorrido.
    int caminoMinimo(Vertice* salida, Vertice* destino);

    // DESTRUCTOR
    // PRE: -
    // POS: Destruye el objeto.
    ~Grafo();
};

#endif /* Grafo_hpp */
