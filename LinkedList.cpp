//
// Created by matma on 3/17/2025.
//

#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "LinkedList.h"

///create new node function
template<typename T>
Node<T>* LinkedList<T>::createNewNode(const T& data) {
  return new Node<T>{data};
}

template<typename T>
void LinkedList<T>::addFirstNode(const T& data) {
  Node<T>* newNode = createNewNode(data);
  newNode->next = head;
  head = newNode;
  tail = newNode;

}



///push front
template<typename T>
void LinkedList<T>::push_front(const T& data) {
    if(empty())
      addFirstNode(data);
    else
      push_front(createNewNode(data));
    _size++;
}

template<typename T>
void LinkedList<T>::push_front(Node<T> *node) {
    node->next = head;
    head->previous = node;
    head = node;
}



///push back
template<typename T>
void LinkedList<T>::push_back(const T& data) {
  if(empty())
    addFirstNode(data);
  else
    push_back(createNewNode(data));
  _size++;
}

template<typename T>
void LinkedList<T>::push_back(Node<T>* node) {
  node->previous = tail;
  tail->next = node;
  tail = node;
}



///pop back and pop front
template<typename T>
void LinkedList<T>::pop_back() {
  if(empty())
    return;

  Node<T>* temp = tail;
  tail = tail->previous;
  tail->next = nullptr;

  delete temp;
  _size--;
}

template<typename T>
void LinkedList<T>::pop_front() {
  if(empty())
    return;

  Node<T>* temp = head;
  head = head->next;
  head->previous = nullptr;

  delete temp;
  _size--;
}



///insert before
template <typename T>
void LinkedList<T>::insert_before(const T& target, const T& data) {
  Node<T>* targetPointer = find(target);
  Node<T>* node = new Node<T>(data);

  if (targetPointer == nullptr)
    return;
  if (targetPointer == head) {
    push_front(data);
    return;
  }

  node->previous = targetPointer->previous;
  if (targetPointer->previous)
    targetPointer->previous->next = node;

  node->next = targetPointer;
  targetPointer->previous = node;

  if (targetPointer == head)
    head = node;

  _size++;
}

///insert after
template <typename T>
void LinkedList<T>::insert_after(const T& target, const T& data) {
  Node<T>* targetPointer = find(target);
  Node<T>* node = new Node<T>(data);

  if (targetPointer == nullptr)
    return;
  if (targetPointer->next == nullptr) {
    push_back(data);
    return;
  }

  node->next = targetPointer->next;
  if (targetPointer->next)
    targetPointer->next->previous = node;

  node->previous = targetPointer;
  targetPointer->next = node;

  if (targetPointer == tail)
    tail = node;

  _size++;
}


///find
template<typename T>
Node<T>* LinkedList<T>::find(const T& data) {
  Node<T>* current = head;
  while (current != nullptr) {
    if (current->data == data)
      return current;
    current = current->next;
  }
  return nullptr;
}


///empty
template<typename T>
bool LinkedList<T>::empty() const {
  return head == nullptr;
}



///size
template<typename T>
int LinkedList<T>::size() const {
  return _size;
}



///clear
template<typename T>
void LinkedList<T>::clear() {
  while (head != nullptr && head->next != nullptr)
  {
    head = head->next;
    delete head->previous;
  }
  head = nullptr;
  tail = nullptr;
  _size = 0;
}



///copy
//OVERLOAD THE = OPERATOR
template<typename T>
Node<T>* LinkedList<T>::operator=(const Node<T>& other) {

  Node<T>* temp = other.head;
  while (temp != nullptr) {
    push_front(temp->data);
    temp = temp->next;
  }

  return temp;
}



template <typename T>
LinkedList<T>& LinkedList<T>::operator+=(const T &data) {
  push_back(data);
  return *this;
}



///output operator
template<typename U>
std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list) {
  Node<U>* current = list.head;

  while (current != nullptr) {
    os << current->data;
    if (current->next != nullptr) {
      os << " ";
    }
    current = current->next;
  }
  return os;
}



///front
template<typename T>
T& LinkedList<T>::front() {
  return head->data;
}

template<typename T>
const T& LinkedList<T>::front() const {
  return head->data;
}



///back
template<typename T>
T& LinkedList<T>::back() {
  return tail->data;
}

template<typename T>
const T& LinkedList<T>::back() const {
  return tail->data;
}



///node iterator functions
template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin() { ///WE NEED THE TYPENAME CAUSE IT IS AN ALIAS OF THE CLASS. IT'S NOT IT'S OWN CLASS!
  return NodeIterator<T>(head);
}

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::end() {
  return NodeIterator<T>(nullptr); //not tail because it's before the nullptr
}



///reverse iterator functions
template <typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::reverseBegin() {
  return ReverseIterator<T>(tail);
}

template <typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::reverseEnd() {
  return ReverseIterator<T>(nullptr);
}



///const iterator functions
template <typename T>
typename LinkedList<T>::const_iterator LinkedList<T>::constBegin() {
  return ConstIterator<T>(head);
}

template <typename T>
typename LinkedList<T>::const_iterator LinkedList<T>::constEnd() {
  return ConstIterator<T>(nullptr);
}

#endif
