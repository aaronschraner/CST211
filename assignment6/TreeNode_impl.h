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
	std::cout << "Created new tree node " << value << std::endl;
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
template < typename T >
void TreeNode<T>::remove (T delval)
{
    //TODO
}

template <typename T>
void TreeNode<T>::display(std::ostream& os, int tablevel, bool RL)
{
	static unsigned long pipes=0;
	pipes = tablevel?pipes:0;
	if(right)
		right->display(os,tablevel+1, 1);
	else
	{
		for(int i=0; i<tablevel + 1; i++)
			os << (pipes&1<<i?"|   ":"    ");
		os << "/```" << "<NIL>" << std::endl;
		pipes |= 2<<tablevel;
	}

	for(int i=0; i<tablevel; i++)
		os << (pipes&1<<i?"|   ":"    ");

	os << (RL?"/```":"\\___") << value << std::endl;
	pipes = RL ? pipes : pipes|1<<tablevel;


	//pipes |= 2 << tablevel;
	if(left)
		left->display(os,tablevel+1, 0);
	else
	{
		for(int i=0; i<tablevel + 1; i++)
			os << (pipes&1<<i?"|   ":"    ");
		os << "\\___" << "<NIL>" << std::endl;
		pipes &= ~(2<<tablevel);
	}
}
#endif

