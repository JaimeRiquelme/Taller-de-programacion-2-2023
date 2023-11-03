#ifndef COMPARADOR_H
#define COMPARADOR_H

#include "Arista.h"

class Comparador
{
public:
    bool operator()(Arista *a, Arista *b);
    ~Comparador();
};

#endif // COMPARADOR_H