#include <stdio.h>
#include <stdlib.h>
#include "figures.h"
#include <math.h>

void PrintCircle(int radio)
{
    int width=2*radio,height=2*radio;
    int matrix[width][height];

    FILE *out;
    out=fopen("circle.pgm","w");
    if (!out){printf("Imposible abrir archivo");return;}
    fprintf(out,"P2\n%d %d\n255\n",width,height);
    int i,j;
    float distance;
    int center [2];
        for(i=0;i<width;i++){
        for (j=0;j<height;j++){
            center[0]=width/2;
            center[1]=height/2;
            distance=sqrt(pow(center[0]-j,2)+pow(center[1]-i,2));
                if (distance<=radio){
                    matrix [i][j]=0;
                    }
                else{
                    matrix[i][j]=255;
                    }
            fprintf(out,"%d ",matrix [i][j]);
            }
        }
    fclose(out);
    return;
}

void PrintTriangle(int side)
{
    int width=side,height=(side);
    int matrix[height][width];

    FILE *out;
    out=fopen("triangle.pgm","w");
    if (!out){printf("Imposible abrir archivo");return;}
    fprintf(out,"P2\n%d %d\n255\n",width,height);
    int i,j;

    for(j=0;j<height;j++)
    for (i=0;i<width;i++)
    matrix[j][i]=255;

    for (j=height-1;j>=0;j--){
    for (i=0;i<=width/2;i++){
    if (height-j<(float)(1.732*i))
    matrix[j][i]=0;}}

    for (j=height-1;j>=0;j--){
    for (i=width;i>=width/2;i--){
    if (height-j<(float)(1.732*(width-i)))
    matrix[j][i]=0;}}

    for(j=0;j<height;j++)
    for (i=0;i<width;i++)
    fprintf(out,"%d ",matrix [j][i]);

    fclose(out);
}

void PrintSquare(int side)
{
    int width=side,height=side;
    int matrix[width][height];

    FILE *out;
    out=fopen("square.pgm","w");
    if (!out){printf("Imposible abrir archivo");return;}
    fprintf(out,"P2\n%d %d\n255\n",width,height);
    int i,j;

    for(i=0;i<width;i++)
    for (j=0;j<height;j++){
    matrix[i][j]=50;
    fprintf(out,"%d ",matrix [i][j]);}

fclose(out);
}
