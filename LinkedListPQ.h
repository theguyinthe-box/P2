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
    bool insert(T object) { return pq->addFirst(); }

    //  Removes the object of highest priority that has been in the
    //  PQ the longest, and returns it.
    //  Throws invalid_argument if the PQ is empty.
    //         exception error message: "Cannot remove from empty queue"
    T remove() { return pq->removeFirst(); }

    //  Deletes all instances of the parameter obj from the PQ if found, and
    //  returns true.  Returns false if no match to the parameter obj is found.
    bool deleteAll(T obj) { return pq->removeAll(obj); }

    //  Returns the object of highest priority that has been in the
    //  PQ the longest, but does NOT remove it.
    //  Throws invalid_argument if the PQ is empty.
    //         exception error message: "Cannot peek from empty queue"
    T peek() { return pq->peekFirst(); }

    //  Returns true if the priority queue contains the specified element
    //  false otherwise.
    bool contains(T obj) { return pq->contains(obj); }

    //  Returns the number of objects currently in the PQ.
    int size() { return pq->size(); }

    //  Returns the PQ to an empty state.
    void clear() { return pq->makeEmpty(); }

    //  Returns true if the PQ is empty, otherwise false
    bool isEmpty() { return pq->isEmpty(); }

    //  Returns true if the PQ is full, otherwise false.  List based
    //  implementations should always return false.
    bool isFull() { return false; }

    //  Returns iterator to first element in PQ list, regardless of priority order
    ListIterator<T> first() { return pq->peekFirst(); }

    //  Returns iterator to last element in PQ list, regardless of priority order
    ListIterator<T> end() { return pq->peekLast(); }
};

#endif //LINKED_LIST_PQ_H
