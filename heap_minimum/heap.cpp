#include <iostream>
#include "heap.hpp"

using namespace std;

template <class tipo>
tipo heapMIN<tipo>::delMax()
{
    exchange(&pq[1],&pq[N]);
    fixDown(pq,1,N-1);
    tipo maxx=pq[N--];
    return maxx;
}

template <class tipo>
void heapMIN<tipo>::fixDown(tipo a[],int k, int N)
{
    while(2*k<=N)
    {
        int j=2*k;
        if(j<N && a[j]>a[j+1])
            j++;
        if(!(a[k]>a[j]))
            break;
        exchange(&a[k],&a[j]);
        k=j;
    }
}

template <class tipo>
void heapMIN<tipo>::Insert(tipo item)
{
    pq[++N]=item;
    fixUp(pq,N);
}

template <class tipo>
int heapMIN<tipo>::isEmpty()
{
    return N==0;
}

template <class tipo>
void heapMIN<tipo>::exchange(tipo *x, tipo *y)
{
    tipo aux=*x;
    *x=*y;
    *y=aux;
}

template <class tipo>
void heapMIN<tipo>::fixUp(tipo a[],int k)
{
    while(k>1&&a[k/2]>a[k])
    {
        exchange(&a[k],&a[k/2]);
        k=k/2;
    }
}
