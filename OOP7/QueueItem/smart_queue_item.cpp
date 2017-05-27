#include "smart_queue_item.h"
#include "../figure.h"
#include "../TreeLvl2/Tree.h"
template <class T>
Figure* SmartQueueItem<T>::first() {
    return this->item->node;
}

template<class T>
SmartQueueItem<T>::SmartQueueItem() {
    this->item = std::shared_ptr<T>(new T);
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
    std::shared_ptr< TreeLvl2<Figure> > f = it.GetItem();
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

template <class T> AllocationBlock
SmartQueueItem<T>::ItemAllocator(sizeof(SmartQueueItem<T>), 100);

#include "../figure.h"
#include "../TreeLvl2/Tree.h"
template class SmartQueueItem< TreeLvl2<Figure> >;
template  std::ostream& operator<<(std::ostream& out,const SmartQueueItem< TreeLvl2<Figure> > & obj);