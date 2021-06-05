#include <iostream>
#define N 5
#define SIZE 100

using namespace std;

typedef struct{
    char name;
    int weight;
    int val;
} Item;

Item items[N];
int values[SIZE+1];
char names[SIZE+1];
int llamadas=0;

int knap(int cap)
{

    static int knownknaps[SIZE+1];
    if (knownknaps[cap]!=0)
        return knownknaps[cap];
    int i,space,max,t;

    for(i=0,max=0;i<N;i++)
        if( (space = cap-items[i].weight)>=0 )
            if( (t = knap(space) + items[i].val )> max )
              {
                max = t;
                knownknaps[cap]=max;
                values[cap]=space;
                names[cap]=items[i].name;
               }
    llamadas++;
    return max;
}

int main()
{
    items[0].name='A'; items[0].weight= 3; items[0].val=  4;
    items[1].name='B'; items[1].weight= 4; items[1].val=  5;
    items[2].name='C'; items[2].weight= 7; items[2].val= 10;
    items[3].name='D'; items[3].weight= 8; items[3].val= 11;
    items[4].name='E'; items[4].weight= 9; items[4].val= 13;

    for (int i=0;i<SIZE+1;i++){
        names[i]='0';
        values[i]=-1;
    }

    cout<<"Tamanio de la bolsa: "<<SIZE<<endl;
    cout<<"Valor maximo: "<<knap(SIZE)<<endl;

    cout<<"Combinacion: ";
    int k=SIZE;
    do{
        cout<<names[k]<<" ";
        k=values[k];
    }while (k!=0);

    cout<<endl;
    cout<<"numero de llamadas: "<<llamadas<<endl;

    /*
    for (int i=0;i<SIZE+1;i++){
        cout<<i<<" ";
        cout<<names[i]<<" ";
        cout<<values[i]<<" "<<endl;
    }
    */
    return 0;
}


