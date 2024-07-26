#include <iostream>

int main(int argc, char const *argv[])
{
    std::string nombre;
    int edad;

    std::cout << "Cual es tu edad? " << std::endl;
    std::cin >> edad;
    std::cout << nombre << std::endl;

    std::cout << "Cual es tu nombre? " << std::endl;
    std::getline(std::cin >> std::ws, nombre);
    std::cout << nombre << std::endl;
    return 0;
}
