#include <stdio.h>
#include <stdlib.h>

void CasoBase(char desde, char hasta)
{
    printf("Mueva el disco superior del poste %c al poste %c\n",desde,hasta);
}

void MoverDiscos(int n, char desde, char hasta, char usando)
{
    if (n>=1)
    {
        MoverDiscos(n-1,desde,usando,hasta);
        CasoBase(desde, hasta);
        MoverDiscos(n-1,usando,hasta,desde);
    }
}
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
    printf("Introduzca entero ");
    scanf("%d",&n);
    printf("%lf",promedio(n));
    //printf("%d",sumarImpares(n));
    //MoverDiscos(n,'B','C','A');
    return 0;
}
