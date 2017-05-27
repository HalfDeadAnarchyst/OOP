#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <iostream>
#include <cstdlib>
#include "../figure.h"

class Trapeze : public Figure{
public:
    Trapeze();
    Trapeze(std::istream& inputStream);
    Trapeze(size_t side_a, size_t side_b, size_t side_c, size_t side_d);

    double Square() override;
    void Print() override;
    bool type(Figure* figure) override;

    virtual ~Trapeze();
/*
    void* operator new(size_t size) ;
    void operator delete(void* ptr);

    static AllocationBlock ItemAllocator;
*/
    friend std::ostream &operator<<(std::ostream &out, const Trapeze& trapeze);

private:
    size_t side_a;
    size_t side_b;
    size_t side_c;
    size_t side_d;
};

#endif //TRAPEZE_H
