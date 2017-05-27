#include "trapeze.h"
#include <iostream>
#include <cmath>
#include <cstring>


Trapeze::Trapeze(): Trapeze(0,0,0,0) {
}

Trapeze::Trapeze(size_t a, size_t b, size_t c, size_t d) :
side_a(a), side_b(b), side_c(c), side_d(d)
{
    //std::cout <<"Trapeze with sides a=" <<side_a <<" b=" <<side_b
    //<<" c=" <<side_c <<" d=" <<side_d <<" was created\n\n";
}

Trapeze::Trapeze(std::istream& is)
{
    std::cout <<"Enter 2 bases: \n";
    is >> side_a;
    is >> side_b;
    std::cout <<"Enter 2 sides: \n";
    is >> side_c;
    is >> side_d;
    std::cout <<"Trapeze with sides a=" <<side_b <<" b=" <<side_b
    <<" c=" <<side_c <<" d=" <<side_d <<" was created\n\n";
}

/*Trapeze::Trapeze(const Triangle& original)
{
    side_a=original.side_a;
    side_b=original.side_b;
    side_c=original.side_c;
    side_d=original.side_d;
}*/

void Trapeze::Print()
{
    std::cout <<"Bases of trapeze:\n"
              <<"a=" <<side_a <<'\n'
              <<"b=" <<side_b <<'\n'
              <<"sides of trapeze:\n"
              <<"c=" <<side_c <<'\n'
              <<"d=" <<side_d <<'\n' <<'\n';
}


double Trapeze::Square()
{
    double x,y;
    if(side_a>=side_b)
        x=side_a;
    else
        x=side_b;

    if(side_c>=side_d)
        y=side_c;
    else
        y=side_d;

    if(x<y)
        x=y; // x- наибольшая сторона трапеции

    double sum3=side_a+side_b+side_c+side_d-x;

    if(side_a==side_b || (sum3<=x) ) //проверка существования данной трапеции
    {
        std::cout <<"Trapeze with this sides doesn't exist.\n";
        return -1;
    }
    else
    {
        double b_a=side_b-side_a;
        if(side_b<0)
            b_a*=-1;
        b_a=(b_a*b_a+side_c*side_c-side_d*side_d)/(2*b_a);
        double p=(side_a+side_b)/2; //полусумма оснований
        double sq=side_c*side_c - b_a*b_a;
        if(sq<=0)
        {
            std::cout <<"Trapeze with this sides doesn't exist.\n";
            return -1;
        }
        double res=p*sqrt( side_c*side_c - b_a*b_a   );

        std::cout <<"Trapeze square S=" <<res <<std::endl;
        return res;

    }
}

Trapeze::~Trapeze() {
    std::cout<<"Trapeze was deleted\n\n";
}

void Trapeze::menu()
{
    this->Print();
    this->Square();

}
