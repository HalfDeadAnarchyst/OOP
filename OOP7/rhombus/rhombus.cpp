#include "rhombus.h"
#include <cmath>
#include <cstring>
#include <iostream>

Rhombus::Rhombus(): Rhombus(0,0){ }

Rhombus::Rhombus(size_t s, size_t a): side(s), angle(a)
{

}

Rhombus::Rhombus(std::istream& is)
{

}

void Rhombus::Print()
{
    std::cout << "Rhombus\n";
    std::cout <<"Length of sides: " <<side
              <<"\nAngle: " <<angle <<"°"
              << "\nSquare: " << this->Square() << '\n' <<std::endl;
}

double Rhombus::Square()
{
    double res=side*side*sin(angle*acos(-1)/180); //acos(-1)=PI
    //std::cout <<"Square: " <<res <<std::endl;
    return res;
}

Rhombus::~Rhombus()
{
    std::cout <<"Rhombus was deleted\n\n";
}


/*
AllocationBlock Rhombus::ItemAllocator(sizeof(Rhombus),2000);

void *Rhombus::operator new(size_t size) {
    return ItemAllocator.Allocate();
}

void Rhombus::operator delete(void *ptr) {
    ItemAllocator.Deallocate(ptr);
}
*/

std::ostream &operator<<(std::ostream &out, const Rhombus& rhombus) {
    out <<"Length of sides: " <<rhombus.side <<"\nAngle A=" <<rhombus.angle <<"°" <<std::endl;
    return out;
}

bool Rhombus::type(Figure* figure) {
    return (dynamic_cast<Rhombus*>(figure) != nullptr);
}