#include <iostream>
#include <stdlib.h>
#include "Tablero.h"
#include "Auto.h"
#include "Estado.h"
#include "Heap.h"
#include "Vector.h"
#include "VectorString.h"
using namespace std;

#define HORIZONTAL 0
#define VERTICAL 1


//Contructor de un tablero
Tablero::Tablero(int Largo)
{
    this->Largo = Largo;
    this->tablero = new int *[Largo];
    for (int i = 0; i < Largo; ++i)
    {
        this->tablero[i] = new int[Largo];
    }
    for (int i = 0; i < Largo; ++i)
    {
        for (int j = 0; j < Largo; ++j)
        {
            this->tablero[i][j] = 0;
        }
    }

    // Creamos las operaciones disponibles para mover los autos
    this->operaciones[0] = Operacion(0, 1);
    this->operaciones[1] = Operacion(0, -1);
    this->operaciones[2] = Operacion (0,2);
    this->operaciones[3] = Operacion (0,-2);
    this->operaciones[4] = Operacion (0,3);
    this->operaciones[5] = Operacion (0,-3);
    this->operaciones[6] = Operacion (0,4);
    this->operaciones[7] = Operacion (0,-4);

}

//Destructor de un tablero
Tablero::~Tablero()
{
    for (int i = 0; i < this->Largo; ++i)
    {
        delete[] this->tablero[i];
    }
    delete[] this->tablero;
}

// Funcion para resolver el problema
Estado *Tablero::resolver(Estado *inicial)
{

    inicial->heuristica = 0; // inicializamos el costo acumulado
    Heap colaPrioridad(1000); // creamos la cola de prioridad
    colaPrioridad.push(inicial); // agregamos el estado inicial a la cola de prioridad


    this->llenarTablero(inicial->getAutos()); // llenamos el tablero con los autos del estado inicial
    cout << "Estado Inicial" << endl;
    inicial->getAutos()->printVector(); // imprimimos el Vector de autos del estado inicial
    cout <<  "Tablero Inicial" << endl;
    this->MostarTablero(); // imprimimos el tablero
    cout << "Paredes" << endl;
    this->mostrarParedes(); // imprimimos las paredes

    VectorString *estadosVisitados = new VectorString(1000); // creamos un Vector de strings para guardar los estados visitados
    while (!colaPrioridad.isEmpty()) // mientras la cola de prioridad no este vacia
    {       
        Estado *actual = colaPrioridad.pop();   // sacamos el estado con menor costo acumulado (dado la heuristica)

        estadosVisitados->push(actual->toString()); // agregamos el estado a los estados visitados

        this->llenarTablero(actual->getAutos()); // llenamos el tablero con los autos del estado actual
        if (actual->esSolucion()) // si el estado actual es solucion
        { 
            cout << "Solucion encontrada" << endl;
            cout << "Estado Final" << endl;
            actual->mostrarEstado(); // imprimimos el estado
            cout << "Tablero Final" << endl;
            this->MostarTablero(); // imprimimos el tablero
            cout << "Movimientos realizados: " << actual->heuristica << endl;
            actual->mostrarsolucion(); // imprimimos la solucion
            Estado *aux = new Estado(*actual);
            return aux;
        }

        Vector *autos = actual->getAutos();  // obtenemos el Vector de autos del estado actual

        for (int i = 0; i <= autos->tope; i++)  // por cada auto en el Vector de autos
        {
            
            Auto *autoCopia = autos->vector[i];  // obtenemos el auto
            

            for (int j = 0; j < 8; j++) // por cada operacion
            {
                // Copiar el Vector de autos
                Vector *autosCopia = copiarVectorProfundamente(autos); // copiamos el Vector de autos
   
                Auto *nuevoAuto = autoCopia->mover(&this->operaciones[j], this->tablero, this->paredes); // movemos el auto con la operacion 
                
                if (nuevoAuto != nullptr) // si el auto se pudo mover
                {
                    if (nuevoAuto->posX < 0 || nuevoAuto->posX > 5 || nuevoAuto->posY < 0 || nuevoAuto->posY > 5)  // verificacion adicional de que el auto no se salga del tablero
                    {
                        continue; // si el auto se sale del tablero, no se hace nada
                    }
                    else
                    {
                        autosCopia->remplazar(nuevoAuto); // remplazamos el auto en el Vector de autos
                        
                        Estado *nuevoEstado = new Estado(autosCopia, &this->operaciones[j], actual, nuevoAuto); // creamos un nuevo estado con el Vector de autos copiado
                        if(colaPrioridad.Contains(nuevoEstado) || estadosVisitados->contains(nuevoEstado->toString())){ // si la cola de prioridad ya contiene el estado (si este intenta meter un estado que ya esta en la cola, siempre será peor ya que tiene mas movimientos que el que ya existe dentro de esta)                           
                            continue; // no se hace nada
                        }
                        nuevoEstado->heuristica = actual->heuristica + 1; // aumentamos el costo acumulado
                        colaPrioridad.push(nuevoEstado); // agregamos el nuevo estado a la cola de prioridad
                    }
                }
            }
        }
    }
    cout << "No se encontro solucion" << endl; // si la cola de prioridad se vacia y no se encontro solucion
    return nullptr;
};

