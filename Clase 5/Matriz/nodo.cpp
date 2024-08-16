#include "nodo.h"

Nodo::Nodo(int i, int j){
    this->i = i;
    this->j = j;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->izq = nullptr;
    this->dcha = nullptr;
}

Nodo::Nodo(int i, int j, bool data){
    this->data = data;
    this->i = i;
    this->j = j;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->izq = nullptr;
    this->dcha = nullptr;   
}

bool Nodo::getData(){
    return data;
}

int Nodo::getI(){
    return i;
}

int Nodo::getJ(){
    return j;
}

Nodo* Nodo::getArriba(){
    return arriba;
}

Nodo* Nodo::getAbajo(){
    return abajo;
}

Nodo* Nodo::getIzq(){
    return izq;
}

Nodo* Nodo::getDcha(){
    return dcha;
}

void Nodo::setData(bool data){
    this->data = data;
}

void Nodo::setI(int i){
    this->i = i;
}

void Nodo::setJ(int j){
    this->j = j;
}

void Nodo::setArriba(Nodo *arriba){
    this->arriba = arriba;
}

void Nodo::setAbajo(Nodo *abajo){
    this->abajo = abajo;
}

void Nodo::setIzq(Nodo *izq){
    this->izq = izq;
}

void Nodo::setDcha(Nodo *dcha){
    this->dcha = dcha;
}