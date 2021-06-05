#include <iostream>
#include "knap.hpp"

Item items[N];
int values[SIZE+1];
char names[SIZE+1];

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

    return max;
}
