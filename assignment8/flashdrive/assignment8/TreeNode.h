/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  6, 2015
 * Last Modified:     November  8, 2015
 * Assignment number: 6
 * Filename:          TreeNode.h
 * 
 * Class: TreeNode
 * 
 * Methods: 
 *     TreeNode(T value):
 *         Constructor given node value
 * 
 *      ~TreeNode ():
 *         destructor (kills children)
 * 
 *     void Insert(value (T):
 *         Insert a value into the node (create a new node if full)
 * 
 *     void Delete (T value):
 *         Delete a value from this node (recurse into children if necessary)
 * 
 * 
 ********************************************************************************/
#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <iostream>

enum NodeRelationship
{
	_left,
	_right,
	_root
};

template < typename T >
class TreeNode
{
	private:
		//typedef for functions that can operate on tree nodes
		typedef void(*TreeFunc)(TreeNode<T>&, void* param);

		//left and right child nodes
		TreeNode<T>* left;
		TreeNode<T>* right;

		//the value of this node
		T value;

	public:
		//constructors
		TreeNode(T value);
		TreeNode(const TreeNode<T>&);

		//member functions
		TreeNode<T>* deepCopy() const;
		TreeNode<T>* find(T key) ;
		TreeNode<T>* findParent(TreeNode<T>* tn);
		TreeNode<T>* greatestChildsParent();
		TreeNode<T>* leastChild();
		void remove(TreeNode<T>* parent, TreeNode<T>* child);
		const T& getValue() const { return value; }
		T& getValue() { return value; }
		int numChildren() const;

		//destructor
		~TreeNode ();

		//basic functions (part of assignment description)
		void insert(T newval);
		void remove (T rmval, TreeNode<T>* parent=0);
		void replaceInParent(TreeNode<T>* parent,TreeNode<T>* newval);
		int Height(TreeNode<T>* tn) const;

		//recursively display a node and its children
		void display(std::ostream& os, int tablevel=0,  NodeRelationship NR=_root);

		//traversals
		void InOrderTraverse(TreeFunc tf, void* parameter);
		void PostOrderTraverse(TreeFunc tf, void* parameter);
		void PreOrderTraverse(TreeFunc tf, void* parameter);
		void BreadthFirstTraverse(TreeFunc tf, void* parameter);

};
#include "TreeNode_impl.h"

#endif