// Funcion para copiar un Vector de autos
Vector *Tablero::copiarVectorProfundamente(Vector *original) // copia el Vector de autos
{
    Vector *copia = new Vector(original->capacidad);
    for (int i = 0; i <= original->tope; i++)
    {
        Auto *autoOriginal = original->vector[i];
        Auto *autoCopia = new Auto(*autoOriginal); 
        copia->push(autoCopia);
    }
    return copia;
}

// Funcion para llenar el tablero con los autos del Vector de autos
void Tablero::llenarTablero(Vector *autos) 
{

    for (int i = 0; i < this->Largo; i++) // llenamos el tablero con ceros
    {
        for (int j = 0; j < this->Largo; j++)
        {
            this->tablero[i][j] = 0;           
        }
    }

    for (int i = 0; i <= autos->tope; i++) // llenamos el tablero con los autos del Vector de autos
    {
        Auto *auto_ = autos->vector[i];
        int x = auto_->posX;
        int y = auto_->posY;
        int largo = auto_->Largo; 
        int direccion = auto_->Direccion;

        if (direccion == HORIZONTAL)
        {
            for (int j = 0; j < largo; j++)
            {
                this->tablero[y][x + j] = auto_->id; // esto sirve para mostrar el tablero correctamente
            }
        }
        else if (direccion == VERTICAL)
        {
            for (int j = 0; j < largo; j++)
            {
                this->tablero[y + j][x] = auto_->id; // esto sirve para mostrar el tablero correctamente
            }
        }
    }
}

// Funcion para vaciar el tablero
void Tablero::vaciarTablero()
{
    for (int i = 0; i < this->Largo; i++) // llenamos el tablero con ceros
    {
        for (int j = 0; j < this->Largo; j++)
        {
            tablero[i][j] = 0;
        }
    }
}

// Funcion para mostrar el tablero
void Tablero::MostarTablero()
{
    for (int i = 0; i < this->Largo; i++)
    {
        for (int j = 0; j < this->Largo; j++)
        {
            cout << this->tablero[i][j] << " "; // mostramos el tablero
        }
        cout << endl;
    }
    cout << endl;
}

// Funcion para setear las paredes del tablero
void Tablero::setParedes(int **paredes)
{
    this->paredes = paredes;
}

// Funcion para mostrar las paredes del tablero
void Tablero::mostrarParedes()
{
    for (int i = 0; i < this->Largo; i++)
    {
        for (int j = 0; j < this->Largo; j++)
        {
            cout << this->paredes[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}