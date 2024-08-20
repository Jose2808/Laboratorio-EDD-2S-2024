#include "matriz.h"

int main(int argc, char const *argv[])
{
    Matriz m;
    m.insert(1,1,false);
    m.insert(1,2,true);
    m.insert(3,2,false);
    m.insert(4,4,true);

    m.print();
    m.graph();
    return 0;
}
