#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

class nodoData{
    private:
        int uid;
        std::string valor;
        nodoData *sig;

    public:
        nodoData();

        int getUid();
        std::string getValor();
        nodoData* getSig();

        void setUid(int);
        void setValor(std::string);
        void setSig(nodoData*);
};

class nodoHash{
    private:
        int uid;
        std::string hash;
        nodoHash *drcha;
        nodoHash *izq;
        nodoData *data;

    public:
        nodoHash();
        ~nodoHash();

        int getUid();
        std::string getHash();
        nodoHash* getDrcha();
        nodoHash* getIzq();
        nodoData* getData();

        void setUid(int);
        void setHash(std::string);
        void setDrcha(nodoHash*);
        void setIzq(nodoHash*);
        void setData(nodoData*);
};