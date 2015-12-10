#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H

#include "../TreeIterator.h"
template <typename T>
class BreadthFirstIterator:
	public TreeIterator<T>
{
	public:
		//constructors (almost everything handled in TreeIterator class)
		BreadthFirstIterator(BinaryTree<T>& tree, 
			   	typename TreeIterator<T>::Position pos = TreeIterator<T>::_begin) 
		{ this->populate(tree,BinaryTree<T>::_BreadthFirst, pos); } 
		BreadthFirstIterator(const TreeIterator<T>& iterator):TreeIterator<T>(iterator) {}
		BreadthFirstIterator(const BreadthFirstIterator<T>& iterator) { this->path = iterator.path; this->position = iterator.position; }

};

#endif
