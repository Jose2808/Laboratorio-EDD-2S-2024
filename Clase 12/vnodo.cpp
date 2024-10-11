#include "vnodo.h"

vnodo::vnodo(){
    this->data = 0;
    this->destinos = nullptr;
    this->siguiente = nullptr;
}

vnodo::~vnodo(){
    enodo *aux = this->destinos;
    enodo *temp;

    while(aux != nullptr){
        temp = aux->getSiguiente();
        delete aux;
        aux = temp;
    }
}

void vnodo::insertarDestino(int destino){
    enodo *nuevo = new enodo();
    nuevo->setDestino(destino);

    if(this->destinos == nullptr){
        this->destinos = nuevo;
    
    }else{
        enodo *aux = this->destinos;
        while(aux->getSiguiente() != nullptr){
            if(aux->getDestino() == destino){
                return;
            }
            aux = aux->getSiguiente();
        }

        if(aux->getDestino() != destino){
            aux->setSiguiente(nuevo);
        }
    }
}

void vnodo::graficarAristas(std::ofstream &f){
    enodo *aux = this->destinos;

    std::string nombre_origen = "Nodo" + std::to_string(this->data);
    while(aux != nullptr){
        if(this->data < aux->getDestino()){
            std::string nombre_destino = "Nodo" + std::to_string(aux->getDestino());
            f << nombre_origen + "->" + nombre_destino + "[dir = both];" << std::endl;
        }
        aux = aux->getSiguiente();
    }
}

void vnodo::graficarListaDestinos(std::ofstream &f){
    enodo  *aux = this->destinos;
    std::ostringstream oss;
    std::string valor = std::to_string(this->data);
    std::string nombre_origen = "Nodo" + valor;
    std::string rank = "{rank=same;" + nombre_origen;

    oss << this->destinos;
    std::string nombre = oss.str();

    f << nombre_origen + "->Nodo" + nombre + ";" << std::endl;

    while(aux != nullptr){
        oss.str("");
        oss << aux;
        std::string nombre = oss.str();

        std::string nombre_destino = "Nodo" + nombre;
        f << nombre_destino + "[label = \"" + std::to_string(aux->getDestino()) + "\" fillcolor = \"white\"];" << std::endl;
        rank+=";" + nombre_destino;

        if(aux->getSiguiente() != nullptr){
            oss.str("");
            oss << aux->getSiguiente();
            std::string nombre = oss.str();
            f << nombre_destino + "->Nodo" + nombre + ";" << std::endl;
        }
        aux = aux->getSiguiente();
    }
    rank+= "}";
    f << rank << std::endl;
}

int vnodo::getData(){
    return this->data;
}

enodo* vnodo::getDestinos(){
    return this->destinos;
}

vnodo* vnodo::getSiguiente(){
    return this->siguiente;
}

void vnodo::setData(int data){
    this->data = data;
}

void vnodo::setDestinos(enodo *destinos){
    this->destinos = destinos;
}

void vnodo::setSiguiente(vnodo *siguiente){
    this->siguiente = siguiente;
}
