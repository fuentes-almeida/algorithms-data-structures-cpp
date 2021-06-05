#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <setjmp.h>
#include <unistd.h>
#include "function.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));

    n=5;
    x=(double*)malloc(n*sizeof(double));
    for (int i=0;i<n;i++)
        x[i]=-i;

    name=(char*)malloc(10*sizeof(char));

    if (argc<2)
        {
        strcpy(name,"logfile.txt");
        FILE *data=fopen(name,"w");
        if (data==NULL) {printf("Imposible abrir archivo");return 0;}
        for (int i=0;i<n;i++)
            fprintf(data,"%lf ",x[i]);
        fprintf(data,"\n");
        fclose(data);
        fija_Seniales();
        int r=rand()%3;
        generarError1(x,0);
        }
    else{
        name=argv[1];
        assert(fopen(name,"r"));
        FILE *data=fopen(name,"r");
        if (data==NULL) {printf("Imposible abrir archivo");return 0;}
        for (int i=0;i<n;i++)
            fscanf(data,"%lf",&x[i]);
        fclose(data);
        fija_Seniales();
        int r=rand()%3;
        generarError2(x,r);
        }

    return 0;
}
