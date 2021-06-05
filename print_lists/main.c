#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main()
{
    liga raiz=NULL;
    int nodes;

    printf("Creando nodo raiz con valor 1...\n");
    raiz=createNode(1,NULL);
    imprimeLista(raiz);

    printf("\nInsertando 3 nodos al final...\n");
    raiz=insertaAlFinal(2,raiz);
    raiz=insertaAlFinal(3,raiz);
    raiz=insertaAlFinal(4,raiz);
    imprimeLista(raiz);

    printf("\nInsertando 3 nodos al inicio...\n");
    raiz=insertarAlInicio(5,raiz);
    raiz=insertarAlInicio(6,raiz);
    raiz=insertarAlInicio(7,raiz);
    imprimeLista(raiz);

    printf("\nQuitando primero y ultimo nodo...\n");
    raiz=quitaPrimero(raiz);
    raiz=quitaUltimo(raiz);
    imprimeLista(raiz);

    nodes=longitud(raiz);
    printf("\nNumero de nodos: %d",nodes);

    liga ptr;
    ptr=regresaNth(3,raiz);
    if(ptr==NULL) printf("\nnull");
    else printf("\nValor del tercer nodo: %d",ptr->item);

    ptr=ultimo(raiz);
    if(ptr==NULL) printf("\nnull");
    else printf("\nValor del ultimo nodo: %d",ptr->item);

    printf("\n\nLimpiando la lista...");
    raiz=limpiar(raiz);
    imprimeLista(raiz);

    return 0;
}
