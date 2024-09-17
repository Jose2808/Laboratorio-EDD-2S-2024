#include "ArbolB.h"

ArbolB::ArbolB(){
    this->raiz = new Nodo();
    this->orden = 5;
}

ArbolB::~ArbolB(){
    delete this->raiz;
}

void ArbolB::insert(int data){
    Llave *nueva_raiz = insertarEnHoja(data, this->raiz);
    if(nueva_raiz != nullptr){
        this->raiz = new Nodo();
        raiz->insertarLlave(nueva_raiz);
        raiz->setHoja(false);
    }
}

Llave* ArbolB::insertarEnHoja(int data, Nodo *raiz){
    if(raiz->esHoja()){
        raiz->insertarLlave(new Llave(data));
        return (raiz->getNumeroLlaves() == this->orden) ? dividir(raiz) : nullptr;
    
    }else{
        Llave *puntero = raiz->getPrimero();
        if(data == puntero->getData()) return nullptr;
        else if( data < puntero->getData()){
            Llave *llaveRaiz = insertarEnHoja(data, puntero->getIzq());
            if(llaveRaiz != nullptr){
                raiz->insertarLlave(llaveRaiz);
                return (raiz->getNumeroLlaves() == this->orden) ? dividir(raiz) : nullptr;
            }

            return nullptr;
        
        }else{
            do{
                if(data == puntero->getData()) return nullptr;
                else if(data < puntero->getData()){
                    Llave *llaveRaiz = insertarEnHoja(data, puntero->getIzq());
                    if(llaveRaiz != nullptr){
                        raiz->insertarLlave(llaveRaiz);
                        return (raiz->getNumeroLlaves() == this->orden) ? dividir(raiz) : nullptr;
                    }
                    return nullptr;
                
                }else if(puntero->getSig() == nullptr){
                    Llave *llaveRaiz = insertarEnHoja(data, puntero->getDrcha());
                    if(llaveRaiz != nullptr){
                        raiz->insertarLlave(llaveRaiz);
                        return (raiz->getNumeroLlaves() == this->orden) ? dividir(raiz) : nullptr;
                    }
                    return nullptr;
                }

                puntero = puntero->getSig();
            } while(puntero != nullptr);
        }
    }
}

Llave* ArbolB::dividir(Nodo *nodo){
    int contador = 1;
    int valorClaveRaiz = 0;
    Llave *temp = nodo->getPrimero();
    Nodo *izquierda = new Nodo();
    Nodo *derecha = new Nodo();

    while(temp != nullptr){
        if(contador < 3){
            Llave *nueva_llave = new Llave(temp->getData());
            nueva_llave->setDrcha(temp->getDrcha());
            nueva_llave->setIzq(temp->getIzq());
            izquierda->insertarLlave(nueva_llave);

            if(nueva_llave->tieneHijos()){
                izquierda->setHoja(false);
            }
        
        }else if(contador == 3){
            valorClaveRaiz = temp->getData();
        
        }else{
            Llave *nueva_llave = new Llave(temp->getData());
            nueva_llave->setDrcha(temp->getDrcha());
            nueva_llave->setIzq(temp->getIzq());
            derecha->insertarLlave(nueva_llave);

            if(nueva_llave->tieneHijos()){
                derecha->setHoja(false);
            }
        }
        contador++;
        temp = temp->getSig();
    }

    Llave *llaveRaiz = new Llave(valorClaveRaiz);
    llaveRaiz->setDrcha(derecha);
    llaveRaiz->setIzq(izquierda);
    return llaveRaiz;
}