#include "Nodo.h"

class listaSimpleEnlazada {
    private:
        Nodo *primero;
        Nodo *ultimo;

    public:
        listaSimpleEnlazada();
        ~listaSimpleEnlazada();

        void push(int valor);
        void append(int valor);
        void insert(int indice, int valor);
        void print();
        void graph();
};