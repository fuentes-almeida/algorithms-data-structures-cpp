#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listas.h"
#include "memo.h"

int main()
{
    liga raiz;
    raiz=creaLista(10,1);
    printf("\nImpresion de Lista hacia la derecha:\n");
    imprimeListaDerecha(raiz);

    liga cola;
    cola=dobleLigar(raiz);
    printf("\nImpresion de Lista hacia la izquierda:\n");
    imprimeListaIzquierda(cola);

    liga aux=NULL;
    aux=FindNode(5.0,raiz,1000,aux);
    printf("\nNodo mas cercano a 5.0: %p = %lf",aux,aux->item);
    aux=raiz;
    raiz=regresaNth(6,raiz);

    printf("\nRaiz desplazada a %lf:",raiz->item);
    printf("\n\nSumatoria hacia la derecha: %lf",SumData(raiz,1));
    printf("\nSumatoria hacia la izquierda: %lf\n",SumData(raiz,0));

    printf("\nRaiz desplazada a %lf:",aux->item);
    printf("\nPromedio: %lf",SumData(aux,1)/countNodes(aux,1));
    printf("\nVarianza: %lf",(Varianza(aux,1,SumData(aux,1)/countNodes(aux,1)))/countNodes(aux,1));
    raiz=limpiarLista(aux);
    printf("\n\nLista borrada: ");
    imprimeListaDerecha(raiz);
    return 0;
}
