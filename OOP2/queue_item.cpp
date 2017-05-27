#include <iostream>

#include "queue_item.h"

/*QueueItem::QueueItem(const Trapeze& tr) {

    this->trap = tr;
    this->next = nullptr;
    std::cout << "Stack item was created" << std::endl;
}

QueueItem::QueueItem(const QueueItem& orig) {

    this->trap=orig.trap;
    this->next=orig.next;
    std::cout << "Stack item was copied" << std::endl;
}*/

QueueItem::QueueItem(const Trapeze &tr) {

    this->trap = tr;
    this->next = nullptr;
    //std::cout << "Queue item was created" << std::endl;
}

QueueItem::QueueItem(const QueueItem &orig) {

    this->trap = orig.trap;
    this->next = orig.next;
    //std::cout << "Stack item was copied" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const QueueItem& obj) {

    out << obj.trap << std::endl;
    return out;
}

void QueueItem::AddNext(QueueItem* item) {

    this->next=item;

}

QueueItem* QueueItem::GetNext () const{

    return this->next;
}

Trapeze QueueItem::Get() {

    return (this->trap);
}

QueueItem::~QueueItem() {

    //std::cout << "Queue item was deleted" << std::endl;
    delete next;
}

void QueueItem::SetNext(QueueItem* element) {
    this->next=element;
}