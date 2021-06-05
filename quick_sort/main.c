#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sort.h"

int main()
{
    int n,key,*item;
    printf("Tamanio del arreglo: ");
    scanf("%d",&n);
    est *array;
    array=(est*)malloc(n*sizeof(est));
    srand(time(NULL));

    for (int i=0;i<n;i++){
        array[i].item1=(double)(100*HybridTaus());
        array[i].item2=(double)(100*HybridTaus());
    }

    printf("Before qsort\n");
    for (int i=0;i<n;i++)
        printf("[%lf,%lf]\n",array[i].item1,array[i].item2);

    qsort(array,n,sizeof(est),compara);

    printf("\nAfter qsort\n");
    for (int i=0;i<n;i++)
        printf("[%lf,%lf]\n",array[i].item1,array[i].item2);

    printf("\nNumero entero a buscar: ");
    scanf("%d",&key);
    item=(int*)bsearch(&key,array,n,sizeof(est),compara2);

    if (item)
    printf("Numero entontrado\n");
    else printf("Numero no encontrado\n");
    free(array);
    return 0;
}
