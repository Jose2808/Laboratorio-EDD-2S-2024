#include "avl.h"

AVL::AVL(){
    this->raiz = nullptr;
}

AVL::~AVL(){
    postOrden(this->raiz, 1);
}

void AVL::insert(std::string data){
    this->raiz = insert(this->raiz, data);
}

void AVL::del(std::string data){
    this->raiz = del(this->raiz, data);
}

void AVL::preOrden(){
    preOrden(this->raiz);
}

void AVL::inOrden(){
    inOrden(this->raiz);
}

void AVL::postOrden(){
    postOrden(this->raiz, 0);
}

void AVL::graph(){
    std::ofstream outfile ("AVL.dot");
    outfile << "digraph G {" << std::endl;

    if(raiz != nullptr){
        graph(raiz, outfile);
    }

    outfile << "}" << std::endl;
    outfile.close();

    int returnCode = system("dot -Tpng ./AVL.dot -o ./AVL.png");

    if(returnCode == 0){std::cout << "Command executed successfully." << std::endl;}
    else{std::cout << "Command execution failed or returned non-zero: " << returnCode << std::endl;}
}

void AVL::graph(Nodo *raiz, std::ofstream &f){
    if(raiz != nullptr){
        std::stringstream oss;
        oss << raiz;
        std::string nombre = oss.str();

        f << "Nodo" + nombre + "[label = \"" + raiz->getData() + "\"]" << std::endl;
    
        if(raiz->getIzq() != nullptr){
            oss.str("");
            oss << raiz->getIzq();
            std::string izquierda = oss.str();
            f << "Nodo" << nombre + "->Nodo" + izquierda << std::endl;
            //Nodo<nombre_raiz>->Nodo<izquierda>;
        }

        if(raiz->getDrcha() != nullptr){
            oss.str("");
            oss << raiz->getDrcha();
            std::string derecha = oss.str();
            f << "Nodo" << nombre + "->Nodo" + derecha << std::endl;
            //Nodo<nombre_raiz>->Nodo<derecha>;
        }

        this->graph(raiz->getIzq(), f);
        this->graph(raiz->getDrcha(), f);
    }
}

void AVL::preOrden(Nodo *raiz){
    if(raiz != nullptr){
        std::cout << raiz->getData() << ", ";
        preOrden(raiz->getIzq());
        preOrden(raiz->getDrcha());
    }
}

void AVL::inOrden(Nodo *raiz){
    if(raiz != nullptr){
        preOrden(raiz->getIzq());
        std::cout << raiz->getData() << ", ";
        preOrden(raiz->getDrcha());
    }
}

void AVL::postOrden(Nodo *raiz, bool accion){
    if(raiz != nullptr){
        postOrden(raiz->getIzq(), accion);
        postOrden(raiz->getDrcha(), accion);
        if(!accion){std::cout << raiz->getData() << ", ";}
        else{delete raiz;}
    }
}

Nodo* AVL::insert(Nodo *raiz, std::string data){
    if(raiz == nullptr){raiz = new Nodo(data);}
    else if(data < raiz->getData()){raiz->setIzq(insert(raiz->getIzq(), data));}
    else if(data > raiz->getData()){raiz->setDrcha(insert(raiz->getDrcha(), data));}

    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzq()), obtenerAltura(raiz->getDrcha())) + 1);

    if(obtenerBalance(raiz) > 1){
        if(obtenerBalance(raiz->getDrcha()) < 0){
            raiz->setDrcha(rotacionDerecha(raiz->getDrcha()));
            raiz = rotacionIzquierda(raiz);
        } else {
            raiz = rotacionIzquierda(raiz);
        }
    }

    if(obtenerBalance(raiz) < -1){
        if(obtenerBalance(raiz->getIzq()) > 0){
            raiz->setIzq(rotacionIzquierda(raiz->getIzq()));
            raiz = rotacionDerecha(raiz);
        }else{
            raiz = rotacionDerecha(raiz);
        }
    }
    return raiz;
}

Nodo* AVL::del(Nodo* raiz, std::string data){
    if(raiz == nullptr) return raiz;
    else if(data < raiz->getData()){raiz->setIzq(del(raiz->getIzq(), data));}
    else if(data > raiz->getData()){raiz->setDrcha(del(raiz->getDrcha(), data));}
    else{
        if(raiz->esHoja()){
            delete raiz;
            raiz = nullptr;
        
        }else if (raiz->tieneUnHijo()){
            raiz = raiz->obtenerHijoUnico();

        }else if (raiz->tieneDosHijos()){
            Nodo *temp = obtenerMayorDeMenores(raiz->getIzq());
            raiz->setData(temp->getData());
            raiz->setIzq(del(raiz->getIzq(), temp->getData()));
        }
    }

    if(raiz == nullptr) return raiz;

    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzq()), obtenerAltura(raiz->getDrcha())) + 1);

    if(obtenerBalance(raiz) > 1){
        if(obtenerBalance(raiz->getDrcha()) < 0){
            raiz->setDrcha(rotacionDerecha(raiz->getDrcha()));
            raiz = rotacionIzquierda(raiz);
        
        }else{
            raiz = rotacionIzquierda(raiz);
        }
    } 

    if(obtenerBalance(raiz) < -1){
        if(obtenerBalance(raiz->getIzq()) > 0){
            raiz->setIzq(rotacionIzquierda(raiz->getIzq()));
            raiz = rotacionDerecha(raiz);
        }else{
            raiz = rotacionDerecha(raiz);
        }
    }

    return raiz; 
}

Nodo* AVL::rotacionIzquierda(Nodo *raiz){
    Nodo *raizDerecha = raiz->getDrcha();
    Nodo *temp = raizDerecha->getIzq();

    raizDerecha->setIzq(raiz);
    raiz->setDrcha(temp);

    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzq()), obtenerAltura(raiz->getDrcha())) + 1);
    raizDerecha->setAltura(alturaMaxima(obtenerAltura(raizDerecha->getIzq()), obtenerAltura(raizDerecha->getDrcha())) + 1);

    return raizDerecha;
}

Nodo* AVL::rotacionDerecha(Nodo *raiz){
    Nodo *raizIzquierda = raiz->getIzq();
    Nodo *temp = raizIzquierda->getDrcha();

    raizIzquierda->setDrcha(raiz);
    raiz->setIzq(temp);

    raiz->setAltura(alturaMaxima(obtenerAltura(raiz->getIzq()), obtenerAltura(raiz->getDrcha())) + 1);
    raizIzquierda->setAltura(alturaMaxima(obtenerAltura(raizIzquierda->getIzq()), obtenerAltura(raizIzquierda->getDrcha())) + 1);

    return raizIzquierda;
}

Nodo* AVL::obtenerMayorDeMenores(Nodo *raiz){
    while(raiz->getDrcha() != nullptr){
        raiz = raiz->getDrcha();
    }
    return raiz;
}

int AVL::obtenerAltura(Nodo *raiz){
    if(raiz == nullptr) return 0;
    return raiz->getAltura();
}

int AVL::alturaMaxima(int izq, int drcha){
    if(izq >= drcha) return izq;
    return drcha;
}

int AVL::obtenerBalance(Nodo *raiz){
    return obtenerAltura(raiz->getDrcha()) - obtenerAltura(raiz->getIzq());
}