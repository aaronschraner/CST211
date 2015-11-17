/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  6, 2015
 * Last Modified:     November  16, 2015
 * Assignment number: 6
 * Filename:          BinaryTree_impl.h
 * 
 ********************************************************************************/
#ifndef BINARYTREE_IMPL_H
#define BINARYTREE_IMPL_H


/********************************************************************************
 * BinaryTree ();
 * 	Purpose: 
 * 		Default constructor for binary tree.
 * 		Initializes root node to NULLPTR
 * 	
 * 	Entry: 
 * 		takes no parameters
 * 	
 * 	Exit: 
 * 		creates an empty tree
 * 	
 ********************************************************************************/
template < typename T >
BinaryTree<T>::BinaryTree ():
	root(0)
{
}

/********************************************************************************
 * ~BinaryTree ();
 * 	Purpose: 
 * 		Destructor for binary tree
 * 		Uses recursive tree node destructor for root node
 * 	
 * 	Entry: 
 * 		no parameters
 * 	
 * 	Exit: 
 * 		destructed tree
 * 	
 ********************************************************************************/
template < typename T >
BinaryTree<T>::~BinaryTree ()
{
	//free the tree (if it exists)
	if(root)
		delete root;
}

/********************************************************************************
 * BinaryTree (const BinaryTree& bt);
 * 	Purpose: 
 * 		Copy constructor for binary tree
 * 	
 * 	Entry: 
 * 		bt: the tree being copied
 * 	
 * 	Exit: 
 * 		An exact deep copy of <bt>
 * 	
 ********************************************************************************/
template < typename T >
BinaryTree<T>::BinaryTree (const BinaryTree& bt)
{
	root = bt.root ? bt.root -> deepCopy() : 0;
}

/********************************************************************************
 * void Insert (T item);
 * 	Purpose: 
 * 		Insert an item into the tree where it belongs
 * 		note: does not attempt to balance tree.
 * 	
 * 	Entry: 
 * 		item: the item to be inserted into the tree
 * 	
 * 	Exit: 
 * 		returns nothing
 * 	
 ********************************************************************************/
template < typename T >
void BinaryTree<T>::Insert (T item)
{
	if(root)
		root->insert(item);
	else
		root = new TreeNode<T>(item);
}

/********************************************************************************
 * void Delete (T item);
 * 	Purpose: 
 * 		Delete an item from the tree
 * 		(TODO)
 * 	
 * 	Entry: 
 * 		item: the item to be searched for and removed from the tree
 * 	
 * 	Exit: 
 * 		returns nothing
 * 	
 ********************************************************************************/
template < typename T >
void BinaryTree<T>::Delete (T item)
{
	if(!root)
		return;
	root->remove(item);
	
}

/********************************************************************************
 * void Purge ();
 * 	Purpose: 
 * 		Delete all nodes from the tree using the recursive node deconstructor
 * 		Then set root equal to NULLPTR
 * 	
 * 	Entry: 
 * 		no parameters
 * 	
 * 	Exit: 
 * 		returns nothing
 * 		just empties the tree
 * 	
 ********************************************************************************/
template < typename T >
void BinaryTree<T>::Purge ()
{
	delete root;
	root=0;
}

/********************************************************************************
 * int Height () const;
 * 	Purpose: 
 * 		Find the height of the tallest branch of the tree
 * 	
 * 	Entry: 
 * 		no parameters
 * 	
 * 	Exit: 
 * 		returns the height of the tallest tree branch
 * 	
 ********************************************************************************/
template <typename T>
int BinaryTree<T>::Height() const
{
	return root->Height(root);
}

/********************************************************************************
 * void Traverse (TreeFunc tf, TraversalPath path);
 * 	Purpose: 
 * 		Traverse the entire tree in the path specified by TraversalPath,
 * 		executing <tf> on each TreeNode in the tree.
 * 		Available traversal options are:
 * 		- In-order (BinaryTree::_InOrder)
 * 		- Pre-order (BinaryTree::_PreOrder)
 * 		- Post-order (BinaryTree::_PostOrder)
 * 		- Breadth first (BinaryTree::_BreadthFirst)
 * 		The actual traversal methods are defined in TreeNode_impl.h
 * 	
 * 	Entry: 
 * 		tf: the function (void (TreeNode<T>&)) to be executed on each element in the tree
 * 		path: the path the function should go in when executing.
 * 	
 * 	Exit: 
 * 		returns nothing
 * 	
 ********************************************************************************/
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
		case BinaryTree::_BreadthFirst: root->BreadthFirstTraverse(tf); break;
	}

}

/********************************************************************************
 * TreeNode<T>* find(T value);
 * 	Purpose: 
 * 		Find the first node in the tree containing the specified value
 * 	
 * 	Entry: 
 * 		value: the item to be searched for
 * 	
 * 	Exit: 
 * 		Returns a pointer to the node containing that value
 * 		(NULLPTR if not found)
 * 	
 ********************************************************************************/
template < typename T >
TreeNode<T>* BinaryTree<T>::find(T value)
{
	return root ? root->find(value) : 0;
}

/********************************************************************************
 * friend std::ostream& operator<<(std::ostream& os, const BinaryTree<U>& bt);
 * 	Purpose: 
 * 		Stream output operator for binary tree class
 * 		calls display on root node
 * 	
 * 	Entry: 
 * 	
 * 	Exit: 
 * 	
 ********************************************************************************/
template <typename T>
std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& bs)
{
	if(bs.root)
		bs.root->display(os);
	return os;
}

template <typename T>
void BinaryTree<T>::balance()
{
	//should happen automagically in insert()
	root->balance();
}


#endif

