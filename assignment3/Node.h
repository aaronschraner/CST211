/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 16, 2015
 * Last Modified:     October 16, 2015
 * Assignment number: 3
 * Filename:          Node.h
 * 
 * Class: Node
 * 
 * Methods: 
 *      Node<T>* getNext ():
 *         return a pointer to the next node
 *
 *      Node<T>* getPrev ():
 *         return a pointer to the previous node
 *
 *      void append (Node<T>* node):
 *         append a node to this node (next=node)
 *
 *      void prepend (Node<T>* node):
 *         prepend a node to this node (this->prev=node, node->next=this)
 *
 *      T& getContents ():
 *         returns the contents of the node
 *
 *      void setContents (const T& val):
 *         set the contents of the node to <val>
 * 
 *      void setNext(Node<T>* n) 
 *      	set the next pointer to <n>
 * 
 *      void setPrev(Node<T>* p) 
 *      	set the prev pointer to <p>
 * 
 *      void unlinkPrev ():
 *      	un-link the previous node (good for splitting lists)
 * 
 *      void unlinkNext ():
 *			un-link the next node (good for splitting lists)
 * 
 *      void deletePrev():
 *			drop and delete the previous node
 * 
 *      void deleteNext():
 *			drop and delete the next node
 *       
 *      void drop():
 *      	un-link a node from the list, and stitch the list around it to remain continuous
 * 
 *      Node():
 *			default constructor (sets contents, prev, and next to 0)
 *      	
 *      Node(const T& val):
 *			constructor given value for node (same as default but contents=val)
 * 
 *      Node(const Node<T>& node):
 *			copy constructor
 * 
 *      Node<T>& operator=(const Node<T>& node):
 *			assignment operator (does not copy node pointers, only contents)
 * 
 *      ~Node():
 *			destructor (calls Purge())
 *      	
 * 
 ********************************************************************************/

#ifndef NODE_H
#define NODE_H

template < typename T >
class Node
{
	private:
		T contents;
		Node<T>* next;
		Node<T>* prev;

	public:
		// return the address of the next node
		Node<T>* getNext () const { return next; }

		// return the address of the previous node
		Node<T>* getPrev () const { return prev; }

		void setNext(Node<T>* n) { next=n; }

		void setPrev(Node<T>* p) { prev=p; }

		// link a node in front of (next) this one
		void append (Node<T>* node);

		// link a node behind (prev) this one
		void prepend (Node<T>* node);

		// break the link between this node and prev
		void unlinkPrev ();

		// break the link between this node and next
		void unlinkNext ();

		// delete the node pointed to by prev
		void deletePrev();

		// delete the node pointed to by next
		void deleteNext();

		// unlink a node from its surrounding nodes (don't delete it)
		void drop();
		
		// return the contents of the node
		const T& getContents () const { return contents; }
		T& getContents() { return contents; }

		// set the contents of the node
		void setContents (const T& val) { contents = val; }

		// default constructor (set everything to 0)
		Node():Node(0) {}

		// constructor given node contents
		Node(const T& val):next(0), prev(0), contents(val) {}

		// copy constructor
		Node(const Node<T>& node);

		// assignment operator
		Node<T>& operator=(const Node<T>& node);

		// destructor
		~Node();

};

#include "Node_impl.h"

#endif

