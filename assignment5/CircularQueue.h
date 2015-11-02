/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  1, 2015
 * Last Modified:     November  1, 2015
 * Assignment number: 5 Array / Linked List implementation (Circular Queue)
 * Filename:          CircularQueue.h
 * 
 * Class: CircularQueue
 * 
 * Methods: 
 *      CircularQueue ( const CircularQueue& cq):
 *         Copy constructor
 * 
 *      CircularQueue ():
 *         Default constructor
 * 
 *      CircularQueue (int size):
 *         Constructor given size of queue
 * 
 *      void Enqueue  (const T& item):
 *         Puts the data item at the end (tail) of the queue
 * 
 *      T Dequeue ():
 *         Removes and returns the data item at the front of the queue
 * 
 *      T& Front ():
 *         Returns a reference to the data at the front of the queue. This will allow the consumer to modify the element at the front of the queue.
 * 
 *      int Size ():
 *         Returns the number of items currently in the queue.
 * 
 *      bool isEmpty ():
 *         Returns true if the stack is empty.
 *
 *      bool isFull ():
 *         Returns true if the queue is full.
 * 
 * 
 ********************************************************************************/
#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include "Array.h"

#define DEFAULT_CQ_SIZE 10

template < typename T >
class CircularQueue
{
	private:
		int head, tail, size;
		Array<T> array;

	public:
		// copy constructor
		CircularQueue ( const CircularQueue& cq);

		// default constructor
		CircularQueue ();

		// constructor given maximum queue size
		CircularQueue (int size);

		// add an element to the end of the queue
		void Enqueue (const T& item);

		// pop an element off the queue and return a copy of it
		T Dequeue ();

		// get a mutable reference to the front element in the queue
		T& Front ();

		// get the number of active elements in the queue
		int Size ();

		// find if the queue is empty
		bool isEmpty () const;

		// find if the queue is full
		bool isFull () const;

		// destructor
		~CircularQueue();

		// exceptions that can be thrown 
		enum Error
		{
			_Overflow,
			_Underflow
		};

};
#include "CircularQueue_impl.h"

#endif

