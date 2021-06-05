#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_vector.h>

// Asigna el valor de los parametros:
// npt    - numero de puntos a generar
// dsigma - desviacion estandar de la distribucion normal
void readParams(int argc, char **argv, int *npt, double *dsigma) {
    if(argc>1) *npt = atoi(argv[1]);
    else   *npt=100;
    if(argc>2) *dsigma = atof(argv[2]);
    else   *dsigma = 1.0;
}

// Genera npt puntos con distribucion normal, con media cero y desviacion
// estandar dsigma.
// Tambien calcula la media y varianza muestral de los puntos generados para
// comprobar.
void muestreoNormal(int npt, double dsigma) {
    const   gsl_rng_type *T;
    gsl_rng    *r;
    gsl_vector *x;

    int            i;
    double         dval, dmean, dev;
    unsigned int   seed;
    struct timeval tv;

    // Crea la semilla para el generador de numeros
    gettimeofday(&tv,0);
    seed = tv.tv_sec + tv.tv_usec;

    // Crea al generador de numeros r
    gsl_rng_env_setup();
    T = gsl_rng_default;
    r = gsl_rng_alloc (T);
    gsl_rng_set(r, seed);

    x = gsl_vector_alloc(npt);

    // Generamos los numeros y los almacenamos en x
    for(i=0; i<npt; i++)
        gsl_vector_set(x, i, gsl_ran_gaussian(r, dsigma));

    // Calculamos la media de los puntos
    dmean = 0;
    for(i=0; i<npt; i++)
        dmean += gsl_vector_get(x, i);
    dmean /= npt;

    // Calculamos la desviacion estandar de los puntos
    dev   = 0;
    for(i=0; i<npt; i++)   {
        dval   = gsl_vector_get(x, i) - dmean;
        dev   += dval*dval;
    }
    dev = sqrt(dev/(npt-1));

    printf("Media =%f | Desviacion=%f \n", dmean, dev);

    // Liberamos memoria
    gsl_rng_free(r);
    gsl_vector_free(x);
}


int main(int argc, char **argv)      {

    int     npt;
    double  dsigma;

    readParams(argc, argv, &npt, &dsigma);

    printf("   Numero de puntos: %d\n", npt);
    printf("Desviacion estandar: %f\n", dsigma);

    muestreoNormal(npt, dsigma);

    return 0;
}
// Para compilar
// gcc -o randomNormal randomNormal.c  -lgsl -lgslcblas -lm

// Para ejecutar
// ./randomNormal 120 3.5

