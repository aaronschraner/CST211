/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 16, 2015
 * Last Modified:     October 16, 2015
 * Assignment number: 3
 * Filename:          LinkedList_impl.h
 * 
 ********************************************************************************/
#ifndef LINKEDLIST_IMPL_H
#define LINKEDLIST_IMPL_H

// returns if the list is empty or not
template < typename T >
bool LinkedList<T>::isEmpty ()
{
	return !head;
}

// returns a reference to the first node in the list
template < typename T >
const Node<T>& LinkedList<T>::First ()
{
	return *head;
}

// returns a reference to the last node in the list
template < typename T >
const Node<T>& LinkedList<T>::Last ()
{
	return *tail;
}

// insert an element before the start of the list
template < typename T >
void LinkedList<T>::Prepend (T elem)
{
	//store the old first element
	Node<T>* temp = head;

	//create the new first element
	head = new Node<T>(elem);

	//if there was an old first element, make it's prev point to the new first one
	if(temp)
		temp->prev = head;
	else
		tail = head;

	//adjust the pointers for the new first node
	head -> next = temp;
	head -> prev = 0;
}

// insert an element after the end of the list
template < typename T >
void LinkedList<T>::Append (T elem)
{
	//store the old last element
	Node<T>* temp = tail;

	//create the new last element
	tail = new Node<T>(elem);

	//if there was an old last element, make it's next point to the new last one
	if(temp)
		temp->next = tail;
	else
		head = tail;

	//adjust the pointers for the new last node
	tail -> prev = temp;
	tail -> next = 0;
}

//delete everything in the list
template < typename T >
void LinkedList<T>::Purge ()
{
	while(head->getNext())
		head->deleteNext();
	delete head;
	head=0;
	tail=0;
}

// (guessing from UML) returns the first node with contents matching <key> and drops it from the list
template < typename T >
Node<T>& LinkedList<T>::Extract (T key )
{
	//TODO
	return *head;
}

// (guessing from UML) find a node with Extract(key) and append an element after it
template < typename T >
void LinkedList<T>::InsertAfter (T key, T value)
{
	Extract(key).append(new Node<T>(value));
}

// (guessing from UML) find a node with Extract(key) and prepend an element before it
template < typename T >
void LinkedList<T>::InsertBefore (T key, T value)
{
	Extract(key).prepend(new Node<T>(value));
}

// return an iterator to the first node in the list
template < typename T >
Iterator<T> LinkedList<T>::Begin ()
{
	return Iterator<T>(head);
}

// return an iterator to the last node in the list
template < typename T >
Iterator<T> LinkedList<T>::End ()
{
	return Iterator<T>(tail);
}

// assignment operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& ll)
{
	//create 
	Purge();
	if ( isEmpty() )
	{
		head=tail=0;
		return *this;
	}
	head = new Node<T> (ll.First().getContents());
	auto newit = Begin();
	auto oldit = Iterator<T>(&(ll.First()));
	for(++oldit; *oldit; ++oldit,++newit)
	{
		(*newit)->append(new Node<T> ( (*oldit)->getContents()));
	}


}

#endif
