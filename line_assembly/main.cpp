#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include "line.hpp"

using namespace std;

int main()
{
    srand(time(NULL));

    char file[50]="input.dat";
    AsmLine L(file);
    int n=L.n;

    L.OptimizeTime(n);
    L.PrintResult();
    cout<<"Puebas aleatorias:"<<endl;
    for (int i=0;i<100;i++)
    L.TestResult();

    return 0;
}
