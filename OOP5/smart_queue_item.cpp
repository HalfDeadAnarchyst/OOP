#include "smart_queue_item.h"
#include "../Lab1/figure.h"


template<class T>
SmartQueueItem<T>::SmartQueueItem(std::shared_ptr<T>& figure) {
    this->item = figure;
    this->next = nullptr;
}
template<class T>
SmartQueueItem<T>::~SmartQueueItem() {}

template<class T>
std::shared_ptr< SmartQueueItem<T> > SmartQueueItem<T>::GetNext() {
    return next;
}
template<class T>
std::shared_ptr<T> SmartQueueItem<T>::GetItem() const{
    return item;
}
template<class T>
void SmartQueueItem<T>::SetLast(std::shared_ptr< SmartQueueItem<T> > set) {
    this->next=set;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const SmartQueueItem<T>& it) {
    std::shared_ptr<Figure> f = it.GetItem();
    f->Print();
}




#include "../Lab1/figure.h"
template class SmartQueueItem<Figure>;
template  std::ostream& operator<<(std::ostream& out,const SmartQueueItem<Figure>& obj);