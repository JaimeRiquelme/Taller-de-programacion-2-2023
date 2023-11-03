#ifndef ESTADO_H
#define ESTADO_H
#include <iostream>
#include "Vector.h"
#include "Operacion.h"


class Estado{
    public:
        Estado(Vector *autos, Operacion *Op, Estado *padre, Auto* automoviendose); // Constructor de un estado
        Estado(Vector *autos, Operacion *Op, int idAuto); // Constructor de un estado 
        ~Estado(); // Destructor de un estado
        void mostrarEstado(); // Funcion para mostrar un estado
        bool esSolucion(); // Funcion para verificar si un estado es solucion
        int CalcularHeuristica() const; // Funcion para calcular la heuristica de un estado
        Vector* getAutos() const; // Funcion para obtener los autos de un estado
        void mostrartablero(); // Funcion para mostrar el tablero de un estado
        void mostrarsolucion(); // Funcion para mostrar la solucion de un estado

        

    //private:
        Vector *autos; // Vector de autos
        Operacion *Op; // Operacion que se realizo para llegar a este estado
        Estado *padre;  // Padre de este estado
        Auto* automoviendose; // Auto que se esta moviendo en este estado
        int heuristica; // Costo acumulado de este estado
        //int heuristica; // Heuristica de este estado    
        std::string toString() const; // Funcion para convertir un estado a string
};

#endif // ESTADO_H