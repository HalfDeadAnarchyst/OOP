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

    double Square() override;
    void Print() override;
    void menu() override ;

    virtual ~Rhombus();

private:
    size_t side; //все стороны равны
    size_t angle; //все равно какой угл водить, наибольший или наименьший
                  //синус будет одинаковый
};


#endif /*RHOMBUS_H */
