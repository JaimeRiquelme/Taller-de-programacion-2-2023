#ifndef VECTORSTRING_H
#define VECTORSTRING_H

#include <string>

class VectorString {
public:
    // Constructor que inicializa el vector con una capacidad dada
    VectorString(int capacidad);

    // Destructor que libera la memoria asignada al vector
    ~VectorString();

    // Método para agregar un string al vector
    void push(const std::string& str);

    // Método para determinar si el vector está vacío
    bool isEmpty();

    // Método para imprimir todos los strings en el vector
    void printVector();

    // Método para verificar si un string específico está en el vector
    bool contains(const std::string& str);

    // Método para obtener un string en una posición específica
    std::string get(int index);

private:
    std::string* vector; // Puntero al array dinámico que contiene los strings
    int capacidad;       // Capacidad actual del vector
    int tope;            // Índice del último elemento en el vector
};

#endif // VECTOR_H
