#include "Nodo.h"
#include <iostream>

/*
Clase test para la clase Nodo
*/

int main()
{
    //Creacion de nodos
    Nodo *nodo = new Nodo(5);
    Nodo *nodo2 = new Nodo(6);
    Nodo *nodo3 = new Nodo(7);

    //Impresion de id de nodos
    printf("Nodo id: %d\n", nodo->getid());
    printf("Nodo id: %d\n", nodo2->getid());
    printf("Nodo id: %d\n", nodo3->getid());

    return 0;
}