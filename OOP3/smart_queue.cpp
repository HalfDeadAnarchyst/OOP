#include <iostream>
#include "smart_queue.h"

SmartQueue::SmartQueue(): head(nullptr), tail(nullptr) {}

SmartQueue::~SmartQueue() {}

std::shared_ptr<SmartQueueItem> SmartQueue::GetHead() const {
    return head;
}


bool SmartQueue::Empty() const {
    return ((head == nullptr) && (tail == nullptr));
}

void SmartQueue::push(std::shared_ptr<Figure> &&figure) {

    std::shared_ptr<SmartQueueItem> it(new SmartQueueItem(figure));
    if(this->Empty()){
        head=it;
        tail=it;
        head->SetLast(nullptr);
        tail->SetLast(nullptr);
    }
    else {
        tail->SetLast(it);
        tail=tail->GetNext();

    }
}

std::shared_ptr<Figure> SmartQueue::first(){
    return head->GetItem();
}

std::shared_ptr<Figure> SmartQueue::pop() {
    std::shared_ptr<Figure> it;

    if(head == tail) {
        it=head->GetItem();
        head = nullptr;
        tail = nullptr;
    }
    else {
        it=head->GetItem();
        head=head->GetNext();
    }

    return it;
}

std::ostream& operator<<(std::ostream& out, const SmartQueue queue) {
    if(queue.Empty()) {
        out << "Queue is Empty\n\n";
    } else {
        std::shared_ptr<SmartQueueItem> iterator(queue.GetHead());
        while(iterator->GetNext() != nullptr) {
            iterator->GetItem()->Print();
            out << "\n";
            iterator=iterator->GetNext();
        }
        iterator->GetItem()->Print();
        out << "\n\n";
    }
    return out;
}

void SmartQueue::del() {
    while(!this->Empty()) {
        this->pop();
    }
}

