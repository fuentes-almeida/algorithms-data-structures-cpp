#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

typedef struct EST{
    double item1;
    double item2;
}est;

int compara(const void*, const void*);
int compara2(const void*, const void*);

unsigned TausStep(unsigned, int, int, int, unsigned);
unsigned LCGStep(unsigned, unsigned, unsigned);
float HybridTaus();

#endif // SORT_H_INCLUDED
