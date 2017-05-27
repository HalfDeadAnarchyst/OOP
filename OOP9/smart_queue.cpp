#include <iostream>
#include "smart_queue.h"
#include "iterator.h"

template<class T>
SmartQueue<T>::SmartQueue(): head(nullptr), tail(nullptr), size(0) {}

template<class T>
SmartQueue<T>::~SmartQueue() {}

template<class T>
std::shared_ptr< SmartQueueItem<T> > SmartQueue<T>::GetHead() const {
    return head;
}

template<class T>
bool SmartQueue<T>::Empty() const {
    return ((head == nullptr) && (tail == nullptr) );
}

template<class T>
void SmartQueue<T>::push(std::shared_ptr<T> figure) {

    std::shared_ptr< SmartQueueItem<T> > it(new SmartQueueItem<T>(figure));
    if(this->Empty()){
        head=it;
        tail=it;
        head->next = tail;
        tail->next = nullptr;
    }
    else if(head == tail) {
        head->next = tail;
        tail->next = it;
        tail = tail->next;
    }
    else {
        tail->next = it;
        tail = tail->next;
    }
    size++;
}
template<class T>
std::shared_ptr<T> SmartQueue<T>::first(){
    return head->GetItem();
}
template<class T>
std::shared_ptr<T> SmartQueue<T>::pop() {
    std::shared_ptr<T> it;
    if(this->Empty()) {
        std::cout << "IDI NAHUI\n";
        return nullptr;
    }

    if(head->item == tail->item) {
        it=head->item;
        head = nullptr;
        tail = nullptr;
    }
    else {
        it=head->item;
        if(head->next != nullptr) {
            head = head->next;
        }
        else {
            it = head->item;
            if(head == nullptr) {
                std::cout << "ALARM\n";
            }
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
    }
    size--;
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

template <class T>
void SmartQueue<T>::sort() {
    if(this->size > 1) {
        std::shared_ptr<T> middle = this->pop();
        SmartQueue<T> left, right;

        while(!this->Empty()) {
            //std::shared_ptr<T> item = this->pop();
            if(head->item->Square() < middle->Square()) {
                left.push(this->pop());
            }
            else {
                right.push(this->pop());
            }
        }

        left.sort();
        right.sort();

        while(!left.Empty()) {
            std::shared_ptr<T> it = left.pop();
            this->push(it);
        }
        this->push(middle);
        while(!right.Empty()) {
            std::shared_ptr<T> it = right.pop();
            this->push(it);
        }
    }
}

template <class T>
void SmartQueue<T>::parallelSort() {
    if(this->size > 1) {
        std::shared_ptr< SmartQueueItem<T> > tmp = head;
        std::shared_ptr< SmartQueueItem<T> > tmp1 = tail;

        std::shared_ptr<T> middle = this->pop();
        SmartQueue<T> left, right;

        while(!this->Empty()) {
            if(head->item->Square() < middle->Square()) {
                std::shared_ptr<T> it = this->pop();
                left.push(it);
            }
            else {
                std::shared_ptr<T> it = this->pop();
                right.push(it);
            }
        }

        std::future<void> left1 = std::async(std::launch::async,&SmartQueue<T>::parallelSort,&left);
        std::future<void> right1 = std::async(std::launch::async,&SmartQueue<T>::parallelSort,&right);

        left1.get();
        right1.get();
        while(!left.Empty()) {
            std::shared_ptr<T> it = left.pop();
            this->push(it);
        }
        this->push(middle);
        while(!right.Empty()) {
            std::shared_ptr<T> it = right.pop();
            this->push(it);
        }
    }
}


#include "../Lab7/figure.h"
template class SmartQueue<Figure>;
template  std::ostream& operator<<(std::ostream& out,const SmartQueue<Figure>& obj);