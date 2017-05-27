
#ifndef OOP_TREE_H
#define OOP_TREE_H

#include <iostream>


template<class T>
class Tree {
public:
    Tree();
    Tree(const Tree<T>& orig);

    bool Empty();

    void Insert(T& elem);
    void Delete();

    T Pull(int pos);


    ~Tree();

    typedef struct List {
        Tree<T>* elem;
        List* next;

        List() {
            elem = nullptr;
            next = nullptr;
        }

        virtual ~List() {
            next = nullptr;
        }
    }List;
    T node;
    List* children;
    int children_size;
    bool empty;

};



template<class T> Tree<T>::Tree() {
    this->children = nullptr;
    children_size = 0;
    empty = true;

}

template<class T> Tree<T>::Tree(const Tree<T>& orig) {
    this->node = orig.node;
    this->children = orig.children;
    this->children_size = orig.children_size;
    this->empty = orig.empty;
}

template <class T> bool Tree<T>::Empty() {
    return ( empty && !children_size );
}


template <class T> void Tree<T>::Insert(T &elem) {
    //std::cout << "kek\n";
    if(empty) {
        node = elem;
        empty = false;
    }
    else {
        Tree<T>* el = new Tree;
        el->node = elem;

        List* newElem = new List;
        newElem->elem = el;
        newElem->next = nullptr;

        if(this->children_size == 0) {
            this->children = newElem;
        }
        else {
            List* iter = this->children;
            while(iter->next != nullptr){
                iter = iter->next;
            }
            iter->next = newElem;
        }
        children_size++;
    }
}

template <class T> T Tree<T>::Pull(int pos) {
    //std::cout << "lol\n";
    if(empty) {
        std::cout << "Tree is empty\n";
        return nullptr;
    }
    else {
        T res = this->node;
        if( children_size > 1) {
            this->node = this->children->elem->node;
            children_size--;

            List *toDel = this->children;
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


template <class T> void Tree<T>::Delete() {
    while( !this->Empty()) {
        this->Pull(1);
    }
}

template <class T> Tree<T>::~Tree() {

}


#endif //OOP_TREE_H
