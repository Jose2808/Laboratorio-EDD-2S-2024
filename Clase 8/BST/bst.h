#include "nodo.h"

class BST{
    private:
        Nodo *raiz;

        Nodo* insert(Nodo *raiz, std::string data);
        void postOrden(Nodo *raiz, bool accion);
        void preOrden(Nodo *raiz);
        void inOrden(Nodo *raiz);
        void graph(Nodo *raiz, std::ofstream &f);

    public:
        BST();
        ~BST();

        void insert(std::string data);
        void preOrden();
        void inOrden();
        void postOrden();
        void graph();
};