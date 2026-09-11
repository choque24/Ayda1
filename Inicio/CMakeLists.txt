cmake_minimum_required(VERSION 4.1)
project(Inicio)

set(CMAKE_CXX_STANDARD 20)

    add_executable(Inicio main.cpp
            BusquedaBinariaMediana.cpp
            BusquedaBinariaMaximo.cpp
            BusquedaBinariaNLogN.cpp
            robotMatriz.cpp)
