#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "function.h"

double evalPolinomio(double *coefs, int grado, double x)
{
    double Px=0;
    for (int i=0; i<=grado; i++)
        {
            Px+=coefs[i]*pow(x,i);
        }
    return Px;


}


void biseccion(double a, double b, int max_iter, double tolerance, int grado, double *coefs)
{
  int i;             // contador de iteraciones
  double x1, x2, x3; // punto inicial, intermedio y final del intervalo actual
  x1 = a;
  x3 = b;
  if (evalPolinomio(coefs,grado,x1) * evalPolinomio(coefs,grado,x3) < 0.0){ // verifica si hay una raiz en el intervalo
        for (i = 1; i <= max_iter; i++)
        {
          x2 = (x1 + x3) / 2.0;// encuentra cual mitad del intervalo contiene la raiz
          if (evalPolinomio(coefs,grado,x1) * evalPolinomio(coefs,grado,x2) <= 0.0){ // la raiz esta en la mitad izquierda del intervalo
            x3 = x2;
          }
          else{
            x1 = x2;// la raiz esta en la mitad derecha del intervalo
          }
          if (fabs(evalPolinomio(coefs,grado,x2)) < tolerance){
            printf("Se encontro una raiz en x = %lf \n",x2);
            return;
          }
        }
    }
    else {printf("No se cumple la condicion necesaria para efectuar el algoritmo de Biseccion");

    }

}
