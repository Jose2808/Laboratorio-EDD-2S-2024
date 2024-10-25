#include "Nodo.h"

class Huffman{
    private:
        Nodo *raiz;
        std::string codigos[256];

        void insertarCaracter(Nodo*);
        void graficar(Nodo*, std::ofstream&);
        void eliminar(Nodo*);

    public:
        Huffman();
        ~Huffman();

        void crearArbol(std::string);
        void crearCodigosHuffman(Nodo*, std::string);
        void graficar();
        void imprimirCodigos();

        std::string comprimir(std::string);
        std::string descomprimir(std::string);

        Nodo* getRaiz();
};