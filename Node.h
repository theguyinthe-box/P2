//
// Created by Adam on 3/18/2023.
//

#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
public:
    int data;
    Node *next;

    Node(int newData) {
        data = newData;
        next = nullptr;
    }
};

#endif //NODE_H
