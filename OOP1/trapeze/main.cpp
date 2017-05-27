#include <cstdlib>
#include <iostream>
#include <cmath>
#include "trapeze.cpp"

int main()
{
    /*Figure* ptr1=new Trapeze(1,3,5,4);
    ptr1->Print();
    ptr1->Square();
    delete ptr1;*/

    Figure* ptr2=new Trapeze(std::cin);
    ptr2->Print();
    ptr2->Square();
    delete ptr2;


}
