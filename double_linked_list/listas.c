#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listas.h"
#include "memo.h"

liga creaLista(int nnodos,int der)
{
    double dato;
    scanf("%lf",&dato);
    liga raiz;
    if (nnodos>0)
    {
        raiz=(node*)malloc(sizeof(node));
        raiz->item=dato;
        if (der){
            raiz->izq=NULL;
            raiz->der=creaLista(nnodos-1,der);
        }
        else {
            raiz->der=NULL;
            raiz->izq=creaLista(nnodos-1,der);
        }
    }
    else return NULL;
    return raiz;
}

void imprimeListaDerecha(liga raiz)
{
    liga ptr=raiz;
    if (raiz==NULL){
        printf("NULL\n"); return;}   //no hay nodos para imprimir
    else{
        printf("[%lf]-->",ptr->item);
        imprimeListaDerecha(raiz->der);
        }
}

void imprimeListaIzquierda(liga ultimo)
{
    liga ptr=ultimo;
    if (ultimo==NULL){
        printf("NULL\n"); return;}    //no hay nodos para imprimir
        else{
        printf("[%lf]-->",ptr->item);
        imprimeListaIzquierda(ultimo->izq);
        }
}

liga dobleLigar(liga raiz)                      //devuelve apuntador al ultimo nodo
{
    liga ptr=raiz;
    if (ptr==NULL)return NULL;              //si la lista esta vacia regresa NULL
    while (ptr->der!=NULL)
    {
        liga aux=ptr;
        ptr=ptr->der;
        ptr->izq=aux;
    }
    return ptr;
}

liga FindNode(double key, liga raiz, double epsilon, liga aux)
{
    if (raiz==NULL) return aux;
    if (fabs(key-raiz->item)<epsilon)
        aux=raiz;
    return FindNode(key,raiz->der,fabs(key-aux->item),aux);

}

liga regresaNth(int n,liga raiz)            //devuelve el apuntador al n-esimo nodo
{
    liga ptr=raiz;
    int i=n;                                //crea un contador de n a 1
    while(i>1){
        if (ptr==NULL)return NULL;          //si el nodo no existe regresa NULL
        ptr=ptr->der;                      //avanza al siquiente hasta que el contador lleque a 1
        i--;
        }
    return ptr;
}

double SumData(liga raiz, int der)
{
    if (raiz==NULL) return 0;
    else if (der) return raiz->item + SumData(raiz->der,der);
    else return raiz->item + SumData(raiz->izq, der);
}

int countNodes(liga raiz,int der)
{
    if (raiz==NULL) return 0;
    else if (der) return 1+countNodes(raiz->der,der);
    else return 1+countNodes(raiz->izq,der);
}

double Varianza(liga raiz, int der, double media)
{
    if (raiz==NULL) return 0;
    else if (der) return pow(raiz->item-media,2) +Varianza(raiz->der,der,media);
    else return pow(raiz->item-media,2) +Varianza(raiz->izq,der,media);
}

liga limpiarLista(liga raiz)                  //borra toda la lista con for
{
    liga ptr;
    for(ptr=NULL;raiz->der!=NULL;)                         //inicializa ptr y se sale hasta que quede solo la raiz
        {
        for(ptr=raiz;ptr->der->der!=NULL;ptr=ptr->der);  //recorre la lista hasta el penultimo
        liga temp=ptr->der;                                //apunta al ultimo nodo
        ptr->der=NULL;                                     //el penultimo ahora apunta a NULL
        free(temp);                                     //borra el ultimo nodo
        }
    ptr=raiz;                                               //borra la raiz
    raiz=NULL;
    free(ptr);
    return raiz;
}
