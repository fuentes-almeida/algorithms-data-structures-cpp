#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include "complex.hpp"

using namespace std;

Complex Complex::operator+(const Complex& B)
{
    Complex C;
    C.real=real+B.real;
    C.img=img+B.img;
    return C;
}

Complex Complex::operator-(const Complex& B)
{
    Complex C;
    C.real=real-B.real;
    C.img=img-B.img;
    return C;
}

Complex Complex::operator*(const Complex& B)
{
    Complex C;
    C.real=real*B.real-img*B.img;
    C.img=real*B.img+img*B.real;
    return C;
}

Complex Complex::operator/(const Complex& B)
{
    Complex C;
    C.real=(real*B.real+img*B.img)/(B.real*B.real+B.img*B.img);
    C.img=(img*B.real-real*B.img)/(B.real*B.real+B.img*B.img);
    return C;
}

ostream& operator<<(ostream& out,const Complex& A)
{
        out<<"("<<A.real<<","<<A.img<<"i"<<")";
        return out;
}
