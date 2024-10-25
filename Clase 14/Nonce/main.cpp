#include <iostream>
#include <string.h>
#include "sha256.h"

int nonce(std::string);

int main(int argc, char const *argv[])
{
    std::cout << nonce("Hello World") << std::endl;
    return 0;
}

int nonce(std::string s){
    std::string hash = sha256(s);
    int nonce = 0;

    while(hash.substr(0,6).compare("000000") == 1){
        hash = sha256(hash);
        nonce++;
    }

    std::cout << hash << std::endl;

    return nonce;
}