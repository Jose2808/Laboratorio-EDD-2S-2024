#include "listaAdyacencia.h"

listaAdyacencia::listaAdyacencia(){
    this->cabeza = nullptr;
}

listaAdyacencia::~listaAdyacencia(){
    vnodo *aux = this->cabeza;
    vnodo *temp;

    while(aux != nullptr){
        temp = aux->getSiguiente();
        delete aux;
        aux = temp;
    }
}

void listaAdyacencia::insert(int vertice){
    if(this->cabeza == nullptr){
        this->cabeza = new vnodo();
        this->cabeza->setData(vertice);

    }else{
        vnodo *nuevo = new vnodo();
        nuevo->setData(vertice);

        if(vertice < this->cabeza->getData()){
            nuevo->setSiguiente(cabeza);
            this->cabeza = nuevo;
        
        }else{
            vnodo *aux = this->cabeza;
            while(aux->getSiguiente() != nullptr){
                if(vertice < aux->getSiguiente()->getData()){
                    nuevo->setSiguiente(aux->getSiguiente());
                    aux->setSiguiente(nuevo);
                    break;
                } 
                aux = aux->getSiguiente();
            }

            if(aux->getSiguiente() == nullptr){
                aux->setSiguiente(nuevo);
            }
        }
    }
}

void listaAdyacencia::crearConexion(int origen, int destino){
    vnodo *aux = this->cabeza;
    while(aux != nullptr){
        if(aux->getData() == origen){
            aux->insertarDestino(destino);
            break;
        }
        aux = aux->getSiguiente();
    }
}

void listaAdyacencia::crearGrafo(){
    std::ofstream outfile ("grafo.dot");
    outfile << "digraph G {" << std::endl;

    vnodo *aux = this->cabeza;
    while(aux != nullptr){
        std::string valor = std::to_string(aux->getData());
        std::string dec_nodo  = "Nodo" + valor + "[label = \"" + valor + "\"];";
        outfile << dec_nodo << std::endl;
        aux->graficarAristas(outfile);
        aux = aux->getSiguiente();
    }

    outfile << "}" << std::endl;
    outfile.close();

    int returnCode = system("dot -Tpng ./grafo.dot -o ./grafo.png");

    if(returnCode == 0){std::cout << "Command executed successfully." << std::endl;}
    else{std::cout << "Command execution failed or returned non-zero: " << returnCode << std::endl;}
}

void listaAdyacencia::crearGrafoLista(){
    std::ofstream outfile ("grafoLista.dot");
    outfile << "digraph G {" << std::endl;
    outfile << "node[shape = \"box\" style = \"filled\"]" << std::endl;

    vnodo *aux = this->cabeza;
    while(aux != nullptr){
        std::string valor = std::to_string(aux->getData());
        std::string nombre = "Nodo" + valor + "[label = \"" + valor + "\" group = \"1\" fillcolor=\"lightgray\"];";
        outfile << nombre << std::endl;

        if(aux->getSiguiente() != nullptr){
            outfile << "Nodo" + valor + "->Nodo" + std::to_string(aux->getSiguiente()->getData()) + "[dir = none];";
        }

        aux->graficarListaDestinos(outfile);
        aux = aux->getSiguiente();
    }

    outfile << "}" << std::endl;
    outfile.close();

    int returnCode = system("dot -Tpng ./grafoLista.dot -o ./grafoLista.png");

    if(returnCode == 0){std::cout << "Command executed successfully." << std::endl;}
    else{std::cout << "Command execution failed or returned non-zero: " << returnCode << std::endl;}  
}