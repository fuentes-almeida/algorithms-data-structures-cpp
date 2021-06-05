#include <iostream>
#include <cstring>
#include "dicc.hpp"

using namespace std;

int indice(char c)
{
    return c-97;
}
Field::Field()
{
    root=NULL;
}
Field::~Field()
{
    Item *aux1=root;
    Item *aux2=root;
    while(aux2)
    {
        aux1=aux2;
        aux2=aux1->next;
        if (aux2)
        delete aux1;
    }
}

void Field::InsertarPalabra(char* palabra)
{
    Item *aux=root;
    if (!root)
    {
        root=new Item;
        root->next=NULL;
        strcpy(root->word,palabra);
        return;
    }
    while (aux->next)
        aux=aux->next;
    aux->next=new Item;
    aux->next->next=NULL;
    strcpy(aux->next->word,palabra);
    return;
}

void Field::ListarLetra()
{
    if (root==NULL)
    {
        cout<<"Esta seccion esta vacia"<<endl;
        return;
    }
    Item *aux=root;
    while (aux)
    {
        cout<<aux->word<<" ";
        aux=aux->next;
    }
    cout<<endl;
}

Diccionario::Diccionario()
{
    Table=new Field[26];
}

Diccionario::~Diccionario()
{
        delete [] Table;
}

void Diccionario::insertar(char* palabra)
{
    int index=indice(palabra[0]);
    Table[index].InsertarPalabra(palabra);
}

void Diccionario::listarpor(char letra)
{
    int index=indice(letra);
    Table[index].ListarLetra();
}

void Diccionario::listar()
{
    for (int i=0;i<26;i++)
    {
        cout<<(char)('a'+i)<<": ";
        Table[i].ListarLetra();
    }
}

