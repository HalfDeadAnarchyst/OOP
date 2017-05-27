#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <iostream>


template <class node, class T>
class Iterator {

public:

    Iterator(std::shared_ptr<node> n) {
        iterator = n;
    }

    std::shared_ptr<T> operator*() {
        return iterator->GetItem();
    }

    std::shared_ptr<T> operator->(){
        return iterator->GetItem();
    }

    void operator++() {
        iterator = iterator->GetNext();
    }

    Iterator operator++(int) {
        Iterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator==(Iterator const& i) {
        return iterator == i.iterator;
    }

    bool operator!=(Iterator const& i) {
        return (iterator != i.iterator);
    }

private:

    std::shared_ptr<node> iterator;
};




#endif