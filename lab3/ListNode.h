/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 16, 2015
 * Last Modified:     October 16, 2015
 * Assignment number: 3
 * Filename:          ListNode.h
 * 
 * Class: ListNode
 * 
 * Methods: 
 *      ListNode<T>* getNext ():
 *         return a pointer to the next node
 *
 *      ListNode<T>* getPrev ():
 *         return a pointer to the previous node
 *
 *      void append (ListNode<T>* node):
 *         append a node to this node (next=node)
 *
 *      void prepend (ListNode<T>* node):
 *         prepend a node to this node (this->prev=node, node->next=this)
 *
 *      T& getContents ():
 *         returns the contents of the node
 *
 *      void setContents (const T& val):
 *         set the contents of the node to <val>
 * 
 *      void setNext(ListNode<T>* n) 
 *      	set the next pointer to <n>
 * 
 *      void setPrev(ListNode<T>* p) 
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
 *      ListNode():
 *			default constructor (sets contents, prev, and next to 0)
 *      	
 *      ListNode(const T& val):
 *			constructor given value for node (same as default but contents=val)
 * 
 *      ListNode(const ListNode<T>& node):
 *			copy constructor
 * 
 *      ListNode<T>& operator=(const ListNode<T>& node):
 *			assignment operator (does not copy node pointers, only contents)
 * 
 *      ~ListNode():
 *			destructor (calls Purge())
 *      	
 * 
 ********************************************************************************/

#ifndef NODE_H
#define NODE_H

template < typename T >
class ListNode
{
	private:
		T contents;
		ListNode<T>* next;
		ListNode<T>* prev;

	public:
		// return the address of the next node
		ListNode<T>* getNext () const { return next; }

		// return the address of the previous node
		ListNode<T>* getPrev () const { return prev; }

		void setNext(ListNode<T>* n) { next=n; }

		void setPrev(ListNode<T>* p) { prev=p; }

		// link a node in front of (next) this one
		void append (ListNode<T>* node);

		// link a node behind (prev) this one
		void prepend (ListNode<T>* node);

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
		ListNode():ListNode(0) {}

		// constructor given node contents
		ListNode(const T& val):next(0), prev(0), contents(val) {}

		// copy constructor
		ListNode(const ListNode<T>& node);

		// assignment operator
		ListNode<T>& operator=(const ListNode<T>& node);

		// destructor
		~ListNode();

};

#include "ListNode_impl.h"

#endif

