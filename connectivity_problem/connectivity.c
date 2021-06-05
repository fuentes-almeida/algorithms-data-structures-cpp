#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "connectivity.h"

long int giveMeRandomNPot10(int pot10)
{

        long int n=0,fact=1; //n es resultado y factor potencia de 10
        for(int i=0;i<pot10;i++){
            n += (rand() % 10) * fact;
            fact *=10;
        }
        return n;
}

void QuickUnion(int N)
{
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
printf("Finished!! ");
finish = clock();
double t=  (double)(finish - start)/CLOCKS_PER_SEC ;
printf("%lf\t",t);
}


void QuickFind(int N)
{
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
printf("Finished!! ");
finish = clock();
double t= (double)(finish - start)/CLOCKS_PER_SEC ;
printf("%lf\t",t);
}


void WeightedQuickUnion(int N)
{
clock_t start, finish;
start = clock();

int i, j, p, q, id[N], weight[N];
for (i=0; i<N; i++){
id[i] = i;
weight[i]=1;
}

while (scanf("%d %d",&p,&q)&&p>=0){
       for (i=p; i!=id[i]; i=id[i]);
// find
       for (j=q; j!=id[j]; j=id[j]);
       if(i==j) continue;
      if (weight[i]<weight[j]){
       id[i]=j;
       weight[j]+=weight[i];
       }
       else{
        id[j]=i;
        weight[i]+=weight[j];
       }
// quick union
//printf("%d %d\n",p,q);
}
printf("Finished!! ");
finish = clock();
double t=  (double)(finish - start)/CLOCKS_PER_SEC ;
printf("%lf\t",t);
}

