#include <iostream>
#include <fstream>
#include <sstream>

class enodo{
    private:
      int destino;
      enodo *siguiente;

    public:
        enodo();

        int getDestino();
        enodo* getSiguiente();
        void setDestino(int); 
        void setSiguiente(enodo*); 
};