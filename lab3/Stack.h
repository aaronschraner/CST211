/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 24, 2015
 * Last Modified:     October 24, 2015
 * Assignment number: 4 Stacks
 * Filename:          Stack.h
 * 
 * Class: Stack
 * 
 * Methods: 
 *      Stack ():
 *         Default constructor (sets size to 10)
 * 
 *      Stack (const Stack<T>& st):
 *         Copy constructor
 * 
 *      Stack (int size):
 *         Constructor given maximum number of stack elements
 * 
 *      ~Stack ():
 *         Destructor (deallocates everything on the Stack)
 * 
 *      void Push (const T& element):
 *         Push an element onto the top of the stacck
 * 
 *     T Pop ():
 *         Remove and return the top element from the stack
 * 
 *     Peek()  T const:
 *         Return the top element on the stack but don'
 * 
 *     Size()  int const:
 *         Return the number of elements on the stack
 * 
 *     isEmpty()  bool const:
 *         Returns true if the stack is empty
 * 
 *     isFull()  bool const:
 *         Returns true if the stack is full
 *
 *      void print(bool reverse, const char* indent):
 *		   Print the maximum and current size of the stack with all its elements
 *	Enums:
 *		enum Error:
 *			Error type to indicate stack overflow/underflow errors
 * 
 * 
 ********************************************************************************/
#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template < typename  T>
class Stack
{
    private:
		LinkedList<T> elements;
		int maxSize;
		int currSize;

    public:
		// default constructor
        Stack ();

        // copy constructor
        Stack (const Stack<T>& st);

        // constructor given maximum number of elements
        Stack (int size);

        // destructor
        ~Stack ();

        // Push an element onto the stack
        void Push (const T& element);

        // Pop an element off the stack and return it
        T Pop ();

        // Return the top element on the stack without removing it
        T Peek()  ;
        const T& Peek() const;

        // get the current size (number of elements on the stack)
        int Size()  const;

        // Find out if the stack is empty
        bool isEmpty()  const;

        // Find out if the stack is full
        bool isFull()  const;

		// print the contents of the stack (just for debugging purposes)
		void print(bool reverse=0, const char* indent="") const ; 

		// Error type for overflow and underflow exceptions
		enum Error
		{
			_Overflow,
			_Underflow
		};

		// assignment operator
		Stack<T>& operator=(const Stack<T>& stack);

		Iterator<T> startIterator() { return elements.Begin(); }
		const Iterator<T> startIterator() const { return elements.Begin(); }

};

#include "Stack_impl.h"

#endif

