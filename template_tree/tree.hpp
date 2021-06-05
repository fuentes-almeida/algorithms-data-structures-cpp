#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED

#include <iostream>
#include <stdlib.h>

using namespace std;

template <class tipo>
class node{

public:
    typedef node<tipo>*link;

public:
    tipo item;
    link right;
    link left;
};

template <class tipo>
class Tree{

typedef typename node<tipo>::link link;

private:
    link root;

link insertTreeNode(link &raiz, tipo item)
{
    if (raiz==NULL)
    {
        raiz=(link)new node<tipo>;
        raiz->right=NULL;
        raiz->left=NULL;
        raiz->item=item;
        return raiz;
    }

    if (item<raiz->item)
        raiz->left=insertTreeNode(raiz->left,item);
    if (item>raiz->item)raiz->right=insertTreeNode(raiz->right,item);

    return raiz;
}

int BinaryTreeHeigh(link &raiz)
{
    if (raiz==NULL)
        return 0;
    int nLeft = BinaryTreeHeigh(raiz->left);
    int nRight = BinaryTreeHeigh(raiz->right);

    if (nLeft > nRight)
        return (nLeft + 1);
    else
        return (nRight + 1);
}

link FreeBinaryTree(link &raiz)
{
    if (raiz==NULL)
        return NULL;
    if(raiz->left!=NULL)
        return FreeBinaryTree(raiz->left);
    if (raiz->right!=NULL)
        return FreeBinaryTree(raiz->right);
    delete raiz;
    raiz=NULL;
    return raiz;
}

bool SearchBinaryTree(link &raiz,tipo item)
{
    if (raiz==NULL)
        return false;
    if(raiz->item<item)
        return SearchBinaryTree(raiz->right,item);
    if (raiz->item>item)
        return SearchBinaryTree(raiz->left,item);
    if (raiz->item==item)
        return true;
    //else return false;
}

void imprimir(link &raiz, int heigh)const{
    if(raiz==NULL) {
        for (int i=0;i<heigh;i++)
            cout<<"\t";
                cout<<"*"<<endl;return;}
    imprimir(raiz->right,heigh+1);

        for (int i=0;i<heigh;i++)
            cout<<"\t";
                cout<<raiz->item<<" "<<endl;

    imprimir(raiz->left,heigh+1);
}

public:
    Tree()
    {
        root=NULL;
        cout<<"disparo constructor"<<endl;
    }
    ~Tree()
    {
        root=FreeBinaryTree(root);
        cout<<"disparo destructor"<<endl;
    }

int altura()
{
    return BinaryTreeHeigh(root);
}

void insertar(tipo item)
{
    root=insertTreeNode(root,item);
}

void print()
{
    imprimir(root,0);
}

bool busqueda(tipo item)
{
    if (root!=NULL)
    return SearchBinaryTree(root,item);
    else return false;
}

friend ostream& operator<<(ostream& out,const Tree<tipo> &arbol)
{
    //arbol.print();
    ((Tree<tipo> )arbol).print();
    return out;
}

};


#endif // TREE_HPP_INCLUDED
