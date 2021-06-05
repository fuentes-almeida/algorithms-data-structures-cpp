#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "sort.hpp"

using namespace std;

//Ordenamiento por quicksort
void quickSort(int* a, int left, int right)
{
    int i,j, mid;
    int pivote;

    mid=(left+right)/2;
    pivote=a[mid];
    i=left;
    j=right;

    do{
        while (a[i]<pivote) i++;
        while (a[j]>pivote) j--;

        if (i<=j)
        {
            int aux=a[i];
            a[i]=a[j];
            a[j]=aux;
            i++;
            j--;
        }
    }while (i<=j);
    if (left<j)
        quickSort(a,left,j);
    if (i<right)
        quickSort(a,i,right);
}

//Genera #SIZE numeros aleatorios en un vector
//Los crea ordenados y luego los desordena
void generateRandomVector(int *a,int SIZE)
{
    int aux=0;
    for (int i=0;i<SIZE;i++)
    {
        aux+=rand()%4+1;
        a[i]=aux;
    }

    for (int i=0;i<3*SIZE;i++)
    {
        int k=rand()%SIZE;
        int j=rand()%SIZE;
        aux=a[k];
        a[k]=a[j];
        a[j]=aux;
    }
}
