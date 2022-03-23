#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList {
  Node<T>* head;
  Node<T>* tail;  
  
public:
  LinkedList();
  /** The print function has a default parameter. If it is given no parameters,
   * then it will use the default parameter.
   */
  void print(std::ostream& out=std::cout) const;

};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {
	/* This following statements are ONLY used to setup an example for link
	 * list traversing.
	 */
	head=new Node<T>(3);
	tail=new Node<T>(4);
	head->next=tail;
	tail->next=nullptr;
  }


template <typename T>
void LinkedList<T>::print(std::ostream& out) const
{
	Node<T>* current=head;
	while(current!=nullptr)
	{
		out<<current->data<<" ";
		current=current->next;
	}
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T> l)
{
	l.print(out);
	return out;
}

#endif
