#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "newton.h"

double f(double x)
{
    return x*x+sin(x);
}
double d(double x)
{
    double h=1e-5;
    return (f(x+h)-f(x-h))/(2.0*h);
}

double MinimoIterativo(double x0,double epsilon, int maxIte)
{
    double alpha=1e-3;
    double dx0=d(x0);
    int Ite=0;
    while (fabs(dx0)>epsilon&&Ite<maxIte)
    {
        x0=x0-alpha*d(x0);
        dx0=d(x0);
        Ite++;
    }
    if (Ite>=maxIte) return NAN;
    return x0;
}

double MinimoRecursivo(double x0,double epsilon,int maxIte)
{
    double alpha=1e-3;
    if (maxIte==0)  return NAN;
    if (fabs(d(x0))<epsilon) return x0;
    else {
        x0=x0-alpha*d(x0);
        return MinimoRecursivo(x0,epsilon,maxIte-1);
        }
}
