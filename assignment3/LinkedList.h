/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 16, 2015
 * Last Modified:     October 16, 2015
 * Assignment number: 3
 * Filename:          LinkedList.h
 * 
 * Class: LinkedList
 * 
 * Methods: 
 *      bool isEmpty ():
 *         returns if the list is empty
 * 
 *      Node<T>& First ():
 *         returns a reference to the first node in the list
 * 
 *      Node<T>& Last ():
 *         returns a reference to the last node in the list
 * 
 *     void Prepend (T elem):
 *         prepend a given element at the start of the list
 * 
 *     void Append (T elem):
 *         append a given element at the end of the list
 * 
 *      void Purge ():
 *         delete every element in the list
 * 
 *      Node<T>& Extract ( key T):
 *         (guessing from UML) returns the first node with contents matching <key> and drops it from the list
 * 
 *      void InsertAfter (T key, T* value):
 *         (guessing from UML) find a node with Extract(key) and append an element after it
 * 
 *      void InsertBefore (T key, T* value):
 *         (guessing from UML) find a node with Extract(key) and prepend an element before it
 * 
 *      Iterator<T> Begin ():
 *         return an iterator to the first node in the list
 * 
 *      Iterator<T> End ():
 *         return an iterator to the last node in the list
 * 
 * block headers suck
 ********************************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "Iterator.h"

template < typename T >
class LinkedList
{
	private:
		Node<T>* head;
		Node<T>* tail;

	public:

		//finds if list is empty
		bool isEmpty () const;

		//get const/mutable references to the first/last nodes
		// (uses inline because it's easier to read and more efficient)
		const Node<T>&	First() const	{ return *head; }
		Node<T>&		First()			{ return *head; }
		const Node<T>&	Last() const	{ return *tail; }
		Node<T>&		Last()			{ return *tail; }

		// append/prepend an element at the end/beginning of the list
		void Append (T elem);
		void Prepend (T elem);

		// delete all elements in the list
		void Purge ();

		// find the first instance of <key>, remove it from the list, and return the node
		Node<T>& Extract ( T key );

		//find the first instance of <key> and insert <value> before/after it
		void InsertBefore (T key, T value);
		void InsertAfter (T key, T value);

		//get const/mutable iterators to the first/last list nodes
		Iterator<T> Begin () ;
		const Iterator<T> Begin () const;
		Iterator<T> End () ;
		const Iterator<T> End() const;

		// copy constructor
		LinkedList(const LinkedList<T>& ll);

		// assignment operator
		LinkedList<T>& operator=(const LinkedList<T>& ll);

		// default constructor
		LinkedList();

		// destructor (calls purge)
		~LinkedList();

		//Find the first instance of <key> in the list and return a reference to the containing node
		Node<T>& Find(T key);

};
#include "LinkedList_impl.h"

#endif
