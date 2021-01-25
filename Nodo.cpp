//
// Created by daniel on 24/11/20.
//

#include "Nodo.h"
#include <iostream>

Nodo::Nodo(){
    dato = nullptr;
    siguiente = nullptr;
}


Nodo::Nodo(Tipo dato){

    this -> dato = dato;

    siguiente = nullptr;
}

Tipo Nodo::obtenerDato(){

    return dato;
}

Nodo* Nodo::obtenerSiguiente(){
    return siguiente;
}

/*void Nodo::asignarDato(Tipo dato){
    this -> dato = dato;
}
*/
void Nodo::asignarSiguiente(Nodo* siguiente){
    this -> siguiente = siguiente;
}

Nodo::~Nodo(){
    delete dato;
}

/*
bool Nodo::haySiguiente(){
    return (obtenerSiguiente() != 0);
}
*/