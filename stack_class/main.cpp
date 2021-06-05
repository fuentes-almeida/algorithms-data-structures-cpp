#include <iostream>
#include <stdlib.h>
#include "pila.hpp"

using namespace std;


int main()
{
    pila P;
    for (int i=0;i<10;i++)
    P.push(i);
    cout<<"Impresion de Pila"<<endl;
    cout<<P;
    cout<<P;
    cout<<P;
    cout<<P;
    cout<<P;
    cout<<"Tamanio de Pila"<<endl;
    cout<<P.tamanio()<<endl;
    cout<<"hacioendo pop a 2 nodos"<<endl;
    P.pop();
    P.pop();
    cout<<"Impresion de Pila"<<endl;
    cout<<P;
    cout<<"haciendo tope a la pila"<<endl;
    lista *L;
    L=P.top();
    delete L;
    return 0;
}
