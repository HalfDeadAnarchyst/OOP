#include "smart_queue_item.h"
#include "../Lab7/figure.h"


template<class T>
SmartQueueItem<T>::SmartQueueItem(std::shared_ptr<T>& figure,std::recursive_mutex* parent) {
    this->item = figure;
    this->next = nullptr;
    this->queueMutex = parent;
}
template<class T>
SmartQueueItem<T>::~SmartQueueItem() {}

template<class T>
std::shared_ptr< SmartQueueItem<T> > SmartQueueItem<T>::GetNext() {
    std::unique_lock<std::recursive_mutex> lock(*queueMutex);
    return next;
}
template<class T>
std::shared_ptr<T> SmartQueueItem<T>::GetItem() const{
    std::unique_lock<std::recursive_mutex> lock(*queueMutex);
    return item;
}
template<class T>
void SmartQueueItem<T>::SetLast(std::shared_ptr< SmartQueueItem<T> > set) {
    std::unique_lock<std::recursive_mutex> lock(*queueMutex);
    this->next=set;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const SmartQueueItem<T>& it) {
    std::unique_lock<std::recursive_mutex> lock(*it.queueMutex);
    std::shared_ptr<Figure> f = it.GetItem();
    f->Print();
}

template <class T>
void* SmartQueueItem<T>::operator new(size_t size) {
    //std::cout <<"weofjnelw";
    return ItemAllocator.Allocate();
}

template <class T>
void SmartQueueItem<T>::operator delete(void* ptr) {
    ItemAllocator.Deallocate(ptr);
}


#include "../Lab7/figure.h"
template class SmartQueueItem<Figure>;
template  std::ostream& operator<<(std::ostream& out,const SmartQueueItem<Figure>& obj);