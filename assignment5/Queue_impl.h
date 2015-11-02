/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  1, 2015
 * Last Modified:     November  1, 2015
 * Assignment number: 5 Array / Linked List implementation (Circular Queue)
 * Filename:          Queue_impl.h
 * 
 ********************************************************************************/
#ifndef QUEUE_IMPL_H
#define QUEUE_IMPL_H
#include "LinkedList.h"

/********************************************************************************
 * Queue ( const Queue& q);
 * 	Purpose: 
 * 		copy constructor for Queue class
 * 		copies size, maximum size, and all elements from <q> to this queue
 * 	
 * 	Entry: 
 * 		q: the queue to be copied
 * 	
 * 	Exit: 
 * 		constructs a copy of q
 * 	
 ********************************************************************************/
template < typename T >
Queue<T>::Queue ( const Queue& q):
	list(q.list), maxSize(q.maxSize), size(q.size)
{
}

/********************************************************************************
 * Queue ();
 * 	Purpose: 
 * 		default constructor for queue
 * 		creates an empty queue with maximum size DEFAULT_QUEUE_SIZE
 * 	
 * 	Entry: 
 * 		no parameters
 * 	
 * 	Exit: 
 * 		constructs an empty queue
 * 	
 ********************************************************************************/
template < typename T >
Queue<T>::Queue ():
	Queue(DEFAULT_QUEUE_SIZE )
{
}

/********************************************************************************
 * Queue (int size);
 * 	Purpose: 
 * 		create a queue with the specified maximum size
 * 	
 * 	Entry: 
 * 		size: the maximum size of the new queue.
 * 	
 * 	Exit: 
 * 		constructs an empty queue with the requested maximum size
 * 	
 ********************************************************************************/
template < typename T >
Queue<T>::Queue (int size):
	maxSize(size), size(0)
{
}

/********************************************************************************
 * ~Queue ();
 * 	Purpose: 
 * 		destructor for queue class
 * 		doesn't need to do anything
 * 		(list destructor called implicitly)
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		nothing
 * 	
 ********************************************************************************/
template < typename T >
Queue<T>::~Queue ()
{
	//list handles its own destructor
}

/********************************************************************************
 * void Enqueue ( const T& elem);
 * 	Purpose: 
 * 		Add an element onto the queue
 * 		(puts it at the back)
 * 	
 * 	Entry: 
 * 		elem: the element to be put on the end of the queue
 * 	
 * 	Exit: 
 * 		returns nothing
 * 		but can throw overflow exception if queue is already full
 * 	
 ********************************************************************************/
template < typename T >
void Queue<T>::Enqueue ( const T& elem)
{
	if(isFull())
		throw Queue::_Overflow;
	list.Prepend(elem);
	size++;
}

/********************************************************************************
 * T Dequeue ();
 * 	Purpose: 
 * 		Pop the element at the front of the queue off and return a copy of it
 * 	
 * 	Entry: 
 * 	
 * 	Exit: 
 * 		Returns a copy of the element in the queue that was just popped off
 * 	
 ********************************************************************************/
template < typename T >
T Queue<T>::Dequeue ()
{
	if(isEmpty())
		throw Queue::_Underflow;
	size--;
	T result = list.Last().getContents();
	list.dropNode(&list.Last());
	return result;
}


/********************************************************************************
 * T& Front ();
 * 	Purpose: 
 * 		Get a mutable reference to the element at the front of the queue
 * 		(next to be removed)
 * 	
 * 	Entry: 
 * 		nothign
 * 	
 * 	Exit: 
 * 		returns a reference to the front element
 * 	
 ********************************************************************************/
template < typename T >
T& Queue<T>::Front ()
{
	if(isEmpty())
		throw Queue::_Underflow;
	return list.First().getContents();
}

/********************************************************************************
 * bool isEmpty() const;
 * 	Purpose: 
 * 		returns true if aliens are attacking earth
 * 		false if the queue is not empty
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		returns true if the queue is empty, false otherwise
 * 	
 ********************************************************************************/
template < typename T >
bool Queue<T>::isEmpty()  const
{
	return size==0;
}

/********************************************************************************
 * bool isFull () const;
 * 	Purpose: 
 * 		returns true if the queue is full
 * 		false otherwise
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		see Purpose section
 * 	
 ********************************************************************************/
template < typename T >
bool Queue<T>::isFull () const
{
	return size>=maxSize;
}

#endif

