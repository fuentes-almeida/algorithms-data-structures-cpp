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
    printf("\nImpresion de Lista:\n");
    liga ptr=raiz;
    if (raiz==NULL)
        printf("La lista esta vacia\n");                      //no hay nodos para imprimir
    else if (raiz->tipo=='o'){
        do{
        printf("[%c]--> ",ptr->token.operador_binario);
        ptr=ptr->next;                                          //recorre la lista hasta el final
        }while(ptr!=NULL);}
        else{
            do{
        printf("[%.2f]--> ",ptr->token.flotante);               //imprime la etiqueta y la palabra del nodo
        ptr=ptr->next;                                          //recorre la lista hasta el final
        }while(ptr!=NULL);
        }
        printf("\n");
}

void popList(liga numeros, liga operadores)
{
    float temp;
    switch (operadores->token.operador_binario)
    {
    case '+':
        if (operadores->next&&operadores->next->token.operador_binario=='-'){
            temp=-numeros->next->token.flotante+numeros->token.flotante;
            operadores->next->token.operador_binario='+';break;}
        else {temp=numeros->next->token.flotante+numeros->token.flotante; break;}
    case '-':
        if (operadores->next&&operadores->next->token.operador_binario=='-'){
            temp=-numeros->next->token.flotante-numeros->token.flotante;
            operadores->next->token.operador_binario='+';break;}
        else {temp=numeros->next->token.flotante-numeros->token.flotante; break;}
    case '*': if (numeros->next){temp=numeros->next->token.flotante*numeros->token.flotante; break;}
    case '/': if (numeros->next){temp=numeros->next->token.flotante/numeros->token.flotante; break;}
    case '^': if (numeros->next){temp=pow(numeros->next->token.flotante,numeros->token.flotante); break;}
    }
    numeros->next->token.flotante=temp;
}

void ComputeResult(liga numeros, liga operadores)
{
    while (operadores)
        {
        popList(numeros,operadores);
        numeros=freeNode(numeros);
        operadores=freeNode(operadores);
        imprimeLista(numeros);
        imprimeLista(operadores);
        }
}

void ParseText(char* input, liga *numeros, liga *operadores)
{
    char temp[5]="+-*/^";
    char *number=RequestVectorCharMem(16);
    DATO item;
    char *test;
    int signo;
    int i=0;
    for (test=input;*test;++test)
    {
        if(strchr(temp,*test))
        {
            signo=1;
            if (*test=='-'&&(*(test-1)=='*'||*(test-1)=='/'||*(test-1)=='^')) signo=-1;
            else{item.flotante=signo*atof(number);
            *numeros=pushList(item,'n',*numeros);
            item.operador_binario=*test;
            if (*operadores)
            while (precedencia(item.operador_binario)<precedencia(operadores[0]->token.operador_binario)){
                popList(*numeros,*operadores);
                *numeros=freeNode(*numeros);
                *operadores=freeNode(*operadores);
                if (operadores[0]==NULL)break;
                }
            *operadores=pushList(item,'o',*operadores);}
            imprimeLista(*numeros);
            imprimeLista(*operadores);
            i=0;
            memset(number,' ',16);
            number[0]='x';
        }
        else number[i++]=*test;

    }
    item.flotante=signo*atof(number);
    *numeros=pushList(item,'n',*numeros);
    free(number);
}

