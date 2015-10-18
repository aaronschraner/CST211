/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 16, 2015
 * Last Modified:     October 16, 2015
 * Assignment number: 3
 * Filename:          Iterator_impl.h
 * Purpose:           Implementation for Iterator class
 * 
 ********************************************************************************/

#include "Node.h"
#ifndef ITERATOR_IMPL_H
#define ITERATOR_IMPL_H

// prefix increment operator
// make node point to the next node
/********************************************************************************
 * Iterator<T>& operator++ ();;
 * 	Purpose: 
 * 		Node iterator increment operator
 * 		(makes this->node point to node->next)
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		A reference to the iterator
 * 	
 ********************************************************************************/
template <typename T>
Iterator<T>& Iterator<T>::operator++ ()
{
	if(node)
		node = node -> getNext();
	return *this;
}

// prefix decrement operator
// make node point to the previous node
/********************************************************************************
 * Iterator<T>& operator-- ();;
 * 	Purpose: 
 * 		Prefix decrement operator for iterator
 * 		makes this->node point to node->prev
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		reference to the iterator
 * 	
 ********************************************************************************/
template <typename T>
Iterator<T>& Iterator<T>::operator-- ()
{
	if(node)
		node = node -> getPrev();
	return *this;
}

// postfix increment operator
// same as operator++ but returns value before increment
/********************************************************************************
 * Iterator<T>& operator++ (int);;
 * 	Purpose: 
 * 		Increment operator (same as other operator but postfix instead of
 * 		prefix)
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		A reference to the iterator before it got pointed to the next node
 * 	
 ********************************************************************************/
template <typename T>
Iterator<T>& Iterator<T>::operator++ (int)
{
	Iterator<T> oldnode = Iterator<T>(node);
	if(node)
		node = node -> getNext();
	return oldnode;
}

// postfix decrement operator
// same as operator-- but returns value before decrement
/********************************************************************************
 * Iterator<T>& operator-- (int);;
 * 	Purpose: 
 * 		Postfix decrement operator
 * 		does the same thing as prefix but returns a reference to the
 * 		iterator before it got changed
 * 	
 * 	Entry: 
 * 		nothing (int doesn't do anything)
 * 	
 * 	Exit: 
 * 		a reference to the iterator before it got changed
 * 	
 ********************************************************************************/
template <typename T>
Iterator<T>& Iterator<T>::operator-- (int)
{
	Iterator<T> oldnode = Iterator<T>(node);
	if(node)
		node = node -> getPrev();
	return oldnode;
}

// dereference operator
// returns the contained node pointer
/********************************************************************************
 * Node<T>* operator* ();;
 * 	Purpose: 
 * 		Dereference list iterator (returns a node pointer because the UML
 * 		didn't say I should do otherwise)
 * 	
 * 	Entry: 
 * 		Nothing
 * 	
 * 	Exit: 
 * 		A node pointer pointing to this->node
 * 	
 ********************************************************************************/
template <typename T>
Node<T>* Iterator<T>::operator* ()
{
	return node;
}

// constructor
// takes optional node pointer
/********************************************************************************
 * Iterator (Node<T>* nodeptr = 0);;
 * 	Purpose: 
 * 		Iterator constructor given node pointer
 * 	
 * 	Entry: 
 * 		Pointer to be assigned to node (defaults to 0)
 * 	
 * 	Exit: 
 * 		Constructs the Iterator
 * 	
 ********************************************************************************/
template <typename T>
Iterator<T>::Iterator (Node<T>* nodeptr):
	node(nodeptr)
{
}

//copy constructor
/********************************************************************************
 * Iterator(const Iterator& rhs);;
 * 	Purpose: 
 * 		Copy constructor for iterator
 * 	
 * 	Entry: 
 * 		const reference to another iterator
 * 	
 * 	Exit: 
 * 		Constructed iterator with same node as rhs
 * 	
 ********************************************************************************/
template <typename T>
Iterator<T>::Iterator(const Iterator& rhs):
	node(rhs.node)
{}


#endif
