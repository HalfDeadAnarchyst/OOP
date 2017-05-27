#include "pentagon.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include "../Allocate/AllcationBlock.h"
#include "../QueueItem/smart_queue_item.h"

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
    std::cout << "Pentagon\n";
    std::cout <<"Length of sides: " <<side
    <<"\nSquare: " << this->Square() <<'\n' <<std::endl;
}

double Pentagon::Square()
{
    double res=(5*side*side)/(4*tan(36)); //acos(-1)=PI
    //std::cout <<"Pentagon sqare S=" <<res <<std::endl;
    return res;
}

Pentagon::~Pentagon()
{
    std::cout <<"Pentagon was deleted\n\n";
}

/*
AllocationBlock Pentagon::ItemAllocator(sizeof(Pentagon),2000);

void *Pentagon::operator new(size_t size) {
    return ItemAllocator.Allocate();
}

void Pentagon::operator delete(void *ptr) {
    ItemAllocator.Deallocate(ptr);
}
*/
std::ostream &operator<<(std::ostream &out, const Pentagon& pent) {
    out <<"Length of sides: " <<pent.side <<"\nAnd angles 108°" <<std::endl;
    return out;
}

bool Pentagon::type(Figure* figure) {
    return (dynamic_cast<Pentagon*>(figure) != nullptr);
}