#include <fstream>
#include <iostream>
#include <sstream>
#include "Grafo.h"
#include "Arista.h"
using namespace std;


/*
Clase que contiene el grafo y metodos que permiten obtener el MST del grafo
*/

// Entrada: Nodo origen, Nodo destino, int peso
// Salida: -
// Descripcion: Agrega una arista al grafo

void Grafo::agregarArista(Nodo *origen, Nodo *destino, int peso)
{
    Arista *arista = new Arista(origen, destino, peso);
    this->aristas.push(arista);

    // Actualizar el mapa de nodos y establecer el padre
    int idOrigen = origen->getid();
    int idDestino = destino->getid();
    nodos[idOrigen] = origen;
    nodos[idDestino] = destino;

    origen->setPadre(idOrigen);
    destino->setPadre(idDestino);
}

// Entrada: -
// Salida: -
// Descripcion: Destructor de la clase Grafo
Grafo::~Grafo()
{
    while (!this->aristas.empty())
    {
        Arista *arista = this->aristas.top();
        this->aristas.pop();
        delete arista;
    }
    for (auto &nodo : nodos)
    {
        delete nodo.second;
    }
}

// Entrada: -
// Salida: -
// Descripcion: obtiene la matriz de adyacencia del archivo input.txt
int Grafo::getMatrizAdyacencia(char *nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo";
        return 1;
    }

    // Leer el archivo y guardar la matriz de adyacencia
    string linea;
    while (getline(archivo, linea))
    {
        vector<int> fila;
        istringstream iss(linea);
        int numero;
        while (iss >> numero)
        {
            fila.push_back(numero);
        }

        this->matrizAdyacencia.push_back(fila);
    }

    this->numeroNodos = this->matrizAdyacencia.size();
    int numeroAristas = 0;

    // Agregar las aristas al grafo
    for (int i = 0; i < numeroNodos; ++i)
    {
        for (int j = i + 1; j < numeroNodos; ++j)
        {
            Nodo *origen = new Nodo(i);
            Nodo *destino = new Nodo(j);
            this->agregarArista(origen, destino, this->matrizAdyacencia[i][j]);
            numeroAristas++;
            // Arista *arista = new Arista(new Nodo(i), new Nodo(j), this->matrizAdyacencia[i][j]);
        }
    }
    this->numeroAristas = numeroAristas;
    return 0;
}

// Entrada: nodo id
// Salida: nodo padre
// Descripcion: encuentra el padre del nodo

int Grafo::BuscarPadre(int nodoId)
{
    Nodo *nodo = nodos[nodoId];
    if (nodo->getPadre() == nodoId)
    { // Si el padre del nodo es el mismo nodo, se retorna el nodo
        return nodoId;
    }
    nodo->setPadre(BuscarPadre(nodo->getPadre()));
    return nodo->getPadre();
}

// Entrada: nodo a, nodo b
// Salida: -
// Descripcion: une los nodos a y b

void Grafo::UnirNodos(int a, int b)
{
    a = BuscarPadre(a);
    b = BuscarPadre(b);
    if (a != b)
    { // Si los padres son diferentes, se cambia el padre del nodo a
        nodos[a]->setPadre(b);
    }
}

// Entrada: -
// Salida: Aristas del grafo impresas en consola
// Descripcion: Funcion para obtener el MST del grafo

void Grafo::kruskal()
{
    int pesoTotal = 0;
    int NumeroAristas = 0;
    int NumeroAristasRevisadas = 0;

    while (!this->aristas.empty() && NumeroAristas < this->numeroNodos - 1)
    { // Mientras no se hayan revisado todas las aristas y no se hayan agregado todas las aristas
        NumeroAristasRevisadas++;
        Arista *arista = this->aristas.top();
        this->aristas.pop();

        int origen = BuscarPadre(arista->getOrigen()->getid());   // Buscar el padre del nodo origen
        int destino = BuscarPadre(arista->getDestino()->getid()); // Buscar el padre del nodo destino
        if (origen != destino)
        { // Si los padres son diferentes, se agrega la arista
            NumeroAristas++;
            UnirNodos(origen, destino);
            cout << "Origen: " << arista->getOrigen()->getid() << " Destino: " << arista->getDestino()->getid() << " Peso: " << arista->getPeso() << "\n";
            pesoTotal += arista->getPeso();
        }
    }
    this->numeroAristasrevisadas = NumeroAristasRevisadas;
    cout << "Peso total: " << pesoTotal << "\n";
}

// Entrada: -
// Salida: numero de nodos
// Descripcion: obtiene las aristas del grafo
int ::Grafo::getNumeroNodos()
{
    return this->numeroNodos;
}

// Entrada: -
// Salida: numero de aristas
// Descripcion: obtiene las aristas del grafo

int ::Grafo::getNumeroAristas()
{
    return this->numeroAristas;
}

// Entrada: -
// Salida: numero de aristas revisadas
// Descripcion: obtiene las aristas del grafo

int ::Grafo::getNumeroAristasRevisadas()
{
    return this->numeroAristasrevisadas;
}