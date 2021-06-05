#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Parentization(int *p, int** matriz, int n)
{
    for (int j=1;j<n;j++)
    for (int i=0;i<n-j;i++)
        {
        if(j==1)
            {
            matriz[i][i+j]=i+1;
            matriz[i+j][i]=p[i]*p[i+1]*p[i+2];
            }

        else{
            int min=99999999;
            for (int k=i;k<i+j;k++)
            {
                int aux=matriz[k][i]+matriz[i+j][k+1]+p[i]*p[k+1]*p[i+j+1];
                if (aux<min)
                    {
                    min=aux;
                    matriz[i][i+j]=k+1;
                    matriz[i+j][i]=min;
                    }
            }
        }
        }
}

int main()
{
    srand(time(NULL));
    int n;
    cout<<"Numero de matrices: "<<endl;
    cin>>n;

    int *p=new int[n+1];
    cout<<"Tamanios: "<<endl;
    for (int i=0;i<=n;i++)
    {
        p[i]=rand()%99+1;
        cout<<p[i]<<" ";
    }
    cout<<"\n\n";

    int** matriz=new int*[n];
    for (int i=0;i<n;i++)
        matriz[i]=new int [n];

    Parentization(p,matriz,n);

    cout<<"Tabla auxiliar"<<endl;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cout<<matriz[i][j]<<"\t";
        cout<<endl;}

    cout<<endl;
    cout<<"Valor optimo: "<<endl;
    cout<<matriz[n-1][0]<<endl;

    delete[] p;
    for (int i=0;i<n;i++)
        delete[] matriz[i];
    delete[] matriz;

    return 0;
}
