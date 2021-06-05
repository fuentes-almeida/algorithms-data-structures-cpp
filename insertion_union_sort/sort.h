#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

typedef union dato{
    int entero;
    double doble;
    char *cadena;
    }DATO;

typedef struct estructura{
    DATO dato;
    char tipo;
    }ESTRUCTURA;

int Compare(ESTRUCTURA,DATO);
ESTRUCTURA *InsertionSort(ESTRUCTURA*,int);
int CompareString(ESTRUCTURA,char*);
ESTRUCTURA *InsertionSort2(ESTRUCTURA*,int,char);
ESTRUCTURA *creaEstructura(int, char);
void ImprimirVector(ESTRUCTURA*, int,char);
void LiberarVector(ESTRUCTURA*, int,char);


#endif // SORT_H_INCLUDED
