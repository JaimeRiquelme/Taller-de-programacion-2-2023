#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include "Operacion.h"
#include "Vector.h"
#include "Estado.h"

class Tablero{
    public:
        Tablero(int Largo); // Constructor de un tablero
        ~Tablero(); // Destructor de un tablero
        Auto* operarauto(Auto* auto_); // Funcion para operar un auto 
        Estado* resolver(Estado* estadoinicial); // Funcion para resolver el problema 
        Vector* copiarVectorProfundamente(Vector* original); // Funcion para copiar un vector profundamente 
        void llenarTablero(Vector* autos); // Funcion para llenar el tablero con los autos del vector de autos
        void vaciarTablero(); // Funcion para vaciar el tablero
        void MostarTablero(); // Funcion para mostrar el tablero
        void setParedes(int** paredes); // Funcion para setear las paredes
        void mostrarParedes(); // Funcion para mostrar las paredes
        
    private:
        int Largo; // Largo del tablero
        int** tablero; // Tablero
        int** paredes; // Paredes
        Operacion operaciones[7]; // Operaciones   
};

#endif
