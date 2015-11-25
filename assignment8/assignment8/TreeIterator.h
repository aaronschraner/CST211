#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "AbstractIterator.h"

template <typename T>
class BinaryTree;

//there is no elegant way to do this

template <typename T>
void pathAppend(TreeNode<T>& node, void* p)
{
	std::list<TreeNode<T>*>& path = *( (std::list<TreeNode<T>*>*)p);
	path.push_back(&node);
}

template <typename T>
class TreeIterator:
	public AbstractIterator<T>
{
	public:
		enum Position { _begin, _end };
		void populate(BinaryTree<T>& tree, typename BinaryTree<T>::TraversalPath tp, Position pos = _begin);
		TreeIterator() { }
		TreeIterator(const TreeIterator<T>& iterator):path(iterator.path), position(iterator.position) {} 
		const T& operator*() const { return (*position)->getValue(); }
		T& operator*() { return (*position)->getValue(); }
		bool operator==(const TreeIterator<T>& ti) const { return *position == *(ti.position); }
		bool operator!=(const TreeIterator<T>& ti) const { return !(*this == ti); }
		TreeIterator<T>& operator++() { position++; return *this; }
		TreeIterator<T>& operator++(int) { position++; return *this; }
		TreeIterator<T>& operator--() { position--; return *this; }
		TreeIterator<T>& operator--(int) { position--; return *this; }
		void setpos(Position p);

		

	protected:

		std::list<TreeNode<T>*> path;
		typename std::list<TreeNode<T>*>::iterator position;
};

template <typename T>
void TreeIterator<T>::setpos(TreeIterator<T>::Position p)
{
	this->path.push_back(0); //my end
	switch(p)
	{
		case TreeIterator<T>::_begin: this->position = this->path.begin(); break;
		case TreeIterator<T>::_end: this->position = this->path.end(); this->position--; break;
	}
}

template <typename T>
void TreeIterator<T>::populate(BinaryTree<T>& tree, typename BinaryTree<T>::TraversalPath tp, Position pos)
{
	tree.Traverse(pathAppend, tp, &path);
	setpos(pos);
}

#endif
