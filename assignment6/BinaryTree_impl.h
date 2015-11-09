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
#include <vector>


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
	//free the tree (if it exists)
	if(root)
		delete root;
}

//TODO: make method comment blocks
template < typename T >
BinaryTree<T>::BinaryTree (const BinaryTree& bt)
{
	root = root ? bt.root -> deepCopy() : 0;
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
void BinaryTree<T>::Delete (T item)
{
	//TODO
}

//TODO: make method comment blocks
template < typename T >
void BinaryTree<T>::Purge ()
{
	delete root;
	root=0;
}

template <typename T>
int BinaryTree<T>::Height() const
{
	return root->Height(root);
}

//TODO: make method comment blocks
template < typename T >
void BinaryTree<T>::Traverse (TreeFunc tf, TraversalPath path)
{
	if(!root)
		return;
	switch(path)
	{
		case BinaryTree::_InOrder: root->InOrderTraverse(tf); break;
		case BinaryTree::_PreOrder: root->PreOrderTraverse(tf); break;
		case BinaryTree::_PostOrder: root->PostOrderTraverse(tf); break;
		case BinaryTree::_BreadthFirst: BreadthFirstTraverse(tf,root); break;
	}

}

template < typename T >
TreeNode<T>* BinaryTree<T>::find(T value)
{
	return root->find(value);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& bs)
{
	if(bs.root)
		bs.root->display(os);
	return os;
}

template <typename T> 
void BinaryTree<T>::BreadthFirstTraverse(TreeFunc tf, TreeNode<T>* node)
{
	//this is so bad
	std::vector<TreeNode<T>*>* values= new std::vector<TreeNode<T>*> [Height()];
	if(!root)
		return;
	std::cout << "assigned [0][0] to root" << std::endl;
	values[0].push_back(root);
	for(int level = 1; level < Height(); level++)
	{
		for(int i = 0; i < values[level-1].size(); i++)
		{
			TreeNode<T>* ptr = values[level-1][i];
			if(ptr->left)
				values[level].push_back(ptr->left);
			if(ptr->right)
				values[level].push_back(ptr->right);
		}
	}

	for(int level=0; level < Height(); level++)
		for(int x=0; x < values[level].size(); x++)
			tf(*(values[level][x]));

}
#endif

