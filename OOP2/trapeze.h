#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <iostream>
#include <cstdlib>


class Trapeze {

public:
    Trapeze();
    Trapeze(size_t side_a, size_t side_b, size_t side_c, size_t side_d);
    Trapeze(const Trapeze& orig);

    void Print();

    double Square();

    Trapeze&operator++();
    Trapeze&operator=(const Trapeze& right);
    bool operator==(const Trapeze& right);

    friend Trapeze operator+(const Trapeze& r, const Trapeze& l);
    friend std::ostream& operator<< (std::ostream& out, const Trapeze&);
    friend std::istream& operator>> (std::istream& in, Trapeze&);


    virtual ~Trapeze();

private:
    size_t side_a;
    size_t side_b;
    size_t side_c;
    size_t side_d;
};

#endif //TRAPEZE_H
