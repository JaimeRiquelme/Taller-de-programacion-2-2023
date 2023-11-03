#include "Estado.h"
#include <sstream>


//Contructor de un estado
Estado::Estado(Vector *autos, Operacion *Op, Estado *padre, Auto *automoviendose)
{
    this->autos = autos;
    this->Op = Op;
    this->padre = padre;
    this->automoviendose = automoviendose;
    this->heuristica = 0;
    //this->heuristica = CalcularHeuristica();
};

//Contructor de un estado
Estado::Estado(Vector *autos, Operacion *Op, int idAuto)
{
    this->autos = autos;
    this->Op = Op;
    this->padre = nullptr;
    this->automoviendose = nullptr;
    this->heuristica = 0;
    //this->heuristica = CalcularHeuristica();
};

//Destructor de un estado
Estado::~Estado()
{

};

// Funcion para mostrar un estado
void Estado::mostrarEstado()
{
    this->autos->printVector();
};

// Funcion para verificar si un estado es solucion

bool Estado::esSolucion()
{
    bool p = this->autos->contains(1, 4, 2, 2, HORIZONTAL); // Busca el auto rojo en la posicion de salida
    if (p)
    { 
        return true; // Si el auto rojo esta en la posicion de salida, entonces es solucion
    }
    else
    {
        return false; // Si el auto rojo no esta en la posicion de salida, entonces no es solucion
    }
};

/* // Funcion para calcular la heuristica de un estado
int Estado::CalcularHeuristica() const
{
    Auto *autoObjetivo = this->autos->buscarPorId(1); // Busca el auto rojo

    int distancia = 5 - autoObjetivo->posX;

    return distancia;
};
 */
// Funcion para convertir un estado a string
std::string Estado::toString() const
{
    std::stringstream ss;
    for (int i = 0; i <= this->autos->tope; i++)
    {
        const Auto *auto_ = this->autos->vector[i];
        ss << auto_->id << " " << auto_->posX << " " << auto_->posY << " " << auto_->Direccion << " " << auto_->Largo << std::endl;
    }
    return ss.str();
};

// Funcion para obtener los autos de un estado
Vector *Estado::getAutos() const
{
    return this->autos;
};

// Funcion para mostrar la solucion final
void Estado::mostrarsolucion()
{
    if (this->padre != nullptr)
    {
        Estado *padre = this->padre;
        padre->mostrarsolucion();
    }
    if (this->Op != nullptr)
    {
        if (automoviendose->Direccion == HORIZONTAL)
        {
            if (Op->paso > 0)
            {
                std::cout << "El auto " << automoviendose->id << " se mueve a la derecha, " << abs(Op->paso)<< " Pasos"<<std::endl;
            }
            else if (Op->paso < 0)
            {
                std::cout << "El auto " << automoviendose->id << " se mueve a la izquierda " << abs(Op->paso)<< " Pasos"<<std::endl;
            }
        }
        else if (automoviendose->Direccion == VERTICAL)
        {
            if (Op->paso > 0)
            {
                std::cout << "El auto " << automoviendose->id << " se mueve hacia abajo " << abs(Op->paso)<< " Pasos"<<std::endl;   
            }
            else if (Op->paso < 0)
            {
                std::cout << "El auto " << automoviendose->id << " se mueve hacia arriba " << abs(Op->paso)<< " Pasos"<<std::endl;
            }
        }
        else
        {
            std::cout << "Estado Inicial" << std::endl;
        }
    }
};
