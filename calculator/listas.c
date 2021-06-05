#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "memo.h"
#include "listas.h"

int precedencia(char operador)
{
    switch (operador)
    {
    case '+': return 1; break;
    case '-': return 1; break;
    case '*': return 2; break;
    case '/': return 2; break;
    case '^': return 3; break;
    default: return 0; break;
    }
}

liga createNode(DATO item, char tipo, liga next) //Crea un nodo
{
    liga ptr= (liga)malloc(sizeof(node));

    if (tipo=='o')
        ptr->token.operador_binario=item.operador_binario;
    else
        ptr->token.flotante=item.flotante;
    ptr->tipo=tipo;
    ptr->next=next;
    return ptr;
}

liga pushList(DATO item, char tipo, liga raiz)
{
    if(raiz==NULL){
        raiz=createNode(item,tipo, NULL);              //si la lista esta vacia, crea una raiz
        return raiz;
        }
    else{
        liga ptr=createNode(item,tipo,raiz);
        return ptr;
        }
}

liga freeNode(liga raiz)
{
    liga aux=raiz;
    raiz=raiz->next;
    free(aux);
    return raiz;
}

void imprimeLista(liga raiz)
{
    liga ptr=raiz;
    if (raiz==NULL){
        printf("NULL\n"); return;}   //no hay nodos para imprimir
    else if (raiz->tipo=='o'){
        printf("[%c]--> ",ptr->token.operador_binario);
        imprimeLista(raiz->next);                                         //recorre la lista hasta el final
        }
        else{
        printf("[%.2f]--> ",ptr->token.flotante);               //imprime la etiqueta y la palabra del nodo
        imprimeLista(raiz->next);
        }
}

void popList(liga *numeros, liga *operadores)
{
    switch (operadores[0]->token.operador_binario)
    {
    case '+': numeros[0]->next->token.flotante+=numeros[0]->token.flotante; break;
    case '-': numeros[0]->next->token.flotante-=numeros[0]->token.flotante; break;
    case '*': numeros[0]->next->token.flotante*=numeros[0]->token.flotante; break;
    case '/': numeros[0]->next->token.flotante/=numeros[0]->token.flotante; break;
    case '^': numeros[0]->next->token.flotante=pow(numeros[0]->next->token.flotante,numeros[0]->token.flotante); break;
    }
    *operadores=freeNode(*operadores);
    *numeros=freeNode(*numeros);
}

void ComputeResult(liga numeros, liga operadores)
{
    if (!operadores) return;
    else{
        popList(&numeros,&operadores);
        imprimeLista(numeros);
        imprimeLista(operadores);
        return ComputeResult(numeros, operadores);
        }
}

void ParseText(char* input, liga *numeros, liga *operadores)
{
    char temp[5]="+-*/^";
    char *number=RequestVectorCharMem(16);
    DATO item;
    char *test;

    int i=0;
    for (test=input;*test;++test)
    {
        if(strchr(temp,*test))
        {
            item.flotante=atof(number);
            *numeros=pushList(item,'n',*numeros);
            item.operador_binario=*test;
            if (*operadores)
            while (precedencia(item.operador_binario)<precedencia(operadores[0]->token.operador_binario)){
                popList(numeros,operadores);
                if (operadores[0]==NULL) break;
                }
            *operadores=pushList(item,'o',*operadores);
            imprimeLista(*numeros);
            imprimeLista(*operadores);
            i=0;
            memset(number,' ',16);
        }
        else number[i++]=*test;

    }
    item.flotante=atof(number);
    *numeros=pushList(item,'n',*numeros);
    free(number);
}

