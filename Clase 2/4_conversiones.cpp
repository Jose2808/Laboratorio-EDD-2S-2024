#include <iostream>

int main(int argc, char const *argv[])
{
    double x = 3.141615;
    std::cout << x << std::endl;

    int y = (int)x;
    std::cout << y << std::endl;

    char a = (char)100;
    std::cout << a << std::endl;

    y = (int)'d';
    std::cout << y << std::endl;
    return 0;
}
