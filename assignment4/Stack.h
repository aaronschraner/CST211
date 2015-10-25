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
        //TODO: brief description
        Stack ();

        //TODO: brief description
        Stack (const Stack<T>& st);

        //TODO: brief description
        Stack (int size);

        //TODO: brief description
        ~Stack ();

        //TODO: brief description
        void Push (const T& element);

        //TODO: brief description
        T Pop ();

        //TODO: brief description
        T Peek()  ;
        const T& Peek() const;

        //TODO: brief description
        int Size()  const;

        //TODO: brief description
        bool isEmpty()  const;

        //TODO: brief description
        bool isFull()  const;

		void print(bool reverse=0, const char* indent="") const ; // just for debugging

		enum Error
		{
			_Overflow,
			_Underflow
		};

};

#include "Stack_impl.h"

#endif

