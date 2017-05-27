#include "pentagon.h"
#include <cmath>
#include <cstring>
#include <iostream>

Pentagon::Pentagon(): Pentagon(0){ }

Pentagon::Pentagon(size_t s): side(s)
{
    //std::cout <<"Pentagon with length of sides " <<side
    //<<" was created\n\n";
}

Pentagon::Pentagon(std::istream& is)
{
    std::cout <<"Enter side:\n";
    is >>side;

    std::cout <<"Pentagon with length of sides " <<side
    <<" was created\n\n";
}

void Pentagon::Print()
{
    std::cout <<"Length of sides: " <<side
    <<"\nAnd angles 108°" <<std::endl;
}

double Pentagon::Square()
{
    double res=(5*side*side)/(4*tan(36)); //acos(-1)=PI
    std::cout <<"Pentagon sqare S=" <<res <<std::endl;
    return res;
}

Pentagon::~Pentagon()
{
    std::cout <<"Pentagon was deleted\n\n";
}
void Pentagon::menu()
{

    this->Print();
    this->Square();
}
