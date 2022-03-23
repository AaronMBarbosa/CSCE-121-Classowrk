#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////
//                         class template definition                        //
//////////////////////////////////////////////////////////////////////////////

template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    DoublyLinkedList(T);
    DoublyLinkedList(const DoublyLinkedList<T>&);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);
    ~DoublyLinkedList();
     unsigned int size() const { return sz; }
    T& front();
    const T& front() const;
     T& back();
    const T& back() const;
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    void erase(unsigned int);
    void insert(T data, unsigned int idx);
    void clear();
    Node<T>* get_head() const {return head;}
    std::string to_str() const;
    // breaks encapsulation... gives operator== access to private data... not great approach, but makes the homework easier for you since we haven't talked about iterators .
    //template<typename U> friend bool operator==(DoublyLinkedList<U> const&, DoublyLinkedList<U> const&);
private:
    // do not change ordering.
    Node<T> *head;
    Node<T> *tail;
    unsigned int sz;
};

//////////////////////////////////////////////////////////////////////////////
//                       helper function declarations                       //
//////////////////////////////////////////////////////////////////////////////
template<typename T> std::ostream& operator<<(std::ostream &, DoublyLinkedList<T> const&);

template<typename T> bool operator==(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

template<typename T> bool operator!=(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

//////////////////////////////////////////////////////////////////////////////
//                     member template function definitions                 //
//////////////////////////////////////////////////////////////////////////////

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
    {
    	head = nullptr;
    	tail = nullptr;
    	sz = 0;
    }
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(T data)
    {
    	head = nullptr;
    	tail = nullptr;
    	sz = 0;

    	Node<T> *pointer = new Node<T>(data);
    	//pointer->data=data;
    	pointer->next = nullptr;
    	pointer->prev = nullptr;
    	head = pointer;
    	tail = pointer;
    	sz++;
    }

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& org)
{
	head = nullptr;
	tail = nullptr;
	sz = 0;
	if(org.head != nullptr)
	{
		Node<T>* orgL = org.head;
		Node<T>* newL = new Node<T>(orgL->data);
		newL->prev = nullptr;;
		newL->next = nullptr;
		head = newL;
		tail = newL;
		sz++;
		orgL = orgL->next;
		while(sz != org.sz)
		{
			T dat = orgL->data;
			push_back(dat);
			orgL = orgL->next;

		}
	}
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& org)
{
	if(this->head != nullptr)
	{
		clear();
	}
	if(this != &org)
	{
		head = nullptr;
		tail = nullptr;
		sz = 0;
		if(org.head != nullptr)
		{
			Node<T>* orgL = org.head;
			Node<T>* newL = new Node<T>(orgL->data);
			newL->prev = nullptr;;
			newL->next = nullptr;
			head = newL;
			tail = newL;
			sz++;
			orgL = orgL->next;
			while(sz != org.sz)
			{
				T dat = orgL->data;
				push_back(dat);
				orgL = orgL->next;

			}
		}
	}
	return *this;
}
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
    {
    	clear();
    }

template<typename T>
T& DoublyLinkedList<T>::front()
    {
		return head->data;
    }
template<typename T>
const T& DoublyLinkedList<T>::front() const
    {
    	const Node<T> *pointer = head;
    	return pointer->data;
    }
template<typename T>
T& DoublyLinkedList<T>::back()
    {
		return tail->data;
    }
template<typename T>
const T& DoublyLinkedList<T>::back() const
    {
    	const Node<T> *pointer = tail;
    	return pointer->data;
    }
template<typename T>
void DoublyLinkedList<T>::push_back(T data)
    {
    	Node<T> *pointer = new Node<T>(data);
    	if (sz == 0)
    	{
    		pointer->next = nullptr;
    		pointer->prev = nullptr;
    		head = pointer;
    		tail = pointer;
    		sz++;
    	}
    	else
    	{
    		Node<T> *lstnode = tail;
    		lstnode->next=pointer;
    		pointer->next = nullptr;
    		pointer->prev = lstnode;
    		tail = pointer;
    		sz++;
    	}

    }
template<typename T>
void DoublyLinkedList<T>::push_front(T data)
    {
    	Node<T> *pointer = new Node<T>(data);
    	if (sz == 0)
    	{
    		pointer->next = nullptr;
    		pointer->prev = nullptr;
    		head = pointer;
			
			
    		tail = pointer;
    		sz++;
    	} else
    	{
    		sz++;
    		Node<T> *first_node = head;
    		head = pointer;
    		pointer->prev = nullptr;
    		pointer->next = first_node;
    		first_node->prev = pointer;
    	}

    }
template<typename T>

void DoublyLinkedList<T>::pop_back()
{
	if (sz == 1)
	{
		head = nullptr;
		tail = nullptr;
		sz--;
	}
	else
	{
		
		
		Node<T> *lstnode = tail;
		tail = lstnode->prev;
		delete lstnode;
		lstnode = nullptr;
		tail->next = nullptr;
		sz--;
	}

}
template<typename T>

void DoublyLinkedList<T>::pop_front()
{
	
	
	if (sz == 1)
	{
		head = nullptr;
		tail = nullptr;
		sz--;
	}
	else
	{
		Node<T> *first_node = head;
		head = first_node->next;
		delete first_node;
		first_node = nullptr;
		head->prev=nullptr;
		sz--;
	}

}
template<typename T>

void DoublyLinkedList<T>::erase(unsigned int i)

{
	if(sz == 1 || i == sz-1)
	{
		pop_back();
	}
	else if (i == 0)
	{
		
		
		pop_front();
	}
	else
	{
		Node<T>* current=head;
		unsigned int j = 0;
		while(j < i)
		{
			current = current->next;
			j++;
		}
		Node<T>* prvnode=current->prev;
		Node<T>* nxtnode=current->next;
		
		prvnode->next = nxtnode;
		
		
		nxtnode->prev = prvnode;
		
		

		delete current;
		current = nullptr;
		sz--;
	}
}
template<typename T>
void DoublyLinkedList<T>::insert(T data, unsigned int idx)
{
	if(sz == 0 || idx==sz)
	{
		push_back(data);
		
	}
	
	else if (idx == 0)
	{
		push_front(data);
		
	}
	
	else if(idx < sz)
	{
		
		Node<T>* current=head;
		unsigned int k = 0;
		
		while(k < idx-1)
		{
			current = current->next;
			k++;
		}
		Node<T> *newnode1 = new Node<T>(data);
		Node<T>* nxtnode=current->next;
		
		current->next = newnode1;
		
		nxtnode->prev = newnode1;
		
		
		newnode1->prev=current;
		newnode1->next=nxtnode;
		sz++;
	}
}
template<typename T>
void DoublyLinkedList<T>::clear()
    {
    	Node<T>* delNode = nullptr;
    	while(head)
			
    	{
    		delNode = head;
			
    		head=head->next;
			
    		delete delNode;
			
    		delNode = nullptr;
    	}
		
    	tail = nullptr;
		
    	head = nullptr;
    	sz = 0;
    }


template<typename T>
std::string DoublyLinkedList<T>::to_str() const
{
    std::stringstream os;
    const Node<T> *curr = head;
    os << std::endl << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    os << "head: " << head << std::endl;
    os << "tail: " << tail << std::endl;
    os << "  sz: " << sz << std::endl;
    os << std::setw(16) << "node" << std::setw(16) << "node.prev" << std::setw(16) << "node.data" <<  std::setw(16) << "node.next" << std::endl;
    while (curr) {
        os << std::setw(16) << curr;
        os << std::setw(16) << curr->prev;
        os << std::setw(16) << curr->data;
        os << std::setw(16) << curr->next;
        os << std::endl;
        curr = curr->next;
    }
    os << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    return os.str();
}

//////////////////////////////////////////////////////////////////////////////
//                     helper template function definitions                 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
bool operator==(DoublyLinkedList<T> const& lhs, DoublyLinkedList<T> const& rhs)
{
	if(lhs.size() != rhs.size())
	{
		return false;
	}
	// getting you started on this once... definition for this overloaded operator will go here.
	Node<T>* ist1 = lhs.get_head();
	Node<T>* ist2 = rhs.get_head();
	while(ist1 != nullptr)
	{
		if(ist1->data != ist2->data)
			
		{
			return false;
		}
		else
		{
			ist1 = ist1->next;
			
			ist2 = ist2->next;
			
		}
	}
	return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T> const& rhs)
{
    os << rhs.to_str();
    return os;
}

#endif