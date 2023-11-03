#include <iostream>
#include "Estado.h"


using namespace std;

class Heap {
    public:
    Estado **heap; // Aqui es doble puntero porque es un arreglo de punteros a Estado
    int size; // cuantos hay almacenado aqui
    int capacity; // cuantos caben aqui

    Heap(int capacity); // Constructor de un heap
    ~Heap(); // Destructor de un heap
    void push(Estado *state); // Funcion para insertar un estado en el heap
    Estado *pop();  // Funcion para obtener el estado con menor costo acumulado y heuristica
    bool isEmpty(); // Funcion para verificar si el heap esta vacio

    void swap(int i, int j);  // Funcion para intercambiar dos estados
    void bubbleUp(int index); // desde abajo asegura que el padre sea menor que el hijo 
    void heapify(int index); // desde arriba asegura que el padre sea menor que el hijo

    bool Contains(Estado *state); // Funcion para verificar si un estado esta en el heap

};