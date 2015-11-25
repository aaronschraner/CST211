template <typename T>
void InOrder(TreeNode<T>* root) const
{
	if(!root)
		return;
	InOrder(root->m_left);
	visit(root);
	InOrder(root->m_right);
}

template <typename T>
void swap(T& lhs, T& rhs)
{
	T temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template <typename T>
void Tree<T>::Insert(TreeNode<T>* root, T data)
{
	if(!root)
		return;
	if(data > root->m_data)
		if(root->m_right)
			Insert(root->m_right, data);
		else
			root->m_right = new TreeNode(data, 0, 0);
	else
		if(root->m_left)
			Insert(root->m_left, data);
		else
			root->m_left = new TreeNode(data,0, 0);
	if(root->m_left && root->m_left->m_data > root->m_data)
		swap(root->m_left->m_data, root->m_data);

	if(root->m_right && root->m_right->m_data < root->m_data)
		swap(root->m_right->m_data, root->m_data);
}


template <typename T> 
void Tree<T>::BreadthFirst()
{
	int height=Height(this);
	std::vector<TreeNode<T>*>* values= new std::vector<TreeNode<T>*> [height];
	values[0].push_back(this);
	for(int level = 1; level < height; level++)
	{
		for(int i = 0; i < values[level-1].size(); i++)
		{
			TreeNode<T>* ptr = values[level-1][i];
			if(ptr->m_left)
				values[level].push_back(ptr->m_left);
			if(ptr->m_right)
				values[level].push_back(ptr->m_right);
		}
	}

	for(int level=0; level < height; level++)
		for(int x=0; x < values[level].size(); x++)
			visit(values[level][x]);

}

template <typename T>
int Tree<T>::Height(TreeNode<T>* root) const
{
	if(!root)
		return 0;
	return 1 + MAX(Height(root->m_left), Height(root->m_right));
}

template <typename T>
void Purge(TreeNode<T>* &root)
{
	if(!root)
		return;
	if(root->m_left)
		Purge(root->m_left);
	if(root->m_right)
		Purge(root->m_right);
	delete root;
	root=0;
}
