#ifndef _STACK_H_
#define _STACK_H_

#include <stdexcept>
#include <algorithm>

template<typename T>
class Node
{
public:
	Node<T> *next;
	T data;
	Node (Node *n, T pData) : next(n), data(pData) {}
};

template<typename T>
class Stack
{
private:
	Node<T> *top;
	unsigned int sizeofstack = 0;
public:
	Stack():top(0), sizeofstack(0){};
	~Stack();

	void push(const T& pData) noexcept;
	T pop();
	bool empty() const noexcept;
	unsigned int size() const noexcept;
};



template<typename T>
Stack<T>::~Stack() {
	while(!empty())
	{
		Node<T> *tmp= top;
		top = top->next;
		delete tmp;
		sizeofstack--;
	}
}

template<typename T>
bool Stack<T>::empty() const noexcept {
	//return top == 0;
	return sizeofstack == 0;
}

template<typename T>
unsigned int Stack<T>::size() const noexcept {
	//return SIZE;
	return sizeofstack;
}


template<typename T>
T Stack<T>::pop() {
	if (empty()) {
		throw std::range_error{"Can't pop empty stack"};
	} else {
		Node<T> *p = top;
		T data = p->data;
		top = top->next;
		delete p;
		sizeofstack--;
		return data;
	}
}


template<typename T>
void Stack<T>::push(const T& pData) noexcept {
	top = new Node<T>(top, pData);
	sizeofstack++;

}


#endif
