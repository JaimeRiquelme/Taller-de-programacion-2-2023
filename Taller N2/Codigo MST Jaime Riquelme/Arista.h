#pragma once
#include "Nodo.h"

class Arista
{

    // Atributos de la clase Arista
private:
    Nodo *origen;
    Nodo *destino;
    int peso;

    // Metodos de la clase Arista
public:
    Arista(Nodo *origen, Nodo *destino, int peso);
    ~Arista();
    Nodo *getOrigen();
    Nodo *getDestino();
    int getPeso();
    void setOrigen(Nodo *origen);
    void setDestino(Nodo *destino);
    void setPeso(int peso);
};