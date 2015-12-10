/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  6, 2015
 * Last Modified:     November  8, 2015
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
#include <vector>

//generic swap function
template <typename T >
void swap(T& lhs, T& rhs)
{
	T temp=lhs;
	lhs=rhs;
	rhs=temp;
}

/********************************************************************************
 * TreeNode(T value);
 * 	Purpose: 
 * 		Construct a tree node with no left or right children and this value
 * 	
 * 	Entry: 
 * 		value: the value that the new TreeNode should have
 * 	
 * 	Exit: 
 * 		constructs the node
 * 	
 ********************************************************************************/
template < typename T >
TreeNode<T>::TreeNode(T value):
	left(0), right(0), value(value)
{
}

/********************************************************************************
 * ~TreeNode ();
 * 	Purpose: 
 * 		Destructor for tree node
 * 		recursively deletes children
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		destructs node and children
 * 	
 ********************************************************************************/
template < typename T >
TreeNode<T>::~TreeNode ()
{
	//delete right child if present
	if(right)
		delete right;

	//delete left child if present
	if(left)
		delete left;
}

/********************************************************************************
 * void insert(T newval);
 * 	Purpose: 
 * 		Recursively insert a value into the search tree
 * 	
 * 	Entry: 
 * 		newval: the value to be inserted
 * 	
 * 	Exit: 
 * 		returns nothing
 * 	
 ********************************************************************************/
template < typename T >
void TreeNode<T>::insert(T newval)
{
	//initial construction
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

	//handles conditions where values are inserted out of order
	if (left && left->value > value)
		swap(left->value, value);

	if(right && right->value < value)
		swap(right->value, value);
}

/********************************************************************************
 * void remove (T rmval);
 * 	Purpose: 
 * 		Recursively remove a value from the node
 * 	
 * 	Entry: 
 * 		rmval: the value to be removed (first instance)
 * 	
 * 	Exit: 
 * 		removes the node and exits
 * 		does not throw exception if node is not found
 * 		TODO: fix segfault problem
 * 	
 ********************************************************************************/
template < typename T >
void TreeNode<T>::remove(T rmval, TreeNode<T>* parent )
{
	//DOES NOT WORK
	if(rmval < value && left)
		left->remove(rmval,this);
	else if(rmval > value && right)
		right->remove(rmval,this);
	else
	{
		if(left && right)
		{
			TreeNode<T>* successor = right->leastChild();
			value = successor->value;
			successor->remove(value);
		}
		else if(left)
			replaceInParent(this,left);
		else if(right)
			replaceInParent(this,right);
		else
			replaceInParent(parent,0);

	}
}

template <typename T>
void TreeNode<T>::replaceInParent(TreeNode<T>* parent,TreeNode<T>* newval)
{
	if(parent)
	{
		if(this==parent->left)
			parent->left = newval;
		else
			parent->right = newval;
	}
}

//template <typename T>
//void TreeNode<T>::remove(TreeNode<T>* parent, TreeNode<T>* child)
//{
//	TreeNode<T>* &childref = parent->left == child ? parent->left : parent->right;
//	switch(child->numChildren())
//	{
//		case 0:
//			std::cout << "removing node with no children" << std::endl;
//			childref=0;
//			delete child;
//
//			break;
//
//		case 1:
//			std::cout << "removing node with one child" << std::endl;
//			{
//				TreeNode<T>* &childref = parent->left == child ? parent->left : parent->right;
//				if(child->left)
//				{
//					childref = child->left;
//					child->left = 0;
//				}
//				else
//				{
//					childref = child->right;
//					child->right = 0;
//				}
//				delete child;
//			}
//			break;
//		case 2:
//			{
//				TreeNode<T>* successor = child->right->leastChild()
//			}
//	}	
//	std::cout << "leaving remove(parent,child)\n";
//}

