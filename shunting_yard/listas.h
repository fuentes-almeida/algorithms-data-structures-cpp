#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

typedef union dato{
    float flotante;
    char operador_binario;
    }DATO;


typedef struct NODE{
    DATO token;
    char tipo;
    struct NODE* next;
}node;

typedef node* liga;


int precedencia(char);
liga createNode(DATO, char, liga);
liga pushList(DATO, char, liga);
liga freeNode(liga);
void imprimeLista(liga);
void popList(liga, liga);
void ComputeResult(liga, liga);
void ParseText(char*, liga*, liga*);

#endif // LISTAS_H_INCLUDED
