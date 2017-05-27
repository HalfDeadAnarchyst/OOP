#ifndef QUEUE_H
#define	QUEUE_H

#include <iostream>

#include "queue_item.cpp"

class Queue {

public:

    Queue();
    Queue(const Queue& orig);

    void push(const Trapeze &el);
    void top();
    bool Empty();
    void Del();

    Trapeze pop();

    friend std::ostream& operator<<(std::ostream& out,const Queue& q);

    virtual ~Queue();

private:
    QueueItem* first;
    QueueItem* last;

};

#endif  /* Queue */