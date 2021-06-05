#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "memo.h"
#include "listas.h"

int main()
{
    char *input=RequestVectorCharMem(128);

    printf("Introduce un calculo a realizar: \n");
    scanf("%s",input);

    liga numeros=NULL;
    liga operadores=NULL;
    ParseText(input,&numeros,&operadores);

    imprimeLista(numeros);
    imprimeLista(operadores);

    ComputeResult(numeros,operadores);
    free(input);
    free(numeros);

    return 0;
}
