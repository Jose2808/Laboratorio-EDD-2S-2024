#include <iostream>
#include "nodo.h"

//ClASE NODO
Nodo::Nodo(){
    this->hoja = true;
    this->primero = nullptr;
    this->numeroLlaves = 0;
}

Nodo::~Nodo(){
    Llave *temp = primero;
    Llave *aux;

    while(temp != nullptr){
        aux = temp->getSig();
        delete temp;
        temp = aux;
    }
}

void Nodo::insertarLlave(Llave *llave){
    Llave *puntero = this->primero;

    if(this->primero == nullptr){
        this->primero = llave;
        this->numeroLlaves++;
    
    }else if(llave->getData() < primero->getData()){
        llave->setSig(primero);
        primero->setIzq(llave->getDrcha());
        primero->setPrev(llave);
        primero = llave;
        numeroLlaves++;

    }else{
        while(puntero != nullptr){
            if(llave->getData() == puntero->getData()){
                std::cout << "El valor " << llave->getData() << " ya se encuentra en el arbol. " << std::endl;
                break;
            
            }else if(llave->getData() < puntero->getData()){
                puntero->setIzq(llave->getDrcha());
                puntero->getPrev()->setDrcha(llave->getIzq());

                llave->setSig(puntero);
                llave->setPrev(puntero->getPrev());
                puntero->getPrev()->setSig(llave);
                puntero->setPrev(llave);

                numeroLlaves++;
                break;
            
            }else if(puntero->getSig() == nullptr){
                puntero->setSig(llave);
                llave->setPrev(puntero);
                puntero->setDrcha(llave->getIzq());

                numeroLlaves++;
                break;
            }
            puntero = puntero->getSig();
        }
    }
}

bool Nodo::esHoja(){
    return hoja;
}

Llave* Nodo::getPrimero(){
    return primero;
}

int Nodo::getNumeroLlaves(){
    return numeroLlaves;
}

void Nodo::setHoja(bool hoja){
    this->hoja = hoja;
}

void Nodo::setPrimero(Llave *primero){
    this->primero = primero;
}

void Nodo::setNumeroLlaves(int numeroLlaves){
    this->numeroLlaves = numeroLlaves;
}

//CLASE Llave
Llave::Llave(int data){
    this->data = data;
    prev = nullptr;
    sig = nullptr;
    drcha = nullptr;
    izq = nullptr;
}

Llave::~Llave(){
    delete drcha;
    delete izq;
}

bool Llave::tieneHijos(){
    return this->drcha != nullptr && this->izq != nullptr;
}

int Llave::getData(){
    return data;
}

Nodo* Llave::getIzq(){
    return izq;
}

Llave* Llave::getSig(){
    return sig;
}

Llave* Llave::getPrev(){
    return prev;
}

Nodo* Llave::getDrcha(){
    return drcha;
}

void Llave::setData(int data){
    this->data = data;
}

void Llave::setIzq(Nodo* izq){
    this->izq = izq;
}

void Llave::setSig(Llave *sig){
    this->sig = sig;
}

void Llave::setPrev(Llave *prev){
    this->prev = prev;
}

void Llave::setDrcha(Nodo *drcha){
    this->drcha = drcha;
}