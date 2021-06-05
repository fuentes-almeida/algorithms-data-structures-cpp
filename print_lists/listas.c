#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

liga createNode(int item, liga next)        //Crea un nodo
{
    liga ptr= (liga)malloc(sizeof(node));   //asigna memoria dinamica
    ptr->item=item;                         //asigna item por parametro
    ptr->next=next;                         //asigna apuntador a siguiente por parametro
    return ptr;
}


liga insertarAlInicio(int item,liga raiz)   //inserta un nodo al inicio de la lista
{
    liga ptr=(liga)malloc(sizeof(node));
    ptr->item=item;
    ptr->next=raiz;
    return ptr;
}

liga insertaAlFinal(int item,liga raiz)     //inserta un nodo al final de la lista
{
    liga ptr=raiz;
    if(ptr==NULL)
        ptr=createNode(item,NULL);          //si no hay otro nodo, crea uno
    else{
        for (;ptr->next;)                   //camina toda la lista hasta el ultimo nodo, para insertar el nuevo
            ptr=ptr->next;
    ptr->next=createNode(item,NULL);
    }
    return raiz;
}

void imprimeLista(liga raiz)
{
    printf("\nImpresion de Lista:\n");
    liga ptr=raiz;
    if (raiz==NULL)
        printf("La lista esta vacia\n");    //no hay nodos para imprimir
    else{
        do{
            printf("%d---->",ptr->item);    //imprime el valor del nodo
            ptr=ptr->next;                  //avanza al siguiente
        }while(ptr!=NULL);
        printf("\n");
    }
}

liga regresaNth(int n,liga raiz)            //devuelve el apuntador al n-esimo nodo
{
    liga ptr=raiz;
    int i=n;                                //crea un contador de n a 1
    while(i>1){
        if (ptr==NULL)return NULL;          //si el nodo no existe regresa NULL
        ptr=ptr->next;                      //avanza al siquiente hasta que el contador lleque a 1
        i--;
        }
    return ptr;
}

liga ultimo(liga raiz)                      //devuelve apuntador al ultimo nodo
{
    liga ptr=raiz;
    if (ptr==NULL)return NULL;              //si la lista esta vacia regresa NULL
    while (ptr->next!=NULL)                 //avanza hasta el ultimo nodo
        ptr=ptr->next;
    return ptr;
}

int longitud(liga raiz)                     //regresa el numero de nodos
{
    int count=0;                            //inicializa contador
    liga ptr=raiz;
    do{
        count++;
        ptr=ptr->next;                      //camina toda la lista, contando los nodos
        }while(ptr!=NULL);
    return count;
}

liga quitaPrimero(liga raiz)                //borra el primer nodo
{
    liga ptr;
    ptr=raiz->next;                         //guarda el apuntador al siguiente nodo
    free(raiz);                             //libera raiz
    return ptr;                             //regresa el segundo nodo como raiz
}

liga quitaUltimo(liga raiz)                 //borra el ultimo nodo
{
    liga ultimo=raiz;                       //crea 2 apuntadores
    liga penultimo=raiz;
    if(raiz!=NULL){                         //si la lista esta vacia, sale
        if(ultimo->next == NULL){           //si la lista solo tiene un nodo, lo borra
            raiz = NULL;                    //y devuelve la lista vacia
            free(ultimo);
            }
    else{
        while(ultimo->next != NULL){        //recorre la lista hasta el penultimo nodo
            penultimo = ultimo;             //apuntador al penultimo nodo
            ultimo = ultimo->next;          //apundator al ultimo nodo
            }
        penultimo->next = NULL;             //se borra el ultimo nodo y el penultimo se apunta a NULL
        free(ultimo);
        }
    }
    return raiz;
}

liga limpiar(liga raiz)                     //Limpia toda la lista
{
    while(raiz!=NULL){                      //si la lista esta vacia, devuelve la raiz nula
        raiz=quitaUltimo(raiz);             //quita el ultimo nodo hasta que la lista este vacia
        }
    return raiz;
}

