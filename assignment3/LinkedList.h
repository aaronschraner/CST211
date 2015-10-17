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
 *      const Node<T>& First ():
 *         returns a reference to the first node in the list
 * 
 *      const Node<T>& Last ():
 *         returns a reference to the last node in the list
 * 
 *     void Prepend (T* elem):
 *         prepend a given element at the start of the list
 * 
 *     void Append (T* elem):
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
 * 
 * this design is awful and I am sorry for bringing an implementation of it into the world. 
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
		//TODO: brief description
		bool isEmpty ();

		//TODO: brief description
		const Node<T>& First ();

		//TODO: brief description
		const Node<T>& Last ();

		//TODO: brief description
		void Prepend (T elem);

		//TODO: brief description
		void Append (T elem);

		//TODO: brief description
		void Purge ();

		//TODO: brief description
		Node<T>& Extract ( T key );

		//TODO: brief description
		void InsertAfter (T key, T value);

		//TODO: brief description
		void InsertBefore (T key, T value);

		//TODO: brief description
		Iterator<T> Begin ();

		//TODO: brief description
		Iterator<T> End ();

		// copy constructor
		LinkedList<T>& operator=(const LinkedList<T>& ll);

};
#include "LinkedList_impl.h"

#endif


