#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <omp.h>
#include "hash.hpp"
#define M 66653
#define N 200000

using namespace std;

int main()
{
    char name[]="NationalFedCodes_20151001.csv";

    ifstream input(name);
    string cadena;
    getline(input,cadena);

    HashTable T(M);
    Item**Datos=new Item*[N];

    int i=0;
    while (getline(input,cadena)!=NULL)
    {
        Datos[i]=new Item;
        NewItem(input,Datos[i],cadena);
        if (Datos[i]!=NULL)
        T.InsertField(Datos[i]);
        i++;
    }

    //T.printTable();
    double start,finish;

    start=omp_get_wtime();
    for (int i=0;i<100000;i++)
    {
    T.SearchItem(Datos[rand()%190000]->key);
    }
    finish=omp_get_wtime();
    cout<<endl;
    cout<<"Tiempo Total de busqueda de datos encontrados: "<<(finish-start)<<" seg"<<endl;
    cout<<"Tiempo promedio de busqueda de datos encontrados: "<<(finish-start)/100000<<" seg"<<endl;

    start=omp_get_wtime();
    for (int i=0;i<10;i++)
    {
    T.SearchItem("XXXXX");
    }
    finish=omp_get_wtime();
    cout<<"Tiempo promedio de busqueda de datos no encontrados: "<<(finish-start)/100000<<" seg"<<endl;

    T.SearchItem("DGKS");//Si dos llaves iguales o mas, imprime todas
    delete [] Datos;
    input.close();

    return 0;
}
