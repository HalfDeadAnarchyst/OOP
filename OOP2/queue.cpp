#include <iostream>
#include "queue.h"

Queue::Queue() : first(nullptr), last(nullptr) {

}

Queue::Queue(const Queue &orig) {

    this->first=orig.first;
    this->last=orig.last;
}

bool Queue::Empty() {
    return (this->first == nullptr) && (this->last == nullptr);
}

void Queue::push(const Trapeze &el) {



    QueueItem *qi = new QueueItem(el);


    if ( this->Empty() ) {
        this->first = qi;
        this->last = qi;
        this->first->SetNext(nullptr);
        this->last->SetNext(nullptr);

    }
    else {
            last->SetNext(qi);
            last = last->GetNext();
    }
}

void Queue::top() {
    std::cout << this->first->Get();
    std::cout << this->first->Get().Square() << std::endl << '\n';
}

Trapeze Queue::pop() {

    Trapeze res = Trapeze(this->first->Get());
    if( this->first == this->last ) {

        this->last = nullptr;
        delete this->first;
        this->first = nullptr;
    }
    else {

        QueueItem* del = this->first;
        this->first=this->first->GetNext();
        del->SetNext(nullptr);
        delete del;
    }
    return res;
}

std::ostream& operator<<(std::ostream& out,const Queue& q) {

    QueueItem* iterator = q.first;

    while( iterator != nullptr ) {

        out << *iterator;
        iterator = iterator->GetNext();

    }
    return out;
}

Queue::~Queue() {

    while( !Empty() ) {
        pop();
    }
    delete first;
    delete last;
}

void Queue::Del() {
    while( Empty() == false ) {
        Trapeze del=pop();

    }

}
