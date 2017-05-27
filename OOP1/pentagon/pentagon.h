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
    void menu() override ;


    virtual ~Pentagon();

private:
    size_t side; //все стороны равны
};


#endif /*PENTAGON_H */
