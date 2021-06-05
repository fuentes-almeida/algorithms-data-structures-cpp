#include <iostream>
#include <stdlib.h>
#include "tree.hpp"
#include <omp.h>

using namespace std;

int main()
{
    srand(time(NULL));

    cout<<"Ordenamiento con Arbol binario de busqueda:"<<endl;
    cout<<"Antes"<<endl;
    int x[]={56,57,35,46,24,79,43,21,70,66};
    for (int i=0;i<10;i++)
        cout<<x[i]<<" ";
    ordenador<int>BSTtree(x,BST_SORT,10);
    cout<<endl<<"Despues"<<endl;
    for (int i=0;i<10;i++)
        cout<<x[i]<<" ";
    int key;
    cout<<endl<<"Elemento a seleccionar"<<endl;
    cin>>key;
    cout<<"Elemento: "<<BSTtree.select(x,key);
    cout<<endl;
    cout<<endl;

    cout<<"Algoritmos de ordenamiento:"<<endl;

    for (int k=10;k<=1000000;k*=10)
    {
    int SIZE=k;
    int *a=(int*)calloc(SIZE,sizeof(int));
    generateRandomVector(a,SIZE);

    int *b=(int*)calloc(SIZE,sizeof(int));
    int *c=(int*)calloc(SIZE,sizeof(int));
    int *d=(int*)calloc(SIZE,sizeof(int));
    for (int i=0;i<SIZE;i++)
    {
        b[i]=a[i];
        c[i]=a[i];
    }

    double start,finish;
    cout<<"Tiempos de ejecucion con "<<SIZE<<" datos"<<endl;

    start=omp_get_wtime();
    ordenador<int>IntSort1(a,MERGE_SORT,SIZE);
    finish=omp_get_wtime();
    cout<<"MergeSort: "<<finish-start<<endl;

    start=omp_get_wtime();
    ordenador<int>IntSort3(c,QUICK_SORT,SIZE);
    finish=omp_get_wtime();
    cout<<"QuickSort: "<<finish-start<<endl;

    if (k<1000000){
    start=omp_get_wtime();
    ordenador<int>IntSort4(d,BST_SORT,SIZE);
    finish=omp_get_wtime();
    cout<<"BSTsort: "<<finish-start<<endl;

    start=omp_get_wtime();
    ordenador<int>IntSort2(b,SELECTION_SORT,SIZE);
    finish=omp_get_wtime();
    cout<<"SelectionSort: "<<finish-start<<endl;
    }

    cout<<endl;
    free(a);
    free(b);
    free(c);
    free(d);
    }

    return 0;
}
