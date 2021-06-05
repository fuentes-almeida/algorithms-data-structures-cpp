#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include "complex.hpp"

using namespace std;

int main()
{
    srand(time(NULL));
    Complex A(5.0,6.0),B(3.0,4.0),C;
    cout<<"A = "<<A<<endl;
    cout<<"|A| = "<<A.magnitude(A)<<endl;
    cout<<"phase(A) = "<<A.phase(A)<<endl;
    cout<<"B = "<<B<<endl;
    cout<<"|B| = "<<B.magnitude(B)<<endl;
    cout<<"phase(B) = "<<B.phase(B)<<endl;
    C=A+B;
    cout<<"A+B = "<<C<<endl;
    C=A-B;
    cout<<"A-B = "<<C<<endl;
    C=A*B;
    cout<<"A*B = "<<C<<endl;
    C=A/B;
    cout<<"A/B = "<<C<<endl;

    return 0;
}
