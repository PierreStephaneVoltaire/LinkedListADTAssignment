#include<iostream>
#include"MySLinkedList.h"
#include"MyExceptions.h"
#include "string"
using namespace std;

// implementation
template <typename E>
MySLinkedList<E>::MySLinkedList()
	: head(NULL), tail(NULL) {

}
template <typename E>
bool MySLinkedList<E>::empty() const
{
	return head == NULL;
}

template <typename E>
const E& MySLinkedList<E>::front() const
{
	return head->elem;
}
template <typename E>
const E& MySLinkedList<E>::last() const
{
	return tail->elem;
}

template <typename E>
MySLinkedList<E>::~MySLinkedList()
{
	while (!empty()) removeFront();
}

template <typename E>
void MySLinkedList<E>::addFront(const E& e) {
	SNode<E>* v = new SNode<E>;
	v->elem = e;
	v->next = NULL;
	if (empty()) {
		tail = v;
	}
	if (!empty()) {
		v->next = head;
		tail = head;
	}
	head = v;
}
template <typename E>
void MySLinkedList<E>::addLast(const E& e) {
	SNode<E>* v = new SNode<E>;

	if (empty()) {
		head = NULL; tail = head;
	}


	v->elem = e;
	v->next = NULL;
	if (empty()) {
		head = v;
		tail = head;
	}
	else {
		tail->next = v;
		tail = v;
		tail->next = NULL;
	}

}

template <typename E>
void MySLinkedList<E>::removeFront() {
	if (empty()) { throw new LinkedException("it's empty"); }
	if (head != tail) {
		SNode<E>* old = head;
		head = old->next;
		delete old;
	}
	else { tail = NULL; head = NULL; }
}
template <typename E>
void MySLinkedList<E>::removeLast() {
	if (empty()) { throw new LinkedException("it's empty"); }
	SNode<E>* old = new SNode<E>;
	SNode<E>* v = new SNode<E>;
	v = head;
	while (v->next) {
		if (v->next) {
			tail = v;
		}
		else { old = tail; }
		v = v->next;
	}
	tail->next = NULL;
	delete old;
}
template <typename E>
void MySLinkedList<E>::print() {
	SNode<E>* v = new SNode<E>;
	v = head;
	int i = 1;
	while (v->next) {
		cout << i << ")" << v->elem << endl;
		v = v->next;
		i++;
	}
}
void use_LinkedList() {
	MySLinkedList<int> a;
	for (int i = 0; i < 51; i++) {
		int num = rand() % 100 + 1;
		a.addFront(num);
	}

	a.print();

	MySLinkedList<string> b;
	for (int i = 0; i < 101; i++) {
		string c = "";
		c = "customer " + to_string(i + 1);
		b.addLast(c);
	}
	b.print();
}


int main() {

	use_LinkedList();

	system("pause");
}
