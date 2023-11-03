#include "Arista.h"

// Entrada: Nodo* origen, Nodo* destino, int peso
// Salida: Arista
// Descripcion: Constructor de la clase Arista
Arista::Arista(Nodo *origen, Nodo *destino, int peso)
{
    this->origen = origen;
    this->destino = destino;
    this->peso = peso;
}

// Entrada: -
// Salida: -
// Descripcion: Destructor de la clase Arista
Arista::~Arista()
{
    delete this->origen;
    delete this->destino;
}

// Entrada: -
// Salida: Nodo*
// Descripcion: Retorna el nodo origen de la arista
Nodo *Arista::getOrigen()
{
    return this->origen;
}

// Entrada: -
// Salida: Nodo*
// Descripcion: Retorna el nodo destino de la arista
Nodo *Arista::getDestino()
{
    return this->destino;
}

// Entrada: -
// Salida: int
// Descripcion: Retorna el peso de la arista
int Arista::getPeso()
{
    return this->peso;
}

// Entrada: Nodo* origen
// Salida: -
// Descripcion: Cambia el nodo origen de la arista

void Arista::setOrigen(Nodo *origen)
{
    this->origen = origen;
}

// Entrada: Nodo* destino
// Salida: -
// Descripcion: Cambia el nodo destino de la arista

void Arista::setDestino(Nodo *destino)
{
    this->destino = destino;
}

// Entrada: int peso
// Salida: -
// Descripcion: Cambia el peso de la arista
void Arista::setPeso(int peso)
{
    this->peso = peso;
}
