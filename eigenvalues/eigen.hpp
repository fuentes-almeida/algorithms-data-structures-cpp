#ifndef EIGEN_HPP_INCLUDED
#define EIGEN_HPP_INCLUDED

#include <gsl/gsl_math.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_eigen.h>

void readParams(int argc, char **argv, char *cfile1);
gsl_vector *readVector(char *cfile);
gsl_matrix *readMatrix(char *cfile);
double **gslmat2array2d(gsl_matrix *mat);
double **gslcomplexmat2array2d(gsl_matrix_complex *mat);
void printMatrix(gsl_matrix *mat);
void printComplexMatrix(gsl_matrix_complex *mat);
void printVector(gsl_vector_complex *vec) ;
void printInfo(char *cfile1, gsl_matrix *mA);
void eigenvalues(char *cfile1);
void evalError(gsl_matrix *mA, gsl_matrix_complex *mV, gsl_vector_complex *eigval);
void eigenvectors(char *cfile1);

#endif // EIGEN_HPP_INCLUDED
