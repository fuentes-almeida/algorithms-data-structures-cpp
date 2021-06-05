#include <iostream>
#include <stdlib.h>
#include "matrix.hpp"
using namespace std;

int main()
{
    matrix A(3,3),B(3,3),C(3,3,0);

    cout<<"A="<<endl;
    cout<<A;
    cout<<"B="<<endl;
    cout<<B;

    C=A+B;
    cout<<"A+B="<<endl;
    cout<<C;

    C=A-Bt<<"A-B="<<endl;
    cout<<C;

    B=B.traspose();
    cout<<"B traspuesta="<<endl;
    cout<<B;

    B=-B;
    cout<<"-B="<<endl;
    cout<<B;

    B=5*B;
    cout<<"5*B="<<endl;
    cout<<B;

    C=A*B;
    cout<<"A*B="<<endl;
    cout<<C;

    return 0;
}
