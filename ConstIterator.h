//
// Created by matma on 3/22/2025.
//

#ifndef CONSTITERATOR_H
#define CONSTITERATOR_H
#include "Node.h"
#include <iterator>

template<typename T>
class ConstIterator : public std::iterator<std::bidirectional_iterator_tag, T>{
    Node<T>* current;

public:
    ConstIterator(Node<T>* current);

    ConstIterator& operator++(); //prefix ++ operator (i.e. ++iter)
    ConstIterator operator++(int); //postfix ++ operator (i.e. iter++)
    ConstIterator& operator--(); //prefix
    ConstIterator operator--(int); //postfix
    Node<T>* operator&();
    const T& operator*();

    template <typename U>
    friend bool operator==(ConstIterator<U> left, ConstIterator<U> right);
    template <typename U>
    friend bool operator!=(ConstIterator<U> left, ConstIterator<U> right);


};


#include "ConstIterator.cpp"
#endif //CONSTITERATOR_H
