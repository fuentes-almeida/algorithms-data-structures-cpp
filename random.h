#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

long int giveMeRandomNPot10(int );
int **GenerateHistogram(long int *,int ,int ,int ,int );
unsigned TausStep(unsigned , int , int , int , unsigned );
unsigned LCGStep(unsigned  , unsigned , unsigned );
int GenerateSeed(int );
double HybridTaus( );
double getGaussian(double , double ,int  );
void DrawHistogram(double , double ,int ,char *);

#endif // RANDOM_H_INCLUDED
