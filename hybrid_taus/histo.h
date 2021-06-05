#ifndef HISTO_H_INCLUDED
#define HISTO_H_INCLUDED
typedef struct {unsigned  z1; unsigned z2;unsigned z3;unsigned z4;} TIPOEST;
typedef TIPOEST* PTREST;
PTREST ptr;

unsigned TausStep(unsigned z, int S1, int S2, int S3, unsigned M);
unsigned LCGStep(unsigned  z, unsigned A, unsigned C);
 double drand(PTREST pseed);
 float HybridTaus();

#endif // HISTO_H_INCLUDED
