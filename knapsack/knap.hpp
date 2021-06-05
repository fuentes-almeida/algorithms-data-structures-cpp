#ifndef KNAP_HPP_INCLUDED
#define KNAP_HPP_INCLUDED

#define N 5
#define SIZE 17

typedef struct{
    char name;
    int weight;
    int val;
} Item;

int knap(int cap);

#endif // KNAP_HPP_INCLUDED
