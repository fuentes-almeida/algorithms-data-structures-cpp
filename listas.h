#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

typedef struct NODE{
    int item;
    struct NODE* next;
}node;
typedef node* liga;

liga createNode(int, liga);
liga insertarAlInicio(int,liga);
liga insertaAlFinal(int ,liga );
void imprimeLista(liga );
int longitud(liga );
liga regresaNth(int ,liga );
liga ultimo(liga );
liga quitaPrimero(liga );
liga quitaUltimo(liga );
liga limpiar(liga );


#endif // LISTAS_H_INCLUDED
