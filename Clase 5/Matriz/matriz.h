#include "nodo.h"

class Matriz {
    private:
        Nodo *raiz;
        int ancho;
        int alto;

        Nodo* buscarColumna(int i);
        Nodo* buscarFila(int j);
        void insertarEnFila(Nodo *nuevo, Nodo *encabezadoColumna);
        void insertarEnColumna(Nodo *nuevo, Nodo *encabezadoFila);
        Nodo* insertarEncabezadoFila(int j);
        Nodo* insertarEncabezadoColumna(int i);
        void imprimirEncabezadosColumna();
        Nodo* obtenerNodo(int i, int j);

    public:
        Matriz();
        ~Matriz();

        void insert(int i, int j, bool data);
        bool existeNodo(Nodo *nuevo);
        void print();
};