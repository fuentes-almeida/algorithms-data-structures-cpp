#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED


typedef struct NODE{
    int item;
    char* palabra;
    struct NODE* next;
}node;

typedef node* liga;

liga crearLista(int ,char[], int ,liga );
liga createNode(int item, char *, int , liga );
void imprimeLista(liga );
liga eliminarLista(liga , int );
liga eliminarNodo(liga , char[] );
liga quitaPrimero(liga );
int CalcularTamLista(liga );
void imprimirFrase(liga );
double promEtiquetas(liga );
liga Invertir(liga );
liga regresaN_esimo(int ,liga );
liga intercambiarNodos(liga , int , int );
liga swapNodes(liga , int , int );
int longitud(liga );
liga desordenarLista(liga ,int );
liga limpiarFor(liga );
liga limpiarDoWhile(liga );
void freeNode(liga );
int CalcularNumNodos(liga ) ;
#endif // LISTAS_H_INCLUDED
