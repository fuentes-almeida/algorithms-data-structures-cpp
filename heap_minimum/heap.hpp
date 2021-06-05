#ifndef HEAP_HPP_INCLUDED
#define HEAP_HPP_INCLUDED

#include <iostream>

using namespace std;

template <class tipo>
class heapMIN
{
private:
    tipo *pq;
    int N;
public:
    heapMIN(int maxN)
    {
        pq=new tipo[maxN+1];
        N=0;
    }

    int isEmpty();
    void exchange(tipo *x, tipo *y);
    void fixUp(tipo a[],int k);
    void Insert(tipo item);
    void fixDown(tipo a[],int k, int N);
    tipo delMax();
};

#endif // HEAP_HPP_INCLUDED
