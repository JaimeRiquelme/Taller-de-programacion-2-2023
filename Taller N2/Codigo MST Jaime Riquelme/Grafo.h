#include <vector>
#include <queue>
#include <unordered_map>
#include "Arista.h"
#include "Comparador.h"

class Grafo
{

private:
    // atributos
    int numeroNodos;
    int numeroAristas;
    int numeroAristasrevisadas;

public:
    // metodos
    int getNumeroNodos();
    int getNumeroAristas();
    int getNumeroAristasRevisadas();
    std::priority_queue<Arista *, std::vector<Arista *>, Comparador> aristas;
    void agregarArista(Nodo *origen, Nodo *destino, int peso);
    int getMatrizAdyacencia(char *nombreArchivo);
    std::vector<std::vector<int>> matrizAdyacencia;
    void imprimirAristas();
    void agregarAristas();
    void kruskal();
    std::unordered_map<int, Nodo *> nodos;
    int BuscarPadre(int nodoId);
    void UnirNodos(int a, int b);
    ~Grafo();
};
