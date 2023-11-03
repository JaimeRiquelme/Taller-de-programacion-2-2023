#include "Auto.h"
#include "Operacion.h"
#include <iostream>

int main(){
    //creamos el auto rojo
    Auto *Auto1 = new Auto(1,0,2,2,0);

    //imprimimos el auto rojo antes de la operacion

    std::cout << "Auto Rojo antes de la operacion:  "
    << "Id: " << Auto1->id << 
    " ,PosX: " << Auto1->posX <<
    " ,PosY: " << Auto1->posY << 
    " ,Largo: " << Auto1->Largo << 
    " ,Direccion: " << Auto1->Direccion << std::endl;
 
    //creamos la operacion de mover el auto rojo hacia la derecha (sumarle 1)
    Operacion *op = new Operacion(0,1);

    //Realizamos la operacion
    Auto *AutoRojoMovido = op->operar(Auto1);

    //imprimimos el auto rojo despues de la operacion
    std::cout << "Auto Rojo despues de la operacion: "
    << "Id: " << AutoRojoMovido->id <<
    " ,PosX: " << AutoRojoMovido->posX <<
    " ,PosY: " << AutoRojoMovido->posY <<
    " ,Largo: " << AutoRojoMovido->Largo <<
    " ,Direccion: " << AutoRojoMovido->Direccion << std::endl;


    //creamos un auto cualquiera en vertical
    Auto *Auto2 = new Auto(2,2,2,2,1);

    //imprimimos el auto cualquiera antes de la operacion
    std::cout << "Auto cualquiera antes de la operacion:  "
    << "Id: " << Auto2->id <<
    " ,PosX: " << Auto2->posX <<
    " ,PosY: " << Auto2->posY <<
    " ,Largo: " << Auto2->Largo <<
    " ,Direccion: " << Auto2->Direccion << std::endl;

    //creamos la operacion de mover el auto cualquiera hacia arriba(restarle 1)
    Operacion *op2 = new Operacion(0,-1);

    //Realizamos la operacion
    Auto *AutoCualquieraMovido = op2->operar(Auto2);

    //imprimimos el auto cualquiera despues de la operacion
    std::cout << "Auto cualquiera despues de la operacion:  "
    << "Id: " << AutoCualquieraMovido->id <<
    " ,PosX: " << AutoCualquieraMovido->posX <<
    " ,PosY: " << AutoCualquieraMovido->posY <<
    " ,Largo: " << AutoCualquieraMovido->Largo <<
    " ,Direccion: " << AutoCualquieraMovido->Direccion << std::endl;


    return 0;


}