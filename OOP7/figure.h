#ifndef FIGURE_H
#define	FIGURE_H

#include "Allocate/AllcationBlock.h"

class Figure {
public:
    virtual double Square() = 0;
    virtual void   Print() = 0;

    virtual ~Figure() {};

    virtual bool type(Figure* figure) = 0;
    //virtual bool operator==(const Figure& lhs,const Figure& rhs);
    //virtual bool operator!=(const Figure& lhs,const Figure& rhs);

};

#endif	/* FIGURE_H */
