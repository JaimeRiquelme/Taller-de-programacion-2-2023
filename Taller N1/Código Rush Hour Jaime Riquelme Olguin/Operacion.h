#pragma once
#ifndef OPERACION_H
#define OPERACION_H
#define HORIZONTAL 0
#define VERTICAL 1
class Auto;
class Operacion{
    public:
        int direccion; // Direccion de la operacion
        int paso; // Paso de la operacion
        Operacion(int direccion, int paso); // Contructor de una operacion
        Operacion(); // Contructor de una operacion
        ~Operacion(); // Destructor de una operacion
        void printOperacion(); // Funcion para mostrar una operacion 
        Auto* operar(Auto *auto_); // Funcion para operar un auto
};

#endif