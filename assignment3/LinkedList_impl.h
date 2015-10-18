/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 16, 2015
 * Last Modified:     October 17, 2015
 * Assignment number: 3
 * Filename:          LinkedList_impl.h
 * 
 ********************************************************************************/
#ifndef LINKEDLIST_IMPL_H
#define LINKEDLIST_IMPL_H

#include "Exception.h"

// returns if the list is empty or not
/********************************************************************************
 * bool isEmpty () const;
 * 	Purpose: 
 * 		Find out if the list is empty or not
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		true if list is empty
 * 		false if list has nodes in it
 * 		(uses head to find out)
 * 	
 ********************************************************************************/
template < typename T >
bool LinkedList<T>::isEmpty () const
{
	return !head;
}


// insert an element before the start of the list
/********************************************************************************
 * void Prepend (T elem);
 * 	Purpose: 
 * 		Prepend an element (elem) before the start of the list
 * 	
 * 	Entry: 
 * 		T elem: the element to be prepended to the list
 * 	
 * 	Exit: 
 * 		void (nothing)
 * 	
 ********************************************************************************/
template < typename T >
void LinkedList<T>::Prepend (T elem)
{
	//store the old first element
	Node<T>* temp = head;

	//create the new first element
	head = new Node<T>(elem);

	//if there was an old first element, make it's prev point to the new first one
	if(temp)
		temp->setPrev( head);
	else
		tail = head;

	//adjust the pointers for the new first node
	head -> setNext(temp);
	head -> setPrev(0);
}

// insert an element after the end of the list
/********************************************************************************
 * void Append (T elem);
 * 	Purpose: 
 * 		Append a given element to the end of the list
 * 		(automatically generates required node)
 * 	
 * 	Entry: 
 * 		T elem: the element to be added to the end of the list
 * 	
 * 	Exit: 
 * 		void (nothing)
 * 	
 ********************************************************************************/
template < typename T >
void LinkedList<T>::Append (T elem)
{
	//store the old last element
	Node<T>* temp = tail;

	//create the new last element
	tail = new Node<T>(elem);

	//if there was an old last element, make it's next point to the new last one
	if(temp)
		temp->setNext(tail);
	else
		head = tail;

	//adjust the pointers for the new last node
	tail -> setPrev(temp);
	tail -> setNext(0);
}

//delete everything in the list
/********************************************************************************
 * void Purge ();
 * 	Purpose: 
 * 		Unlink and free each item in the list
 * 		Note: does not delete in perfect sequential order.
 * 		Deletes second node first, then third, until it deletes the
 * 		last node. Then deletes the first node.
 * 		(deletes list[1, 2, 3, 4, ... end, 0])
 * 		Also used in destructor
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		(not returned but there) a completely empty list
 * 	
 ********************************************************************************/
template < typename T >
void LinkedList<T>::Purge ()
{
	if(head)
	{
		while(head->getNext())
			head->deleteNext();
		delete head;
	}
	head=0;
	tail=0;
}

/********************************************************************************
 * Node<T>& Find(T key);
 * 	Purpose: 
 * 		Find the first instance of a node whose contents match <key>
 * 		(iterates from head to tail, beginning to end)
 * 	
 * 	Entry: 
 * 		T key: the element/object to search for in the list
 * 	
 * 	Exit: 
 * 		a reference to the node that matched <key>
 * 		(can throw Exception meaning that the key was not found)
 * 	
 ********************************************************************************/
template <typename T>
Node<T>& LinkedList<T>::Find(T key)
{
	for(auto it=Begin(); *it; ++it)
		if ( key == (*it)->getContents())
			return **it;
	throw Exception ("Key not found");
}

// (guessing from UML) returns the first node with contents matching <key> and drops it from the list
/********************************************************************************
 * Node<T>& Extract ( T key );
 * 	Purpose: 
 * 		(had to guess from the UML name)
 * 		Find the first node in the array whose contents are equal to <key>
 * 		- unlink the node from the rest of the list
 * 		- patch the list around it
 * 		- return that node
 * 	
 * 	Entry: 
 * 		T key: the item to look for in the list
 * 	
 * 	Exit: 
 * 		a reference to the node that has just been removed/extracted
 * 		can also throw Exception because of dependence on Find()
 * 		exception probably means that <key> was not found in the list
 * 	
 ********************************************************************************/
template < typename T >
Node<T>& LinkedList<T>::Extract (T key )
{
	Node<T>& res = Find(key);
	res.drop();
	return res;
}

// (guessing from UML) find a node with Extract(key) and append an element after it
/********************************************************************************
 * void InsertAfter (T key, T value);
 * 	Purpose: 
 * 		(had to guess from UML diagram)
 * 		Use Find() to locate the first instance of <key> in the list,
 * 		and insert the element <value> after that node
 * 	
 * 	Entry: 
 * 		T key: the element to search for in the list
 * 		T value: the element to be inserted after the node matching <key>
 * 	
 * 	Exit: 
 * 		Hopefully nothing (void)
 * 		but can throw Exception if the requested key is not found in
 * 		the list.
 * 	
 ********************************************************************************/
