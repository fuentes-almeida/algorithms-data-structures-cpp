#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED

#define SELECTION_SORT      100
#define QUICK_SORT          101
#define MERGE_SORT          102
#define BST_SORT            103

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
    link parent;
};

template <class tipo>
class Tree{

typedef typename node<tipo>::link link;

private:
    link root;

    void leftRotate(link x);
    void rightRotate(link x);

    void insertTreeNode(link &raiz, link &new_node);
    void rootInsertion(link &raiz,link &new_node);

    int BinaryTreeHeigh(link &raiz);
    void FreeBinaryTree(link &raiz);

    bool SearchBinaryTree(link &raiz,tipo item);
    void imprimir(link &raiz, int heigh);
    void BSTsort(link &raiz,tipo *a,int n);

public:
    Tree()
    {
        root=NULL;
    }
    ~Tree()
    {
        FreeBinaryTree(root);
    }

    int altura();
    void insertar(tipo item);
    void insertarRaiz(tipo item);
    void print();
    bool busqueda(tipo item);
    void BST(Tree<tipo> &arbol,tipo *a);

    friend ostream& operator<<(ostream& out, Tree<tipo> &arbol)
    {
        arbol.print();
        return out;
    }

};

template <class tipo>
class ordenador{
typedef typename node<tipo>::link link;
private:

void merge_func(tipo *a,int left, int mid,int right,int SIZE);
void mergeSort(tipo *a,int left, int right, int n);
void selectionSort(tipo *a,int n);
void quickSort(tipo* a, int left, int right);

public:
    ordenador(tipo *a, int macro,int SIZE)
    {
        if (macro==100)
            selectionSort(a,SIZE);
        else if (macro==102)
            mergeSort(a,0,SIZE-1,SIZE);
        else if (macro==101)
            quickSort(a,0,SIZE-1);
        else if (macro==103)
        {
        Tree<tipo>intTree;
        for (tipo i=0;i<SIZE;i++){
        tipo aux=a[i];
        if(rand()%3==0)intTree.insertarRaiz(aux);
        else intTree.insertar(aux);
        }
        intTree.BST(intTree,a);
        }
    }

    tipo select(tipo *a, int k)
    {
        return a[k-1];
    }
};


template <class tipo>
void Tree<tipo>::leftRotate(link x)
{
    link y=x->right;
    x->right=y->left;

    if (y->left!=NULL)
        y->left->parent=x;
    y->parent=x->parent;
    if (x->parent==NULL)
        root=y;
    else if (x==x->parent->left)
        x->parent->left=y;
    else
        x->parent->right=y;
    y->left=x;
    x->parent=y;
}

template <class tipo>
void Tree<tipo>::rightRotate(link x)
{
    link y=x->left;
    x->left=y->right;

    if (y->right!=NULL)
        y->right->parent=x;
    y->parent=x->parent;
    if (x->parent==NULL)
        root=y;
    else if (x==x->parent->right)
        x->parent->right=y;
    else
        x->parent->left=y;
    y->right=x;
    x->parent=y;
}

template <class tipo>
void Tree<tipo>::insertTreeNode(link &raiz, link &new_node)
{
    if (raiz==NULL)
    {
        raiz=new_node;
        return;
    }

    if (new_node->item<raiz->item){
        new_node->parent=raiz;
        insertTreeNode(raiz->left,new_node);
    }

    if (new_node->item>raiz->item){
        new_node->parent=raiz;
        insertTreeNode(raiz->right,new_node);
    }
}

template <class tipo>
void Tree<tipo>::rootInsertion(link &raiz,link &new_node)
{
    if (raiz==NULL)
        {
        raiz=new_node;
        return;
        }
    if (new_node->item<raiz->item)
    {
        new_node->parent=raiz;
        rootInsertion(raiz->left,new_node);
        rightRotate(raiz);
    }
    else
    {
        new_node->parent=raiz;
        rootInsertion(raiz->right,new_node);
        leftRotate(raiz);
    }
}

template <class tipo>
int Tree<tipo>::BinaryTreeHeigh(link &raiz)
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
bool Tree<tipo>::SearchBinaryTree(link &raiz,tipo item)
{
    if (raiz==NULL)
        return false;
    else if (raiz->item==item)
        return true;
    else {
    //if(raiz->item<item)
        bool aux= SearchBinaryTree(raiz->left,item);
    //if (raiz->item>item)
        if (aux==true) return aux;
        else return SearchBinaryTree(raiz->right,item);
        }
    //else return false;
}

