/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  6, 2015
 * Last Modified:     November  6, 2015
 * Assignment number: 6
 * Filename:          BinaryTree.h
 * 
 * Class: BinaryTree
 * 
 * Methods: 
 *      BinaryTree ():
 *         Default constructor
 * 
 *      ~BinaryTree ():
 *         destructor
 * 
 *      BinaryTree (const BinaryTree& bt):
 *         copy constructor
 * 
 *     void Insert (T item):
 *         Insert an item into the tree
 * 
 *      void Delete (T& item):
 *         Delete an item from the tree
 * 
 *     void Purge ():
 *         Delete every item in the tree
 * 
 *      int Height ():
 *         Get the height of the tree
 * 
 *     void Traverse (TreeFunc tf, TraversalPath path):
 *         Traverse the tree with <path> executing <tf> on each element
 * 
 * 
 ********************************************************************************/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"


template < typename T >
class BinaryTree
{
    private:
        //TODO: add member variables
		TreeNode<T>* root;

    public:
		typedef void(*TreeFunc)(T&);

        //TODO: brief description
        BinaryTree ();

        //TODO: brief description
        ~BinaryTree ();

        //TODO: brief description
        BinaryTree (const BinaryTree& bt);

        //TODO: brief description
        void Insert (T item);

        //TODO: brief description
        void Delete (TreeNode<T>* item);

        //TODO: brief description
        void Purge ();

        //TODO: brief description
        int Height ();

		TreeNode<T>* find(T value);

		enum TraversalPath
		{
			_InOrder,
			_PreOrder,
			_PostOrder,
			_BreadthFirst
		};

        //TODO: brief description
        void Traverse (TreeFunc tf, TraversalPath path);

		template <typename U>
		friend std::ostream& operator<<(std::ostream& os, const BinaryTree<U>& bt);

};
#include "BinaryTree_impl.h"

#endif

