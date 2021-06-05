#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

typedef struct NODE{
    double item;
    struct NODE *izq,*der;
}node;

typedef node* liga;

liga creaLista(int,int);
void imprimeListaDerecha(liga );
void imprimeListaIzquierda(liga );
liga dobleLigar(liga);
liga FindNode(double, liga, double, liga);
liga regresaNth(int,liga);
double SumData(liga, int);
int countNodes(liga,int);
double Varianza(liga, int, double);
liga limpiarLista(liga);

#endif // LISTAS_H_INCLUDED
