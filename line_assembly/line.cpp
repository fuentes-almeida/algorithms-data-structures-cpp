#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include "line.hpp"

AsmLine::AsmLine(char file[])
 {
        ifstream input;
        input.open(file);
        int aux;
        input>>n>>e1>>e2;
        for (int i=0;i<n;i++)
        {
            input>>aux;
            a1.push_back(aux);
        }
        for (int i=0;i<n;i++)
        {
            input>>aux;
            a2.push_back(aux);
        }
        for (int i=0;i<n-1;i++)
        {
            input>>aux;
            t1.push_back(aux);
        }
        for (int i=0;i<n-1;i++)
        {
            input>>aux;
            t2.push_back(aux);
        }
        input>>x1>>x2;
        input.close();
    }


int min(int x, int y, vector<int> &line,int flag,int n)
{
    if (x<y)
    {
        if (flag==1)
            line.push_back(1);
        else
            line.push_back(2);
        return x;
    }
    else
    {
        if (flag==1)
            line.push_back(2);
        else
            line.push_back(1);
        return y;
    }
}


void AsmLine::OptimizeTime(int k)
{
     if (k==1)
    {
        f1.push_back(e1+a1[0]);
        f2.push_back(e2+a2[0]);
        return;
    }
    else
    {
        OptimizeTime(k-1);
        f1.push_back(min(f1[k-2]+a1[k-1],f2[k-2]+t2[k-2]+a1[k-1],L1,1,k));
        f2.push_back(min(f2[k-2]+a2[k-1],f1[k-2]+t1[k-2]+a2[k-1],L2,2,k));
    }
}

void AsmLine::PrintResult()
{
    if (f1[n-1]+x1<f2[n-1]+x2)
    {
        cout<<"Tiempo minimo: "<<f1[n-1]+x1<<endl;
        cout<<"Recorrido: ";
        cout<<1<<" "<<L1[n-2]<<" ";
        int k=n,flag=1;
        vector<int> aux=L1;
        while (k-2>0)
        {
            if (aux[k-2]==flag)
            {
            flag=1;
            cout<<aux[k-3]<<" ";
            }
            else {
                aux=L2;
                flag=2;
                cout<<aux[k-3]<<" ";
            }
            k--;
        }
        cout<<endl;
    }

    else
    {
        cout<<"Tiempo minimo: "<<f2[n-1]+x2<<endl;
        cout<<"Recorrido: ";
        cout<<2<<" "<<L2[n-2]<<" ";
        int k=n,flag=2;
        vector<int> aux=L2;
        while (k-2>0)
        {
            if (aux[k-2]==flag)
            {
            flag=2;
            cout<<aux[k-3]<<" ";
            }
            else {
                aux=L1;
                flag=1;
                cout<<aux[k-3]<<" ";
            }
            k--;
        }
        cout<<endl;
    }
}

void AsmLine::TestResult()
{
    vector<int> test;
    for (int i=0;i<n;i++)
        test.push_back(rand()%2+1);

    cout<<"Secuencia: ";
    for (int i=n;i>0;i--)
        cout<<test[i-1]<<" ";

    int aux=GetTime(test,n);
    if(test[n-1]==1)
        cout<<"Tiempo: "<<aux+x1<<endl;
    else
        cout<<"Tiempo: "<<aux+x2<<endl;
}

int AsmLine::GetTime(vector<int> &path,int k)
{
    if (k==1)
    {
    if (path[0]==1)
        return e1+a1[0];
    else
        return e2+a2[0];
    }
    else
    {
    if (path[k-1]==path[k-2])
        if (path[k-1]==1)
            return a1[k-1]+GetTime(path,k-1);
        else
            return a2[k-1]+GetTime(path,k-1);
    else
        if (path[k-1]==1)
            return a1[k-1]+t2[k-2]+GetTime(path,k-1);
        else
            return a2[k-1]+t1[k-2]+GetTime(path,k-1);
    }
}
