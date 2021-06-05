#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char **argv)
{
    if (argc<2){
        printf("Error, introduce el numero como parametro");
        return 0;
        }
    double x=atof(argv[1]);
    int maxcount=100,counter=0;
    double b,tolerance=1e-6;

    //printf("Introduce el valor de x: ");
   // scanf("%lf",&x);
    if (x<0){
    printf("Valor negativo, no se puede calcular la raiz");
    return 0;}

    b=x;
    while (fabs(b-x/b)>tolerance&&counter<maxcount)
        {
        b=(x/b+b)/2;
        counter++;
        }

    printf("La raiz de %lf es %lf",x,b);

    return 0;
}
