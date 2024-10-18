#include "Nodos.h"

class merkle{
    private:
        nodoHash *topHash;
        nodoData *primeroData;
        nodoData *ultimoData;
        std::string dot;
        int pos;

        void postOrder(nodoHash*);
        void crearArbol(nodoHash*, int);
        void generarHash(nodoHash*, int);
        void generarDotRec(nodoHash*, std::ofstream&);

        int largoListaData();
        nodoData* obtenerData(int);

    public:
        merkle();
        ~merkle();

        void agregar(std::string);
        void generar();
        void generarDot();
};