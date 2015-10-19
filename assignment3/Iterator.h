/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 16, 2015
 * Last Modified:     October 16, 2015
 * Assignment number: 3
 * Filename:          Iterator.h
 * 
 * Class: Iterator
 * 
 * Methods: 
 *     Iterator<T>& operator++ ():
 *         Make node point to node->next
 *
 *     Iterator<T>& operator-- ():
 *         Make node point to node->prev
 *
 *     Node<T>& operator* ():
 *         return a reference to the contained node
 *
 *      Iterator (Node<T>* nodeptr):
 *         Construct iterator from node pointer
 *
 *      bool operator== ( const Iterator<T>& rhs):
 *         Returns true if the iterators point to the same node
 * 
 *      Iterator<T>& operator= (const Iterator<T>& rhs):
 *         assigns this iterator's node to <rhs>'s
 * 
 *      Iterator<T>& operator++ (int):
 *         same as the other operator++ but postfix
 * 
 *      Iterator<T>& operator-- (int):
 *         same as the other operator-- but postfix
 * 
 *      Iterator ( const Iterator<T>& rhs):
 *         copy constructor (sets node to <rhs>'s node)
 * 
 ********************************************************************************/

#ifndef ITERATOR_H
#define ITERATOR_H
#include "Node.h"

template < typename T >
class Iterator
{
	private:
		// the node pointer that this iterator should operate on
		Node<T>* node;

	public:
		// Compare iterator to another iterator
		bool operator== (const Iterator<T>& rhs) const { return &(*rhs)==node; }

		// Assignment operator
		Iterator<T>& operator=(const Iterator<T>& rhs) { node=rhs.node; return *this; }

		// Increment operator (node=node->next)
		Iterator<T>& operator++ ();
		Iterator<T>& operator++ (int);

		// decremeent operator (node=node->prev)
		Iterator<T>& operator-- ();
		Iterator<T>& operator-- (int);

		// dereference operator (return pointer to contained node)
		Node<T>* operator* ();

		// constructor (takes pointer to node)
		Iterator (Node<T>* nodeptr = 0);

		// copy constructor
		Iterator(const Iterator<T>& rhs);
};

#include "Iterator_impl.h"
#endif

