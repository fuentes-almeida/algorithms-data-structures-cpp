#ifndef DICC_HPP_INCLUDED
#define DICC_HPP_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

int indice(char c);

struct Item
{
    char word[50];
    Item* next;
};

class Field
{
    Item *root;
public:
    Field();
    ~Field();

    void InsertarPalabra(char* palabra);
    void ListarLetra();
};

class Diccionario
{
private:
    Field *Table;
public:
    Diccionario();
    ~Diccionario();

    void insertar(char* palabra);
    void listarpor(char letra);
    void listar();
};

#endif // DICC_HPP_INCLUDED
