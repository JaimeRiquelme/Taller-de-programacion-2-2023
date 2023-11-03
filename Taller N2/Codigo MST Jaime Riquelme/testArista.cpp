#include "Nodo.h"
#include "Arista.h"
#include <iostream>

/*
Clase test para la clase Arista

*/

int main()
{
    //Creacion de nodos
    Nodo *nodo = new Nodo(5);
    Nodo *nodo2 = new Nodo(6);

    Arista *arista = new Arista(nodo, nodo2, 10); //Crea una arista con origen nodo y destino nodo2 y peso 10

    //Impresion de arista
    std::cout << "Arista origen: " << arista->getOrigen()->getid() << " | Arista destino: " << arista->getDestino()->getid() << " | Arista peso: " << arista->getPeso() << "\n";

    return 0;
}