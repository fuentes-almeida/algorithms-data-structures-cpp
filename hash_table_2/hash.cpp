#include <iostream>
#include "hash.hpp"
using namespace std;

int Hash(int i)
{
    return i%7;
}

int PruebaLineal(char letra,int j)
{
    int i=letra;
    int res=Hash(i)+j;
    return res%7;
}

HashTable::HashTable()
{
    Table=new Item[M];
}

HashTable::~HashTable()
{
    delete [] Table;
}

void HashTable::insertar(char letra)
{
    int j=0;
    int index=PruebaLineal(letra,j);
    while(Table[index].busy>0)
        {
            j++;
            index=PruebaLineal(letra,j);
        }
    Table[index].letra=letra;
    Table[index].busy=1;
}

void HashTable::listar()
{
    for (int i=0;i<M;i++)
    {
        cout<<Table[i].letra<<" ";
    }
    cout<<endl;
}
