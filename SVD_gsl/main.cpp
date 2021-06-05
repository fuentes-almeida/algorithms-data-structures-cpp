#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_eigen.h>


// Lee el valor de los parametros y los asigna a las variables:
// cfile1   - Nombre del archivo de la matriz
// cfile2   - Nombre del archivo del vector
void readParams(int argc, char **argv, char *cfile1) {
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
    int n,scale;char format[2];
    fscanf(f1,"%s %d %d %d",format,&n,&n,&scale);

    mat = gsl_matrix_alloc(n, n);

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            fscanf(f1,"%lf",&mat->data[i*n+j]);
    //gsl_matrix_fread(f1, mat);
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

// Imprime en la consola las entradas del vector
void printVector(gsl_vector *vec) {
    unsigned int i;
    double *ptr = vec->data;
    for(i=0; i<vec->size; ++i)
	printf("% 8.4f   ", ptr[i]);
    printf("\n");
}

// Lectura de los datos del sistema lineal de los archivos dados
void printInfo(char *cfile1, gsl_matrix *mA) {
    if(mA==NULL) {
	printf("El archivo %s no puedo ser leido.\n", cfile1);
	exit(0);
    }

    printf("Dimensiones de la matriz: %d x %d\n", mA->size1, mA->size2);
    if(mA->size1<=10) {
	printf("Matriz del sistema: \n");
	printMatrix(mA);
    }
}

// Calcula solo los eigenvalores de la matriz
void eigenvalues(char *cfile1) {
    gsl_matrix *mA;
    gsl_vector *eig;
    gsl_eigen_symm_workspace *workspace;

    // Leemos los datos del sistema lineal
    mA  = readMatrix(cfile1);

    printInfo(cfile1, mA);

    eig       = gsl_vector_alloc(mA->size1);
    workspace = gsl_eigen_symm_alloc(mA->size1);

    // Calcula solo los eigenvalores de la matriz, la cual
    // es modificada en el proceso.
    gsl_eigen_symm(mA, eig, workspace);

    printf("\nEigenvalores: ");
    printVector(eig);

    gsl_matrix_free(mA);
    gsl_vector_free(eig);
    gsl_eigen_symm_free(workspace);
}

// Calcula el valor minimo y maximo de las entradas de la matriz A*V - V*D,
// donde V es la matriz de eigenvectores y D es la matriz diagonal con los
// eigenvalores.
void evalError(gsl_matrix *mA, gsl_matrix *mV, gsl_vector *eigval) {
    gsl_matrix  *mD, *mAV, *mVD;
    int          i;
    double       dmin, dmax;

    mAV       = gsl_matrix_alloc(mA->size1, mA->size2);
    mVD       = gsl_matrix_alloc(mA->size1, mA->size2);
    mD        = gsl_matrix_alloc(mA->size1, mA->size2);

    // Primero, creamos una matriz diagonal D que tiene los eigenvalores
    gsl_matrix_set_zero(mD);
    for(i=0; i<mA->size1; ++i)
       gsl_matrix_set(mD, i, i, gsl_vector_get(eigval, i));

    // Calculamos el producto de A*V
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, mA, mV, 0.0, mAV);
    // Calculamos el producto de V*D
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, mV, mD, 0.0, mVD);

    // Calculamos la resta de las matrices A*V - V*D, y almacenamos
    // el resultado en la propia matriz mAV.
    gsl_matrix_sub(mAV, mVD);

    // Obtenemos el valor de la entrada de la matriz mas chica y
    // la mas grande, y esperamos que ambas sean peque~nas.
    dmin = gsl_matrix_min(mAV);
    dmax = gsl_matrix_max(mAV);
    printf("\nRango de las entradas de matriz AV-VD: [%e, %e]\n", dmin, dmax);

    gsl_matrix_free(mAV);
    gsl_matrix_free(mVD);
    gsl_matrix_free(mD);
}

// Calcula los eigenvalores y los eigenvectores de una matriz
void SVDdecomposition(char *cfile1) {
    gsl_matrix *mA, *mAt,*mAcopy, *eigvec, *mD, *mU, *mVD;
    gsl_vector *eigval;
    gsl_eigen_symmv_workspace *workspace;

    // Leemos los datos del sistema lineal
    mA  = readMatrix(cfile1);
    printInfo(cfile1, mA);

    mAt=gsl_matrix_alloc(mA->size1, mA->size2);

    //gsl_matrix_transpose_memcpy(mAt,mA);


    gsl_blas_dgemm(CblasTrans, CblasNoTrans, 1.0, mA, mA, 0.0, mAt);

    printInfo(cfile1, mAt);

    // Reservamos memoria para hacer los calculos
    eigvec    = gsl_matrix_alloc(mAt->size1, mAt->size2);
    workspace = gsl_eigen_symmv_alloc(mAt->size1);
    eigval    = gsl_vector_alloc(mAt->size1);
    mAcopy    = gsl_matrix_alloc(mAt->size1, mAt->size2);

    // Hacemos una copia de la matriz porque la funcion que calcula
    // los eigenvalores modifica la matriz
    gsl_matrix_memcpy(mAcopy, mAt);

    // Calcula eigenvalores y eigenvectores de la matriz, la cual
    // es modificada en el proceso.
    gsl_eigen_symmv(mAcopy, eigval, eigvec, workspace);

    if(mA->size1<10) {
	// Imprimimos los resultados
	printf("\nEigenvalores: ");
	printVector(eigval);
	printf("\nEigenvectores: \n");
	printMatrix(eigvec);
    }

    // Adicionalmente podemos verificar que lo que calculamos
    // cumpla las relaciones de eigenvalor-eigenvector. Es decir,
    // que si V es la matriz de eigenvectores y D la matriz
    // diagonal con los eigenvalores, se debe cumplir que A*V = V*D.
    //evalError(mA, eigvec, eigval);

    mD = gsl_matrix_alloc(mA->size1, mA->size2);


    gsl_matrix_set_zero(mD);
    for(int i=0; i<mA->size1; ++i)
       gsl_matrix_set(mD, i, i, sqrt(gsl_vector_get(eigval, i)));

    printInfo(cfile1, mD);

    mU=gsl_matrix_alloc(mA->size1, mA->size2);

    gsl_blas_dgemm(CblasNoTrans, CblasTrans, 1.0, mA, eigvec, 0.0, mU);

    printInfo(cfile1, mU);

    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, mU, mD, 0.0, mU);

    printInfo(cfile1, mU);


    gsl_matrix_free(mA);
    gsl_matrix_free(mAcopy);
    gsl_vector_free(eigval);
    gsl_matrix_free(eigvec);
    gsl_eigen_symmv_free(workspace);
}


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
    SVDdecomposition(cfile1);


    return(0);
}
// Para compilar:
// gcc -o eigenvals eigenvals.c  -lgsl -lgslcblas -lm
//
// Para ejecutar:
// ./eigenvals mA13.bin

