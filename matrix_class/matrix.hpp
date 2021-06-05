#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED
#include <iostream>
#include <stdlib.h>
using namespace std;

class matrix
{
private:
    int n;
    int m;
    double **M;
public:
    matrix(int a,int b)
    {
    n=a;m=b;
    M=(double **)calloc(n,sizeof(double*));
    for (int i=0;i<m;i++)
        M[i]=(double*)calloc(m,sizeof(double));
    for (int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            M[i][j]=100.0*rand()/RAND_MAX;
    }
    matrix(int a,int b,double x)
    {
    n=a;m=b;
    M=(double **)calloc(n,sizeof(double*));
    for (int i=0;i<m;i++)
        M[i]=(double*)calloc(m,sizeof(double));
    for (int i=0;i<n;i++)
            M[i][i]=x;
    }
    ~matrix()
    {
        for (int i=0;i<m;i++)
            delete M[i];
        delete M;
        cout<<"destruye"<<endl;
    }

    matrix operator+(const matrix& B);
    matrix operator-(const matrix& B);
    matrix operator*(const matrix& B);
    void operator=(const matrix& B);
    void operator/(double esca);
    friend ostream& operator<<(ostream& out,const matrix& A);
    matrix operator-();
    friend matrix operator*(double escalar,const matrix& B);

    matrix traspose()
    {
        matrix T(m,n);
        for (int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                T.M[j][i]=M[i][j];
            return T;
    }

};
#endif // MATRIX_HPP_INCLUDED
