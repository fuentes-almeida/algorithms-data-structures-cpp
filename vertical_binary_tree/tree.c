#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "tree.h"

liga createNode(liga raiz,int item)
{
    raiz=(node*)malloc(sizeof(node));
    raiz->item=item;
    raiz->der=NULL;
    raiz->izq=NULL;
    return raiz;
}

liga insertTreeNode(liga raiz, int item)
{
    if (raiz==NULL)
    return createNode(raiz, item);
    if (rand()%2==1)
        raiz->izq=insertTreeNode(raiz->izq,item);
    else raiz->der=insertTreeNode(raiz->der,item);
    return raiz;
}

int BinaryTreeHeigh(liga raiz)
{
    if (raiz==NULL)
        return 0;
    int nLeft = BinaryTreeHeigh(raiz->izq);
    int nRight = BinaryTreeHeigh(raiz->der);
    if (nLeft > nRight)
        return (nLeft + 1);
    else
        return (nRight + 1);
}

void printlevel(liga raiz, int level, int i,int len)
{
    if (raiz)
        {
        if (level == i){
            printf("%d", raiz->item);
            if (raiz->item<10)
                for (int k=0;k<len;k++) printf(" ");
            else for (int k=0;k<len-1;k++) printf(" ");
            }
        else
        {
            printlevel(raiz->izq, level, i+1,len/2);
            printlevel(raiz->der, level, i+1,len/2);
        }
        }
    else
        for (int k=0;k<len+1;k++) printf(" ");



}

void printTree(liga raiz,int heigh, int i)
{
    int len=2*(int)pow(2,heigh)-1;
    if(i==heigh) return;
    else
        for (int k=0;k<(int)pow(2,heigh-i)-1;k++)
            printf(" ");
        printlevel(raiz, i, 0,len);
        printf("\n");
    return printTree(raiz,heigh,i+1);
}

void freeLevel(liga raiz, int level, int i)
{
    if (raiz)
        {
        if (level == i){
            free(raiz);
            }
        else
        {
            freeLevel(raiz->izq, level, i+1);
            freeLevel(raiz->der, level, i+1);
        }
        }
}

liga FreeBinaryTree(liga raiz,int heigh)
{
    if(heigh<0) return raiz;
    else
        freeLevel(raiz, heigh, 0);
    FreeBinaryTree(raiz,heigh-1);
    return raiz;
}
