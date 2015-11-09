/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  6, 2015
 * Last Modified:     November  6, 2015
 * Assignment number: 6
 * Filename:          BinaryTree_impl.h
 * 
 ********************************************************************************/
#ifndef BINARYTREE_IMPL_H
#define BINARYTREE_IMPL_H

//TODO: make method comment blocks
template < typename T >
BinaryTree<T>::BinaryTree ():
	root(0)
{
}

//TODO: make method comment blocks
template < typename T >
BinaryTree<T>::~BinaryTree ()
{
    //TODO
}

//TODO: make method comment blocks
template < typename T >
BinaryTree<T>::BinaryTree (const BinaryTree& bt)
{
    //TODO
}

//TODO: make method comment blocks
template < typename T >
void BinaryTree<T>::Insert (T item)
{
	if(root)
		root->insert(item);
	else
		root = new TreeNode<T>(item);
}

//TODO: make method comment blocks
template < typename T >
void BinaryTree<T>::Delete (TreeNode<T>* item)
{
    //TODO
}

//TODO: make method comment blocks
template < typename T >
void BinaryTree<T>::Purge ()
{
    //TODO
}

//TODO: make method comment blocks
template < typename T >
int BinaryTree<T>::Height ()
{
    //TODO
}

//TODO: make method comment blocks
template < typename T >
void BinaryTree<T>::Traverse (TreeFunc tf, TraversalPath path)
{
    //TODO
}

template < typename T >
TreeNode<T>* BinaryTree<T>::find(T value)
{
	//TODO
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& bs)
{
	if(bs.root)
		bs.root->display(os,0, 0);
	return os;
}


#endif

