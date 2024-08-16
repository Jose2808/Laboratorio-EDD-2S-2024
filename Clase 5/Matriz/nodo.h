#include <iostream>

class Nodo {
    private:
        int i, j;
        bool data = false;
        Nodo *arriba, *abajo;
        Nodo *izq, *dcha;

    public:
        Nodo(int i, int j);
        Nodo(int i, int j, bool data);    

        void setI(int i);
        void setJ(int j);
        void setData(bool data);
        void setArriba(Nodo *arriba);
        void setAbajo(Nodo *abajo);
        void setIzq(Nodo *izq);
        void setDcha(Nodo *dcha);

        int getI();
        int getJ();
        bool getData();
        Nodo* getArriba();
        Nodo* getAbajo();
        Nodo* getIzq();
        Nodo* getDcha();
};