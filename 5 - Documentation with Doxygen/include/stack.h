/**
* @file stack.h
* @author Sebastian Strindlund <sest1601@student.miun.se>
* @version 1.0
*/




#ifndef _STACK_H_
#define _STACK_H_

#include <stdexcept>
#include <algorithm>






/**
* @class Node
* @brief class for holding pointer & data to next object in stack.
* @details Contains a pointer and data of Template type.
*/

template<typename T>
class Node
{
public:
	Node<T> *next;
	T data;

/**
* @brief Constructor that initializes Node data.
*
* @param n pointer to next node
* @param pData (Template) data for a node.
* @code Node(Node *n, T pData) : next(n), data(pData) {} @endcode
*/

	Node (Node *n, T pData) : next(n), data(pData) {}
};


/**
* @class Stack
* @brief This class is a linked-list stack.
* @details Contains pointer to top of stack and a variable for the size of stack.
*/

template<typename T>
class Stack
{
private:
	Node<T> *top;
	unsigned int sizeofstack = 0;
public:

	/**
	* @brief Constructor initializes the stack.
	*
	* @param top initializes pointer to point at top (0).
	* @param sizeofstack initializes stack to size (0).
	* @code Stack():top(0), sizeofstack(0){}; @endcode
	*/
	Stack():top(0), sizeofstack(0){};

	/**
	* @brief Destructor deallocates memory.
	* ##### Example code
	* @code aStack.push(randomData) @endcode
	*/
	~Stack();

	/**
	* @brief Method for pushing object to stack (increases sizeofstack and redirects pointer to new top)
	* @param pData template value
	* @code push(const T& pData) noexcept; @endcode
	*
	* ##### Example code
	* @code aStack.push(randomData); @endcode
	*/
	void push(const T& pData) noexcept;

	/**
	* @brief Method for to pop (remove) the top object from stack.
	* ##### Example code
	* @code aStack.pop(); @endcode
	* @return data from node
	*/
	T pop();

	/**
	* @brief Method for checking if stack is empty
	* ##### Example code
	* @code aStack.empty(); @endcode
	* @return True if empty, false if not.
	*/
	bool empty() const noexcept;

	/**
	* @brief Method for getting size of stack
	* ##### Example code
	* @code aStack.size(); @endcode
	* @return size of stack
	*/
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
