#ifndef SMART_QUEUE
#define SMART_QUEUE

#include <memory>
#include "smart_queue_item.h"
#include "iterator.h"
#include <random>
#include <chrono>
#include <future>
#include "../Lab7/figure.h"
#include "../Lab7/pentagon/pentagon.h"
#include "../Lab7/rhombus/rhombus.h"
#include "../Lab7/trapeze/trapeze.h"
template<class T>
class SmartQueue {

public:
    SmartQueue();
    virtual ~SmartQueue();

    bool Empty();

    void push(std::shared_ptr<T> figure);
    void del();
    void sort();
    void parallelSort();

    std::shared_ptr<T> first();
    std::shared_ptr<T> pop();

    Iterator <SmartQueueItem<T>, T> begin();
    Iterator <SmartQueueItem<T>, T> end();

    int GetSize();

    template<class A>
    friend std::ostream& operator<<(std::ostream& out, SmartQueue<A>& queue);

private:
    std::shared_ptr< SmartQueueItem<T> > GetHead();

    std::recursive_mutex queueMutex;

    std::shared_ptr< SmartQueueItem<T> > head;
    std::shared_ptr< SmartQueueItem<T> > tail;
    int size;
};


#endif
