#include <iostream>
#include <stdlib.h>
#include "pila.hpp"
using namespace std;

void imprimeLista(lista* raiz)
{
    lista* ptr=raiz;
    if (raiz==NULL)
        cout<<"La lista esta vacia\n";    //no hay nodos para imprimir
    else{
        do{
            cout<<ptr->item<<"---->";    //imprime el valor del nodo
            ptr=ptr->next;                  //avanza al siguiente
        }while(ptr!=NULL);
        cout<<"\n";
    }
}

ostream& operator<<(ostream& out,const pila& P)
{
        imprimeLista(P.L);
        return out;
}

lista* pila::createNode(int item, lista* next)        //Crea un nodo
{
    lista* ptr= (lista*)new lista;          //asigna memoria dinamica
    ptr->item=item;                         //asigna item por parametro
    ptr->next=next;                         //asigna apuntador a siguiente por parametro
    return ptr;
}


void pila::push(int item)
{
    L=createNode(item,L);
}

void pila::pop()
{
    lista* p;
    p=L;
    if (p!=NULL)
    {
        L=L->next;
        delete p;
    }

}

lista* pila::top()
{
    lista* ptr;
    ptr=createNode(L->item,NULL);
    cout<<ptr->item<<endl;
    return ptr;
}

lista* pila::limpiarFor(lista* raiz)                  //borra toda la lista con for
{
    lista* ptr;
    for(ptr=NULL;raiz->next!=NULL;)                         //inicializa ptr y se sale hasta que quede solo la raiz
        {
        for(ptr=raiz;ptr->next->next!=NULL;ptr=ptr->next);  //recorre la lista hasta el penultimo
        lista* temp=ptr->next;                                //apunta al ultimo nodo
        ptr->next=NULL;                                     //el penultimo ahora apunta a NULL
        delete temp;                                     //borra el ultimo nodo
        }
    ptr=raiz;                                               //borra la raiz
    raiz=NULL;
    delete ptr;
    return raiz;
}

void pila::limpia()
{
        lista* next=L;
        for(;next!=NULL;){
            if(next->next!=NULL){
                for(;next->next->next!=NULL;next=next->next);
                delete next->next;
                next->next=NULL;
                next=L;
            }else{
                delete next;
                next=NULL;
            }
        }
}


int pila::tamanio()                     //regresa el numero de nodos
{
    lista* ptr=L;
    int counter=0;                            //inicializa contador
    while(ptr!=NULL){
        counter++;
        ptr=ptr->next;                      //camina toda la lista, contando los nodos
        }
    return counter;
}
