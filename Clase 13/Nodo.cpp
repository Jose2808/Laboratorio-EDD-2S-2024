#include "Nodos.h"

//NodoData
nodoData::nodoData(){
    uid = 0;
    valor = "";
    sig = nullptr;
}

int nodoData::getUid(){
    return uid;
}

std::string nodoData::getValor(){
    return valor;
}

nodoData* nodoData::getSig(){
    return sig;
}

void nodoData::setUid(int uid){
    this->uid = uid;
}

void nodoData::setValor(std::string valor){
    this->valor = valor;
}

void nodoData::setSig(nodoData* sig){
    this->sig = sig;
}

//NodoHash
nodoHash::nodoHash(){
    uid = 0;
    hash = "";
    drcha = nullptr;
    izq = nullptr;
    data = nullptr;
}

nodoHash::~nodoHash(){
    if(this->data != nullptr){
        delete this->data;
    }
}

int nodoHash::getUid(){
    return uid;
}

std::string nodoHash::getHash(){
    return hash;
}

nodoHash* nodoHash::getDrcha(){
    return drcha;
}

nodoHash* nodoHash::getIzq(){
    return izq;
}

nodoData* nodoHash::getData(){
    return data;
}

void nodoHash::setUid(int uid){
    this->uid = uid;
}

void nodoHash::setHash(std::string  hash){
    this->hash = hash;
}

void nodoHash::setIzq(nodoHash* izq){
    this->izq = izq;
}

void nodoHash::setDrcha(nodoHash* drcha){
    this->drcha = drcha;
}

void nodoHash::setData(nodoData*  data){
    this->data = data;
}