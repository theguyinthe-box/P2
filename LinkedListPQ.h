//
// Created by Adam on 3/18/2023.
//

#ifndef LINKED_LIST_PQ_H
#define LINKED_LIST_PQ_H

#include "PriorityQueue.h"
#include "LinkedList.h"

template<class T>
class LinkedListPQ : public PriorityQueue<T> {

private:
    LinkedList<T> *pq;

public:
// Your code here
    //  Inserts a new object into the priority queue.  Returns true if
    //  the insertion is successful.  If the PQ is full, the insertion
    //  is aborted, and the method returns false.
    virtual bool insert(T object) {}

    //  Removes the object of highest priority that has been in the
    //  PQ the longest, and returns it.
    //  Throws invalid_argument if the PQ is empty.
    //         exception error message: "Cannot remove from empty queue"
    virtual T remove() {}

    //  Deletes all instances of the parameter obj from the PQ if found, and
    //  returns true.  Returns false if no match to the parameter obj is found.
    virtual bool deleteAll(T obj) {}

    //  Returns the object of highest priority that has been in the
    //  PQ the longest, but does NOT remove it.
    //  Throws invalid_argument if the PQ is empty.
    //         exception error message: "Cannot peek from empty queue"
    virtual T peek() {}

    //  Returns true if the priority queue contains the specified element
    //  false otherwise.
    virtual bool contains(T obj) {}

    //  Returns the number of objects currently in the PQ.
    virtual int size() {}

    //  Returns the PQ to an empty state.
    virtual void clear() {}

    //  Returns true if the PQ is empty, otherwise false
    virtual bool isEmpty() {}

    //  Returns true if the PQ is full, otherwise false.  List based
    //  implementations should always return false.
    virtual bool isFull() {}

    //  Returns iterator to first element in PQ list, regardless of priority order
    virtual ListIterator<T> first() { return pq->first; }

    //  Returns iterator to first element in PQ list, regardless of priority order
    virtual ListIterator<T> end() {}
};

#endif //LINKED_LIST_PQ_H
