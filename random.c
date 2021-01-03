#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "memo.h"
#include "random.h"

long int giveMeRandomNPot10(int pot10)
{
        long int n=0,fact=1; //n es resultado y factor potencia de 10
        for(int i=0;i<pot10;i++)
            {
            n += (rand() % 10) * fact;
            fact *=10;
            }
        return n;
}

int GenerateSeed(int seed)
{
     return rand();
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

double HybridTaus( )
{
    // Combined period is lcm(p1,p2,p3,p4)~ 2^121
    return 2.3283064365387e-10 * (
    // Periods
    TausStep(rand(), 13, 19, 12, 4294967294UL) ^    // p1=2^31-1
    TausStep(rand(), 2, 25, 4, 4294967288UL)   ^    // p2=2^30-1
    TausStep(rand(), 3, 11, 17, 4294967280UL)  ^    // p3=2^28-1
    LCGStep(rand(), 1664525, 1013904223UL)
    // p4=2^32
    );

}

double getGaussian(double mean, double stdDev,int seed)
{
    double spare;
    int isSpareReady = 0;
    if (isSpareReady>0) {
        isSpareReady = 0;
        return spare * stdDev + mean;
    } else {
        double u, v, s;
        do {
            u = 3*HybridTaus()-1;
            v = 3*HybridTaus()-1;
            s = u * u + v * v;
        } while (s >= 1 || s == 0);
        double mul = sqrt(-2.0 * log(s) / s);
        spare = v * mul;
        isSpareReady++;
        return mean + stdDev * u * mul;
    }
}

int **GenerateHistogram(long int *randomvector,int length,int width,int n,int m)
{
    double MAX = -99999999999999999;
	double MIN = 99999999999999999;
    int maxvalue=0;
        for( int i=0; i<n; i++)
            {
            if( randomvector[i]<MIN )
                MIN = randomvector[i];
            if( randomvector[i]>MAX)
                MAX = randomvector[i];
            }
    int* histogram;
    histogram=RequestVectorIntMem(m);

    for (int k=0;k<m;k++)
        histogram [k]=0;

    double delta=(MAX-MIN)/(double)m;
    //printf("%lf",delta);

    for (int k=0;k<m;k++)
        for (int i=0;i<n;i++)
            {
            if ((randomvector[i]>=MIN +k*delta)&&(randomvector[i]<MIN +(k+1)*delta))
            histogram [k]++;
            }

    for (int k=0;k<m;k++)
        {
        if (histogram[k]>maxvalue)
        maxvalue=histogram[k];
        }

    int **pixel;
    pixel=RequestMatrixIntMem(length,width);
    double scale=width/m;

    for (int i=0;i<length;i++)
        for (int j=0;j<width;j++)
            pixel[i][j]=255;

    for (int k=0;k<m;k++){
      for (int i=0;i<histogram[k]*0.8*length/maxvalue;i++){
        for (int j=k*scale;j<(k+1)*scale;j++){
            pixel[j][i]=0;}}}

    return pixel;
    free(histogram);
}

void DrawHistogram(double mean, double stdDev,int seed,char *name)
{

    int length=300,width=300,n=1e6,m=100;//pantalla y constantes de graficacion
    double *randomvector;
    randomvector=RequestVectorDoubleMem(n);

    srand(time(NULL));
    //generacion de vector de numeros aleatorios

    srand(seed);//semilla que inicializa funcion random
    for (int i=0;i<n;i++)
        {
        randomvector[i]=getGaussian(mean,stdDev,seed);
        }

    double MAX = -9999999999999;//valor MIN y MAX para normalizacion del histograma
	double MIN = 99999999999999;
    int maxvalue=0;
        for( int i=0; i<n; i++)
            {
            if( randomvector[i]<MIN )
                MIN = randomvector[i];
            if( randomvector[i]>MAX)
                MAX = randomvector[i];
            }
	//generacion del histograma
    int* histogram;
    histogram=RequestVectorIntMem(m);

    for (int k=0;k<m;k++)
        histogram [k]=0;
    double delta=(MAX-MIN)/(double)m;//factor de normalizacion

    for (int k=0;k<m;k++)
        for (int i=0;i<n;i++)
            {
            if ((randomvector[i]>=MIN +k*delta)&&(randomvector[i]<MIN +(k+1)*delta))
            histogram [k]++;
            }

    for (int k=0;k<m;k++)
            {
        if (histogram[k]>maxvalue)
            maxvalue=histogram[k];
            }

    //generacion de matriz de pixeles
    int **pixel;
    pixel=RequestMatrixIntMem(length,width);
    double scale=width/m;

    for (int i=0;i<length;i++) //poner en blanco
        for (int j=0;j<width;j++)
            pixel[i][j]=255;

    for (int k=0;k<m;k++)
        {
        for (int i=0;i<histogram[k]*0.8*length/maxvalue;i++)
            {
            for (int j=k*scale;j<(k+1)*scale;j++)
                {
                pixel[j][i]=0;
                }
            }
        }
    free(histogram);

    FILE* output;
    output=fopen(name,"w");
    fprintf(output, "%s\n%d %d\n%d\n","P2",length,width,255);

    for (int i=0;i<length;i++)
        for (int j=0;j<width;j++)
            fprintf(output,"%d ",pixel[i][j]);

    freeMatrizInt(pixel,width);

    return ;
}
