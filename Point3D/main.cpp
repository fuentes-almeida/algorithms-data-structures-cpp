#include <iostream>
#include "point.hpp"
using namespace std;

int main()
{
    Point3D<double> P;
    P.setX(3.654);
    P.setY(4.984);
    P.setZ(-2.48);
    cout<<P.getX()<<" , "<<P.getY()<<" , "<<P.getZ()<<endl;

    Point3D<int> Q(9,1,-8);
    cout<<Q.getX()<<" , "<<Q.getY()<<" , "<<Q.getZ()<<endl;

    return 0;
}
