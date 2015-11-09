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

template < typename T >
class TreeNode
{
    private:
        //TODO: add member variables
		TreeNode<T>* left;
		TreeNode<T>* right;
		T value;

    public:
        //TODO: brief description
        TreeNode(T value);

        //TODO: brief description
        ~TreeNode ();

        //TODO: brief description
        void insert(T newval);

        //TODO: brief description
        void remove (T newval);
		void display(std::ostream& os, int tablevel,  bool LR=0);

};
#include "TreeNode_impl.h"

#endif

