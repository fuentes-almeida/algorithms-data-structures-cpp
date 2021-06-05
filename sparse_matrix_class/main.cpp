#include <iostream>
#include "matrix.cpp"

using namespace std;

int main()
{
    int n=5;
    MatrizRala<double> A(5,5);
    A.insertarDato(0,0,1.0);
    A.insertarDato(1,1,2.0);
    A.insertarDato(2,2,4.0);
    A.insertarDato(3,3,1.0);
    A.insertarDato(4,4,3.0);
    A.insertarDato(0,3,2.0);
    A.insertarDato(1,2,5.0);
    A.insertarDato(2,1,1.0);
    A.insertarDato(3,1,2.0);

    cout<<"A:"<<endl;
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cout<<A.regresaDato(i,j)<<" ";
    cout<<endl;}

    MatrizRala<double> B(5,5);
    B.insertarDato(0,0,1.0);
    B.insertarDato(1,1,2.0);
    B.insertarDato(2,2,4.0);
    B.insertarDato(3,3,1.0);
    B.insertarDato(4,4,3.0);
    B.insertarDato(0,3,2.0);
    B.insertarDato(1,2,5.0);
    B.insertarDato(2,1,1.0);
    B.insertarDato(3,1,2.0);

    cout<<" B:"<<endl;
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cout<<B.regresaDato(i,j)<<" ";
    cout<<endl;}

    MatrizRala<double> C(5,5);

    C=A*B;

    cout<<"A*B:"<<endl;
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cout<<C.regresaDato(i,j)<<" ";
    cout<<endl;}

    C=C*B;

    cout<<"C*B:"<<endl;
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cout<<C.regresaDato(i,j)<<" ";
    cout<<endl;}

    return 0;
}
