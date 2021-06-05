#ifndef COMPLEX_HPP_INCLUDED
#define COMPLEX_HPP_INCLUDED
#include <cmath>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Complex
{
private:
    double real, img;
public:
    Complex(double a=0,double b=0)
    {
        real=a;
        img=b;
    }

    double magnitude(Complex A)
    {
        return sqrt(A.real*A.real+A.img*A.img);
    }

    double phase(Complex A)
    {
        return atan2(A.img,A.real);
    }

    Complex operator+(const Complex& B);
    Complex operator-(const Complex& B);
    Complex operator*(const Complex& B);
    Complex operator/(const Complex& B);

    friend ostream& operator<<(ostream& out,const Complex& A);

};

#endif // COMPLEX_HPP_INCLUDED
