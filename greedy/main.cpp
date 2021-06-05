#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>

using namespace std;

vector <int> GreedyTasks(vector <int> s,vector <int> f,int i, int n)
{
    vector <int> a;
    int k=i-1;
    a.push_back(k+1);

    while(k<n-1)
    {
        int aux=f[k];
        while(s[k]<aux)
            k++;
        if (k<n-1)
            a.push_back(k+1);
    }
    return a;
}

int main()
{
    srand(time(NULL));
    int n,aux=0;
    vector <int> s,f,a;

    cout<<"Numero de tareas: ";
    cin>>n;
    for (int j=0;j<n;j++)
    {
        aux+=rand()%5+1;
        f.push_back(aux);
        s.push_back(rand()%aux);
    }

    int inicio,fin;
    cout<<"Inicio y fin? "<<endl;
    cin>>inicio>>fin;
    a=GreedyTasks(s,f,inicio,fin);
    int tam= a.size();

    cout<<"Tareas compatibles: \n";
    for (int j=0;j<tam;j++)
        cout<<a[j]<<": ["<<s[a[j]-1]<<","<<f[a[j]-1]<<"]"<<endl;

    return 0;
}
