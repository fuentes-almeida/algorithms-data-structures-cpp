#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "connectivity.h"

int main()
{

    /*srand(time(NULL));
    for (int i=0;i<2*3e6;i++){
    printf("%ld\t",giveMeRandomNPot10(4));
    }
    printf("%d %d",-1,-1);
    return 0;*/
    int N=1e4;

   QuickFind(N);
    QuickUnion(N);
   WeightedQuickUnion(N);
}

