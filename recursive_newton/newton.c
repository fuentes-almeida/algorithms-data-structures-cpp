#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "newton.h"

double f(double x)
{
    return x*x-25.0;
}
double d(double x, double h)
{
    return (f(x+h)-f(x-h))/(2.0*h);
}

double NewtonIterativo(double x0,double epsilon, int maxIte)
{
    double fx0=f(x0);
    int Ite=0;
    while (fabs(fx0)>epsilon&&Ite<maxIte)
    {
        x0=x0-fx0/d(x0,1.0e-5);
        fx0=f(x0);
        Ite++;
    }
    if (Ite>=maxIte) return NAN;
    return x0;
}

double NewtonRecursivo(double x0,double epsilon,int maxIte)
{
    if (maxIte==0)  return NAN;
    if (fabs(f(x0))<epsilon) return x0;
    else {
        x0=x0-f(x0)/d(x0,1.0e-5);
        return NewtonRecursivo(x0,epsilon,maxIte-1);
        }
}
