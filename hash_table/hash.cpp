#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

#include "hash.hpp"

field::field()
{
    root=NULL;
    num_items=0;
}

field::~field()
{
    Item *aux1=root;
    Item *aux2=root;
    while(aux2)
    {
        aux1=aux2;
        aux2=aux1->next;
        if (aux2)
        delete aux1;
    }
}

void field::InsertItem(Item *newItem)
{
    Item *aux=root;
    if (!root)
    {
        root=newItem;
        root->next=NULL;
        num_items++;
        return;
    }

    while (aux->next)
        aux=aux->next;

    aux->next=newItem;
    newItem->next=NULL;
    num_items++;
    return;
}

void field::SearchKey(char *key)
{
    Item *aux=root;
    while (aux)
    {
        if(strcmp(aux->key,key)==0)
            {
                cout<<*aux;
                //return aux;
            }
        aux=aux->next;
    }
    return;
}

void field::printList()
{
    if (num_items == 0)
    {
        cout<<endl;
        return;
    }
    Item *aux=root;
    while (aux)
    {
        cout<<aux->key<<" ";
        aux=aux->next;
    }
    cout<<endl;
}

long int HashTable::hashFx(char *k, int num)
{
    long int h, a=31415,b=27183;
    for (h=0;*k!=0;k++,a=a*b%(num-1))
        h=(a*h+*k)%num;
    return h;
}

HashTable::HashTable(int m)
{
    size=m;
    Table=new field[m];
    num_elements=0;
}

HashTable::~HashTable()
{
    delete [] Table;
}

void HashTable::InsertField(Item *newItem)
{
    long int index=hashFx(newItem->key,size);
    Table[index].InsertItem(newItem);
    num_elements++;
}

void HashTable::SearchItem(char *key)
{
    long int index=hashFx(key,size);
    return Table[index].SearchKey(key);
}

void HashTable::printTable()
{
    cout << "\n\nHash Table:\n";
    for ( int i = 0; i < size; i++ )
    {
        cout << "Slot " << i + 1 << ": ";
        Table[i].printList();
    }
}

void NewItem(ifstream& input, Item *newItem,string str)
{
    unsigned int i=0;

    while (i<str.length())
    {
        if (str.compare(i,2,",,")==0)
            str.insert(i+1,"0");
        i++;
    }

    char *token=strtok(&str[0],",");
    strcpy(newItem->key,token);
        token=strtok(NULL,",");
    newItem->Feature_ID=atoi(token);
        token=strtok(NULL,",");
    newItem->Census_Code=atoi(token);
        token=strtok(NULL,",");
    strcpy(newItem->Census_Class_Code,token);
        token=strtok(NULL,",");
    newItem->State_numeric=atoi(token);
        token=strtok(NULL,",");
    strcpy(newItem->State_Alpha,token);
        token=strtok(NULL,",");
    newItem->Country_numeric=atoi(token);
        token=strtok(NULL,",");
    newItem->primary_latt=atof(token);
        token=strtok(NULL,",");
    newItem->primary_long=atof(token);
    newItem->next=NULL;

    return;
}

ostream& operator<<(ostream& out, const Item A)
{
    out<<"["<<A.key<<" "<<A.Feature_ID<<A.Census_Code<<" "
    <<A.Census_Class_Code<<" "<<A.State_numeric<<" "<<A.State_Alpha
    <<" "<<A.Country_numeric<<" "<<A.primary_latt<<" "<<A.primary_long<<"]"<<endl;
    return out;
}
