//
// Created by Adam on 3/18/2023.
//

#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "Node.h"

template<class T>
class ListIterator {
    private:
        Node<T> *itptr; // Pointer to traverse the linked list
    public:
        //constructors
        ListIterator() { itptr = nullptr; }

        ListIterator(const ListIterator<T>& q) { itptr = q.itptr; }

        ListIterator(Node<T> *q) { itptr = q; }

        //overloaded operators
        //prefix
        ListIterator& operator++(){
            itptr = itptr->next;
            return *this;
        }

        ListIterator& operator++(int){
            ListIterator<T> tmp = *this;
            ++*this;
            return tmp;
        }

        bool operator==(ListIterator<T> q) {
            return itptr == q.itptr;
        }

        bool operator!=(ListIterator<T> q) {
            return itptr != q.itptr;
        }

        T& operator*(){
            return itptr->data;
        }
   
        
};

#endif //LIST_ITERATOR_H
