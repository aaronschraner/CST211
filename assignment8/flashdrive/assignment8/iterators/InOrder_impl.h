#ifndef INORDER_ITERATOR_H
#define INORDER_ITERATOR_H

template <typename T>
void pathAppend(TreeNode<T>& tn, void* param)
{
	std::deque<TreeNode<T>*>* path = (std::deque<TreeNode<T>*>*)param;
	std::cout << "pushing " << tn.getValue() << " onto queue." << std::endl;
	path->push_back(&tn);
	std::cout << "end of queue: " << ((*(path->rbegin()))->getValue()  ) << std::endl;
}

template <typename T>
InOrderIterator<T>::InOrderIterator(BinaryTree<T>* tree)
{
	tree->Traverse(&pathAppend<T>, BinaryTree<T>::_InOrder, &(this->path));
}


#endif
