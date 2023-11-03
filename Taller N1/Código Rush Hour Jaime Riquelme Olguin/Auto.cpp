#include "Auto.h"
#include "Operacion.h"

//Contructor de un auto
Auto::Auto(int id, int posX, int posY,int Largo, int Direccion) {
    this->id = id;
    this->posX = posX;
    this->posY = posY;
    this->Direccion = Direccion;
    this->Largo = Largo;
}

// Destructor de un auto
Auto::~Auto() {
}


// Constructor de copia de un auto
Auto::Auto(const Auto& copia){
    this->id = copia.id;
    this->posX = copia.posX;
    this->posY = copia.posY;
    this->Direccion = copia.Direccion;
    this->Largo = copia.Largo;
}


// Funcion para mover un auto
Auto* Auto::mover(Operacion* op, int** tablero, int** paredes){
    Auto* copia;
    if (verificarMovimiento(tablero, op, paredes)){
        copia = op->operar(this);
        return copia;
    } else{
        copia = nullptr;
    }
    return nullptr;
}

// Funcion para verificar si un auto puede moverse
bool Auto::verificarMovimiento(int** tablero, Operacion* op, int** paredes) {
    int llegada_x, llegada_y, inicio_x, inicio_y,pasosx,pasosy;

    // Se calcula la posicion de llegada
    if(this->Direccion == HORIZONTAL){ // Si el auto esta en horizontal
        if(op->paso > 0){
            inicio_x = this->posX + this->Largo;
            llegada_x = this->posX + this->Largo - 1 + op->paso;
            llegada_y = this->posY;
        } else if (op->paso < 0){
            inicio_x = this->posX -1 ;
            llegada_x = this->posX + op->paso;
            llegada_y = this->posY;
        }
    }else if(this->Direccion == VERTICAL){ // Si el auto esta en vertical
        if(op->paso > 0){
            inicio_y = this->posY + this->Largo;
            llegada_x = this->posX;
            llegada_y = this->posY + this->Largo - 1 + op->paso;

        } else if (op->paso < 0){
            inicio_y = this->posY -1 ;
            llegada_x = this->posX;
            llegada_y = this->posY + op->paso;
        }
    }

    if(llegada_x < 0 || llegada_y < 0 || llegada_x >5 || llegada_y > 5){ // Si se sale del tablero
        return false;
    }
    
    pasosx = abs(llegada_x - inicio_x); // Se calcula la cantidad de pasos que se mueve
    pasosy = abs(llegada_y - inicio_y); // Se calcula la cantidad de pasos que se mueve
    
    if(this->Direccion == HORIZONTAL){ // Si el auto esta en horizontal
        if(op->paso > 0){
            for(int i = 0; i <= pasosx; i++){ // Se verifica que no haya autos en el camino
                if((tablero[llegada_y][llegada_x - i] != 0) || (paredes[llegada_y][llegada_x - i] == 1)){  // Si hay un auto o una pared
                    return false;
                }
            }
        } else if (op->paso < 0){
            for(int i = 0; i <= pasosx; i++){ // Se verifica que no haya autos en el camino
                if((tablero[llegada_y][llegada_x + i] != 0) || (paredes[llegada_y][llegada_x + i] == 1)){ // Si hay un auto o una pared
                    return false;
                }
            }
        }
    }else if(this->Direccion == VERTICAL){ // Si el auto esta en vertical
        if(op->paso > 0){
            for(int i = 0; i <= pasosy; i++){ // Se verifica que no haya autos en el camino
                if((tablero[llegada_y - i][llegada_x] != 0) || (paredes[llegada_y - i][llegada_x] == 1)){ // Si hay un auto o una pared
                    return false;
                }
            }
        } else if (op->paso < 0){
            for(int i = 0; i <= pasosy; i++){ // Se verifica que no haya autos en el camino 
                if((tablero[llegada_y + i][llegada_x] != 0) || (paredes[llegada_y + i][llegada_x] == 1)){ // Si hay un auto o una pared
                    return false;
                }
            }
        }
    }

    if(paredes[llegada_y][llegada_x] == 1){ // Si hay una pared
        return false;
    }
    
    if(tablero[llegada_y][llegada_x] == 0) // Si no hay un auto
        return true;
    else
        return false;
}



