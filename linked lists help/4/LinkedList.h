#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList {
  Node<T>* head;
  Node<T>* tail;  
  Node<T>* find(T val) const;
  
public:
  LinkedList() : head(nullptr), tail(nullptr) {}
  
  void print(std::ostream& out=std::cout) const;
  
  bool hasValue(T val) const { return find(val) != nullptr; }
  
  // insert
  void insertHead(T val);
  void insertTail(T val);

};

template <typename T>
Node<T>* LinkedList<T>::find(T val) const {
  Node<T>* cur = head;
  while (cur != nullptr && cur->data != val) {
    cur = cur->next;
  }
  return cur;
}

template <typename T>
void LinkedList<T>::insertHead(T val) {
  Node<T>* newNode = new Node<T>(val);
  if (head == nullptr) { // empty list
    head = newNode;
    tail = newNode;
  }
  else { // existing node at head
    newNode->next = head;
    head = newNode;
  }
}

template <typename T>
void LinkedList<T>::insertTail(T val) {
  Node<T>* newNode = new Node<T>(val);
  if (head == nullptr) { // empty list
    head = newNode;
    tail = newNode;
  }
  else { // existing node at head
    tail->next = newNode;
    tail = newNode;
  }
}

// print function
template <class T>
void LinkedList<T>::print(std::ostream& out) const
{
	Node<T>* current=head;
	while(current!=nullptr)
	{
		out<<current->data<<" ";
		current=current->next;
	}
}

// overload the output operator
template <class T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T> l)
{
	l.print(out);
	return out;
}

#endif