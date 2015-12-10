#ifndef INORDERITERATOR_H
#define INORDERITERATOR_H

#include "../TreeIterator.h"
template <typename T>
class InOrderIterator:
	public TreeIterator<T>
{
	public:
		//constructors (almost everything handled in TreeIterator class)
		InOrderIterator(BinaryTree<T>& tree, 
			   	typename TreeIterator<T>::Position pos = TreeIterator<T>::_begin) 
		{ this->populate(tree,BinaryTree<T>::_InOrder, pos); } 
		InOrderIterator(const TreeIterator<T>& iterator):TreeIterator<T>(iterator) {}
		InOrderIterator(const InOrderIterator<T>& iterator) { this->path = iterator.path; this->position = iterator.position; }

};

#endif
