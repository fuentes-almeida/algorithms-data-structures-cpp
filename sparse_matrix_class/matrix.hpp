#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Item{
    long int llave;
    double dato;
};

template <class tipo>
class node{

public:
    typedef node<tipo>*link;

public:
    Item item;
    link right;
    link left;
    link parent;
};

template <class tipo>
class Tree{

typedef typename node<tipo>::link link;

private:
    link root;

    void insertTreeNode(link &raiz, link &new_node);
    void FreeBinaryTree(link &raiz);
    tipo SearchBinaryTree(link &raiz,int item);

public:
    Tree()
    {
        root=NULL;
    }
    ~Tree()
    {
        FreeBinaryTree(root);
    }

    void insertar(link nodo);
    tipo buscar( int llave);
    void free();
};

template <class tipo>
class MatrizRala{

    typedef typename node<tipo>::link link;

private:
    Tree<double>Arbol;
    int rows;
    int cols;

public:
    MatrizRala(int n, int m)
    {
        rows=n;
        cols=m;
    }
    void insertarDato(int i, int j, double val);
    tipo regresaDato(int i, int j);
    MatrizRala<tipo>operator*(MatrizRala<tipo> &B);
    void operator=( MatrizRala<tipo> B);
};



#endif // MATRIX_HPP_INCLUDED
