#include "Estado.h"
#include "Auto.h"
#include "Vector.h"

int main(){

    //creamos los autos
    Auto *auto1 = new Auto(1,2,2,0,0);
    Auto *auto2 = new Auto(2,0,0,2,1);
    Auto *auto3 = new Auto(3,1,1,2,0);
    Auto *auto4 = new Auto(4,4,1,2,1);
    Auto *auto5 = new Auto(5,5,1,2,1);
    
    //creamos el vector

    Vector *vector = new Vector(10);

    //agregamos los autos al vector

    vector->push(auto1);
    vector->push(auto2);
    vector->push(auto3);
    vector->push(auto4);
    vector->push(auto5);

    //creamos el estado

    Estado *estado = new Estado(vector,nullptr,nullptr,nullptr); // creamos un estado con el vector de autos creado anteriormente
    estado->heuristica = 5; // le asignamos una heuristica

    estado->mostrarEstado(); // imprimimos el estado
    std::cout << "Heuristica: " << estado->heuristica << std::endl; // imprimimos la heuristica

    

}