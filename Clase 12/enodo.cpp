#include "enodo.h"

enodo::enodo(){
    this->destino = 0;
    this->siguiente = nullptr;
}

int enodo::getDestino(){
    return destino;
}

enodo* enodo::getSiguiente(){
    return siguiente;
}

void enodo::setDestino(int destino){
    this->destino = destino;
}

void enodo::setSiguiente(enodo* siguiente){
    this->siguiente = siguiente;
}