#ifndef POSTORDERITERATOR_H
#define POSTORDERITERATOR_H

#include "../TreeIterator.h"
template <typename T>
class PostOrderIterator:
	public TreeIterator<T>
{
	public:
		//constructors (almost everything handled in TreeIterator class)
		PostOrderIterator(BinaryTree<T>& tree, 
			   	typename TreeIterator<T>::Position pos = TreeIterator<T>::_begin) 
		{ this->populate(tree,BinaryTree<T>::_PostOrder, pos); } 
		PostOrderIterator(const TreeIterator<T>& iterator):TreeIterator<T>(iterator) {}
		PostOrderIterator(const PostOrderIterator<T>& iterator) { this->path = iterator.path; this->position = iterator.position; }

};

#endif
