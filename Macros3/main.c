#include <stdio.h>
#include <stdlib.h>

#define declarray(type,var,istart,iend)\
type var[iend-istart+1];\
type *ptr=&var[istart];\

int main()
{
    int i=-5,j=10;
    declarray(double,x,i,j);

    for (int k=i;k<=j;k++){
        x[k]=k;
        printf("x[%d] = %lf\n",k,x[k]);
        }

    return 0;
}
