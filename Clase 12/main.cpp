#include "listaAdyacencia.h"

void crearConexionGrafo(listaAdyacencia&, int, int);

int main(int argc, char const *argv[])
{
    listaAdyacencia grafo;
    grafo.insert(7);
    grafo.insert(14);
    grafo.insert(1);
    grafo.insert(5);
    grafo.insert(12);
    grafo.insert(9);
    grafo.insert(11);
    grafo.insert(8);
    grafo.insert(3);
    grafo.insert(6);
    grafo.insert(10);
    grafo.insert(2);
    grafo.insert(13);
    grafo.insert(4);

    crearConexionGrafo(grafo, 1,5);
    crearConexionGrafo(grafo, 1,10);
    crearConexionGrafo(grafo, 2,3);
    crearConexionGrafo(grafo, 2,14);
    crearConexionGrafo(grafo, 3,1);
    crearConexionGrafo(grafo, 3,9);
    crearConexionGrafo(grafo, 4,8);
    crearConexionGrafo(grafo, 5,7);
    crearConexionGrafo(grafo, 6,2);
    crearConexionGrafo(grafo, 6,12);
    crearConexionGrafo(grafo, 7,5);
    crearConexionGrafo(grafo, 8,11);
    crearConexionGrafo(grafo, 9,4);
    crearConexionGrafo(grafo, 10,6);
    crearConexionGrafo(grafo, 11,13);
    crearConexionGrafo(grafo, 12,9);
    crearConexionGrafo(grafo, 13,2);
    crearConexionGrafo(grafo, 14,11);

    grafo.crearGrafo();
    grafo.crearGrafoLista();
    return 0;
}

void crearConexionGrafo(listaAdyacencia &grafo, int origen, int destino){
    grafo.crearConexion(origen, destino);
    grafo.crearConexion(destino, origen);
}
