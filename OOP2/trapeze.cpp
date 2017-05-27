#include "trapeze.h"
#include <iostream>
#include <cmath>
#include <cstring>


Trapeze::Trapeze(): Trapeze(0,0,0,0) {
}

Trapeze::Trapeze(size_t a, size_t b, size_t c, size_t d) :
side_a(a), side_b(b), side_c(c), side_d(d)
{
    //std::cout <<"Trapeze with sides a=" <<side_b <<" b=" <<side_b
    //<<" c=" <<side_c <<" d=" <<side_d <<" was created\n\n";
}

Trapeze::Trapeze(const Trapeze& orig) {

    side_a=orig.side_a;
    side_b=orig.side_b;
    side_c=orig.side_c;
    side_d=orig.side_d;
}



void Trapeze::Print()
{
    std::cout <<"Bases: "  <<side_a << " " <<side_b <<'\n'
              <<"Sides: " <<side_c <<" " <<side_d <<'\n' <<'\n';
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

Trapeze& Trapeze::operator=(const Trapeze &right) {
    if(this == &right) {
        return *this;
    }

    side_a=right.side_a;
    side_b=right.side_b;
    side_c=right.side_c;
    side_d=right.side_d;

    return *this;
}

Trapeze& Trapeze::operator++() {

    side_a++;
    side_b++;
    side_c++;
    side_d++;

    return  *this;
}

Trapeze operator+(const Trapeze& l, const Trapeze& r) {

    return Trapeze(l.side_a+r.side_a,l.side_b+r.side_b,
                   l.side_c+r.side_c,l.side_d+r.side_d);
}

std::ostream& operator<< (std::ostream& out, const Trapeze& obj) {

    out << "Bases: " << obj.side_a << " " << obj.side_b <<'\n'
        << "Sides: " << obj.side_c << " " << obj.side_d <<'\n' << '\n';
    return out;
}

std::istream& operator>> (std::istream& in, Trapeze& obj) {

    in >> obj.side_a;
    in >> obj.side_b;
    in >> obj.side_c;
    in >> obj.side_b;

    return in;
}


Trapeze::~Trapeze() {
    //std::cout<<"Trapeze was deleted\n\n";
}

bool Trapeze::operator==(const Trapeze& right) {

    if(side_a==right.side_a && side_b==right.side_b &&
            side_c==right.side_c && side_d==right.side_d) {
        return true;
    } else {
        return false;
    }
}
