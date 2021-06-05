#include <iostream>
#include <stdlib.h>
#include "matrix.hpp"

using namespace std;


template <class tipo>
void Tree<tipo>::insertTreeNode(link &raiz, link &new_node)
{
    if (raiz==NULL)
    {
        raiz=new_node;
        return;
    }

    if (new_node->item.llave<raiz->item.llave){
        new_node->parent=raiz;
        insertTreeNode(raiz->left,new_node);
    }

    if (new_node->item.llave>raiz->item.llave){
        new_node->parent=raiz;
        insertTreeNode(raiz->right,new_node);
    }
}

template <class tipo>
void Tree<tipo>::FreeBinaryTree(link &raiz)
{
    if (raiz==NULL)
        return;
    if(raiz->left!=NULL)
        FreeBinaryTree(raiz->left);
    if (raiz->right!=NULL)
        FreeBinaryTree(raiz->right);
    delete raiz;
    raiz=NULL;
}

template <class tipo>
tipo Tree<tipo>::SearchBinaryTree(link &raiz,int item)
{
    if (raiz == NULL)
        return 0.0;
    else if (raiz->item.llave == item)
        return raiz->item.dato;
    else {
        tipo aux = SearchBinaryTree(raiz->left, item);
        return aux? aux: SearchBinaryTree(raiz->right, item);
        }
}

template <class tipo>
void MatrizRala<tipo>::operator=(MatrizRala<tipo> B)
{
    Arbol.free();
    for (int i=0;i<B.rows;i++)
        for(int j=0;j<B.cols;j++)
            insertarDato(i,j,B.regresaDato(i,j));
}

template <class tipo>
MatrizRala<tipo> MatrizRala<tipo>::operator*(MatrizRala<tipo> &B)
{
     MatrizRala<tipo> C(rows,B.cols);
     if (B.cols==rows&&B.rows==cols){
    for ( int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            {
            double sum=0;
            for (int k = 0; k < cols; ++k)
                sum+=regresaDato(i,k)*B.regresaDato(k,j);
                if (sum!=0.0) C.insertarDato(i,j,sum);
            }
     }
    return C;
}

template <class tipo>
void Tree<tipo>::insertar(link nodo)
{
    insertTreeNode(root,nodo);
}

template <class tipo>
tipo Tree<tipo>::buscar( int llave)
{
    return SearchBinaryTree(root,llave);
}

template <class tipo>
void Tree<tipo>::free()
{
    FreeBinaryTree(root);
}

template <class tipo>
tipo MatrizRala<tipo>::regresaDato(int i, int j)
{
    return Arbol.buscar(i*rows+j);
}

template <class tipo>
void MatrizRala<tipo>::insertarDato(int i, int j, double val)
{
    link new_node=(link)new node<double>;
    new_node->item.llave=i*rows+j;
    new_node->item.dato=val;
    Arbol.insertar(new_node);
}
