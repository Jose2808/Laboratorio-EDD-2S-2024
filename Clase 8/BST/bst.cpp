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

void BST::preOrden(){
    preOrden(this->raiz);
}

void BST::inOrden(){
    inOrden(this->raiz);
}

void BST::postOrden(){
    postOrden(this->raiz, 0);
}

void BST::graph(){
    std::ofstream outfile ("bst.dot");
    outfile << "digraph G {" << std::endl;

    if(raiz != nullptr){
        graph(raiz, outfile);
    }

    outfile << "}" << std::endl;
    outfile.close();

    int returnCode = system("dot -Tpng ./bst.dot -o ./bst.png");

    if(returnCode == 0){std::cout << "Command executed successfully." << std::endl;}
    else{std::cout << "Command execution failed or returned non-zero: " << returnCode << std::endl;}
}

void BST::graph(Nodo *raiz, std::ofstream &f){
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

void BST::preOrden(Nodo *raiz){
    if(raiz != nullptr){
        std::cout << raiz->getData() << ", ";
        preOrden(raiz->getIzq());
        preOrden(raiz->getDrcha());
    }
}

void BST::inOrden(Nodo *raiz){
    if(raiz != nullptr){
        preOrden(raiz->getIzq());
        std::cout << raiz->getData() << ", ";
        preOrden(raiz->getDrcha());
    }
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