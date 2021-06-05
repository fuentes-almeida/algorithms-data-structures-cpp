#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "eigen.hpp"

#include <gsl/gsl_math.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_eigen.h>

int main(int argc, char **argv)      {
    char    cfile1[50];

    // Lectura de los parametros
    readParams(argc, argv, cfile1);

    // Primero mostramos que podemos calcular solo
    // los eigenvalores de la matriz
    printf("------ Calculamos unicamente los eigenvalores ----------\n");
    eigenvalues(cfile1);

    // Luego calculamos tanto los  eigenvalores como los
    // eigenvectores  de la matriz
    printf("\n\n------ Calculamos eigenvalores y eigenvectores ------\n");
    eigenvectors(cfile1);


    return(0);
}
// Para compilar:
// gcc -o eigenvals eigenvals.c  -lgsl -lgslcblas -lm
//
// Para ejecutar:
// ./eigenvals mA13.bin


