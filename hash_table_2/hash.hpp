#ifndef HASH_HPP_INCLUDED
#define HASH_HPP_INCLUDED
#include <iostream>
#define M 7

using namespace std;

class Item
{
public:
    char letra;
    int busy;
    Item()
    {
        busy=0;
    }

};

class HashTable
{
private:
    Item *Table;
public:
    HashTable();
    ~HashTable();

    void insertar(char letra);
    void listar();
};

int Hash(int);
int PruebaLineal(char,int);

#endif // HASH_HPP_INCLUDED
