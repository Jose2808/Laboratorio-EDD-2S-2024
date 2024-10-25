#include "Huffman.h"

int main(int argc, char const *argv[])
{
    Huffman h;

    std::string s;
    std::string contenido;
    std::ifstream f("ejemplo.edd");

    if(!f.is_open()){
        std::cerr << "Error abriendo el archivo";
        return 1;
    }

    while(getline(f, s)){
        contenido+=s;
    }
    f.close();

    h.crearArbol(contenido);
    h.graficar();
    h.crearCodigosHuffman(h.getRaiz(), "");
    h.imprimirCodigos();

    std::string comprimido =  h.comprimir(contenido);
    std::cout << "Texto comprimido: " + comprimido << std::endl;

    std::string descomprimido = h.descomprimir(comprimido);
    std::cout << "Texto descomprimido: " + descomprimido << std::endl;

    std::ofstream outfile ("backup.edd");
    outfile << comprimido << std::endl;
    outfile.close();
    return 0;
}
