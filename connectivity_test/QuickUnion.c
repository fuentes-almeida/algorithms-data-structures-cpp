#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
int N=1e4;
clock_t start, finish;
start = clock();

int i, j, p, q, id[N];
for (i=0; i<N; i++)
id[i] = i;
while ( scanf("%d %d",&p,&q)&&p>=0 ){
       for (i=p; i!=id[i]; i=id[i]);
// find
       for (j=q; j!=id[j]; j=id[j]);
       if(i==j) continue;
       id[i]=j;
// quick union
//printf("%d %d\n",p,q);
}

finish = clock();
double t=  (double)(finish - start)/CLOCKS_PER_SEC ;
printf("%lf\t",t);

return 0;
}
