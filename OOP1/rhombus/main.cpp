#include <cstdlib>
#include <iostream>
#include <cmath>
#include "rhombus.cpp"

int main()
{
    /*Figure* ptr1=new Rhombus(10,30);
    ptr1->Print();
    ptr1->Square();
    delete ptr1;*/

    Figure* ptr2=new Rhombus(std::cin);
    ptr2->Print();
    ptr2->Square();
    delete ptr2;


}
