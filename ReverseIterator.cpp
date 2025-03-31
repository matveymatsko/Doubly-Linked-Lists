//
// Created by matma on 3/22/2025.
//
#ifndef REVERSE_ITERATOR_H
#define REVERSE_ITERATOR_H

#include "ReverseIterator.h"


template<typename T>
ReverseIterator<T>::ReverseIterator(Node<T> *current) {
    this->current = current;
}

template<typename T>
ReverseIterator<T>& ReverseIterator<T>::operator++() {
    this->current = current->previous;
    return *this;
}

template<typename T>
ReverseIterator<T> ReverseIterator<T>::operator++(int) {
    ReverseIterator<T> temp = *this;
    this->current = current->previous;
    return *this;
}

template<typename T>
ReverseIterator<T>& ReverseIterator<T>::operator--() {
    this->current = current->next;
    return *this;
}

template<typename T>
ReverseIterator<T> ReverseIterator<T>::operator--(int) {
    ReverseIterator<T> temp = *this;
    this->current = current->next;
    return *this;
}

template <typename U>
bool operator==(ReverseIterator<U> left, ReverseIterator<U> right) {
    return left.current == right.current;
}

template <typename U>
bool operator!=(ReverseIterator<U> left, ReverseIterator<U> right) {
    return left.current != right.current;
}

template<typename T>
Node<T>* ReverseIterator<T>::operator&() {
    return this->current;
}

template<typename T>
T& ReverseIterator<T>::operator*() {
    return this->current->data;
}

#endif
