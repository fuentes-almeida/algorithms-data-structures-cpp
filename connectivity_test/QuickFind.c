#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
int N=1e4;
clock_t start, finish;
start = clock();

int i, p, q, id[N];
for (i=0; i<N; i++)
// initialization
id[i] = i;
while (scanf("%d %d",&p,&q)&&p>=0)
    {
    int t = id[p];
    if (t == id[q]) continue;
    // quick find
    for ( i=0; i<N; i++)
    // union
    if (id[i] == t ) id[i]=id[q];
    //printf("%d %d\n",p,q);
}
finish = clock();
double t= (double)(finish - start)/CLOCKS_PER_SEC ;
printf("%lf\t",t);

return 0;
}

