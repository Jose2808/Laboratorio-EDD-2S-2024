#include "nodo.h"

Nodo::Nodo(std::string data){
    this->data = data;
    altura = 1;
    drcha = nullptr;
    izq = nullptr;
}

bool Nodo::esHoja(){
    return drcha == nullptr && izq == nullptr;
}

bool Nodo::tieneUnHijo(){
    return (drcha == nullptr && izq != nullptr) || (drcha != nullptr || izq == nullptr);
}

bool Nodo::tieneDosHijos(){
    return drcha != nullptr && izq != nullptr;
}

Nodo* Nodo::obtenerHijoUnico(){
    if(this->tieneUnHijo()){
        return (this->drcha != nullptr) ? this->drcha : this->izq;
    }  
    return nullptr;
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