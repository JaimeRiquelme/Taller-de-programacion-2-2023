#include "Auto.h"
#include "Vector.h"

int main(){

    //creamos el vector
    Vector *vector = new Vector(10);

    //creamos los autos
    Auto *auto1 = new Auto(1,2,2,0,0);
    std::cout << "Auto creado:" << "AutoId: " << auto1->id << " ,PosX: " << auto1->posX << " ,PosY: " << auto1->posY << " ,Largo: " << auto1->Largo << " ,Direccion: " << auto1->Direccion << std::endl;
    Auto *auto2 = new Auto(2,0,0,2,1);
    std::cout << "Auto creado:" << "AutoId: " << auto2->id << " ,PosX: " << auto2->posX << " ,PosY: " << auto2->posY << " ,Largo: " << auto2->Largo << " ,Direccion: " << auto2->Direccion << std::endl;
    Auto *auto3 = new Auto(3,1,1,2,0);
    std::cout << "Auto creado:" << "AutoId: " << auto3->id << " ,PosX: " << auto3->posX << " ,PosY: " << auto3->posY << " ,Largo: " << auto3->Largo << " ,Direccion: " << auto3->Direccion << std::endl;
    Auto *auto4 = new Auto(4,4,1,2,1);
    std::cout << "Auto creado:" << "AutoId: " << auto4->id << " ,PosX: " << auto4->posX << " ,PosY: " << auto4->posY << " ,Largo: " << auto4->Largo << " ,Direccion: " << auto4->Direccion << std::endl;
    Auto *auto5 = new Auto(5,5,1,2,1);
    std::cout << "Auto creado:" << "AutoId: " << auto5->id << " ,PosX: " << auto5->posX << " ,PosY: " << auto5->posY << " ,Largo: " << auto5->Largo << " ,Direccion: " << auto5->Direccion << std::endl;
    Auto *auto6 = new Auto(6,1,2,3,1);
    std::cout << "Auto creado:" << "AutoId: " << auto6->id << " ,PosX: " << auto6->posX << " ,PosY: " << auto6->posY << " ,Largo: " << auto6->Largo << " ,Direccion: " << auto6->Direccion << std::endl;
    Auto *auto7 = new Auto(7,2,3,2,1);
    std::cout << "Auto creado:" << "AutoId: " << auto7->id << " ,PosX: " << auto7->posX << " ,PosY: " << auto7->posY << " ,Largo: " << auto7->Largo << " ,Direccion: " << auto7->Direccion << std::endl;
    Auto *auto8 = new Auto(8,3,3,2,0);
    std::cout << "Auto creado:" << "AutoId: " << auto8->id << " ,PosX: " << auto8->posX << " ,PosY: " << auto8->posY << " ,Largo: " << auto8->Largo << " ,Direccion: " << auto8->Direccion << std::endl;
    Auto *auto9 = new Auto(9,5,3,3,1);
    std::cout << "Auto creado:" << "AutoId: " << auto9->id << " ,PosX: " << auto9->posX << " ,PosY: " << auto9->posY << " ,Largo: " << auto9->Largo << " ,Direccion: " << auto9->Direccion << std::endl;
    Auto *auto10 = new Auto(10,1,5,2,0);
    std::cout << "Auto creado:" << "AutoId: " << auto10->id << " ,PosX: " << auto10->posX << " ,PosY: " << auto10->posY << " ,Largo: " << auto10->Largo << " ,Direccion: " << auto10->Direccion << std::endl;
    Auto *auto11 = new Auto(11,3,5,2,0);
    std::cout << "Auto creado:" << "AutoId: " << auto11->id << " ,PosX: " << auto11->posX << " ,PosY: " << auto11->posY << " ,Largo: " << auto11->Largo << " ,Direccion: " << auto11->Direccion << std::endl;

    std::cout << "" << std::endl;

    //agregamos los autos al vector
    std::cout << "Agregando autos al vector..." << std::endl;
    vector->push(auto1);
    vector->push(auto2);
    vector->push(auto3);
    vector->push(auto4);
    vector->push(auto5);
    vector->push(auto6);
    vector->push(auto7);
    vector->push(auto8);
    vector->push(auto9);
    vector->push(auto10);
    vector->push(auto11);

    //imprimimos el vector
    std::cout << "Imprimiendo vector..." << std::endl;
    vector->printVector();

   

}