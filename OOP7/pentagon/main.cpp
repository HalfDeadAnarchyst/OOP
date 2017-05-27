#include <cstdlib>
#include <iostream>
#include <cmath>
#include "pentagon.cpp"

int main()
{
    /*Figure* ptr1=new Pentagon(10);
    ptr1->Print();
    ptr1->Square();
    delete ptr1;*/

    Figure* ptr2=new Pentagon(std::cin);
    ptr2->Print();
    ptr2->Square();
    delete ptr2;


}