template <typename T>
TreeNode<T>* TreeNode<T>::findParent(TreeNode<T>* child)
{
	if(right == child || left == child)
		return this;
	if(child->value < value)
		return right->findParent(child);
	if(child->value > value)
		return left->findParent(child);
	std::cout << "FAILED TO FIND PARENT" << std::endl;
	return 0;
}
/********************************************************************************
 * TreeNode<T>* greatestChild();
 * 	Purpose: 
 * 		Find the parent of the greatest child of a node recursively
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		returns a pointer to the greatest child
 * 	
 ********************************************************************************/
template <typename T>
TreeNode<T>* TreeNode<T>::greatestChildsParent()
{
	if(right && !right->right)
		return this;
	else if(right)
		return right->greatestChildsParent();
	std::cout << "No GCP found\n";
	return 0;
}

/********************************************************************************
 * TreeNode<T>* leastChild();
 * 	Purpose: 
 * 		finds the child of this node with least value recursively
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		returns a pointer to the least child
 * 	
 ********************************************************************************/
template <typename T>
TreeNode<T>* TreeNode<T>::leastChild()
{
	if(left)
		return left->leastChild();
	else
		return this;
}

/********************************************************************************
 * int numChildren() const;
 * 	Purpose: 
 * 		Find the number of children a node has
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		returns the number of children (0, 1, or 2)
 * 	
 ********************************************************************************/
template <typename T>
int TreeNode<T>::numChildren() const
{
	return !!left + !!right;
}


/********************************************************************************
 * void display(std::ostream& os, int tablevel=0,  NodeRelationship NR=_root);
 * 	Purpose: 
 * 		Recursively display a tree node and all its children
 * 	
 * 	Entry: 
 * 		os: the output stream object to print to
 * 		tablevel: the number of indents to put before drawing the value and children
 * 		NR: an enum corresponding to if this is a left child, right child, or root node.
 * 	
 * 	Exit: 
 * 		displays the node's tree of children
 * 	
 ********************************************************************************/
template <typename T>
void TreeNode<T>::display(std::ostream& os, int tablevel, NodeRelationship NR)
{
	//each bit is one indent
	static unsigned long pipes=0;


	//display in-order
	//right children first
	if(right)
		right->display(os,tablevel+1, _right);

	//used to explicitly display null children
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

	//indent with pipes where necessary
	for(int i=0; i<tablevel; i++)
		os << (pipes&1<<i?"|   ":"    ");

	//display a thing to graphically draw the tree better
	switch(NR)
	{
		case _right: os << "/```";  break;
		case _left:  os << "\\___"; break;
		case _root:  os << "----";	 break;
	}

	//display the value of the node
	os << value << std::endl;

	if(left)
		left->display(os,tablevel+1, _left);
	else if(0)
	{
		for(int i=0; i<tablevel + 1; i++)
			os << (pipes&1<<i?"|   ":"    ");
		os << "\\___" << "<NIL>" << std::endl;

	}
}

/********************************************************************************
 * TreeNode<T>* deepCopy() const;
 * 	Purpose: 
 * 		Dynamically allocate and create a deep copy of this tree.
 * 		This was originally going to be part of the copy constructor but
 * 		I didn't want to accidentally invoke it and copy the whole tree
 * 	
 * 	Entry: 
 * 		Copies all elements and children of <this>
 * 	
 * 	Exit: 
 * 		Returns a pointer to the new dynamic tree
 * 	
 ********************************************************************************/
template <typename T>
TreeNode<T>* TreeNode<T>::deepCopy() const
{
	TreeNode<T>* newNode = new TreeNode<T>(value);
	newNode -> right = right ? right -> deepCopy() : 0;
	newNode -> left  = left  ? left  -> deepCopy() : 0;
	return newNode;
}

/********************************************************************************
 * TreeNode<T>* find(T key) ;
 * 	Purpose: 
 * 		Find the first instance of an element in the tree that matches <key>.
 * 		Then return a pointer to the node that contains it.
 * 	
 * 	Entry: 
 * 		key: the value to search for
 * 	
 * 	Exit: 
 * 		Returns a pointer to the key's containing node if it is found
 * 		otherwise returns NULLPTR
 * 	
 ********************************************************************************/
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

