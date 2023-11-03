#pragma once


class Nodo {
    public:
        Nodo(int id);
        ~Nodo();
        int getid();
        int getPadre();
        void setPadre(int padre);


    private:
        int id;
        int padre;
};
