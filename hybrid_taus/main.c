#include <stdio.h>
#include <stdlib.h>
#include "memo.h"
#include "histo.h"

int main ()
{
    int n=1e6,m=100;//# de aleatorios y # de barras
    int length=300,width=300;//tamano de la pantalla
    int maxvalue=0;
    double *randomvector;

    randomvector=RequestVectorDoubleMem(n);
    srand(time(NULL));


    for (int i=0;i<n;i++){
    randomvector[i]=HybridTaus();//llamada a funcion que devuelve un aleatorio entre 0 y 1
    }

    //Calculo del vector de histogramas (ocurrencias)
    int* histogram;
    histogram=RequestVectorIntMem(m);

    for (int k=0;k<m;k++)
    histogram [k]=0;
    double delta=1.0/m;

    for (int k=0;k<m;k++)
    for (int i=0;i<n;i++){
     if ((randomvector[i]>=k*delta)&&(randomvector[i]<(k+1)*delta))
     histogram [k]++;
    }

    //Deteccion del mayor valor para normalizar
    for (int k=0;k<m;k++){
    if (histogram[k]>maxvalue)
    maxvalue=histogram[k];}

    //matriz de pixeles para dibujar el histograma
    int **pixel;
    pixel=RequestMatrixIntMem(length,width);
    double scale=width/m;

    for (int i=0;i<length;i++)//para pintar todo de blanco
        for (int j=0;j<width;j++)
        pixel[i][j]=255;

    //se utiliza un factor de 0.6 para evitar que los histogramas ocupen casi toda la pantalla
    for (int k=0;k<m;k++){
      for (int i=0;i<histogram[k]*0.6*length/maxvalue;i++){
        for (int j=k*scale;j<(k+1)*scale;j++){
         pixel[j][i]=0;}}}


    FILE* output;
    output=fopen("histogram.pgm","w");
    fprintf(output, "%s\n%d %d\n%d\n","P2",length,width,255);
    for (int i=0;i<length;i++)
        for (int j=0;j<width;j++)
        fprintf(output,"%d ",pixel[i][j]);

    return 0;
}
