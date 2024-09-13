#include "nodo.h"

class AVL{
    private:
        Nodo *raiz;

        Nodo* insert(Nodo *raiz, std::string data);
        Nodo* del(Nodo *raiz, std::string data);
        Nodo* rotacionIzquierda(Nodo *raiz);
        Nodo* rotacionDerecha(Nodo *raiz);
        Nodo* obtenerMayorDeMenores(Nodo *raiz);

        int alturaMaxima(int izq, int drch);
        int obtenerAltura(Nodo *raiz);
        int obtenerBalance(Nodo *raiz);

        void postOrden(Nodo *raiz, bool accion);
        void preOrden(Nodo *raiz);
        void inOrden(Nodo *raiz);
        void graph(Nodo *raiz, std::ofstream &f);

    public:
        AVL();
        ~AVL();

        void insert(std::string data);
        void del(std::string data);
        void preOrden();
        void inOrden();
        void postOrden();
        void graph();
};