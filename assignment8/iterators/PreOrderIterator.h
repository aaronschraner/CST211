#ifndef PREORDERITERATOR_H
#define PREORDERITERATOR_H

#include "../TreeIterator.h"
template <typename T>
class PreOrderIterator:
	public TreeIterator<T>
{
	public:
		//constructors (almost everything handled in TreeIterator class)
		PreOrderIterator(BinaryTree<T>& tree, 
			   	typename TreeIterator<T>::Position pos = TreeIterator<T>::_begin) 
		{ this->populate(tree,BinaryTree<T>::_PreOrder, pos); } 
		PreOrderIterator(const TreeIterator<T>& iterator):TreeIterator<T>(iterator) {}
		PreOrderIterator(const PreOrderIterator<T>& iterator) { this->path = iterator.path; this->position = iterator.position; }

};

#endif
