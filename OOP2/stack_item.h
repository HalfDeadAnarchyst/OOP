#ifndef QUEUEITEM_H
#define	QUEUEITEM_H

#include <trapeze.cpp>

class QueueItem {
public:
    QueueItem(const Trapeze& tr);
    QueueItem(const QueueItem& orig);

    friend std::ostream&operator<< (std::ostream& out, const QueueItem& obj);

    QueueItem* AddToTail(QueueItem* last);
    QueueItem* MoveHead (QueueItem* fisrt);

    Trapeze Get() const;

    virtual  ~QueueItem();

private:
    Trapeze trap;
    QueueItem* next;
};

#endif	/* QUEUEITEM_H */