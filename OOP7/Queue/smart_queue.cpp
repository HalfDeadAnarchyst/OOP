#include <iostream>
#include "smart_queue.h"
#include "../iterator.h"
#include "../TreeLvl2/Tree.h"

template<class T,class F>
F* SmartQueue<T,F>::top() {
    if(this->Empty()) {
        std::cout << "Queue is empty\n";
        return nullptr;
    }
    else {
        F* res = this->head->first();
        return res;
    }
}

template<class T,class F>
SmartQueue<T,F>::SmartQueue(): head(nullptr), tail(nullptr) {}

template<class T, class F>
SmartQueue<T,F>::~SmartQueue() {}

template<class T, class F>
std::shared_ptr< SmartQueueItem<T> > SmartQueue<T,F>::GetHead() const {
    return head;
}

template<class T, class F>
bool SmartQueue<T,F>::Empty() const {
    return ((head == nullptr) && (tail == nullptr));
}

template<class T, class F>
void SmartQueue<T,F>::push(F* figure) {

    if(this->Empty()){
        SmartQueueItem<T>* newelem = new SmartQueueItem<T>();
        std::shared_ptr< SmartQueueItem<T> > newElem(newelem);
        this->head = newElem;
        this->tail = newElem;
        this->head->next = tail;
        this->tail->next = nullptr;
    }
    else if(this->tail->item->children_size >= 4){
        SmartQueueItem<T>* newelem = new SmartQueueItem<T>();
        std::shared_ptr< SmartQueueItem<T> > newElem(newelem);
        this->tail->next = newElem;
        tail = tail->next;
    }
    this->tail->item->Insert(figure);
}

template<class T, class F>
std::shared_ptr<T> SmartQueue<T,F>::first(){
    return head->GetItem();
}

template<class T, class F>
F* SmartQueue<T,F>::pop() {
    if(this->Empty()) {
        return nullptr;
    }
    else {
        F* it;
        it = this->head->item->Pull(0);
        if(this->head->item->Empty()) {
            if(head == tail) {
                head = nullptr;
                tail = nullptr;
            }
            else {
                head = head->next;
            }
        }
        return it;
    }
}

template<class T, class F>
std::ostream& operator<<(std::ostream& out, const SmartQueue<T,F>& queue) {
    if(queue.Empty()) {
        out << "Queue is Empty\n\n";
    } else {
        std::shared_ptr< SmartQueueItem<T> > iterator(queue.GetHead());
        while(iterator->GetNext() != nullptr) {
            iterator->GetItem()->Print();
            out << "\n";
            iterator=iterator->GetNext();
            out << "______________________\n";
        }
        iterator->GetItem()->Print();
        out << "\n\n\n";
    }
    return out;
}
template<class T, class F>

void SmartQueue<T,F>::del() {
    while(!this->Empty()) {
        this->pop();
    }

}

template<class T, class F> Iterator <SmartQueueItem<T>, T> SmartQueue<T,F>::begin() {
    return Iterator<SmartQueueItem<T>, T>(head);
}

template <class T, class F> Iterator<SmartQueueItem<T>, T> SmartQueue<T,F>::end() {
    return Iterator<SmartQueueItem<T>, T>(nullptr);
}

template <class T,class F>  void SmartQueue<T,F>::DelEmpty() {
    while(head->item->Empty()) {
        if(head == tail) {
            head = nullptr;
            tail = nullptr;
            return;
        }
        head = head->next;
    }
    if(head == tail && (!head->item->Empty())) {
        head->next = tail;
        tail->next = nullptr;
        return;
    }
    std::shared_ptr< SmartQueueItem<T> > iterator1(this->GetHead());
    while(iterator1->next != nullptr) {
        if(iterator1->next->item->Empty()) {
            if(iterator1->next->next == nullptr) {
                iterator1->next = nullptr;
                this->tail = iterator1;
                return;
            }
            else {
                iterator1->next = iterator1->next->next;
                continue;
            }
        }
        iterator1 = iterator1->next;
    }
    this->tail = iterator1;
}

template <class T, class F> void SmartQueue<T,F>::DelLess(double value) {

    std::shared_ptr< SmartQueueItem<T> > iterator(this->GetHead());

    while(iterator->next != nullptr) {
        iterator->item->Del_Less(value);
        iterator = iterator->next;
    }
    iterator->item->Del_Less(value);
    this->DelEmpty();

}

template <class T,class F> void SmartQueue<T,F>::DelGreater(double value) {
    std::shared_ptr< SmartQueueItem<T> > iterator(this->GetHead());

    while(iterator->next != nullptr) {
        iterator->item->Del_Greater(value);
        iterator = iterator->next;
    }
    iterator->item->Del_Greater(value);
    this->DelEmpty();
}

template <class T, class F>
void SmartQueue<T,F>::DelByType(Figure* figure) {
    std::shared_ptr< SmartQueueItem<T> > iterator(this->GetHead());

    while(iterator->next != nullptr) {
        iterator->item->Del_ByType(figure);
        iterator = iterator->next;
    }
    iterator->item->Del_ByType(figure);
    this->DelEmpty();
}

#include "../figure.h"
#include "../TreeLvl2/Tree.h"
template class SmartQueue<TreeLvl2<Figure>, Figure>;
template  std::ostream& operator<<(std::ostream& out,const SmartQueue<TreeLvl2<Figure>,Figure>& obj);