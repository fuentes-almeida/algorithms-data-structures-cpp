#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "sort.hpp"

using namespace std;

int main()
{
    srand(time(NULL));
    int n=10000;
    int *random=new int[n];
    generateRandomVector(random,n);
    quickSort(random,0,n-1);

    ofstream output("Salida.txt");
    for (int i=0;i<n;i++)
        output<<random[i]<<"\n";

    delete [] random;
    return 0;
}
