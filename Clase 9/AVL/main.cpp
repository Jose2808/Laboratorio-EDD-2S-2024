#include "avl.h"

int main(){
    AVL arbol;
    arbol.insert("Carlos");
    arbol.insert("Francisco");
    arbol.insert("Daniel");
    arbol.insert("Xavier");
    arbol.insert("Zara");

    arbol.del("Carlos");
    arbol.graph();
}