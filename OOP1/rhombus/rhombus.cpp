#include "rhombus.h"
#include <cmath>
#include <cstring>
#include <iostream>

Rhombus::Rhombus(): Rhombus(0,0){ }

Rhombus::Rhombus(size_t s, size_t a): side(s), angle(a)
{
    //std::cout <<"Rhombus with length of sides " <<side
    //<<"\nAnd angle A=" <<angle <<"°" <<" was created\n\n";
}

Rhombus::Rhombus(std::istream& is)
{
    std::cout <<"Enter side:\n";
    is >>side;
    std::cout <<"Enter angle:\n";
    is >>angle;
    std::cout <<"Rhombus with length of sides " <<side
    <<"\nAnd angle A=" <<angle <<"° was created\n\n";
}

void Rhombus::Print()
{
    std::cout <<"Length of sides: " <<side
    <<"\nAngle A=" <<angle <<"°" <<std::endl;
}

double Rhombus::Square()
{
    double res=side*side*sin(angle*acos(-1)/180); //acos(-1)=PI
    std::cout <<"Rhombus sqare S=" <<res <<std::endl;
    return res;
}

Rhombus::~Rhombus()
{
    std::cout <<"Rhombus was deleted\n\n";
}

void Rhombus::menu()
{
    this->Print();
    this->Square();
}
