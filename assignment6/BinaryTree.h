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
		// Typedef for the functions that can be executed by Traverse()
		typedef void(*TreeFunc)(TreeNode<T>&);

		//default constructor (creates empty tree)
		BinaryTree ();

		//destructor (deletes everything from tree)
		~BinaryTree ();

		//copy constructor (creates a copy of the tree)
		BinaryTree (const BinaryTree& bt);

		//Insert (insert an item into the tree)
		void Insert (T item);

		//Delete (delete an item from the tree)
		void Delete (T item);

		//Purge all elements from the tree
		void Purge ();

		//Find the height of the tree (recursively)
		int Height () const;

		//Find the first occurrence of a value in the tree
		TreeNode<T>* find(T value);

		//types of traversals that can be passed to Traverse()
		enum TraversalPath
		{
			_InOrder,
			_PreOrder,
			_PostOrder,
			_BreadthFirst
		};
		//breadth-first traversal algorithm

		//Traverse a binary tree using the specified path, executing <tf> on each element.
		void Traverse (TreeFunc tf, TraversalPath path);

		//stream output operator
		template <typename U>
			friend std::ostream& operator<<(std::ostream& os, const BinaryTree<U>& bt);

};
#include "BinaryTree_impl.h"

#endif

