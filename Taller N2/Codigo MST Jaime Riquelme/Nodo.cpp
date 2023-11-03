#include "Nodo.h"

/*
Clase representativa de un nodo del grafo
*/

// Entrada: int id
// Salida: -
// Descripcion: constructor de la clase Nodo
Nodo::Nodo(int id)
{
    this->id = id;
}

// Entrada: -
// Salida: -
// Descripcion: destructor de la clase Nodo
Nodo::~Nodo()
{
}

// Entrada: -
// Salida: int
// Descripcion: retorna el id del nodo
int Nodo::getid()
{
    return this->id;
}

// Entrada: -
// Salida: int
// Descripcion: retorna el padre del nodo

int Nodo::getPadre()
{
    return this->padre;
}

// Entrada: int padre
// Salida: -
// Descripcion: cambia el padre del nodo
void Nodo::setPadre(int padre)
{
    this->padre = padre;
}