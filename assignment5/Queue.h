/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  1, 2015
 * Last Modified:     November  1, 2015
 * Assignment number: 5 Array / Linked List implementation (Circular Queue)
 * Filename:          Queue.h
 * 
 * Class: Queue
 * 
 * Methods: 
 *      Queue ( const Queue& q):
 *         copy constructor
 * 
 *      Queue ():
 *         default constructor
 * 
 *      Queue (int size):
 *         constructor given max queue size
 * 
 *      ~Queue ():
 *         destructor
 * 
 *      void Enqueue ( const T& elem):
 *         Add an element to the end of the queue
 * 
 *      T Dequeue ():
 *         Remove the front element and return a copy of it
 * 
 *      T& Front ():
 *         Return a reference to the element at the front of the queue
 * 
 *      int Size () const:
 *         Return the number of items currently in the queue
 * 
 *		bool isEmpty() const:
 *         Find if the queue is empty or not
 * 
 *      bool isFull () const:
 *         Find if the queue is full
 * 
 * 
 ********************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

#define DEFAULT_QUEUE_SIZE 10

template < typename T >
class Queue
{
    private:
		LinkedList<T> list;
		int size;
		int maxSize;


    public:
        // copy constructor
        Queue ( const Queue& q);

        // default constructor (sets maximum size to DEFAULT_QUEUE_SIZE)
        Queue ();

		// constructor given maximum queue size
        Queue (int size);

		// destructor (list dtor gets called implicitly)
        ~Queue ();

        // add an element at the end of the queue
        void Enqueue ( const T& elem);

        // remove and return an element from the front of the queue
        T Dequeue ();

        // get a reference to the front element in the queue
        T& Front ();

        // get the size of the queue
        int Size () const { return size; }

        // find if the queue is empty
        bool isEmpty() const;

        // find if the queue is full
        bool isFull () const;

		// exceptions that can be thrown
		enum Error
		{
			_Overflow,
			_Underflow
		};

};
#include "Queue_impl.h"

#endif

