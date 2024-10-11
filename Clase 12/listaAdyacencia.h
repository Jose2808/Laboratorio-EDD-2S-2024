#include "vnodo.h"

class listaAdyacencia{
    private:
        vnodo *cabeza;

    public:
        listaAdyacencia();
        ~listaAdyacencia();

        void insert(int);
        void crearConexion(int, int);
        void crearGrafo();
        void crearGrafoLista();
};