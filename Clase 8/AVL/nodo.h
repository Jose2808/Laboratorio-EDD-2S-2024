#include <iostream>
#include <fstream>
#include <sstream>

class Nodo{
    private:
        std::string data;
        int altura;
        Nodo *drcha, *izq;

    public:
        Nodo(std::string value);

        std::string getData();
        Nodo* getDrcha();
        Nodo* getIzq();
        int getAltura();

        void setData(std::string data);
        void setDrcha(Nodo *drcha);
        void setIzq(Nodo *Izq);
        void setAltura(int altura);
};