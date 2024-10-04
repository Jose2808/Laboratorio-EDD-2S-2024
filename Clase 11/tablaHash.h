#include <iostream>
#include <math.h>

class tablaHash{
    private:
        const float R = 0.618034;
        int M = 13;
        int noElementos;
        int *tabla;

    public:
        tablaHash();
        ~tablaHash();

        void insert(int);
        void rehashing();
        void print();

        int pruebaLineal(int);
        int hash(int);
};