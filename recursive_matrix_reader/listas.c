#include <stdio.h>
#include <stdlib.h>
#include "memo.h"
#include "listas.h"

void readArray(double *array,int m,liga ptr)
{
    if (m<1) return;
    ptr->cadena[m-1]=array[m-1];
    readArray(array,m-1,ptr);
}

liga createNode(double *array, int m,liga next)        //Crea un nodo
{
    liga ptr= (liga)malloc(sizeof(node));   //asigna memoria dinamica
    ptr->cadena=RequestVectorDoubleMem(m);
    readArray(array,m,ptr);                    //asigna item por parametro
    ptr->next=next;
                     //asigna apuntador a siguiente por parametro
    return ptr;
}

liga crearLista(double *array,int m,liga raiz)     //inserta un nodo al final de la lista
{
    liga ptr=raiz;
    if(raiz==NULL){
        raiz=createNode(array,m,NULL);
}        //si no hay otro nodo, crea uno
    else{
        for (;ptr->next;)                   //camina toda la lista hasta el ultimo nodo, para insertar el nuevo
            ptr=ptr->next;
    ptr->next=createNode(array,m,NULL);
    }
    return raiz;
}

double *LeerArray(double *array,FILE *input,int i,int m)
{
    if (i==m) return array;
    else {
        fscanf(input,"%lf",&array[i]);
        return LeerArray(array,input,i+1,m);
        }
}

liga LeerMatriz(liga raiz, double *array,FILE *input,int n,int m)
{
    if (n==0)
        return raiz;
    array=LeerArray(array,input,0,m);

    raiz=crearLista(array,m,raiz);

    return LeerMatriz(raiz,array,input,n-1,m);

}

void imprimeRenglon(liga raiz, int m,int count)
{
    if (count==m) return;
    printf("%lf ",raiz->cadena[count]);
    return imprimeRenglon(raiz,m,count+1);
}

void imprimeMatriz(liga raiz,int m)
{
    if (raiz==NULL)  return;  //no hay nodos para imprimir
    else{
            imprimeRenglon(raiz,m,0);
            printf("\n");
        }
    return imprimeMatriz(raiz->next,m);
}

liga limpiarLista(liga raiz)                  //borra toda la lista con for
{
    liga ptr;
    for(ptr=NULL;raiz->next!=NULL;)                         //inicializa ptr y se sale hasta que quede solo la raiz
        {
        for(ptr=raiz;ptr->next->next!=NULL;ptr=ptr->next);  //recorre la lista hasta el penultimo
        liga temp=ptr->next;                                //apunta al ultimo nodo
        ptr->next=NULL;                                     //el penultimo ahora apunta a NULL
        free(temp->cadena);
        free(temp);                                     //borra el ultimo nodo
        }
    ptr=raiz;                                               //borra la raiz
    raiz=NULL;
    free(ptr->cadena);
    free(ptr);
    return raiz;
}

