#include "smart_queue_item.h"
#include "../Lab1/figure.h"


SmartQueueItem::SmartQueueItem(std::shared_ptr<Figure>& figure) {
    item = figure;
    next = nullptr;
}

SmartQueueItem::~SmartQueueItem() {}

std::shared_ptr<SmartQueueItem> SmartQueueItem::GetNext() {
    return next;
}

std::shared_ptr<Figure> SmartQueueItem::GetItem() {
    return item;
}

void SmartQueueItem::SetLast(std::shared_ptr<SmartQueueItem> set) {
    this->next=set;
}
