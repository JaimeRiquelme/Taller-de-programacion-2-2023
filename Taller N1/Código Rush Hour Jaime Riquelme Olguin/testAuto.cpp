#include "Auto.h"

int main(){

    //creamos el auto rojo
    std::cout << "Creando auto rojo..." << std::endl;
    Auto *Auto1 = new Auto(1,0,2,2,0);

    //imprimimos el auto creado

    std::cout << "Auto Rojo "
    << "Id: " << Auto1->id << 
    " ,PosX: " << Auto1->posX <<
    " ,PosY: " << Auto1->posY << 
    " ,Largo: " << Auto1->Largo << 
    " ,Direccion: " << Auto1->Direccion << std::endl;

    //creamos otro auto cualquiera

    std::cout << "Creando auto cualquiera..." << std::endl;
    Auto *Auto2 = new Auto(2,2,2,2,1);

    //imprimimos el auto creado

    std::cout << "Auto cualquiera "
    << "Id: " << Auto2->id <<
    " ,PosX: " << Auto2->posX <<
    " ,PosY: " << Auto2->posY <<
    " ,Largo: " << Auto2->Largo <<
    " ,Direccion: " << Auto2->Direccion << std::endl;


}