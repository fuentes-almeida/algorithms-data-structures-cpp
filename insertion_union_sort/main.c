#include <stdio.h>
#include <stdlib.h>
#include "memo.h"
#include <string.h>
#include "sort.h"

int main()
{
    int n;
    char tipo;
    scanf("%c %d",&tipo,&n);

    ESTRUCTURA *VECTOR=creaEstructura(n,tipo);
    printf("Datos leidos:\n");
    ImprimirVector(VECTOR,n,tipo);

    //InsertionSort(VECTOR,n);
    InsertionSort2(VECTOR,n,tipo);

    printf("\nOrdenamiento:\n");
    ImprimirVector(VECTOR,n,tipo);

    LiberarVector(VECTOR,n,tipo);

    return 0;
}
