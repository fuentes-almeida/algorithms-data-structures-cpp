#include <stdio.h>
#include <stdlib.h>


typedef struct NODE{    //Declara un tipo de variable estructura como "node"
    int item;           //dentro de la estructura definida como node se declara un entero llamado "item"
    struct node* next;  //se declara tambien un apuntador al tipo "node" creado y se nombra como next
}node;                  //nombre que se le da al tipo estructura creado

typedef node* liga;     //se crea un tipo apuntador al tipo "node" creado y se nombra "liga"

liga createNode(int item, liga next){       //se declara una funcion que regresa una "liga" y recibe un entero y otra liga como argumentos
    liga r= (liga)malloc(sizeof(node));     //se llama a la funcion malloc para asignar memoria dinamica de tamanio "node" a un apuntador "liga" llamado r
    r->item=item;                           //al "item" del nuevo nodo creado, se le asigna el argumento recibido por la funcion
    r->next=next;                           //el apuntador a "node" del nuevo nodo creado se iguala al apuntador recibido como argumento
    return r;                               //regresa el apuntador al nuevo nodo creado
}

int main(int narg,char* argv[])                 //el programa recibe como argumentos el valor de n (# total de personas) y k (tamanio del salto)
{
    int i,n=atoi(argv[1]), k=atoi(argv[2]);     //los argumentos tipo char* recibidos se convierten a entero
    if (n<3){
        printf("Deben ser mas de tres personas");
        return 0;}
    liga t=createNode(1,NULL);                  //se crea una liga t y un nodo asociado a t, que al principio apunta a NULL (aterrizado)
    t->next=t;                                  //el apuntador del nuevo nodo se iguala a t, se hace que el nodo se punte a si mismo
    liga x=t;                                   //se crea un apuntador a nodo x y se iguala a t, hay 3 apuntadores apuntando al nodo, t, x y el apuntador next del mismo nodo

    for(i=2;i<=n;i++)                           //ciclo que va de 2 hasta n
        x=(x->next= createNode(i,t));           //se crean n-1 nodos, cada uno con un entero de 2 hasta n como item
                                                //x->next que apunta al apuntador next del primer nodo, se le ha asignado un nuevo nodo, con un nuevo item
                                                //por tanto, ahora el apuntador next del primer nodo apunta al nuevo nodo creado
                                                //despues de crear el nodo, x se iguala a x->next, es decir, ahora x tambien apunta al nuevo nodo creado
                                                //el nodo recien creado recibe a t como argumento, por tantu su apuntador next va a apuntar al primer nodo
                                                //este ciclo se repite hasta i=n, cada nodo que se va creando apuntara al primer nodo, el nodo anterior apuntara al nuevo nodo
                                                //y x apuntara al nodo creado
    printf("Mueren: ");

    int j=n;
    while (j>3){                                //mientras no queden tres nodos
        for (i=1;i<k;i++)                       //ciclo del tamanio del salto menos 1 (k-1)
            x=x->next;                          //el ciclo hace que x salte de nodo en nodo k-1 veces

        t=x->next;                              //despues de k-1 saltos, el apuntador t se iguala al apuntador del k-esimo nodo
        x->next=t->next;                        //hacemos ahora que el apuntador que apuntaba al k-esimo nodo apunte al nodo siguiente
        printf("%d ",t->item);                  //se imprime el valor del k-esimo nodo
        free(t);
        j--;                                    //se libera el nodo (muere)
    }

        printf("\nSobreviven: ");
        for (i=1;i<=3;i++){
        printf("%d ",x->item);
            x=x->next;
        }
    return 0;
}
