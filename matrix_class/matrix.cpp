#include <iostream>
#include <stdlib.h>
#include "matrix.hpp"

using namespace std;

matrix matrix::operator+(const matrix& B)
{
    matrix C(n,m);
    if (B.m==m&&B.n==n){

    for (int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        C.M[i][j]=M[i][j]+B.M[i][j];

    }
    return C;
}

matrix matrix::operator-(const matrix& B)
{
       matrix C(n,m);
    if (B.m==m&&B.n==n){

    for (int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        C.M[i][j]=M[i][j]-B.M[i][j];

    }
return C;
}

void matrix::operator=(const matrix& B)
{

    if (B.m==m&&B.n==n){

    for (int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        M[i][j]=B.M[i][j];

    }
}

matrix matrix::operator-()
{

matrix C(n,m);
    for (int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        C.M[i][j]=-M[i][j];
return C;

}

matrix matrix::operator*(const matrix& B)
{
     matrix C(n,n);
if (B.m==n&&B.n==m){

    for ( int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            {
            double sum=0;
            for (int k = 0; k < m; ++k)
                sum+=M[i][k]*B.M[k][j];
                C.M[i][j]=sum;
            }
}
 return C;

}

matrix operator*(double escalar,const matrix& B)
{

matrix C(B.n,B.m);
        for ( int i = 0; i < B.n; ++i)
            for (int j = 0; j < B.m; ++j)
            C.M[i][j]=B.M[i][j]*escalar;

return C;

}

ostream& operator<<(ostream& out,const matrix& A)
{
    for (int i=0;i<A.n;i++){
        for (int j=0;j<A.m;j++)
        out<<A.M[i][j]<<" ";
    out<<endl;}
    cout<<endl;
        return out;
}

