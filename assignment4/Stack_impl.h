/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 24, 2015
 * Last Modified:     October 24, 2015
 * Assignment number: 4 Stacks
 * Filename:          Stack_impl.h
 * 
 ********************************************************************************/
#ifndef STACK_IMPL_H
#define STACK_IMPL_H
#include "LinkedList.h"
#include "Iterator.h"
#include <iomanip>

/********************************************************************************
 * Stack ();
 * 	Purpose: 
 * 		Default constructor for stack class
 * 	
 * 	Entry: 
 * 		Nothing
 * 		(starts with empty stack supporting up to 10 elements)
 * 	
 * 	Exit: 
 * 		Constructed stack with ability to store 10 elements
 * 	
 ********************************************************************************/
template < typename T >
Stack<T>::Stack ():
	Stack(10)
{
}

/********************************************************************************
 * Stack (const Stack<T>& st);
 * 	Purpose: 
 * 		Copy constructor for stack class
 * 		Copies <st>
 * 		's
 * 		- maximum number of elements
 * 		- current number of elements
 * 		- every element in <st>
 * 	
 * 	Entry: 
 * 		const Stack<T>& st: the  stack to be copied from
 * 	
 * 	Exit: 
 * 		A new stack matching <st>
 * 	
 ********************************************************************************/
template < typename T >
Stack<T>::Stack (const Stack<T>& st):
	maxSize(st.maxSize),
	currSize(st.currSize)
{
	for(Iterator<T> it = elements.Begin(); it.isValid(); ++it)
		Push(*it); //real good
}

/********************************************************************************
 * Stack (int size);
 * 	Purpose: 
 * 		Construct a stack with <size> maximum elements
 * 		Starts with 0 elements
 * 	
 * 	Entry: 
 * 		size: the maximum number of elements the stack can contain
 * 	
 * 	Exit: 
 * 		Constructed stack with <size> max elements
 * 	
 ********************************************************************************/
template < typename T >
Stack<T>::Stack (int size):
	maxSize(size),
	currSize(0)
{
    
}

/********************************************************************************
 * ~Stack ();
 * 	Purpose: 
 * 		Destructor for Stack class
 * 		De-allocates every element in the stack using LinkedList::Purge()
 * 	
 * 	Entry: 
 * 		No parameters
 * 		operates on the Stack's linked list
 * 	
 * 	Exit: 
 * 		Destructed stack
 * 	
 ********************************************************************************/
template < typename T >
Stack<T>::~Stack ()
{
	elements.Purge();
}

/********************************************************************************
 * void Push (const T& element);
 * 	Purpose: 
 * 		Push an element onto the top of the stack.
 * 	
 * 	Entry: 
 * 		const T& element: the element to be pushed onto the stack
 * 	
 * 	Exit: 
 * 		Does not return anything
 * 		(can throw Overflow exception if stack is full)
 * 	
 ********************************************************************************/
template < typename T >
void Stack<T>::Push (const T& element)
{
	if(isFull())
		throw Stack<T>::_Overflow;
	currSize++;
	elements.Append(element);


}

/********************************************************************************
 * T Pop ();
 * 	Purpose: 
 * 		Remove the element on the top of the stack and return a copy of it
 * 	
 * 	Entry: 
 * 		Nothing (removes top element)
 * 	
 * 	Exit: 
 * 		Returns a copy of the top element
 * 		(can throw an Underflow exception if stack is empty when called)
 * 	
 ********************************************************************************/
template < typename T >
T Stack<T>::Pop ()
{
	if(isEmpty())
		throw Stack<T>::_Underflow;
	currSize--;
	Node<T>* node = &elements.Last();
	T res = node->getContents();
	elements.dropNode(node);
	return res;
}

/********************************************************************************
 * Peek()  T const;
 * 	Purpose: 
 * 		Return the element on the top of the stack without removing it
 * 	
 * 	Entry: 
 * 		Nothing
 * 	
 * 	Exit: 
 * 		Returns a reference to the top element on the stack
 * 	
 ********************************************************************************/
template < typename T >
const T& Stack<T>::Peek() const
{
	if(isEmpty())
		throw Stack::_Underflow;
	return elements.Last().getContents();
}

/********************************************************************************
 * Peek()  T const;
 * 	Purpose: 
 * 		Return the element on the top of the stack without removing it
 * 	
 * 	Entry: 
 * 		Nothing
 * 	
 * 	Exit: 
 * 		Returns a reference to the top element on the stack
 * 	
 ********************************************************************************/
template < typename T >
T Stack<T>::Peek() 
{
	if(isEmpty())
		throw Stack::_Underflow;
	return elements.Last().getContents();
}

/********************************************************************************
 * Size()  int const;
 * 	Purpose: 
 * 		Returns the current number of elements in the stack
 * 	
 * 	Entry: 
 * 		Nothing (relies on currSize being correct)
 * 	
 * 	Exit: 
 * 		Returns the number of elements in the stack
 * 	
 ********************************************************************************/
template < typename T >
int Stack<T>::Size() const
{
	return currSize;
}

/********************************************************************************
 * isEmpty()  bool const;
 * 	Purpose: 
 * 		Find out if the Stack is empty or not
 * 	
 * 	Entry: 
 * 		Nothing (relies on currSize)
 * 	
 * 	Exit: 
 * 		Returns true if stack is empty
 * 		False if it isn't
 * 	
 ********************************************************************************/
template < typename T >
bool Stack<T>::isEmpty()  const
{
	return !currSize;
}

/********************************************************************************
 * isFull()  bool const;
 * 	Purpose: 
 * 		Find out if the stack is full or not
 * 	
 * 	Entry: 
 * 		Nothing (relies on currSize)
 * 	
 * 	Exit: 
 * 		Returns true if stack is full
 * 		False if it isn't
 * 	
 ********************************************************************************/
template < typename T >
bool Stack<T>::isFull()  const
{
	return currSize==maxSize ;
}

template < typename T >
void Stack<T>::print(bool reverse, const char* indent) const
{
	std::cout << indent << "Current size: " << currSize << " | Max size: " << maxSize << std::endl;
	std::cout << indent;
	int lineNum=0;
	for(auto it = reverse ? elements.End() : elements.Begin(); 
			it.isValid(); (reverse?--it:++it), ++lineNum)
	{
		if ( lineNum >= 10 )
		{
			lineNum = 0;
			std::cout << std::endl << indent;
		}
		std::cout << "[" << std::setw(5) << std::left << *it << "] ";

	}
	if (isEmpty())
		std::cout << "<stack is empty>";
	std::cout << std::endl;
}

#endif

