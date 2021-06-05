#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "function.h"


int main()
{
    int max_iter=40; // número maximo de iteraciones
    int grad;
    double a, b; // extremos izquierdo y derecho del intervalo inicial
    double tolerance=1e-6; // tolerancia
    double *coefs;

    scanf("%d",&grad);
    coefs=(double*)malloc((grad+1)*sizeof(double));

    for (int i=0; i<=grad;i++)
      scanf("%lf",&coefs[i]);
    scanf("%lf %lf",&a,&b);

    biseccion(a, b, max_iter, tolerance, grad, coefs);

    return 0;
}
