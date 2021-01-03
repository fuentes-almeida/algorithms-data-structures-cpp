#include <stdio.h>
#include <stdlib.h>
#include "listas2.h"
#include <string.h>
#include "memo.h"
#include <time.h>

liga createNode(int item, char cadena[], int length, liga next) //Crea un nodo
{
    liga ptr= (liga)malloc(sizeof(node));                       //asigna memoria dinamica
    ptr->item=item;                                             //asigna item por parametro
    ptr->palabra=RequestVectorCharMem(length);                  //pide memoria para el puntero palabra, de tamano cadena
    strcpy(ptr->palabra,cadena);                                //copia la cadena a palabra
    ptr->next=next;                                             //asigna apuntador a siguiente por parametro
    printf("r:%p\n", ptr);                                      //imprime direccion del apuntador a nodo
    return ptr;
}

void freeNode(liga ptr)         //borra un nodo
{
    free(ptr->palabra);         //libera la memoria que se pidio para la palabra
    printf("d:%p\n", ptr);      //imprime la direccion del nodo borrado
    free(ptr);
}

liga crearLista(int item,char cadena[], int length,liga raiz)   //crea un nodo al final de una lista
{
    if(raiz==NULL){
        raiz=createNode(item,cadena,length, NULL);              //si la lista esta vacia, crea una raiz
        return raiz;
        }
    else{
        liga ptr;                                               //si no esta vacia, crea un apuntador
            for(ptr=raiz;ptr->next;ptr=ptr->next);              //el apuntador recorre la lista hasta el final
        ptr->next=createNode(item,cadena,length, NULL);         //crea un nodo al final de la lista
        return raiz;
        }
}

void imprimeLista(liga raiz)
{
    printf("\nImpresion de Lista:\n");
    liga ptr=raiz;
    if (raiz==NULL)
        printf("\nLa lista esta vacia\n");                      //no hay nodos para imprimir
    else{
        do{
        printf("[%d][%s]--> ",ptr->item,ptr->palabra);        //imprime la etiqueta y la palabra del nodo
        ptr=ptr->next;                                          //recorre la lista hasta el final
        }while(ptr!=NULL);
        printf("\n");
    }
}

liga eliminarLista(liga raiz, int pos)                          //elimina el nodo en la posicion indicada
{
    liga ptr=raiz;
    int i=pos;
    if (pos==1)                                                 //si se pide eliminar la raiz de la lista
        {                                                       //se llama a una funcion que remueve el primer nodo
        ptr=quitaPrimero(raiz);                                 //que recibe la raiz y devuelve el apuntador al 2do nodo
        return ptr;                                             //se regresa ese apuntador como raiz
        }
    while(i>2){                                                 //se recorre la lista hasta un nodo antes
        if (ptr==NULL)                                          //del nodo que se va a borrar
            return raiz;                                        //si la lista termina antes de encontrar el nodo
        ptr=ptr->next;                                          //regresa la raiz, sin borrar nada
        i--;
        }

    if (ptr==NULL) return raiz;                                 //si no existe el nodo regresa la raiz
    liga temp=ptr->next;                                        //apuntador al nodo que se va a borrar

    if (temp==NULL) return raiz;                                //si no existe el nodo regresa la raiz
    ptr->next=temp->next;                                       //apuntar al nodo a borrar ahora apunta al nodo siguiente

    if (temp->next==NULL){                                      //si el nodo a borrar es el ultimo
        ptr->next=NULL;                                         //el apuntador al anterior se apunta a NULL
        freeNode(temp);                                         //y se borra el ultimo nodo
        }
    else {
        freeNode(temp);                                         //si no es el ultimo solo borra el nodo
    }
    return raiz;
}

liga eliminarNodo(liga raiz, char cadena[])         //borra el nodo que contenga la palabra indicada
{
    if (raiz==NULL){                                //mensaje se error si la lista esta vacia
        printf("Lista vacia");
        return NULL;
        }
    liga ptr=raiz;
    int count=1;

    while(strcmp(ptr->palabra,cadena)!=0)           //recorre lista comparando el elemento "palabra"
        {                                           //con la cadena indicada por entrada estandar
        ptr=ptr->next;
        if (ptr==NULL){                             //si se acaba la lista manda un mensaje
            printf("NO se encontro");
            return raiz;}
        count++;                                    //va contando el numero de nodos
        }
    return eliminarLista(raiz,count);               //elimina el numero de nodo donde se encuentra la palabra buscada
}

liga quitaPrimero(liga raiz)                        //borra el primer nodo
{
    liga ptr;
    ptr=raiz->next;                                 //guarda el apuntador al siguiente nodo
    freeNode(raiz);                                 //libera raiz
    return ptr;                                     //regresa el segundo nodo como raiz
}

int CalcularTamLista(liga raiz)                     //calcula el tamano en total de todas las palabras
{
    liga ptr=raiz;
    int count=0;
    do{
        count+=strlen(ptr->palabra)+1;              //suma la longitud de la palabra mas un espacio
        ptr=ptr->next;                              //avanza al siguiente
    }while(ptr!=NULL);                              //hasta que se acabe la lista
    return count-1;                                 //resta 1 por el ultimo espacio agregado
}

void imprimirFrase(liga raiz)                       //imprime la frase que forman todas las palabras
{
    int tam=CalcularTamLista(raiz);                 //calcula el tamano de la frase
    char* frase;
    frase=RequestVectorCharMem(tam);                //pide memoria dinamica para la frase
    strcpy(frase,"");                               //inicializa la frase vacia
    liga ptr=raiz;

    do{                                             //recorre la lista
        strcat(frase,ptr->palabra);                 //concatenando cada palabra a la frase
        if (ptr->next!=NULL) strcat(frase," ");     //concatena un espacio si no ha llegado al final de la lista
        ptr=ptr->next;
    }while(ptr!=NULL);

    printf("\n\nImpresion de frase:\n%s\n",frase);      //imprime la frase
    free(frase);                                    //libera la memoria
}

