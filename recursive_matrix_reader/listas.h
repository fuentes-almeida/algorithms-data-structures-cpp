#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

typedef struct NODE{
    double *cadena;
    struct NODE* next;
}node;

typedef node* liga;

liga createNode(double*, int,liga );
liga crearLista(double*,int,liga);
double *LeerArray(double*,FILE*,int,int);
void imprimeMatriz(liga,int);
liga limpiarLista(liga);
liga LeerMatriz(liga raiz, double*,FILE*,int,int);

#endif // LISTAS_H_INCLUDED
