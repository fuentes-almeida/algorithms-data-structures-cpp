#include <stdio.h>
#include <stdlib.h>
#include "memo.h"
#include <string.h>
#include "sort.h"

int Compare(ESTRUCTURA EST,DATO key)
{
    if (EST.tipo=='e')
        return EST.dato.entero>key.entero;
    else if (EST.tipo=='d')
        return EST.dato.doble>key.doble;
    else
        for(int i=0;i<strlen(key.cadena);i++)
            if (EST.dato.cadena[i]==key.cadena[i]) continue;
            else return EST.dato.cadena[i]>key.cadena[i];
    return 0;
}

ESTRUCTURA *InsertionSort(ESTRUCTURA *VECTOR,int n)
{
    for (int j=1;j<n;j++)
    {
        DATO key=VECTOR[j].dato;
        int i=j-1;
        while (i>=0 && Compare(VECTOR[i],key))
        {
            VECTOR[i+1].dato=VECTOR[i].dato;
            i=i-1;
        }
        VECTOR[i+1].dato=key;
    }
    return VECTOR;
}

int CompareString(ESTRUCTURA EST,char* key)
{
    for(int i=0;i<strlen(key);i++)
        if (EST.dato.cadena[i]==key[i]) continue;
        else return EST.dato.cadena[i]>key[i];
    return 0;
}

ESTRUCTURA *InsertionSort2(ESTRUCTURA *VECTOR,int n,char tipo)
{
    if (tipo!='c')
        for (int j=1;j<n;j++)
        {
            DATO key=VECTOR[j].dato;
            int i=j-1;
            while (i>=0 && Compare(VECTOR[i],key))
            {
                VECTOR[i+1].dato=VECTOR[i].dato;
                i=i-1;
            }
            VECTOR[i+1].dato=key;
        }
    else
        for (int j=1;j<n;j++)
        {
            char *key=RequestVectorCharMem(20);
            strcpy(key,VECTOR[j].dato.cadena);
            int i=j-1;
            while (i>=0 && CompareString(VECTOR[i],key))
            {
                strcpy(VECTOR[i+1].dato.cadena,VECTOR[i].dato.cadena);
                i=i-1;
            }
            strcpy(VECTOR[i+1].dato.cadena,key);
            free(key);
        }

    return VECTOR;
}

void ImprimirVector(ESTRUCTURA *VECTOR, int n,char tipo)
{
        if (tipo=='e')
            for (int i=0;i<n;i++)
                printf("%d\n",VECTOR[i].dato.entero);
        else if (tipo=='d')
            for (int i=0;i<n;i++)
                printf("%lf\n",VECTOR[i].dato.doble);
        else
            for (int i=0;i<n;i++)
                printf("%s\n",VECTOR[i].dato.cadena);
}

ESTRUCTURA *creaEstructura(int n, char tipo)
{
    ESTRUCTURA *VECTOR=(ESTRUCTURA*)malloc(n*sizeof(ESTRUCTURA));
    DATO elemento;

    if (tipo=='e')
    for (int i=0;i<n;i++){
    scanf("%d",&elemento.entero);
    VECTOR[i].dato=elemento;
    VECTOR[i].tipo=tipo;
    }

    else if (tipo=='d')
    for (int i=0;i<n;i++){
    scanf("%lf",&elemento.doble);
    VECTOR[i].dato=elemento;
    VECTOR[i].tipo=tipo;
    }

    else if (tipo=='c')
    for (int i=0;i<n;i++){
    elemento.cadena=RequestVectorCharMem(20);
    scanf("%s",elemento.cadena);
    VECTOR[i].dato.cadena=RequestVectorCharMem(20);
    strcpy(VECTOR[i].dato.cadena,elemento.cadena);
    VECTOR[i].tipo=tipo;
    free(elemento.cadena);
    }
    return VECTOR;
}

void LiberarVector(ESTRUCTURA *VECTOR, int n,char tipo)
{
    for (int i=0;i<n;i++){
        if (tipo=='c')
            free(VECTOR[i].dato.cadena);
    }
        free(VECTOR);
}
