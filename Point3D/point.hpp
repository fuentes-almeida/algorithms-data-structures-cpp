#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

#include <iostream>

using namespace std;

template <class tipo>
class Point
{
    tipo _x,_y;
public:
    Point()
    {
        _x=_y=0;
    }
    Point(const tipo x, const tipo y)
    {
        _x=x;
        _y=y;
    }
    Point(const Point &from)
    {
        _x=from._x;
        _y=from._y;
    }
    ~Point(){/*Nada que hacer! */}

    void setX(const tipo val){_x=val;}
    void setY(const tipo val){_y=val;}
    tipo getX(){return _x;}
    tipo getY(){return _y;}

};

template <class tipo>
class Point3D: public Point<tipo>
{
    tipo _z;
public:
    Point3D():Point<tipo>()
    {
       _z=0;
    }
    Point3D(const tipo x, const tipo y, const tipo z): Point<tipo>(x,y)
    {
        _z=z;
    }
    ~Point3D(){/*Nada que hacer! */}
    void setZ(const tipo val){_z=val;}
    tipo getZ(){return _z;}
    tipo getX()
    {
        return Point<tipo>::getX();

    }
};


#endif // POINT_HPP_INCLUDED
