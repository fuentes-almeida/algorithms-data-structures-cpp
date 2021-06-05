#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct NODE{
    int item;
    struct NODE* der;
    struct NODE* izq;
}node;

typedef node* liga;

liga createNode(liga,int);
liga insertTreeNode(liga, int);
int BinaryTreeHeigh(liga);
void printlevel(liga, int, int ,int );
void printTree(liga,int, int );
void freeLevel(liga, int, int );
liga FreeBinaryTree(liga,int);

#endif // TREE_H_INCLUDED
