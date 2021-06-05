#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main()
{
    int n=5, m=6;

    double **x=matriz_double(n,m);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        x[i][j]=5;
    freematriz_double(x,n);

    return 0;
}
