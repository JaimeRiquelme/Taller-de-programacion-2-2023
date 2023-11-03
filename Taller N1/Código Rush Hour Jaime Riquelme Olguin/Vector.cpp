#include "Vector.h"
#include <string>

//Contructor de un vector
Vector::Vector(int capacidad) {
    this->capacidad = capacidad;
    this->tope = -1;
    this->vector = new Auto*[capacidad];

}


//Destructor de un vector
Vector::~Vector() {
    delete[] this->vector;
};



// Funcion para agregar un auto al vector
void Vector::push(Auto* auto_){
    if(this->tope == this->capacidad - 1){
        Auto** aux = new Auto*[this->capacidad * 2];
        for (int i = 0; i < this->capacidad; i++) {
            aux[i] = this->vector[i];
        }
        delete[] this->vector;
        this->vector = aux;
        this->capacidad *= 2;
    }
    this->tope++;
    this->vector[this->tope] = auto_;
};

// Funcion saber si el vector esta vacio
bool Vector::isEmpty(){
    return this->tope == -1;
};

// Funcion mostrar el vector
void Vector::printVector(){
    for(int i = 0; i <= this->tope; i++){
        std::cout << this->vector[i]->id << " " << this->vector[i]->posX << " " << this->vector[i]->posY << " " << this->vector[i]->Direccion << " " << this->vector[i]->Largo << std::endl;
    }
    std::cout << std::endl;
};

// Funcion para saber si un auto esta en el vector
bool Vector::contains(int id, int x , int y,int largo, int direccion){
    for(int i = 0; i <= this->tope; i++){
        if(this->vector[i]->id == id && 
        this->vector[i]->posX == x && 
        this->vector[i]->posY == y && 
        this->vector[i]->Largo == largo && 
        this->vector[i]->Direccion == direccion){
            //printf("true\n");
            return true;
        }
    }
    //printf("false\n");
    return false;
};

// Funcion para buscar un auto por su id
Auto* Vector::buscarPorId(int id){
    for(int i = 0; i <= this->tope; i++){
        if(this->vector[i]->id == id){
            return this->vector[i];
        }
    }
    return NULL;
};

// Funcion para reemplazar un auto en el vector
void Vector::remplazar(Auto* autoNuevo){
    for(int i = 0; i <= this->tope; i++){
        if(this->vector[i]->id == autoNuevo->id){
            this->vector[i] = autoNuevo;
        }
    }
};

    