/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 18, 2015
 * Last Modified:     October 18, 2015
 * Assignment number: 
 * Filename:          LinkedList.h
 * 
 * Class: LinkedList
 * 
 * Methods: 
 *      const Node<T>& First() const: 
 *         returns a const reference to the first list node
 * 
 *      Node<T>&  First() 
 *         returns a mutable reference to the first list node
 * 
 *      Node<T>&  Last() 
 *         returns a mutable reference to the last list node
 * 
 *     const Node<T>& Last() const: 
 *         returns a const reference to the last list node
 * 
 *     const Iterator<T> Begin() const: 
 *         returns a const iterator to the first list node
 * 
 *     Iterator<T> Begin ():
 *         returns a mutable iterator to the first list node
 * 
 *     const Iterator<T> End() const: 
 *         returns a const iterator to the last list node
 * 
 *     Iterator<T> End ():
 *         returns a mutable iterator to the last list node
 * 
 *      LinkedList (const LinkedList<T>& ll):
 *         Copy constructor (deep copies each node)
 * 
 *      LinkedList<T>& operator= (const LinkedList<T>& ll):
 *         assignment operator (deep copy)
 * 
 *      LinkedList ():
 *         default constructor (creates empty list)
 * 
 *      ~LinkedList ():
 *         Destructor (deletes every node and empties list)
 * 
 *      Node<T>& Find (T key):
 *         Find the first instance of <key> in the list and return a reference to the containing node
 * 
 * 
 ********************************************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template < typename  >
class LinkedList
{
	private:
		//TODO: add member variables

	public:
		const Node<T>& First() const; 
		Node<T>&  First(); 
		const Node<T>& Last() const; 
		Node<T>&  Last(); 

		//TODO: brief description
		Iterator<T> Begin() const; 

		//TODO: brief description
		Iterator<T> Begin ();

		//TODO: brief description
		const Iterator<T> End() const; 

		//TODO: brief description
		Iterator<T> End ();

		//TODO: brief description
		LinkedList (const LinkedList<T>& ll);

		//TODO: brief description
		LinkedList<T>& operator= (const LinkedList<T>& ll);

		//TODO: brief description
		LinkedList ();

		//TODO: brief description
		~LinkedList ();

		//TODO: brief description
		Node<T>& Find (T key);

};
#include "LinkedList_impl.h"

#endif

