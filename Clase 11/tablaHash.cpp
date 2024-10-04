#include "tablaHash.h"

tablaHash::tablaHash(){
    this->tabla = new int[M];

    for(int i = 0; i < M; i++){
        this->tabla[i] = -999;
    }
    this->noElementos = 0;
}

tablaHash::~tablaHash(){
    delete this->tabla;
}

void tablaHash::insert(int llave){
    int pos = hash(llave);

    if(this->tabla[pos] != -999 && this->tabla[pos] != llave){
        pos = pruebaLineal(pos);
    }

    this->tabla[pos] = llave;
    this->noElementos++;

    //Cuando mi tabla hash está llena al 75%, yo creo una nueva tabla hash
    //con el doble de espacio

    if(((float)this->noElementos/M) > 0.75){
        int* temp = this->tabla;

        this->rehashing();

        for(int i = 0; i < M/2; i++){
            if(temp[i] != -999){
                this->insert(temp[i]);
            }
        }
    }
}

void tablaHash::print(){
    for(int i = 0; i < M; i++){
        std::cout << tabla[i] << ", ";
    }
    std::cout << std::endl;
}

void tablaHash::rehashing(){
    this->tabla = new int[M*2];
    this->noElementos = 0;
    this->M = M*2;

    for(int i = 0; i < M; i++){
        this->tabla[i] = -999;
    }
}

int tablaHash::hash(int x){
    float t = (float)R*x - floor(R*x);

    return floor(M*t);
}

int tablaHash::pruebaLineal(int pos){
    while(this->tabla[pos] != -999){
        pos = pos + 1;
        pos = pos%M;
    }

    return pos;
}