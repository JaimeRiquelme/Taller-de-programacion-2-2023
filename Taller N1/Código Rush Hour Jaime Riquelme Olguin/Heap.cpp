#include "Heap.h"

//Contructor de un heap
Heap::Heap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->heap = new Estado*[capacity];
}

//Destructor de un heap
Heap::~Heap() {
    for (int i=0; i<this->size; i++) {
        delete this->heap[i];
    }
    delete[] this->heap;
}

// Funcion para intercambiar dos estados
void Heap::swap(int i, int j) {
    Estado *temp = this->heap[i];
    this->heap[i] = this->heap[j];
    this->heap[j] = temp;
}

// Funcion para obtener el estado con menor costo acumulado y heuristica
Estado * Heap::pop() {
    if (isEmpty()) { // Ojo retorna nulo si esta vacio
        return nullptr;
    }
    Estado *state = this->heap[0]; // tomo la raiz
    this->heap[0] = this->heap[this->size-1]; // pongo el ultimo en la raiz
    this->size--; // reduzco el size
    this->heapify(0); // burbujea hacia abajo intercambiando con el menor de los hijos
    return state;
}

// Funcion para burbuajear hacia abajo intercambiando con el menor de los hijos
void Heap::heapify(int index) {
    int left = 2*index+1;
    int right = 2*index+2;
    int smallest = index;
    if (left < this->size && (this->heap[left]->heuristica) < (this->heap[smallest]->heuristica)) {
        smallest = left;
    }
    if (right < this->size && (this->heap[right]->heuristica) < (this->heap[smallest]->heuristica)) {
        smallest = right;
    }
    if (smallest != index) {
        this->swap(index, smallest); // smallest va ser el hijo menor de ambos
        this->heapify(smallest);
    }
}

// Funcion para insertar un estado en el heap
void Heap::push(Estado *state) {
    if (this->size == this->capacity) {
        Estado **temp = new Estado*[this->capacity*2];
        for (int i=0; i<this->size; i++) {
            temp[i] = this->heap[i];
        }
        delete[] this->heap;
        this->heap = temp;
        this->capacity *= 2;
    }
    this->heap[this->size] = state; // lo pongo al final
    this->bubbleUp(this->size); // burbujea hacia arriba intercambiando con el padre
    this->size++; // aumento el size
}

// Funcion para burbuajear hacia arriba intercambiando con el padre
void Heap::bubbleUp(int index) {
    int parent = (index-1)/2;
    if (parent >= 0 && (this->heap[index]->heuristica) < (this->heap[parent]->heuristica)) {
        this->swap(index, parent); // caso que no se cumple padre < hijo
        this->bubbleUp(parent);
    }
}

// Funcion para verificar si el heap esta vacio
bool Heap::isEmpty() {
    return this->size == 0;
}   

// Funcion para verificar si el heap contiene un estado
bool Heap::Contains(Estado *state){
    for (int i = 0; i < this->size; i++)
    {
        if (this->heap[i]->toString() == state->toString())
        {
            return true;
        }
        
    }
    return false;
    
}