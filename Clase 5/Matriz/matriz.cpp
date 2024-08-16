#include "matriz.h"

Matriz::Matriz(){
    this->raiz  = new Nodo(-1, -1);
    this->alto = 0;
    this->ancho = 0;
}

Matriz::~Matriz(){
    Nodo *temp = raiz;
    Nodo *aux;

    while(temp != nullptr){
        Nodo *tempFila = temp;
        Nodo *auxFila;

        aux = temp->getAbajo();

        while(tempFila != nullptr){
            auxFila = tempFila->getDcha();
            delete tempFila;
            tempFila = auxFila;
        }

        temp = aux;
    }
}

void Matriz::insert(int i, int j, bool data){
    Nodo *nuevo = new Nodo(i, j, data);
    Nodo *columna = buscarColumna(i);
    Nodo *fila = buscarFila(j);

    if(i > this->ancho){this->ancho = i;}
    if(j > this->alto){this->alto = j;}

    if(!this->existeNodo(nuevo)){
        if(columna == nullptr){ columna = insertarEncabezadoColumna(i);}
        if(fila == nullptr){ fila = insertarEncabezadoFila(j);}

        insertarEnColumna(nuevo, fila);
        insertarEnFila(nuevo, columna);
    }
}

Nodo* Matriz:: insertarEncabezadoFila(int j){
    Nodo *nuevoEncabezadoFila = new Nodo(-1, j);
    this->insertarEnFila(nuevoEncabezadoFila, this->raiz);
    return nuevoEncabezadoFila;
}

Nodo* Matriz:: insertarEncabezadoColumna(int i){
    Nodo *nuevoEncabezadoColumna = new Nodo(i, -1);
    this->insertarEnColumna(nuevoEncabezadoColumna, this->raiz);
    return nuevoEncabezadoColumna;
}

void Matriz::insertarEnFila(Nodo *nuevo, Nodo *encabezadoColumna){
    Nodo *temp = encabezadoColumna;

    while(temp->getAbajo() != nullptr){
        if(nuevo->getJ() < temp->getAbajo()->getJ()){
            nuevo->setAbajo(temp->getAbajo());
            nuevo->setArriba(temp);
            temp->getAbajo()->setArriba(nuevo);
            temp->setAbajo(nuevo);
            break;
        }

        temp = temp->getAbajo();
    }

    if(temp->getAbajo() == nullptr){
      temp->setAbajo(nuevo);
      nuevo->setArriba(temp);  
    }
}

void Matriz::insertarEnColumna(Nodo *nuevo, Nodo *encabezadoFila){
    Nodo *temp = encabezadoFila;

    while(temp->getDcha() != nullptr){
        if(nuevo->getI() < temp->getDcha()->getI()){
            nuevo->setDcha(temp->getDcha());
            nuevo->setIzq(temp);
            temp->getDcha()->setIzq(nuevo);
            temp->setDcha(nuevo);
            break;
        }
        temp = temp->getDcha();
    }

    if(temp->getDcha() == nullptr){
        temp->setDcha(nuevo);
        nuevo->setIzq(temp);
    }
}

Nodo* Matriz::buscarColumna(int i){
    Nodo *temp = this->raiz;

    while(temp != nullptr){
        if(temp->getI() == i){
            return temp;
        }
        temp = temp->getDcha();
    }
    return nullptr;
}

Nodo* Matriz::buscarFila(int j){
    Nodo *temp = this->raiz;

    while(temp != nullptr){
        if(temp->getJ() == j){
            return temp;
        }
        temp = temp->getAbajo();
    }
    return nullptr;
}

bool Matriz::existeNodo(Nodo *nuevo){
    Nodo *encabezadoFila = this->raiz;

    while(encabezadoFila != nullptr){
        if(encabezadoFila->getJ() == nuevo->getJ()){
            Nodo *columna = encabezadoFila;

            while(columna != nullptr){
                if(columna->getI() == nuevo->getI()){
                    columna->setData(nuevo->getData());
                    delete nuevo;
                    return true;
                }
                columna = columna->getDcha();
            }  

            return false; 
        }

        encabezadoFila = encabezadoFila->getAbajo();
    }
    return false;
}

void Matriz::imprimirEncabezadosColumna(){
    for(int i = -1; i <= ancho; i++){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

Nodo* Matriz::obtenerNodo(int i, int j){
    Nodo *encabezadoFila = this->raiz;

    while(encabezadoFila != nullptr){
        if(encabezadoFila->getJ() == j){
            Nodo *columna = encabezadoFila;

            while(columna != nullptr){
                if(columna->getI() == i){
                    return columna;
                }
                columna = columna->getDcha();
            }
            return nullptr;
        }
        encabezadoFila = encabezadoFila->getAbajo();
    }
    return nullptr;
}

void Matriz::print(){
    Nodo *temp;
    this->imprimirEncabezadosColumna();

    for(int j = 0; j <= alto; j++){
        std::cout << " " << j << " ";
        for(int i = 0; i <= ancho; i++){
            temp = obtenerNodo(i, j);
            std::cout << (temp != nullptr ? (temp->getData() ? "V" : "F") : "0") << " ";
        }
        std::cout << std::endl;
    }
}