template <class tipo>
void Tree<tipo>::imprimir(link &raiz, int heigh){
    if(raiz==NULL) {
        for (int i=0;i<heigh;i++)
            cout<<"\t";
                cout<<"*"<<endl;
                return;}
    imprimir(raiz->right,heigh+1);

        for (int i=0;i<heigh;i++)
            cout<<"\t";
                cout<<raiz->item<<" "<<endl;

    imprimir(raiz->left,heigh+1);
}

template <class tipo>
int Tree<tipo>::altura()
{
    return BinaryTreeHeigh(root);
}

template <class tipo>
void Tree<tipo>::insertar(tipo item)
{
    link new_node=(link)new node<tipo>;
    new_node->right=NULL;
    new_node->left=NULL;
    new_node->parent=NULL;
    new_node->item=item;
    insertTreeNode(root,new_node);
}

template <class tipo>
void Tree<tipo>::insertarRaiz(tipo item)
{
    link new_node=(link)new node<tipo>;
    new_node->right=NULL;
    new_node->left=NULL;
    new_node->parent=NULL;
    new_node->item=item;
    rootInsertion(root,new_node);
}

template <class tipo>
void Tree<tipo>::print()
{
    imprimir(root,0);
}

template <class tipo>
bool Tree<tipo>::busqueda(tipo item)
{
    if (root!=NULL)
    return SearchBinaryTree(root,item);
    else return false;
}

template <class tipo>
void ordenador<tipo>::merge_func(tipo *a,int left, int mid,int right,int SIZE)
{
     int h,i,j,b[SIZE],k;
     h=left;
     i=left;
     j=mid+1;

     while((h<=mid)&&(j<=right))
     {
        if(a[h]<=a[j]){
        b[i]=a[h];
        h++;
        }
        else{
        b[i]=a[j];
        j++;
        }
      i++;
     }

     if(h>mid)
        for(k=j;k<=right;k++)
        {
        b[i]=a[k];
        i++;
        }
     else
        for(k=h;k<=mid;k++)
        {
        b[i]=a[k];
        i++;
        }

     for(k=left;k<=right;k++)
        a[k]=b[k];
}

template <class tipo>
void ordenador<tipo>::mergeSort(tipo *a,int left, int right,int n)
{
        if (right<=left)
            return;
        int mid=(right+left)/2;
        mergeSort(a,left,mid,n);
        mergeSort(a,mid+1,right,n);
        merge_func(a,left,mid,right,n);

}

template <class tipo>
void ordenador<tipo>::selectionSort(tipo *a,int n)
{
        int indexmin;
        for (int i=0;i<n-1;i++)
        {
            indexmin=i;
            for(int j=i+1;j<n;j++)
            {
                if (a[j]<a[indexmin])
                indexmin=j;
            }
            if(i!=indexmin)
            {
                tipo aux=a[i];
                a[i]=a[indexmin];
                a[indexmin]=aux;
            }
        }
}

template <class tipo>
void ordenador<tipo>::quickSort(tipo* a, int left, int right)
{
    int i,j, mid;
    tipo pivote;

    mid=(left+right)/2;
    pivote=a[mid];
    i=left;
    j=right;

    do{
        while (a[i]<pivote) i++;
        while (a[j]>pivote) j--;

        if (i<=j)
        {
            tipo aux=a[i];
            a[i]=a[j];
            a[j]=aux;
            i++;
            j--;
        }
    }while (i<=j);
    if (left<j)
        quickSort(a,left,j);
    if (i<right)
        quickSort(a,i,right);
}

int index;
template <class tipo>
void Tree<tipo>::BSTsort(link &raiz,tipo *a,int n)
{
    if(raiz==NULL)
        return;
    BSTsort(raiz->left,a,n);
    a[index]=raiz->item;index++;
    BSTsort(raiz->right,a,n);
}

template <class tipo>
void Tree<tipo>::BST(Tree<tipo> &arbol,tipo *a)
{
index=0;
BSTsort(arbol.root,a,0);
}


void generateRandomVector(int *a,int SIZE)
{
    int aux=0;
    for (int i=0;i<SIZE;i++)
    {
        aux+=rand()%4+1;
        a[i]=aux;
    }

    for (int i=0;i<2*SIZE;i++)
    {
        int k=rand()%SIZE;
        int j=rand()%SIZE;
        aux=a[k];
        a[k]=a[j];
        a[j]=aux;
    }
}

#endif // TREE_HPP_INCLUDED
