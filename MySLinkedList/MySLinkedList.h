#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"MyExceptions.h"
using namespace std;
// define the node
template <typename E>
class SNode {					// singly linked list node
private:
	E elem;					// linked list element value
	SNode<E>* next;


	template<class E> friend class MySLinkedList;

};
// interface
template <typename E>
class MySLinkedList {				// a singly linked list
public:
	MySLinkedList();				// empty list constructor
	~MySLinkedList();				// destructor
	bool empty() const;				// is list empty?
	const E& front() const;
	const E& last() const;
	void addFront(const E& e);
	void addLast(const E& e);
	void removeFront();
	void removeLast();
	void print();
	// remove front item list
private:
	SNode<E>* head;
	SNode<E>*tail;
};



#endif