double promEtiquetas(liga raiz)         //Calcula el promedio de todas las etiquetas
{
    int suma=0;                         //inicializa la suma y la cuenta
    int count=0;
    liga ptr=raiz;
    do{                                 //recorre la lista, sumando los valores de las etiquetas
        suma+=ptr->item;                //y contando el numero de nodos
        count++;
        ptr=ptr->next;
    }while(ptr!=NULL);
    return (double)suma/count;          //regresa el promedio de los valores, en un double
}

liga Invertir(liga raiz)                //invierte la lista
{
    liga ptr = NULL;
    while (raiz!=NULL) {                //recorre la lista
        liga next = raiz->next;         //apuntador que apunta al siquiente de la raiz
        raiz->next = ptr;               //el siguiente de la raiz se apunta a NULL, como si fuera el ultimo
        ptr = raiz;                     //el apuntador que era NULL se iguala a la raiz
        raiz = next;                    //la raiz de iguala al siguiente de la raiz, y se repite el proceso
        }
  return ptr;
}

liga regresaN_esimo(int n,liga raiz)    //devuelve el apuntador al n-esimo nodo
{
    liga ptr=raiz;
    int i=n;                            //crea un contador de n a 1
    while(i>1){
        if (ptr==NULL)return NULL;      //si el nodo no existe regresa NULL
        ptr=ptr->next;                  //avanza al siquiente hasta que el contador lleque a 1
        i--;
        }
    return ptr;
}

liga swapNodes(liga raiz, int a, int b)             //intercambia los nodos en las posiciones indicadas
{

    liga ptr1=regresaN_esimo(a,raiz);               //se obtienen los apuntadores a esos nodos
    liga ptr2=regresaN_esimo(b,raiz);

    if(raiz==NULL||ptr1== NULL ||ptr2 == NULL){     //si la lista esta vacia o alguno de los nodos no existe
        printf("\nNada que intercambiar");          //envia mensaje de error
        return raiz;
    }

    if (a>1){                                       //si el nodo en a no es la raiz
        liga prev1 = regresaN_esimo(a-1,raiz);      //se pide el apuntador a su nodo anterior
        prev1->next = ptr2;}                        //se hace que el siguiente apunte al otro nodo
    if (b>1){                                       //si el nodo en b no es la raiz
        liga prev2 = regresaN_esimo(b-1,raiz);      //se pide el apuntador a su nodo anterior
        prev2->next = ptr1;}                        //se hace que el siguiente apunte al otro nodo

    liga temp = NULL;                               //se intercambian los apuntadores al siguiente de ambos nodos
    temp = ptr1->next;
    ptr1->next = ptr2->next;
    ptr2->next = temp;

    if(raiz==ptr1)                                  //si algun nodo es la raiz, la raiz se reasigna al otro nodo
        raiz = ptr2;
    else
        if(raiz==ptr2)
        raiz = ptr1;
    return raiz;
}

int longitud(liga raiz)             //funcion que determina el numero de nodos de una lista
{
    int count=0;
    liga ptr=raiz;
    do{
        count++;
        ptr=ptr->next;
        }while(ptr!=NULL);
    return count;
}

liga desordenarLista(liga raiz,int n)       //funcion que desordena la lista
{
    srand(time(NULL));
    int length=longitud(raiz);              //se calcula el numero de nodos

    for(int i=0;i<n;i++)                    //se desordena n veces, segun el parametro
        {
        int random=rand()%11;               //se genera aleatorio entre 0 y 10
        if (random!=0){                     //si es cero, no se desordena nada
        int pos=random%length;              //se determina el modulo del valor aleatorio
                                            //para saber en que nodo caera la cuenta
        raiz=swapNodes(raiz,1,pos+1);}      //se intercambia la raiz y el nodo en que caiga la cuenta
        }
    return raiz;
}

liga limpiarDoWhile(liga raiz)              //borra toda la lista con while y do-while
{
    do{
        liga ultimo=raiz;                   //crea 2 apuntadores
        liga penultimo=raiz;
        if(raiz!=NULL){                     //si la lista esta vacia, sale
            if(ultimo->next == NULL){       //si la lista solo tiene un nodo, lo borra
                raiz = NULL;                //y devuelve la lista vacia
                freeNode(ultimo);
                }
        else{
            while(ultimo->next != NULL){    //recorre la lista hasta el penultimo nodo
                penultimo = ultimo;         //apuntador al penultimo nodo
                ultimo = ultimo->next;      //apundator al ultimo nodo
                }
            penultimo->next = NULL;         //se borra el ultimo nodo y el penultimo se apunta a NULL
            freeNode(ultimo);
            }
        }
        }while(raiz!=NULL);                 //todo se repite hasta acabarse la lista
    return raiz;
}

liga limpiarFor(liga raiz)                  //borra toda la lista con for
{
    liga ptr;
    for(ptr=NULL;raiz->next!=NULL;)                         //inicializa ptr y se sale hasta que quede solo la raiz
        {
        for(ptr=raiz;ptr->next->next!=NULL;ptr=ptr->next);  //recorre la lista hasta el penultimo
        liga temp=ptr->next;                                //apunta al ultimo nodo
        ptr->next=NULL;                                     //el penultimo ahora apunta a NULL
        freeNode(temp);                                     //borra el ultimo nodo
        }
    ptr=raiz;                                               //borra la raiz
    raiz=NULL;
    freeNode(ptr);
    return raiz;
}

