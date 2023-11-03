#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include "Auto.h"
#include <sstream>

class Vector{
    public:
        Vector(int capacidad); // Contructor de un vector
        ~Vector(); // Destructor de un vector

        void push(Auto* auto_);  // Funcion para agregar un auto al vector
        bool isEmpty();  // Funcion saber si el vector esta vacio
        void printVector(); // Funcion mostrar el vector
        bool contains(int id, int x , int y,int largo, int direccion); // Funcion para saber si un auto esta en el vector
        Auto* buscarPorId(int id); // Funcion para buscar un auto por su id
        void remplazar(Auto* autoNuevo); // Funcion para remplazar un auto en el vector
    // private:
        int capacidad; // Capacidad del vector
        int tope; // Tope del vector
        Auto** vector; // Vector de autos
};

#endif