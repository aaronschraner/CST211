#ifndef INORDER_H
#define INORDER_H
#include "../TreeIterator.h"


template <typename T>
class BinaryTree;

template <typename T>
class InOrderIterator:
	public TreeIterator<T>
{
	private:
	public:
		InOrderIterator(BinaryTree<T>* tree);
		void operator++()		{ this->currentNode++; }
		void operator++(int)	{ this->currentNode++; }
		void operator--()		{ this->currentNode--; }
		void operator--(int)	{ this->currentNode--; } 


};

#include "InOrder_impl.h"

#endif
