#ifndef SMART_QUEUE_ITEM
#define SMART_QUEUE_ITEM

#include <memory>
#include "../Lab7/figure.h"
#include "../Lab7/pentagon/pentagon.h"
#include "../Lab7/rhombus/rhombus.h"
#include "../Lab7/trapeze/trapeze.h"
#include "AllcationBlock.h"
template<class T>
class SmartQueueItem {

public:
    SmartQueueItem(std::shared_ptr<T>& figure);
    virtual ~SmartQueueItem();

    std::shared_ptr< SmartQueueItem<T> > GetNext();

    std::shared_ptr<T> GetItem() const;


    void SetLast(std::shared_ptr< SmartQueueItem<T> > set);


    void* operator new(size_t size);
    void operator delete(void* ptr);
    static AllocationBlock ItemAllocator;

    std::shared_ptr<T> item;
    std::shared_ptr< SmartQueueItem<T> > next;
};


template <class T> AllocationBlock
        SmartQueueItem<T>::ItemAllocator(sizeof(SmartQueueItem<T>), 1000);


#endif