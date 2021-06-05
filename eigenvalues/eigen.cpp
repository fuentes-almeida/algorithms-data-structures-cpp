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

// Lee el valor de los parametros y los asigna a las variables:
// cfile1   - Nombre del archivo de la matriz
// cfile2   - Nombre del archivo del vector
void readParams(int argc, char **argv, char *cfile1)
{
    if(argc>1) strcpy(cfile1, argv[1]);
}

// Lectura del vector en el archivo cfile.
// Devuelve NULL si no se pudo abrir el archivo.
gsl_vector *readVector(char *cfile) {
    gsl_vector *vec;
    int         nr;
    FILE       *f1 = fopen(cfile, "rb");

    if(!f1) return(NULL);
    fread(&nr, sizeof(int), 1, f1);
    vec = gsl_vector_alloc(nr);
    gsl_vector_fread(f1, vec);
    fclose(f1);
    return(vec);
}


// Lectura de la matriz en el archivo cfile.
// Devuelve NULL si no se pudo abrir el archivo.
gsl_matrix *readMatrix(char *cfile) {
    gsl_matrix *mat;
    int         nr, nc;
    FILE       *f1 = fopen(cfile, "rb");

    if(!f1) return(NULL);
    fread(&nr, sizeof(int), 1, f1);
    fread(&nc, sizeof(int), 1, f1);
    mat = gsl_matrix_alloc(nr, nc);
    gsl_matrix_fread(f1, mat);
    fclose(f1);
    return(mat);
}


// Devuelve un doble apuntador para poder trabajar con las
// entradas de las matriz mat con un arreglo bidimensional
double **gslmat2array2d(gsl_matrix *mat) {
    double **array2d;
    unsigned int i;

    array2d = (double **) malloc(mat->size1 * sizeof(double *));
    if(array2d==NULL) return(NULL);

    for(i=0; i<mat->size1; ++i)
       array2d[i] = mat->data + mat->size2*i;
    return(array2d);
}

double **gslcomplexmat2array2d(gsl_matrix_complex *mat) {
    double **array2d;
    unsigned int i;

    array2d = (double **) malloc(mat->size1 * sizeof(double *));
    if(array2d==NULL) return(NULL);

    for(i=0; i<mat->size1; ++i)
       array2d[i] = mat->data + 2*mat->size2*i;
    return(array2d);
}


// Imprime en la consola las entradas de la matriz
void printMatrix(gsl_matrix *mat) {
    unsigned int i, j;
    double **arr = gslmat2array2d(mat);
    for(i=0; i<mat->size1; ++i) {
	for(j=0; j<mat->size2; ++j)
	    printf("% 8.4f   ", arr[i][j]);
	printf("\n");
    }
    free(arr);
}

void printComplexMatrix(gsl_matrix_complex *mat) {
    unsigned int i, j;
    double **arr = gslcomplexmat2array2d(mat);
    for(i=0; i<mat->size1; i++) {
	for(j=0; j<2*mat->size2; j+=2)
	    printf("[%.4lf,%.4lfi] ", arr[i][j],arr[i][j+1]);
	printf("\n");
    }
    free(arr);
}

// Imprime en la consola las entradas del vector
void printVector(gsl_vector_complex *vec) {
    unsigned int i;
    double *ptr = vec->data;
    for(i=0; i<2*vec->size; i+=2)
	printf("\n[%.4lf,%.4lfi]", ptr[i],ptr[i+1]);
    printf("\n");
}

// Lectura de los datos del sistema lineal de los archivos dados
void printInfo(char *cfile1, gsl_matrix *mA) {
    if(mA==NULL) {
	printf("El archivo %s no puedo ser leido.\n", cfile1);
	exit(0);
    }

    printf("Dimensiones de la matriz: %d x %d\n", (int)mA->size1,(int)mA->size2);
    if(mA->size1<10) {
	printf("Matriz del sistema: \n");
	printMatrix(mA);
    }
}

// Calcula solo los eigenvalores de la matriz
void eigenvalues(char *cfile1) {
    gsl_matrix *mA;
    gsl_vector_complex *eig;
    gsl_eigen_nonsymm_workspace *workspace;

    // Leemos los datos del sistema lineal
    mA  = readMatrix(cfile1);

    printInfo(cfile1, mA);

    eig       = gsl_vector_complex_alloc(mA->size1);
    workspace = gsl_eigen_nonsymm_alloc(mA->size1);

    // Calcula solo los eigenvalores de la matriz, la cual
    // es modificada en el proceso.
    gsl_eigen_nonsymm(mA, eig, workspace);

    printf("\nEigenvalores: ");
    printVector(eig);

    gsl_matrix_free(mA);
    gsl_vector_complex_free(eig);
    gsl_eigen_nonsymm_free(workspace);
}

