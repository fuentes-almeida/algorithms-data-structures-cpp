#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memo.h"
    char script[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                   'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void SplitFile(FILE *input, char nombre[10],int k)
{

    int c,i,j,m;

       FILE *output;
   char extension[5];
   char index[2];

    strcpy(extension,".txt");
    sprintf(index,"%d",k);
    strcat(nombre,index);
    strcat(nombre,extension);
    output=fopen(nombre,"w");
    //printf("Creando archivo %s \n",nombre);

        i=0;
        do{
        c = fgetc(input);
        if(feof(input)){
        fclose(output);
        return;}
            fputc(c,output);
            i++;
            }while(i<10000);

         while (c!=' '){
            c=fgetc(input);
            fputc(c,output);
         }
        fclose(output);




        return;
}

void FindCasePairs(char nombre[10], int k)
{

    FILE *output;
    output=fopen(nombre,"r");
    //printf("Abriendo archivo %s \n",nombre);
    int i,j;
    char pairs[500][2];
    char *scan_string;
    scan_string=RequestVectorCharMem(20);
    char *test_string;
    test_string=RequestVectorCharMem(20);

    fscanf(output,"%s",scan_string);


for (int i=0;i<52;i++){

if (scan_string[0]==script[i])
printf("%s\n",scan_string);
}
scan_string++;

printf("%s",scan_string);


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
        //FindCasePairs(nombre,k);
        k++;
        }while(1);
        }
        else
        {
        strcpy(nombre,"pg1232_");
        SplitFile (input,nombre,k);
        FindCasePairs(nombre,k);
        k++;
        }
    }
    while(1);
   return 0;
}
