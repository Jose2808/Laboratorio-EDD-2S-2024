#include "bst.h"

BST::BST(){
    this->raiz = nullptr;
}

BST::~BST(){
    postOrden(this->raiz, 1);
}

void BST::insert(std::string data){
    this->raiz = insert(this->raiz, data);
}

void BST::postOrden(){
    postOrden(this->raiz, 0);
}

void BST::postOrden(Nodo *raiz, bool accion){
    if(raiz != nullptr){
        postOrden(raiz->getIzq(), accion);
        postOrden(raiz->getDrcha(), accion);
        if(!accion){std::cout << raiz->getData() << ", ";}
        else{delete raiz;}
    }
}

Nodo* BST::insert(Nodo *raiz, std::string data){
    if(raiz == nullptr){raiz = new Nodo(data);}
    else if(data < raiz->getData()){raiz->setIzq(insert(raiz->getIzq(), data));}
    else if(data > raiz->getData()){raiz->setDrcha(insert(raiz->getDrcha(), data));}
    return raiz;
}