//
// Created by matma on 3/22/2025.
//

#ifndef REVERSEITERATOR_H
#define REVERSEITERATOR_H
#include <iterator>
#include "Node.h"

template <typename T>
class ReverseIterator : public std::iterator<std::bidirectional_iterator_tag, T>{
    Node<T>* current;

public:
    ReverseIterator(Node<T>* current);

    ReverseIterator& operator++(); //prefix ++ operator (i.e. ++iter)
    ReverseIterator operator++(int); //postfix ++ operator (i.e. iter++)
    ReverseIterator& operator--(); //prefix
    ReverseIterator operator--(int); //postfix
    Node<T>* operator&();
    T& operator*();

    template <typename U>
    friend bool operator==(ReverseIterator<U> left, ReverseIterator<U> right);
    template <typename U>
    friend bool operator!=(ReverseIterator<U> left, ReverseIterator<U> right);

};


#include "ReverseIterator.cpp"
#endif //REVERSEITERATOR_H
