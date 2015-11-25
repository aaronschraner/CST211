template <typename T>
class Tree
{
	public:
		Tree();
		~Tree();
		Tree(const Tree & copy);
		Tree & operator = (const Tree & rhs);
		void Purge();
		void Insert(T data);
		void Delete(T data);
		void InOrder() const;
		void BreadthFirst() const;
		int Height() const;
	private:
		int Height(TreeNode<T> * root) const;
		void InOrder(TreeNode<T> * root) const;
		void Purge(TreeNode<T> *& root);
		void Insert(TreeNode<T> *& root, T data); //Recursive
		void Delete(TreeNode<T> *& root, T data);
		void Visit(TreeNode<T> * node) const;

		TreeNode<T> * m_root;
};

template <typename T>
class Tree;

template <typename T>
class TreeNode
{
	friend class Tree;
	public:
	TreeNode();
	TreeNode(const T & data, TreeNode * left, TreeNode * right);
	private:
	TreeNode * m_left;
	TreeNode * m_right;
	T m_data;
};
