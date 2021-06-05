#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "memo.h"
#include <time.h>
int main()
{
    char cadena[128];
    int length,label=1,nodo;
    liga raiz=NULL;
    printf("Ingrese cualquier numero de cadenas (0-9 para continuar)\n");
    while(cadena[0]<'0'||cadena[0]>'9'){
        scanf("%s",cadena);
        if (cadena[0]<'0'||cadena[0]>'9'){
            length=strlen(cadena);
            raiz=crearLista(label,cadena,length,raiz);
            label++;
            }
        }
    imprimeLista(raiz);

    printf("\nPromedio de las etiquetas: %lf",promEtiquetas(raiz));
    imprimirFrase(raiz);

    printf("\nInvertir lista...");
    raiz=Invertir(raiz);
    imprimeLista(raiz);

    printf("\nDesordenando lista...");
    raiz=desordenarLista(raiz,30);
    imprimeLista(raiz);

    printf("\nNumero de nodo a eliminar: ");
    scanf("%d",&nodo);
    raiz=eliminarLista(raiz,nodo);
    imprimeLista(raiz);

    printf("\nIngrese palabra a eliminar: ");
    scanf("%s",cadena);
    raiz=eliminarNodo(raiz,cadena);
    imprimeLista(raiz);

    printf("\nBorrando Lista...");
    raiz=limpiarFor(raiz);
    imprimeLista(raiz);

    return 0;
}