/********************************************************************************
 * TreeNode(const TreeNode<T>& tn);
 * 	Purpose: 
 * 		Copy constructor for tree node
 *		(does a deep copy)
 * 	
 * 	Entry: 
 * 		tn: the tree node to be copied
 * 	
 * 	Exit: 
 * 		returns an exact copy of <tn>'s tree
 * 	
 ********************************************************************************/
template <typename T>
TreeNode<T>::TreeNode(const TreeNode<T>& tn):
	value (tn.value)
{
	left = tn.left ? tn.left->deepCopy() : 0;
	right = tn.right ? tn.right->deepCopy():0;
}

/********************************************************************************
 * int Height(TreeNode<T>* tn) const;
 * 	Purpose: 
 * 		Recursively determine the height of the tree's tallest branch
 * 	
 * 	Entry: 
 * 		tn: used for recursion purposes (call Height(root) to find height of tree)
 * 	
 * 	Exit: 
 * 		Returns the height of the tallest branch
 * 	
 ********************************************************************************/
template <typename T>
int TreeNode<T>::Height(TreeNode<T>* node) const
{
	if(!node)
		return 0;
	return 1 + MAX(Height(node->left), Height(node->right));
}

/********************************************************************************
 * void InOrderTraverse(TreeFunc tf);
 * 	Purpose: 
 * 		Traverse the tree in sorted order from least to greatest, executing
 * 		<tf> on each node.
 * 	
 * 	Entry: 
 * 		tf: the function to be executed on each node
 * 	
 * 	Exit: 
 * 		returns nothing
 * 	
 ********************************************************************************/
template <typename T> 
void TreeNode<T>::InOrderTraverse(TreeFunc tf, void* p)
{
	if(left)
		left->InOrderTraverse(tf,p);
	tf(*this,p);
	if(right)
		right->InOrderTraverse(tf,p);
		
	
}

/********************************************************************************
 * void PostOrderTraverse(TreeFunc tf);
 * 	Purpose: 
 * 		Traverse the tree in post-order, executing <tf> on each node
 * 	
 * 	Entry: 
 * 		tf: the function to be executed on each node
 * 	
 * 	Exit: 
 * 		returns nothing
 * 	
 ********************************************************************************/
template <typename T> 
void TreeNode<T>::PostOrderTraverse(TreeFunc tf, void* p)
{
	if(left)
		left->PostOrderTraverse(tf,p);
	if(right)
		right->PostOrderTraverse(tf,p);
	tf(*this,p);

}

/********************************************************************************
 * void PreOrderTraverse(TreeFunc tf);
 * 	Purpose: 
 * 		Traverse the list in pre-order, firing arrows at each node
 * 	
 * 	Entry: 
 * 		tf: the function to be executed on each node
 * 	
 * 	Exit: 
 * 		returns nothing
 * 	
 ********************************************************************************/
template <typename T> 
void TreeNode<T>::PreOrderTraverse(TreeFunc tf, void* p)
{
	tf(*this,p);
	if(left)
		left->PreOrderTraverse(tf,p);
	if(right)
		right->PreOrderTraverse(tf,p);
}

/********************************************************************************
 * void BreadthFirstTraverse(TreeFunc tf);
 * 	Purpose: 
 * 		Traverse the tree under this node breadth-first,
 * 		executing <tf> on each node in that order
 * 	
 * 	Entry: 
 * 		tf: the function to be executed on each node
 * 		this: should be the root node of the tree
 * 		(root->BreadthFirstTraverse(tf))
 * 	
 * 	Exit: 
 * 		returns nothing
 * 	
 ********************************************************************************/
template <typename T> 
void TreeNode<T>::BreadthFirstTraverse(TreeFunc tf, void* p)
{
	//this is so bad
	int height=Height(this);
	std::vector<TreeNode<T>*>* values= new std::vector<TreeNode<T>*> [height];
	values[0].push_back(this);
	for(int level = 1; level < height; level++)
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

	for(int level=0; level < height; level++)
		for(int x=0; x < values[level].size(); x++)
			tf(*(values[level][x]),p);

}

#endif

