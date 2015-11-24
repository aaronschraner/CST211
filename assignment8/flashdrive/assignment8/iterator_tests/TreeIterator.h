#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "Iterator.h"
#include <deque>
template <typename T>
class TreeNode;

template <typename T>
class TreeIterator:
	public Iterator<T>
{
	public:
		const T& operator*() const { return currentNode->getValue(); }
		T& operator*() { return currentNode->getValue(); }
		bool operator==(const TreeIterator<T>& ti) const { return currentNode == ti.currentNode; }
	private:
		std::deque<TreeNode<T>*> path;
		TreeNode<T>* currentNode;
};
#endif
