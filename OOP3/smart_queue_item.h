#ifndef SMART_QUEUE_ITEM
#define SMART_QUEUE_ITEM

#include <memory>
#include "../Lab1/figure.h"

class SmartQueueItem {

public:
    SmartQueueItem(std::shared_ptr<Figure>& figure);
    virtual ~SmartQueueItem();

    std::shared_ptr<SmartQueueItem> GetNext();
    std::shared_ptr<Figure> GetItem();

    void SetLast(std::shared_ptr<SmartQueueItem> set);

private:
    std::shared_ptr<Figure> item;
    std::shared_ptr<SmartQueueItem> next;
};

#endif