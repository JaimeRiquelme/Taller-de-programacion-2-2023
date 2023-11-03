#include "Heap.h"

int main()
{
    Vector *autos = new Vector(10);

    //Creamos autos cualquieras
    autos->push(new Auto(1, 4, 2, 2, HORIZONTAL));
    autos->push(new Auto(2, 0, 0, 2, VERTICAL));
    autos->push(new Auto(3, 0, 3, 2, VERTICAL));
    autos->push(new Auto(4, 1, 0, 2, HORIZONTAL));
    autos->push(new Auto(5, 1, 3, 2, HORIZONTAL));
    autos->push(new Auto(6, 3, 0, 2, VERTICAL));
    autos->push(new Auto(7, 3, 3, 2, VERTICAL));
    autos->push(new Auto(8, 4, 0, 2, HORIZONTAL));
    autos->push(new Auto(9, 4, 3, 2, HORIZONTAL));

    //Creamos el estado inicial

    Estado *inicial = new Estado(autos, nullptr, 0);
    inicial->mostrarEstado();
    inicial->heuristica = 4; //ingresamos cualquier valor a su heuristica

    //Creamos el estado 1
    Estado *estado1 = new Estado(autos, nullptr, 0);
    estado1->mostrarEstado();
    estado1->heuristica = 8;

    //Creamos el estado 2
    Estado *estado2 = new Estado(autos, nullptr, 0);
    estado2->mostrarEstado();
    estado2->heuristica = 5;

    //Creamos el estado 3
    Estado *estado3 = new Estado(autos, nullptr, 0);
    estado3->mostrarEstado();
    estado3->heuristica = 32;

    //Creamos el estado 4
    Estado *estado4 = new Estado(autos, nullptr, 0);
    estado4->mostrarEstado();
    estado4->heuristica = 3;

    //Creamos la cola de prioridad
    Heap colaPrioridad(10);

    //Agregamos los estados a la cola de prioridad

    colaPrioridad.push(inicial);
    colaPrioridad.push(estado1);
    colaPrioridad.push(estado2);
    colaPrioridad.push(estado3);
    colaPrioridad.push(estado4);

    //Mostramos la cola de prioridad
    //voy obteniendo los estados de la cola de prioridad y los muestro del mejor al peor estado dado su heuristica, es decir, el estado con menor heuristica es el mejor estado.
    cout << "Cola de prioridad" << endl;
    while (!colaPrioridad.isEmpty())
    {
        Estado *estado = colaPrioridad.pop();
        cout << estado->heuristica << endl;
    }
    

    return 0;
}