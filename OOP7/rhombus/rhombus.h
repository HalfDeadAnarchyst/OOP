#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "../figure.h"
#include <iostream>
#include <cstdlib>

class Rhombus : public Figure {
public:
    Rhombus();
    Rhombus(std::istream& is);
    Rhombus(size_t side,size_t angle);
    bool type(Figure* figure) override;

    double Square() override;
    void Print() override;

    virtual ~Rhombus();

    //static AllocationBlock ItemAllocator;

    /*void* operator new(size_t size) ;
    void operator delete(void* ptr); */

    friend std::ostream &operator<<(std::ostream &out, const Rhombus& rhombus);
private:
    size_t side; //все стороны равны
    size_t angle; //все равно какой угол вводить, наибольший или наименьший
                  //синус будет одинаковый
};
#endif /*RHOMBUS_H */
