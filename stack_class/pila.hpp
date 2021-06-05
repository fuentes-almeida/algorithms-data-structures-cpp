#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED
#include <iostream>
#include <stdlib.h>

using namespace std;

class lista{

public:
    int item;
    lista *next;
};

class pila{

    private:
        lista* L;
    public:
        pila()
        {
            L=NULL;
        }
        ~pila()
        {
            limpia();
            cout<<"destruye"<<endl;
        }

    lista* createNode(int item, lista* next);
    lista* quitaPrimero(lista* raiz);
    void push(int item);
    void pop();
    lista* top();
    lista* limpiarFor(lista* raiz);
    void limpia();
    int tamanio();
    friend ostream& operator<<(ostream& out,const pila& P);

};

#endif // PILA_HPP_INCLUDED
