#ifndef SMART_QUEUE_ITEM
#define SMART_QUEUE_ITEM

#include <memory>
#include "../figure.h"
#include "../pentagon/pentagon.h"
#include "../rhombus/rhombus.h"
#include "../trapeze/trapeze.h"
#include "../Allocate/AllcationBlock.h"
template<class T>
class SmartQueueItem {

public:
    SmartQueueItem();
    virtual ~SmartQueueItem();

    std::shared_ptr< SmartQueueItem<T> > GetNext();
    std::shared_ptr<T> GetItem() const;

    void SetLast(std::shared_ptr< SmartQueueItem<T> > set);

    Figure* first();

    void* operator new(size_t size);
    void operator delete(void* ptr);
    static AllocationBlock ItemAllocator;

    std::shared_ptr<T> item;
    std::shared_ptr< SmartQueueItem<T> > next;
};
#endif