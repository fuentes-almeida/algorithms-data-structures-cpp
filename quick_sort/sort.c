#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sort.h"

int compara(const void *a, const void *b)
{
    est A=*(est*)a;
    est B=*(est*)b;

    double x=fmax(A.item1,A.item2);
    double y=fmax(B.item1,B.item2);

    if(x==y) return 0;
    else if (x>y) return 1;
    else return -1;
}

int compara2(const void *a,const void *b)
{
    est B=*(est*)b;
    int key=*(int*)a;
    int x=(int)fmax(B.item1,B.item2);
    return (key-x);
}

  // S1, S2, S3, and M are all constants, and z is part of the
  // private per-thread generator state.
unsigned TausStep(unsigned z, int S1, int S2, int S3, unsigned M)
{
  unsigned b=(((z << S1) ^ z) >> S2);
  return z = (((z & M) << S3) ^ b);
}

// A and C are constants
unsigned LCGStep(unsigned  z, unsigned A, unsigned C)
{
return z=(A*z+C);
}

float HybridTaus()
{
    unsigned z1=rand();
    unsigned z2=rand();
    unsigned z3=rand();
    unsigned z4=rand();
// Combined period is lcm(p1,p2,p3,p4)~ 2^121
return 2.3283064365387e-10 * (
// Periods
TausStep(z1, 13, 19, 12, 4294967294UL) ^    // p1=2^31-1
TausStep(z2, 2, 25, 4, 4294967288UL)   ^    // p2=2^30-1
TausStep(z3, 3, 11, 17, 4294967280UL)  ^    // p3=2^28-1
LCGStep(z4, 1664525, 1013904223UL)
// p4=2^32
);

}
