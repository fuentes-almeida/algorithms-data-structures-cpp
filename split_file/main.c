#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void SplitFile(FILE *input, char nombre[10],int k)
{
    char script[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                   'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int c,i,j,m;

       FILE *output;
   char extension[5];
   char index[2];

    strcpy(extension,".txt");
    sprintf(index,"%d",k);
    strcat(nombre,index);
    strcat(nombre,extension);
    output=fopen(nombre,"w");
    printf("Creando archivo %s \n",nombre);

        i=0;
        do{
        c = fgetc(input);
        if(feof(input)){
                fclose(output);
                return;}
            for (j=0;j<52;j++){
                if (c==script[j]){
                    fputc(c,output);
                    i++;
                    }
                }
            }while(i<5000);
            fclose(output);
            return;
}

int main ()
{
    FILE *input;
    char nombre[10];
    int k,n=1;

    input = fopen("pg1232.txt","r");
    k=1;
    do{
    if(feof(input)&&n==2){break;}
    else if (feof(input)&&n==1)
        {
        n++;
        fclose(input);
        input = fopen("pg5827.txt","r");
        k=1;
        do
        {
        if(feof(input)){break;}
        strcpy(nombre,"pg5827_");
        SplitFile (input,nombre,k);
        k++;
        }while(1);
        }
        else
        {
        strcpy(nombre,"pg1232_");
        SplitFile (input,nombre,k);
        k++;
        }
    }
    while(1);
   return 0;
}



