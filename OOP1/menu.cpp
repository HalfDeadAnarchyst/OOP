#include "trapeze/trapeze.cpp"
#include "pentagon/pentagon.cpp"
#include "rhombus/rhombus.cpp"
#include "iostream"

int main()
{
    while(true)
    {
        std::cout <<"----------Menu----------" <<std::endl;
        std::cout <<"1. Trapeze" <<std::endl;
        std::cout <<"2. Rhombus" <<std::endl;
        std::cout <<"3. Pentagon" <<std::endl;
        std::cout <<"4. Exit" <<std::endl;
        int a;
        std::cin >>a;
        if(a==1)
        {
            Figure* ptr2=new Trapeze(std::cin);
            ptr2->menu();
            delete ptr2;
        }
        if(a==2)
        {
            Figure* ptr2=new Rhombus(std::cin);
            ptr2->menu();
            delete ptr2;
        }
        if(a==3)
        {
            Figure* ptr2=new Pentagon(std::cin);
            ptr2->menu();
            delete ptr2;
        }
        if(a==4)
            break;
    }
    return 0;
}