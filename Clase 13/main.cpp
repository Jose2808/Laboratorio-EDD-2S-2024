#include "merkle.h"

int main(int argc, char const *argv[])
{
    merkle arbol;
    arbol.agregar("prueba1");
    arbol.agregar("prueba2");
    arbol.agregar("prueba3");
    arbol.agregar("prueba4");
    arbol.agregar("prueba5");

    arbol.generar();
    arbol.generarDot();
    return 0;
}
