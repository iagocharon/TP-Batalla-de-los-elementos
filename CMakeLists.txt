cmake_minimum_required(VERSION 3.16.5)
project(BDE)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BDE
        ABB.cpp
        ABB.hpp
        ArchivoPersonajes.cpp
        ArchivoPersonajes.h
        Casillero.cpp
        Casillero.h
        DatosGrafo.cpp
        DatosGrafo.h
        ElementalAgua.cpp
        ElementalAgua.h
        ElementalAire.cpp
        ElementalAire.h
        ElementalFuego.cpp
        ElementalFuego.h
        ElementalTierra.cpp
        ElementalTierra.h
        Grafo.cpp
        Grafo.h
        Juego.cpp
        Juego.h
        Jugador.cpp
        Jugador.h
        main.cpp
        MenuInicio.cpp
        MenuInicio.h
        MenuSeleccion.cpp
        MenuSeleccion.h
        NodoABB.cpp
        NodoABB.h
        Personaje.cpp
        Personaje.h
        Tablero.cpp
        Tablero.h
        Utiles.cpp
        Utiles.h MenuJuego.cpp MenuJuego.h Jugar.cpp Jugar.h)
