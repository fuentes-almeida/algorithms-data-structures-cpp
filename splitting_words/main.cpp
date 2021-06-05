#include <iostream>
#include <cstring>
#include "dicc.hpp"
using namespace std;

int main()
{
    Diccionario d;
    int salir=0;
    char palabra[41];
    int opcion;
    char letra;
    while(!salir)
    {
        cout<<"1. Introducir palabra \n";
        cout<<"2. Listar palabras que empiecen por...\n";
        cout<<"3. Listar todas las palabras \n";
        cout<<"4. Salir \n";
        cout<<"Eleccion: \n";
        cin>>opcion;

        switch(opcion)
        {
            case 1: cout<<"Introduzca palabra: ";
            cin>>palabra;
            d.insertar(palabra);
            break;

            case 2: cout<<"Introducza letra: ";
            cin>>letra;
            d.listarpor(letra);
            break;

            case 3: d.listar();
            break;

            case 4: salir=1;
            break;

            default: cout<<"Eleccion incorrecta \n";
            break;
        }

    }
    return 0;
}
