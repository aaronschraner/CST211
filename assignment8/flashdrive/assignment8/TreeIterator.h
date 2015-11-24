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
		TreeIterator():Iterator<T>(this) { currentNode = path.begin(); }
		const T& operator*() const { return (*currentNode)->getValue(); }
		T& operator*() { return (*currentNode)->getValue(); }
		bool operator==(const TreeIterator<T>& ti) const { return currentNode == ti.currentNode; }
		bool isValid() const { return (!path.empty()) && *(path.rbegin()) == *currentNode; }
		void operator++() { currentNode++; }

		std::deque<TreeNode<T>*> path;
		typename std::deque<TreeNode<T>*>::iterator currentNode;
};
#endif
