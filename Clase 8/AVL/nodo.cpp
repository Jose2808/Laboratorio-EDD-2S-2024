#include "nodo.h"

Nodo::Nodo(std::string data){
    this->data = data;
    altura = 1;
    drcha = nullptr;
    izq = nullptr;
}

std::string Nodo::getData(){
    return data;
}

int Nodo::getAltura(){
    return altura;
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

void Nodo::setAltura(int altura){
    this->altura = altura;
}

void Nodo::setDrcha(Nodo *drcha){
    this->drcha = drcha;
}

void Nodo::setIzq(Nodo *izq){
    this->izq = izq;
}