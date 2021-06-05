#include <iostream>
#include <stdlib.h>
#include "tree.hpp"

using namespace std;

int main()
{
    srand(time(NULL));

    cout<<"Arbol de enteros"<<endl;
    Tree<int>intTree;

    cout<<"Nodos: ";
    for (int i=0;i<10;i++){
        int aux=rand()%100;
        intTree.insertar(aux);
        cout<<aux<<" ";}
    cout<<endl;

    cout<<"Altura: "<<intTree.altura()<<endl;
    cout<<intTree;

    int key;
    cout<<"Item a buscar: ";
    cin>>key;
    if (intTree.busqueda(key)==true)
    cout<<"Elemento "<<key<<" Encontrado"<<endl;
    else cout<<"Elemento "<<key<<" No Encontrado"<<endl;

    cout<<endl;
    cout<<endl;
    cout<<"Arbol de caracteres"<<endl;
    Tree<char>charTree;

    char cadena[]="GUANAJUATO";
    for (int i=0;i<10;i++)
        charTree.insertar(cadena[i]);

    cout<<"Altura: "<<charTree.altura()<<endl;
    cout<<charTree;

    char key2;
    cout<<"Item a buscar: ";
    cin>>key2;
    if (charTree.busqueda(key2)==true)
    cout<<"Elemento "<<key2<<" Encontrado"<<endl;
    else cout<<"Elemento "<<key2<<" No Encontrado"<<endl;

    return 0;
}


