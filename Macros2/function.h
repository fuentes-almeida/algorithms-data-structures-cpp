#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#define decmemoria(type,dim) macro1_##dim(type)

#define macro1_1(type) type *vector_##type(int);
#define macro1_2(type) type **matriz_##type(int,int);

#define decliberar(type,dim) macro2_##dim(type)

#define macro2_1(type) void freevector_##type(type *ptr);
#define macro2_2(type) void freematriz_##type(type **ptr,int n);

decmemoria(double,2);
decliberar(double,2);

#endif // FUNCTION_H_INCLUDED
