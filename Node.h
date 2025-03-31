//
// Created by matma on 3/17/2025.
//

#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
    Node<T>* previous = nullptr;
};



#endif //NODE_H
