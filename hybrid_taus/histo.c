#include <stdio.h>
#include <stdlib.h>
#include "memo.h"
#include "histo.h"


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

 double drand(PTREST pseed)
 {

return rand();

 }

float HybridTaus()
{
    ptr  = (PTREST)malloc(sizeof(TIPOEST));
    ptr->z1=drand(ptr);
    ptr->z2=drand(ptr);
    ptr->z3=drand(ptr);
    ptr->z4=drand(ptr);
// Combined period is lcm(p1,p2,p3,p4)~ 2^121
return 2.3283064365387e-10 * (
// Periods
TausStep(ptr->z1, 13, 19, 12, 4294967294UL) ^    // p1=2^31-1
TausStep(ptr->z2, 2, 25, 4, 4294967288UL)   ^    // p2=2^30-1
TausStep(ptr->z3, 3, 11, 17, 4294967280UL)  ^    // p3=2^28-1
LCGStep(ptr->z4, 1664525, 1013904223UL)
// p4=2^32
);

}
