#include <iostream>
#include <ctime>
#include <cstdlib>
#include "heap.cpp"
using namespace std;

int main()
{
    srand(time(NULL));
    int n;
    cout<<"Numero de datos: ";
    cin>>n;

    int a[n];
    heapMIN<int>A(n);

    for (int i=0;i<n;i++)
        a[i]=rand()%(10*n);
    cout<<"Datos desordenados:"<<endl;
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    for (int i=0;i<n;i++)
        A.Insert(a[i]);
    cout<<"Datos ordenados:"<<endl;
    for (int i=0;i<n;i++)
        cout<<A.delMax()<<" ";
    return 0;
}
