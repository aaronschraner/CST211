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

//TODO: make method comment blocks
template < typename T >
Queue<T>::Queue ( const Queue& q):
	list(q.list), maxSize(q.maxSize), size(q.size)
{
}

//TODO: make method comment blocks
template < typename T >
Queue<T>::Queue ():
	Queue(DEFAULT_QUEUE_SIZE )
{
}

//TODO: make method comment blocks
template < typename T >
Queue<T>::Queue (int size):
	maxSize(size), size(0)
{
}

//TODO: make method comment blocks
template < typename T >
Queue<T>::~Queue ()
{
	//list handles its own destructor
}

//TODO: make method comment blocks
template < typename T >
void Queue<T>::Enqueue ( const T& elem)
{
	if(isFull())
		throw Queue::_Overflow;
	list.Prepend(elem);
	size++;
}

//TODO: make method comment blocks
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

//TODO: make method comment blocks
template < typename T >
T& Queue<T>::Front ()
{
	if(isEmpty())
		throw Queue::_Underflow;
	return list.First().getContents();
}

//TODO: make method comment blocks
template < typename T >
bool Queue<T>::isEmpty()  const
{
	return size==0;
}

//TODO: make method comment blocks
template < typename T >
bool Queue<T>::isFull () const
{
	return size>=maxSize;
}

#endif

