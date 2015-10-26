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
 * 		Copies <st>'s...
 * 		 - maximum number of elements
 * 		 - current number of elements
 * 		 - every element in <st>
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
	currSize(0)
{
	// iterate through <st>'s elements and push them onto this stack
	for(Iterator<T> it = st.elements.Begin(); it.isValid(); ++it)

		Push( *it ); // real good
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
	// Just clean up the stack elements
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
	//Throw an overflow exception if the stack is already full
	if(isFull())
		throw Stack<T>::_Overflow;

	//Increase the current size of the stack
	currSize++;

	// Append <element> onto the stack
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
	//If the stack is empty, throw an Underflow exception
	if(isEmpty())
		throw Stack<T>::_Underflow;

	//Decrease the stack size by 1
	currSize--;

	// Get a pointer to the last element in the list
	Node<T>* node = &elements.Last();

	// Store the contents of it
	T res = node->getContents();

	// Remove the last element from the list
	elements.dropNode(node);

	//return the stored contents from the last element
	return res;
}

/********************************************************************************
 * const T& Peek() const;
 * 	Purpose: 
 * 		Return the element on the top of the stack without removing it
 * 		(returns a const reference)
 * 	
 * 	Entry: 
 * 		Nothing
 * 	
 * 	Exit: 
 * 		Returns a const reference to the top element on the stack
 * 	
 ********************************************************************************/
template < typename T >
const T& Stack<T>::Peek() const
{
	//if the stack is empty, throw an underflow exception
	if(isEmpty())
		throw Stack::_Underflow;

	//return the value of the top element on the stack
	return elements.Last().getContents();
}

/********************************************************************************
 * T& Peek()  ;
 * 	Purpose: 
 * 		Return the element on the top of the stack without removing it
 * 		(returns a mutable reference to the element - this is the only way to modify
 *			elements from outside the Stack class)
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
	//if the stack is empty, throw an underflow exception
	if(isEmpty())
		throw Stack::_Underflow;

	//return the value of the top element on the stack
	return elements.Last().getContents();
}

/********************************************************************************
 * int Size() const;
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
 * bool isEmpty()  const;
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
 * bool isFull()  const;
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

/********************************************************************************
 * void print( bool reverse, const char* indent ) const
 * 	Purpose: 
 *		Helper function to print:
 *		 - Current stack size (number of active elements)
 *		 - Maximum stack size
 *		 - Elements on the stack
 *		With nice indentation
 *
 *		(this function was made purely for testing purposes)
 *
 * 	Entry: 
 *		bool reverse: If this parameter is true, the stack will be printed in 
 *			reverse (last element pushed on the stack gets printed first), Otherwise
 *			stack is printed from the first element pushed to the last.
 *		const char* indent: Gets prepended before every line of output (used for
 *			neat output formatting)
 * 
 * 	Exit: 
 *		Prints the current and maximum size of the stack.
 *		Then prints each element it contains in neat rows of up to 10 elements
 *		Columns of output will line up if elements are less than 5 characters wide
 *		when printed with cout
 *
 ********************************************************************************/
template < typename T >
void Stack<T>::print(bool reverse, const char* indent) const
{
	//print the current and maximum size
	std::cout << indent << "Current size: " << currSize << " | Max size: " << maxSize << std::endl;

	//print all the elements in the array in neatly formatted rows
	std::cout << indent;
	int lineNum=0;

	// if <reverse> is true, traverse the stack from the end to the beginning
	// otherwise, start at the beginning and iterate to the end
	for(auto it = reverse ? elements.End() : elements.Begin(); 
			it.isValid(); (reverse?--it:++it), ++lineNum)
	{
		// break rows into new lines after 10 elements
		if ( lineNum >= 10 )
		{
			lineNum = 0;
			std::cout << std::endl << indent;
		}

		//print each element with square brackets around it and consistent spacing
		std::cout << "[" << std::setw(5) << std::left << *it << "] ";

	}

	//if the stack is empty, say so.
	if (isEmpty())
		std::cout << "<stack is empty>";

	std::cout << std::endl;
}

#endif

