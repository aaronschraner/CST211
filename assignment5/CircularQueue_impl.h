/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  1, 2015
 * Last Modified:     November  1, 2015
 * Assignment number: 5 Array / Linked List implementation (Circular Queue)
 * Filename:          CircularQueue_impl.h
 * 
 ********************************************************************************/
#ifndef CIRCULARQUEUE_IMPL_H
#define CIRCULARQUEUE_IMPL_H
#include "Array.h"

/********************************************************************************
 * CircularQueue ( const CircularQueue& cq);
 * 	Purpose: 
 * 		Copy constructor for CircularQueue class
 * 		Constructs a copy of cq
 * 	
 * 	Entry: 
 * 		const CircularQueue& cq: the Circular Queue to be copied
 * 	
 * 	Exit: 
 * 		Constructs the circular queue so each element matches the one in <cq>
 * 	
 ********************************************************************************/
template < typename T >
CircularQueue<T>::CircularQueue ( const CircularQueue& cq):
	CircularQueue(cq.size())
{
	//copy all of the elements from cq to the new queue
	for(int i=0; i<size; i++)
		Enqueue(cq.array[i]);
}

/********************************************************************************
 * CircularQueue ();
 * 	Purpose: 
 * 		Default constructor for CQ class
 * 		sets size of queue to <DEFAULT_CQ_SIZE>
 * 		(from now on anywhere I write "CQ" in all caps I mean the Circular
 * 		Queue class)
 * 	
 * 	Entry: 
 * 		Nothing (relies on DEFAULT_CQ_SIZE and calls the constructor
 * 		that takes size as a parameter)
 * 	
 * 	Exit: 
 * 		Returns an empty circular queue with a size of DEFAULT_CQ_SIZE
 * 	
 ********************************************************************************/
template < typename T >
CircularQueue<T>::CircularQueue ():
	CircularQueue(DEFAULT_CQ_SIZE)
{
	//construct a queue with the default size
	// (DEFAULT_CQ_SIZE defined in CircularQueue.h)
}

/********************************************************************************
 * CircularQueue (int size);
 * 	Purpose: 
 * 		Constructs a circular queue with the requested size
 * 		Sets head and tail to -1 to indicate that queue is empty
 * 		Sets this->size to size and allocates a new Array<T> of that size
 * 		Also sets array's start_index to 0
 * 	
 * 	Entry: 
 * 		int size: the maximum size of the circular queue being created
 * 	
 * 	Exit: 
 * 		Constructs the Circular Queue and exits
 * 	
 ********************************************************************************/
template < typename T >
CircularQueue<T>::CircularQueue (int size):
	size(size), head(-1), tail(-1), array(size, 0)
{
	//set this->size to size, head and tail to -1, and construct the array
}

/********************************************************************************
 * void Enqueue  (const T& item);
 * 	Purpose: 
 * 		Put an item on the end of the queue
 * 	
 * 	Entry: 
 * 		item: the element to be added
 * 	
 * 	Exit: 
 * 		returns nothing
 * 		(adds <item> to the end/tail of the queue)
 * 		(can throw exception if queue is already full)
 * 	
 ********************************************************************************/
template < typename T >
void CircularQueue<T>::Enqueue (const T& item)
{
	//if the queue is already full, throw an exception
	if (isFull())
		throw CircularQueue::_Overflow;

	//store if it is currently empty
	bool wasEmpty = isEmpty();

	//move the tail up one
	tail = (tail + 1) % size;

	//if this is the first element in the queue, set head equal to tail
	if (wasEmpty)
		head=tail;

	//put <item> at the tail of the queue
	array[tail] = item;
}

/********************************************************************************
 * T Dequeue ();
 * 	Purpose: 
 * 		Similar to Pop() in a stack but reversed,
 * 		Removes the first-added element (the head) of the queue and
 * 		returns a copy of it.
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		Returns the element that was just removed
 * 		(can throw exception if queue is empty)
 * 	
 ********************************************************************************/
template < typename T >
T CircularQueue<T>::Dequeue ()
{
	// if the queue is empty, throw an exception
	if(isEmpty())
		throw CircularQueue::_Underflow;

	// store a copy of the current first element
	T result = array[head];

	// if this is the last element in the array, set head and tail to -1
	// (to signify that the queue is empty)
	if(head == tail)
		head = tail = -1;

	// otherwise just move the head up a space
	else
		head = ( head + 1 ) % size;

	//return the first added element from the queue 
	return result;
}

/********************************************************************************
 * T& Front ();
 * 	Purpose: 
 * 		Get a reference to the front element on the queue
 * 		(the one that was first added that is still on the queue)
 * 	
 * 	Entry: 
 * 		Nothing
 * 	
 * 	Exit: 
 * 		Returns a reference to the front queue element
 * 		(can throw exception if queue is empty)
 * 	
 ********************************************************************************/
template < typename T >
T& CircularQueue<T>::Front ()
{
	//if the queue is empty, throw an exception
	if(isEmpty())
		throw CircularQueue::Underflow;

	//otherwise return a reference to the head element
	return array[head];
}

/********************************************************************************
 * int Size ();
 * 	Purpose: 
 * 		Get the number of active elements on the stack
 * 		(that haven't been Dequeue'd yet)
 * 		Note: does NOT return the maximum size of the queue.
 * 	
 * 	Entry: 
 * 		(unless it is full)
 * 		Nothing
 * 	
 * 	Exit: 
 * 		Returns the number of active elements in the queue
 * 	
 ********************************************************************************/
template < typename T >
int CircularQueue<T>::Size ()
{
	//if the queue is empty, return 0
	if(isEmpty())
		return 0;

	//otherwise return the clockwise distance from head to tail
	return (tail + size - head) % size + 1;
}

/********************************************************************************
 * bool isEmpty () const;
 * 	Purpose: 
 * 		Find if the queue is empty or not
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		returns true if it's empty, false if it's not
 * 	
 ********************************************************************************/
template < typename T >
bool CircularQueue<T>::isEmpty () const
{
	//relies on head and tail being set to -1 when the queue is completely emptied
	return head == -1 || tail == -1 ;
}

/********************************************************************************
 * bool isFull () const;
 * 	Purpose: 
 * 		Find if the queue is full or not
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		returns true if it's full, false if it's not.
 * 	
 ********************************************************************************/
template < typename T >
bool CircularQueue<T>::isFull () const 
{
	//return true if head becomes the element right after tail in the queue
	return ( head + size - 1 ) % size == tail;
}

/********************************************************************************
 * ~CircularQueue();
 * 	Purpose: 
 * 		Destructor for circular queue class
 * 		doesn't need to do anything because Array's destructor is implicitly
 * 		called.
 * 	
 * 	Entry: 
 * 		A valid circular queue
 * 	
 * 	Exit: 
 * 		A de-allocated circular queue
 * 	
 ********************************************************************************/
template < typename T >
CircularQueue<T>::~CircularQueue()
{
	//implicitly call Array destructor for array
}

#endif

