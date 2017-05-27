#ifndef QUEUEITEM_H
#define	QUEUEITEM_H

#include "trapeze.cpp"

class QueueItem {
public:
    QueueItem();

    QueueItem(const Trapeze &tr);

    QueueItem(const QueueItem &orig);

    friend std::ostream &operator<<(std::ostream &out, const QueueItem &obj);

    void AddNext(QueueItem* item);
    void SetNext(QueueItem* element);

    QueueItem* GetNext() const;

    Trapeze Get();

    virtual ~QueueItem();

private:



    Trapeze trap;
    QueueItem *next;
};

#endif	/* QUEUEITEM_H */