template < typename T >
void LinkedList<T>::InsertAfter (T key, T value)
{
	Find(key).append(new Node<T>(value));
}

// (guessing from UML) find a node with Extract(key) and prepend an element before it
/********************************************************************************
 * void InsertBefore (T key, T value);
 * 	Purpose: 
 * 		Same as InsertAfter() but inserts <value> before the first node
 * 		that matches <key>.
 * 	
 * 	Entry: 
 * 		T key: the node to look for in the list
 * 		T value: the element to be inserted before that node^
 * 	
 * 	Exit: 
 * 		Hopefully nothing (void)
 * 		but can throw Exception if <key> is not found
 * 	
 ********************************************************************************/
template < typename T >
void LinkedList<T>::InsertBefore (T key, T value)
{
	Find(key).prepend(new Node<T>(value));
}

// return an iterator to the first node in the list
/********************************************************************************
 * Iterator<T> Begin () ;
 * 	Purpose: 
 * 		Returns an iterator to the first node in hte list (can be 0)
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		mutable iterator where Iterator.node = this->head
 * 	
 ********************************************************************************/
template < typename T >
Iterator<T> LinkedList<T>::Begin ()
{
	return Iterator<T>(head);
}

/********************************************************************************
 * const Iterator<T> Begin () const;
 * 	Purpose: 
 * 		Returns a const iterator to the first node in hte list (can be 0)
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		const iterator where Iterator.node = this->head
 * 	
 ********************************************************************************/
template <typename T>
const Iterator<T> LinkedList<T>::Begin () const
{
	return Iterator<T>(head);
}

// return an iterator to the last node in the list
/********************************************************************************
 * Iterator<T> End () ;
 * 	Purpose: 
 * 		Returns an iterator to the last element in the list
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		iterator where Iterator->node = this->tail
 * 	
 ********************************************************************************/
template < typename T >
Iterator<T> LinkedList<T>::End ()
{
	return Iterator<T>(tail);
}

// return a const iterator to the last node in the list
/********************************************************************************
 * const Iterator<T> End() const;
 * 	Purpose: 
 * 		Get a const iterator to the last node/element in the list
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		const iterator (basically the same as the other End() but const
 * 		)
 * 	
 ********************************************************************************/
template <typename T> 
const Iterator<T> LinkedList<T>::End() const
{
	return Iterator<T>(tail);
}

// assignment operator
/********************************************************************************
 * LinkedList<T>& operator=(const LinkedList<T>& ll);
 * 	Purpose: 
 * 		Assignment operator for linked list
 * 		- Purge/deletes every item in the list
 * 		- Creates a new head node
 * 		- Copies everything from the other list (ll) into this one
 * 		by appending elements onto the end of this list
 * 	
 * 	Entry: 
 * 		const LinkedList<T>& ll: the list that needs to be copied FROM
 * 	
 * 	Exit: 
 * 		a const reference to the new copy of the list
 * 		The list will now contain a copy of every element in <ll>
 * 	
 ********************************************************************************/
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& ll)
{
	//clear the list first 
	Purge();

	//if ll is empty, return the empty list
	if ( ll.isEmpty() )
	{
		return *this;
	}

	//create a new first node
	tail = head = new Node<T> (ll.First().getContents());

	auto newit = Begin();
	auto oldit = ll.Begin();
	for(++oldit; *oldit; ++oldit,++newit)
	{
		Append((*oldit)->getContents());
	}


}

// destructor
/********************************************************************************
 * ~LinkedList();
 * 	Purpose: 
 * 		Linked list destructor
 * 		(uses Purge to delete all elements in list)
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		even less nothing
 * 		(list is now empty)
 * 	
 ********************************************************************************/
template <typename T>
LinkedList<T>::~LinkedList()
{
	Purge();
}

/********************************************************************************
 * LinkedList(const LinkedList<T>& ll);
 * 	Purpose: 
 * 		Copy constructor for linked list
 * 		Creates a new copy of each node in the  old list (ll) in the new
 * 		list (this)
 * 	
 * 	Entry: 
 * 		const LinkedList<T>& ll: linked list to copy everything from
 * 	
 * 	Exit: 
 * 		A deep copy of <ll>
 * 	
 ********************************************************************************/
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& ll):
	LinkedList()
{
	*this=ll;
}

/********************************************************************************
 * LinkedList();
 * 	Purpose: 
 * 		Default constructor
 * 		sets head and tail to 0 (NULL/NULLPTR)
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		Empty linked list
 * 	
 ********************************************************************************/
template <typename T>
LinkedList<T>::LinkedList():
	head(0), tail(0)
{
}

#endif
