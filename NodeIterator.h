//
// Created by matma on 3/19/2025.
//

#ifndef NODEITERATOR_H
#define NODEITERATOR_H
#include "Node.h"
#include <iterator>

template<typename T>
class NodeIterator : public std::iterator<std::bidirectional_iterator_tag, T>{
    Node<T>* current;

public:
    NodeIterator(Node<T>* current);

    NodeIterator& operator++(); //prefix ++ operator (i.e. ++iter)
    NodeIterator operator++(int); //postfix ++ operator (i.e. iter++)
    NodeIterator& operator--(); //prefix
    NodeIterator operator--(int); //postfix
    Node<T>* operator&();
    T& operator*();

    template <typename U>
    friend bool operator==(NodeIterator<U> left, NodeIterator<U> right);
    template <typename U>
    friend bool operator!=(NodeIterator<U> left, NodeIterator<U> right);

};


#include "NodeIterator.cpp"
#endif //NODEITERATOR_H
