#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "newton.h"


int main()
{
    double x, epsilon; int maxIte;
    printf("Valor inicial: "); scanf("%lf",&x);
    printf("Tolerancia: "); scanf("%lf",&epsilon);
    printf("Iteraciones: "); scanf("%d",&maxIte);

    printf("\nMetodo iterativo: %lf",NewtonIterativo(x,epsilon,maxIte));
    printf("\nMetodo recursivo: %lf\n",NewtonRecursivo(x,epsilon,maxIte));

    return 0;
}
