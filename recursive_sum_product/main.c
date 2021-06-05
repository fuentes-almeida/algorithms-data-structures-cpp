#include <stdio.h>
#include <stdlib.h>

int sumarImpares(int n)
{
    if(n%2==0) n--;
    if (n==1) return 1;
    else return n+sumarImpares(n-2);

}

double promedio(int n)
{
    if (n==1) return 1;
    else return ((n-1)*promedio(n-1)+n)/(double)n;
}

int main()
{
    int n;
    printf("Introduzca un entero: ");
    scanf("%d",&n);
    printf("\nEl promedio de los numeros de 1 a %d es: %lf",n,promedio(n));
    printf("\nLa suma de los impares de 1 a %d es: %d\n\n",n ,sumarImpares(n));
    return 0;
}
