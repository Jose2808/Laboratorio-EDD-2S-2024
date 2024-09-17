#include "nodo.h"

class ArbolB {
    private:
        Nodo *raiz;
        int orden;

        Llave* insertarEnHoja(int data, Nodo *raiz);
        Llave* dividir(Nodo *nodo);

    public:
        ArbolB();
        ~ArbolB();

        void insert(int dato);
};