#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *datos,int n,int key,int izq,int der){

     int index;
     if(izq<=der)
    {
        index=(izq+der)/2;

        if(key==datos[index])
            return index;

        else if(key<datos[index])
            return binarySearch(datos,n,key,izq,index-1);

        else
            return binarySearch(datos,n,key,index+1,der);
     }
     return -1;
}

int main()
{
    int *datos,n,key,index;

    printf("Tamanio del arreglo: ");
    scanf("%d",&n);

    datos=(int*)malloc(n*sizeof(int));

    printf("Elementos del arreglo (enteros): " );
    for(int i=0;i<n;i++)
         scanf("%d",&datos[i]);

    printf("Elemento a buscar: ");
    scanf("%d",&key);

    index=binarySearch(datos,n,key,0,n-1);

    if(index>0)
         printf("\nNumero encontrado en la posicion %d \n",index+1);
    else
         printf("\nNumero no encontrado\n");

    return 0;
 }

