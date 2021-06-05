#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "tree.h"

int main()
{
    srand(time(NULL));
    liga raiz=NULL;
    int n;
    printf("Numero de datos: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        raiz=insertTreeNode(raiz,rand()%100+1);
    int heigh=BinaryTreeHeigh(raiz);
    printTree(raiz,heigh,0);
    FreeBinaryTree(raiz,heigh);

    return 0;
}
