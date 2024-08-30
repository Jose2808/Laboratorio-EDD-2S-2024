#include "nodo.h"

class BST{
    private:
        Nodo *raiz;

        Nodo* insert(Nodo *raiz, std::string data);
        void postOrden(Nodo *raiz, bool accion);
    public:
        BST();
        ~BST();

        void insert(std::string data);
        void preOrder();
        void inOrder();
        void postOrden();
        void graph();
};