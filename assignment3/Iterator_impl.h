/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 16, 2015
 * Last Modified:     October 16, 2015
 * Assignment number: 3
 * Filename:          Iterator_impl.h
 * 
 ********************************************************************************/

#include "Node.h"
#ifndef ITERATOR_IMPL_H
#define ITERATOR_IMPL_H

//TODO: make method comment blocks
template <typename T>
Iterator<T>& Iterator<T>::operator++ ()
{
	node = node -> getNext();
	return *this;
}

//TODO: make method comment blocks
template <typename T>
Iterator<T>& Iterator<T>::operator-- ()
{
    node = node -> getPrev();
	return *this;
}

//TODO: make method comment blocks
template <typename T>
Node<T>* Iterator<T>::operator* ()
{
    return node;
}

//TODO: make method comment blocks
template <typename T>
Iterator<T>::Iterator (Node<T>* nodeptr):
	node(nodeptr)
{
}


#endif
