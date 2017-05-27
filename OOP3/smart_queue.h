#ifndef SMART_QUEUE
#define SMART_QUEUE

#include <memory>
#include "smart_queue_item.h"


class SmartQueue {

public:
    SmartQueue();
    virtual ~SmartQueue();

    bool Empty() const;

    void push(std::shared_ptr<Figure>&& figure);
    void del();

    std::shared_ptr<Figure> first();
    std::shared_ptr<Figure> pop();

    friend std::ostream& operator<<(std::ostream& out, const SmartQueue queue);

private:
    std::shared_ptr<SmartQueueItem> GetHead() const;
    std::shared_ptr<SmartQueueItem> head;
    std::shared_ptr<SmartQueueItem> tail;
};


#endif