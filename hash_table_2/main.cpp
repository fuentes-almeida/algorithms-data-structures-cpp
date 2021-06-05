#include <iostream>
#include "hash.hpp"

using namespace std;

int main()
{
    HashTable T;
    T.insertar('p');
    T.insertar('r');
    T.insertar('o');
    T.insertar('b');
    T.insertar('i');
    T.insertar('n');
    T.insertar('g');
    T.listar();
    return 0;
}
