#include <stdio.h>
#include <stdlib.h>
#include "function.h"

#define defmemoria(type,dim) header1_##dim(type)

#define header1_1(type) type *vector_##type(int n)\
{\
type *p=(type*)malloc(n*sizeof(type));\
return p;\
}

#define header1_2(type) type **matriz_##type(int n,int m)\
{\
type **ptr=(type**)calloc(n,sizeof(type*));\
for (int i=0;i<n;i++)\
    ptr[i]=(type*)calloc(m,sizeof(type));\
return ptr;\
}

#define defliberar(type,dim) header2_##dim(type)

#define header2_1(type) void freevector_##type(type *ptr)\
{\
free(ptr);\
}

#define header2_2(type) void freematriz_##type(type **ptr,int n)\
{\
for (int i=0;i<n;i++)\
    free (ptr[i]);\
free (ptr);\
}


defmemoria(double,2);
defliberar(double,2);
