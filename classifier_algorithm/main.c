#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memo.h"
#include <time.h>
#include <math.h>



char script[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
               'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

double **class1vector,**class2vector;
int *vector_training1,*vector_training2;
int *vector_test1,*vector_test2;
int *vector1,*vector2;
int size1,maximum1,size2,maximum2;
FILE *fpointer;

double** GetClass1vectors()
{
    double **class1vector;
    class1vector=RequestMatrixDoubleMem(48,52);
    int i,j,k;
    char c;
    char index[2],name[10],extension [5];
    strcpy(extension,".txt");

    for (i=0;i<48;i++)
    for (j=0;j<52;j++)
    class1vector[i][j]=0;

    for (i=0;i<48;i++)
    {
    strcpy(name,"pg1232_");
    sprintf(index,"%d",i+1);
    strcat(name,index);
    strcat(name,extension);
    fpointer=fopen(name,"r");
    k=0;
    while (!feof(fpointer))
    {
    c=fgetc(fpointer);
    k++;
    for (j=0;j<52;j++){
    if (c==script[j])
    class1vector[i][j]++;}
    }
    for (j=0;j<52;j++)
    class1vector[i][j]=class1vector[i][j]/k;
    fclose(fpointer);
    }
return class1vector;
}

double** GetClass2vectors()
{
    double **class2vector;
    class2vector=RequestMatrixDoubleMem(43,52);
    int i,j,k;
    char c;
    char index[2],name[10],extension [5];
    strcpy(extension,".txt");

    for (i=0;i<43;i++)
    for (j=0;j<52;j++)
    class2vector[i][j]=0;

    for (i=0;i<43;i++)
    {
    strcpy(name,"pg5827_");
    sprintf(index,"%d",i+1);
    strcat(name,index);
    strcat(name,extension);
    fpointer=fopen(name,"r");
    k=0;
    while (!feof(fpointer))
    {
    c=fgetc(fpointer);
    k++;
    for (j=0;j<52;j++){
    if (c==script[j])
    class2vector[i][j]++;}
    }
    for (j=0;j<52;j++)
    class2vector[i][j]=class2vector[i][j]/k;
    fclose(fpointer);
    }
    return class2vector;
}

void RunVectorTest(double **class1vector, double **class2vector)
{
    double euclidean1=0,euclidean2=0, min_euclidean1=1,min_euclidean2=1;
    int i,j,k,l,n,scoreclass1=0,scoreclass2=0;

    for (i=0;i<maximum1-size1;i++){
    for (l=0;l<size2;l++){
    for (j=0;j<52;j++){
    euclidean2+=pow(class1vector[vector_test1[i]][j]-class2vector[vector_training2[l]][j],2);}
    euclidean2=sqrt(euclidean2);
    if (euclidean2<min_euclidean2)
    min_euclidean2=euclidean2;
    euclidean2=0;
    }

    for (k=0;k<size1;k++){
    for (n=0;n<52;n++){
    euclidean1+=pow(class1vector[vector_test1[i]][n]-class1vector[vector_training1[k]][n],2);}
    euclidean1=sqrt(euclidean1);
    if (euclidean1<min_euclidean1)
    min_euclidean1=euclidean1;
    euclidean1=0;
    }
    if (min_euclidean1<min_euclidean2)
    scoreclass1++;
    }
    printf("Porcentaje de correspondencia para Clase 1 = %.2f",(float)scoreclass1*10.0);
    printf("\n");

    min_euclidean1=1,min_euclidean2=1;

    for (i=0;i<maximum2-size2;i++){
    for (l=0;l<size2;l++){
    for (j=0;j<52;j++){
    euclidean2+=pow(class2vector[vector_test2[i]][j]-class2vector[vector_training2[l]][j],2);}
    euclidean2=sqrt(euclidean2);
    if (euclidean2<min_euclidean2)
    min_euclidean2=euclidean2;
    euclidean2=0;
    }
    for (k=0;k<size1;k++){
    for (n=0;n<52;n++){
    euclidean1+=pow(class2vector[vector_test2[i]][n]-class1vector[vector_training1[k]][n],2);}
    euclidean1=sqrt(euclidean1);
    if (euclidean1<min_euclidean1)
    min_euclidean1=euclidean1;
    euclidean1=0;
    }
    if (min_euclidean1>min_euclidean2)
    scoreclass2++;
    }
    printf("Porcentaje de correspondencia para Clase 2 = %.2f\n\n",(float)scoreclass2*11.11);

return;
}

int* GenerateRandomvectors(int size, int maximum)
{
    int *vector;
    srand(time(0));
    int i, j,num;
    vector=RequestVectorIntMem(maximum);

    for(i=0;i<maximum;i++){
        num =rand()%maximum;
       if(i>0){
          for(j=0;j<i;j++)
              if(num==vector[j]){
                 num = rand()%maximum;
                 j=-1;}
                }
        vector[i]=num;}
return vector;
}

void freememory()
{
    int i;
    free(vector1);
    free(vector2);
    free(vector_test1);
    free(vector_test2);
    free(vector_training1);
    free(vector_training2);

    for (i=0;i<48;i++)
    free(class1vector[i]);
    free(class1vector);
    for (i=0;i<43;i++)
    free(class2vector[i]);
    free(class2vector);
return;
}

int main()
{
    int i;

    class1vector=GetClass1vectors();
    class2vector=GetClass2vectors();

    size1=38;
    maximum1=48;

    vector_training1=RequestVectorIntMem(size1);
    vector_test1=RequestVectorIntMem(maximum1-size1);
    vector1=GenerateRandomvectors(size1,maximum1);

    for (i=0;i<size1;i++)
    vector_training1[i]=vector1[i];
    for (i=0;i<maximum1-size1;i++)
    vector_test1[i]= vector1[i+size1];

    size2=34;
    maximum2=43;

    vector_training2=RequestVectorIntMem(size2);
    vector_test2=RequestVectorIntMem(maximum2-size2);
    vector2=GenerateRandomvectors(size2,maximum2);

    for (i=0;i<size2;i++)
    vector_training2[i]=vector2[i];
    for (i=0;i<maximum2-size2;i++)
    vector_test2[i]= vector2[i+size2] ;

    RunVectorTest(class1vector,class2vector);
    freememory();
    return 0;
}


