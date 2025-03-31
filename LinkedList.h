//
// Created by matma on 3/17/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"
#include "NodeIterator.h"
#include "ReverseIterator.h"
#include "ConstIterator.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head = nullptr, *tail = nullptr;
    int _size = 0;
    Node<T>* createNewNode(const T& data);

    void push_front(Node<T>* node);
    void push_back(Node<T>* node);


public:
    void addFirstNode(const T& data);

    ///Node iterator functions
    typedef NodeIterator<T> iterator;
    iterator begin();
    iterator end();

    ///Reverse iterator functions
    typedef ReverseIterator<T> reverse_iterator;
    reverse_iterator reverseBegin();
    reverse_iterator reverseEnd();

    ///Const iterator functions
    typedef ConstIterator<T>  const_iterator;
    const_iterator constBegin();
    const_iterator constEnd();

    void push_front(const T& data);
    void push_back(const T& data);
    void insert_before(const T& target, const T& data);
    void insert_after(const T& target, const T& data);
    Node<T>* find(const T& data);


    ///instead of remove(), use the following:
    void pop_back();
    void pop_front();

    bool empty() const;
    int size() const;
    void clear();

    ///for copy, overload the =
    Node<T>* operator=(const Node<T>& other);

    ///output function (overload <<)
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list);

    ///the += operator
    LinkedList<T>& operator+=(const T& data);

    ///front and back functions
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;


};


#include "LinkedList.cpp"
#endif //LINKEDLIST_H
