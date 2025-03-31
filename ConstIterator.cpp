//
// Created by matma on 3/22/2025.
//

#ifndef CONSTITERATOR_CPP
#define CONSTITERATOR_CPP

#include "ConstIterator.h"


template<typename T>
ConstIterator<T>::ConstIterator(Node<T> *current) {
    this->current = current;
}

template<typename T>
ConstIterator<T> & ConstIterator<T>::operator++() {
    this->current = current->next;
    return *this;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator++(int) {
    ConstIterator<T> temp = *this;
    this->current = current->next;
    return *this;
}

template<typename T>
ConstIterator<T>& ConstIterator<T>::operator--() {
    this->current = current->previous;
    return *this;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator--(int) {
    ConstIterator<T> temp = *this;
    this->current = current->previous;
    return *this;

}

template <typename U>
bool operator==(ConstIterator<U> left, ConstIterator<U> right) {
    return left.current == right.current;
}

template <typename U>
bool operator!=(ConstIterator<U> left, ConstIterator<U> right) {
    return left.current != right.current;
}

template<typename T>
Node<T>* ConstIterator<T>::operator&() {
    return this->current;
}

template<typename T>
const T& ConstIterator<T>::operator*() {
    return this->current->data;
}


#endif
