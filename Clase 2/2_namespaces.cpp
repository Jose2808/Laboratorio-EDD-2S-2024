#include <iostream>

namespace n1
{
    int x = 1;
} // namespace n1

namespace n2
{
    int x = 2;
} // namespace n2

int main(int argc, char const *argv[])
{
    //using namespace std;
    //Comentarios de una sola linea
    /*
        Comentario
        Multilínea
    */

    int x = 15;


    std::cout << x << std::endl;
    std::cout << n1::x << std::endl;
    std::cout << n2::x << std::endl;
    return 0;
}