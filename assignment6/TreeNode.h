/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  6, 2015
 * Last Modified:     November  6, 2015
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
        //TODO: add member variables
		typedef void(*TreeFunc)(TreeNode<T>&);

    public:
		TreeNode<T>* left;
		TreeNode<T>* right;
		T value;
        //TODO: brief description
        TreeNode(T value);
		TreeNode(const TreeNode<T>&);

		TreeNode<T>* deepCopy() const;
		TreeNode<T>* find(T key) ;
		TreeNode<T>* findParent(TreeNode<T>* tn);
		TreeNode<T>* greatestChild();
		TreeNode<T>* leastChild();
		int Height(TreeNode<T>* tn) const;
		
		const T& getValue() const { return value; }
		int numChildren() const;

        //TODO: brief description
        ~TreeNode ();

        //TODO: brief description
        void insert(T newval);

        //TODO: brief description
        void remove (T rmval);
		void display(std::ostream& os, int tablevel=0,  NodeRelationship NR=_root);

		void InOrderTraverse(TreeFunc tf);
		void PostOrderTraverse(TreeFunc tf);
		void PreOrderTraverse(TreeFunc tf);

};
#include "TreeNode_impl.h"

#endif

