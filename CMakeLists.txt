cmake_minimum_required(VERSION 3.17)
project(BDE)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BDE
        ABB.cpp
        ABB.hpp
        Accion.cpp
        Accion.h
        ArchivoPersonajes.cpp
        ArchivoPersonajes.h
        Casillero.cpp
        Casillero.hpp
        ColaPrioridad.cpp
        ColaPrioridad.hpp
        DatosGrafo.cpp
        DatosGrafo.hpp
        Ejecucion.cpp
        Ejecucion.h
        ElementalAgua.cpp
        ElementalAgua.h
        ElementalAire.cpp
        ElementalAire.h
        ElementalFuego.cpp
        ElementalFuego.h
        ElementalTierra.cpp
        ElementalTierra.h
        Etiqueta.cpp
        Etiqueta.hpp
        Grafo.cpp
        Grafo.hpp
        Juego.cpp
        Juego.h
        Jugador.cpp
        Jugador.h
        main.cpp
        Menu.cpp
        Menu.h
        MenuSeleccion.cpp
        MenuSeleccion.h
        NodoABB.cpp
        NodoABB.hpp
        NodoColaPrioridad.cpp
        NodoColaPrioridad.hpp
        Personaje.cpp
        Personaje.h
        Tablero.cpp
        Tablero.h
        Utiles.cpp
        Utiles.h MenuJuego.cpp MenuJuego.h Jugar.cpp Jugar.h)
