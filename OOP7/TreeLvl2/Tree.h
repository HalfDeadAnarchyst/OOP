#ifndef OOP_TREELVL2_H
#define OOP_TREELVL2_H
#include <iostream>
#include "../figure.h"
template <class T> class TreeLvl2;
template <class T>
struct List {
    TreeLvl2<T>* elem;
    List<T>* next;

    List() {
        elem = nullptr;
        next = nullptr;
    }

    virtual ~List() {
        next = nullptr;
    }
};

template<class T>
class TreeLvl2 {
public:
    TreeLvl2();
    TreeLvl2(const TreeLvl2<T>& orig);

    bool Empty();

    void Insert(T* elem);
    void Delete();
    void Print();

    T* Pull(int pos);

    ~TreeLvl2();

    template<class A>
    friend std::ostream &operator<<(std::ostream &out, const TreeLvl2<A>& tree);

    void Del_Less(double value);
    void Del_Greater(double value);
    void Del_ByType(Figure* figure);

    T* node;
    List<T>* children;
    int children_size;
    bool empty;

};

template<class T> TreeLvl2<T>::TreeLvl2() {
    this->children = nullptr;
    children_size = 0;
    empty = true;

}

template<class T> TreeLvl2<T>::TreeLvl2(const TreeLvl2<T>& orig) {
    this->node = orig.node;
    this->children = orig.children;
    this->children_size = orig.children_size;
    this->empty = orig.empty;
}

template <class T> bool TreeLvl2<T>::Empty() {
    return ( empty && !children_size );
}

template <class T> void TreeLvl2<T>::Insert(T* figure) {
    //std::cout << "kek\n";
    if(empty) {
        node = figure;
        empty = false;
    }
    else {

        if(this->node->Square() >= figure->Square()) {
            T* tmp = this->node;
            this->node = figure;

            List<T>* newElem = new List<T>;
            TreeLvl2<T>* el = new TreeLvl2;
            newElem->elem = el;
            newElem->elem->node = tmp;

            newElem->next = this->children;
            this->children = newElem;
            children_size++;
            return;
        }
        else if(children_size == 0) {
            List<T>* newElem = new List<T>;
            TreeLvl2<T>* el = new TreeLvl2;
            newElem->elem = el;
            newElem->elem->node = figure;

            this->children = newElem;
            children_size++;
        }
        else {
            List<T>* iterator = this->children;
            while(iterator->next != nullptr) {
                if(iterator->elem->node->Square() >= figure->Square()) {
                    List<T>* newElem = new List<T>;
                    TreeLvl2<T>* el = new TreeLvl2;
                    newElem->elem = el;
                    newElem->elem->node = iterator->elem->node;

                    List<T>* iterator2 = iterator->next;

                    iterator->next = newElem;
                    iterator->elem->node = figure;
                    newElem->next = iterator2;

                    children_size++;
                    return;
                }
                else {
                    iterator = iterator->next;
                }
            }
            List<T>* newElem = new List<T>;
            TreeLvl2<T>* el = new TreeLvl2;
            newElem->elem = el;

            if(iterator->elem->node->Square() >= figure->Square()) {
                newElem->elem->node = iterator->elem->node;
                iterator->elem->node = figure;
                iterator->next = newElem;
            }
            else {
                newElem->elem->node = figure;
                iterator->next = newElem;
            }
            children_size++;
        }
    }
}

template <class T> T* TreeLvl2<T>::Pull(int pos) {
    //std::cout << "lol\n";
    if(empty) {
        std::cout << "TreeLvl2 is empty\n";
        return nullptr;
    }
    else {
        T* res = this->node;
        if( children_size > 1) {
            this->node = this->children->elem->node;
            children_size--;

            List<T> *toDel = this->children;
            this->children = this->children->next;
            delete (toDel);
        }
        else if( children_size == 0 ){
            this->empty = true;
        }
        else if( children_size == 1) {
            this->node = this->children->elem->node;
            delete(this->children);
            children_size--;
        }
        return res;
    }
}


template <class T> void TreeLvl2<T>::Delete() {
    while( !this->Empty()) {
        this->Pull(1);
    }
}

template <class T> TreeLvl2<T>::~TreeLvl2() {

}

template <class T> void TreeLvl2<T>::Print() {
    if(this->Empty()) {
        std::cout << "TreeLvl2 is empty\n";
    }
    else {
        this->node->Print();
        if(this->children_size > 0) {
            List<T>* iterator = this->children;
            for(int i = 0; i < this->children_size; ++i) {
                iterator->elem->node->Print();
                iterator = iterator->next;
            }
            //if(children_size) {
            //    iterator->elem->node->Print();
            //}
        }
    }
}

template <class A>
std::ostream &operator<<(std::ostream &out, const TreeLvl2<A>& tree) {
    if(tree->Empty()) {
        out << "TreeLvl2 is empty\n";
    }
    else {
        tree->node->Print();
        if(tree->children_size > 0) {
            List<A>* kek = tree->children;

            for(int i = 0; i < tree->children_size; ++i) {
                out << kek->elem->node;
                kek = kek->next;
            }
            //if(children_size) {
            //    iterator->elem->node->Print();
            //}
        }
    }

}


template <class T>
void TreeLvl2<T>::Del_Less(double value) {
    T* toDel;
    while(this->node->Square() <= value ) {
        if(this->Empty()) {
            break;
        }
        toDel = Pull(0);
        delete(toDel);
    }

}

template <class T>
void TreeLvl2<T>::Del_Greater(double value) {
    T* toDel;
    List<T>* ListToDel;
    if(this->Empty()) {
        return;
    }

    if(this->node->Square() >= value) {
        while(!this->Empty()) {
            toDel = Pull(0);
            delete(toDel);
        }
    }
    else if(children_size > 0){
        if(this->children->elem->node->Square() >= value) {
            while(children_size) {
                toDel = this->children->elem->node;
                ListToDel = this->children;
                this->children = this->children->next;
                delete(toDel);
                delete(ListToDel);
                children_size--;
            }
            this->children = nullptr;
        }
        else {
            List<T>* iter = this->children;
            while(iter->next != nullptr) {
                if(iter->next->elem->node->Square() >= value) {
                    toDel = iter->next->elem->node;
                    ListToDel = iter->next;
                    iter->next = iter->next->next;
                    delete(toDel);
                    delete(ListToDel);
                }
                else {
                    iter = iter->next;
                }
            }
        }
    }
}

template <class T>
void TreeLvl2<T>::Del_ByType(Figure* figure) {
    T* toDel;
    if(this->Empty()) {
        return;
    }

    while(this->node->type(figure)) {
        if(this->Empty()) {
            break;
        }
        toDel = this->Pull(0);
        delete(toDel);
    }
    if(this->Empty() || children_size == 0) {
        return;
    }

    List<T>* iterator = this->children;

    while(children_size && this->children->elem->node->type(figure)) {
        toDel = this->children->elem->node;
        iterator = this->children;
        this->children = this->children->next;

        children_size--;
        delete(toDel);
        delete(iterator);
    }

    if(children_size <= 1) {
        return;
    }

    iterator = this->children;
    List<T>* listToDel;
    while(iterator->next != nullptr) {
        if(iterator->next->elem->node->type(figure)) {
            toDel = iterator->next->elem->node;
            listToDel =  iterator->next;

            iterator->next = iterator->next->next;
            delete(toDel);
            delete(listToDel);
        }
        else {
            iterator = iterator->next;
        }
    }
}

#endif //OOP_TREELVL2_H
