#include "ListaCircular.h"

ListaCircular::ListaCircular(){
    largo = 0;
    primero = nullptr;
}

ListaCircular::~ListaCircular(){
    Nodo *temp = primero->getSig();
    Nodo *aux;

    while(temp != primero){
        aux = temp->getSig();
        delete temp;
        temp = aux;
    }

    delete temp;
}

