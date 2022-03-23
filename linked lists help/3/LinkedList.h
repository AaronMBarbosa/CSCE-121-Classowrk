#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList {
  Node<T>* head;
  Node<T>* tail;  
  
public:
  LinkedList() : head(nullptr), tail(nullptr) {}
};

#endif