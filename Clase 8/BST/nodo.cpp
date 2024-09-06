#include "nodo.h"

Nodo::Nodo(std::string data){
    this->data = data;
    drcha = nullptr;
    izq = nullptr;
}

std::string Nodo::getData(){
    return data;
}

Nodo* Nodo::getDrcha(){
    return drcha;
}

Nodo* Nodo::getIzq(){
    return izq;
}

void Nodo::setData(std::string data){
    this->data = data;
}

void Nodo::setDrcha(Nodo *drcha){
    this->drcha = drcha;
}

void Nodo::setIzq(Nodo *izq){
    this->izq = izq;
}