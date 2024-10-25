#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

class Nodo{
    public:
        char c;
        int n;
        Nodo *sig;
        Nodo *izq;
        Nodo *der;

        Nodo(char);
};