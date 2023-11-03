#include <queue>
#include <iostream>
#include "Comparador.h"
#include "Arista.h"
#include "Nodo.h"
#include "Grafo.h"

/*
Class test para la clase Comparador
*/

int main(){
    //Creacion del grafo
    Grafo* grafo = new Grafo();

    //Creacion de nodos
    Nodo* nodo1 = new Nodo(1);
    Nodo* nodo2 = new Nodo(2);
    grafo->agregarArista(nodo1, nodo2, 8); //Agrega una arista al grafo
    

    Nodo* nodo3 = new Nodo(3);
    Nodo* nodo4 = new Nodo(4);
    grafo->agregarArista(nodo3, nodo4, 33); //Agrega una arista al grafo

    Nodo* nodo5 = new Nodo(5);
    Nodo* nodo6 = new Nodo(6);
    grafo->agregarArista(nodo5, nodo6, 1); //Agrega una arista al grafo
    
    Nodo* nodo7 = new Nodo(7);
    Nodo* nodo8 = new Nodo(8);
    grafo->agregarArista(nodo7, nodo8, 21);//Agrega una arista al grafo

    while (!grafo->aristas.empty()) //Imprime las aristas del grafo en orden de menor a mayor, segun el peso de la arista.
    {
        Arista *arista = grafo->aristas.top();
        grafo->aristas.pop();
        std::cout << arista->getPeso() << std::endl;
    }

    


    return 0;
}