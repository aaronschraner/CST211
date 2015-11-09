/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  6, 2015
 * Last Modified:     November  6, 2015
 * Assignment number: 6
 * Filename:          TreeNode_impl.h
 * 
 ********************************************************************************/
#ifndef TREENODE_IMPL_H
#define TREENODE_IMPL_H

#ifndef MAX
#define MAX(x,y) ((x > y) ? (x) : (y))
#endif
#include <iostream>

template <typename T >
void swap(T& lhs, T& rhs)
{
	T temp=lhs;
	lhs=rhs;
	rhs=temp;
}

//TODO: make method comment blocks
template < typename T >
TreeNode<T>::TreeNode(T value):
	left(0), right(0), value(value)
{
}

//TODO: make method comment blocks
template < typename T >
TreeNode<T>::~TreeNode ()
{
	if(right)
		delete right;
	if(left)
		delete left;
}

//TODO: make method comment blocks
template < typename T >
void TreeNode<T>::insert(T newval)
{
	if (newval > value)
		if (right)
			right->insert(newval);
		else
			right = new TreeNode(newval);
	else
		if(left)
			left->insert(newval);
		else
			left = new TreeNode(newval);

	if (left && left->value > value)
		swap(left->value, value);
	if(right && right->value < value)
		swap(right->value, value);
}

//TODO: make method comment blocks
//
//return true if node should be deleted, false if it shouldn't.
template < typename T >
void TreeNode<T>::remove(T rmval)
{
	//TODO
	if (numChildren() == 0)
		return this;
	if (numChildren() == 1)
	{
		if(right)
		{
			TreeNode<T>* rptr = right;
			value = right->value;
			left = right->left;
			right = right->right;
			rptr -> left = 0;
			rptr -> right = 0;
			delete rptr;
		}
		else if(left)
		{
			TreeNode<T>* lptr = left;
			value = left->value;
			right = left->right;
			right = right->right;
			lptr -> right = 0;
			lptr -> left = 0;
			delete lptr;
		}
	}
}

template <typename T>
TreeNode<T>* TreeNode<T>::greatestChild()
{
	if(right)
		return right->greatestChild();
	else
		return this;
}

template <typename T>
TreeNode<T>* TreeNode<T>::leastChild()
{
	if(left)
		return left->leastChild();
	else
		return this;
}

template <typename T>
int TreeNode<T>::numChildren() const
{
	return !!left + !!right;
}


template <typename T>
void TreeNode<T>::display(std::ostream& os, int tablevel, NodeRelationship NR)
{
	static unsigned long pipes=0;
	if(right)
	{
		right->display(os,tablevel+1, _right);
	}
	else if(0)
	{
		for(int i=0; i<tablevel + 1; i++)
			os << (pipes&1<<i?"|   ":"    ");
		os << "/```" << "<NIL>" << std::endl;
	}

	if(NR == _right)
		pipes |= 1<<tablevel;
	else
		pipes &= ~(1<<tablevel);
	for(int i=0; i<tablevel; i++)
		os << (pipes&1<<i?"|   ":"    ");

	switch(NR)
	{
		case _right: os << "/```";  break;
		case _left:  os << "\\___"; break;
		case _root:  os << "----";	 break;
	}
	os << value << std::endl;

	if(left)
	{
		left->display(os,tablevel+1, _left);
	}
	else if(0)
	{
		for(int i=0; i<tablevel + 1; i++)
			os << (pipes&1<<i?"|   ":"    ");
		os << "\\___" << "<NIL>" << std::endl;

	}
}

//deep copy
template <typename T>
TreeNode<T>* TreeNode<T>::deepCopy() const
{
	TreeNode<T>* newNode = new TreeNode<T>(value);
	newNode -> right = right ? right -> deepCopy() : 0;
	newNode -> left  = left  ? left  -> deepCopy() : 0;
	return newNode;
}

template <typename T>
TreeNode<T>* TreeNode<T>::find(T key)
{
	//finds first instance
	if(key == value)
		return this;

	if(key < value && left)
		return left->find(key);

	if(key > value && right)
		return right->find(key);

	return 0;
}

//shallow copy
template <typename T>
TreeNode<T>::TreeNode(const TreeNode<T>& tn):
	value(tn.value), right(tn.right), left(tn.left)
{
}

template <typename T>
int TreeNode<T>::Height(TreeNode<T>* node) const
{
	if(!node)
		return 0;
	return 1 + MAX(Height(node->left), Height(node->right));
}

template <typename T> 
void TreeNode<T>::InOrderTraverse(TreeFunc tf)
{
	if(left)
		left->InOrderTraverse(tf);
	tf(*this);
	if(right)
		right->InOrderTraverse(tf);
		
	
}

template <typename T> 
void TreeNode<T>::PostOrderTraverse(TreeFunc tf)
{
	if(left)
		left->PostOrderTraverse(tf);
	if(right)
		right->PostOrderTraverse(tf);
	tf(*this);

}

template <typename T> 
void TreeNode<T>::PreOrderTraverse(TreeFunc tf)
{
	tf(*this);
	if(left)
		left->PreOrderTraverse(tf);
	if(right)
		right->PreOrderTraverse(tf);
}


#endif

