#include "Grafo.h"
#include "Nodo.h"
#include "Arista.h"
#include <stdio.h>

/*
Clase test para la clase Grafo
*/

int main()
{
    //Creacion de nodos
    Nodo *nodo = new Nodo(5);
    printf("Nodo 1: %d\n", nodo->getid());
    Grafo *grafo = new Grafo();
    grafo->agregarArista(nodo, nodo, 8); //Agrega una arista al grafo

    Nodo *nodo2 = new Nodo(6);
    printf("Nodo 2: %d\n", nodo2->getid());
    grafo->agregarArista(nodo2, nodo2, 1); //Agrega una arista al grafo

    Nodo *nodo3 = new Nodo(7);
    printf("Nodo 3: %d\n", nodo3->getid());
    grafo->agregarArista(nodo3, nodo3, 9); //Agrega una arista al grafo


    //Impresion de aristas
    printf("Arista origen: %d | Arista destino: %d | Arista peso: %d\n", grafo->aristas.top()->getOrigen()->getid(), grafo->aristas.top()->getDestino()->getid(), grafo->aristas.top()->getPeso());

    return 0;
}