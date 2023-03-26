//
// Created by Adam on 3/18/2023.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include "ListIterator.h"
#include <stdexcept>

template<class T>
class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    int currentSize;

public:

/* constructor initializes private members
   Note the C++ initializer list is equivalent to
        tail = head = nullptr;
        currentSize = 0;
*/
    LinkedList() : head(nullptr), tail(head), currentSize(0) { }

// size: return number of items in the list
    int size() {
        return currentSize;
    }

// isEmpty: return true is list has no items in it
    bool isEmpty() {
        return head == nullptr;
    }

// addAt : insert item at index if it between 0 and currentSize
//         (index == currentSize adds at the end of the list)
//         else do nothing

    void addAt(int index, T obj) {
        // TODO
        // conditions to handle: bad index, empty list, one item,
        // insert at beginning, in the middle, at the end

        if(index < 0 || index > currentSize){
            throw std::runtime_error ("bad index");
        }else {
            Node<T> *curr = head,
                    *newNode= new Node<T>(obj);

            if( index == 0){
                printf("adding first\n");
                addFirst(obj);
                return;
            }

            if( index == currentSize ){
                printf("adding last\n");
                addLast(obj);
                return;
            }

            for(int i = 0; i < index - 1 ; i++){
                curr = curr->next;
            }

            newNode->next = curr->next;
            curr->next = newNode;
            currentSize++;
        }
    }

// addFirst : insert item at the head
    void addFirst(T obj) {
        Node<T> *newNode = new Node<T>(obj);
        if(isEmpty())
            head = tail = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
        currentSize++;
    }

// addLast : insert item at the tail
    void addLast(T obj) {
        Node<T> *newNode = new Node<T>(obj);
        if(isEmpty()) {
            head = newNode;
            tail = newNode;
        }else {
            tail->next = newNode;
            tail = newNode;
        }
        currentSize++;
    }

// peekFirst: return item at head if it exists, else
// if list is empty: throws runtime_error "Error: peekFirst empty list"
    T peekFirst() {
        if(head == nullptr)
            throw std::runtime_error("Error: peekFirst empty list");
        return head->data;
    }

// peekLast: return item at tail if it exists, else
// if list is empty: throws runtime_error "Error: peekLast empty list"
    T peekLast() {
        // TODO
        if(head == nullptr){
            throw std::runtime_error ("Error: peekLast empty list");
        }else {
            Node<T> *tmp = head;
            while (tmp != tail) {
                tmp = tmp->next;
            }
            return tmp->data;

            /*return tail->data;*/
        }
    }

// removeAt : delete at index if it between 0 and currentSize-1
//            else do nothing
// if list is empty: throws runtime_error "Error: removeAt empty list"
// if bad index: throws runtime_error "Error: removeAt bad index"
    void removeAt(int index) {
        // TODO
        // conditions to handle: bad index, empty list, one item,
        //         insert at beginning, in the middle, at the end
        if(isEmpty()){
            throw std::runtime_error ("Error: removeAt empty List");
        }else if( index < 0 || index > currentSize - 1) {
            throw std::runtime_error ("Error: removeAt bad index");
        }else {
            if( index == 0){
                //printf("in remove first\n");
                removeFirst();
                return;
            }else if( index == (currentSize-1) ) {
                removeLast();
                return;

            }else {
                printf("deleting some stuff in thuh middle\n");
                Node<T> *curr = head,
                        *delNode = nullptr;

                for(int i = 0; i < index; i++){
                    curr = curr->next;
                }
                delNode = curr->next;
                curr->next = delNode->next;
                delete delNode;
                currentSize--;
            }
        }
    }

// removeFirst: return the first data item and delete it from the list
// if list is empty: throws runtime_error "Error: removeFirst empty list"
    T removeFirst() {

        if(isEmpty()) {
            throw std::runtime_error("Error: removeFirst empty list");
        }
        Node<T> *nodeToDelete = head;

        T dataToReturn = head->data;

        head = head->next;

        if(head == nullptr) {
            head = tail = nullptr;
        }

        currentSize--;
        delete nodeToDelete;
        return dataToReturn;
    }

// removeLast: returns the last data item and deletes it from the list
// if list is empty: throws runtime_error "Error: removeLast empty list"
    T removeLast() {
        printf("removing last\n");
        if(isEmpty()) {
            throw std::runtime_error("Error: removeLast empty list");
        }
        Node<T> *previous = nullptr,
                *current = head;
        T tmp = tail->data;            //stores data in tail node to tmp
        if(head == tail) {             // only one element in the list
            printf("removing only one element\n");
            head = tail = nullptr;
        }else {
            while(current != tail) {
                previous = current;
                current = current->next;
            }
            previous->next = nullptr;
            tail = previous;
        }
        delete current;
        currentSize--;
        return tmp;
    }


    // find: gets the index of the object if it's in the list else
// if list is empty or the item is not found: returns -1
    int find(T obj) {
        Node<T> *curr = head;
        for(int index = 0; index < currentSize; index++){
            if(curr->data == obj){
                return index;
            }
            curr = curr->next;
        }
        return -1;
    }

// isFull: list is never full
    bool isFull() {
        return false;
    }

// makeEmpty: loop through list to delete nodes then
// reset head/tail to nullptr and currentSize to 0.
// Note: to free memory, must call for each node:
//       delete theNodeToDelete;
    void makeEmpty() {

        if(head == nullptr) {
            return;
        }
        Node<T> *curr = head,
                *delNode = nullptr;

        while(curr->next != tail){
            delNode = curr;
            curr = curr->next;
            delete delNode;
        }

        head = tail = nullptr;
        currentSize = 0;
    }

// contains: returns true if the item is in the list
    bool contains(T obj) {
        return find(obj) == -1 ? false : true;
/*
        if(head == nullptr)
           return false;
        Node<T> *tmp = head;
        while(tmp != nullptr) {
            if(tmp->data == obj)
                return true;
            tmp = tmp->next;
            }
        return false;
*/
    }

// remove:  returns true if the first occurence of the item
//          was removed from the list else
// conditions handled: empty list, one item,
//         remove at beginning, in the middle, at the end
    bool remove(T obj) {
        if(isEmpty())  // empty list
            return false;
        Node<T> *previous = nullptr, *current = head;
        while(current != nullptr) {
            if( (current->data) == obj) {
                if(current == head)  // first element
                    removeFirst();
                else if(current == tail) // last element
                    removeLast();
                else {  // in the middle
                    previous->next = current->next;
                    currentSize--;
                }
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;
    }

// removeAll: deletes all occurences of item in the list
    void removeAll(T obj) {
        while(contains(obj)){
            remove(obj);
        }
    }

// first:  returns a ListIterator at head of list
    ListIterator<T> first() {
        return ListIterator<T>(head);
    }

// end:  returns a ListIterator at one past the tail of list
    ListIterator<T> end() {
        return ListIterator<T>(nullptr);
    }
};

#endif //LINKED_LIST_H
