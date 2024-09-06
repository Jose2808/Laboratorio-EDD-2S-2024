#include "bst.h"

int main(){
    BST arbol;
    arbol.insert("Carlos");
    arbol.insert("Andres");
    arbol.insert("Francisco");
    arbol.insert("Daniel");
    arbol.insert("Xavier");

    arbol.graph();
    arbol.inOrden();
}