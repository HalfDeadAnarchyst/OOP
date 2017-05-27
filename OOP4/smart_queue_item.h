#ifndef SMART_QUEUE_ITEM
#define SMART_QUEUE_ITEM

#include <memory>
#include "../Lab1/figure.h"
#include "../Lab1/pentagon/pentagon.h"
#include "../Lab1/rhombus/rhombus.h"
#include "../Lab1/trapeze/trapeze.h"
template<class T>
class SmartQueueItem {

public:
    SmartQueueItem(std::shared_ptr<T>& figure);
    virtual ~SmartQueueItem();

    std::shared_ptr< SmartQueueItem<T> > GetNext();

    std::shared_ptr<T> GetItem() const;

    void SetLast(std::shared_ptr< SmartQueueItem<T> > set);

private:
    std::shared_ptr<T> item;
    std::shared_ptr< SmartQueueItem<T> > next;
};

#endif