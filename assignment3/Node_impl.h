/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 16, 2015
 * Last Modified:     October 16, 2015
 * Assignment number: 3
 * Filename:          Node_impl.h
 * 
 ********************************************************************************/
#include <iostream>

#ifndef NODE_IMPL_H
#define NODE_IMPL_H

// link a node after this one (node goes in this->next)
/********************************************************************************
 * void append (Node<T>* node);
 * 	Purpose: 
 * 		Link a node <node> after this node
 * 		(this->next = node)
 * 		also takes care of double linking and moving the next node out
 * 		of the way instead of forgetting about it
 * 	
 * 	Entry: 
 * 		Node<T>* node: the node to be appended after this node
 * 	
 * 	Exit: 
 * 		Nothing (void)
 * 	
 ********************************************************************************/
template <typename T>
void Node<T>::append (Node<T>* node)
{
	if(node)
	{
		node -> next = next;
		node -> prev = this;
	}
	next = node;
}

// link a node before this one (node goes in this->prev)
/********************************************************************************
 * void prepend (Node<T>* node);
 * 	Purpose: 
 * 		Same as append
 * 		but prepends a node before this one
 * 		(does linking and stitches list around new node)
 * 	
 * 	Entry: 
 * 		Node<T>* node: a pointer to the node that should be prepended
 * 		before this one
 * 	
 * 	Exit: 
 * 		does not return anything
 * 		does leave containing list still continuous
 * 	
 ********************************************************************************/
template <typename T>
void Node<T>::prepend (Node<T>* node)
{
	if(node)
	{
		node -> next = this;
		node -> prev = prev;
	}
	prev = node;
}

// break the link between this node and prev
/********************************************************************************
 * void unlinkPrev ();
 * 	Purpose: 
 * 		Same as unlinkNext() but with prev
 * 		un-links previous node without deleting
 * 		effectively splits list between this and this->prev
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		prev->next is now 0 and this->prev is now 0
 * 		prev is now its own independent list
 * 	
 ********************************************************************************/
template <typename T>
void Node<T>::unlinkPrev ()
{
	prev -> next = 0;
	prev = 0;
}

// break the link between this node and next
/********************************************************************************
 * void unlinkNext ();
 * 	Purpose: 
 * 		Un-links (does not delete) the next node in the list
 * 		Should really never be used unless splitting one list into two
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		next->prev is now 0 and this->next is now 0
 * 		next effectively becomes a new independent list
 * 	
 ********************************************************************************/
template <typename T>
void Node<T>::unlinkNext ()
{
	next -> prev = 0;
	next = 0;
}

// unlink and delete the next node
/********************************************************************************
 * void deleteNext();
 * 	Purpose: 
 * 		De-allocates the next node after this one and stitches the list
 * 		around it using drop()
 * 	
 * 	Entry: 
 * 		nothing
 * 		(but operates on this->next)
 * 	
 * 	Exit: 
 * 		nothing
 * 	
 ********************************************************************************/
template <typename T>
void Node<T>::deleteNext ()
{
	if(next)
	{
		//drop changes the value of next
		auto tmp = next;
		next->drop();
		delete tmp;
	}
}

//unlink and delete the previous node
/********************************************************************************
 * void deletePrev();
 * 	Purpose: 
 * 		Works exactly the same as deleteNext but deletes the previous
 * 		node instead of the next one
 * 	
 * 	Entry: 
 * 		nothing
 * 		(but operates on this->prev)
 * 	
 * 	Exit: 
 * 		nothing
 * 	
 ********************************************************************************/
template <typename T>
void Node<T>::deletePrev ()
{
	if(prev)
	{
		//drop changes the value of prev
		auto tmp = prev;
		prev->drop();
		delete tmp;
	}
}



// remove a node and patch the nodes around it 
/********************************************************************************
 * void drop();
 * 	Purpose: 
 * 		Un-link (do not de-allocate) a node and stitch the containing
 * 		list around it.
 * 		WARNING: Node becomes inaccessible except for existing references
 * 		after this is called
 * 		If this node is the only one in the list, sets head and tail to 0
 * 	
 * 	Entry: 
 * 		nothing (but operates on this node)
 * 	
 * 	Exit: 
 * 		A still continuous list (as long as this wasn't the only node)
 * 		but missing this node
 * 		the node that called drop() is still allocated, but cannot be
 * 		accessed from the list that previously contained it
 * 	
 ********************************************************************************/
template <typename T>
void Node<T>::drop()
{
	if(next)
		next->prev=prev;
	if(prev)
		prev->next=next;
	next=prev=0;
}

/********************************************************************************
 * ~Node();
 * 	Purpose: 
 * 		Destructor for node class
 * 		Doesn't really do anything but (currently) let you know
 * 		that the destructor was called
 * 		(for memory leak testing purposes
 * 		)
 * 	
 * 	Entry: 
 * 		A perfectly good node
 * 	
 * 	Exit: 
 * 		the exact same node except now nobody knows it exists
 * 	
 ********************************************************************************/
template <typename T>
Node<T>::~Node()
{
	std::cout << "Freed node containing [" << contents << "]\n";
}

/********************************************************************************
 * Node(const Node<T>& node);
 * 	Purpose: 
 * 		Copy constructor for Node class
 * 	
 * 	Entry: 
 * 		const Node<T>& node: the node to be copied
 * 	
 * 	Exit: 
 * 		A node with the same contents as <node>, but with next and prev
 * 		set to 0/NULLPTR
 * 		This means the  result is not an exact copy of node
 * 	
 ********************************************************************************/
template <typename T>
Node<T>::Node(const Node<T>& node):
	Node(node.contents) // not sure if this should copy anything else...
{
}

/********************************************************************************
 * Node<T>& operator=(const Node<T>& node);
 * 	Purpose: 
 * 		Assignment operator for node class
 * 		(does not copy values of next and prev)
 * 		designed to allow easy copy / assignment in linked list class
 * 	
 * 	Entry: 
 * 		const Node<T>& node: the node to have its contents copied
 * 	
 * 	Exit: 
 * 		returns a reference to the newly assigned node
 * 		node pointers will not have changed
 * 		contents will now be the same as node.contents
 * 	
 ********************************************************************************/
template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& node)
{
	//TODO
	contents=node.contents;
	return node;
}

#endif
