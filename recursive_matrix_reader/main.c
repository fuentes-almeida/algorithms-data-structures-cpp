#include <stdio.h>
#include <stdlib.h>
#include "memo.h"
#include "listas.h"

int main()
{
    int n,m;
    FILE *input;
    input=fopen("matrix.dat","r");
    if (input==NULL)
        printf("No se pudo abrir el archivo");
    fscanf(input,"%d %d",&n,&m);
    double *array=RequestVectorDoubleMem(m);
    liga raiz=NULL;
    raiz=LeerMatriz(raiz,array,input,n,m);
    imprimeMatriz(raiz,m);
    limpiarLista(raiz);

    return 0;
}
