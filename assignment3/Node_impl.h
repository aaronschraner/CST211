/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 16, 2015
 * Last Modified:     October 16, 2015
 * Assignment number: 3
 * Filename:          Node_impl.h
 * 
 ********************************************************************************/
#include <iostream>

// link a node after this one (node goes in this->next)
template <typename T>
void Node<T>::append (Node<T>* node)
{
    next = node;
	if(node)
		node -> prev = this;
}

// link a node before this one (node goes in this->prev)
template <typename T>
void Node<T>::prepend (Node<T>* node)
{
	prev = node;
	if(node)
		node -> next = this;
}

// break the link between this node and prev
template <typename T>
void Node<T>::unlinkPrev ()
{
	prev -> next = 0;
	prev = 0;
}

// break the link between this node and next
template <typename T>
void Node<T>::unlinkNext ()
{
	next -> prev = 0;
	next = 0;
}

// unlink and delete the next node
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
template <typename T>
void Node<T>::drop()
{
	if(next)
		next->prev=prev;
	if(prev)
		prev->next=next;
	next=prev=0;
}

template <typename T>
Node<T>::~Node()
{
	std::cout << "Freed node containing [" << contents << "]\n";
}

template <typename T>
Node<T>::Node(const Node<T>& node):
	Node(node.contents) // not sure if this should copy anything else...
{
}

template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& node)
{
	//TODO
	contents=node.contents;
	return node;
}

