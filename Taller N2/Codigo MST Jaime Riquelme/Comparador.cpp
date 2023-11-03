#include "Comparador.h"

/*
Esta clase es un comparador de aristas para la cola de prioridad de aristas del grafo
*/


// entrada: Arista* a, Arista* b
// salida: bool
// descripcion: compara dos aristas y retorna true si el peso de la arista a es mayor que el peso de la arista b
bool Comparador::operator()(Arista *a, Arista *b)
{
    return a->getPeso() > b->getPeso();
}

// entrada: -
// salida: -
// descripcion: constructor de la clase
Comparador::~Comparador()
{
}