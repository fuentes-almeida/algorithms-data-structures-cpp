#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double evalPolinomio(double *coefs, int grado, double x)
{
    double Px=0;
    for (int i=0; i<=grado; i++)
        {
            Px+=coefs[i]*pow(x,i);
        }
    return Px;


}

int main()
{
    int n;
    double x=0, *vector;
    scanf("%d",&n);

    vector=(double*)malloc((n+1)*sizeof(double));

    for (int i=0;i<=n;i++)
        scanf("%lf",&vector[i]);
    scanf("%lf",&x);

    printf("El valor del Polinomio leido es P(x) = %lf\n",evalPolinomio(vector,n,x));

    return 0;
}
