#ifndef SMART_QUEUE
#define SMART_QUEUE

#include <memory>
#include "smart_queue_item.h"
#include "iterator.h"
#include "../Lab1/figure.h"
#include "../Lab1/pentagon/pentagon.h"
#include "../Lab1/rhombus/rhombus.h"
#include "../Lab1/trapeze/trapeze.h"
template<class T>
class SmartQueue {

public:
    SmartQueue();
    virtual ~SmartQueue();

    bool Empty() const;

    void push(std::shared_ptr<T>&& figure);
    void del();

    std::shared_ptr<T> first();
    std::shared_ptr<T> pop();

    Iterator <SmartQueueItem<T>, T> begin();
    Iterator <SmartQueueItem<T>, T> end();

    template<class A>
    friend std::ostream& operator<<(std::ostream& out, const SmartQueue<A>& queue);

private:
    std::shared_ptr< SmartQueueItem<T> > GetHead() const;
    std::shared_ptr< SmartQueueItem<T> > head;
    std::shared_ptr< SmartQueueItem<T> > tail;
};


#endif
