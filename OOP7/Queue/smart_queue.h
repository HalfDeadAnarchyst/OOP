#ifndef SMART_QUEUE
#define SMART_QUEUE
#include <memory>
#include "../QueueItem/smart_queue_item.h"
#include "../iterator.h"
#include "../figure.h"
#include "../pentagon/pentagon.h"
#include "../rhombus/rhombus.h"
#include "../trapeze/trapeze.h"
template<class T, class F> //T - container, F- figure
class SmartQueue {

public:
    SmartQueue();
    virtual ~SmartQueue();

    bool Empty() const;

    void push(F* figure);
    void del();

    //void AddContainer

    F* top();

    std::shared_ptr<T> first();
    F* pop();

    Iterator <SmartQueueItem<T>, T> begin();
    Iterator <SmartQueueItem<T>, T> end();

    template<class A, class B>
    friend std::ostream& operator<<(std::ostream& out, const SmartQueue<A,B>& queue);

    void DelLess(double value);
    void DelGreater(double value);
    void DelByType(Figure* figure);

    void DelEmpty();

private:
    std::shared_ptr< SmartQueueItem<T> > GetHead() const;
    std::shared_ptr< SmartQueueItem<T> > head;
    std::shared_ptr< SmartQueueItem<T> > tail;
};


#endif