// Calcula el valor minimo y maximo de las entradas de la matriz A*V - V*D,
// donde V es la matriz de eigenvectores y D es la matriz diagonal con los
// eigenvalores.
void evalError(gsl_matrix *mA, gsl_matrix_complex *mV, gsl_vector_complex *eigval) {
    gsl_matrix_complex  *mD, *mAV, *mVD, *mAcopy;
    gsl_matrix *mAVcopy;
    unsigned int          i;
    double       dmin, dmax;

    mAVcopy   = gsl_matrix_alloc(mA->size1, mA->size2);
    mAcopy    = gsl_matrix_complex_alloc(mA->size1, mA->size2);
    mAV       = gsl_matrix_complex_alloc(mA->size1, mA->size2);
    mVD       = gsl_matrix_complex_alloc(mA->size1, mA->size2);
    mD        = gsl_matrix_complex_alloc(mA->size1, mA->size2);

    for ( i=0;i<2*mA->size1*mA->size2;i+=2)
        mAcopy->data[i]=mA->data[i/2];

    // Primero, creamos una matriz diagonal D que tiene los eigenvalores
    gsl_matrix_complex_set_zero(mD);
    for(i=0; i<mA->size1; ++i)
       gsl_matrix_complex_set(mD, i, i, gsl_vector_complex_get(eigval, i));

    gsl_complex alpha,beta;
        alpha.dat[0]=1.0;
        beta.dat[0]=0.0;

    // Calculamos el producto de A*V
    gsl_blas_zgemm(CblasNoTrans, CblasNoTrans, alpha, mAcopy, mV, beta, mAV);
    // Calculamos el producto de V*D
    gsl_blas_zgemm(CblasNoTrans, CblasNoTrans, alpha, mV, mD, beta, mVD);

    // Calculamos la resta de las matrices A*V - V*D, y almacenamos
    // el resultado en la propia matriz mAV.
    gsl_matrix_complex_sub(mAV, mVD);

    // Obtenemos el valor de la entrada de la matriz mas chica y
    // la mas grande, y esperamos que ambas sean peque~nas.
    for (i=0;i<mA->size1*mA->size2;i++)
        mAVcopy->data[i]=mAV->data[2*i];

    dmin = gsl_matrix_min(mAVcopy);
    dmax = gsl_matrix_max(mAVcopy);
    printf("\nRango de las entradas de matriz AV-VD: [%e, %e]\n", dmin, dmax);

    gsl_matrix_free(mAVcopy);
    gsl_matrix_complex_free(mAcopy);
    gsl_matrix_complex_free(mAV);
    gsl_matrix_complex_free(mVD);
    gsl_matrix_complex_free(mD);
}

// Calcula los eigenvalores y los eigenvectores de una matriz
void eigenvectors(char *cfile1) {
    gsl_matrix *mA, *mAcopy;
    gsl_matrix_complex *eigvec;
    gsl_vector_complex *eigval;
    gsl_eigen_nonsymmv_workspace *workspace;

    // Leemos los datos del sistema lineal
    mA  = readMatrix(cfile1);

    printInfo(cfile1, mA);

    // Reservamos memoria para hacer los calculos
    eigvec    = gsl_matrix_complex_alloc(mA->size1, mA->size2);
    workspace = gsl_eigen_nonsymmv_alloc(mA->size1);
    eigval    = gsl_vector_complex_alloc(mA->size1);
    mAcopy    = gsl_matrix_alloc(mA->size1, mA->size2);

    // Hacemos una copia de la matriz porque la funcion que calcula
    // los eigenvalores modifica la matriz
    gsl_matrix_memcpy(mAcopy, mA);

    // Calcula eigenvalores y eigenvectores de la matriz, la cual
    // es modificada en el proceso.
    gsl_eigen_nonsymmv(mAcopy, eigval, eigvec, workspace);

    if(mA->size1<10) {
	// Imprimimos los resultados
	printf("\nEigenvalores: ");
	printVector(eigval);
	printf("\nEigenvectores: \n");
	printComplexMatrix(eigvec);
    }

    // Adicionalmente podemos verificar que lo que calculamos
    // cumpla las relaciones de eigenvalor-eigenvector. Es decir,
    // que si V es la matriz de eigenvectores y D la matriz
    // diagonal con los eigenvalores, se debe cumplir que A*V = V*D.
    evalError(mA, eigvec, eigval);

    gsl_matrix_free(mA);
    gsl_matrix_free(mAcopy);
    gsl_vector_complex_free(eigval);
    gsl_matrix_complex_free(eigvec);
    gsl_eigen_nonsymmv_free(workspace);
}
