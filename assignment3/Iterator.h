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
 *     Iterator<T>& operator-- ():
 *         Make node point to node->prev
 *     Node<T>& operator* ():
 *         return a reference to the contained node
 *      Iterator (Node<T>* nodeptr):
 *         Construct iterator from node pointer
 * 
 ********************************************************************************/

#ifndef ITERATOR_H
#define ITERATOR_H
#include "Node.h"

template < typename T >
class Iterator
{
    private:
        Node<T>* node;
    public:
        //Compare iterator to another iterator
        bool operator== (const Iterator<T>& lhs) const { return &(*lhs)==node; }

        //TODO: brief description
        Iterator<T>& operator++ ();
        //TODO: brief description
        Iterator<T>& operator-- ();
        //TODO: brief description
        Node<T>* operator* ();
        //TODO: brief description
        Iterator (Node<T>* nodeptr);
};

#include "Iterator_impl.h"
#endif

