#include "enodo.h"

class vnodo{
    private:
        int data;
        vnodo *siguiente;
        enodo *destinos;

    public:
        vnodo();
        ~vnodo();

        void insertarDestino(int);
        void graficarAristas(std::ofstream&);
        void graficarListaDestinos(std::ofstream&);

        int getData();
        vnodo* getSiguiente();
        enodo* getDestinos();
        void setData(int);
        void setSiguiente(vnodo*);
        void setDestinos(enodo*);
};