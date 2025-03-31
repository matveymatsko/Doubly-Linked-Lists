//
// Created by matma on 3/19/2025.
//

#ifndef NODEITERATOR_CPP
#define NODEITERATOR_CPP

#include "NodeIterator.h"

template<typename T>
NodeIterator<T>::NodeIterator(Node<T> *current) {
    this->current = current;
}

template<typename T>
NodeIterator<T> & NodeIterator<T>::operator++() {
    this->current = current->next;
    return *this;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator++(int) {
    NodeIterator<T> temp = *this;
    this->current = current->next;
    return *this;
}

template<typename T>
NodeIterator<T>& NodeIterator<T>::operator--() {
    this->current = current->previous;
    return *this;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator--(int) {
    NodeIterator<T> temp = *this;
    this->current = current->previous;
    return *this;

}

template <typename U>
bool operator==(NodeIterator<U> left, NodeIterator<U> right) {
    return left.current == right.current;
}

template <typename U>
bool operator!=(NodeIterator<U> left, NodeIterator<U> right) {
    return left.current != right.current;
}

template<typename T>
Node<T>* NodeIterator<T>::operator&() {
    return this->current;
}

template<typename T>
T& NodeIterator<T>::operator*() {
    return this->current->data;
}



#endif