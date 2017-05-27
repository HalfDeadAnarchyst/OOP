#include <iostream>
#include "smart_queue.h"
#include "iterator.h"

template<class T>
SmartQueue<T>::SmartQueue(): head(nullptr), tail(nullptr) {}

template<class T>
SmartQueue<T>::~SmartQueue() {}

template<class T>
std::shared_ptr< SmartQueueItem<T> > SmartQueue<T>::GetHead() const {
    return head;
}

template<class T>
bool SmartQueue<T>::Empty() const {
    return ((head == nullptr) && (tail == nullptr));
}

template<class T>
void SmartQueue<T>::push(std::shared_ptr<T>&& figure) {

    std::shared_ptr< SmartQueueItem<T> > it(new SmartQueueItem<T>(figure));
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
template<class T>
std::shared_ptr<T> SmartQueue<T>::first(){
    return head->GetItem();
}
template<class T>
std::shared_ptr<T> SmartQueue<T>::pop() {
    std::shared_ptr<T> it;

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

template<class T>
std::ostream& operator<<(std::ostream& out, const SmartQueue<T>& queue) {
    if(queue.Empty()) {
        out << "Queue is Empty\n\n";
    } else {
        std::shared_ptr< SmartQueueItem<T> > iterator(queue.GetHead());
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
template<class T>
void SmartQueue<T>::del() {
    while(!this->Empty()) {
        this->pop();
    }
}

template<class T> Iterator <SmartQueueItem<T>, T> SmartQueue<T>::begin() {
    return Iterator<SmartQueueItem<T>, T>(head);
}

template <class T> Iterator<SmartQueueItem<T>, T> SmartQueue<T>::end() {
    return Iterator<SmartQueueItem<T>, T>(nullptr);
}


#include "../Lab1/figure.h"
template class SmartQueue<Figure>;
template  std::ostream& operator<<(std::ostream& out,const SmartQueue<Figure>& obj);