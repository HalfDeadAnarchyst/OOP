#ifndef PENTAGON_H
#define PENTAGON_H

#include "../figure.h"
#include <iostream>
#include <cstdlib>

class Pentagon : public Figure {
public:
    Pentagon();
    Pentagon(std::istream& is);
    Pentagon(size_t side);

    double Square() override;
    void Print() override;

    bool type(Figure* figure) override;


    virtual ~Pentagon();

    /*void* operator new(size_t size) ;
    void operator delete(void* ptr);*/

   // static AllocationBlock ItemAllocator;

    friend std::ostream &operator<<(std::ostream &out, const Pentagon& pent);

private:
    size_t side; //все стороны равны
};


#endif /*PENTAGON_H */
