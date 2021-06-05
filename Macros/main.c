#include <stdio.h>
#include <stdlib.h>

#define NOMBRE(V) #V
#define vector(var,type,tam)\
{\
var=(type*)malloc(tam*sizeof(type));\
}

#define matriz(var,type,tam1,tam2)\
{\
var=(type**)calloc(tam1,sizeof(type*));\
for (int i=0;i<tam1;i++)\
    var[i]=(type*)calloc(tam2,sizeof(type));\
}


void freeMatrizDouble(double **matriz, int w){
    int i;
    for( i=0;i<w;i++)
        free(matriz[i]);
    free(matriz);
}

int main()
{
    double *x;
    vector(x,double,10);
    printf("Se definio un arreglo tipo %s\n",NOMBRE(double));

    int m=5,n=7;
    double **y;
    matriz(y,double,m,n);
    printf("Se definio una matriz tipo %s\n",NOMBRE(double));

    free(x);
    freeMatrizDouble(y,m);

    return 0;
}
